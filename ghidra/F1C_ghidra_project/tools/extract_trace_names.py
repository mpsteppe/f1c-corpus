"""Extract original class::method names and source-file mappings from ida_strings.csv.

Outputs:
  tools/trace_rename_table.csv   — 60 confirmed function renames from "Entered X::Y()" strings
  tools/source_file_map.csv      — source file -> function address mapping from .cpp path strings
  tools/trace_caller_strings.csv — all strings referenced by functions that call FUN_004d7a50
"""

import csv
import re
import json
import os

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_DIR = os.path.dirname(SCRIPT_DIR)

IDA_STRINGS = os.path.join(SCRIPT_DIR, "ida_strings.csv")
CALL_GRAPH = os.path.join(PROJECT_DIR, "knowledge_graph", "call_graph.json")
CALLERS_GRAPH = os.path.join(PROJECT_DIR, "knowledge_graph", "callers.json")

OUT_RENAME = os.path.join(SCRIPT_DIR, "trace_rename_table.csv")
OUT_SOURCE_MAP = os.path.join(SCRIPT_DIR, "source_file_map.csv")
OUT_CALLER_STRINGS = os.path.join(SCRIPT_DIR, "trace_caller_strings.csv")

TRACE_EMIT = "0x004d7a50"
TRACE_WRITE = "0x004d7aa0"


