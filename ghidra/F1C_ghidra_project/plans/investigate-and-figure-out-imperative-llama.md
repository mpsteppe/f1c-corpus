# Safety Car Implementation Plan for F1 Challenge 99-02

## Context

F1C shipped without a safety car — ISI's #1 cut feature. But the infrastructure is
surprisingly intact: AI command `0xe` ("safety car") still works, vehicle struct
offset `+0x443c` (SafetyCarFollow flag) activates reduced-speed following, and the
SDK defines `mGamePhase=6` as "Full course yellow / safety car" with a full 8-state
`mYellowFlagState` lifecycle. NASCAR Thunder 03/04 (same engine) shipped with a
complete full-course caution/pace car system — 15+ functions in `raceevent.cpp`.

An existing prototype `oph.dll` (at `analysis_pipeline/work/oph/`) already proves
the concept: sets `+0x443c=1` on all AI, injects command `0xe` into their queues,
triggers on DNF count, runs a 5-state machine (IDLE/DEPLOYING/ACTIVE/WITHDRAWING/COOLDOWN).
It works but is minimal — no yellow flags, no field ordering, no pit rules, no
unlapping, no speed governor, no physical SC vehicle model.

Goal: evolve the existing `oph.dll` prototype into a proper safety car system,
using NASCAR's documented caution architecture as the design reference.

---

## What Already Works (Don't Rebuild)

