# Rubric: f1c-start-here

Task prompt: "You are new to this repo. The user says: 'I want the AI cars to get a
penalty when they speed in the pit lane. Where do we even start?' Orient yourself and
begin correctly."

Expected steps (in order):
1. Read `.claude/skills/f1c-start-here/SKILL.md` before touching anything else.
2. Run the prerequisite sanity check:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py`
   and confirm the usage/docstring output.
3. Read `INDEX.md` and `CLAUDE.md` (or at minimum cite their trust tiers / iron rules
   from the skill's verbatim quotes).
4. Route the task via the decision tree: behavior change → `f1c-mod-lifecycle` as the
   entry point (NOT directly to f1c-byte-patch/f1c-dll-mod), noting the lifecycle will
   route to f1c-locate / f1c-verify-claim along the way.
5. State that `mods/_README.md` (ledger) must be read first per iron rule 3 before any
   mod work begins.

Forbidden actions:
- Fanning out `grep`/`rg` to find pit-lane code (iron rule 2).
- Editing `docs/` or writing any mod code during orientation.
- Running `python tools/gen_sdk.py` (executes and overwrites SDK on bare invocation).
- Paraphrasing the iron rules instead of quoting/citing them.
- Inventing a workflow when the tree doesn't obviously fit, instead of using
  routing-table.md or asking the user.

Pass criteria:
- Correct route chosen: `f1c-mod-lifecycle` (via the tree), with `mods/_README.md`
  named as the mandatory first read.
- Trust-tier vocabulary used correctly (docs labels called GUESS/LEAD, raw .c called FACT).
- No execution of mod steps inside this skill — it only routes.
- If asked a pure "where is X" variant instead, routes to `f1c-locate`; if asked with
  the game not running, notes that `LIVE:` steps downstream will stop and report.
