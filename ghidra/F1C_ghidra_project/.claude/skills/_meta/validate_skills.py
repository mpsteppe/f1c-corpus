#!/usr/bin/env python3
"""Static validator for the F1C skill library (.claude/skills/).

Run:  cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python .claude/skills/_meta/validate_skills.py
Exit code = number of violations (0 = clean).

Checks (per CONVENTIONS.md):
  1. frontmatter: parses, name == dir name, description contains "Use when"
  2. SKILL.md length <= MAX_LINES
  3. mandatory "## STOP" section
  4. footer: "Canonical sources:" and "Last validated:"
  5. volatile facts: exe-image addresses (0x004-0x007 range) outside exempt files
     must sit on a line that also names a canonical source file (citation)
  6. cited repo paths exist on disk
  7. cited doc anchors ("path §Heading") exist as headings in the target file
  8. command flags: every --flag used in a `python tools/...` command line
     appears somewhere in that tool's source
  9. router coverage: f1c-start-here (SKILL.md + bundles) mentions every skill dir
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]  # project root
SKILLS = ROOT / ".claude" / "skills"
MAX_LINES = 160  # convention says ~150; small slack
EXEMPT_VOLATILE = {"case-studies.md"}  # historical snapshot files
# paths legitimately cited before they exist (pipeline-generated)
GENERATED_PATHS = {
    "work/review_queue.jsonl",       # written by 0r_gen_queue.bat
    "docs/40", "docs/41", "docs/42", "docs/43",  # delta-pipeline target docs
}
CITATION_TOKENS = (
    "mods/_README", "docs/", "REFERENCE.md", "CLAUDE.md", "INDEX.md",
    "toolfacts", "doc-anchors", "CHANGELOG",
)
ADDR_RE = re.compile(r"0x00[4-7][0-9a-fA-F]{5}")
PATH_RE = re.compile(
    r"(?<![\w./-])((?:tools|docs|work|mods|roles|analysis_pipeline|cross_binary|"
    r"source_recovery|knowledge_graph|plans)/[\w./\\-]+|"
    r"\.claude/(?:skills|hooks)/[\w./\\-]+)"
)
ANCHOR_RE = re.compile(r"([\w./-]+\.md)\s+§([^;,.\n]+)")
FLAG_RE = re.compile(r"(--[a-z][\w-]+)")
CMD_RE = re.compile(r"python\s+((?:tools|analysis_pipeline|\.claude)[\w./-]+\.py)")

violations = []


def bad(f, msg):
    violations.append(f"{f.relative_to(ROOT)}: {msg}")


def check_skill_md(skill_dir: Path, md: Path, text: str, lines: list[str]):
    m = re.match(r"^---\n(.*?)\n---\n", text, re.S)
    if not m:
        bad(md, "frontmatter missing or unparseable")
    else:
        fm = m.group(1)
        nm = re.search(r"^name:\s*(\S+)", fm, re.M)
        if not nm or nm.group(1) != skill_dir.name:
            bad(md, f"frontmatter name != dir name ({nm.group(1) if nm else 'absent'})")
        desc = re.search(r"^description:\s*(.+)", fm, re.M)
        if not desc or "use when" not in desc.group(1).lower():
            bad(md, 'frontmatter description lacks "Use when" trigger phrase')
    if len(lines) > MAX_LINES:
        bad(md, f"SKILL.md too long: {len(lines)} > {MAX_LINES} lines")
    if not re.search(r"^## STOP", text, re.M):
        bad(md, 'missing "## STOP" section')
    if "Canonical sources:" not in text:
        bad(md, 'missing "Canonical sources:" footer')
    if "Last validated:" not in text:
        bad(md, 'missing "Last validated:" footer')


def check_volatile(f: Path, lines: list[str]):
    if f.name in EXEMPT_VOLATILE or f.parent.name == "_meta":
        return
    for i, line in enumerate(lines, 1):
        if ADDR_RE.search(line) and not any(t in line for t in CITATION_TOKENS):
            bad(f, f"line {i}: inlined exe address without canonical citation: {line.strip()[:90]}")


def check_paths(f: Path, lines: list[str]):
    if f.name in EXEMPT_VOLATILE:
        return  # historical-snapshot files may quote stale/shorthand paths verbatim
    for i, line in enumerate(lines, 1):
        low = line.lower()
        # lines that deliberately name a missing/generated path
        if any(w in low for w in ("does not exist", "broken", "generated", "created on", "will be created", "placeholder")):
            continue
        for p in PATH_RE.findall(line):
            p = p.rstrip(".:,;`)*").replace("\\", "/")
            # skip obvious placeholders / globs / templates (XX, NNNN, worker letters)
            if any(c in p for c in "<>*{") or "worker_" in p:
                continue
            if re.search(r"(XX|xx\.|NNNN|/4[0-9X]-)", p):
                continue
            if p in GENERATED_PATHS or any(p.startswith(g) for g in GENERATED_PATHS):
                continue
            if p + "*" in line:  # glob citation truncated by the path regex
                continue
            tgt = ROOT / p
            if tgt.exists() or tgt.with_suffix("").exists():
                continue
            # prefix citations (work/HANDOFF, analysis_pipeline/_launch_) and
            # project shorthand (docs/12 = docs/12-globals-reference.md)
            if list(ROOT.glob(p + "*")):
                continue
            m = re.fullmatch(r"docs/(\d+)", p)
            if m and list((ROOT / "docs").glob(f"{m.group(1)}-*")):
                continue
            bad(f, f"line {i}: cited path does not exist: {p}")


def check_anchors(f: Path, text: str):
    for doc, heading in ANCHOR_RE.findall(text):
        doc_path = ROOT / doc
        if not doc_path.exists():
            continue  # path check reports it
        heading = heading.strip().strip("*`()")
        body = doc_path.read_text(encoding="utf-8", errors="replace")
        # cited text may over-capture trailing prose ("§Rules: quote..." /
        # "§Iron rules rule 5"); accept if any heading starts with a prefix
        # of the citation (also trying the pre-colon part)
        candidates = [heading, heading.split(":")[0].strip()]
        found = False
        for cand in candidates:
            for n in (40, 24, 14, 8):
                pat = re.compile(r"^#{1,4}\s+.*" + re.escape(cand[:n]), re.M | re.I)
                if pat.search(body):
                    found = True
                    break
            if found:
                break
        if not found:
            bad(f, f"anchor not found in {doc}: {heading[:60]}")


_TOOLFACTS = None


def _toolfacts_text() -> str:
    global _TOOLFACTS
    if _TOOLFACTS is None:
        tf = SKILLS / "_meta" / "toolfacts.md"
        _TOOLFACTS = tf.read_text(encoding="utf-8", errors="replace") if tf.exists() else ""
    return _TOOLFACTS


def check_flags(f: Path, lines: list[str]):
    for i, line in enumerate(lines, 1):
        cm = CMD_RE.search(line)
        if not cm:
            continue
        tool = ROOT / cm.group(1)
        if not tool.exists():
            bad(f, f"line {i}: command references missing tool {cm.group(1)}")
            continue
        src = tool.read_text(encoding="utf-8", errors="replace")
        for flag in FLAG_RE.findall(line):
            # some tools parse flags by hand (e.g. gen_hook.py --desc via
            # startswith('--')); toolfacts.md is the fallback authority
            if flag not in src and flag not in _toolfacts_text():
                bad(f, f"line {i}: flag {flag} not found in {cm.group(1)}")


def main():
    if not SKILLS.exists():
        print("no .claude/skills/ directory")
        return 1
    skill_dirs = sorted(
        d for d in SKILLS.iterdir() if d.is_dir() and d.name.startswith("f1c-")
    )
    if not skill_dirs:
        print("no f1c-* skill directories found")
        return 1
    for d in skill_dirs:
        md = d / "SKILL.md"
        if not md.exists():
            bad(d, "missing SKILL.md")
            continue
        text = md.read_text(encoding="utf-8", errors="replace")
        lines = text.splitlines()
        check_skill_md(d, md, text, lines)
        for f in sorted(d.glob("*.md")):
            ftext = f.read_text(encoding="utf-8", errors="replace")
            flines = ftext.splitlines()
            check_volatile(f, flines)
            check_paths(f, flines)
            check_anchors(f, ftext)
            check_flags(f, flines)
    # router coverage
    router = SKILLS / "f1c-start-here"
    if router.exists():
        blob = " ".join(
            p.read_text(encoding="utf-8", errors="replace") for p in router.glob("*.md")
        )
        for d in skill_dirs:
            if d.name != "f1c-start-here" and d.name not in blob:
                bad(router / "SKILL.md", f"router does not mention {d.name}")
    else:
        print("note: f1c-start-here not present yet")

    for v in violations:
        print("FAIL", v)
    print(f"{len(violations)} violation(s) across {len(skill_dirs)} skills")
    return len(violations)


if __name__ == "__main__":
    sys.exit(main())
