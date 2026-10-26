#!/usr/bin/env python3
"""Validate and summarize read-only MAS path-probe JSONL evidence."""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path


def clean_preview(value: object) -> object:
    """Remove the known capture-v1 sized-read terminator rendering artifact."""
    if isinstance(value, str) and value.endswith("\ufffd"):
        return value[:-1]
    return value


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("trace", type=Path)
    parser.add_argument("--json", type=Path)
    parser.add_argument("--capture-v1-preview-artifact", action="store_true")
    args = parser.parse_args()
    raw = args.trace.read_bytes()
    rows = [json.loads(line) for line in raw.decode("utf-8").splitlines()]
    roots = [row for row in rows if row.get("kind") == "root_enter"]
    leaves = [row for row in rows if row.get("kind") == "root_leave"]
    attempts = [row for row in rows if row.get("kind") == "open_attempt"]
    errors = [row for row in rows if row.get("kind") == "frida_message"]

    calls = []
    for root in roots:
        call_id = root["call_id"]
        related = [row for row in attempts if row.get("call_id") == call_id]
        leave = next((row for row in leaves if row.get("call_id") == call_id), None)
        filename = root["filename"]
        preview = filename.get("preview")
        if args.capture_v1_preview_artifact:
            preview = clean_preview(preview)
        call_attempts = []
        for row in related:
            path = row["path"].get("preview")
            if args.capture_v1_preview_artifact:
                path = clean_preview(path)
            call_attempts.append({
                "site": row["site"], "path": path,
                "path_length": row["path"].get("terminator_offset"),
                "terminated": row["path"].get("terminated_within_limit"),
                "succeeded": row["succeeded"],
                "return_address": row["return_address"],
            })
        prefixes = []
        for entry in root.get("prefixes", {}).get("entries", []):
            value = entry["value"]
            text = value.get("preview")
            if args.capture_v1_preview_artifact:
                text = clean_preview(text)
            prefixes.append({
                "index": entry["index"], "path": text,
                "length": value.get("terminator_offset"),
                "terminated": value.get("terminated_within_limit"),
            })
        calls.append({
            "call_id": call_id,
            "filename": preview,
            "filename_length": filename.get("terminator_offset"),
            "filename_terminated": filename.get("terminated_within_limit"),
            "prefixes": prefixes,
            "attempts": call_attempts,
            "result": None if leave is None else leave.get("result"),
        })

    direct_first_fail_then_fallback = 0
    for call in calls:
        root_attempts = [a for a in call["attempts"]
                         if a["site"] in {"root_direct", "root_fallback"}]
        if (len(root_attempts) >= 2 and root_attempts[0]["site"] == "root_direct"
                and root_attempts[0]["succeeded"] is False
                and root_attempts[1]["site"] == "root_fallback"):
            direct_first_fail_then_fallback += 1

    summary = {
        "schema": "f1c.mas_path_runtime_summary.v1",
        "read_only": True,
        "trace": str(args.trace.resolve()),
        "trace_size": len(raw),
        "trace_sha256": hashlib.sha256(raw).hexdigest().upper(),
        "capture_v1_preview_artifact_normalized": args.capture_v1_preview_artifact,
        "event_count": len(rows),
        "frida_errors": len(errors),
        "root_calls": len(roots),
        "completed_root_calls": len(leaves),
        "open_attempts": len(attempts),
        "direct_attempts": sum(row.get("site") == "root_direct" for row in attempts),
        "fallback_attempts": sum(row.get("site") == "root_fallback" for row in attempts),
        "direct_failure_then_fallback_calls": direct_first_fail_then_fallback,
        "unterminated_root_inputs_within_1024": sum(
            call["filename_terminated"] is False for call in calls),
        "max_root_filename_length": max(
            (call["filename_length"] for call in calls
             if isinstance(call["filename_length"], int)), default=-1),
        "calls": calls,
        "limitations": [
            "Only paths exercised during the capture are supported by runtime evidence.",
            "No collision between a direct file and prefixed file was created.",
            "No overlong or unterminated input was injected.",
        ],
    }
    encoded = json.dumps(summary, indent=2) + "\n"
    if args.json:
        args.json.write_text(encoded, encoding="utf-8", newline="\n")
    print(encoded, end="")


if __name__ == "__main__":
    main()
