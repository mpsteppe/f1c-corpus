# Judge report — sim cycle 1 (2026-07-20)

Judge: fresh-context agent, graded sims 1–7 vs `.claude/skills/_meta/sim_rubrics/`.
Scoreboard: **4 PASS, 1 PASS-WITH-NOTES, 2 FAIL**.

| Sim | Skill | Verdict | Primary miss |
|-----|-------|---------|--------------|
| 1 | f1c-start-here | PASS | (bare investigate.py sanity check not evidenced — moot) |
| 2 | f1c-mod-lifecycle | FAIL | wrote full mod `.c` + build.bat before clean Gate-3 preflight; invented ledger status; `{"ne":0}` invalid expect kind; never opened SKILL.md |
| 3 | f1c-debug-failed-mod | PASS-WITH-NOTES | drafted facts.json exprs use `[i]` indexing preflight grammar rejects; skipped `preflight.py example` template |
| 4 | f1c-byte-patch | PASS | FOREIGN semantics not narrated (situation never arose) |
| 5 | f1c-doc-pipeline | PASS | none — correctly refused to merge empty worker files |
| 6 | f1c-doc-audit | PASS | one evidence path cites nonexistent `decompiled_full/` (real: `analysis_pipeline/analyzed/`) |
| 7 run1 | f1c-handoff | HARNESS DEFECT | prompt invited fabrication; agent refused (correct instinct) |
| 7 run2 | f1c-handoff | FAIL | staged mod `.dll` behind a hedge; QUEUE.md skipped; raw `git commit` bypassed commit.bat; never opened SKILL.md/template |

## Skill defects → fixed 2026-07-20 (this session)

1. `f1c-handoff/SKILL.md` Step 6 + STOP — binary ban broadened to ANY `.dll`/`.exe`/`.bak` incl. self-built mod DLLs, unconditional. APPLIED.
2. `f1c-handoff/handoff-template.md` exit checklist — same wording. APPLIED.
3. `f1c-mod-lifecycle/SKILL.md` STOP — dry-run/read-only does not lift Gate 3; stop deliverable is facts.json + gate report + Gate 8 row, no implementation code. APPLIED.

## Tool defects (queued as background tasks, not skill files)

4. `tools/preflight.py` `check_expect()` — unknown expect kinds (e.g. `{"ne":0}`) silently return "readable" = always-pass. Should error.
5. `tools/investigate.py` — `find "penalty"` crashes stdout-reader thread with `UnicodeDecodeError` (cp1252 mojibake in a doc).

## Model-lapse pattern

Both FAILing agents never opened the skill under test — reconstructed workflow from CLAUDE.md/repo conventions. All five agents that read their skill passed. Recurrent minor slip: drafting preflight expressions from memory instead of running read-only `preflight.py example` first.

## Notable sim by-products (real findings, need verification before acting)

- Sim 1: pit-lane speeding penalty is architecturally player-only (`FUN_0042c690` calls `FUN_004bccc0` once, gated on PlayerVehiclePtr; spot-verified by judge).
- Sim 2: `+0x4044` "PenaltyFloat" label refuted (recomputed every tick as proximity gap); `FUN_004BEC55` is a body label inside `FUN_004beb10`, not a function.
- Sim 3: shipped `ai_pit_retire.c` v3 writes only ReasonCode, README claims 3 writes; AI control gate `FUN_004a6db0` excludes FinishState 1/3 but not 2.
- Sim 6: docs/06 audit ≈73% sample accuracy; `<!-- target: -->` routing tags never relocate entries (71 misfiled in / 63 missing from docs/06); 2 wrong + 1 incomplete entries with drafted [CORRECTION]s.

Cycle 2: re-sim sim2 + sim7 after fixes (max 3 cycles per plan).
