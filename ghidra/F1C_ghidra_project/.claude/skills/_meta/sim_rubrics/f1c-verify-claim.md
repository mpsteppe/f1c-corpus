# Rubric: f1c-verify-claim

Task prompt: "docs/13 says the vehicle struct has a float fuel-load field at a given
offset. We plan to write to it from a mod. Verify the claim. (Assume the game is NOT
currently running.)"

Expected steps (in order):
1. State the claim precisely: doc entry, expression shape `[PlayerVehiclePtr]+<offset>`,
   claimed type float, expected behavior.
2. `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py <addr> --snippet`
   for the function(s) touching the offset (route via f1c-locate if no address known).
3. Cross-read the raw `.c`: confirm the offset appears as `*(float *)(ptr + <offset>)`,
   check for `↳` sub-object rows, check read vs write direction.
4. Declare the static verdict (static-SUPPORTED / static-REFUTED / static-SILENT).
5. Reach the `LIVE:` probe step (`python tools/preflight.py probe "[PlayerVehiclePtr]+<offset>:float"`),
   recognize the game is not running, and STOP the live portion — reporting the exact
   verdict as UNVERIFIED-LIVE (static-<verdict>) and what command to run once live.
   Because the claim is a write target, also state that a `stable:true` fact check via
   `preflight.py run` is required before any mod write.

Forbidden actions:
- Skipping the static cross-read and going straight to "docs say so".
- Writing any mod code, facts.json-gated or not, before the claim is verified.
- Treating a FAIL/refutation as a code problem ("fix the fact, not the code").
- Regenerating the SDK casually to make a name resolve.
- Marking the claim CONFIRMED without a live probe agreeing.

Pass criteria:
- Stops correctly at the first `LIVE:` step (game not running) with the verbatim-ish
  precondition message anticipated, and still delivers a useful static verdict.
- Verdict vocabulary correct (CONFIRMED / REFUTED / UNVERIFIED-LIVE; FACT reserved for
  raw source / byte reads per INDEX.md).
- A REFUTED outcome is routed to `f1c-doc-audit` for a `[CORRECTION]`, not silently fixed.
- The 0.9^N coin-flip rationale (or equivalent per-fact-verification reasoning) is
  reflected in how the answer treats multi-fact reliance.
