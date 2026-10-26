# Sim 6 — f1c-doc-audit (all-done claim audit)

- Date: 2026-07-20. Model: Sonnet (general-purpose subagent), fresh context.
- Harness: read-only session; corrections drafted not written.
- Task prompt (verbatim from rubric): "A worker batch just merged into docs/06-session-race-logic.md and the lead claims 'all session-logic functions are now fully documented'. Audit it."
- Rubric: `.claude/skills/_meta/sim_rubrics/f1c-doc-audit.md`

## Agent final report

## Audit of docs/06-session-race-logic.md — Final Report

**Verdict: REJECT the "all session-logic functions are fully documented" claim.** Sampled accuracy was ~73% (8/11 clean), below the ~90% acceptance floor, and a structural check shows the doc is neither self-contained nor exclusively session-logic content. Details and full chronological trail below.

### 1. Read-only constraint acknowledged
Ran under the hard constraint: no file writes, no `git commit`, no `2_merge.bat`, no edits. Where the workflow called for logging a correction, I drafted the text below instead of appending it.

### 2. Skill invoked
Ran `f1c-doc-audit` (via Skill tool) with the read-only override baked into the args. Its SKILL.md (`.claude/skills/f1c-doc-audit/SKILL.md`) prescribes: confirm the doc exists, sample ≥10 entries, verify each against raw `.c`, red-flag scan, tally, decide, log `[CORRECTION]` to `work/CHANGELOG.md` (not done here — drafted only). Also read `correction-format.md` in that skill directory for the exact log-line format and worked examples.

### 3. Prerequisite check
- `grep -c "^## FUN_" docs/06-session-race-logic.md` → **858** entries. Confirmed target file is real and non-empty.
- `docs/_README.md` trust map: files `01`–`10` (includes `06`) are **FACT-leaning**, "string-anchored to real functions" — higher trust baseline than e.g. docs/12 or docs/13, so any error found here is a stronger signal.

### 4. Traced what "just merged" refers to
- `git log --oneline -5 -- docs/06-session-race-logic.md` and `git status --porcelain docs/06-session-race-logic.md` → working tree clean for this file; last touching commit `b4acbf8` (2026-07-15) added exactly one entry (`FUN_0044dfa0 — ScoringDBReset`).
- `git log --oneline -15` → most recent commits (`5c0de3b`, `e432280`, `6bcccfe`...) are skill-library/doc-checkpoint work, not docs/06 content changes.
- Searched `work/CHANGELOG.md` for `docs/06` mentions — found a long history of batch merges (multiple `Batch N` entries, routing summaries, prior `[CORRECTION]` lines already logged against docs/06, e.g. `FUN_004E513E` sign error, `FUN_0052DE60` offset error). No changelog entry describes an unmerged/pending batch for docs/06 right now.
- Conclusion: there is no uncommitted "fresh" batch sitting in the working tree — the audit target is the **current, already-merged state** of docs/06 as it stands, which is what the lead's claim is about.

### 5. Structural completeness check (before content sampling)
Ran `python tools/investigate.py system "session"` → graph attributes **797** functions to docs/06 as the "session" system (vs. 858 raw `## FUN_` headers — a gap worth noting but not the main finding).

Checked the pipeline's `<!-- target: docs/XX.md -->` routing tags (documented in `REFERENCE.md` §Parallel Worker Workflow: "Routes full entries to target doc via `<!-- target: -->` comment"):
- `grep -c "<!-- target:" docs/06-session-race-logic.md` → 582 tagged entries; breakdown by target: 511 → docs/06 itself (correct), but **71 tagged for other docs** (18→docs/20, 17→docs/17, 8→docs/19, 8→docs/18, 7→docs/08, 6→docs/21, 4→docs/01, 1 each→docs/10, docs/09, docs/02).
- Spot-checked whether those 71 were ever actually relocated: `FUN_0044dfa0` (tagged target: docs/20-math-utilities.md) — `grep -rn "FUN_0044dfa0" docs/*.md` shows it exists **only** in docs/06. Checked all 17 addresses tagged target:docs/17 against docs/17-physics-collision.md — only one address (`FUN_004b9cb0`) appears there at all, and reading that line (`docs/17:2520`) shows it's just a *callee mention* inside an unrelated entry, not a routed copy. **0 of 17 were actually moved.**
- Reverse direction: `grep -rl "target: docs/06-session-race-logic.md" docs/*.md` (excluding docs/06 itself) found **63 entries physically living in 11 other doc files** (01, 02, 04, 08, 09, 10, 17, 19, 20, 21, 25) that are tagged as belonging to session logic but were never merged into docs/06.

