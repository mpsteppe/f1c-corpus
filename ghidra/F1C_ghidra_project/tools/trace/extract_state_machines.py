#!/usr/bin/env python3
"""
Extract state machine information from decompiled .c files.
Finds all reads and writes to state variables and builds transition tables.
"""

import json
import os
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).parent.parent.parent
ANALYZED = ROOT / "analysis_pipeline" / "analyzed"
DECOMPILED_ALL = ROOT / "decompiled_all"
FUNCS_JSON = ROOT / "knowledge_graph" / "functions.json"

STATE_VARS = {
    "DAT_007d00ec": {"name": "GameState", "known_values": {
        1: "INIT", 2: "MENU", 3: "LOADING", 4: "SETUP", 5: "RUNNING", 6: "QUALIFYING?", 7: "RACE"
    }},
    "DAT_007c56a4": {"name": "SessionType", "known_values": {
        0: "PRACTICE_FP1", 1: "PRACTICE_FP2", 2: "PRACTICE_FP3", 3: "PRACTICE_FP4",
        4: "PRACTICE_FP5", 5: "SERVER", 6: "QUALIFYING", 7: "RACE"
    }},
    "DAT_007c56a8": {"name": "RacePhase", "known_values": {
        0: "PRE_START", 1: "FORMATION", 2: "GREEN_FLAG", 3: "RACING",
        4: "CAUTION", 5: "RED_FLAG", 6: "CHECKERED", 7: "POST_RACE", 8: "DONE"
    }},
    "DAT_007cf080": {"name": "WeatherMode", "known_values": {
        0: "DRY", 1: "LIGHT_RAIN", 2: "RAIN", 3: "HEAVY_RAIN", 4: "STORM", 5: "VARIABLE"
    }},
    "DAT_007d0410": {"name": "RaceMode", "known_values": {
        0: "SINGLE_RACE", 1: "WEEKEND", 2: "QUICK_RACE", 3: "CHAMPIONSHIP", 4: "CHAMPIONSHIP_ALT"
    }},
    "DAT_007d0308": {"name": "RaceActiveFlag", "known_values": {0: "INACTIVE", 1: "ACTIVE"}},
    "DAT_007c56ac": {"name": "PauseFlag", "known_values": {0: "RUNNING", 1: "PAUSED"}},
    "DAT_007cebc4": {"name": "FormationLapFlag", "known_values": {0: "NO", 1: "YES"}},
}


def func_name(addr_str, funcs):
    f = funcs.get(addr_str, {})
    return (f.get("summary") or "unknown")[:50]


def extract_from_file(filepath, funcs):
    try:
        content = filepath.read_text(encoding="utf-8", errors="replace")
    except Exception:
        return []

    # Get function address from filename
    m = re.search(r"0x([0-9a-fA-F]{8})", filepath.name)
    func_addr = f"0x{m.group(1)}" if m else "unknown"

    results = []
    lines = content.split("\n")

    for i, line in enumerate(lines):
        for var, info in STATE_VARS.items():
            if var not in line:
                continue

            # Check if it's a write (assignment, not comparison)
            write_match = re.search(rf"{re.escape(var)}\s*=\s*([^=;]+);", line)
            # Check if it's a read (comparison)
            read_match = re.search(rf"{re.escape(var)}\s*==\s*(\d+)", line)
            # Check for != comparison
            neq_match = re.search(rf"{re.escape(var)}\s*!=\s*(\d+)", line)
            # Check for < or > comparison
            cmp_match = re.search(rf"{re.escape(var)}\s*([<>]=?)\s*(\d+)", line)

            if write_match:
                val_str = write_match.group(1).strip()
                # Try to extract numeric value
                try:
                    val = int(val_str)
                    val_name = info["known_values"].get(val, "?")
                except ValueError:
                    val = val_str
                    val_name = "dynamic"

                results.append({
                    "var": var,
                    "var_name": info["name"],
                    "type": "write",
                    "value": val,
                    "value_name": val_name,
                    "func": func_addr,
                    "line": i + 1,
                    "context": line.strip()[:120],
                })

            if read_match:
                val = int(read_match.group(1))
                val_name = info["known_values"].get(val, "?")
                results.append({
                    "var": var,
                    "var_name": info["name"],
                    "type": "read_eq",
                    "value": val,
                    "value_name": val_name,
                    "func": func_addr,
                    "line": i + 1,
                    "context": line.strip()[:120],
                })

            if neq_match:
                val = int(neq_match.group(1))
                val_name = info["known_values"].get(val, "?")
                results.append({
                    "var": var,
                    "var_name": info["name"],
                    "type": "read_neq",
                    "value": val,
                    "value_name": val_name,
                    "func": func_addr,
                    "line": i + 1,
                    "context": line.strip()[:120],
                })

    return results


