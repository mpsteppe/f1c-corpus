"""
Merge cross_validate_2 worker outputs.

Extracts FAIL verdicts + corrected entries → docs/25-cv2-corrections.md
Also appends [CORRECTION] lines to work/CHANGELOG.md.
Does NOT auto-patch docs/ — corrections need architect review first.

Usage:
    python work/merge_cross_validate_2.py [--archive]
"""
import re
import shutil
import sys
from datetime import datetime
from pathlib import Path

ROOT         = Path(__file__).parent.parent
OUTPUT_DIR   = ROOT / "analysis_pipeline" / "output" / "cross_validate_2"
OUT_DOC      = ROOT / "docs" / "25-cv2-corrections.md"
CHANGELOG    = ROOT / "work" / "CHANGELOG.md"
ARCHIVE_BASE = ROOT / "analysis_pipeline" / "output" / "archive" / "cross_validate_2"

ARCHIVE = "--archive" in sys.argv

FAIL_RE    = re.compile(r'^## (FUN_[0-9a-fA-F]+)[^\n]*— FAIL', re.MULTILINE)
TARGET_RE  = re.compile(r'<!-- target:\s*(docs/[\w\-\.]+)\s*-->')
FUN_RE     = re.compile(r'^## FUN_[0-9a-fA-F]+', re.MULTILINE)


def read(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return f.read()


def extract_fail_blocks(content, filename):
    """Extract each FAIL block: verdict section + corrected entry if present."""
    results = []
    matches = list(FAIL_RE.finditer(content))

    for i, m in enumerate(matches):
        addr = m.group(1).lower()
        block_start = m.start()
        # Block ends at next ## FUN_ header or EOF
        remaining = content[m.end():]
        next_fun = FUN_RE.search(remaining)
        block_end = m.end() + next_fun.start() if next_fun else len(content)
        block = content[block_start:block_end].strip()

        # Extract error tags
        errors = re.findall(r'\[([A-Z_]+)\]', block)

        # Extract corrected entry (## FUN_ block inside the FAIL block, after "Corrected entry:")
        corrected = ""
        target = ""
        corr_match = re.search(r'(?:Corrected entry:|corrected entry:)\s*\n(.*)', block, re.DOTALL)
        if corr_match:
            corrected = corr_match.group(1).strip()
            tm = TARGET_RE.search(corrected)
            if tm:
                target = tm.group(1)

        results.append({
            "addr": addr,
            "source": filename,
            "errors": errors,
            "block": block,
            "corrected": corrected,
            "target": target,
        })

    return results


def count_verdicts(content):
    passes = len(re.findall(r'^## FUN_[^\n]*— PASS', content, re.MULTILINE))
    fails  = len(re.findall(r'^## FUN_[^\n]*— FAIL', content, re.MULTILINE))
    return passes, fails


def main():
    worker_files = sorted(OUTPUT_DIR.glob("worker_*.md"))
    if not worker_files:
        print(f"No worker files in {OUTPUT_DIR}")
        sys.exit(1)

    all_fails    = []
    total_pass   = 0
    total_fail   = 0
    workers_read = 0

    for wf in worker_files:
        content = read(wf)
        if not content.strip():
            print(f"  SKIP {wf.name}: empty")
            continue

        p, f = count_verdicts(content)
        total_pass += p
        total_fail += f

        fails = extract_fail_blocks(content, wf.name)
        all_fails.extend(fails)
        workers_read += 1
        print(f"  {wf.name}: {p} PASS, {f} FAIL")

    print(f"\nTotal: {total_pass} PASS, {total_fail} FAIL across {workers_read} files")

    # Build corrections doc
    lines = []
    lines.append("# Cross-Validation Round 2 — Corrections\n")
    lines.append(f"*Merged from {workers_read} worker(s) on {datetime.now().strftime('%Y-%m-%d')}.*\n")
    lines.append(f"**{total_pass} PASS | {total_fail} FAIL | {len(all_fails)} corrections extracted**\n")
    lines.append("")
    lines.append("Review each FAIL below. Apply corrected entries manually to the target doc.\n")
    lines.append("")

    # Group by target doc
    by_target = {}
    no_target = []
    for f in all_fails:
        if f["target"]:
            by_target.setdefault(f["target"], []).append(f)
        else:
            no_target.append(f)

    for target in sorted(by_target.keys()):
        lines.append(f"## {target}\n")
        for entry in by_target[target]:
            lines.append(f"### {entry['addr'].upper()}")
            lines.append(f"Source worker: {entry['source']}")
            if entry["errors"]:
                lines.append(f"Error types: {', '.join(entry['errors'])}")
            lines.append("")
            lines.append(entry["block"])
            lines.append("")

    if no_target:
        lines.append("## Corrections Without Target Doc\n")
        for entry in no_target:
            lines.append(f"### {entry['addr'].upper()}")
            lines.append(f"Source worker: {entry['source']}")
            if entry["errors"]:
                lines.append(f"Error types: {', '.join(entry['errors'])}")
            lines.append("")
            lines.append(entry["block"])
            lines.append("")

    OUT_DOC.write_text("\n".join(lines), encoding="utf-8")
    print(f"Wrote {OUT_DOC} ({OUT_DOC.stat().st_size // 1024} KB)")

    # Append to CHANGELOG
    changelog_lines = [
        f"\n## cross_validate_2 audit — {datetime.now().strftime('%Y-%m-%d')}\n",
        f"Total validated: {total_pass + total_fail} | PASS: {total_pass} | FAIL: {total_fail}\n",
    ]
    for entry in all_fails:
        err_str = ", ".join(entry["errors"]) if entry["errors"] else "see block"
        changelog_lines.append(
            f"[CORRECTION] {entry['addr'].upper()} — {err_str} (worker: {entry['source']})\n"
        )
    with open(CHANGELOG, "a", encoding="utf-8") as f:
        f.writelines(changelog_lines)
    print(f"Appended {len(all_fails)} corrections to {CHANGELOG}")

    if ARCHIVE:
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        dest = ARCHIVE_BASE / ts
        dest.mkdir(parents=True, exist_ok=True)
        for wf in worker_files:
            shutil.move(str(wf), str(dest / wf.name))
        print(f"Archived {len(worker_files)} files -> {dest}")


if __name__ == "__main__":
    main()
