---
name: f1c-skill-maintenance
description: Keep the .claude/skills/ library true when tools, docs, or conventions change, or when a skill misfires — validate, patch, re-footer, re-simulate. Use when a task says "a skill gave a wrong command", "update the skills for the new CLI", "validate the skill library", "the validator fails", or after any tool/doc restructuring. Do NOT use for errors in the game docs themselves — use f1c-doc-audit; for authoring a brand-new skill, start from _meta/TEMPLATE.md and _meta/CATALOG.md, then use this skill to validate it.
---

# Maintain the skill library

## When to use / when not

Use whenever a skill's content may have drifted from reality: a tool CLI changed, a
canonical doc was restructured (anchors moved), a skill led an agent to a wrong
action, or a periodic validation is due. Not for wrong facts in `docs/` (that is
f1c-doc-audit territory — skills deliberately contain no volatile facts to audit).

## The one design rule being protected

From `_meta/CONVENTIONS.md`: **skills are execution shells; canonical docs are
knowledge stores.** Skills inline procedures, commands, expected outputs, and STOP
conditions — never addresses, offsets, statuses, or labels. Litmus test (verbatim):

> if the fact could be invalidated by a doc merge, a new mod result, or a
> `[CORRECTION]` entry, it does not belong in a skill.

Command syntax in skills comes ONLY from `_meta/toolfacts.md`. Doc-section citations
come ONLY from the anchor table in `_meta/doc-anchors.md`. Iron rules are quoted
verbatim from CLAUDE.md, never paraphrased.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| Meta files present | `ls /c%USERPROFILE%/Desktop/F1C_ghidra_project/.claude/skills/_meta` | `CONVENTIONS.md`, `TEMPLATE.md`, `CATALOG.md`, `toolfacts.md`, `doc-anchors.md`, `sim_rubrics/` |
| Current commit hash for footers | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && git log --oneline -1` | one line: `<short-hash> <subject>` |

## Procedure

### Step 1: Run the validator
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python .claude/skills/_meta/validate_skills.py
```
Expected output: `<N> violation(s) across <M> skills`; exit code = violation count
(0 = clean). Its implemented checks (1–9): frontmatter parses, name == dir name,
description contains "Use when"; SKILL.md length ≤ 160 lines; a `## STOP` section;
both footer lines (`Canonical sources:` + `Last validated:`); volatile exe addresses
(0x004–0x007 range) outside EXEMPT_VOLATILE files must sit on a line that also names
a canonical source (citation-token heuristic); cited repo paths exist on disk
(GENERATED_PATHS exempts pipeline-created files); cited doc anchors
(`path §Heading`) resolve by PREFIX MATCH against the TARGET doc's real headings —
the validator never reads `_meta/doc-anchors.md`, which remains the authoring
authority but is not machine-enforced; command `--flags` in `python tools/...`
lines are grepped as substrings in the tool's source (not parsed from argparse —
a stale-but-still-mentioned flag can pass); router coverage (f1c-start-here must
mention every skill dir).
If instead you see `No such file or directory` → the validator file is missing from
this checkout; check each changed skill by hand against `_meta/CONVENTIONS.md`
§Hard conventions and note in your report that validation was manual.

### Step 2: If a tool CLI changed — regenerate toolfacts FIRST
Before editing any skill: re-verify the changed tool's flags/subcommands/messages
against its source, rewrite that tool's section of `_meta/toolfacts.md` (update the
section, keep the file's format), and only then update the skills that cite it.
Skills copying commands from a stale toolfacts section just re-encode the bug.
Expected output: the toolfacts section matches the tool's current argparse; every
skill command citing that tool matches the new section.

### Step 3: If a doc was restructured — re-harvest anchors
If a canonical doc's headings changed, update the affected rows of
`_meta/doc-anchors.md` (anchors are verbatim headings), then fix every skill footer
and body citation that used the old anchor. Never leave a citation pointing at a
heading that no longer resolves.

### Step 4: Patch the skill
Minimal edit, obeying `_meta/CONVENTIONS.md` and the structure in
`_meta/TEMPLATE.md`. If the skill misfire revealed a wrong CANONICAL doc (not a
wrong skill), do NOT absorb the fix into the skill — treat it as doc-audit: log the
error where it lives (`work/CHANGELOG.md` `[CORRECTION]` for docs) and leave the
skill citing the now-corrected source.

### Step 5: Update the footer
Set the skill's final line to `Last validated: <today> against <short-hash>` using
the hash from Prerequisites. A patched skill with a stale footer is indistinguishable
from an unpatched one — the footer update is mandatory, not cosmetic.

### Step 6: Re-simulate with a fresh agent
Re-run the patched skill's rubric at `_meta/sim_rubrics/<skill-name>.md` with a
FRESH agent (cold context, zero project memory — the skill's actual audience). The
rubric gives the task prompt, expected step order, forbidden actions, and pass
criteria (including stopping correctly at the first `LIVE:` step when the game is
unavailable). Expected output: the fresh agent passes all pass criteria without
hints. If instead it fails → the patch is incomplete; return to Step 4.

### Step 7: Re-validate and report
Re-run Step 1 (expect exit 0), then report: which skills changed, why, what the
sim run showed, and any toolfacts/doc-anchors sections regenerated.

## STOP — do not proceed if

- The validator exits nonzero and you are about to ship anyway → fix findings first.
- You are about to inline a volatile fact (exe address, struct offset, mod status,
  function label) into a skill "to save the reader a hop" → forbidden; cite the
  canonical file instead.
- You are about to paraphrase an iron rule → forbidden; quote CLAUDE.md (or the
  hook text) verbatim.
- A tool's CLI changed but you are editing skills before its toolfacts section →
  regenerate `_meta/toolfacts.md` first (Step 2 order is mandatory).
- The misfire was a wrong fact in a canonical doc, not in the skill → route to
  f1c-doc-audit; do not "fix" the skill by inlining a corrected volatile fact.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `No such file or directory` for validate_skills.py | validator missing from this checkout | manual check vs `_meta/CONVENTIONS.md` §Hard conventions; say so in the report |
| Validator flags an address in a skill | volatile fact inlined without a citation sentence | replace with a citation to its canonical file; a legitimate historical-snapshot file is exempted by adding its FILENAME to `EXEMPT_VOLATILE` inside `validate_skills.py` (a validator edit, done via this skill) |
| Validator flags an unknown anchor | doc restructured or citation typo | re-harvest the anchor into `_meta/doc-anchors.md` from the real heading, then fix the citation |
| Fresh-agent sim fails a step the old skill passed | patch changed step semantics | diff the skill against the rubric; update whichever is wrong — and if the rubric, note it in the report |
| Two skills disagree on a shared rule | one paraphrased instead of quoting | make both quote the canonical source verbatim |

---
Canonical sources: _meta/CONVENTIONS.md; _meta/TEMPLATE.md; _meta/CATALOG.md; _meta/toolfacts.md; _meta/doc-anchors.md; _meta/validate_skills.py (checks 1–9 in its docstring); CLAUDE.md §Iron rules
Last validated: 2026-07-20 against 6bcccfe
