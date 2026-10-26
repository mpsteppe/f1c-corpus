# Rubric: f1c-debug-failed-mod

Task prompt: "My ai_pit_retire DLL logs `retired 21 AI cars (count=22)` when I press F8, but
the cars keep driving normally. It compiles and injects fine. Figure out why."

Expected steps (in order):
1. Open the failure log and confirm it carries read-backs + gate states (it does here); if it
   only said "loaded", STOP and re-instrument first.
2. Re-read mods/_README.md §Current contents for this mod CRITICALLY — its Status is
   "LOG-CONFIRMED ONLY" (writes land ≠ game reacts); cross-check the mod's own README/apply script.
3. Walk triage-tree.md in order. Node 1 (stale ledger): ai_pit_retire has NO facts.json, so
   FIRST author one — start from `python tools/preflight.py example`, fill in each fact
   (expr + type + expect) from the mod's .c/README — then LIVE: run
   `python tools/preflight.py run mods/ai_pit_retire/facts.json`. Node 2 (log-confirmed-only
   trap) matches the symptom: writes land, no effect.
4. LIVE: run the stability check the ledger itself prescribes on the DNF/FinishState field —
   `python tools/preflight.py probe "[<veh-ptr>]+<offset the ledger names>:<field type per SDK/docs>" --secs 3`
   — to see whether the game re-derives the field (clobber) or reads a different one.
5. Mandatory exit: update the ledger Status to what the evidence shows; file a [CORRECTION]
   per refuted fact (route to f1c-doc-audit for format).
6. Write the bits-not-vibes failure report (template in case-studies.md): writes, read-backs,
   gate states, stability result, next step.

Forbidden actions:
- Editing the C to work around a FAILing preflight fact (fix the FACT, not the code).
- Calling a game-internal function to "force" a reaction.
- Skipping triage nodes to guess at a fix.
- Closing without a ledger update and the [CORRECTION](s).
- Reporting "nothing happened" instead of bits.
- Inlining volatile addresses anywhere EXCEPT case-studies.md (which carries the historical banner).

Pass criteria:
- Identifies Node 2 (log-confirmed-only trap) as the matching failure shape.
- Recognizes ai_pit_retire has no facts.json and AUTHORS one (from the example template) before
  running preflight, rather than dead-ending on the missing file.
- Runs the LIVE stability probe rather than assuming, uses the field's SDK/docs type (int32 for
  FinishState, not a guessed float), and stops at it if the game is not running, reporting which
  facts remain unverified.
- Produces both mandatory exits (ledger update + [CORRECTION] routed to f1c-doc-audit).
- Final report is in bits (logged writes, read-backs, gate states), not vibes.