def main():
    sys.stdout.reconfigure(encoding="utf-8")

    print("Loading function metadata...")
    funcs = json.load(open(FUNCS_JSON, encoding="utf-8"))

    print("Scanning .c files...")
    all_results = []
    dirs = [ANALYZED, DECOMPILED_ALL]
    for d in dirs:
        if not d.exists():
            continue
        for f in d.glob("*.c"):
            results = extract_from_file(f, funcs)
            all_results.extend(results)

    print(f"Found {len(all_results)} state variable references")

    # Group by variable
    by_var = defaultdict(list)
    for r in all_results:
        by_var[r["var_name"]].append(r)

    # Generate output
    output = []
    output.append("# State Machine Analysis")
    output.append("")
    output.append(f"Extracted from {len(all_results)} state variable references across .c files.")
    output.append("")

    for var_name in ["GameState", "SessionType", "RacePhase", "WeatherMode", "RaceMode",
                     "RaceActiveFlag", "PauseFlag", "FormationLapFlag"]:
        refs = by_var.get(var_name, [])
        if not refs:
            continue

        var_addr = [k for k, v in STATE_VARS.items() if v["name"] == var_name][0]
        info = STATE_VARS[var_addr]

        writes = [r for r in refs if r["type"] == "write"]
        reads_eq = [r for r in refs if r["type"] == "read_eq"]
        reads_neq = [r for r in refs if r["type"] == "read_neq"]

        # Collect observed values
        observed_values = set()
        for r in reads_eq + reads_neq:
            if isinstance(r["value"], int):
                observed_values.add(r["value"])
        for r in writes:
            if isinstance(r["value"], int):
                observed_values.add(r["value"])

        output.append(f"## {var_name} ({var_addr})")
        output.append("")
        output.append(f"Writers: {len(writes)} | Equality checks: {len(reads_eq)} | Inequality checks: {len(reads_neq)}")
        output.append("")

        # Value table
        output.append("### Known Values")
        output.append("")
        output.append("| Value | Name | Eq checks | Neq checks | Writes |")
        output.append("|-------|------|-----------|------------|--------|")
        for val in sorted(observed_values):
            name = info["known_values"].get(val, "?")
            eq_count = len([r for r in reads_eq if r["value"] == val])
            neq_count = len([r for r in reads_neq if r["value"] == val])
            w_count = len([r for r in writes if r["value"] == val])
            output.append(f"| {val} | {name} | {eq_count} | {neq_count} | {w_count} |")
        output.append("")

        # Writer functions
        if writes:
            output.append("### Writers")
            output.append("")
            output.append("| Function | Value | Context |")
            output.append("|----------|-------|---------|")
            for w in writes:
                fname = func_name(w["func"], funcs)
                val = w["value"]
                vname = w["value_name"]
                ctx = w["context"][:80]
                output.append(f"| {w['func']} ({fname}) | {val} ({vname}) | `{ctx}` |")
            output.append("")

        # Per-value usage: which subsystems check for which values
        output.append("### Usage by Value")
        output.append("")
        for val in sorted(observed_values):
            name = info["known_values"].get(val, "?")
            checkers = [r for r in reads_eq if r["value"] == val]
            if not checkers:
                continue
            checker_funcs = set()
            for c in checkers:
                fn = func_name(c["func"], funcs)
                checker_funcs.add(f'{c["func"]} ({fn})')

            output.append(f"**Value {val} ({name})** — checked by {len(checker_funcs)} functions:")
            for cf in sorted(checker_funcs)[:10]:
                output.append(f"  - {cf}")
            if len(checker_funcs) > 10:
                output.append(f"  - ... and {len(checker_funcs)-10} more")
            output.append("")

    text = "\n".join(output)
    outpath = ROOT / "docs" / "15-state-machines.md"
    outpath.write_text(text, encoding="utf-8")
    print(f"Written to {outpath}")
    print(f"  Size: {len(text)} bytes, {len(output)} lines")


if __name__ == "__main__":
    main()