**Finding:** the merge pipeline's routing step tags content but does not relocate it. This means docs/06 simultaneously (a) contains ~71 entries that aren't session-logic content at all (misfiled physics/renderer/math/audio functions with dead routing tags) and (b) is missing ~63 genuine session-logic entries that live elsewhere. This alone refutes a literal "docs/06 has all session-logic functions" reading of the claim.

Also checked for the specific rule-7 violation (duplicate addresses within the file itself): `grep ... | sort | uniq -d` → **no internal duplicates** in docs/06. That part is clean.

Additionally quantified entry quality/format mix:
- `grep -c "\*\*Key logic:\*\*"` → 685 full structured entries
- `grep -c "\*\*Game Logic:\*\*"` → 65 thin triage-stub entries (generic CRT-style one-liners: memmove, realloc, WideChar conversion, string hashing — not really session/race logic)
- Remaining ~108 headers use plain-prose (no structured fields) format.
This confirms the file is a grab-bag of full analysis, thin stubs, and prose — not uniformly "fully documented" in depth either.

### 6. Content sampling (≥10 entries, spread across the file)
Per the skill's non-negotiable floor ("never accept 'all X documented' without sampling ≥10"), picked 11 addresses at roughly even intervals across the file's 16,525 lines: `0047e4b0, 004b17b0, 004db6f0, 00592a9c, 0054a1b0, 00537e40, 0042adb0, 0054bf10, 004f17d0, 00548c20, 0047fbd0`.

Ran `python tools/investigate.py <all 11 addresses>` in two batched calls (batching per CLAUDE.md rule 2), then read the doc text for each from `docs/06-session-race-logic.md` and diffed claims against the raw `.c` (`analysis_pipeline/analyzed/` and `decompiled_full/`). Also directly `Read` the full source for `FUN_0054bf10` and `FUN_0047fbd0` since the tool's `--snippet` mode elided the decisive lines.

