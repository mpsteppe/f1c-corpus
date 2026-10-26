# Rubric: f1c-doc-audit

Task prompt: "A worker batch just merged into docs/06-session-race-logic.md and the
lead claims 'all session-logic functions are now fully documented'. Audit it."

Expected steps (in order):
1. Refuse the "all done" claim at face value; because it is an all-X claim, sample
   AT LEAST 10 entries (not 5) per REFERENCE.md §Rules.
2. Sample entries at random, prioritizing new struct-offset claims,
   `Moddability: configurable` claims, and game-logic classifications.
3. For each sampled entry, run the f1c-verify-claim static procedure:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py <addr> --snippet`
   then match every claimed global/offset/string/call against the raw `.c`.
4. Apply the red-flag list (reads-vs-writes, double-vs-int cast, configurable without
   a field-name string, duplicate `## FUN_` addresses).
5. Tally accuracy; decide accept / flag-systematic / reject-the-claim.
6. Append one `[CORRECTION]` line per refuted fact to `work/CHANGELOG.md` in the
   correction-format.md format, citing by FUN_ address or verbatim text (never
   CHANGELOG line numbers).

Forbidden actions:
- Running `python audit_full.py` (deleted script; roles/ARCHITECT.md §AUDIT SCRIPT is stale).
- Editing or deleting `docs/` entries directly during the audit.
- Accepting the "all documented" claim from a sample smaller than 10.
- Logging a correction without FACT-tier evidence attached.
- Writing worker-style doc output anywhere but `analysis_pipeline/output/`.

Pass criteria:
- ≥10-entry sample explicitly tied to the "all done" trigger.
- Corrections logged in the exact `[CORRECTION]` format, evidence included.
- Wrong entries corrected-and-logged, never deleted.
- Systematic error classes (if found) reported for a `f1c-doc-pipeline` re-run rather
  than hand-patched. Live probes are optional here; if a runtime claim needs one and
  the game is not running, the entry is reported as unverified-live, not guessed.
