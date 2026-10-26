> **HISTORICAL SNAPSHOT 2026-07 — pedagogy, not current state. Check `mods/_README.md` for live status.**
>
> This is the ONLY file in the skill library permitted to inline addresses/offsets. They are
> frozen teaching examples, not current facts. Never copy an address from this file into a
> live mod — re-verify against the ledger and the running game first.

# f1c-debug-failed-mod — case studies

Three verbatim postmortems, each mapped to a triage-tree node. Read these to recognize the
failure SHAPE, then diagnose YOUR mod with `triage-tree.md` against the LIVE game.

---

## Case 1 — safety_car v3: GUESS offset in the chain, never live-probed (Node 3)

A whole DLL was built on top of an unverified GUESS-tier offset. Per-fact preflight
(CLAUDE.md rule 4) would have gated this before any C was written.

`mods/_README.md` Current-contents ledger row (verbatim):

> | `safety_car/` | **Safety car deployment via oph.dll** — two-layer speed governor (SafetyCarFollow flag + liveLapRatio clamp), AI cmd 0xe queue injection, auto-deploy on DNF, manual hotkeys (NUM8/2/5) | **v3 UNTESTED** — built on v2 prototype (`analysis_pipeline/work/oph/`). Speed offset 0x453C is GUESS tier; run NUM5 probe to verify. Plan: `plans/investigate-and-figure-out-imperative-llama.md` |

`mods/safety_car/README.md` — status header:

> ## Status: TESTING REQUIRED
>
> v3 adds speed governor and probe diagnostics but key offsets are GUESS tier.
> Run the probe (NUM5 in-game) and check `LOG\safety_car.txt` before trusting
> speed control.

`mods/safety_car/README.md` §Known Limitations (first bullet):

> - Speed governor offset (0x453C) is GUESS tier — may need adjustment

`mods/safety_car/README.md` — the falsification criterion (end of §Phase 1 Verification Checklist):

> If `live_lap_ratio` shows garbage (very large/small numbers, NaN), the
> byte offset 0x453C is wrong — consult the probe raw bytes dump to find
> the actual location.

**Lesson:** garbage/NaN out of a struct field means the offset is GUESS-wrong. The fix is not
in the C — it is finding the real offset (probe the raw bytes, `f1c-live-probe`), then a
`[CORRECTION]`. The falsification criterion was written INTO the mod but never executed;
running it (probe `[<veh-ptr>]+0x453C:float`, expect ~0.85–1.0) would have caught it in
seconds.

---

## Case 2 — replay-ai-fix: three failed attempts + a stale-ledger correction (Nodes 1 & 4)

The ledger itself once overstated this mod as shipped. "Read the ledger" means read it
CRITICALLY — the mod's own artifacts carry the ground truth.

`mods/replay-ai-fix/apply_replay_ai_fix.py` module docstring (verbatim):

> Bugfix: AI simplified driving after instant replay.
>
> STATUS: NO WORKING PATCH YET — see docs/28-known-bugs.md for full analysis.
>
> Root cause: FUN_004ef5a0 (Vehicle State Setter) has an InternalState != 5 gate
> at VA 0x004ef623 that returns early, preventing AI_ENABLE from firing during
> replay exit when InternalState hasn't reached RACING (5). Mid-race replays work
> fine; early replays (during formation/lights) leave AI in simplified mode.
>
> Three patch attempts failed:
>   1. Save offset change → grid bunching
>   2. Phase 5→3 comparison → timer delay too long for short tracks
>   3. NOP jne in backup enable → timer delay still present
>
> Proposed fix (not yet validated): NOP the InternalState gate in FUN_004ef5a0
> at VA 0x004ef62a (75 46 → 90 90). Risk: may break formation driving during
> normal game startup since 0→1 transition also passes through this path.

`mods/_README.md` Current-contents ledger row (verbatim):

> | `replay-ai-fix/` | Bugfix attempt: AI simplified driving after instant replay | **NO WORKING PATCH YET** — 3 attempts failed; proposed fix unvalidated. See `docs/28-known-bugs.md` BUG-001 + `apply_replay_ai_fix.py` header |

