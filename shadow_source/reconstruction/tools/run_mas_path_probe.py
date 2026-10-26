#!/usr/bin/env python3
"""Attach the read-only MAS path probe and persist JSONL evidence."""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import sys
import threading
import time

import frida


HERE = Path(__file__).resolve().parent


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--process", default="F1 Challenge Online.exe")
    parser.add_argument("--agent", type=Path, default=HERE / "mas_path_probe.js")
    parser.add_argument("--output", type=Path,
                        default=HERE.parent / "reports" / "mas_path_runtime.jsonl")
    parser.add_argument("--seconds", type=float, default=30.0)
    args = parser.parse_args()
    if args.seconds <= 0:
        raise SystemExit("--seconds must be positive")

    target = int(args.process) if args.process.isdecimal() else args.process
    try:
        session = frida.attach(target)
    except frida.ProcessNotFoundError:
        print(f"process not found: {args.process}", file=sys.stderr)
        return 2
    detached = threading.Event()
    session.on("detached", lambda *unused: detached.set())
    script = session.create_script(args.agent.read_text(encoding="utf-8"))
    rows: list[dict] = []
    errors: list[dict] = []
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open("w", encoding="utf-8", buffering=1, newline="\n") as stream:
        def on_message(message, data):
            if message.get("type") == "send" and isinstance(message.get("payload"), dict):
                row = message["payload"]
                rows.append(row)
            else:
                row = {"schema_version": 1, "kind": "frida_message", "message": message}
                errors.append(row)
            stream.write(json.dumps(row, sort_keys=True) + "\n")

        script.on("message", on_message)
        script.load()
        end = time.monotonic() + args.seconds
        while time.monotonic() < end and not detached.is_set():
            time.sleep(0.25)
        if not detached.is_set():
            script.unload()
            session.detach()

    roots = [row for row in rows if row.get("kind") == "root_enter"]
    attempts = [row for row in rows if row.get("kind") == "open_attempt"]
    prefixes = next((row.get("prefixes") for row in rows
                     if row.get("kind") == "probe_ready"), None)
    summary = {
        "schema_version": 1,
        "read_only": True,
        "event_count": len(rows),
        "frida_errors": len(errors),
        "root_calls": len(roots),
        "open_attempts": len(attempts),
        "direct_attempts": sum(row.get("site") == "root_direct" for row in attempts),
        "fallback_attempts": sum(row.get("site") == "root_fallback" for row in attempts),
        "unterminated_root_inputs_within_1024": sum(
            row.get("filename", {}).get("terminated_within_limit") is False for row in roots),
        "max_root_filename_length": max(
            (row.get("filename", {}).get("terminator_offset", -1) for row in roots), default=-1),
        "prefixes": prefixes,
        "output": str(args.output.resolve()),
        "limitations": [
            "Observation covers only calls executed during this capture window.",
            "No malformed filename or fallback collision is injected.",
            "The probe never writes target memory or calls target functions."
        ]
    }
    print(json.dumps(summary, indent=2))
    return 1 if errors else 0


if __name__ == "__main__":
    sys.exit(main())
