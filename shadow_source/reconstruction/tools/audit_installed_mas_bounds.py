#!/usr/bin/env python3
"""Read-only structural audit of installed CUBEMAS4.10 archives."""

from __future__ import annotations

import argparse
import json
import struct
from collections import Counter
from pathlib import Path


MAGIC = b"CUBEMAS4.10\0"
RECORD_SIZE = 256


def audit(root: Path) -> dict[str, object]:
    files = list(root.rglob("*.MAS")) + list(root.rglob("*.mas"))
    files = sorted(set(files), key=lambda path: str(path).lower())
    rows = []
    headers = Counter()
    invalid_directory = []
    payload_mismatches = []
    total_mismatches = []
    counts = []
    sizes = []
    totals = []
    for path in files:
        data = path.read_bytes()
        sizes.append(len(data))
        headers[data[:12].hex().upper()] += 1
        if len(data) < 24 or data[:12] != MAGIC:
            continue
        reserved, count, total = struct.unpack_from("<III", data, 12)
        counts.append(count)
        totals.append(total)
        directory_end = 24 + count * RECORD_SIZE
        if directory_end > len(data):
            invalid_directory.append(str(path))
            continue
        stored_sum = sum(struct.unpack_from("<I", data, 24 + i * RECORD_SIZE + 12)[0]
                         for i in range(count))
        payload_size = len(data) - directory_end
        if total != payload_size:
            total_mismatches.append({"path": str(path), "delta": payload_size - total})
        if stored_sum != payload_size:
            payload_mismatches.append({
                "path": str(path), "payload_size": payload_size,
                "stored_size_sum": stored_sum, "delta": payload_size - stored_sum,
            })
        rows.append((reserved, count, total))
    return {
        "schema": "f1c.installed_mas_bounds_audit.v1",
        "root": str(root),
        "file_count": len(files),
        "header_hex_counts": dict(headers),
        "parsed_410_count": len(rows),
        "reserved_field_counts": dict(Counter(str(row[0]) for row in rows)),
        "count": {"min": min(counts), "max": max(counts), "zero": counts.count(0)},
        "file_size": {"min": min(sizes), "max": max(sizes)},
        "header_total": {"min": min(totals), "max": max(totals)},
        "directory_beyond_eof": invalid_directory,
        "header_total_vs_payload_mismatch_count": len(total_mismatches),
        "header_total_delta_signs": dict(Counter(
            "positive" if item["delta"] > 0 else "negative" for item in total_mismatches)),
        "stored_sum_vs_payload_mismatches": payload_mismatches,
        "conclusion": (
            "Validate directory and per-record stored ranges with checked arithmetic. "
            "Do not require header total or exact EOF equality."
        ),
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("root", type=Path)
    parser.add_argument("--json", type=Path)
    args = parser.parse_args()
    result = audit(args.root.resolve())
    encoded = json.dumps(result, indent=2) + "\n"
    if args.json:
        args.json.write_text(encoded, encoding="utf-8", newline="\n")
    print(encoded, end="")


if __name__ == "__main__":
    main()
