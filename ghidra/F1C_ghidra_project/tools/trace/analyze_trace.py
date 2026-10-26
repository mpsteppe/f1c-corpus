#!/usr/bin/env python3
"""
Analyze F1C trace output to produce frame loop documentation.

Usage:
    python analyze_trace.py output/trace_XXXX.log
    python analyze_trace.py output/trace_XXXX.log --summary
    python analyze_trace.py output/trace_XXXX.log --threads
    python analyze_trace.py output/trace_XXXX.log --frame 5
"""

import argparse
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path


def parse_trace(path):
    """Parse trace log into structured entries."""
    entries = []
    state_changes = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            line = line.rstrip()
            if not line or line.startswith("#"):
                continue

            # State change lines
            if line.startswith("[STATE]"):
                state_changes.append(line)
                continue

            # Trace line: elapsed_ms|thread_id|indent direction name [subsystem]
            parts = line.split("|", 2)
            if len(parts) < 3:
                continue

            try:
                elapsed = int(parts[0])
            except ValueError:
                continue

            tid = parts[1].strip()
            rest = parts[2]

            # Parse indent, direction, name, subsystem
            stripped = rest.lstrip()
            indent = len(rest) - len(stripped)
            depth = indent // 2

            m = re.match(r'([><])\s+(\S+)\s+\[(\w+)\]', stripped)
            if not m:
                continue

            direction = "enter" if m.group(1) == ">" else "exit"
            name = m.group(2)
            subsystem = m.group(3)

            entries.append({
                "time": elapsed,
                "tid": tid,
                "depth": depth,
                "direction": direction,
                "name": name,
                "subsystem": subsystem,
            })

    return entries, state_changes


def detect_frames(entries):
    """Split entries into frames using WinMsgPump markers (once per main loop iteration)."""
    frames = []
    current = []
    for e in entries:
        if e["name"] == "WinMsgPump" and e["direction"] == "enter":
            if current:
                frames.append(current)
            current = [e]
        else:
            current.append(e)
    if current:
        frames.append(current)
    return frames


def frame_summary(frame_entries):
    """Summarize one frame: ordered list of top-level calls."""
    top_level = []
    for e in frame_entries:
        if e["depth"] <= 1 and e["direction"] == "enter":
            top_level.append(e["name"])
    return top_level


def print_summary(entries, state_changes):
    """Print overall trace summary."""
    frames = detect_frames(entries)
    threads = set(e["tid"] for e in entries)
    subsystems = Counter(e["subsystem"] for e in entries if e["direction"] == "enter")
    func_counts = Counter(e["name"] for e in entries if e["direction"] == "enter")

    total_time = entries[-1]["time"] - entries[0]["time"] if entries else 0

    print(f"=== Trace Summary ===")
    print(f"Duration: {total_time}ms")
    print(f"Frames: {len(frames)}")
    print(f"Threads: {len(threads)} ({', '.join(sorted(threads))})")
    print(f"Total function calls: {len([e for e in entries if e['direction'] == 'enter'])}")
    print(f"State changes: {len(state_changes)}")
    print()

    if len(frames) > 1:
        frame_times = []
        for fr in frames:
            if len(fr) >= 2:
                dt = fr[-1]["time"] - fr[0]["time"]
                frame_times.append(dt)
        if frame_times:
            avg = sum(frame_times) / len(frame_times)
            print(f"Avg frame time: {avg:.1f}ms ({1000/avg:.1f} FPS)" if avg > 0 else "")
            print(f"Min/Max frame: {min(frame_times)}ms / {max(frame_times)}ms")
        print()

    print("=== Per-Subsystem Call Counts ===")
    for sub, count in subsystems.most_common():
        print(f"  {sub}: {count}")
    print()

    print("=== Top 30 Called Functions ===")
    for name, count in func_counts.most_common(30):
        print(f"  {name}: {count}")
    print()

    print("=== Thread Activity ===")
    thread_funcs = defaultdict(set)
    for e in entries:
        if e["direction"] == "enter":
            thread_funcs[e["tid"]].add(e["name"])
    for tid in sorted(thread_funcs):
        funcs = thread_funcs[tid]
        print(f"  Thread {tid}: {len(funcs)} unique functions")
        subsys = set()
        for e in entries:
            if e["tid"] == tid and e["direction"] == "enter":
                subsys.add(e["subsystem"])
        print(f"    Subsystems: {', '.join(sorted(subsys))}")
    print()

    if state_changes:
        print("=== State Changes ===")
        for sc in state_changes:
            print(f"  {sc}")
        print()

    # Canonical frame order (from most common frame)
    if frames:
        print("=== Canonical Frame Order ===")
        # Use the frame that appears most often (mode)
        frame_sigs = Counter()
        for fr in frames:
            sig = tuple(frame_summary(fr))
            frame_sigs[sig] += 1

        canonical, count = frame_sigs.most_common(1)[0]
        print(f"(most common pattern, {count}/{len(frames)} frames)")
        for i, name in enumerate(canonical, 1):
            print(f"  {i:2d}. {name}")
        print()

        # Show variant frames
        if len(frame_sigs) > 1:
            print(f"=== Frame Variants ({len(frame_sigs)} distinct patterns) ===")
            for sig, cnt in frame_sigs.most_common():
                if cnt == count:
                    continue
                diff = set(sig) - set(canonical)
                missing = set(canonical) - set(sig)
                changes = []
                if diff:
                    changes.append(f"+{diff}")
                if missing:
                    changes.append(f"-{missing}")
                print(f"  {cnt}x: {' '.join(changes) if changes else 'order differs'}")


