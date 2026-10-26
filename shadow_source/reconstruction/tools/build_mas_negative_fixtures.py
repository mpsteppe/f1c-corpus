#!/usr/bin/env python3
"""Build and verify deterministic MAS loader boundary fixtures.

These fixtures encode the proposed replacement policy, not claims about every
quirk of the original executable.  They never touch installed game content.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path


MAGIC_410 = b"CUBEMAS4.10\0"
RECORD_SIZE = 256


def header(magic: bytes, reserved: int, count: int, total: int) -> bytes:
    return magic + struct.pack("<III", reserved, count, total)


def record(raw_size: int = 0, stored_size: int = 0, region: int = 0,
           name: bytes = b"fixture") -> bytes:
    value = bytearray(RECORD_SIZE)
    struct.pack_into("<III", value, 8, raw_size, stored_size, region)
    value[20:20 + min(len(name), 235)] = name[:235]
    return bytes(value)


def fixture_cases() -> list[dict[str, object]]:
    full_record = record()
    cases: list[dict[str, object]] = [
        {"name": "empty.bin", "data": b"", "expected": "reject_-1",
         "reason": "empty header"},
        {"name": "header_1_byte.bin", "data": b"C", "expected": "reject_-1",
         "reason": "short header read"},
        {"name": "header_11_bytes.bin", "data": MAGIC_410[:11],
         "expected": "reject_-1", "reason": "short header read"},
        {"name": "version_400.bin", "data": b"CUBEMAS4.00\0",
         "expected": "reject_-1", "reason": "obsolete version"},
        {"name": "version_401.bin", "data": b"CUBEMAS4.01\0",
         "expected": "reject_-1", "reason": "obsolete version"},
        {"name": "version_unknown.bin", "data": b"CUBEMAS9.99\0",
         "expected": "reject_-1", "reason": "unknown version"},
        {"name": "410_only.bin", "data": MAGIC_410, "expected": "reject_-1",
         "reason": "missing fixed fields"},
        {"name": "410_15_bytes.bin", "data": MAGIC_410 + b"\0" * 3,
         "expected": "reject_-1", "reason": "short fixed-field read"},
        {"name": "410_23_bytes.bin", "data": MAGIC_410 + b"\0" * 11,
         "expected": "reject_-1", "reason": "short fixed-field read"},
        {"name": "count_zero.bin", "data": header(MAGIC_410, 0, 0, 0),
         "expected": "reject_-1", "reason": "zero directory count is not observed"},
        {"name": "count_shift_overflow.bin",
         "data": header(MAGIC_410, 0, 0x01000000, 0),
         "expected": "reject_-1", "reason": "count << 8 wraps in 32 bits"},
        {"name": "directory_beyond_eof.bin", "data": header(MAGIC_410, 0, 2, 0),
         "expected": "reject_-1", "reason": "declared directory exceeds file"},
        {"name": "payload_beyond_eof.bin",
         "data": header(MAGIC_410, 0, 1, 1) + record(1, 1),
         "expected": "reject_-1", "reason": "stored payload range exceeds file"},
        {"name": "stored_sum_overflow.bin",
         "data": header(MAGIC_410, 0, 2, 0) + record(1, 0xFFFFFFFF) + record(1, 2),
         "expected": "reject_-1", "reason": "stored-size accumulation overflows 32 bits"},
        {"name": "valid_minimal_410.bin",
         "data": header(MAGIC_410, 0, 1, 0) + full_record,
         "expected": "accept", "reason": "minimal bounded 4.10 control"},
        {"name": "valid_stale_total_410.bin",
         "data": header(MAGIC_410, 0, 1, 12345) + full_record,
         "expected": "accept", "reason": "header total is advisory in installed corpus"},
        {"name": "valid_trailing_bytes_410.bin",
         "data": header(MAGIC_410, 0, 1, 0) + full_record + b"TRAILING",
         "expected": "accept", "reason": "exact EOF equality is not required"},
    ]
    return cases


def build(output: Path) -> None:
    output.mkdir(parents=True, exist_ok=True)
    entries = []
    expected_names = set()
    for case in fixture_cases():
        name = str(case["name"])
        data = bytes(case["data"])
        expected_names.add(name)
        (output / name).write_bytes(data)
        entries.append({
            "file": name,
            "size": len(data),
            "sha256": hashlib.sha256(data).hexdigest().upper(),
            "expected": case["expected"],
            "reason": case["reason"],
        })

    manifest = {
        "schema": "f1c.mas_negative_fixtures.v1",
        "policy": "proposed replacement behavior; not original runtime equivalence",
        "fixtures": entries,
        "fault_injection": [
            {"case": "object_allocation_failure", "expected": "reject_-1",
             "invariant": "parser not called; output/list/count unchanged"},
            {"case": "payload_allocation_failure", "expected": "reject_-1",
             "invariant": "cleanup exactly once; output/list/count unchanged"},
            {"case": "parser_returns_-2", "expected": "reject_-2",
             "invariant": "cleanup exactly once; output/list/count unchanged"},
            {"case": "parser_returns_unexpected_nonzero", "expected": "reject_-1",
             "invariant": "cleanup exactly once; output/list/count unchanged"},
        ],
    }
    (output / "manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8", newline="\n")

    for old in output.glob("*.bin"):
        if old.name not in expected_names:
            raise SystemExit(f"unexpected stale fixture: {old}")


def verify(output: Path) -> None:
    manifest = json.loads((output / "manifest.json").read_text(encoding="utf-8"))
    if manifest.get("schema") != "f1c.mas_negative_fixtures.v1":
        raise SystemExit("wrong manifest schema")
    expected = {str(case["name"]): bytes(case["data"]) for case in fixture_cases()}
    listed = {entry["file"]: entry for entry in manifest["fixtures"]}
    if set(listed) != set(expected):
        raise SystemExit("manifest fixture set differs from builder")
    for name, wanted in expected.items():
        actual = (output / name).read_bytes()
        digest = hashlib.sha256(actual).hexdigest().upper()
        if actual != wanted or listed[name]["size"] != len(actual) or listed[name]["sha256"] != digest:
            raise SystemExit(f"fixture verification failed: {name}")
    print(f"VALID: {len(expected)} file fixtures and {len(manifest['fault_injection'])} fault cases")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("command", choices=("build", "verify"))
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    (build if args.command == "build" else verify)(args.output.resolve())


if __name__ == "__main__":
    main()
