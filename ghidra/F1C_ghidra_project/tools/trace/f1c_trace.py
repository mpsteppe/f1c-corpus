#!/usr/bin/env python3
"""
F1 Challenge 99-02 Runtime Trace Controller

Attaches Frida to the running game process, loads the agent, and captures
function call traces for frame loop analysis.

Usage:
    python f1c_trace.py                    # Attach and start interactive session
    python f1c_trace.py --frames 100       # Capture 100 frames then stop
    python f1c_trace.py --output trace.log # Save trace to file
    python f1c_trace.py --state            # Just read current state variables
    python f1c_trace.py --list-threads     # List game threads

Requires: pip install frida frida-tools
"""

import argparse
import frida
import json
import os
import signal
import sys
import threading
import time
from datetime import datetime
from pathlib import Path

SCRIPT_DIR = Path(__file__).parent
AGENT_JS = SCRIPT_DIR / "agent.js"
AGENT_STATE_JS = SCRIPT_DIR / "agent_state.js"
TRACE_DIR = SCRIPT_DIR / "output"
PROCESS_NAME = "F1 Challenge Online.exe"

# State variable names for display
STATE_NAMES = {
    "GameState": {1: "INIT", 2: "MENU", 3: "LOADING", 4: "SETUP", 5: "RUNNING", 6: "QUALIFYING", 7: "RACE"},
    "SessionType": {0: "PRACTICE_0", 1: "PRACTICE_1", 2: "PRACTICE_2", 3: "PRACTICE_3",
                    4: "PRACTICE_4", 5: "PRACTICE_5", 6: "QUALIFYING", 7: "RACE"},
    "RacePhase": {0: "PRE_START", 1: "FORMATION", 2: "GREEN_FLAG", 3: "RACING",
                  4: "CAUTION", 5: "RED_FLAG", 6: "CHECKERED", 7: "POST_RACE", 8: "DONE"},
    "WeatherMode": {0: "DRY", 1: "LIGHT_RAIN", 2: "RAIN", 3: "HEAVY_RAIN", 4: "STORM", 5: "VARIABLE"},
    "RaceMode": {0: "SINGLE_RACE", 1: "WEEKEND", 2: "QUICK_RACE", 3: "CHAMPIONSHIP", 4: "CHAMPIONSHIP_ALT", 5: "MULTIPLAYER", 6: "MONITOR"},
    "RaceActiveFlag": {0: "INACTIVE", 1: "ACTIVE"},
    "PauseFlag": {0: "RUNNING", 1: "PAUSED"},
    "FormationLap": {0: "NO", 1: "YES"},
    "InternalState": {2: "IDLE", 3: "LOADING", 4: "PROCESSING", 5: "READY", 6: "SESSION_END"},
}


