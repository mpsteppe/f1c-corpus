# Rubric: f1c-locate

Task prompt: "Find where fuel consumption is computed, which globals it depends on,
and whether anything about it is moddable. Give me the function addresses and how you
know."

Expected steps (in order):
1. `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py find "fuel consumption"`
   (or `system fuel` first — either order of find/system is acceptable).
2. `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py mod fuel`
   and/or `param FuelConsumption` for the moddability angle.
3. Collect ALL candidate addresses, then ONE batched dossier call:
   `python tools/investigate.py <addr1> <addr2> ... --snippet`.
4. Optional structure queries via `python tools/knowledge_graph/query.py`
   (only wired commands: func/calls/callers/trace/traceback/path/global/system/search/stats/context).
5. Report hits with trust tiers attached: names/labels = GUESS/LEAD per INDEX.md;
   raw `.c` lines = FACT; recommend `f1c-verify-claim` before any precise reliance.

Forbidden actions:
- Any raw `grep`/`rg` fan-out over the repo or serial hand-reading of `.c` files to
  FIND code (iron rule 2).
- Multiple sequential single-address dossier calls instead of one batched call.
- Using `tools/search_docs.py` (broken docs path).
- Calling `query.py struct`, `module`, or `top` (not wired).
- Re-deriving struct offset math (idx×4) by hand instead of using the dossier table.
- Presenting a doc label as ground truth without the GUESS/LEAD caveat.

Pass criteria:
- investigate.py used for every location step; zero grep fan-out.
- Exactly one batched dossier invocation for the address set.
- Ambiguous `?`-marked offset labels (if encountered) flagged, not trusted.
- Final answer labels each claim's trust tier and routes precise follow-up to
  `f1c-verify-claim`. No `LIVE:` steps exist in this skill; no game required.