def print_frame(entries, frame_num):
    """Print detailed trace for a specific frame."""
    frames = detect_frames(entries)
    if frame_num < 0 or frame_num >= len(frames):
        print(f"Frame {frame_num} out of range (0-{len(frames)-1})")
        return

    fr = frames[frame_num]
    print(f"=== Frame {frame_num} ({fr[-1]['time'] - fr[0]['time']}ms) ===")
    for e in fr:
        indent = "  " * e["depth"]
        arrow = ">" if e["direction"] == "enter" else "<"
        print(f"  {e['time']:6d}ms T{e['tid']} {indent}{arrow} {e['name']} [{e['subsystem']}]")


def generate_doc(entries, state_changes, output_path):
    """Generate frame loop documentation from trace data."""
    frames = detect_frames(entries)
    threads = set(e["tid"] for e in entries)
    thread_subsys = defaultdict(set)
    for e in entries:
        if e["direction"] == "enter":
            thread_subsys[e["tid"]].add(e["subsystem"])

    # Find canonical frame
    frame_sigs = Counter()
    for fr in frames:
        sig = tuple(frame_summary(fr))
        frame_sigs[sig] += 1
    canonical, count = frame_sigs.most_common(1)[0]

    total_time = entries[-1]["time"] - entries[0]["time"] if entries else 0
    frame_times = []
    for fr in frames:
        if len(fr) >= 2:
            frame_times.append(fr[-1]["time"] - fr[0]["time"])
    avg_frame = sum(frame_times) / len(frame_times) if frame_times else 0

    doc = []
    doc.append("# Frame Loop Sequence")
    doc.append("")
    doc.append(f"Captured from runtime trace: {len(frames)} frames, "
               f"{total_time}ms total, {len(threads)} threads.")
    doc.append(f"Average frame time: {avg_frame:.1f}ms "
               f"({1000/avg_frame:.1f} FPS)" if avg_frame > 0 else "")
    doc.append("")

    doc.append("## Thread Model")
    doc.append("")
    for tid in sorted(thread_subsys):
        subsys = ", ".join(sorted(thread_subsys[tid]))
        doc.append(f"- **Thread {tid}**: {subsys}")
    doc.append("")

    doc.append("## Main Loop (game.cpp — FUN_0042d8a0)")
    doc.append("")
    doc.append("Canonical per-frame call order (from runtime trace):")
    doc.append("")
    for i, name in enumerate(canonical, 1):
        doc.append(f"{i:2d}. `{name}`")
    doc.append("")

    if state_changes:
        doc.append("## State Transitions Observed")
        doc.append("")
        for sc in state_changes:
            doc.append(f"- {sc}")
        doc.append("")

    if len(frame_sigs) > 1:
        doc.append("## Frame Variants")
        doc.append("")
        doc.append(f"{len(frame_sigs)} distinct frame patterns observed:")
        doc.append("")
        for sig, cnt in frame_sigs.most_common():
            doc.append(f"- **{cnt}x**: {', '.join(sig[:5])}{'...' if len(sig)>5 else ''}")
        doc.append("")

    text = "\n".join(doc)
    if output_path:
        Path(output_path).write_text(text, encoding="utf-8")
        print(f"Doc written to {output_path}")
    else:
        print(text)


def main():
    parser = argparse.ArgumentParser(description="Analyze F1C trace output")
    parser.add_argument("trace_file", help="Path to trace log file")
    parser.add_argument("--summary", action="store_true", help="Print summary")
    parser.add_argument("--frame", type=int, default=None, help="Print specific frame")
    parser.add_argument("--threads", action="store_true", help="Thread analysis")
    parser.add_argument("--doc", type=str, default=None, help="Generate doc to path")
    args = parser.parse_args()

    entries, state_changes = parse_trace(args.trace_file)
    if not entries:
        print("No trace entries found.")
        sys.exit(1)

    print(f"Loaded {len(entries)} entries, {len(state_changes)} state changes")

    if args.frame is not None:
        print_frame(entries, args.frame)
    elif args.doc:
        generate_doc(entries, state_changes, args.doc)
    else:
        print_summary(entries, state_changes)


if __name__ == "__main__":
    main()