class TraceController:
    def __init__(self, output_path=None, max_frames=0, quiet=False, state_only=False):
        self.session = None
        self.script = None
        self.output_path = output_path
        self.output_file = None
        self.max_frames = max_frames
        self.quiet = quiet
        self.state_only = state_only
        self.running = False
        self.total_lines = 0
        self.start_time = None

    def attach(self):
        try:
            self.session = frida.attach(PROCESS_NAME)
        except frida.ProcessNotFoundError:
            print(f"ERROR: '{PROCESS_NAME}' not running.")
            print("Start the game first, then run this script.")
            sys.exit(1)
        except frida.PermissionDeniedError:
            print("ERROR: Permission denied. Run as Administrator.")
            sys.exit(1)

        print(f"Attached to {PROCESS_NAME} (PID: {self.session._impl.pid})")

        agent_file = AGENT_STATE_JS if self.state_only else AGENT_JS
        agent_code = agent_file.read_text(encoding="utf-8")
        if self.state_only:
            print("State-only mode (no function hooks, minimal output)")
        self.script = self.session.create_script(agent_code)
        self.script.on("message", self._on_message)
        self.script.load()
        print("Agent loaded.")

    def _on_message(self, message, data):
        if message["type"] == "send":
            payload = message["payload"]
            msg_type = payload.get("type", "")

            if msg_type == "ready":
                print(f"Hooks installed: {payload['hooks']}")

            elif msg_type == "started":
                n = payload["maxFrames"]
                limit = f"{n} frames" if n > 0 else "unlimited"
                print(f"Trace started ({limit})")
                self.start_time = time.time()

            elif msg_type == "trace":
                lines = payload["lines"]
                self.total_lines += len(lines)
                if self.output_file:
                    for line in lines:
                        self.output_file.write(line + "\n")
                if not self.quiet:
                    for line in lines:
                        print(line)

            elif msg_type == "state_change":
                name = payload["name"]
                val = payload["newValue"]
                old = payload.get("oldValue", "?")
                writer = payload["writer"]
                t = payload["time"]
                friendly = STATE_NAMES.get(name, {}).get(val, "")
                old_friendly = STATE_NAMES.get(name, {}).get(old, "")
                label = f" ({friendly})" if friendly else ""
                old_label = f" ({old_friendly})" if old_friendly else ""
                msg = f"[STATE] {name}: {old}{old_label} -> {val}{label} @ {t}ms"
                print(msg)
                if self.output_file:
                    self.output_file.write(msg + "\n")

            elif msg_type == "state_init":
                name = payload["name"]
                val = payload["value"]
                friendly = STATE_NAMES.get(name, {}).get(val, "")
                label = f" ({friendly})" if friendly else ""
                print(f"  {name} = {val}{label}")

            elif msg_type == "state_watchers":
                print(f"State watchers: {', '.join(payload['names'])}")

            elif msg_type == "stopped":
                elapsed = time.time() - (self.start_time or time.time())
                print(f"\nTrace stopped. {payload['frames']} frames, "
                      f"{self.total_lines} log lines, {elapsed:.1f}s elapsed")
                self.running = False

            elif msg_type == "done":
                elapsed = time.time() - (self.start_time or time.time())
                print(f"\nCapture complete. {payload['frames']} frames, "
                      f"{self.total_lines} log lines, {elapsed:.1f}s elapsed")
                self.running = False

            elif msg_type == "error":
                print(f"AGENT ERROR: {payload['msg']}")

        elif message["type"] == "error":
            print(f"FRIDA ERROR: {message.get('description', message)}")

    def start_trace(self, frames=None):
        if frames is None:
            frames = self.max_frames

        if self.output_path:
            TRACE_DIR.mkdir(parents=True, exist_ok=True)
            out = TRACE_DIR / self.output_path
            self.output_file = open(out, "w", encoding="utf-8")
            ts = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            self.output_file.write(f"# F1C Runtime Trace — {ts}\n")
            self.output_file.write(f"# Format: elapsed_ms|thread_id|indent direction name [subsystem]\n")
            self.output_file.write(f"# Frames: {'unlimited' if frames == 0 else frames}\n\n")
            print(f"Output: {out}")

        self.running = True
        self.script.exports_sync.start(frames)

    def stop_trace(self):
        self.script.exports_sync.stop()
        if self.output_file:
            self.output_file.close()
            self.output_file = None

    def read_state(self):
        state = self.script.exports_sync.read_state()
        print("\n=== Game State Variables ===")
        for name, val in state.items():
            friendly = STATE_NAMES.get(name, {}).get(val, "")
            label = f" ({friendly})" if friendly else ""
            print(f"  {name}: {val}{label}")
        return state

    def read_global(self, address):
        val = self.script.exports_sync.read_global(address)
        print(f"Global @ {address}: {val}")
        return val

    def status(self):
        st = self.script.exports_sync.status()
        print(f"Enabled: {st['enabled']}, Frames: {st['frames']}, "
              f"Hooks: {st['hooks']}, Buffer: {st['bufferSize']}")
        return st

    def list_threads(self):
        if not self.session:
            return
        threads = self.session.enumerate_threads()
        print(f"\n=== Threads ({len(threads)}) ===")
        for t in threads:
            ctx = t.read_context()
            eip = ctx.get("pc", ctx.get("eip", 0))
            print(f"  TID {t.id}: state={t.state}, EIP=0x{eip:08x}")

    def detach(self):
        if self.output_file:
            self.output_file.close()
        if self.script:
            self.script.unload()
        if self.session:
            self.session.detach()
            print("Detached.")

    def interactive(self):
        print("\n=== Interactive Mode ===")
        print("Commands: start [N], stop, state, status, threads, global <addr>, quit")
        print()
        try:
            while True:
                try:
                    cmd = input("f1c> ").strip()
                except EOFError:
                    break
                if not cmd:
                    continue

                parts = cmd.split()
                verb = parts[0].lower()

                if verb == "quit" or verb == "q":
                    break
                elif verb == "start":
                    frames = int(parts[1]) if len(parts) > 1 else 0
                    if not self.output_path:
                        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
                        self.output_path = f"trace_{ts}.log"
                    self.start_trace(frames)
                elif verb == "stop":
                    self.stop_trace()
                elif verb == "state":
                    self.read_state()
                elif verb == "status":
                    self.status()
                elif verb == "threads":
                    self.list_threads()
                elif verb == "global" and len(parts) > 1:
                    self.read_global(parts[1])
                elif verb == "help":
                    print("start [N]  — start trace (N frames, 0=unlimited)")
                    print("stop       — stop trace")
                    print("state      — read state variables")
                    print("status     — show hook/buffer status")
                    print("threads    — list game threads")
                    print("global <addr> — read 4-byte value at address")
                    print("quit       — detach and exit")
                else:
                    print(f"Unknown: {verb}. Type 'help'.")
        except KeyboardInterrupt:
            pass
        finally:
            self.stop_trace()
            self.detach()


def main():
    parser = argparse.ArgumentParser(description="F1C Runtime Trace Controller")
    parser.add_argument("--frames", type=int, default=0,
                        help="Capture N frames then stop (0=interactive)")
    parser.add_argument("--output", "-o", type=str, default=None,
                        help="Output filename (saved in tools/trace/output/)")
    parser.add_argument("--state", action="store_true",
                        help="Just read current state variables and exit")
    parser.add_argument("--list-threads", action="store_true",
                        help="List game threads and exit")
    parser.add_argument("--quiet", "-q", action="store_true",
                        help="Suppress per-line console output (still writes to file)")
    parser.add_argument("--state-only", "-S", action="store_true",
                        help="State-only mode: no function hooks, only watch state variable writes. Tiny output.")
    args = parser.parse_args()

    if not args.output and args.frames > 0:
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        args.output = f"trace_{ts}_{args.frames}frames.log"

    ctrl = TraceController(
        output_path=args.output,
        max_frames=args.frames,
        quiet=args.quiet,
        state_only=args.state_only,
    )

    ctrl.attach()

    if args.state:
        ctrl.read_state()
        ctrl.detach()
        return

    if args.list_threads:
        ctrl.list_threads()
        ctrl.detach()
        return

    if args.frames > 0:
        ctrl.start_trace()
        print("Capturing... (Ctrl+C to abort)")
        try:
            while ctrl.running:
                time.sleep(0.5)
        except KeyboardInterrupt:
            print("\nAborted.")
        ctrl.stop_trace()
        ctrl.detach()
    else:
        ctrl.interactive()


if __name__ == "__main__":
    main()
