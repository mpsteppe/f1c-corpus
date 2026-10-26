#!/usr/bin/env python3
"""Attach the read-only MAS lifecycle Frida probe and write JSONL evidence."""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import sys
import threading
import time

import frida


DEFAULT_PROCESS = "F1 Challenge Online.exe"
HERE = Path(__file__).resolve().parent
DEFAULT_AGENT = HERE / "mas_lifecycle_probe.js"
DEFAULT_OUTPUT = HERE.parent / "reports" / "mas_lifecycle_runtime.jsonl"


def parser() -> argparse.ArgumentParser:
    result = argparse.ArgumentParser(
        description="Read-only MAS thread/lifecycle trace; never starts or modifies the game."
    )
    result.add_argument("--process", default=DEFAULT_PROCESS,
                        help="running process name or numeric PID")
    result.add_argument("--agent", type=Path, default=DEFAULT_AGENT)
    result.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    result.add_argument("--seconds", type=float, default=0.0,
                        help="stop after this many seconds; 0 waits for Ctrl+C")
    return result


def target(value: str):
    return int(value) if value.isdecimal() else value


def main() -> int:
    args = parser().parse_args()
    if args.seconds < 0:
        raise SystemExit("--seconds must be non-negative")
    source = args.agent.read_text(encoding="utf-8")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    events: list[dict] = []
    errors: list[dict] = []

    try:
        session = frida.attach(target(args.process))
    except frida.ProcessNotFoundError:
        print(f"process not found: {args.process}; start the game before attaching", file=sys.stderr)
        return 2
    except frida.PermissionDeniedError:
        print("Frida attach denied; run at the game's integrity level", file=sys.stderr)
        return 2
    detached = threading.Event()
    session.on("detached", lambda *unused: detached.set())
    script = session.create_script(source)

    with args.output.open("w", encoding="utf-8", buffering=1) as stream:
        def on_message(message, data):
            if message.get("type") == "send" and isinstance(message.get("payload"), dict):
                row = message["payload"]
                events.append(row)
            else:
                row = {"schema_version": 1, "kind": "frida_message", "message": message}
                errors.append(row)
            stream.write(json.dumps(row, sort_keys=True) + "\n")

        script.on("message", on_message)
        script.load()
        started = time.monotonic()
        try:
            while ((args.seconds == 0 or time.monotonic() - started < args.seconds)
                   and not detached.is_set()):
                time.sleep(0.25)
        except KeyboardInterrupt:
            pass
        finally:
            last_observed_list = next(
                (row["list"] for row in reversed(events)
                 if isinstance(row.get("list"), dict)
                 and row["list"].get("readable") is True),
                {"readable": False, "error": "no_readable_list_snapshot"})
            final_snapshot_source = "rpc"
            final_rpc_error = None
            try:
                final_snapshot = script.exports_sync.snapshot()
            except Exception as exc:  # target may exit before the final RPC
                final_snapshot = last_observed_list
                final_snapshot_source = "last_observed_before_detach"
                final_rpc_error = str(exc)
            final_row = {"schema_version": 1, "kind": "final_list_snapshot",
                         "list": final_snapshot, "source": final_snapshot_source,
                         "rpc_error": final_rpc_error,
                         "timestamp_ms": round(time.time() * 1000)}
            events.append(final_row)
            stream.write(json.dumps(final_row, sort_keys=True) + "\n")
            if not detached.is_set():
                script.unload()
                session.detach()

    mutation_names = {"mas_root_load", "mas_remove_one", "mas_prune_marked"}
    mutation_threads = sorted({row.get("thread_id") for row in events
                               if row.get("kind") == "call_enter"
                               and row.get("function") in mutation_names})
    main_threads = sorted({row.get("thread_id") for row in events
                           if row.get("kind") == "thread_marker"
                           and row.get("function") in {"game_main_entry", "main_loop_tick"}})
    network_threads = sorted({row.get("thread_id") for row in events
                              if row.get("kind") == "thread_marker"
                              and row.get("function") == "network_thread_entry"})
    bad_lists = [row for row in events if row.get("kind") != "final_list_snapshot"
                 and isinstance(row.get("list"), dict)
                 and (row["list"].get("count_matches") is False
                      or row["list"].get("reciprocal_back_links") is False
                      or row["list"].get("error"))]
    zero_without_object = [row for row in events
                           if row.get("kind") == "call_leave"
                           and row.get("function") in {"mas_root_load", "mas_checked_load_bridge"}
                           and row.get("result") == 0 and row.get("output_value") in {None, "0x0"}]
    summary = {
        "schema_version": 1,
        "read_only": True,
        "event_count": len(events),
        "frida_errors": len(errors),
        "mutation_thread_ids": mutation_threads,
        "game_main_thread_ids": main_threads,
        "network_thread_ids": network_threads,
        "single_mutation_thread_observed": len(mutation_threads) == 1,
        "mutations_match_observed_main_thread": bool(main_threads)
        and mutation_threads == main_threads,
        "mutation_seen_on_network_thread": bool(set(mutation_threads) & set(network_threads)),
        "list_invariant_failures": len(bad_lists),
        "zero_result_without_object": len(zero_without_object),
        "final_list": final_snapshot,
        "final_list_source": final_snapshot_source,
        "final_rpc_error": final_rpc_error,
        "final_list_empty": final_snapshot.get("declared_count") == 0
        and final_snapshot.get("traversed_count") == 0,
        "output": str(args.output.resolve()),
        "limitations": [
            "A clean trace supports only the exercised loading and shutdown paths.",
            "Frida hooks observe calls but do not prove absence of unhooked direct memory mutation.",
            "No target memory is written by this probe."
        ]
    }
    print(json.dumps(summary, indent=2))
    return 1 if errors or bad_lists or summary["mutation_seen_on_network_thread"] else 0


if __name__ == "__main__":
    sys.exit(main())