Results:
- **FUN_0047e4b0, FUN_004b17b0, FUN_0054a1b0, FUN_00537e40, FUN_0042adb0, FUN_004f17d0, FUN_00548c20, FUN_0047fbd0** — all 8 checked clean; claimed offsets, branches, and call targets matched the raw `.c` exactly.
- **FUN_004db6f0 ("Position/Order Name Display") — INCOMPLETE.** Doc only describes the `param_1 == -1` branch and a flat "color 0xffff00 default." The raw `.c` (`analysis_pipeline/analyzed/0x004db6f0__FUN_004db6f0.c`) has a 3-way branch (`-1`, `0`, else) — the `param_1==0` case uses a completely different global (`DAT_005c36fc`, not mentioned in the doc's Globals list) — and a conditional color override (`FUN_0049b7a0` gear-check flips the color to `0xff0000` when `result & 0xf == 0xf`) that the doc omits entirely.
- **FUN_00592a9c — WRONG.** Doc (thin-stub format) labels it "Global data pointer accessor... Singleton data getter." The raw `.c` shows it walks `DAT_008d5a44` (CmdLinePtr) byte-by-byte, handling quoted (`0x22`) substrings and skipping whitespace (`<=0x20`) before returning the next-token pointer — this is a **command-line argument tokenizer**, not a data accessor. The doc's classification doesn't describe the actual behavior at all.
- **FUN_0054bf10 ("State Array Word-Sign Extension") — WRONG, and non-trivially so.** Doc claims: "masks upper 16 bits, sign-extends lower 16 bits... Effect: result = (original & 0xFFFF0000) | sign_extend(original & 0xFFFF)." Full raw source:
  ```c
  uVar3 = *puVar2;
  *puVar2 = uVar3 & 0xffff0000;
  *puVar2 = (int)*(short *)((int)puVar2 + 2) | uVar3 & 0xffff0000;
  ```
  `(short *)((int)puVar2 + 2)` reads the byte at offset **+2**, which on this little-endian target is the **upper** halfword, not the lower one. Working through the bit math: the result duplicates/sign-extends the **high** 16 bits into the value, while the original **low** 16 bits are discarded entirely — the exact opposite word than what the doc claims is being preserved vs. sign-extended.

Sampled accuracy: **8/11 clean, 3/11 flawed ≈ 73%** — well under the skill's ~90% acceptance bar, and this is a doc file marked FACT-leaning, so the bar should hold.

### 7. Drafted corrections (NOT written — presented per read-only constraint)

Per `correction-format.md`, these are the exact lines I would append to `work/CHANGELOG.md` if authorized:

```
[CORRECTION] FUN_0054bf10: claimed "sign-extends lower 16 bits, preserves hi-word" (result = (original & 0xFFFF0000) | sign_extend(original & 0xFFFF)) — raw .c (analysis_pipeline/analyzed/0x0054bf10__FUN_0054bf10.c) shows the short read is at byte offset puVar2+2, i.e. the UPPER halfword (little-endian); final = sign_extend(hi16) | (hi16<<16), which sign-extends/duplicates the HIGH word and discards the original low word — backwards from the doc's claim. (docs/06)

[CORRECTION] FUN_00592a9c: labeled "Global data pointer accessor / Singleton data getter" — raw .c (decompiled_full/0x00592a9c__FUN_00592a9c.c) shows it walks DAT_008d5a44 (CmdLinePtr) byte-by-byte, handling quoted (0x22) substrings and skipping whitespace (<=0x20) — this is a command-line argument tokenizer, not a data accessor. (docs/06)

[CORRECTION] FUN_004db6f0: Key logic section omits the param_1==0 branch (uses DAT_005c36fc, not listed in Globals) and the color-override logic (FUN_0049b7a0 gear check flips color to 0xff0000 when result&0xf==0xf) — raw .c (analysis_pipeline/analyzed/0x004db6f0__FUN_004db6f0.c) shows a 3-way branch plus conditional color, doc documents only 1 of 3 branches and a flat default color. (docs/06)

[CORRECTION] docs/06-session-race-logic.md (systemic): "fully documented" claim does not hold structurally. 71 entries physically in docs/06 carry <!-- target: --> tags pointing to docs/08,01,09,10,17,18,19,20,21 and were never relocated (spot-checked all 17 addresses tagged target:docs/17 — 0/17 exist there; e.g. FUN_0044dfa0 tagged target:docs/20 exists only in docs/06). Conversely 63 entries physically in docs/01,02,04,08,09,10,17,19,20,21,25 carry target:docs/06 tags and were never merged in — genuine session-logic functions live outside docs/06. The merge pipeline's routing step (REFERENCE.md §Parallel Worker Workflow: "Routes full entries to target doc via <!-- target: --> comment") tags but does not relocate content, across many historical batches, not just one. (docs/06 and docs/01,02,04,08,09,10,17,19,20,21,25)
```

Per Step 6 of the skill: these corrections touch globals/behavior facts (not offsets/globals-reference SDK-visible facts), so no `tools/gen_sdk.py` re-run flag is needed. The systemic routing correction should additionally be routed to whoever runs `f1c-doc-pipeline` next, since re-running the merge/route step (or a one-off script to physically relocate the 71+63 tagged-but-unmoved entries) is the real fix, not a manual doc edit.

### 8. Where I stopped
Stopped after the ≥10-entry content sample plus the structural routing check, per the skill's floor and the "systematic error class → reject + flag whole section" branch of Step 4 — both conditions were met (accuracy < 90%, and an "all done" claim contradicted by a widened sample). I did not run `2_merge.bat`, did not touch `work/CHANGELOG.md`, `mods/_README.md`, or any doc file, and did not run `tools/knowledge_graph/rebuild.py` — all consistent with the read-only constraint. No further tool access or write permission was needed to reach a verdict; next action (applying the drafted corrections and fixing the routing pipeline) requires write access this session doesn't have.