`work/CHANGELOG.md` — the stale-ledger correction (verbatim):

> [CORRECTION] mods/_README.md claimed replay-ai-fix = shipped "1-byte patch (GREEN_FLAG
> instead of FINISHING)". FALSE: apply_replay_ai_fix.py header says "NO WORKING PATCH YET";
> docs/28 BUG-001 records 3 failed attempts (grid bunching / timer delay / gate still blocks).
> mods/_README.md and docs/33 exec summary + byte-patch row corrected.

**Lesson:** when the ledger and the mod's own `apply_*.py` header disagree, the artifact
wins, and the ledger gets a `[CORRECTION]` (Node 1). Also: each of the three attempts changed
a DIFFERENT lever (save offset, phase comparison, NOP the jne) and each produced a NEW side
effect — a signature that the underlying FACT (which gate actually blocks) was never pinned
down first. Note the proposed fix touches a shared code path (the 0→1 transition) — a
shared-path side-effect risk (the Node 1/3 fact class: pin down which gate actually blocks,
against live evidence, before patching a path many transitions share).

---

## Case 3 — ai_pit_retire: "writes stick ≠ game reacts" (Node 2, the log-confirmed-only trap)

A mod can log perfect read-backs and still not produce the observable. Only an in-game
observation upgrades a mod to CONFIRMED.

`mods/_README.md` Current-contents ledger row (verbatim):

> | `ai_pit_retire/` | **Press F8 in a race → every AI car pits + DNFs** (player untouched) | **LOG-CONFIRMED ONLY** — v3 log shows writes land (`retired 21 AI cars (count=22)`) but desired in-game outcome NOT confirmed by user. Writes stick ≠ game reacts. Run `tools/preflight.py` stability check on `veh+0x4064` next; suspect game logic never reads it, or reads a different field. |

`mods/ai_pit_retire/README.md` §Notes / limits (verbatim):

> - Hybrid design: cars are marked pitting + DNF in one shot; they do **not**
>   drive a full in-lap first. Scoring/standings show them as retired.
> - Non-ASLR binary (base 0x00400000) so absolute VAs are used directly.
> - Physics/AI may keep the car object alive visually until the game's own
>   retirement cleanup runs off FinishState. Verify in-game.

**Lesson:** the log says `retired 21 AI cars (count=22)` — the writes landed perfectly — yet
the in-game outcome was never user-confirmed. The prescribed next move is exactly Node 2's
test: a `preflight.py` stability check on `veh+0x4064` to see whether the game re-derives the
field (clobbering the write) or reads a different one. (Note: one memory file calls this mod
"already works"; the ledger's **LOG-CONFIRMED ONLY** is the authoritative status — another
Node-1 reminder to trust the ledger's evidence, not stray optimism.)

---

## The bits-not-vibes failure report (mandatory exit)

Never close with "nothing happened". Fill this in from the mod's log and your live probes:

```
MOD: <name>   VERSION: <vN>   TRIAGE NODE(S): <1–6>
PREDICTED OBSERVABLE: <what should have happened in-game>
ACTUAL: <what happened>

WRITES (from <name>_log.txt):
  <addr/field> = <value written> -> re-read <value got>   [landed? yes/no]
GATE STATES at action time:
  SessionType=<v> RaceActiveFlag=<v> <other gates>=<v>
STABILITY (preflight probe, if run):
  <expr> over <secs>s: <stable | changed to X> -> field owned by game? yes/no

REFUTED FACTS (each needs a [CORRECTION] via f1c-doc-audit):
  <doc> <fact> — expected <X>, live shows <Y>
LEDGER UPDATE APPLIED: <new Status text in mods/_README.md>
NEXT STEP: <lowest untried ladder rung / next fact to pin>
```

A report shaped like this lets the next session resume without re-deriving anything. That is
the whole point: bits, not vibes.

---
Canonical sources: mods/_README.md §Current contents; mods/safety_car/README.md; mods/replay-ai-fix/apply_replay_ai_fix.py (header); mods/ai_pit_retire/README.md; work/CHANGELOG.md ([CORRECTION] entries)
Last validated: 2026-07-18 against 6bcccfe
