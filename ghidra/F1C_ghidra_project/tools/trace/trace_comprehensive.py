#!/usr/bin/env python3
"""
F1 Challenge — Comprehensive 10-minute trace capture.

Attaches Frida to running game, installs hooks AFTER game is stable,
captures first-call events + state changes + periodic summaries + vehicle snapshots.

Usage:
    python trace_comprehensive.py                  # 10 min, attach to running game
    python trace_comprehensive.py --duration 300   # 5 min
    python trace_comprehensive.py --launch         # launch game first, then attach

Requires: pip install frida frida-tools
Run as Administrator.
"""

import argparse
import frida
import os
import subprocess
import sys
import time
from datetime import datetime
from pathlib import Path

SCRIPT_DIR = Path(__file__).parent
AGENT_JS = SCRIPT_DIR / "agent_comprehensive.js"
TRACE_DIR = SCRIPT_DIR / "output"
PROCESS_NAME = "F1 Challenge Online.exe"
GAME_DIR = Path(r"%USERPROFILE%\Desktop\F1 Challenge V10")
GAME_EXE = GAME_DIR / PROCESS_NAME


def main():
    parser = argparse.ArgumentParser(description="F1C Comprehensive Trace")
    parser.add_argument("--duration", type=int, default=600,
                        help="Trace duration in seconds (default: 600 = 10 min)")
    parser.add_argument("--launch", action="store_true",
                        help="Launch game in noplayer mode before attaching")
    parser.add_argument("--wait", type=int, default=20,
                        help="Seconds to wait after launch before attaching (default: 20)")
    parser.add_argument("--quiet", "-q", action="store_true",
                        help="Suppress per-line console output")
    args = parser.parse_args()

    ts = datetime.now().strftime("%Y%m%d_%H%M%S")
    output_name = f"comprehensive_{ts}_{args.duration}s.log"
    TRACE_DIR.mkdir(parents=True, exist_ok=True)
    output_path = TRACE_DIR / output_name

    # Step 1: Launch game if requested
    if args.launch:
        print(f"Launching: {GAME_EXE} -trace=2 -noplayer")
        subprocess.Popen(
            [str(GAME_EXE), "-trace=2", "-noplayer"],
            cwd=str(GAME_DIR),
        )
        print(f"Waiting {args.wait}s for game to start...")
        time.sleep(args.wait)

    # Step 2: Attach to game process (retry loop)
    print(f"Attaching to {PROCESS_NAME}...")
    session = None
    for attempt in range(30):
        try:
            session = frida.attach(PROCESS_NAME)
            break
        except frida.ProcessNotFoundError:
            if attempt < 29:
                time.sleep(2)
            else:
                print(f"ERROR: '{PROCESS_NAME}' not found after 60s.")
                sys.exit(1)
        except frida.PermissionDeniedError:
            print("ERROR: Permission denied. Run as Administrator.")
            sys.exit(1)

    if session is None:
        print("ERROR: Could not attach.")
        sys.exit(1)

    print(f"Attached (PID: {session._impl.pid})")

    # Step 3: Load agent WITHOUT installing hooks
    agent_code = AGENT_JS.read_text(encoding="utf-8")
    script = session.create_script(agent_code)

    total_lines = [0]
    done = [False]
    start_time = [time.time()]

    outfile = open(output_path, "w", encoding="utf-8")
    outfile.write(f"# F1C Comprehensive Trace -- {datetime.now().isoformat()}\n")
    outfile.write(f"# Duration: {args.duration}s\n")
    outfile.write(f"# Mode: noplayer AI race\n\n")

    def on_message(message, data):
        if message["type"] == "send":
            payload = message["payload"]
            msg_type = payload.get("type", "")

            if msg_type == "ready":
                print(f"Agent loaded (hooks pending: {payload['hooks']})")

            elif msg_type == "started":
                print(f"Trace started ({args.duration}s duration)")
                start_time[0] = time.time()

            elif msg_type == "trace":
                lines = payload["lines"]
                total_lines[0] += len(lines)
                for line in lines:
                    outfile.write(line + "\n")
                    if not args.quiet:
                        if line.startswith("[FIRST]"):
                            print(f"\033[92m{line}\033[0m")
                        elif line.startswith("[STATE]"):
                            print(f"\033[93m{line}\033[0m")
                        elif line.startswith("[SUMMARY]") or line.startswith("  [RATES]"):
                            print(f"\033[96m{line}\033[0m")
                        elif line.startswith("[VEHICLE]") or line.startswith("[AI_VEH]"):
                            print(f"\033[95m{line}\033[0m")
                        elif line.startswith("[FINAL]") or line.startswith("[NEVER"):
                            print(f"\033[91m{line}\033[0m")
                        else:
                            print(line)

            elif msg_type == "done":
                elapsed = time.time() - start_time[0]
                print(f"\nTrace complete. {total_lines[0]} lines, {elapsed:.1f}s")
                done[0] = True

            elif msg_type == "stopped":
                done[0] = True

            elif msg_type == "error":
                print(f"AGENT ERROR: {payload['msg']}")

        elif message["type"] == "error":
            print(f"FRIDA ERROR: {message.get('description', message)}")

    script.on("message", on_message)
    script.load()

    try:
        # Step 4: Wait for game to be in a stable state before hooking
        print()
        print("Agent loaded. Waiting for game to finish loading...")
        print("(Checking GameState every 2s — need state >= 5 = RUNNING)")
        print()

        game_ready = False
        for check in range(90):
            try:
                state = script.exports_sync.read_state()
                gs = state.get("GameState", 0)
                veh = state.get("VehicleCount", 0)
                internal = state.get("InternalState", 0)
                print(f"  Check {check+1}: GameState={gs}, InternalState={internal}, Vehicles={veh}")
                if gs >= 5 and veh > 0:
                    print(f"\n  Game is running! Installing hooks...")
                    game_ready = True
                    break
            except Exception as e:
                print(f"  Check {check+1}: read failed ({e})")
            time.sleep(2)

        if not game_ready:
            print("\nWARNING: Game never reached RUNNING state after 3 min.")
            print("Installing hooks anyway (may be in menu/loading).")

        # Step 5: Install hooks and start trace
        try:
            hook_count = script.exports_sync.installnow()
            print(f"  {hook_count} hooks installed successfully.")
        except Exception as e:
            print(f"  Hook installation error: {e}")
            raise

        print(f"\nOutput: {output_path}")
        print(f"Running for {args.duration}s... (Ctrl+C to stop early)")
        print()

        script.exports_sync.start(args.duration)

        # Step 6: Wait for completion
        while not done[0]:
            time.sleep(1)
            elapsed = time.time() - start_time[0]
            if not args.quiet and int(elapsed) % 30 == 0 and int(elapsed) > 0:
                remaining = max(0, args.duration - elapsed)
                print(f"  [{int(elapsed)}s / {args.duration}s] {total_lines[0]} lines, {int(remaining)}s remaining")

    except KeyboardInterrupt:
        print("\nStopping early...")
        try:
            script.exports_sync.stop()
        except Exception:
            pass

    except Exception as e:
        print(f"\nError: {e}")

    finally:
        # Always save the file
        outfile.flush()
        outfile.close()

        if output_path.exists():
            size = output_path.stat().st_size
            print(f"\nSaved: {output_path}")
            print(f"  Size: {size:,} bytes ({size/1024:.1f} KB)")
            print(f"  Lines: {total_lines[0]:,}")

        try:
            script.unload()
        except Exception:
            pass
        try:
            session.detach()
        except Exception:
            pass
        print("Detached.")


if __name__ == "__main__":
    main()