def load_strings():
    rows = []
    with open(IDA_STRINGS, "r", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            refs = [r.strip() for r in row["ref_funcs"].split("|") if r.strip()] if row["ref_funcs"] else []
            rows.append({"addr": row["addr"], "value": row["value"], "ref_funcs": refs})
    return rows


def extract_entered_names(strings):
    """Parse 'Entered Class::Method()' and other Class::Method strings into rename table."""
    renames = []
    seen = set()
    entered = re.compile(r"^Entered (\w+)::(\w+)\(\)$")
    general = re.compile(r"(\w+)::(\w+)")

    # First pass: high-confidence "Entered" strings
    for s in strings:
        m = entered.match(s["value"])
        if m and s["ref_funcs"]:
            class_name = m.group(1)
            method_name = m.group(2)
            for func_addr in s["ref_funcs"]:
                key = (func_addr, class_name, method_name)
                if key not in seen:
                    seen.add(key)
                    renames.append({
                        "address": func_addr,
                        "class": class_name,
                        "method": method_name,
                        "full_name": f"{class_name}::{method_name}",
                        "source": "entered",
                        "string_addr": s["addr"],
                    })

    # Second pass: other Class::Method references (error messages, etc.)
    skip_classes = {"ios", "std", "basic"}
    for s in strings:
        if s["value"].startswith("Entered "):
            continue
        for m in general.finditer(s["value"]):
            class_name = m.group(1)
            method_name = m.group(2)
            if class_name.lower() in skip_classes:
                continue
            if s["ref_funcs"]:
                for func_addr in s["ref_funcs"]:
                    key = (func_addr, class_name, method_name)
                    if key not in seen:
                        seen.add(key)
                        renames.append({
                            "address": func_addr,
                            "class": class_name,
                            "method": method_name,
                            "full_name": f"{class_name}::{method_name}",
                            "source": "error_string",
                            "string_addr": s["addr"],
                        })

    renames.sort(key=lambda r: int(r["address"], 16))
    return renames


def extract_source_map(strings):
    """Parse D:\\dev\\F1_1999_2002\\Source\\*.cpp strings into source file map."""
    source_map = []
    pattern = re.compile(r"D:\\dev\\F1_1999_2002\\Source\\(.+\.cpp)", re.IGNORECASE)
    for s in strings:
        m = pattern.search(s["value"])
        if m and s["ref_funcs"]:
            filename = m.group(1)
            addrs = sorted(set(s["ref_funcs"]), key=lambda a: int(a, 16))
            addr_min = min(addrs, key=lambda a: int(a, 16))
            addr_max = max(addrs, key=lambda a: int(a, 16))
            source_map.append({
                "source_file": filename,
                "func_count": len(addrs),
                "addr_min": addr_min,
                "addr_max": addr_max,
                "addresses": "|".join(addrs),
            })
    source_map.sort(key=lambda r: int(r["addr_min"], 16))
    return source_map


def find_trace_callers():
    """Find all functions that call the trace emit function."""
    callers = set()
    targets = {TRACE_EMIT, TRACE_WRITE}

    # callers.json: { "0xADDR": [ {"caller": "0xADDR", ...}, ... ] }
    try:
        with open(CALLERS_GRAPH, "r", encoding="utf-8") as f:
            data = json.load(f)
        for addr in targets:
            if addr in data:
                for entry in data[addr]:
                    callers.add(entry["caller"])
    except (FileNotFoundError, json.JSONDecodeError, KeyError):
        pass

    if not callers:
        # call_graph.json: { "0xADDR": [ {"callee": "0xADDR", ...}, ... ] }
        try:
            with open(CALL_GRAPH, "r", encoding="utf-8") as f:
                data = json.load(f)
            for caller_addr, edges in data.items():
                for edge in edges:
                    if edge.get("callee") in targets:
                        callers.add(caller_addr)
        except (FileNotFoundError, json.JSONDecodeError):
            pass

    return callers


def extract_caller_strings(strings, callers):
    """Find all strings referenced by trace-emitting functions."""
    results = []
    for s in strings:
        for ref in s["ref_funcs"]:
            if ref in callers:
                results.append({
                    "caller_address": ref,
                    "string_addr": s["addr"],
                    "value": s["value"],
                })
    results.sort(key=lambda r: (int(r["caller_address"], 16), int(r["string_addr"], 16)))
    return results


def main():
    print("Loading ida_strings.csv...")
    strings = load_strings()
    print(f"  {len(strings)} strings loaded")

    # 1. Rename table
    renames = extract_entered_names(strings)
    with open(OUT_RENAME, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["address", "class", "method", "full_name", "source", "string_addr"])
        w.writeheader()
        for r in renames:
            w.writerow(r)
    print(f"\n=== RENAME TABLE: {len(renames)} confirmed renames -> {OUT_RENAME}")

    classes = {}
    for r in renames:
        classes.setdefault(r["class"], []).append(r["method"])
    print(f"  {len(classes)} classes: {', '.join(sorted(classes.keys()))}")
    for cls in sorted(classes.keys()):
        methods = sorted(classes[cls])
        print(f"    {cls}: {', '.join(methods)}")

    # 2. Source file map
    source_map = extract_source_map(strings)
    with open(OUT_SOURCE_MAP, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["source_file", "func_count", "addr_min", "addr_max", "addresses"])
        w.writeheader()
        for r in source_map:
            w.writerow(r)
    print(f"\n=== SOURCE FILE MAP: {len(source_map)} source files -> {OUT_SOURCE_MAP}")
    total_funcs = sum(r["func_count"] for r in source_map)
    print(f"  {total_funcs} function-to-source assignments")
    for r in source_map:
        print(f"    {r['source_file']:25s}  {r['func_count']:3d} funcs  [{r['addr_min']}..{r['addr_max']}]")

    # 3. Trace caller strings
    print("\nFinding trace emit callers...")
    callers = find_trace_callers()
    print(f"  {len(callers)} functions call trace emit")

    caller_strings = extract_caller_strings(strings, callers)
    with open(OUT_CALLER_STRINGS, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["caller_address", "string_addr", "value"])
        w.writeheader()
        for r in caller_strings:
            w.writerow(r)
    print(f"\n=== TRACE CALLER STRINGS: {len(caller_strings)} strings from {len(callers)} callers -> {OUT_CALLER_STRINGS}")

    # Extract additional names from caller strings
    name_patterns = [
        re.compile(r"Entered (\w+::\w+)\(\)"),
        re.compile(r"(\w+::\w+)\(\)"),
        re.compile(r"(\w+)::(\w+)"),
    ]
    extra_names = set()
    for cs in caller_strings:
        for pat in name_patterns:
            for m in pat.finditer(cs["value"]):
                extra_names.add(m.group(0))

    entered_names = {r["full_name"] for r in renames}
    novel = extra_names - {f"Entered {n}()" for n in entered_names} - entered_names
    if novel:
        print(f"\n=== ADDITIONAL CLASS::METHOD REFERENCES in trace strings ({len(novel)}):")
        for n in sorted(novel):
            print(f"    {n}")


if __name__ == "__main__":
    main()