| Component | Status | Source |
|-----------|--------|--------|
| DLL injection via `oph.dll` slot | PROVEN | Game calls `LoadLibraryA("oph.dll")` + `start()` |
| Vehicle iteration + race gate | PROVEN | `oph.c` lines 89-102, 267-283 |
| `+0x443c` SafetyCarFollow flag | PROVEN | Sets AI to reduced-speed following |
| AI command `0xe` queue injection | PROVEN | `oph.c` lines 107-153 |
| HUD messages via `FUN_0045bd10` | PROVEN | `oph.c` line 200 |
| SC vehicle identification (car #99) | PROVEN | `.veh` file + number scan |
| SC vehicle parking (FinishState=DSQ) | PROVEN | `oph.c` line 187 |
| 5-state machine skeleton | PROVEN | `oph.c` lines 65-334 |
| Manual hotkey deploy/withdraw | PROVEN | `oph.c` lines 225-261 |

## What's Missing (Implementation Targets)

### Phase 1: Verify & Harden Existing Mechanism (1-2 days)

Before adding features, verify the existing `+0x443c` and `0xe` claims against
the live game with `tools/preflight.py`. The mods/_README.md warns that
"writes stick ≠ game reacts."

**Tasks:**

1. **Probe `+0x443c` behavior** — write `SafetyCarFollow=1` to one AI via
   `poke.py`, observe if it actually slows down. Measure speed delta.
   ```
   python tools/preflight.py probe "read_int(vehicle_ptr(0) + 0x443c)"
   python tools/poke.py write vehicle_ptr(0)+0x443c 1
   ```

2. **Probe command `0xe`** — inject `0xe` into one AI's queue, observe behavior
   change. Does the AI acknowledge it? Does it change driving state?

3. **Probe `RacePhase` write** — write `RacePhase=6` (the SDK's "full course
   yellow" value) at `0x007c56a8`. Does anything happen? Does the game's own
   steward/flag logic react?

4. **Probe FlagState** — find the flag bitfield in F1C (documented at
   `0x007d02e8` per explore, needs verification). Write the safety-car bit.

5. **Document results** — which writes produce visible behavior, which are dead.

**Files:** `mods/safety_car/facts.json` (preflight fact set)

### Phase 2: Speed Control (2-3 days)

Current `+0x443c` flag may just slow AI vaguely. Need precise speed limiting.

**Tasks:**

1. **Map AI target speed** — `FUN_0059e450` (AI target speed calculation) is
   documented. Find where target speed is stored in vehicle struct. Candidate:
   offset `+0xf5b` has values `{1,2}` labeled "Vehicle driving state:
   1=pit/caution? 2=racing?" (docs/24-enum-catalog.md line 7239).

2. **Pit lane speed limiter reuse** — `FUN_004bf300` already implements speed
   limiting for pit lane, reading `PitLaneSpeedLimit` at `0x007c5700`. Can we
   repurpose this? Write a custom speed to `PitLaneSpeedLimit` and force the
   "in pit lane" flag? Or directly write a target speed to the AI's speed field?

3. **Safety car speed** — NASCAR uses sector-based pacing. F1 uses a simpler
   constant SC speed (~120 km/h). Implement as a constant memory write to each
   AI's target speed field, re-applied every tick.

4. **SC vehicle itself** — when active, the SC vehicle (car 99) should drive at
   SC speed. Currently it just gets FinishState=0 (running) — need to verify it
   actually drives and isn't stuck in grid position.

**Key addresses to investigate:**
- `FUN_0059e450` (AI target speed) — find the output field
- `FUN_004bf300` (pit speed limiter) — reusable logic
- `PitLaneSpeedLimit` at `0x007c5700`

### Phase 3: Field Ordering & No-Overtaking (3-4 days)

NASCAR's `sub_4C9A50` manages the field queue. F1C needs:

**Tasks:**

1. **Position locking** — during SC, freeze race positions. Find the "current
   race position" field in vehicle struct (likely near `+14116` per NASCAR
   offsets, but F1C struct differs). Lock it by writing back each tick.

2. **Gap control** — AI should close up behind leader at ~1s gaps. The
   `SafetyCarFollow` flag may do this already — verify in Phase 1. If not,
   write target gap values to the AI following-distance field.

3. **Overtaking ban** — `FUN_0059e700` (AI overtaking decision) checks
   `RacePhase` per docs. If `RacePhase=5` or `6` disables overtaking, writing
   RacePhase might be enough. Otherwise, find the overtaking-enable flag per
   vehicle.

4. **Leader identification** — SC should pick up the race leader. Need to read
   position data and identify who's P1 to set SC speed reference.

### Phase 4: Yellow Flag Visuals (2-3 days)

**Tasks:**

1. **Flag state** — find the flag rendering variable. `FlagState` bitfield at
   `0x007d02e8` — bit 3 may be safety car. Write it and check if yellow flags
   appear on track marshal posts.

2. **HUD yellow** — if flag rendering doesn't work via memory write, use the
   existing HUD function (`FUN_0045bd10`) to display "YELLOW FLAG" messages.

3. **"SC" board** — the string `"SC"` exists at `0x005d6f38` (Str_SC global),
   used by `FUN_004fc400`. Investigate what this function does — may be the
   SC board display code.

### Phase 5: Pit Lane Rules (2-3 days)

Under safety car in F1, pit lane opens after a delay.

**Tasks:**

1. **Pit window control** — F1C already has pit window open/close timing
   (`FUN_004d2e50` — pit window timing). Can we manipulate it during SC?

2. **SC pit behavior** — AI should be able to pit during SC. Currently the
   SC follow flag may prevent pit entry. Need to exempt pitting cars from
   the follow flag.

3. **Queue management** — cars leaving pits rejoin at back of SC queue.
   NASCAR's `sub_4B88A0` (restart position setup) handles this.

### Phase 6: Deployment Intelligence (1-2 days)

Current trigger: DNF count. Upgrade to:

**Tasks:**

1. **Crash detection** — detect when vehicles crash/retire AND are stranded
   on track (not in pits). Use FinishState + position data.

2. **Multi-criteria deployment** — combine: DNF on track, heavy collision
   (read collision data), rain conditions.

3. **Duration scaling** — vary SC duration based on incident severity and
   track length. Short tracks = fewer laps under SC.

### Phase 7: Restart Procedure (2-3 days)

**Tasks:**

1. **SC withdrawal** — SC vehicle returns to pits (drive through pit lane,
   then FinishState=DSQ to park).

2. **Rolling restart** — field stays in SC queue order, leader controls pace
   for final lap before green. Gradual speed increase.

3. **Green flag** — restore normal RacePhase, clear all SafetyCarFollow flags,
   clear overtaking bans, restore normal AI speed targets.

---

## Architecture Decision

**Approach: DLL tick-loop with memory writes** (strategy ladder step 2+3)

The existing `oph.dll` architecture is correct. Don't call game functions from
injected code (thiscall danger). Instead:

- Read game state via raw memory reads (vehicle array, race phase, positions)
- Write game state via raw memory writes (flags, speeds, phases)
- Use the game's own AI infrastructure (`0xe` command, `+0x443c` flag)
- Only exception: HUD display via `FUN_0045bd10` (__cdecl, safe to call)

This matches the proven pattern from `cut_track_dq` and `red-flag-dll`.

---

## Critical Files

| File | Role |
|------|------|
| `analysis_pipeline/work/oph/oph.c` | Existing prototype to evolve |
| `analysis_pipeline/work/oph/zzz_safety_car.veh` | SC vehicle definition |
| `mods/_README.md` | Ledger — update when mod ships |
| `tools/preflight.py` | Fact verification before code |
| `tools/poke.py` | Live memory probing |
| `docs/02-ai-system.md` | AI command queue (0xe) docs |
| `docs/12-globals-reference.md` | Global addresses |
| `docs/13-struct-offsets.md` | Vehicle struct layout |
| `source_material/Nascar Thunder 2003/docs/40-gameplay.md` | NASCAR caution reference |
| `source_recovery/03_sdk_crossref/headers/InternalsPlugin.hpp` | SDK phase/flag definitions |

---

## Verification Plan

Each phase must pass verification before moving to next:

1. **Phase 1:** `preflight.py` fact checks pass. Each claim (flag sets speed,
   command changes behavior, RacePhase triggers logic) gets a TRUE/FALSE.

2. **Phase 2:** In-game test: deploy SC manually (NUM8), observe AI visibly
   slow to SC speed. Measure with telemetry overlay or poke.py speed reads.

3. **Phase 3:** In-game test: cars maintain position order behind SC. No
   overtaking observed during SC period.

4. **Phase 4:** In-game test: yellow flags visible on marshal posts and/or HUD.

5. **Phase 5:** In-game test: AI can pit during SC, rejoin at back.

6. **Phase 6:** In-game test: SC deploys automatically on crash, not just DNF.

7. **Phase 7:** In-game test: SC withdraws cleanly, racing resumes, no AI
   bunching or stuck cars.

---

## Risk Register

| Risk | Mitigation |
|------|------------|
| `+0x443c` flag doesn't actually control speed | Fall back to direct speed-field writes |
| `RacePhase` write crashes the game | Use custom state variable in DLL instead |
| AI command `0xe` is truly dead code | Implement speed control via direct memory writes only |
| SC vehicle (car 99) doesn't drive properly | Use "virtual" SC — no physical car, just AI slow mode |
| Vehicle struct offsets wrong (GUESS tier) | Verify every offset with `preflight.py` before shipping |
| No yellow flag rendering mechanism | Accept HUD-only messages as MVP |

---

## Recommended Execution Order

**MVP (Phase 1+2+3):** ~1 week. Verifiable safety car with speed control and
field ordering. No yellow flags, no pit rules, no restart procedure. This
alone would be a significant feature.

**Full (all phases):** ~3 weeks. Complete safety car system matching real F1
procedures.

Start with Phase 1 — everything depends on which memory writes actually work.
