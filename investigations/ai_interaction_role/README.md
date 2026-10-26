# Role direction of the transient AI interaction pointer at vehicle `+0x45FC`

Read-only static investigation. Scope: only the canonical repository interface
`python tools/f1c_mod.py`; no game/process access, no memory writes, no
`api1.txt`, no settings/RCD edits. Only file created by this investigation is
this report.

## Current readiness

- Static core map: verified through initialization, 25-ms AI scheduling,
  planner/traffic/gear/pit/race-order paths, and the normal mode-1
  output-to-physics chain.
- Safe writable core-AI SDK contract: **not proved**. The public pace
  specialist and generic SDK gate do not prove a supported insertion phase,
  writer arbitration, stable lifetime/range, or replay/network behavior.
- Therefore: preserve the map as read-only evidence; do not expose the
  recovered control vector or physical aliases as SDK writes.

## Commands run

```
python tools/f1c_mod.py start --json
python tools/f1c_mod.py inspect 0042af70 --full     # Overtaking (raw Hex-Rays)
python tools/f1c_mod.py inspect 004270a0 --full     # AISteering (raw Hex-Rays)
python tools/f1c_mod.py inspect 0042a7d0 --full     # OpponentProximityScanTeamRecognition
python tools/f1c_mod.py inspect 004bf390 --full     # AIDriverSorting
python tools/f1c_mod.py inspect 00424790 --full     # AIDriverStructInit (0x45FC/0x45F8/0x4420 init)
python tools/f1c_mod.py inspect 00423e80 --full     # RaceStructInit (0x45FC init)
python tools/f1c_mod.py inspect 00426cf0 --full     # AISteeringCorrection (0x45FC reader)
python tools/f1c_mod.py inspect 0042ae20 --full     # AIDriverRandomSelector (0x45FC reset)
python tools/f1c_mod.py inspect 004c6e80 --full     # sub_4C6E80 (calls the reset, vehicle removal)
python tools/f1c_mod.py inspect 00429470 --full     # AIAbility (0x45F8 reader: fuel cross-check)
python tools/f1c_mod.py inspect 00424e70 --full     # AIMainUpdate (AI-update call order)
python tools/f1c_mod.py inspect 004c7bd0 --full     # sub_4C7BD0 (team-recognition gate)
python tools/f1c_mod.py inspect 0042ae60 --full     # ServerSessionGateCheck (session-5 gate)
python tools/f1c_mod.py evidence-query offset 0x45FC
python tools/f1c_mod.py evidence-query offset 0x45F8
python tools/f1c_mod.py evidence-query offset 0x48A4   # TeamIndex (pit team)
python tools/f1c_mod.py evidence-query offset 0x48A8   # garage bay index
python tools/f1c_mod.py evidence-query offset 0xCD4    # FrontWingRecordPtr
python tools/f1c_mod.py evidence-query offset 0xD18    # RearWingRecordPtr
python tools/f1c_mod.py search "0042af70|004270a0|0042a7d0|004bf390" --regex
```

Raw Hex-Rays C (`functions/*.c`) is the authority. `skeletons*`, `name_index`,
and derived prose are aids only.

## Offset arithmetic used (index*4)

- `this[4360]`  = `+0x4420` (lateral steering-line offset / "side offset")
- `this[4418]`  = `+0x4508` (per-AI-update interaction counter)
- `this[4419]`  = `+0x450C` (shared max speed, recalc)
- `this[4478]`  = `+0x45F8` (companion "previous/other vehicle" pointer)
- `this[4479]`  = `+0x45FC` (the pointer under investigation)
- `this[3681]`  = `+0x3984` (fuel ratio; gates: `> 0.001`)
- `this[3931]`  = `+0x3D6C` (carConditions; gate: `!= 2`)
- `this[4111]`  = `+0x403C` (lapNumber)
- `this[4135]`  = `+0x409C` (bestLap)
- `this[4189]`  = `+0x4174` (proximity slot 0 primary vehicle pointer)
- `this[4203]`  = `+0x41AC` (proximity slot 0 secondary pointer)
- `this[4202]`  = `+0x41A8` (proximity slot 0 squared distance)
- `*this`       = first dword = vehicle self/object pointer; `obj+0x403C` lap,
  `obj+0x48A4` team (TeamIndex), `obj+0x48A8` garage bay, `obj+0xCD4/0xD18`
  wing records.
- `dword_7C56A4` = session type (`7` = race; `5` = special-cased qualifying).

## Verified facts (raw code)

### Writers of `+0x45FC` (evidence-query offset 0x45FC)

| Address | Function | Write |
|---|---|---|
| 0x00424790 | AIDriverStructInit | `this[4479] = 0` (init) |
| 0x00423e80 | RaceStructInit | `this[4479] = 0` (init) |
| 0x00424e70 | AIMainUpdate | `*(this+17916) = 0` (race-countdown/early path) |
| 0x0042a7d0 | OpponentProximityScanTeamRecognition | `this[4479] = vehicle` + `this[4360] = +/-2.5` |
| 0x0042af70 | Overtaking | `this[4479] = a2` + `this[4360] = +/-3.0` |
| 0x0042ae20 | AIDriverRandomSelector | `*(this+17916) = 0` if `a2 == *(this+17916)` (vehicle removal/reset) |

Readers: inits, AIMainUpdate, AISteeringCorrection (0x00426cf0), Overtaking,
ProximityScan, selector. The value is a **vehicle pointer**: ProximityScan
stores `dword_7C54F0[i]` (global vehicle array); the selector identity-compares
it against a vehicle pointer passed from sub_4C6E80 (called on vehicle
reset/removal, per car, `AIDriverRandomSelector(dword_7C54F0[i], this)`).

### Companion `+0x45F8`

`AIDriverStructInit` is a recovered non-zero writer during its full-init path:
it clears `this[4478]`, scans `dword_7C54F0`, and stores each non-self vehicle
whose C string at vehicle `+0x46B8` equals THIS vehicle's string at `+0x46B8`.
If several match, the last matching vehicle in the global vehicle-array order
wins. `RaceStructInit` clears the field and `AIDriverRandomSelector` clears a
matching value during reset/removal. `AIAbility` passes a non-zero field to
`FuelMultiplierValue` / `FuelWeightLimitCheck`, proving it is treated as a
vehicle pointer for an associated-car fuel/pit-exit check. The semantic label
of the matched `+0x46B8` string is not proven by this code.

### `Overtaking_0042AF70` (sub_42AF70) — `functions/Overtaking_0042af70.c`

`int __thiscall sub_42AF70(float *this, float *a2, int a3)` — `this` =
current vehicle AI struct, `a2` = candidate vehicle, `a3` = side/mode.

Entry: `if (ReplayAIStateCheck(this+3)) return 0;`

Speed share: `this[4419] = max(this[4419], a2[4401])` (`+0x450C` vs
candidate `+0x44C4`).

Session gate (`dword_7C56A4`):
- `!= 7`:
  - `== 5` (qualifying): `if (ServerSessionGateCheck(this) || !ServerSessionGateCheck(a2)) return 0;`
    → act only when THIS fails the gate **and** candidate passes it.
    `ServerSessionGateCheck` (sub_42AE60): pass iff `callToBox(+0x454C)==1`
    **or** `lapOfRun(+0x4094) != 2`. So the act condition is: THIS on
    `lapOfRun==2`, not called to box (flying/qualifying lap), candidate
    pitting or on another lap.
  - otherwise (practice/other): `if (a2[4135] >= this[4135]) return 0;`
    → act only when **candidate `bestLap(+0x409C)` < THIS `bestLap`** (THIS
    is the faster car).
  - then `goto LABEL_26` (act).
- `== 7` (race):
  - `if (*(*(_DWORD*)a2 + 16444) > this lapNumber)` → `LABEL_26` (act):
    **candidate `obj+0x403C` lapNumber > THIS lapNumber** (candidate is a lap
    ahead).
  - else `if (this[4478] != a2) return 0;` — the only other recovered race
    exits (`this obj+0x48A8 > a2 obj+0x48A8 && this lap > 3`, and the
    wing-record pair below) are gated behind `this[0x45F8] == a2`. No
    recovered indexed *direct* writer establishes that non-zero relationship.
    This is insufficient to call the branches unreachable: the offset has
    runtime-observed non-zero values, and their provenance is unresolved.
  - wing branch: `(this obj+0xCD4 && !this byte+0xD14) || (this obj+0xD18 && !this byte+0xD58)`
    AND `(!a2 obj+0xCD4 || a2 byte+0xD14) && a2 obj+0xD18 && !a2 byte+0xD58`
    → THIS has a pending wing record; candidate has a pending REAR-wing
    record (`obj+0xD18` set, byte+0xD58 clear = the retirement trigger per
    PitStopBlockingCondition 0x0042aee0). Guarded by the same unresolved
    `0x45F8` relationship.

Commit (`LABEL_28`):
```
if ( v4 && this[3931] != 2 && this[3681] > 0.001 )
{
  this[4479] = a2;                     // +0x45FC = candidate vehicle
  if ( a3 == 2 ) this[4360] =  3.0;    // +0x4420 = +3.0  (mode 2 only)
  else           this[4360] = -3.0;    // +0x4420 = -3.0  (modes 1, 8)
}
```
Guard triple mirrored in AIMainUpdate: `if (!*(this+17916) && this[3931] != 2 && this[3681] > 0.001) *(this+17440) = 0;`
→ `+0x4420` is cleared every AI update unless `+0x45FC` is set.

### Caller `AISteering_004270A0` (sub_4270A0)

- Per-AI-update scan of the 5 proximity slots (`this+0x4174 + 68*i`); candidate
  slot `v33 = &this[68*v30]`, so `v33+16756` = slot base; slot vehicle
  pointer `v34 = *((_DWORD*)v33 + 4189)` = `+0x4174`.
- Mode variable `v86` (the `a3` argument) is resolved from lateral geometry:
  `v86 ∈ {1, 2, 7, 8}` at the two call sites.
- Call sites (raw C):
  - `if (v86 == 2 || v86 == 7) { ... Overtaking(this, v86); ... }`
  - `else if (v86 == 1 || v86 == 8) { ... Overtaking(this, v86); ... }`
  - Hex-Rays renders two args, but the callee dereferences a2 as a valid
    vehicle pointer and needs the mode as a3. The exact call-site argument
    transfer is therefore unresolved. The candidate-slot pointer is a strong
    contextual inference, not raw ABI proof.
- Mode→offset: `v86 == 2` → `+3.0`; `v86 ∈ {1, 7, 8}` → `-3.0`.
- Geometry inputs: `v144` = target lateral position of the candidate's line
  (dot of candidate heading vs track-target delta); `v165 = v144 - this[4362]`
  (lateral error); `v94`/`v148` per-side steering costs; side selection
  compares `v33+4190` (candidate lateral) sign or `v94` vs `v148`.

### `OpponentProximityScanTeamRecognition_0042A7D0` (sub_42A7D0)

- Called first in each AIMainUpdate, before AISteering
  (line 247) and AISteeringCorrection (line 249).
- Writes `+0x45FC` only under:
  - `dword_7C56A4 == 7` (race),
  - `v41 < 625.0` (squared distance < 25 units),
  - `sub_4C7BD0(v7)` true — `v7[0x4894] == vehicle[dword_7C54F0[dword_7C54E4]] [0x4894]`
    (same team ID; "TeamRecognition" gate),
  - `*(v7 + 0x403C) > this[0x403C]` (candidate lapNumber > this lapNumber).
  - then `this[4479] = v11` (`+0x45FC` = `dword_7C54F0[i]` vehicle),
    and `this[4360]` (`+0x4420`) = `-2.5` if
    `(cand.z - this.z)*this[4387] - (cand.x - this.x)*this[4389] <= 0.0`
    else `+2.5` (side from 2-D cross product of relative position with THIS
    car's forward vector at `+0x448C`/`+0x4494`; those are set in AIMainUpdate
    from yaw at `+0x34F0`: `-sin(yaw)`, `-cos(yaw)`).

### `AIDriverSorting_004BF390` (sub_4BF390)

- `__stdcall sub_4BF390(int a1)`; re-orders race **positions** independently:
  - race (`dword_7C56A4 == 7`): compares `lapNumber (+0x403C)` then
    `totalTimeOnFinishLine (+0x4098)`; swaps `+0x4034` position via
    ConditionalFieldSetter when a1 is ahead.
  - other sessions: `bestLap (+0x409C)`.
- It never touches `+0x45FC`. Confirms: a `+0x45FC` event does not by itself
  prove a completed pass.

## Inferences (marked as such — from raw code, not decompiler prose)

1. **`a2` at the Overtaking call sites is the candidate vehicle pointer.**
   The callee dereferences `*a2` (vehicle self-pointer), `a2[0x44C4]`
   (speed), `a2[0x409C]` (bestLap) and `*(*(_DWORD*)a2 + 0x403C)` (candidate
   lap) — all vehicle-struct offsets; ProximityScan writes the identical
   field with a `dword_7C54F0[i]` vehicle pointer; the reset path
   identity-compares it with vehicle pointers. The candidate vehicle pointer
   available at the call site is `v34 = *((_DWORD*)v33 + 4189)` (slot
   `+0x4174`). (Open: the Hex-Rays listing drops the middle argument; the
   exact register/stack slot is not visible without disassembly.)

2. **In race mode (`==7`), the writer of `+0x45FC` is the car BEHIND in
   laps.** The only provable race path (both Overtaking and ProximityScan)
   fires when `candidate lapNumber > this lapNumber`, i.e. the candidate is a
   lap ahead. The writer (THIS car) points AT the lap-ahead car and applies a
   `+/-2.5` (ProximityScan) or `+/-3.0` (Overtaking) steering-line offset.
   The writer is therefore the lapped/backmarker car, and the pointed-to car
   is the lapping (attacking) car. The writer is NOT the attacker in this
   branch.

3. **In practice/other sessions (`!= 7`, `!= 5`), the writer is the
   code-selected faster car.** The gate requires candidate `bestLap < this
   bestLap` (THIS faster). That is consistent with a pass-seeking interaction,
   but static code here does not prove a physical attack, the candidate's
   on-track position, or a completed pass.

4. **In qualifying (`==5`), the writer is the car selected by the
   flying-lap gate.** THIS must be on `lapOfRun==2` and not called to the box;
   the candidate must satisfy the complementary gate (called to box or not on
   that lap). This is consistent with a flying-lap car negotiating traffic,
   but it does not statically prove a physical pass or attacker intent.

5. **`+0x4420` is the lateral steering-line offset.** Written `+/-3.0` /
   `+/-2.5` on interaction, held at 0 otherwise (AIMainUpdate clears it when
   `+0x45FC` is 0). AISteeringCorrection consumes `+0x45FC`: when set, it
   caps steering input (`+0x457C`) at `0.75 * AIDifficultyScalar()` — the
   "wheel-to-wheel reduced steering" state, role-agnostic.

6. **The `0x45F8`-gated race branches (garage-bay compare and wing-record
   pair) have no recovered indexed direct non-zero writer.** Init paths set
   the field to zero and the selector clears matching values, but
   `evidence-query offset 0x45F8` also reports runtime-observed non-zero
   values. The static index therefore does not prove the branches live, and
   the runtime observation means it also does not prove them unreachable. If
   an indirect/unindexed writer establishes the relationship, the wing branch
   would mean: THIS has a pending wing record AND candidate has the
   retirement-triggering rear-wing record — a damaged-car interaction, not a
   clean attacker/defender role.

## Comparison: Overtaking vs ProximityScan

| | Overtaking (0x42af70) | ProximityScan (0x42a7d0) |
|---|---|---|
| Session | 7 (race), 5 (qual), others | 7 only |
| Distance | (caller-side slot distance) | `dist² < 625` (25 units) |
| Progress gate | candidate `+0x403C` > this `+0x403C` (race) | candidate `+0x403C` > this `+0x403C` |
| Team gate | none | same team (`+0x4894`) via sub_4C7BD0 |
| Side source | mode `a3` (2 → +3.0; 1/7/8 → −3.0), from steering geometry | cross product sign → ±2.5 |
| Magnitude | 3.0 | 2.5 |

Both write the same pointer field for the same *lap-order relationship* in
race mode (writer is lap-behind; candidate is lap-ahead). That relationship
does not by itself establish an attacker, defender, or yielding intent.
ProximityScan is the coarse same-team pre-selector; Overtaking is the refined
steering-decision writer running later in the same frame.

## Verdict

**No — the `+0x45FC` writer cannot be called "the attacker" as a general
role.** The pointer is a role-ambiguous "selected other vehicle" for close AI
interaction. In the only recovered race path that does not rely on the
unresolved `+0x45F8` relationship, the writer is the lap-behind car pointing
at a lap-ahead car and applying a lateral offset. That proves the lap-order
relationship, not whether either car is attacking, defending, or yielding.
The faster/flying-lap interpretations in non-race sessions are similarly
selection evidence, not proof of a physical pass. Thus a race-mode `+0x45FC`
event does not prove an attack and does not prove a completed pass
(`AIDriverSorting` owns order changes independently).

## Open questions (not knowable from static code alone)

1. **Call-site argument shape.** `Overtaking(this, v86)` renders as two args
   while the callee needs `(this, candidate_vehicle, mode)`. Which register/
   stack slot carries the candidate pointer, and is it `+0x4174` vs `+0x41AC`
   — resolvable only from the disassembly (not present in this repo).
2. **Left/right sign convention.** Whether `+3.0` means "left" or "right" of
   the car, and which coordinate axis the cross product and `v144`/`v165`
   use — unproven without the track/world-frame convention or a live
   observation.
3. **Intent in race mode: yield vs defend.** The lap-behind writer shifts its
   line by ±3.0/±2.5; the code does not distinguish "concede" from "defend"
   (no delta, threat, or contact check feeding the commit in the race path).
4. **`+0x45F8` writers.** The indexed writers do not establish a direct
   non-zero value, but the evidence query records runtime-observed non-zero
   values. Recover their provenance before deciding whether the garage-bay and
   wing-record race branches are live, and before assigning either branch a
   role.
5. **Mode 7 vs 8 / 1 vs 2 semantics** (which side each maps to, and what
   state 16 / 5 / 3 / 4 in the AISteering per-opponent machine do) — richer
   side/phase meaning not provable from static shape.
6. **Persisted-frame value.** Which of ProximityScan's ±2.5 vs Overtaking's
   ±3.0 (and which candidate) is last-written per frame when both gates
   overlap (same frame order: ProximityScan → AISteering).

## Next best static investigation step

Find the disassembly of `AISteering_004270A0` (or re-derive the call from the
original IDA listing) to recover the exact arguments passed at the two
`sub_42AF70` call sites, and resolve the `+0x4174`-vs-`+0x41AC` pointer and
the `v86` mode-to-side mapping; then audit for any indirect writer of
`+0x45F8` (to decide whether the garage-bay and wing-record race branches are
live). If no disassembly is available in the repo, the fallback static step is
to exhaust the index for `+0x45F8` writes (e.g. `evidence-query offset 0x45F8`
plus a full `name_index` scan) and to document the sign convention from the
field-pair `+0x448C`/`+0x4494` producers.

## 2026-08-18 review correction record

This report was independently rechecked against the canonical raw Hex-Rays
output for `Overtaking_0042AF70`, `AIDriverSorting_004BF390`, and the canonical
`evidence-query offset 0x45F8` result.

- The raw commit rule is exact: `a3 == 2` writes `+3.0` to `+0x4420`; every
  other mode value writes `-3.0`. The caller-mode table above reflects that
  rule: mode 2 is `+3.0`; observed call-site modes 1, 7, and 8 are `-3.0`.
- `+0x4098` is compared as the equal-lap race-order tie-breaker. The SDK
  currently names it `totalTimeOnFinishLine`; until its producers and units are
  fully recovered, the conservative description is **race-order timestamp
  scalar**.
- The report deliberately distinguishes raw-code facts from interpretations:
  a lap-order, best-lap, or qualifying-lap gate does not prove real-world
  attacker/defender intent, vehicle adjacency, a completed pass, or a left/
  right side convention.
- The prior wording that treated the `+0x45F8` branches as unreachable was
  removed. Indexed static evidence finds no direct non-zero writer, while the
  canonical evidence query records runtime-observed non-zero values. Their
  provenance remains an explicit open question.

## 2026-08-18 AISteering call-site and mode-family follow-up

### Commands run

```
python tools/f1c_mod.py start --json
python tools/f1c_mod.py inspect 004270a0 --full
python tools/f1c_mod.py inspect 0042a7d0 --full
python tools/f1c_mod.py evidence-query offset 0x4174
python tools/f1c_mod.py search "Overtaking" --corpus raw --context 10 --limit 20
python tools/f1c_mod.py search "LABEL_368" --corpus raw --context 10 --limit 10
python tools/f1c_mod.py search "v86 = 7|v86 = 8|v86 = 1|v86 = 2" --corpus raw --regex --context 8 --limit 30
python tools/f1c_mod.py capabilities --json
```

### Verified facts

1. `AISteering_004270A0` iterates five proximity candidates. For each selected
   slot index `v30`, it derives `v33 = &this[68 * v30]`, reads
   `v34 = *((DWORD *)v33 + 4189)` (`this + 0x4174` for slot zero), and reads
   `v35 = *((DWORD *)v33 + 4203)` (`this + 0x41AC` for slot zero). `v34` is
   used as a vehicle pointer; `v35` is used for the corresponding geometry/
   waypoint record. Canonical evidence for `+0x4174` identifies
   `OpponentProximityScanTeamRecognition` as its writer and `AISteering` as
   its reader.
2. The two recovered `Overtaking` calls occur inside that same per-slot body:
   `v86 == 2 || v86 == 7` reaches one call site; `v86 == 1 || v86 == 8`
   reaches the other. Each increments `this[4418]` before calling. The raw
   Hex-Rays text renders both calls as `Overtaking(this, v86)`.
3. The raw callee declaration is
   `sub_42AF70(float *this, float *a2, int a3)`, and the callee dereferences
   `a2` as a vehicle-like pointer before writing it to `+0x45FC`. The rendered
   two-argument calls therefore conflict with the recovered three-parameter
   callee declaration. They do **not** prove which register or stack slot
   supplies `a2` at either call site.
4. Modes form two opposing lateral-control families in the caller:
   - Modes 2/7 enter the branch containing
     `(v165 - v167) * v168 + this[4362]` and a lower-bound comparison.
   - Modes 1/8 enter the branch containing
     `(v165 + v167) * v158 + this[4362]` and an upper-bound comparison.
   That proves opposing geometric branches, not a world-space left/right label.
5. Mode transitions are not a simple attacker/defender flag. Recovered code
   selects mode 1 in one decision branch, falls back to mode 2 in another,
   can turn mode 1 into 7 when `v165 <= 1.0`, and can turn mode 2 into 1 or 8
   at the opposite geometry bound. Modes 7/8 reset both `v168` and `v158` to
   `1.0` at `LABEL_368`.
6. At the callee commit, exact raw code remains: `a3 == 2` writes `+3.0` to
   `+0x4420`; every other mode (including 1, 7, and 8) writes `-3.0`.

### Inferences

- `v34` (`+0x4174` in the active proximity record) is the strongest static
  candidate for the missing `a2` vehicle argument: it is the local per-slot
  vehicle pointer available immediately before the call, and the callee needs
  a vehicle pointer. This remains an inference until instruction-level call
  argument recovery exists.
- The four modes encode a lateral collision/line-resolution state machine,
  rather than a direct semantic role such as attacker or defender. The two
  call-site families are geometrically opposed, but their absolute side labels
  and tactical intent are unproven.

### Open question and capability boundary

The canonical `f1c_mod.py capabilities --json` interface exposes source
inspection and search but no static x86 disassembly or call-register recovery
operation. Under the read-only, canonical-interface-only scope, the exact
hidden `a2` argument cannot be established further. Do not convert the `v34`
inference into a verified fact from the decompiler's malformed call rendering.

The next evidence-producing step requires a separately authorized
instruction-level analysis path (for example, a reviewed static disassembly
export through the canonical interface). It must trace the two call sequences
at `AISteering_004270A0` and record stack/register values for both `a2` and
`a3`; no live game access is necessary.

## 2026-08-18 superseding correction: `+0x45F8` pairing is recovered

This section supersedes earlier statements in this report that said no
recovered static writer established a non-zero `+0x45F8` value or that the
`+0x45F8`-gated `Overtaking` branches had unresolved provenance.

### Verified facts

- In the full-init path of `AIDriverStructInit_00424790`, the code clears
  `this[4478]`, then scans the global vehicle array. For each non-self vehicle
  `v10`, it executes:

  ```c
  if (!strcmp((const char *)(*this + 18104), (const char *)(v10 + 18104))
      && (int *)v10 != this)
    this[4478] = v10;
  ```

- `18104` decimal is vehicle `+0x46B8`. The field is an observed string; the
  writer selects the **last** non-self vehicle in global-array order whose
  `+0x46B8` string equals THIS vehicle's string.
- `+0x45F8` is therefore a vehicle pointer produced at full AI initialization,
  not merely a clear/reset field. `RaceStructInit` zeroes it and the selector
  reset path can clear a matching pointer later.
- `AIAbility_00429470` consumes a non-zero `+0x45F8` in a race-only fuel/
  weight condition and can call `ForcePitExit(this)`. This independently
  confirms that the stored value is used as an associated vehicle pointer.
- The alternate race branches in `Overtaking_0042AF70` require
  `this[4478] == a2`. Since the paired pointer has a recovered writer, those
  branches are potentially live when the candidate is the paired vehicle.

### What this changes—and what it does not

The alternate garage-bay and wing-record branches must no longer be described
as unreachable or as having unknown pointer provenance. They express special
handling for a vehicle pair sharing the `+0x46B8` string. The semantic label
of that string is still open: raw code alone does not prove it means team,
driver, constructor, or another identity grouping. It also does not repair the
malformed Hex-Rays Overtaking call rendering, so it remains unproven whether
the candidate supplied at either AISteering call site is the paired vehicle.
Neither fact changes the primary conclusion: a `+0x45FC` write does not
generically identify an attacker or prove a completed pass.

### `+0x46B8` data-source follow-up

`NationalityDriverInfoLoader_004C78F0` copies the string into vehicle
`+0x46B8` from `v2 + 31`, where `v2 = dword_8AC394 + 1060 * a2`; it then records
`a2` at vehicle `+0x4898`. `VehicleSetupDriverNumber_004C7B50` later uses
`+0x46B8` as a linked-list lookup key. These are verified data-flow facts.
The loader references a separate `"Nationality"` lookup for a different field,
but no raw code labels `v2 + 31`; therefore calling `+0x46B8` nationality,
team, driver, or constructor remains an inference and is deliberately avoided.

### 2026-08-18 final semantic recovery: `+0x46B8` is team name

The preceding caution is now superseded by direct raw-code evidence.
`sub_417640` sets `v7 = dword_8AC394 + 1060 * a2 + 124` and tests that exact
string against the literals `"McLaren"`, `"Ferrari"`, `"Williams"`,
`"Jordan"`, `"Sauber"`, `"Arrows"`, `"Prost"`, `"Minardi"`, `"Jaguar"`,
`"Benetton"`, `"Renault"`, `"Stewart"`, and `"Toyota"` to select
team-specific IDs. Its comparison helper `sub_566810` is a case-folded
substring search, so a non-zero result is a textual match.

Therefore the vehicle string copied at `+0x46B8` is a **team-name string**, and
the full-init `+0x45F8` relationship is a **teammate pointer** (last matching
teammate in global vehicle-array order). Consequences:

- `Overtaking`'s alternate race branches can be live only when its candidate
  is the current vehicle's selected teammate.
- The garage-bay comparison and wing-record branches are teammate-specific
  special handling, not generic rival-passing logic.
- `AIAbility`'s `+0x45F8` fuel/weight condition is a teammate-aware pit-exit
  interaction.

This still does not prove an attacker, defender, yielding, or completed-pass
role for `+0x45FC`; it narrows the alternate branch relationship to teammates.

### Next static target

Recover the data-source meaning of vehicle `+0x46B8` and the circumstances in
which the Overtaking candidate equals `+0x45F8`. This is now more valuable than
another absence-of-writer audit. Instruction-level call recovery remains needed
for a definitive candidate-argument proof.
## 2026-08-18 superseding correction: proximity gate is current-vehicle, not team, selection

The earlier references in this report to a `same team` gate, `team pre-selector`, or the decompiler-derived name `OpponentProximityScanTeamRecognition_0042A7D0` are superseded.  The raw code for the gate, `sub_4C7BD0`, is:

```c
bool sub_4C7BD0(_DWORD *this)
{
  return this[4645] == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580);
}
```

`4645 * 4 = 18580 = 0x4894`.  Therefore the gate compares the candidate's `+0x4894` value with the `+0x4894` value of `dword_7C54F0[dword_7C54E4]`, the repository's current-vehicle index.  It is an identity/current-vehicle comparison, not a team comparison.  Existing field evidence identifies `+0x4894` as a scene-slot/index field; it is not the team-name field (`+0x46B8`).

In the proximity scan, after this gate, the candidate must be within squared distance `625.0`, the session must be race (`SessionType == 7`), and the candidate's `+0x403C` lap number must exceed the writer's.  The writer then stores that current vehicle in `+0x45FC` and applies a `+/-2.5` lateral offset.  Thus this is a special response by a lap-behind AI to the lap-ahead current vehicle (normally the player-controlled vehicle in the standard single-player path).  The raw code proves the selection and relative lap condition; calling the steering response *yielding* or *avoidance* remains an inference, not a proven intent label.

This strengthens, rather than reverses, the verdict: this writer is not generically an attacker.  On the proven race path it is the vehicle behind in laps reacting to a lap-ahead current vehicle.

### Player-index corroboration

`sub_42BC40` provides the missing connection for the global index.  Its raw code sets `dword_7C54E8` to the selected vehicle pointer, searches `dword_7C54F0[0..103]` for that same pointer, then writes the matching array position to `dword_7C54E4`:

```c
dword_7C54E8 = (int)&unk_5EC6D8 + 18624 * a1;
while (dword_7C54F0[result] != (char *)&unk_5EC6D8 + 18624 * a1) {
  if (++result >= 104) return result;
}
dword_7C54E4 = result;
```

The canonical facts identify `dword_7C54E8` as `PlayerVehiclePtr`; the function is also called by `NetCommPlayerSlotSync`.  Accordingly, in the normal path the proximity gate selects the player vehicle's scene-slot identity.  This proves *which vehicle* is selected, but does not turn the lateral-offset response into a proven semantic label such as "yield".

Commands used for this correction (all through the canonical repository interface):

```text
python tools\f1c_mod.py inspect 004c7bd0 --full
python tools\f1c_mod.py evidence-query offset 0x4894
python tools\f1c_mod.py evidence-query global 0x7C54E4
python tools\f1c_mod.py inspect 0042bc40 --full
```

## 2026-08-18 correction: `+0x45FC` persists in the ordinary AI path

The per-AI-update call order in raw `sub_424E70` (`AIMainUpdate`) is:

```text
OpponentProximityScanTeamRecognition(this)
AIRacingLine(this)
AISteering(this)                    // contains the Overtaking calls
sub_426100(this)
AISteeringCorrection(this)
PhysicsGearShiftLogicWithThresholds(this)
```

The raw body of `sub_426CF0` (`AISteeringCorrection`) contains the only ordinary-tick read in that sequence:

```c
if ( *(_DWORD *)(this + 17916) )
  *(float *)(this + 17788) = AIDifficultyScalar() * 0.75;
```

Thus the two writers run before the read.  The ordinary branch does **not**
clear `+0x45FC`: its recovered clears are the race-start/direct-output return
path and `AIDriverRandomSelector` when the selected vehicle is removed/reset.
Once set, the latch can therefore persist and keep applying the
`AIDifficultyScalar() * 0.75` longitudinal cap until overwritten or reset.
It still does not prove a completed pass; the consumer only tests nonzero.

Commands used:

```text
python tools\f1c_mod.py inspect 00424e70 --full
python tools\f1c_mod.py inspect 00426cf0 --full
```

## 2026-08-18 qualifying polarity recovered

The session-5 helper `sub_42AE60` is exact and small:

```c
if (dword_7C56A4 != 5)
  return 0;
if (this[4435] != 1 && this[4133] == 2)
  return 0;
return 1;
```

The confirmed offsets are `+0x454C` (`callToBox`) and `+0x4094` (`lapOfRun`).  In `Overtaking`, session 5 returns early when `ServerSessionGateCheck(this)` is true **or** `ServerSessionGateCheck(a2)` is false.  Its write path therefore requires:

```text
writer:    callToBox != 1 AND lapOfRun == 2
candidate: callToBox == 1 OR lapOfRun != 2
```

This proves the session-5 writer is the uncalled vehicle on its second lap-of-run, whereas its candidate is not in that same eligible state.  Calling that writer a flying-lap vehicle responding to traffic is a bounded inference from the confirmed `lapOfRun`/pit-call fields; the raw code still does not prove a completed pass, an attacker label, or the candidate's physical placement.

Command used: `python tools\f1c_mod.py inspect 0042ae60 --full`.

## System-map expansion: inputs, initialization, and scheduling (static)

This section broadens the dossier beyond `+0x45FC`.  It is intentionally limited to facts shown by raw code; it is not yet a full model of every AI subsystem.

### Verified facts

1. **AI update cadence and vehicle scope.** Raw `MainGameTickUpdate` (`sub_42C690`) derives a simulation tick from `SessionTime * 400.0`, advances in `0.0025` steps, and on every tenth `dword_7C5698` tick executes:

   ```c
   for (i = 0; i < dword_5C329C; ++i)
     AIMainUpdate(dword_7C54F0[i]);
   ```

   `dword_5C329C` is the confirmed vehicle count and `dword_7C54F0` the confirmed vehicle-pointer array.  Thus the main AI update is dispatched to every active-array vehicle on that scheduled full-update pass.  The same raw function separately calls `AILateralForceComputation` every 50 ticks and `FuelConsumptionAndWear` every 400 ticks; neither is evidence that those functions are part of the decision logic itself.

2. **AI database/difficulty input.** Raw `AIDatabase_Init` (`sub_4040A0`, caller `Game_Init`) sets defaults, constructs and opens the configured `AIDatabaseFile`, then calculates field `this[70]` from confirmed global `dword_7D01A0` (`AIDifficultySlider`).  The interpolation has two explicit ranges: `<=100` blends defaults `0.5 -> 1.0` at `1/30`, while `>100` blends `1.0 -> 1.3` at `1/20`.  The exact later consumers of `this[70]` are not recovered here, so it must be called a difficulty-derived configuration output, not an aggression control.

3. **Driver-structure initialization.** Raw `AIDriverStructInit` (`sub_424790`) clears/sets the per-driver state fields used by later traffic logic, including `+0x45F8`, `+0x45FC`, `+0x4420`, and several lane-search entries.  When its Boolean second argument is set, it also scans `dword_7C54F0[0..VehicleCount)` for another vehicle with identical `+0x46B8` team-name text and stores the last non-self match at `+0x45F8`.  It then obtains indexed scene data and calls `SpatialTreeNearestNeighborSearch`.  This is initialization/setup evidence, not proof that the routine executes every frame.

4. **Separate pit-mode dispatcher.** Raw `AIStateMachineWithModeDispatch` (`sub_4A5D10`) reads a byte mode from its event/record argument `a2 + 8`, stores it at its own `+0x184`, and calls `AIPitStrategyState(*this)` only when that mode changes.  For vehicle `(*this)+0x32C8` equal to `2` or `3`, mode `0` dispatches `sub_4A5F20`, and mode `2` dispatches `sub_4A5EA0`; modes `1`/`2` take a delegate/control chain.  This is a pit-machine state dispatcher, separate from the ordinary `AIMainUpdate` steering sequence.

### Inferences

- With 0.0025-second simulation steps and a full AI pass every tenth tick, the nominal full AI update interval is 0.025 seconds.  Actual wall-clock cadence can still vary with the game's time step/catch-up loop, so “40 Hz” is a derived nominal rate, not a runtime measurement.
- The database interpolation is plausibly a difficulty multiplier, but no raw consumer trace in this section proves the gameplay trait it scales.

### Open questions

- Which AI database fields feed racing-line selection, target speed, braking, and lateral lane choice.
- The initial call path and lifetime policy for `AIDriverStructInit`.
- The relation, if any, between the separate pit-machine dispatcher and `AIMainUpdate`'s driver-status/pit branches.

Commands used:

```text
python tools\f1c_mod.py inspect 0042c690 --full
python tools\f1c_mod.py inspect 00424790 --full
python tools\f1c_mod.py inspect 004040a0 --full
python tools\f1c_mod.py inspect 004a5d10 --full
```

## System-map expansion: waypoint/racing-line planning and control outputs

### Verified facts

1. **Waypoint acquisition is an AI-driving gate.** `AIMainUpdate` returns before its driving sequence unless `sub_426430(this)` succeeds.  In raw `sub_426430`, a missing current record at `+0x4354`, or one more than squared distance `3200.0` away, triggers `SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, vehicle position +0x34E0, selector +0x4550)`.  The only two false returns immediately follow a null result from that query.  A successful acquisition then rebuilds a 20-entry forward chain using `SpatialTreeNearestNeighborSearch`.

2. **The waypoint routine computes forward geometry.** After a successful acquisition, raw `sub_426430` derives vehicle speed from the three velocity components, chooses a look-ahead index by speed tier, and calculates three projected lateral values from vehicle position, heading, and the selected track record.  These values are clamped against bounds collected from the five nearby chain records.  The exact gameplay names of every calculated field remain unproven; the geometry and chain construction do not.

3. **Racing-line planner builds a 20-step speed profile.** Raw `AIRacingLine` starts from the spatially selected record, follows its linked records, and fills the 20-float array beginning at `+0x43A4`.  Each forward step calls `TireForce` and reduces the carried value using the record's fields and the AI state's coefficient at `+0x44CC`; the loop stops when the carried value reaches zero or meets the target condition.  This is a forward speed-profile computation, not proof of a physical pass.

4. **Planner intermediates reach confirmed vehicle controls.** `AIRacingLine` writes its two rate/limit intermediates at `+0x4434` and `+0x4438`.  At common exit, raw `AIMainUpdate` copies:

   ```c
   *(float *)(this + 13692) = *(float *)(this + 17460); // 0x357C <- 0x4434
   *(float *)(this + 13700) = *(float *)(this + 17464); // 0x3584 <- 0x4438
   *(float *)(this + 13696) = *(float *)(this + 17452); // 0x3580 <- 0x442C
   ```

   Canonical evidence confirms `+0x357C` is `ThrottleFactor` and `+0x3584` is `BrakeFactor`.  `+0x3580` has no confirmed semantic name, so it is recorded only as a third AI-written control field.

### Inferences

- The 20-entry linked-record sequence is the AI's racing-line/look-ahead planning horizon.  Its exact physical length depends on the record data, so it is not a fixed-distance horizon.
- Because `AIRacingLine` chooses values for the confirmed throttle/brake factors, it is the immediate planning source for longitudinal AI control.  This static trace does not yet establish the final vehicle-physics consumer of those fields.

### Open questions

- The precise data schema and provenance of the `dword_5EA2C0` spatial track records.
- Meaning of the third copied control (`+0x3580`) and its final consumer.
- Exact steering-output transformation downstream of the projected lateral values.

Commands used:

```text
python tools\f1c_mod.py inspect 00425920 --full
python tools\f1c_mod.py inspect 00426430 --full
python tools\f1c_mod.py evidence-query offset 0x357C
python tools\f1c_mod.py evidence-query offset 0x3580
python tools\f1c_mod.py evidence-query offset 0x3584
```

## 2026-08-18 — Decimal-offset raw search: consumers remain role-specific, not a general physics link

### Verified facts

The raw corpus search for decimal offsets found no additional direct read of `+0x357C` (`13692`) beyond `AIMainUpdate_00424E70` and the later encoder `SetupCarLightingAndRender_004C71C0`.  The raw `13696` and `13700` searches add two context-specific readers:

- `DriverInputController_00451720`, called from `MainGameTickUpdate_0042C690`, reads `dword_7C54E0 + 13696` and tests/scales `dword_7C54E0 + 13700` in several branches.
- `AISteering_004270A0` reads a selected other vehicle's `+13700` in one steering condition.

Neither raw excerpt establishes a general vehicle motion integrator: the former is tied to the particular global `dword_7C54E0` rather than an arbitrary AI vehicle, and the latter is an AI steering decision that uses another car's brake state.  `TireGripLateralForceCalculation_004E9300` contains `this + 13696`, but raw code uses it as a base for a later `+144` access in a contact-parameter calculation; it is not a direct read of the control scalar at `+0x3580`.

### Inferences

The raw search closes the simple-text version of this evidence gap: no recovered direct general physics read of the AI throttle field exists in the corpus search results, and the additional steering/brake hits do not supply one.  It remains possible that a pointer-arithmetic or indirect path is absent from the index/search representation.

### Open questions / next static step

Trace the full caller chain of the physics-side `PhysicsNodePropagationWithDistanceFalloff_00401C90` and compare its object identity with the AI vehicle pointer array.  This is stronger than treating same numerical offsets in unrelated `this` objects as a data-flow match.

### Commands run

```text
python tools\f1c_mod.py search "13692"
python tools\f1c_mod.py search "13696"
python tools\f1c_mod.py search "13700"
python tools\f1c_mod.py search "0x357C"
python tools\f1c_mod.py search "0x3580"
python tools\f1c_mod.py search "0x3584"
python tools\f1c_mod.py inspect 00451720
python tools\f1c_mod.py inspect 004270A0
python tools\f1c_mod.py inspect 004E9300
```

## 2026-08-18 — Physics scheduling and object-identity boundary

### Verified facts

`MainGameTickUpdate_0042C690` has two distinct schedules in raw code.  On `dword_7C5698 % 10 == 0`, it loops `dword_7C54F0[i]` and calls `AIMainUpdate` for every vehicle.  On other ticks, its direct `VehiclePhysicsModeDispatcher_004E4930` call is guarded by fields of `dword_7C54E8` (the player vehicle pointer): it requires `!*(PlayerVehiclePtr+13000)`, the additional replay/tire-model condition, and bit `8` at `PlayerVehiclePtr+18620`.  This direct call therefore cannot be used as a proven per-AI control-consumption path.

The same tick ends by calling `PerVehicleCameraUpdateIterator_004109D0`.  In its `dword_8AB6E4 != 2` path, it iterates a separate array at `this[2]` and calls `ModeDispatchedRenderPhysicsCall` on each element.  Mode 6 in that dispatcher calls `sub_4F0430`; separately, `SceneObjectLoaderStateMachine_0040F1C0` mode 6 obtains a sub-object from its own `this+32`, conditionally calls `VehiclePhysicsModeDispatcher`, then reads position from that sub-object.  The raw code does not establish that either list element or sub-object is identical to a particular `dword_7C54F0[i]` AI vehicle.

`PhysicsNodePropagationWithDistanceFalloff_00401C90` is called by `CollisionWrapperWithLock_004E4910` with `dword_5EA2C0`, not a `dword_7C54F0` vehicle pointer.  Its raw object has a count at `+0x130` and a node-data pointer at `+0x134`, and it traverses 316-byte contact nodes.  It is therefore a separate collision/contact object at this point in the evidence, despite the tire-force functions downstream.

### Inferences

The main tick establishes temporal proximity between AI update and later physics/scene work, but not object identity or a direct data read.  The apparently missing arguments at `VehiclePhysicsModeDispatcher` and `sub_4F0430` call sites are consistent with incomplete `__thiscall` recovery in Hex-Rays; they are not evidence that a hidden target is the current AI vehicle.

### Open questions / next static step

Recover a raw, explicit bridge between `dword_7C54F0` vehicle objects and the scene/collision list objects (or establish that they are distinct) by tracing construction/writes of the list at `PerVehicleCameraUpdateIterator.this[2]` and the `SceneObjectLoaderStateMachine.this+32` sub-object.  Do not use names or matching offsets as a substitute.

### Commands run

```text
python tools\f1c_mod.py inspect 00401C90
python tools\f1c_mod.py inspect 004E4910
python tools\f1c_mod.py inspect 004E4930
python tools\f1c_mod.py inspect 0040F300
python tools\f1c_mod.py inspect 0042C690
python tools\f1c_mod.py inspect 00441650
python tools\f1c_mod.py inspect 004109D0
python tools\f1c_mod.py inspect 0040F1C0
python tools\f1c_mod.py evidence-query func 00401C90
python tools\f1c_mod.py evidence-query func 004109D0
```

## 2026-08-18 — Proven vehicle-to-scene identity mapping, with a strict limit

### Verified facts

`VehgenScnFileLoader_004C6C40` receives a vehicle object as `this`, calls `VehicleGraphicsSceneLoader`, and later calls `ShortComputation_0B20(dword_5EA560, this + 12)`.  Within the graphics loader, the raw call `StatusFieldCopy(dword_5EA560, v54[4645], 1)` supplies the vehicle value at byte offset `18580` (`0x4894`) as its index argument.

Raw `StatusFieldCopy_00411570` makes that index concrete: it forms `v3 = &unk_5ECDC8 + 18624 * a2`, then copies selected records from that per-index source into targets owned by the `dword_5EA560` manager.  On reset, `VehicleResetClear_004E09E0` calls the same function with `*(*this + 18580)` and mode zero.  Thus a vehicle's `+0x4894` provides an explicit static key into a fixed-stride scene/status representation associated with the global manager.

`ArrayOfStructLinearSearchByID_00410B80` is a separate manager lookup: it searches `this[17]+208` with a 792-byte stride and returns a parallel 36-byte result entry.  Collision code uses this lookup, but raw evidence here does not establish that its searched ID is the same `vehicle+0x4894` key in every call.

### Inferences

There is now a confirmed vehicle-to-scene/status identity bridge.  It supports treating `+0x4894` as an identity/index field in the established interaction analysis, but it does not identify `dword_5EA560`'s scene/status records as the contact-node object, the final motion-physics object, or a direct control-field consumer.

### Open questions / next static step

Trace `ShortComputation_0B20_00410B20` and the manager routines that build the iterator list to determine whether the list contains these per-vehicle scene records and whether one carries a pointer back to the original vehicle.  Keep the physics/control link open until a raw same-object read is present.

### Commands run

```text
python tools\f1c_mod.py evidence-query global 0x5EA560
python tools\f1c_mod.py search "dword_5EA560"
python tools\f1c_mod.py search "StatusFieldCopy"
python tools\f1c_mod.py search "ArrayOfStructLinearSearchByID"
python tools\f1c_mod.py inspect 00411570
python tools\f1c_mod.py inspect 00410B80
python tools\f1c_mod.py inspect 004C6C40
python tools\f1c_mod.py inspect 004DFCE0
python tools\f1c_mod.py inspect 004E09E0
python tools\f1c_mod.py inspect 004EA970
```

## 2026-08-18 — Per-vehicle iterator bridge recovered

### Verified facts

`sub_40FE50`, the constructor for `dword_5EA560`, allocates 104 records of 36 bytes at manager `this[4]`, then initializes each record with `ShortComputation_e860(record, index, vehicleBase)`.  Raw `ShortComputation_e860_0040E860` stores that index at record `+0x8`, sets record `+0x1C` to mode `6`, and stores the supplied pointer at record `+0x20`.  During construction the supplied pointer starts at `unk_5EC6E4` and advances by 18624 bytes per record; this is the vehicle-array base at `VEH[0]+0xC`.

When `VehgenScnFileLoader_004C6C40` sets up a vehicle, `ShortComputation_0B20(dword_5EA560, vehicle+12)` selects `manager[4] + 36 * *(vehicle+16)` and passes that record to `LinkedListNodeInsert_0AD0`.  The insertion routine stores the record into `manager[2] + 4*manager[0]` and increments `manager[0]`.  These are exactly the `this[2]` pointer list and `this[0]` count consumed by `PerVehicleCameraUpdateIterator_004109D0`.

Thus the post-tick iterator's list consists of per-vehicle records whose `+0x20` field points to the associated `VEH[index]+0xC` object.  `ModeDispatchedRenderPhysicsCall_0040F300` selects case `record+0x1C == 6` and explicitly calls `WheelContactTransform(record[8])`, where `record[8]` is that stored vehicle-plus-12 pointer.

### Inferences

This is a proven bridge from the AI vehicle-array population to the post-tick scene/physics list.  It makes the temporal relation between AI updates and later per-vehicle wheel/contact work concrete.  `ModeDispatchedRenderPhysicsCall` also calls `sub_4F0430` in mode 6, but the recovered call lacks a visible receiver argument; raw Hex-Rays therefore does not yet prove whether that callee receives the record or the vehicle object.  The explicit `WheelContactTransform(record[8])` must not be generalized into a proof that direct AI control fields are consumed by the final motion integrator.

### Open questions / next static step

Use an instruction-level representation or a source variant that preserves the register setup at the mode-6 `sub_4F0430` call.  If unavailable, trace `WheelContactTransform_004EF180` with the explicit vehicle-plus-12 argument and inspect whether it or immediate callees read `+0x357C/+0x3580/+0x3584` relative to the containing vehicle.

### Commands run

```text
python tools\f1c_mod.py inspect 00410B20
python tools\f1c_mod.py inspect 00410AD0
python tools\f1c_mod.py inspect 0040E860
python tools\f1c_mod.py inspect 0040F0D0
python tools\f1c_mod.py inspect 0040FE50
python tools\f1c_mod.py evidence-query func 00410B20
python tools\f1c_mod.py evidence-query func 00410AD0
```

## 2026-08-18 — Explicit wheel-contact path does not consume AI control scalars

### Verified facts

The explicit post-tick call `WheelContactTransform(record[8])` reaches `WheelContactTransform_004EF180` with the associated `VEH[index]+0xC` object.  Its raw body reads transform/contact fields beginning at byte offsets `0x704` through `0x724`, iterates four wheel entries, queries `CollisionNormalFromFeature`, and conditionally calls `WheelSurfaceContactFriction`.  It has no raw reference to vehicle-relative offsets `13692`, `13696`, or `13700` (`0x357C`, `0x3580`, `0x3584`).

The alternate `dword_8AB6E4 == 2` branch in `PerVehicleCameraUpdateIterator_004109D0` likewise calls `WheelContactTransform(dword_7C54F0[i] + 12)` for every vehicle, with the nearby `sub_4F0430(a2)` still lacking a recovered receiver.  The explicit contact call is therefore a geometry/friction update, not the missing direct consumer of AI throttle, steering, or brake fields.

### Open questions / next static step

The best remaining static route is the hidden-receiver `sub_4F0430` call, or its callers in a representation that preserves ECX.  If that is not available in the canonical corpus, record a hard static boundary: the AI-to-vehicle-field and vehicle-to-contact-update paths are both proven, but their direct control-scalar connection is not.

### Commands run

```text
python tools\f1c_mod.py inspect 004EF180
python tools\f1c_mod.py evidence-query func 004EF180
python tools\f1c_mod.py search "WheelContactTransform"
```

## 2026-08-18 — Pairwise lateral-force output reaches physics

### Verified facts

`AILateralForceComputation_0042CAA0` runs from `MainGameTickUpdate_0042C690` every 50 ticks.  Raw code iterates `dword_7C54F0` twice: the first pass derives per-vehicle geometric values from fields around `+0x34E0..+0x3500`; the second compares every vehicle against the other entries, accumulating two values from angular and distance tests.  For each current vehicle it writes:

- accumulated first component to `vehicle + 14948` (`+0x3A64`),
- literal zero to `vehicle + 14952` (`+0x3A68`), and
- accumulated second component to `vehicle + 14956` (`+0x3A6C`).

This is a separate all-vehicle pairwise interaction computation.  Its raw code neither reads nor writes `+0x45FC`, so it is not the transient overtake/proximity-pointer mechanism.

Raw `DamperSpringForceComputationWithAntiRoll_004432F0`, called by `PhysicsIntegrationStep_00441D60`, explicitly reads a three-float vector from `*(_DWORD *)(this + 7936) + 14948/+14952/+14956` (`0x1F00` pointer plus `0x3A64/+0x3A68/+0x3A6C`).  It passes that vector into `Mat3x3MulVec` before the subsequent suspension/contact force calculations and angular-momentum accumulation.  This proves a physical consumer exists for the exact three field offsets the pairwise routine writes.  `SuspensionAndWheelPhysics_004E5F60` also writes `this+14948` in a different path, so write ownership and ordering must remain explicit: the pairwise writer is proven, but it is not the sole writer to the field.

### Inferences

The strongest supported interpretation is a periodic lateral interaction vector that enters the suspension/rigid-body force pipeline.  It is more direct physical evidence than the control-packet path, but it does not show that `+0x45FC` selects the pair being pushed, nor that the vector is an overtaking force.  The raw pairwise routine uses all vehicles and its own geometric tests.

### Open questions / next static step

Trace construction of the physics object's `+0x1F00` pointer to prove its exact relationship to a `dword_7C54F0` vehicle, then trace the two writers' order around each simulation step to determine whether the periodic pairwise vector is preserved, accumulated, or overwritten before consumption.

### Commands run

```text
python tools\f1c_mod.py inspect 0042CAA0
python tools\f1c_mod.py inspect 004432F0
python tools\f1c_mod.py inspect 004E58D0
python tools\f1c_mod.py inspect 004E5F60
python tools\f1c_mod.py inspect 004E45B0
python tools\f1c_mod.py inspect 004ED810
python tools\f1c_mod.py inspect 004F1C40
python tools\f1c_mod.py evidence-query offset 0x3A64
python tools\f1c_mod.py search "14948"
python tools\f1c_mod.py search "0x3A64"
```

## System-map expansion: traffic events versus race order

### Verified facts

1. **Race order is an independent sorter.** Raw `AIDriverSorting` (`sub_4BF390`) scans `VehiclePtrArray` by position slot and compares the focal vehicle with the occupant of each slot.  It accesses only the confirmed `+0x403C` lap number, `+0x4060` position, `+0x4098` finish-line time scalar, and `+0x409C` best lap among the relevant vehicle fields.  It neither reads nor writes `+0x45FC`.

2. **Race comparator.** In session type `7`, it refrains from a swap when the compared vehicle has more laps, or has equal laps and a finish-line time scalar no greater than the focal vehicle's.  Conversely, the focal vehicle can move ahead only when it has more laps, or equal laps with the better (smaller) scalar.  The scalar is confirmed as `totalTimeOnFinishLine` by the existing SDK evidence; this code establishes only its comparator polarity.

3. **Non-race comparator.** Outside session type `7`, it refrains from a swap when the focal vehicle's `+0x409C` best-lap value is greater-or-equal to the other vehicle's non-negative value.  The complementary branch performs a reordering.  This is a best-lap-based classification path, separate from traffic steering.

4. **Position changes are transition-aware.** The sorter calls `ConditionalFieldSetter(a1 + 0x4034, newPosition)`.  Raw `ConditionalFieldSetter` compares field `+0x2C` of that subobject—therefore vehicle `+0x4060`—then invokes `AIDriverStateTransition` before storing a changed value.  A race-order change is therefore a separate state-transition event, not an inference from a steering pointer.

### Consequence

`+0x45FC` is a same-tick traffic/steering latch; race position is a separate sorting outcome based on accumulated lap/time or best-lap data.  Neither static direction proves the other: a transient pointer does not prove a pass, and a sorter update does not identify which traffic maneuver caused it.

### Open questions

- The update cadence and callers' conditions for `AIDriverSorting` in actual race progression.
- The exact event consumers of `AIDriverStateTransition`.
- The dynamic physical condition that changes lap/time records before sorting.  Resolving that requires further static call-chain work; no live-game access is authorized for this goal.

Commands used:

```text
python tools\f1c_mod.py inspect 004bf390 --full
python tools\f1c_mod.py inspect 004bc2f0 --full
```

## System-map expansion: ability/pace adjustment and pit strategy

### Verified facts

1. **Ability check is time-gated.** Raw `AIMainUpdate` calls `AIAbility(this)` only when current session time exceeds `+0x4404`; immediately before the call it writes `current session time + 4.0` back to that field.  Therefore this ability/strategy work is scheduled at roughly four-session-second intervals on the active main-AI path, not every frame.

2. **Difficulty scaler drives two strategy fields.** In raw `AIAbility`, `RingBufferAccessWithWrap(this[4113])` selects whether `AIDifficultyScalar()` or `AIDifficultyScalar() * 0.75` is written to `this[4447]` (`+0x457C`).  In the race branch the function also adjusts `this[4431]` (`+0x453C`) by bounded `+/-0.01` steps and can make a random-gated alternative adjustment.  The exact gameplay names/consumers of these fields are not established here; the scaling and bounded adjustment are.

3. **Pit decisions are an explicit strategy subsystem.** `AIAbility` calls `PitStopDecisionTireCompound`, `PostPitCleanup`, `ForcePitExit`, and finally `RacePhasePitEntryTrigger` on its applicable paths.  One post-pit cleanup path clears AI state, sets `+0x4510` to `4` in race or `5` otherwise, reacquires waypoint state through `sub_426430`, and schedules a later timer.  This establishes a strategy-to-waypoint-reset link without assuming exact pit semantics for every field.

4. **Teammate-aware fuel/exit path.** At the end of `AIAbility`, a non-null `+0x45F8` is used only in race when the writer's `FuelMultiplierValue` is below `2`; it reads the paired vehicle's value and, under `0 < value < 3` plus two `FuelWeightLimitCheck` passes, calls `ForcePitExit(this)`.  As previously recovered, `+0x45F8` is a teammate pointer constructed from equal `+0x46B8` team-name text.  This is a strategy relationship, distinct from transient `+0x45FC` traffic steering.

### Inferences

- `+0x453C` is a periodically adjusted AI pace/ability parameter, not an immediate throttle value: its updates are bounded, difficulty-based, and occur within the time-gated ability routine.
- The teammate fuel condition coordinates pit-exit timing.  “Coordinates” is supported by the shared data and `ForcePitExit` call; cooperative intent beyond that is not directly encoded.

### Open questions

- What ring-buffer state `this[4113]` represents and how it is produced.
- Consumers and visible gameplay effect of `+0x453C` and `+0x457C`.
- Full call chains for `RacePhasePitEntryTrigger`, tyre-compound choice, and `ForcePitExit`.

Command used: `python tools\f1c_mod.py inspect 00429470 --full`.

### Follow-through: exact `ForcePitExit` gate

Raw `ForcePitExit` (`sub_42A110`) provides the action boundary for the strategy paths:

```c
if (SessionType == 7) {
  if (lapNumber != TotalRaceLaps - 1) {
    value = TeammatePartValueLookup(this + 3251);
    if (!value || value == 4 || FinishState == 1) {
      StateConditionalAction(this + 3251);
      AIStateFlagSetter(1);
    }
  }
} else {
  StateConditionalAction(this + 3251);
  AIStateFlagSetter(1);
}
```

So the call does not directly move a vehicle in the inspected code.  It advances a separate state/action path.  In race it is blocked on the final lap and otherwise gated by `TeammatePartValueLookup`; outside race it takes the action unconditionally.  The contents and eventual consumer of the `this + 3251` state block remain open.

Command used: `python tools\f1c_mod.py inspect 0042a110 --full`.

## Race-order producer audit: what is proved and what is not

### Verified facts

1. **Lap completion is event-driven timing/session logic.** Raw `LapCompletion` (`sub_4BC4E0`) receives a timing value and a sector/lap selector, records positive timing values, tracks a best value, advances its own lap/checkpoint counter, handles session-specific finish/penalty branches, and invokes `PitStopOrderRank`, `RaceFinishHandler`, and other timing/session helpers.  It operates on its own timing/session structure, whose first member points at a vehicle; it is not a direct write proof for vehicle `+0x403C` or `+0x4098`.

2. **A packet/event dispatcher reaches it.** Raw `sub_4B3400` decodes a packed event header.  Its major-type-4, subtype-8 route calls `LapCompletion` for a selected vehicle when the vehicle's `+0x32C8` state is `2` or `3`.  The same dispatcher routes a different event type to `AIStateMachineWithModeDispatch`.  This locates lap completion and pit-mode input in an event-dispatch layer distinct from the ordinary AI tick.

3. **Position transition has an optional driver-table side effect.** After a `ConditionalFieldSetter` position change, raw `AIDriverStateTransition` is gated by active-race/track conditions, non-final race phase, and a true old/new difference.  In session type 7 it may look up and insert a driver-table entry, with player-versus-nonplayer and ordering/time/random gates.  This is a reaction to a position change; it does not itself determine race order or prove an on-track maneuver.

4. **Direct field writers are absent from the available static index.** Canonical `evidence-query` lists no writers for vehicle `+0x403C` (`lapNumber`) or `+0x4098` (`totalTimeOnFinishLine`), while confirming both as sorter inputs.  This is positive evidence of an unresolved source/alias/indirect-write boundary—not evidence that the values are constant or that `LapCompletion` writes them directly.

### Open questions

- The exact bridge from lap-completion timing/session data to vehicle `+0x403C` and `+0x4098`.
- Whether those fields are written through an alias, an unindexed helper, or another omitted/indirect path.
- Which inserted driver-table entry types are user-visible commentary versus internal behavior.

Commands used:

```text
python tools\f1c_mod.py inspect 004bc4e0 --full
python tools\f1c_mod.py inspect 00419120 --full
python tools\f1c_mod.py inspect 004b3400 --full
python tools\f1c_mod.py evidence-query offset 0x403C
python tools\f1c_mod.py evidence-query offset 0x4098
python tools\f1c_mod.py evidence-query offset 0x4060
```

## Control-output follow-through: packet encoding boundary

Raw `sub_4C71C0` consumes the three values that `AIMainUpdate` writes:

```c
BitfieldInsert(v4, *(float *)(this + 13692));        // +0x357C, ThrottleFactor
FloatToBitfieldEncoder(v4, *(float *)(this + 13696)); // +0x3580, unnamed third control
if (*(float *)(this + 13700) <= 0.0099999998)
  v4[12] &= 0xFBFFFFFF;
else
  v4[12] |= 0x4000000;                                // +0x3584, BrakeFactor
```

This proves the immediate downstream representation: throttle and the unnamed third control are value-encoded into the packet, while brake is quantized to bit `0x04000000` by a `> 0.01` threshold.  It also explains why a brake *factor* can have a discrete representation in this path.

`VehiclePhysicsTimeStep` reads the same packet bit and writes its own `+0x3584` to `1.0` or `0.0`.  That pairing proves an encode/decode channel, but static code inspected so far does **not** prove whether the packet is the authoritative local physics input, a replay/network representation, or both.  The report therefore records an output/serialization boundary, not a completed physics-actuation proof.

Command used: `python tools\f1c_mod.py inspect 004c71c0 --full`.

### Serialization scheduling clarification

Raw `sub_4C77D0` invokes `sub_4C71C0` for each eligible vehicle and supplies either the current `dword_8AAE64` buffer pointer or a fallback when ring count reaches `1023`; otherwise it increments the count and advances the pointer by `432` bytes.  This statically establishes a bounded, fixed-stride output ring-buffer path for the encoded control/state packet.

It does not identify a network transport, renderer, or replay consumer by itself.  The correct current conclusion is: AI control values reach an output ring buffer; the final authoritative physics/control-consumer question remains open.

Command used: `python tools\f1c_mod.py inspect 004c77d0 --full`.

## 2026-08-18 — Superseding correction: race-order input producer and shared staging buffer

### Verified facts

Raw Hex-Rays for `AITickUpdate_004BF4F0` directly supplies the values that the race sorter reads.  For each `dword_7C54F0[v2]` vehicle (`v5`), it first reads `*(v5 + 16484)` (`0x4064`) and skips the update when that value is `2` or `3`.  When the per-slot float at `v4 + 4*v2 + 8148208` is positive, it computes a difference against the parallel value at `... + 8148624`, then:

- increments `*(_DWORD *)(v5 + 16444)` (`0x403C`), the same lap field read by `AIDriverSorting_004BF390`;
- writes the non-negative `v7 + this[213]` to `*(float *)(v5 + 16536)` (`0x4098`), the same time field read by that sorter;
- writes `this[213] - flt_8ACF90 + v7` to `v5 + 16568` (`0x40B8`);
- changes `v5+0x4064` to `1` unless it is `3`; and
- calls `AIDriverSorting(v5)` immediately afterward.

Consequently, the evidence-backed race-order chain is `AITickUpdate_004BF4F0` → direct `+0x403C/+0x4098` update → `AIDriverSorting_004BF390` → `ConditionalFieldSetter_004BC2F0` → guarded `AIDriverStateTransition_00419120` notification.  It proves an order-update path, not a physical pass, overtake, defender, or attacker role.

This supersedes the earlier statement that no writer for those fields had been found.  That statement was a limitation of the static index: it did not attribute the pointer-arithmetic stores in the raw function.  The raw function is controlling evidence.  The semantics and ownership of `this[213]` and the two per-slot source arrays remain unresolved.

`dword_8AAE64`/`dword_83EE60` must also not be described as a vehicle-only AI output ring.  `AITickUpdate_004BF4F0` resets the write pointer to `unk_83EE64` and the count to zero.  Independent raw writers include camera shake, state-change notification, pit-stop timing, audio, penalties, lap-split events, and vehicle packet code; entries are bounded by count `< 1023` and advance the pointer by 432 bytes.  Therefore it is a shared fixed-stride staging buffer.  The AI control encoder serializes its values into one entry, but that alone does not establish the packet's consumer or physical authority.

`GamePostMainLoop_0042D8A0` calls `MainGameTickUpdate`, `IterateVehicles(&dword_83EE60)`, `SessionScoringUpdate`, `TwoPathDispatch`, and then `BufferReset(&dword_83EE60)`.  In `TwoPathDispatch_004BA6C0`, its type-1 path calls `CallWrapper_9870(this + 2, &dword_83EE60, &unk_5EC6D8, sessionTime)` when `byte_7C56AC` is zero.  This proves a dispatch call observes the counter before reset; it does not yet prove exactly how that wrapper consumes or applies an AI control entry.

### Inferences

The direct call from the producer to the sorter makes a timing/progress-triggered order refresh much stronger than the former indirect evidence.  It still cannot turn a `+0x45FC` selection into proof of an overtake: the fields can be refreshed because a positive internal timing term occurred, and the pointer is independently cleared during the normal AI update.

### Open questions / next static step

Inspect raw `CallWrapper_9870_004B9870` and its immediate callees to determine whether the shared staging buffer is iterated, copied, or transmitted, and whether any entry type reaches vehicle control application.  Keep the packet/application boundary unresolved unless raw control flow proves it.

### Commands run

```text
python tools\f1c_mod.py inspect 004BF4F0
python tools\f1c_mod.py inspect 004BA6C0
python tools\f1c_mod.py search dword_83EE60
python tools\f1c_mod.py evidence-query global 0x8AAE64
```

## 2026-08-18 — Shared-buffer consumer narrowed

### Verified facts

The immediate `CallWrapper_9870_004B9870` body is only `return PitTimingUpdate(*this, a2, a3, a4)`.  In raw `PitTimingUpdate_004B7A90`, when `*a2 > 0`, it calls `SessionDataCopy(a2)` and repeatedly calls `AdvanceRingBuffer(a2, v15)`.  `AdvanceRingBuffer_004B3AF0` copies one 432-byte entry into `v15`, advances its read pointer by 432, and stops after wrapping at the end pointer.  `PitTimingUpdate` dispatches only selected header classes (`v15[0] >> 29`): classes 2, 3, 4, and 6, plus most class-1 subcodes, reach `PitStallProximityCheck`; other classes do not in this function.

`IterateVehicles_004B3BA0`, called after `MainGameTickUpdate_0042C690` by `GamePostMainLoop_0042D8A0`, loops over the vehicle array and calls `TireTemperatureSimStep_004C77D0`.  On its non-return path, that function reserves one shared 432-byte entry and calls `SetupCarLightingAndRender_004C71C0` with the vehicle and entry pointer.  The encoder begins with `ProgressBarEventEncode(a2, 1, 0, 52, vehicle+18580, sessionTime, 0)` and then reads vehicle `+0x357C`, `+0x3580`, and `+0x3584` while packing the entry.  It therefore occurs after the AI update in the main-loop order and serializes current vehicle fields; it is not an AI-output consumer that applies those fields to the vehicle.

### Inferences

The staging buffer has at least one real reader, but this reader is pit/session-event handling, not evidence that an AI control packet actuates physics.  The strongest proven data direction is still AI state → vehicle `+0x357C/+0x3580/+0x3584` fields → later serialized entry.  Whether, and where, those fields are used by the motion/physics update requires a separate raw consumer trace.

### Open questions / next static step

Trace raw readers of vehicle offsets `+0x357C`, `+0x3580`, and `+0x3584`, starting with `VehiclePhysicsTimeStep_004C73F0`.  Distinguish direct vehicle-field reads from packet decodes and preserve the boundary if no direct physics read is recoverable.

### Commands run

```text
python tools\f1c_mod.py inspect 004B9870
python tools\f1c_mod.py inspect 004B7A90
python tools\f1c_mod.py inspect 004B3BA0
python tools\f1c_mod.py inspect 004C77D0
python tools\f1c_mod.py inspect 004C71C0
python tools\f1c_mod.py inspect 004B3B30
python tools\f1c_mod.py inspect 004B3AF0
```

## 2026-08-18 — Vehicle-field consumer boundary

### Verified facts

Raw `VehiclePhysicsTimeStep_004C73F0` takes a separate input buffer (`a2`) and decodes packed values from `a2+8` and `a2+52/+56`.  It writes `this+0x3580` in its mode-2 branch and writes `this+0x3584` to `1.0` or `0.0` from bit `0x04000000` of `a2+56`.  It does **not** directly read `this+0x357C`, `this+0x3580`, or `this+0x3584` as inputs to motion physics in the recovered raw code.

The canonical offset index lists direct readers of `+0x357C` only in `AIMainUpdate_00424E70` and `SetupCarLightingAndRender_004C71C0`; the latter serializes it.  For `+0x3580` and `+0x3584`, the index additionally lists `VehiclePhysicsTimeStep`, but raw code establishes those as packet-derived writes, not reads of the pre-existing vehicle fields.  This is consistent with two data directions in the same structure: AI writes current control values, whereas a packet/replay/network-like decode path can overwrite steering/brake-related fields from an external packed input.

### Inferences

The recovered corpus proves AI computation reaches named vehicle control fields and that those fields are serialized later in the main loop.  It does not yet prove the final motion-physics consumer of the direct AI-written values.  Neither `VehiclePhysicsTimeStep` nor the pit-timing buffer consumer closes that gap.  The absence of an indexed direct reader is not evidence that no reader exists, because the earlier race-order writer was also missed by pointer-arithmetic indexing.

### Open questions / next static step

Follow callers and raw callees of `AIMainUpdate_00424E70`'s same-frame vehicle-processing path, and search raw code for pointer arithmetic using decimal offsets `13692`, `13696`, and `13700` as well as hexadecimal `0x357C`, `0x3580`, `0x3584`.  Identify a direct motion integrator only if its raw code reads the AI-written field from the same vehicle object.

### Commands run

```text
python tools\f1c_mod.py inspect 004C73F0
python tools\f1c_mod.py evidence-query offset 0x357C
python tools\f1c_mod.py evidence-query offset 0x3580
python tools\f1c_mod.py evidence-query offset 0x3584
```

## 2026-08-18 — correction: pairwise lateral vector is on the physics vehicle context

### Verified facts

- `AILateralForceComputation_0042CAA0` writes the three float components at vehicle `+0x3A64`, `+0x3A68`, and `+0x3A6C` (`14948`, `14952`, `14956`) after its pairwise vehicle-geometry work.
- `TireModelInit_0043E050(this, a2)` stores `a2` at physics-object `this+0x1F00`.  It immediately uses `a2+0x4898` (`18584`) and `a2+0x4794` (`18324`) as vehicle-context fields.
- `LargeConfigFunctionWithPhysicsConstants_004E45B0` calls it as `TireModelInit(&dbl_7C7428, *(_DWORD *)this)`: the passed context is therefore the pointer later retained at `physics+0x1F00`.
- In `DamperSpringForceComputationWithAntiRoll_004432F0`, called by `PhysicsIntegrationStep_00441D60`, the code reads exactly `*(physics+0x1F00)+0x3A64/+0x3A68/+0x3A6C` and passes the resulting vector through `Mat3x3MulVec` before the physics integration continues.
- `VehiclePhysicsIntegrationStep_00441650` calls `PhysicsIntegrationStep` twice within its substep loop.  The force-vector consumer is therefore in the documented vehicle physics path, not a UI or packet-only path.

### Inference

The `+0x3A64` triple is an AI-produced, pairwise traffic vector that enters the vehicle physics calculation.  It is separate from the transient `+0x45FC` interaction pointer and is not evidence that a selected pointer target has been passed.

### Open question

`SuspensionAndWheelPhysics_004E5F60` also writes `+0x3A64`; static evidence gathered so far does not prove frame ordering or whether that writer replaces, combines with, or merely initializes the AI vector.  Do not claim a final vehicle-motion effect until that ordering is recovered.

### Correction to the open question

The apparent `SuspensionAndWheelPhysics_004E5F60` `this+0x3A64` write is **not yet proven to use the same vehicle receiver**.  Its recovered caller is `LargeConfigFunctionWithPhysicsConstants_004E45B0`, which calls it with local `v16`/`v8` buffers; Hex-Rays argument recovery is insufficient to establish the hidden receiver.  The only confirmed writer/reader chain for the vehicle field is `AILateralForceComputation_0042CAA0` to `DamperSpringForceComputationWithAntiRoll_004432F0`.  Ordering/persistence of any second writer remains unresolved.

### Superseding correction — second writer is a local work buffer

Raw `LargeConfigFunctionWithPhysicsConstants_004E45B0` calls `SuspensionAndWheelPhysics(v16, v8)` after creating `v16` and `v8` as local stack work buffers.  `SuspensionAndWheelPhysics_004E5F60` receives that first argument as its recovered `this` and writes `this+14948` there.  This is not the retained vehicle pointer used by `TireModelInit`/`DamperSpringForceComputationWithAntiRoll`.

Therefore the same numeric offset in `SuspensionAndWheelPhysics` is an incidental local-work-buffer member, not a competing proven write to vehicle `+0x3A64`.  The confirmed vehicle chain is now unambiguous: `AILateralForceComputation` writes the vehicle triple; `DamperSpringForceComputationWithAntiRoll` reads it through `physics+0x1F00` during integration.  No second vehicle-field writer was recovered in this check.

### Exact integration use

At the start of `DamperSpringForceComputationWithAntiRoll_004432F0`, the code loads vehicle `+0x3A64/+0x3A68/+0x3A6C`, transforms that triple with `Mat3x3MulVec`, subtracts the transformed result from another chassis vector, feeds the difference to `QuadraticForm6x6`, transforms the result again, and calls `AccumulateAngularMomentum`.  `PhysicsIntegrationStep_00441D60` calls this routine before rigid-body constraint solving and then adds its accumulated linear/angular deltas to the chassis body state.

The narrow, evidence-grade conclusion is therefore: the periodic AI pairwise vector affects the rigid-body force/torque calculation.  Axis meaning and player-visible motion direction remain unassigned; they are not needed to prove physical participation.

## 2026-08-18 — AI control outputs: present, but physical consumer not yet statically proven

### Verified facts

- `AIMainUpdate_00424E70` copies AI working values at `+0x442C/+0x4434/+0x4438` into vehicle `+0x3580/+0x357C/+0x3584` (`13696/13692/13700`).  Its inactive fallback writes `0/0/1` respectively.
- The only raw-code reader found for `+0x357C` is `SetupCarLightingAndRender_004C71C0`, which packs it into a shared serialized entry.  This is not physical actuation.
- `VehiclePhysicsTimeStep_004C73F0` writes `+0x3580` and `+0x3584` from its separate packed input argument; it does not read the pre-existing AI values as its source.
- `DriverInputController_00451720` reads `dword_7C54E0+0x3580/+0x3584`, but it is a singleton controller with a player-vehicle global path and does not establish an all-AI physical consumer.

### Verdict

The AI has proven steering/throttle/brake output fields, but the static corpus currently proves neither the exact per-AI control-to-drivetrain consumer nor that the packet/input paths consume those values for AI vehicles.  Keep this as an explicit coverage gap; do not substitute the player/global controller or packed-input decoder as proof.

### Correction: what the three AI outputs prove

- `sub_426100` computes `+0x442C` from the signed angle between the vehicle heading (`+0x448C/+0x4494`) and a target point.  It rate-limits the result by `0.1` per update and clamps it to `[-1, 1]`.  This is solid evidence for a signed steering target.
- In the normal AI path, `AIMainUpdate` calls `OpponentProximityScanTeamRecognition`, `AIRacingLine`, `AISteering`, `sub_426100`, and `AISteeringCorrection`, then copies `+0x442C/+0x4434/+0x4438` to `+0x3580/+0x357C/+0x3584`.
- `AIRacingLine` and `AISteeringCorrection` update `+0x4434` and `+0x4438` from track-distance, grip, and speed-dependent conditions.  They are bounded longitudinal/control-like scalars, but raw code here does not prove the labels “throttle” and “brake” at the final physical actuator.

Use “signed steering target plus two longitudinal control scalars” in evidence-grade documentation until their per-AI physics consumer is recovered.

### Output-staging boundary, strengthened

`TireTemperatureSimStep_004C77D0` allocates a 432-byte entry from the shared `dword_8AAE64/dword_83EE60` buffer and calls `SetupCarLightingAndRender_004C71C0` for each vehicle.  That function writes an event header through `ProgressBarEventEncode_004B33B0` and packs the three vehicle values into the entry.  `ProgressBarEventEncode` itself only writes the header/time fields; it is not a physics call.

The visible consumer path for those entries is `PitTimingUpdate_004B7A90`, which drains a ring and dispatches only selected event types to pit handling.  Separately, `sub_4F0430` case 3 obtains a packet through `sub_4B9AC0` before calling `VehiclePhysicsTimeStep`; `sub_4B9AC0` is an unrelated linked-list/audio-sample dispatcher and has no recovered edge from the shared staging buffer.  Static evidence therefore supports a serialization/event boundary, not a closed AI-control-to-physics path.

`MainGameTickUpdate_0042C690` reinforces that boundary: its direct call to `VehiclePhysicsModeDispatcher_004E4930` is guarded through the single `dword_7C54E8` vehicle pointer, whereas the AI loop iterates `dword_7C54F0`.  This direct dispatcher call cannot be used as proof that every AI vehicle's copied controls enter the physical integrator.

### Correction: separate per-registered-vehicle physics dispatch exists

The immediately preceding statement applies only to the *direct* `dword_7C54E8` call.  A separate route exists:

- `sub_40FE50` allocates 104 36-byte records; `sub_40E860` sets each record's `+0x1C` mode to `6` and `+0x20` to `unk_5EC6E4 + 0x48C0*index`.
- `VehgenScnFileLoader_004C6C40` registers each vehicle through `ShortComputation_0B20(dword_5EA560, vehicle+0xC)`.  That function selects the record using `*(vehicle+0x10)` and inserts it into the manager's active list.
- Every tenth simulation tick, `MainGameTickUpdate` calls `LoopWithConditionalSkipFunction` on that active list.  Its mode-6 handler, `SceneObjectLoaderStateMachine_0040F1C0`, checks the linked vehicle context and invokes `VehiclePhysicsModeDispatcher`, then copies its position fields.

This proves a per-registered-vehicle route into the physics dispatcher, alongside the single direct player/global call.  It still does **not** prove that `+0x3580/+0x357C/+0x3584` are read by that physics route: no raw direct read of those copied AI scalars in the vehicle integrator has yet been recovered.

## 2026-08-18 — secondary interaction field `+0x45F8`

### Verified facts

- `AIDriverStructInit_00424790` initializes `+0x45F8` to zero.
- The direct raw-code references found are in `AIDriverRandomSelector_0042AE20`: if its `a2` equals `this+0x45F8`, it clears that field.  The same function performs the analogous identity test/clear for `+0x45FC`.
- `Overtaking_0042AF70` reads `+0x45F8` but writes the newly selected candidate to `+0x45FC`.

### Boundary

No direct literal nonzero writer for `+0x45F8` has been recovered.  This is evidence that the field is unpopulated in the currently recovered direct paths, **not** proof that no aliased or un-recovered writer exists.  Its role and any branches gated by it remain open.

### Additional verified use

`AIAbility_00429470` gives `+0x45F8` a narrow, evidence-backed role: when it is nonzero, session type is race (`7`), and the local fuel multiplier is below `2`, it passes that pointed object to `FuelMultiplierValue` and `FuelWeightLimitCheck`.  If the pointed vehicle's multiplier is `1` or `2` and both fuel-limit checks are false, it calls `ForcePitExit(this)`.  Thus `+0x45F8` is a secondary linked-vehicle pointer participating in a race fuel/pit decision.  It is still not established as a live teammate link, overtaking target, or interaction writer because no nonzero producer has been recovered.

### Superseding correction — producer recovered

The preceding “no producer” boundary was wrong.  `AIDriverStructInit_00424790`, on its full-init (`LOBYTE(a2) != 0`) path, zeroes `this[4478]` (`+0x45F8`), then loops `dword_7C54F0[0..VehicleCount)` and compares the current vehicle's string at `*this+0x46B8` (`18104`) with each candidate's `candidate+0x46B8`.  For each equal string where `candidate != this`, it writes `candidate` to `this[4478]`.  It does not break, so the last matching vehicle-array entry wins.

This proves `+0x45F8` is an initialization-time same-string vehicle link used by the later race fuel/pit branch.  The string's semantic label is not needed for that conclusion; it is not evidence that `+0x45F8` is the transient overtaking target (that remains `+0x45FC`).

## 2026-08-18 — control-output consumer correction: wheel-block alias recovered, no scalar read proved

### Verified facts

- `sub_4E5AE0_004E5AE0`, reached from `PhysicsIntegrationStateMachine_004E4E60`, forms `v11 = (float *)(this + 13696)` and calls `sub_4E43D0(v11)` four times, advancing `v11` by 62 floats each time.  Thus `+0x3580` is also the base address of a four-element, 248-byte-stride physics sub-block in that recovered receiver layout.
- `sub_4E43D0` reads/writes relative indices `4, 9, 12, 13, 21, 22, 24, 27, 28`; it does **not** read index `0` or `1`.  Therefore the exact values at `+0x3580` and `+0x3584` copied by `AIMainUpdate` are not consumed by that shown wheel routine.
- `+0x357C` remains absent from the recovered force/integration readers; its raw reader found here is the serialization routine `SetupCarLightingAndRender_004C71C0`.
- `VehiclePhysicsTimeStep_004C73F0` can overwrite `+0x3580/+0x3584` from its separate packed input in mode 2.  That is a write, not an AI-output consumer.

### Superseding boundary

The earlier statement that no physics-side reference to `+0x3580` had been found was too broad.  A physics routine uses that address as a per-wheel-block base, but the recovered callee does not read the first two floats where the AI copy lands.  This strengthens—not closes—the gap: static code still lacks a recovered per-AI read of the three copied scalar values into a force/drivetrain calculation.  Do not call the overlapping layout an actuator path without such a read.

## 2026-08-18 — output packet lifecycle recovered

### Verified facts

- `GamePostMainLoop_0042D8A0` orders `MainGameTickUpdate` → `IterateVehicles_004B3BA0` → `TwoPathDispatch_004BA6C0` → `BufferReset(&dword_83EE60)` in one outer frame.
- `IterateVehicles` calls `TireTemperatureSimStep_004C77D0(dword_7C54F0[i])` for every registered vehicle.  The latter calls `SetupCarLightingAndRender_004C71C0` only when `vehicle+0x32C8 <= 1`, allocating a 432-byte entry from `dword_8AAE64/dword_83EE60`.
- The encoder reads all three copied AI destinations: it packs `+0x357C`, encodes `+0x3580`, and sets packet bit `0x4000000` from `+0x3584 > 0.01`.
- In the session branch, `TwoPathDispatch` calls `PitTimingUpdate_004B7A90` with the same `&dword_83EE60` queue.  `PitTimingUpdate` drains entries via `AdvanceRingBuffer` and sends selected header classes to `PitStallProximityCheck`; the outer loop then resets the queue.
- The shared 432-byte queue is generic: `ProgressBarEventEncode_004B33B0` has many non-AI callers (network, UI, collision, audio, penalties).  It must not be described as an AI-only or pit-only buffer.

### Boundary

This closes the static lifecycle of the encoded output packet through same-frame queue consumption/reset.  Its recovered consumer is event/pit proximity processing, not a vehicle force or drivetrain function.  The packet route is therefore evidence of serialized state publication, not proof that the AI scalar values physically actuate a vehicle.

### Eligibility alignment

`AIMainUpdate` returns when `vehicle+0x32C8 > 1`; `TireTemperatureSimStep` uses the same `> 1` exclusion before packet encoding.  Therefore the recovered packet-publication path covers the same `0/1` eligibility set as the AI tick.  The semantic names of values 0 and 1 remain unproven here, so do not label them player/AI modes from this comparison alone.

### Further wheel-block check

`TireGripLateralForceCalculation_004E9300` also selects `this+0x3580` as a base (unless its selector is `2`, when it uses `this+0x3770`), but its actual read is `base+144`.  Together with `sub_4E43D0`'s relative-index reads, this is additional direct raw evidence that recovered wheel/tire consumers access later members of the overlapping block—not the AI-written first two floats at `+0x3580/+0x3584`.

### Singleton-reader classification

`DriverInputController_00451720` is called once from `MainGameTickUpdate` with the singleton `&unk_7CBB10`, uses `dword_7C54E0` throughout, compares it with `dword_7C54E8` (the player vehicle), polls four controller sub-objects, and accumulates contact/audio-effect state.  Its reads of `dword_7C54E0+0x3580/+0x3584` are therefore player/global effect processing, not a per-vehicle AI actuator path.  It cannot close the missing scalar-control bridge.
## 2026-08-18 — race-order update path (layout resolved)

### Verified facts

- `AITickUpdate_004BF4F0` conditionally advances vehicle `+0x403C` and recalculates values at `+0x4098` and `+0x40B8` before calling `AIDriverSorting_004BF390`.
- In session `7`, `AIDriverSorting_004BF390` compares vehicle `+0x403C` and `+0x4098`; outside session `7`, it compares `+0x409C`. It contains no `+0x45FC` access.
- Candidate lookup uses vehicle `+0x4060`. The sorter updates it through `ConditionalFieldSetter_004BC2F0` with `this = vehicle + 0x4034`.
- `ConditionalFieldSetter_004BC2F0` compares and writes its nested `+0x2C` field, resolving to vehicle `+0x4060`, and invokes `AIDriverStateTransition_00419120` before storing a changed value.

### Boundary

This proves the rank/order field's update mechanism is a separate timing-driven path. It does not prove that a `+0x45FC` selection caused a position change.

### Recovered race-order caller

`EngineFailureCheck_004BEC55` directly invokes `AITickUpdate_004BF4F0` after its registered-vehicle loop (despite the incomplete direct-caller index). In that loop, a non-collision path increments `+0x403C`, updates `+0x4098/+0x409C/+0x40B8`, and calls `AIDriverSorting_004BF390` before the aggregate tick reaches `AITickUpdate`. The only static connection between interaction and ordering remains absent: neither function accesses `+0x45FC`.

### Transition-callback boundary

`AIDriverStateTransition_00419120` does not itself establish a scoreboard update. Its only recovered caller is the setter; it is gated by race-active/session state and, for session `7`, conditionally performs driver-table lookup/insertion before recording the new value in its own indexed state storage. The definitive rank write remains the setter's nested `+0x2C` store; the callback is an ancillary conditional transition path.

## 2026-08-18 — scalar-trio boundary tightened

### Verified facts

- `AIMainUpdate_00424E70` copies its signed steering target to vehicle `+0x3580`; `SetupCarLightingAndRender_004C71C0` encodes that field into the per-vehicle packet.
- The same encoder converts `+0x3584 > 0.01` into packet bit `0x4000000`; `VehiclePhysicsTimeStep_004C73F0` decodes that bit back to `+0x3584` as exactly `0.0` or `1.0`.
- `VehiclePhysicsTimeStep_004C73F0` also can overwrite `+0x3580` from the packet's signed input in its mode-`2` branch. This is a packet decode/write path, not an AI-to-force consumer.
- No recovered static reader consumes `+0x357C` beyond packet encoding. No recovered static reader consumes the AI-written `+0x3580/+0x3584` as a per-AI drivetrain or tire-force input.

### Conclusion

The trio is proven AI-produced vehicle state that is serialized, with `+0x3580` specifically a signed steering value in this path and `+0x3584` represented as a packet flag. The missing direct actuator bridge remains open; semantic names from external/UI metadata are not used as static proof.

## 2026-08-18 — longitudinal decision logic recovered

### Verified facts

`AIRacingLine_00425920` forms the two upstream scalars before `AIMainUpdate_00424E70` copies them to `+0x357C/+0x3584`:

- When its forward speed profile is depleted (`v46 <= 0.0`), it sets `+0x4438 = 0` and writes `+0x4434` from `BrakeThermalModel(this+12)` or fixed `0.4`, `0.5`, or `1.0`, with a bounded-rise path.
- When the profile remains positive, it writes `+0x4434 = 0` and `+0x4438 = TireGripCoefficient(this+12)`, bounded to no more than `0.2` above its entry value.
- The proximity branch makes the same polarity explicit: its non-positive condition writes `+0x4438 = 0` and `+0x4434 = BrakeThermalModel(this+12)`; otherwise it writes `+0x4434 = 0`, `+0x4438 = 1.0`.
- `sub_4258C0` establishes the default each update: `+0x4434 = 0`, `+0x4438 = 1.0`.

### Conclusion

Static code proves a mutually exclusive slow/stop-versus-drive decision pair, modulated by predicted path speed and tire-related helpers. It does not, by itself, prove the final physical actuator consuming the copied pair.

## 2026-08-18 — control-conditioning stage recovered

### Verified facts

- `AISteeringCorrection_00426CF0` reduces `+0x4434` when `abs(+0x442C) > 0.1` and speed `+0x4440 > 20.0`, then further conditions the pair from two wheel-related values, `SuspensionRatioClamp`, `BrakeThermalModel`, and `TireGripCoefficient`.
- Its later timing gate either zeros `+0x4438` and assigns `+0x4434 = 0.8 * BrakeThermalModel`, or zeros `+0x4434` and assigns/raises `+0x4438` from `TireGripCoefficient`; a final cap can limit `+0x4434`.
- `PhysicsGearShiftLogicWithThresholds_00426330`, called in the same AI update sequence, only invokes the recovered gear-change callback after engine/gear/wheel-related threshold checks. It does not read the scalar trio.
- `SteeringAngleController_00425670` is a navigation/state routine (heading tests, timers, and AI-state changes), not a final steering actuator.

### Boundary

The static path now covers AI planning through steering and conditioned slow/drive decisions plus gear-change requests. The remaining unproven edge is where those vehicle-state values become the authoritative per-AI physics controls.

## 2026-08-18 — initialization inputs and cadence tightened

### Verified facts

- `AIDriverStructInit_00424790` establishes the AI working-state defaults, including `+0x4431 = 1.0`, `+0x4437 = 1.0`, `+0x4414 = 1.0`, `+0x4403 = 1.0`, `+0x4420 = 0`, and `+0x45FC = 0`.
- In its `LOBYTE(a2)` initialization branch it resets `+0x45F8`, scans registered vehicles for equal non-self strings at `vehicle+0x46B8`, and stores the last match in `+0x45F8`; it then derives `this[2]` from global `dword_5EA2D0` plus the vehicle's `+0x48A4` index and obtains an initial spatial node through `SpatialTreeNearestNeighborSearch`.
- The same initializer fills seven fields at `+0x4600..+0x4618` using `GuardedCallWithCheck`, then calls `AIDifficultyInterpolation`, scaling its result by `flt_5EA3E8` except in sessions `3/4/5`.
- `MainGameTickUpdate_0042C690` executes `AIMainUpdate` for every registered vehicle on each tenth internal tick. Every fiftieth tick it separately calls `AILateralForceComputation`, then per-vehicle yaw recovery and, for vehicles whose `+0x32C8 == 1`, wheel/tire-force update.

### Boundary

This establishes the static initialization sources and two cadences. The semantic content of the equal `+0x46B8` string and the seven guarded values is still unresolved; no team/driver meaning is assigned from names alone.

## 2026-08-18 — driver configuration inputs recovered

### Verified facts

`sub_424080`, called by `AIDriverStructInit_00424790`, performs static string-keyed lookup of these driver configuration keys: `STARTSDRY`, `STARTSWET`, `STARTSTALLS`, `QUALIFYINGABILITY`, `TRACKAGGRESSION`, `RAINABILITY`, `RACEABILITY`, `PASSING`, `CORNERINGADD`, `CORNERINGMULT`, `CRASH`, `COMPLETEDLAPS`, and `SCRIPT`.

- Missing keys retain hard-coded defaults; each found value is parsed and stored in the vehicle AI working region.
- The routine then applies global/session scaling, including `flt_7D017C`, `flt_5EA3D8`, `flt_8AFEE8`, and difficulty global `dword_7D01A0`, and calls `LateralForceTorqueCalculation(this, 100)`.
- `AIDifficultyInterpolation_00424AC0` is exactly piecewise on `dword_7D01A0`: above `100` it interpolates between `flt_5EA3E0/5EA3E4`; otherwise it scales between `flt_5EA3DC/5EA3E0` from the `70` baseline.
- `GuardedCallWithCheck`'s seven initialization values are not generic AI coefficients: it performs `NthValidPartLookup` followed by `TireCompoundNameIDMapping`.

### Boundary

The key names prove the configuration-input surface and the code proves how global difficulty/weather-like scalars reshape it. Exact file provenance and the semantic identity of every destination field remain outside this static slice.

### Naming correction

Despite its inherited name, `LateralForceTorqueCalculation_0042AD00` only performs `+0x453C = a2 * (+0x44F4) * 0.01`; init calls it with `a2 = 100`. `AIDriverRandomSelector_0042AE20` also calls it with `100` when clearing a matching `+0x45FC` pointer. It is a percentage-style scalar setter, not evidence of a force/torque write.

## 2026-08-18 — waypoint-planning state recovered

### Verified facts

- `sub_426430` derives vehicle speed at `+0x4440` from the three-component velocity at `+0x34F8/+0x34FC/+0x3500`.
- Its current spatial node is `+0x4354`. It queries `SpatialNearestNeighborQueryWithPlaneTest` when that pointer is null or its planar squared displacement exceeds `3200.0`; a failed query is the function's only zero return.
- A refresh invokes `SpatialTreeNearestNeighborSearch`, then builds a 20-node look-ahead pointer chain at `+0x4358...`; links select `node+0x114` when it agrees with the current selection context, otherwise `node+0x110`.
- The chosen node's `+0x12C` updates AI lane/mode field `+0x4550`. The planner selects a look-ahead index from speed bands `15`, `30`, and `65`, computes a normalized speed ratio capped at `1.0`, and derives steering-ray/lateral bounds at `+0x4414/+0x4418/+0x441C` from node geometry and the active look-ahead chain.
- `AISteering_004270A0` consumes that look-ahead chain and bound state, scans candidate vehicles, and calls `Overtaking_0042AF70` only in selected per-candidate modes. It narrows a lateral target against the computed bounds before committing it to its working state.

### Boundary

This proves the planner's spatial recovery, forward-chain, lane-selection, speed-band, and lateral-bound stages. Node field semantics beyond their arithmetic/geometric use remain intentionally unnamed.

## 2026-08-18 — proximity-pointer lifecycle tightened

### Verified facts

- `OpponentProximityScanTeamRecognition_0042A7D0` resets five per-candidate records before using `FindNearestVehicle`; if that yields no vehicle, it scans every other registered vehicle and maintains a five-entry nearest-distance ordering.
- In race session `7`, only an eligible scanned vehicle within squared planar distance `625.0` and with `candidate+0x403C > current+0x403C` is written to current vehicle `+0x45FC`. The writer simultaneously puts `-2.5` or `+2.5` in `+0x4420`, chosen by the sign of a 2D cross-product expression.
- `Overtaking_0042AF70` independently writes `+0x45FC` only after its session/mode gates; it writes `+3.0` for mode `2` and `-3.0` otherwise.
- `AIDriverRandomSelector_0042AE20`, reached from `ResetDriverGridState_004C6E80` during a vehicle reset, clears `+0x45FC` when the reset vehicle equals its stored pointer. It separately clears `+0x45F8` if that pointer matches.

### Conclusion

Both live writer families select another vehicle and a signed lateral displacement. In the directly proved race proximity branch, the selected candidate is a lap ahead of the writer; it cannot support a general “writer is attacker” claim. Reset-time equality clearing confirms the fields are pointer identities, not rank/state codes.

## Static coverage ledger — 2026-08-18

| Area | Static status | Evidence boundary |
|---|---|---|
| Inputs/init | Mapped | String-keyed driver values, tire-part mapping, difficulty scaling, state defaults, initial spatial query; source-file provenance and some destination semantics remain open. |
| Planning | Mapped | Nearest-node recovery, 20-node look-ahead, lane/mode, speed bands, lateral bounds, speed profile. |
| Traffic/overtaking | Mapped with role boundary | Candidate scans and two pointer writers are known; no general attacker/defender label is proved. |
| Controls | Mapped to exported state | Signed steering and mutually exclusive slow/drive pair are generated, conditioned, copied, and packetized. |
| Physical effects | Partially mapped | Independent 50-tick pairwise vector reaches rigid-body force/torque integration; no direct all-AI actuator consumer for the copied scalar trio is recovered. |
| Race order | Mapped | Timing/lap fields update rank through a distinct setter/transition path, with no `+0x45FC` dependency. |

### Priority open questions

1. Recover the authoritative per-AI physical consumer, if any, for `+0x357C/+0x3580/+0x3584`, including alias/indirect-call possibilities.
2. Resolve the semantic source of the equal `+0x46B8` string and whether its `+0x45F8` link materially changes race behavior beyond documented pit logic.
3. Bound `AISteering` modes and sign convention sufficiently to label the two lateral choices, if raw assembly can resolve the decompiler's dropped call argument.

### `+0x46B8` source narrowed

`NationalityDriverInfoLoader_004C78F0` copies the `+0x46B8` string from source-record slot `v2+31` (`v2 = dword_8AC394 + 1060*a2`). It is one of several loaded identity/display strings, but raw code does not identify the source record member semantically. The equal-string `+0x45F8` link is therefore still not safely nameable as team, driver, nationality, or any other role.
## 2026-08-18 — exported drive flag feeds traffic decisions

`AISteering_004270A0` reads a candidate vehicle's `+0x3584` (`+13700`) during close-traffic mode selection: when that value exceeds `0.1` and the candidate's local motion term is positive, it forces that term to `-1.0` before applying distance thresholds. This is a real all-AI consumer of the exported state, but it is a traffic-planning input—not a drivetrain or tire-force actuator. The prior boundary remains: `+0x3584` is packetized as bit `0x4000000` and no direct physical scalar consumer has been recovered.
## 2026-08-18 — scalar-consumer static audit

Raw-corpus searches for the exact vehicle offsets establish the current negative boundary:

- `+0x357C` (`13692`) occurs only in `AIMainUpdate_00424E70` (writer/default) and `SetupCarLightingAndRender_004C71C0` (packet encoding).
- `+0x3580` (`13696`) occurs in those paths, the singleton `DriverInputController_00451720`, packet decoding, and wheel-block functions whose direct relative accesses bypass the copied slot.
- `+0x3584` (`13700`) occurs in those paths, packet decoding, the singleton controller, and candidate-state read in `AISteering_004270A0`.

No exact-offset raw occurrence is a per-AI engine, gearbox, wheel-force, or tire-force consumer. This is strong corpus coverage for the direct-field hypothesis, not proof that an indirect/aliased actuator bridge cannot exist.
## 2026-08-18 — `AISteering` mode-to-offset proof

The two recovered `AISteering_004270A0` call sites invoke `Overtaking` for mode classes `{2,7}` and `{1,8}`. In `Overtaking_0042AF70`, only mode `2` writes `+0x4420 = +3.0`; every other successful mode writes `-3.0`. Therefore the `AISteering` classes resolve to: `2 → +3.0`; `1/7/8 → -3.0`. The Hex-Rays caller text still drops the required candidate argument, so this does not identify the candidate passed at either call site or establish left/right physical convention.
## 2026-08-18 — command-driven AI state inputs

`AICommandMessageQueueDispatcher_00424CD0` invokes `CommandQueueResponseHandler_00429EE0` synchronously. Raw response handling proves these state inputs:

- In non-race sessions, command `0` sets `+0x4510 = 5` and invokes `AISpeedDeltaSetter(1)`.
- Command `5` sets `+0x4544 = 1`; command `4` sets `+0x443C = 1`; command `14` sets `+0x4544 = 0` and `+0x443C = 1`.
- Session-phase conditions additionally set/clear speed-related state through `AISpeedDeltaSetter` and `ParameterValueSetter`.

`AIMainUpdate` branches on `+0x4510`: modes `0/6` enter `SteeringAngleController`, `1` enters the state-reset/default-output path, `2` resets it to `0`, `3` performs a geometry/timer check, `7` forces neutral steering and `+0x4434/+0x4438 = 0/1`, and `4/5` follow the special pit/phase path. This maps actual state-machine edges without assigning unsupported human labels to every numeric mode.
## 2026-08-18 — AI pit-decision branch bounded

`AIAbility_00429470` is periodically scheduled by `AIMainUpdate` and owns the recovered pit-decision calls. `RacePhasePitEntryTrigger_00429EB0` calls `ForcePitExit_0042A110` only when `FuelMultiplierValue(this) < 1`, `+0x4544` is clear, and session phase equals `5`. `ForcePitExit` then applies its own race/session, lap, and finish-state gates before state-transition helpers.

`PitStopDecisionTireCompound_0042A3D0` derives a lap-distance-like quantity from current lap and indexed values, computes a bounded target scalar, sets per-index plan fields, and conditionally performs cleanup/state transition. This confirms pit logic is an AIAbility-side branch with lap/finish/track-condition gates; it remains separate from `AIDriverSorting` and does not make `+0x45FC` a pass event.
## 2026-08-18 — push-lap and difficulty paths

`AIPushLap_0042A180` is called from the timed `AIMainUpdate` branch for vehicles passing the `+0x32C8 == 1` gate. Outside race session `7`, it increases `+0x453C` toward a lap-dependent bound. It also computes `+0x4580 = max(0.5, 1 - flt_8AFEE8 * +0x4468)`, compares current tire identity against weather-band-selected IDs, and can call `ForcePitExit`; an average of four tire-related fields below `0.9` is another direct trigger.

`AIDifficultyScalar_00424750` returns exactly `1.0` at difficulty `>=95`; below that it is linear from the `70` baseline. This scalar is consumed by initialization, AIAbility, and steering conditioning. These paths establish session/difficulty/tire inputs to AI behavior without requiring a runtime interpretation of the weather scalar.
## 2026-08-18 — per-vehicle physics dispatch order

`MainGameTickUpdate_0042C690` calls `AIMainUpdate` for every registered vehicle, then immediately calls `LoopWithConditionalSkipFunction`. Its state-`6` worker, `SceneObjectLoaderStateMachine_0040F1C0`, checks the linked vehicle's `+0x48BC` bit `0x8`, invokes `VehiclePhysicsModeDispatcher_004E4930`, then calls `SuspensionStateUpdate` for that same linked vehicle and copies its position into the scene record.

This proves a per-vehicle physics-dispatch route after the AI pass, rather than only the separately visible player/global route. The recovered dispatcher/integration source still has no direct read of the copied AI scalar trio, so it strengthens ordering evidence but does not close the indirect-actuator gap.
## 2026-08-18 — major correction: interior-base actuator bridge recovered

The earlier direct-offset audit was incomplete because the per-vehicle physics state machine uses an interior base `vehicle+0xC`: its `this+12988` is the vehicle's `+0x32C8` gate. Consequently its relative offsets resolve as follows:

| Physics interior offset | Vehicle offset | Proven use |
|---|---:|---|
| `+13680` | `+0x357C` | `sub_4E51A0` reads it into a torque/interpolation calculation; `sub_4E5AE0` uses it to interpolate/clamp rotational dynamics. |
| `+13688` | `+0x3584` | `sub_4E51A0` multiplies it into front/rear wheel values before later wheel-force processing. |
| `+13684` | `+0x3580` | Initialized/reset in the same interior state block; no direct physical read has yet been recovered. |

`PhysicsIntegrationStateMachine_004E4E60` calls `sub_4E51A0` and `sub_4E5AE0` in the post-AI per-vehicle dispatch. This establishes the previously missing physical bridge for the two longitudinal scalars: `AIMainUpdate` copies `+0x4434 → +0x357C` and `+0x4438 → +0x3584`, then the physics state machine consumes them through the interior alias. The signed steering value at `+0x3580` remains separately unresolved.

This supersedes only the prior claim that no direct physical consumer for the copied scalar pair had been found; it does not change the packet/traffic consumers or the open steering-actuator boundary.
## 2026-08-18 — steering serialization/physical path recovered

`SetupCarLightingAndRender_004C71C0` passes vehicle `+0x3580` to `FloatToBitfieldEncoder_004B2A40`, which stores `(int)(value*63)-64` in bits `0..6` of packet word `11`. `VehiclePhysicsTimeStep_004C73F0` calls the exact inverse helper, `BitfieldToFloatConversion_004B2A80`, on that word: `((word11 & 0x7F)-64)/63`.

The decoder clamps the recovered signed value to `[-1,1]`, writes it to vehicle `+0x1040`, multiplies it by `+0x1044`, and passes that product to `SuspensionParamUpdate_004E24A0` for wheel indices `0` and `1`; the other two indices receive `0.0`. `SuspensionParamUpdate` updates each wheel's rotation/geometry state.

This closes the static steering-data path from AI's `+0x442C → +0x3580` through the shared packet codec into front-wheel suspension geometry. The currently recovered call graph does not prove which local/network/replay execution mode consumes every AI packet, so that deployment detail remains open—not the encoding/decoding mechanism itself.
## 2026-08-18 — steering-path deployment correction

The packet codec proof establishes a valid physical decode path, but not that it is the authoritative local steering actuator for every AI car. `VehiclePhysicsModeDispatcher_004E4930` sends interior mode `1` to `PhysicsIntegrationStateMachine_004E4E60` and mode `2` to `TeamColorLoader_004F03E0`; only the latter calls `VehiclePhysicsTimeStep_004C73F0`, the packet decoder. Meanwhile `AIMainUpdate` itself admits vehicles with outer `+0x32C8` values `0/1` and rejects values above `1`.

Therefore: the signed `+0x3580` codec-to-wheel-geometry mechanism is verified, but its local all-AI deployment is not. The longitudinal physical bridge through mode-`1` interior aliases remains directly proven. This supersedes any wording that claimed all three AI controls were proven to actuate every AI car locally.
# 2026-08-18 — Steering decoder deployment: second static pass

## Verified facts

- The raw corpus has exactly two recovered calls to `VehiclePhysicsTimeStep_004C73F0`:
  1. `TeamColorLoader_004F03E0` calls it as `VehiclePhysicsTimeStep(*this, (int)v3, a2)` only when `UtilityFunction_3D50(dword_7CD25C, *(*this + 0x4894), (int)v3, a2)` succeeds.  `VehiclePhysicsModeDispatcher` reaches that function only for its inner mode `2`.
  2. `sub_4F0430` calls it only in its switch case `*((DWORD *)this + 3247) == 3`, after `sub_4B9AC0(&dword_8AB6EC, *((DWORD *)this + 1), (int)v95, -FLT_MAX)` succeeds and after `Delegation(&dword_8AB6EC)`.  Its first argument is `&unk_5EC6D8 + 18624 * *((DWORD *)this + 1)`, not its own `this` pointer.
- `PerVehicleCameraUpdateIterator_004109D0`, called by `MainGameTickUpdate_0042C690`, has a global-state branch: when `dword_8AB6E4 == 2`, it calls `sub_4F0430(a2)` once per `dword_7C54F0[i]`, then calls `WheelContactTransform(dword_7C54F0[i] + 0xC)`.  That call to `sub_4F0430` has no vehicle argument.
- In its other branch, `PerVehicleCameraUpdateIterator` invokes `ModeDispatchedRenderPhysicsCall_0040F300` for elements of `this[2]`.  That dispatcher calls `sub_4F0430(a2)` only when its element's `+0x1C` mode is `6`; other modes `0..5` call `VehicleOrientationFromAngularVelocityIntegration` instead.
- Therefore this newly recovered route does not establish a one-to-one `AIMainUpdate` vehicle -> `VehiclePhysicsTimeStep` relation for all AI cars.  It instead proves that the same steering decoder has at least two gated deployment routes, one mode-2 vehicle-dispatch route and one separately indexed case-3 route.

## Inference

The packet codec remains a proven physical front-wheel input mechanism, but these callers strengthen the existing caution: static evidence does not yet identify which route is authoritative for every locally simulated AI vehicle versus other presentation, synchronization, or control modes.

## Open question / next best static step

Recover the producer and membership semantics of `dword_8AB6EC` / `unk_5EC6D8` and the mode source for the `+0x1C == 6` elements.  That is the shortest static route to classify the case-3 decoder path without naming it from decompiler prose.
# 2026-08-18 — Correction: case-3 decoder selects a vehicle slot

## Verified facts

- `BuildActiveVehiclePointerArray_0042BC80` starts at `unk_5EC6D8`, advances by `4656` dwords (`0x48C0` / 18624 bytes), and writes each slot whose dword index `3250` (`+0x32C8`) is not `-1` into `dword_7C54F0`.  It then fills remaining entries from the same `unk_5EC6D8` array.  Thus `unk_5EC6D8 + 18624 * index` is a vehicle-slot address in the same array that supplies `dword_7C54F0`.
- Accordingly, the case-3 call in `sub_4F0430` is vehicle-indexed: `VehiclePhysicsTimeStep(&unk_5EC6D8 + 18624 * this[1], v95, dt)` targets one such slot.  The prior statement that it was merely a separate indexed route remains true, but it must not be read as evidence that it is a non-vehicle or presentation-only object.

## Open question

The raw call graph still does not connect `sub_4F0430` case 3's `this[1]` index to the vehicle currently being updated by `AIMainUpdate`, nor prove which active slots select case 3.  Universal local-AI steering deployment is therefore still unproven.
# 2026-08-18 — Case-3 decoder input is record interpolation, not an AI direct call

## Verified facts

- In case 3, `sub_4F0430` asks `sub_4B9AC0(&dword_8AB6EC, this[1], v95, -FLT_MAX)` to fill the stack buffer `v95`, then supplies that buffer to `VehiclePhysicsTimeStep` for the selected vehicle slot.
- `sub_4B9AC0` uses `LinkedListTraversalWithFilter(*this, index, time)` and, on success, delegates buffer creation to `AudioSamplePlaybackWithPitchModulationAndStereoP_00500210` or `PassthroughWrapper_00C0`; the SDK-like audio names are not used as semantic evidence.
- Raw `sub_500210` builds an output record at its `a3` parameter.  It writes an encoded first dword through `ProgressBarEventEncode`, interpolates three 1/32768-scaled values, interpolates three 1/2048-scaled values, and writes several packed fields.  Its zero-selector branch delegates to `sub_4FF8F0`.
- Raw `sub_4FF8F0` clamps the supplied time to two source-record time fields, interpolates position/orientation and packed fields between those source records, and calls the same `FloatToBitfieldEncoder` / `BitfieldToFloatConversion` steering codec helpers for an interpolated packed control value.

## Inference

The case-3 route feeds physics from a time-selected/interpolated record buffer.  It is therefore a distinct input path from the direct AI commit `vehicle+0x442C -> vehicle+0x3580`; it cannot be used as proof that the AI commit is the source of every decoder invocation.  Static code alone still does not classify the record stream as replay, remote synchronization, or another non-AI control source.

## Next best step

Trace construction and writers of the indexed lists selected by `sub_4B9AC0`, beginning with callers of `LinkedListIteratorWithStateUpdate_004B5760` and `sub_4B6360`, to determine the record stream's ownership without relying on generated names.
# 2026-08-18 — Indexed record stream has its own 104-slot traversal

## Verified facts

- `sub_4B9000` iterates indices `0..103`, calls `LinkedListTraversalWithFilter(this, index, time)` for each, and stores the selected record pointer in a local 104-entry table.  It then routes packed events whose selector is zero and whose low byte is below `0x68` to the corresponding indexed record.
- The same raw routine independently calls `NetworkMessageDispatch` for packed events whose selector is in `1..6`, then finishes with `LinkedListIteratorWithStateUpdate`.
- `LinkedListIteratorWithStateUpdate_004B5760` iterates another list, conditionally creates a stack record with the same record-builder helper, and passes that record to `SceneNodeDecoder_00410F60`.

## Inference

The data that reaches the case-3 physics decoder belongs to a general indexed time-record/event subsystem with scene and message-dispatch consumers.  It is not a direct call chain from `AIMainUpdate`; the evidence supports keeping it separate from the proven local AI-output path.  It still does not prove a single label for the subsystem (for example, replay versus network), so no such label is assigned.
# 2026-08-18 — AISteering candidate-loop reconstruction (argument still unproven)

## Verified facts

- `AISteering_004270A0` processes five candidate records: it begins at `this + 0x4174` (`16756`), advances by 68 bytes, and skips a record whose `+0x34` value is at least `12000.0`.
- In each accepted record, `*(_DWORD *)v33` is repeatedly used as a vehicle pointer: its nested `+0x32C8` state, wheel/geometry fields, and values near `+0x44xx` are dereferenced.  The loop computes heading, longitudinal/lateral separation, feasibility, lane bounds, and a mode `v86` for that selected other vehicle.
- Only modes `{2,7}` and `{1,8}` invoke `Overtaking_0042AF70`; modes `{2,7}` take one opposite signed/lane-bound update path from `{1,8}`.  `Overtaking` itself writes `+0x4420 = +3.0` only when its mode argument is `2`; all other committing modes write `-3.0`.
- The raw callee's `a2` must be a full vehicle pointer, not a small candidate record: it reads `a2[4401]` and dereferences `*a2` at vehicle-relative offsets `+0x403C`, `+0x4034`, `+0x404C`, `+0x4124`, `+0x4174`, `+0x41A0`, and `+0x42C8`-range fields.

## Inference — not raw-call proof

The only candidate-vehicle pointer visibly available in the call's loop iteration is `*(_DWORD *)v33`; it matches the callee's required `a2` shape and is the most likely argument that Hex-Rays omitted at both `Overtaking(this, v86)` sites.  This materially narrows the dropped-argument issue, but does not replace raw disassembly proof of the calling convention/register setup.

## Open question / next best static step

Recover the actual instructions at the two `sub_42AF70` call sites to prove whether they load `*v33` into the callee's candidate argument/register.  Until then, preserve the candidate link as an evidence-backed inference, not a verified call signature.
# 2026-08-18 — `+0x45F8` is a pit-interaction link, not a dead field

## Verified facts

- `AIDriverStructInit_00424790` clears vehicle `+0x45F8` and, in its flagged initialization branch, assigns it to the last nonself active vehicle whose `+0x46B8` string equals the current vehicle's `+0x46B8` string.
- `RaceStructInit_00423E80` clears both `+0x45F8` and the transient `+0x45FC` pointer.  `AIDriverRandomSelector_0042AE20` independently clears either field when it equals the reset vehicle.
- `AIAbility_00429470` has a live `+0x45F8` consumer.  In race session `7`, when the current vehicle's `FuelMultiplierValue(this) < 2`, it evaluates the linked vehicle's fuel value.  If that value is `0 < value < 3` and neither linked nor current vehicle satisfies `FuelWeightLimitCheck`, it calls `ForcePitExit(this)`.
- `Overtaking_0042AF70` has a separate race-session gate: if candidate lap/progress does not satisfy its main `candidate +0x403C > current +0x403C` route, it returns unless candidate equals current `+0x45F8`; only then can its additional progress/pit-state tests reach the normal commit block.

## Corrected conclusion

`+0x45F8` is not an unreachable branch artifact.  It is a persistent same-`+0x46B8` initialization link with proven pit/fuel interaction and a special race overtake eligibility role.  Its exact real-world grouping semantic remains unknown because the exact meaning of source string `+0x46B8` is still not proven; do not call it teammate, driver, or nationality.

## SDK implication

Any direct AI SDK must expose this field, if at all, as an opaque persistent linked-vehicle relation with the above validated consumers—not as an attacker target and not as a freely editable “team” setting until its identity semantics are resolved.
# 2026-08-18 — `+0x45FC` has a direct downstream control effect

## Verified facts

- `AISteeringCorrection_00426CF0`, called by `AIMainUpdate_00424E70`, tests current vehicle `+0x45FC` (`this + 17916`).  When nonzero, it writes `AIDifficultyScalar_00424750() * 0.75` to current vehicle `+0x457C` (`this + 17788`).
- Later in the same function, the value at `+0x457C` is an upper cap: when `byte_5C3160` is clear and current `+0x4434` (`this + 17460`) exceeds `+0x457C`, it replaces `+0x4434` with `+0x457C`.
- This is independent of the lateral `+0x4420` write: a non-null selected-other-vehicle pointer can therefore also constrain the AI's longitudinal slow/stop demand through `+0x457C`.

## Corrected model

`+0x45FC` is not merely a transient lateral-line selector.  Its provable consumers are now: (1) `AISteeringCorrection` longitudinal cap activation, (2) `AIMainUpdate` reset/clearing flow, and (3) the traffic/overtake selection logic already documented.  It still does not prove a completed pass or a universal attacker/defender role.

## SDK implication

An AI SDK must treat `+0x45FC` as an opaque interaction state with downstream throttle/brake consequences.  Directly injecting it would alter more than line offset and remains unsafe without runtime invariants.
# 2026-08-18 — `+0x46B8` identity resolved: vehicle-record `Team`

## Verified facts

- `VehFileParser_004C3200` parses the literal key `TEAM` (`aTeam_0`) into its vehicle-record field at byte `+124`.
- `NationalityDriverInfoLoader_004C78F0` treats each source vehicle record as `dword_8AC394 + 1060 * index` and copies `v2 + 31`—exactly byte `+124`—to the live vehicle at `+0x46B8`.
- `AIDriverStructInit_00424790` compares those live `+0x46B8` strings across active nonself vehicles and stores the last equal match at `+0x45F8`.

## Corrected conclusion

The persistent `+0x45F8` link is a same-`TEAM` vehicle relation, not an opaque identity relation.  Combined with its proven race fuel/pit and special overtake consumers, it is evidence-backed teammate-pair state.  It is still implementation-sensitive: initialization retains the last matching active vehicle, so teams with more than two active cars do not have a proven stable pair-selection policy.

## SDK implication

A direct AI SDK can safely describe `+0x45F8` as the current vehicle's selected same-team peer pointer, while preserving its reset and multi-car-team uncertainty in the public contract.
# 2026-08-18 — Same-team fuel condition advances the pit machine

## Verified facts

- `ForcePitExit_0042A110` operates on the vehicle-owned subobject beginning at `vehicle + 0x32CC` (`this + 3251` dwords).  It calls `StateConditionalAction_004A5E40` and then sets AI `+0x454C` to `1` through `AIStateFlagSetter_0042AC70`.
- `StateConditionalAction` is confirmed-owned by `F1CPitMachine`; it reads subobject `+0x184` and, when it is zero or `4`, invokes `StateChangeNotify(..., 1)`.
- In race session 7, `ForcePitExit` has an end-of-session/lap guard: it takes its state-advance path unless current `+0x403C` equals `dword_8ACF8C - 1` without the stated exception.  Outside race session 7 it unconditionally uses the same state-advance path.
- Thus the `AIAbility` same-team fuel/weight condition previously documented is not merely a boolean hint: it reaches a confirmed pit-machine state transition and sets AI state `+0x454C = 1`, subject to these guards.

## SDK implication

The teammate link participates in strategy state, not just traffic.  A direct SDK needs a high-level, guarded pit-strategy interface rather than raw writes to `+0x45F8`, pit-machine state, or `+0x454C` independently.
# 2026-08-18 — Driver-AI configuration surface mapped to live fields

## Verified raw token-to-field mapping in `sub_424080`

| Input key | Initial destination | Verified immediate transform / note |
|---|---:|---|
| `STARTSDRY` | local dry-start value | Blended with `STARTSWET` into `+0x44B8` using `flt_8AFEE8`, then randomized/clamped and converted by `value * 0.1 + 1.0`. |
| `STARTSWET` | local wet-start value | Same blend as above. |
| `STARTSTALLS` | `+0x44BC` | Direct parsed value; later used for race-start probability (`value * 100` versus `rand % 10000`). |
| `QUALIFYINGABILITY` | `+0x44C0` | `(22.0 - parsed) / 22.0`. |
| `TRACKAGGRESSION` | `+0x44F8` | Multiplied by `flt_7D017C`, with a minimum `0.01`. |
| `RAINABILITY` | `+0x44C8` | Initially direct; then multiplied by `0.01 * flt_5EA3D8`.  Also feeds `+0x4580 = 1 - flt_8AFEE8 * (+0x44C8)`. |
| `RACEABILITY` | `+0x44C4` | Initial parsed value feeds `+0x44F4`, `+0x44D8`, `+0x44D4`; destination finally becomes `(22.0 - parsed) / 22.0`, with an additional `dword_7D01A0 < 100` square scaling. |
| `PASSING` | `+0x44CC` | Final value `min(1.0, 0.9 + parsed * 0.001)`. |
| `CORNERINGADD` | `+0x4500` | Direct parsed value. |
| `CORNERINGMULT` | `+0x4504` | Direct parsed value. |
| `CRASH` | `+0x44D0` | Direct parsed value. |
| `COMPLETEDLAPS` | `+0x44DC` | Direct parsed value. |
| `SCRIPT` | `+0x44E0` string buffer | Replaces default `"DEFAULT.SCP"` when present. |

## Important coupling

- The function invokes `LateralForceTorqueCalculation_0042AD00(this, 100)` after deriving race-ability-related values; that callee writes `+0x453C` from `+0x44F4` and its supplied factor.  The configuration surface is therefore not a set of independent knobs.
- Race start events can write failure/category state from `STARTSTALLS` and season event data.  A direct SDK must preserve this initialization ordering rather than live-patching the raw derived fields blindly.

## SDK implication

These keys are the strongest current high-level, data-driven modding surface.  Expose them as named configuration inputs; expose the resulting fields as read-only diagnostics until each has runtime validation across race, qualifying, wet, and start paths.
# 2026-08-18 — Cornering keys feed the speed target, not steering geometry

## Verified facts

- `AIComputePassScore_0042A780`, called by `AIRacingLine_00425920`, returns:
  `((segmentInput * vehicle+0x4504) + vehicle+0x4500) * vehicle+0x4580 * vehicle+0x453C * segmentFactor`.
  It invokes `TireForceSolver` before the calculation; `segmentInput` and `segmentFactor` are caller-supplied/segment-derived values and are not renamed here.
- `AIWaypointSteering_00426430` also reads `+0x4500` and `+0x4504` on waypoint refresh: it computes `waypoint +0x74 * (+0x4504) + (+0x4500)`, caps this at `75.0`, then divides current speed by that result and caps the ratio at `1.0`.
- Therefore `CORNERINGADD` (`+0x4500`) and `CORNERINGMULT` (`+0x4504`) are direct longitudinal speed-profile inputs.  They are not direct steering-angle multipliers.

## SDK implication

For a named SDK, expose these as speed-profile affine coefficients.  Couple their validation to `RAINABILITY`/`+0x4580` and pace `+0x453C`, because all three multiply in the racing-line score.
# 2026-08-18 — Race ability and passing are direct racing-line inputs

## Verified facts

- In `AIRacingLine_00425920`, `+0x44CC` (`PASSING` normalized) multiplies the speed-profile decrement for each traversed waypoint: after tire/waypoint terms it subtracts `waypoint+0x3C / currentProfileSpeed * (+0x44CC) * candidateScore * 0.915` (with the function's existing low-speed guards).
- The same function uses `+0x44C4` (`RACEABILITY` normalized) as the normal brake-demand ramp source when `byte_5C3160` is clear: its value is multiplied by `0.2` to limit a step toward the chosen `+0x4434` braking target.
- `+0x44B8` is the alternate ramp source only when `byte_5C3160` is set.  Its start-dry/wet/random initialization is therefore separate from the normal race-ability route.

## Corrected SDK map

`PASSING` affects the built speed profile; `RACEABILITY` affects the rate at which braking demand approaches its target.  Neither field alone means “overtake permission” or a fixed vehicle speed.  The named SDK contract must keep them coupled to the racing-line update rather than offering naïve independent actuator writes.
# 2026-08-18 — Configuration-consumer coverage boundary

## Direct static consumer status

| Key / live field | Direct static behavior path recovered |
|---|---|
| `TRACKAGGRESSION` / `+0x44F8` | `AISteering`: follow gaps, side-by-side window, and pressure accumulation. |
| `PASSING` / `+0x44CC` | `AIRacingLine`: waypoint speed-profile decrement. |
| `RACEABILITY` / `+0x44C4`, `+0x44F4`, `+0x453C` | Config derivation, racing-line score, and braking-ramp path. |
| `RAINABILITY` / `+0x44C8`, `+0x4580` | Config derivation, `AIPushLap`, and racing-line score multiplier. |
| `CORNERINGADD`/`CORNERINGMULT` / `+0x4500`/`+0x4504` | Waypoint speed target and racing-line score. |
| `STARTSTALLS` / `+0x44BC` | Initialization-time race-start probability branch in `sub_424080`. |
| `QUALIFYINGABILITY`, `CRASH`, `COMPLETEDLAPS`, `SCRIPT` | Parser destinations confirmed, but no direct downstream field reader is presently recovered by the canonical offset index. |

## Required uncertainty

Absence from the current direct-offset index is not proof that the last four inputs are inert: a consumer can access them through an alias, an aggregate copy, or an unindexed call.  These are now explicit remaining static gaps for a complete direct-AI SDK, not safe fields to omit or expose as behavior-proven controls.
# 2026-08-18 — AI command queue writes coupled control state

## Verified facts

- `AICommandMessageQueueDispatcher_00424CD0` deduplicates command IDs in its per-vehicle pair queue and immediately calls `CommandQueueResponseHandler_00429EE0` after enqueuing a new one.  It is not merely deferred storage.
- Response command `0`, outside race session 7, clears `+0x4544`, calls `ParameterValueSetter(18)`, writes `+0x4510 = 5`, and calls `AISpeedDeltaSetter(1)`.
- Response command `5` calls `ParameterValueSetter(99999)` and writes `+0x4544 = 1`; command `4` writes `+0x443C = 1` and calls `ParameterValueSetter(18)`; command `14` writes `+0x4544 = 0` and `+0x443C = 1`.
- `ParameterValueSetter_0042ACD0` writes `+0x4538`: argument `18` maps to `flt_8ACFB4`; other values are stored as float directly.  `AISpeedDeltaSetter_0042ACA0` writes `+0x4550` when its argument is 0 or 1 and, for 1, also calls `sub_4A46F0(this, 1, 0)`.
- Dispatcher command `4` directly calls `sub_4A46F0(this, 1, 1)`; command `5` clears `+0x4548` then calls `sub_4A46F0(this, 0, 0)`.

## SDK implication

These command IDs are coupled transitions, not independent field presets.  A future direct SDK should expose guarded named actions only after `sub_4A46F0` is classified; it must not present raw commands 0/4/5/14 as stable public mode numbers.
# 2026-08-18 — `sub_4A46F0` cannot yet be semantically classified

## Verified limitation

- Raw `sub_4A46F0` appears to take `(_DWORD *this, int a2, char a3, int a4)` and uses `*(_DWORD *)(a2 + 4)` as an index before writing `this[index] = a2` or zero.
- Its recovered callers render small literals such as `sub_4A46F0(this, 1, 1)` and `sub_4A46F0(this, 0, 0)`, which are incompatible with that apparent `a2 + 4` dereference.

## Consequence

This is another calling-convention/decompiler-argument reconstruction failure, analogous to the dropped candidate argument at the `Overtaking` call sites.  The command-transition field writes documented above remain raw-callee facts, but the semantic effect of their shared `sub_4A46F0` calls is unresolved until actual instructions or a corrected prototype are recovered.  Do not infer a named pit/lane/state operation from its generated label.
# 2026-08-18 — Push-lap pace and weather strategy formula

## Verified facts

- `AIPushLap_0042A180` runs only while the vehicle's `+0x32C8` equals `1`.
- Outside race session 7, it raises `+0x453C` toward `+0x44F4 + +0x44D8`; the per-call increment is `min(current + lapCount * 0.003, target)`, with `lapCount` capped at 10.
- Every admitted call writes wet factor `+0x4580 = max(0.5, 1.0 - flt_8AFEE8 * +0x44C8)`.
- Unless AI state `+0x454C` is `1`, it evaluates target tire-choice/lap conditions and forces the pit-machine path on mismatches; it also forces that path when the average of four tire-related values at indices `3471, 3533, 3595, 3657` is below `0.9`.

## Corrected model

`RAINABILITY` has two distinct effects: it scales the racing-line score through `+0x4580`, and it participates in weather-band tire/pit strategy.  `RACEABILITY`-derived `+0x44F4/+0x44D8` also controls non-race-session pace ramping through `+0x453C`.
# 2026-08-18 — Correction: race-phase pit gate uses `+0x4550`, not `+0x4544`

## Verified facts

- `RacePhasePitEntryTrigger_00429EB0` calls `ForcePitExit(this)` only when all three conditions hold: `FuelMultiplierValue(this) < 1`, current `+0x4550 == 0`, and global `dword_7C56A8 == 5`.
- The tested field is `this[4436]`, which is byte offset `0x4550`.  `AISpeedDeltaSetter_0042ACA0` is a direct writer of that field for values 0 and 1.

## Correction

Any earlier prose that described this exact gate as using `+0x4544` was wrong.  `+0x4544` is a different command-response state field; the race-phase fuel gate uses `+0x4550`.
# Direct AI SDK readiness ledger — static evidence only (2026-08-18)

| SDK surface | Static readiness | Reason |
|---|---|---|
| Driver `.rcd` ability configuration | Strong | Parser, all destinations, and most core consumers recovered. Runtime validation is still required before a public write API. |
| Read-only plan/traffic telemetry | Strong | Waypoint chain, candidate scan, line offset, speed profile, and interaction-pointer consumers recovered. |
| Read-only teammate strategy telemetry | Strong | `TEAM -> +0x46B8 -> +0x45F8`, fuel/pit machine path recovered. |
| Named speed-profile tuning | Strong static / not yet runtime-safe | Cornering, race ability, rain and passing formulae recovered; session/state invariants remain unvalidated in this investigation. |
| Direct actuator writing | Not ready | The normal mode-1 aliases and consumers are recovered; write timing, ownership, range/reset invariants, and mode coverage are not yet SDK-safe. |
| Traffic-pointer or lateral-offset writing | Not ready | `+0x45FC` has coupled braking/line consequences and role semantics vary by session. |
| Command/action API | Not ready | Command field effects recovered, but shared `sub_4A46F0` calling convention is unresolved. |
| Pit-strategy action API | Partial | Major state transitions recovered, but pit-machine plan/entry states are not fully mapped. |

## Completion blockers for the user’s direct-SDK objective

1. Recover raw call instructions/prototypes for `Overtaking_0042AF70` callers and `sub_4A46F0` callers.
2. Complete the universal AI steering-actuation route, separating local simulation from record/replay/network paths.
3. Trace the unresolved `QUALIFYINGABILITY`, `CRASH`, `COMPLETEDLAPS`, and `SCRIPT` consumer paths.
4. Add controlled runtime validation for every intended writable SDK field/action; static evidence alone cannot establish safe, repeatable mod behavior.

## Superseding 2026-08-18 ledger correction

The former “longitudinal physical bridge is recovered” statement lacked receiver-aware alias proof.  The later alias audit corrects that: the mode-1 embedded receiver begins at `vehicle+0xC`, so its `+0x3570/+0x3574/+0x3578` reads are the three vehicle commit fields.  The current direct-actuator row above is authoritative: the normal mode-1 chain is proven, but no writable SDK contract follows without timing, ownership, reset, range, and mode-coverage proof.
# 2026-08-18 — Qualifying, crash, and completed-laps consumers recovered

## Verified facts

- `AIBehaviorInitialization_004BF0A0` calls `sub_4BE760`.  That routine scans active mode-1 vehicles by their `+0x409C` values; in session 7 it uses each selected vehicle's `+0x44C4`, otherwise it uses `+0x44C0`.  Thus `QUALIFYINGABILITY` has a direct non-race behavior-initialization consumer, while `RACEABILITY` supplies the equivalent race-session value in the same calculation.
- `AICollision_004BEF60`, called by `EngineFailureCheck_004BEC55`, has two probabilistic branches in race session 7.  When its first internal flag is set, it compares a random table value to `vehicle+0x44D0 * 0.01 / state+0x35C * a3`.  When its second flag is set and the first branch did not win, it compares a random value to `(1 - vehicle+0x44DC * 0.01) / state+0x35C * a3 * state+0x344`.
- These are direct raw consumers of `CRASH` and `COMPLETEDLAPS`, respectively.  Their enclosing flags, `a3`, and state-scale fields remain named only by offsets, so the final real-world event labels are not overclaimed.

## Ledger correction

The unresolved configuration-consumer list is now reduced to `SCRIPT` only.  `QUALIFYINGABILITY`, `CRASH`, and `COMPLETEDLAPS` are no longer gaps, although their higher-level behavior-event context still needs deeper classification for a polished SDK.
# 2026-08-18 — `SCRIPT` static-search result

## Verified search result

The canonical raw corpus has no additional match for the literal `DEFAULT.SCP`, the default-string symbol, a `.SCP` pattern, or vehicle offset `+0x44E0` beyond `sub_424080`'s write.  No direct static consumer is currently available in this corpus.

## Boundary

This does not prove `SCRIPT` has no game effect: it may be consumed through a generic string/object path absent from the decompiled corpus, an alias, or an external data-driven interpreter.  For the direct-AI SDK objective it remains an unsupported configuration input, explicitly not a no-op.
# 2026-08-18 — Main-update start path is a separate control path

## Verified facts

- `AIMainUpdate_00424E70` first rejects vehicle `+0x32C8 > 1`.  Its normal driving path then requires `AIWaypointSteering_00426430` success and vehicle `+0x32C8 == 1` before traffic scan, racing line, steering, correction, gear logic, and control commits.
- A separate early race-start/countdown path runs when the function's `+0x45F4` flag is clear under its mode-1 condition.  It calculates `+0x4434/+0x4438/+0x442C`-side values directly from countdown/timing state, copies the resulting three control values to `+0x357C/+0x3584/+0x3580` via the shared final block, clears `+0x45FC`, and returns before normal planning/traffic logic.
- Therefore the normal traffic/overtake subsystem is deliberately bypassed during this start-control path.  A modding SDK must not expect `+0x45FC`, racing-line data, or ordinary steering-state transitions to be meaningful while it is active.
# 2026-08-18 — `+0x4510` modes 6/7 transition behavior

## Verified facts

- `SteeringAngleController_00425670` is called by `AIMainUpdate` only for `+0x4510` modes 0 and 6.  Despite its generated name, the raw function does not write the AI steering intermediate `+0x442C`.
- In mode 6 it computes the wrapped heading error from current position/yaw to current waypoint `+0x4354`.  It changes `+0x4510` to 7 when absolute error is below `0.5` radians or its timing condition is met.
- Outside that mode-6 branch it uses the vehicle motion-vector heading error and a speed threshold to increase/decrease an internal counter at `+0x446C`.  When that counter exceeds `+0x4558`, it clears AI state and sets `+0x4510 = 1`.
- The same function periodically copies position into `+0x4470/+0x4474/+0x4478` and advances its `+0x447C` timer.

## Correction

Modes 6 and 7 should be treated as geometry/timed recovery-transition states, not as a direct steering-output controller.  The actual steering intermediate remains produced by the separate `sub_426100` / racing-line paths.
# 2026-08-18 — Direct AI steering-intermediate formula

## Verified facts

- `sub_426100` runs on the normal `AIMainUpdate` path after racing-line/traffic processing.  It selects a waypoint from the current speed-band index `+0x4468`, constructs a target vector using that waypoint's `+0x20/+0x28/+0x94/+0x9C/+0xA4/+0xAC` fields and current `+0x4408` / distance state.
- It projects the target vector against the current forward basis `+0x448C/+0x4494`; the 2D cross-product determines sign.  The magnitude is divided by `+0x44B4`; mode `+0x4510 == 6` flips that sign.
- The result is rate-limited to a change of `0.1` per call, clamped to `[-1.0, +1.0]`, and written to `+0x442C`.
- `AIMainUpdate` then commits `+0x442C` to vehicle `+0x3580` in its common final-control block.

## SDK implication

The steering intermediate is a deterministic, bounded target-angle result, not a raw lane offset.  A future SDK may safely provide it as telemetry; a write API must preserve the rate limit, clamp, state-6 inversion, and start-path exclusion.
# 2026-08-18 — `+0x4510 == 1` output behavior

## Verified facts

- In `AIMainUpdate`, mode `+0x4510 == 1` calls `sub_4258C0`.
- That function sets `+0x4438 = 1.0` and `+0x4434 = 0.0`.  It then changes mode to `2` when current speed `+0x4440 < 4.0`, or when both `+0x37CC` and `+0x38C4` exceed `0.89999998`.
- `AIMainUpdate` handles mode 2 by calling `FieldZeroSetter` and returning before the normal final-control commit.

## SDK implication

Modes 1/2 are a special output/reset path.  A telemetry or action layer must represent them separately from the normal racing-line command path; treating `+0x4438=1, +0x4434=0` as an ordinary drive request would be incomplete.
# 2026-08-18 — Correction: mode 2 only resets the mode field

## Verified correction

`FieldZeroSetter_00425660` consists solely of `this[4420] = 0`, i.e. it writes `+0x4510 = 0`.  Thus `AIMainUpdate` mode 2 skips that tick's normal final-control commit and returns after resetting the mode to 0; it does **not** zero `+0x4434`, `+0x4438`, or physical output fields itself.

## Corrected interpretation

Mode 1 sets the intermediate pair and may schedule a one-tick mode-2 transition.  Mode 2 is a mode-reset/commit-skip state, not a general output-reset action.  Preserve the previous control outputs until another path overwrites them.
# 2026-08-18 — Pit completion returns control through command 15

## Verified facts

- Confirmed `F1CPitMachine` function `PitStopProgress_004A68B0` advances its own state to `4` when its elapsed argument reaches the completion threshold at subobject `+0x1A4`.
- On completion, if the linked vehicle has `+0x32C8 == 1`, it calls `PostPitCleanup(vehicle)` and then `AICommandMessageQueueDispatcher(vehicle, 15, 0)`.
- Queue command 15 clears/sets the documented coupled AI fields (`+0x4544`, `+0x454C`, `+0x4550`, `+0x4548`) and invokes its session-gated helpers; this is the proven return path from pit completion into the driver AI control state.

## SDK implication

Pit completion is not a standalone car-field reset.  A direct SDK must invoke or emulate the whole pit-machine completion path, including post-pit cleanup and command 15, rather than changing a pit flag or AI mode alone.
# Correction — command 15 field list

`AICommandMessageQueueDispatcher` command 15 directly writes `+0x4544 = 0`, `+0x4550 = 1`, and byte `+0x4548 = 1` (plus `ParameterValueSetter(18)` / `+0x4538`).  It does **not** directly write `+0x454C`; remove that field from the preceding command-15 attribution.
# 2026-08-18 — Pit-machine state sequence recovered

## Verified facts

- `VehiclePhysicsModeDispatcher_004E4930` calls confirmed `F1CPitMachine` `PitStateUpdateMachine_004A6E50`.
- The pit-machine state field is subobject `+0x184`.  State 1 returns to state 0 after its 150-second condition; state 2 waits for `VehicleProximityCollisionDetection` then changes to 3; state 3 calls `PitStopProgress` once its `+0x190` byte is set, otherwise calls `PitStopReadyCheck`; state 4 calls `CollisionAvoidanceCheck` when the global guard permits.
- This confirms that pit activity is executed in the vehicle-physics dispatch path, while driver AI requests/receives it through the separately documented AIAbility/ForcePitExit/command transitions.

## SDK implication

Pit strategy is a cross-subsystem protocol: AI decision -> pit-machine states -> physics-dispatch tick -> completion -> AI command return.  It cannot be represented as a single AI boolean or an arbitrary per-frame state write.
# 2026-08-18 — Physics dispatcher mode matrix

## Verified facts

`VehiclePhysicsModeDispatcher_004E4930` reads its interior object's mode at `+0x32BC` and has exactly these raw branches:

| Inner mode | Calls |
|---:|---|
| 0 | `PitStateUpdateMachine`, `VehiclePhysicsIntegrationStep`, stores time at `+0x34AC`, then `VehicleSetupInitialization` |
| 1 | `PitStateUpdateMachine`, then `PhysicsIntegrationStateMachine` |
| 2 | stores time at `+0x34AC`, then `TeamColorLoader_004F03E0` |

## Consequence

The packet/steering-decoder route through `TeamColorLoader` is inner mode 2 and does not invoke `PitStateUpdateMachine` or `PhysicsIntegrationStateMachine` in that dispatch invocation.  The proven AI longitudinal physical bridge is the inner-mode-1 route; universal local steering deployment remains open as documented.

# 2026-08-18 — Correction: `+0x45FC` target direction and pointer type

## Verified facts

- `Overtaking_0042AF70` writes its `a2` argument directly to current AI `+0x45FC`.  `a2` is a candidate **AI-object pointer**, not a direct vehicle pointer: the same raw function reads `*a2` as the candidate vehicle pointer, `a2[4401]` as candidate AI `+0x44C4`, and `a2[4135]` as candidate AI `+0x409C`.
- In race session 7, the ordinary acceptance path requires `candidateVehicle+0x403C > currentVehicle+0x403C`.  The selected target has completed more laps than the writer.
- Outside race/qualifying, the routine rejects `candidateAI+0x409C >= currentAI+0x409C`; its acceptance path therefore requires a strictly better target best-lap value.
- In qualifying, `ServerSessionGateCheck(x)` is false exactly when `x+0x454C != 1` and `x+0x4094 == 2`.  `Overtaking` accepts only current-gate false / candidate-gate true.  Thus the writer is on lap-of-run 2 and not called to box; the target is outside that exact state.
- `AISteering_004270A0` processes five 68-byte candidate records beginning at `this+0x4174`.  Its recovered call display omits the candidate argument (`Overtaking(this, v86)`), while the callee requires candidate AI pointer plus mode.  The selected record's leading pointer is the strongest candidate source, but instruction-level calling convention recovery remains required.

## Correction

Earlier wording that called the callee argument or `+0x45FC` a vehicle pointer was imprecise: the field holds the selected candidate AI object, whose first word points to that candidate's vehicle.  The race and non-race gates select a vehicle ahead on lap progress or better on best-lap evidence.  They do not prove the writer is an attacker; no generic attacker label is safe.  Qualifying has a different state gate and likewise does not establish a universal role.

## SDK boundary

Expose this only as read-only `selectedTrafficAI` / `selectedTrafficVehicle` telemetry after resolving the caller argument setup.  Do not expose it as an attacker/defender relation or writable pointer.

# 2026-08-18 — AI gear output is a request, not a direct current-gear write

## Verified facts

- `AIMainUpdate_00424E70` calls `PhysicsGearShiftLogicWithThresholds_00426330`.
- That routine reads physical `CurrentGear` at vehicle `+0x39FC`, engine RPM at `+0x39A0`, AI mode `+0x4510`, and physical shift-related fields `+0x3A10/+0x3A18`.  It returns while `+0x3A10 > 0`; mode 6 can request `-1`, and vehicle `+0x3D6C == 2` can request `0`.
- Its normal upshift branch compares current gear with `+0x3A04`, then calls `RaceStartCountdownStateUpdate_004EF930(this, currentGear + 1)` when the recovered RPM/threshold tests admit it.  The opposite branch ends in a Hex-Rays `JUMPOUT`, so its exact downshift condition remains open.
- `RaceStartCountdownStateUpdate` receives that requested gear as `a2` and updates its own shift/timer fields; it does not directly write vehicle `+0x39FC`.  The recovered writer for `CurrentGear` is physical `SuspensionAndWheelPhysics_004E5F60`.

## SDK boundary

Current gear is physical state, not a safe AI write surface.  Any future gear API must be a validated request through the recovered shift controller; raw `+0x39FC` writes are outside the current SDK surface.

# 2026-08-18 — Traffic candidate state directly modulates pace

## Verified facts

- `Overtaking_0042AF70` maintains current AI `+0x450C` as the maximum seen candidate AI `+0x44C4` before it evaluates the final `+0x45FC` write gate.  It is therefore a candidate-ability value, separate from the selected-AI pointer.
- `AISteering_004270A0` increments current `+0x4508` while processing the traffic candidate mode paths.
- In race session 7, `AIAbility_00429470` consumes both fields on its roughly four-session-second gate.  With `+0x4508 == 0`, it moves `+0x453C` down by at most `0.01` toward `+0x44F4`; otherwise it moves `+0x453C` up by at most `0.01` toward `+0x44D8 + +0x44F4`.
- If `+0x450C != 0`, the same function performs a random branch using `( +0x44D4 - +0x450C * 0.5 ) * 100` against `rand % 100`: one branch moves `+0x453C` up toward `+0x44D8 + +0x44F4`, the other down toward `+0x44F4 * 0.5`, each bounded to `0.01` per call.  It then clears `+0x4508` and `+0x450C`.

## Consequence

Traffic processing affects longitudinal pace before the final throttle/brake commit, independently of the `+0x45FC` pointer's steering-correction cap.  These fields are transient AI-update state, not stable mod inputs; do not publish either as a writable SDK configuration surface.

# 2026-08-18 — Critical correction: `+0x45FC` is a writer-dependent reference union

## Verified facts

- `Overtaking_0042AF70` stores its candidate **AI-object** argument in current `+0x45FC`; dereferencing that AI object's first word yields the candidate vehicle pointer.
- `OpponentProximityScanTeamRecognition_0042A7D0` independently stores a direct active-vehicle pointer in current `+0x45FC`.  In its race-only direct path, the target is within planar squared distance `< 625`, has `candidateVehicle+0x403C > currentVehicle+0x403C`, and produces `+0x4420 = -2.5` or `+2.5` from the signed planar cross-product.
- The proximity scan therefore writes a **vehicle pointer**, while `Overtaking` writes an **AI-object pointer**.  Both writers also update the same lateral-offset field with different magnitudes (`+/-2.5` versus `+/-3.0`).
- The recovered downstream `AISteeringCorrection_00426CF0` only tests whether `+0x45FC` is nonzero before applying its longitudinal cap; it does not dereference it.  This permits both representations to coexist safely only as transient internal state.

## Correction

The preceding single-type wording was too broad.  `+0x45FC` is a tagged-by-writer reference union, not universally `selectedTrafficAI` and not universally `selectedTrafficVehicle`.  Its nonzero condition means a traffic interaction was selected; its raw value cannot be dereferenced safely without knowing which writer last set it.

## SDK boundary

Do not expose the raw field.  A future telemetry layer must identify the producing path and normalize either representation to a vehicle only after proving the frame/order provenance.  It remains strictly non-writable.

# 2026-08-18 — Superseding correction: `+0x45FC` is consistently an active vehicle record pointer

## Verified reconciliation

- `AIDriverStructInit_00424790` is confirmed `F1CVehicle` code.  It iterates `dword_7C54F0` active vehicle records, compares each record to `this`, and stores a matching record directly in `+0x45F8`.  The initialized driver's `this[0]` is its linked/owner vehicle pointer used for fields such as lap progress and team data.
- `OpponentProximityScanTeamRecognition` writes `dword_7C54F0[i]` directly to `+0x45FC`.
- `Overtaking` receives the same candidate record form: it reads its AI/configuration fields directly through `a2[...]`, reads linked physical/race fields through `*a2`, then writes `a2` directly to `+0x45FC`.
- `AISteering` candidate records carry that same active vehicle record form.  The apparent omitted argument at the `Overtaking` calls is therefore a missing candidate **vehicle-record** argument, not evidence of a second pointer representation.

## Superseded correction

The immediately preceding “reference union” entry was an overcorrection.  The first word of the active vehicle record is a linked/owner pointer, not proof that `Overtaking` stores a differently typed reference.  Both known writers store the same top-level active `F1CVehicle` record pointer.  Retain the raw-call reconstruction as open, but restore `+0x45FC` to a single vehicle-record pointer type.

## SDK boundary

It remains read-only and non-semantic: expose only as optional selected-traffic vehicle telemetry after validating writer timing.  Do not call it attacker/defender and do not permit writes.

# 2026-08-18 — Correction: AIAbility traffic/pace update runs on a four-second timer

## Verified facts

- `AIAbility_00429470` has only one recovered caller: `AIMainUpdate_00424E70`.
- `AIMainUpdate` calls it only when current session time `+0x4480` exceeds the per-vehicle deadline `+0x4404`; immediately before the call it writes `+0x4404 = currentTime + 4.0`.
- `AIAbility`, not `AISteering`, clears transient traffic fields `+0x4508` and `+0x450C` after using them in its race-session pace calculation.

## Correction

Earlier entries calling the `AIAbility` pace adjustment “per frame” are wrong.  Traffic processing may accumulate/update its transient state during normal AI updates, but the resulting `+0x453C` adjustment and reset occur on the recovered four-second AIAbility cadence.  This makes it a sampled strategic pace response, not an immediate throttle-control loop.

## SDK boundary

Any future telemetry must report the next AIAbility deadline and distinguish this slow strategy value from the per-update throttle/brake/steering outputs.  No raw writes are safe.

# 2026-08-18 — Race order is updated at lap/timing events, not by traffic selection

## Verified facts

- `AITickUpdate_004BF4F0` loops active vehicle records.  It skips vehicles with `+0x4064` equal to 2 or 3.  When its per-vehicle timing source is positive, it increments that vehicle's `+0x403C` lap count, updates its finish-line timing fields, and calls `AIDriverSorting_004BF390`.
- `AIDriverSorting` compares race candidates by lap count and `+0x4098` (`totalTimeOnFinishLine`) in race session 7; outside race it compares `+0x409C` best lap.  It uses `ConditionalFieldSetter_004BC2F0` to update the position field at vehicle `+0x4060` through the subobject rooted at `+0x4034`.
- Neither `AITickUpdate` nor `AIDriverSorting` reads `+0x45FC`.

## Consequence

`+0x45FC` traffic selection and lateral-offset changes cannot directly alter race order.  The recovered race-order update is a separate lap/timing-driven subsystem; a visual side-by-side event is not static evidence of a completed pass or position change.

# 2026-08-18 — Racing-line controller produces the two immediate longitudinal intermediates

## Verified facts

- On the normal path, `AIRacingLine_00425920` builds a forward waypoint speed profile.  Starting from current speed, it walks up to 20 linked track nodes and reduces its residual profile by `node+0x3C / residual * +0x44CC * nodeScore * 0.915`; a residual below `0.5` becomes zero.
- When the residual remains positive, the routine writes `+0x4434 = 0` and writes `+0x4438` from `TireGripCoefficient(this + 12)`, rate-limited to an increase of `0.2` from the entry value.
- When the residual is zero, it writes `+0x4438 = 0` and selects/ramps `+0x4434` from the recovered path/obstruction conditions.  One ordinary ramp is bounded by `0.2 *` the active route scalar; other exact branches use `BrakeThermalModel(this + 12)` or fixed values `1.0`, `0.5`, or `0.4`.
- `AIMainUpdate` later commits these exact intermediates to physical control fields `+0x357C` and `+0x3584`; the source/decompiler labels for the helper functions are not treated as pedal semantics.

## Consequence

The fast longitudinal controller is a mutually exclusive profile response: one intermediate is zero while the other is actively generated, subject to route and obstruction conditions.  This is separate from the four-second `AIAbility` strategy scalar and from transient traffic selection.

## SDK boundary

Provide these as read-only immediate command telemetry only.  Pedal-facing names and write semantics require physical/runtime validation despite the static commit path.

# 2026-08-18 — Exact Overtaking lateral-offset mode values

## Verified facts

- `AISteering_004270A0` calls `Overtaking` only for candidate mode groups `{2, 7}` and `{1, 8}`.
- When `Overtaking_0042AF70` accepts the candidate, it writes current `+0x4420 = +3.0` only for argument `a3 == 2`; every other accepted mode writes `-3.0`.
- Therefore the recovered values are: mode 2 -> `+3.0`; modes 7, 1, and 8 -> `-3.0`, subject to all of `Overtaking`'s session/progress/team gates.
- The two groups enter opposite lateral-bound calculations in `AISteering`, but the corpus does not establish which numerical sign means physical left or right on track.

## SDK boundary

Expose at most the raw signed line-offset telemetry plus its mode number.  Do not rename signs to left/right, infer overtaking intent, or write either value.

# 2026-08-18 — Main tick orders AI commits before the per-vehicle physics route

## Verified facts

- `MainGameTickUpdate_0042C690` advances fixed `0.0025`-second substeps.  On every tenth internal tick it calls `AIMainUpdate` for every active vehicle record, then immediately calls `LoopWithConditionalSkipFunction`.
- That loop invokes `SceneObjectLoaderStateMachine` for its registered scene objects.  State 6 checks the linked vehicle flag bit `+0x48BC & 8`, calls `VehiclePhysicsModeDispatcher`, then performs suspension-state update and position copy.
- `AIMainUpdate` writes the immediate AI control outputs before returning; therefore the scene state-6 route is the recovered post-AI per-vehicle physics dispatch in the same ten-tick batch.

## Boundary

This proves update order and the physical dispatch boundary, not that every steering control reaches local wheel actuation through the same inner dispatcher mode.  The all-AI steering-deployment gap remains open.

# 2026-08-18 — Current core-driver static-coverage ledger

| Area | Static state | Boundary |
|---|---|---|
| Driver inputs/configuration | Strong | All parsed keys mapped; only `SCRIPT` lacks a downstream consumer. |
| Initialization, team peer, cadence | Strong | Team peer, start path, ten-tick AI batch, and four-second strategy cadence recovered. |
| Waypoint/racing-line planning | Strong | Normal route refresh, speed profile, lane bounds, and immediate command generation recovered. |
| Traffic and interaction | Strong telemetry / partial semantics | Candidate geometry, offsets, pace effect, pointer type, and session gates recovered; caller instructions, left/right convention, and human role labels remain open. |
| Immediate longitudinal control | Strong static | Racing-line intermediates and physical commits recovered; pedal-facing labels remain unvalidated. |
| Steering | Partial | Formula, clamp, commit, packet codec, and wheel geometry recovered; universal local deployment is unproven. |
| Gear | Partial | AI request path and physical current-gear owner recovered; JUMPOUT/downshift path is missing. |
| Pit strategy | Strong static / action unsafe | Decision and pit-machine protocol recovered; no raw action API. |
| Race order | Strong | Lap/timing-driven sorter and position write recovered; independent of traffic pointer. |

## Exact remaining static blockers

1. Recover instruction-level argument setup/prototypes at both `Overtaking` call sites and the `sub_4A46F0` callers.
2. Recover the omitted `0x004F62E6` gear/downshift continuation.
3. Prove the local-AI route from `+0x3580` through physical steering for every relevant vehicle/dispatcher mode, or document distinct modes precisely.
4. Recover an indirect consumer for `SCRIPT`, or establish corpus incompleteness with an external static artifact.
5. Resolve lateral-sign convention and role intent only from stronger evidence; current code does not prove attacker/defender labels.

Runtime validation remains a separate later phase and is intentionally outside this static investigation.

# 2026-08-18 — Qualifying/Race ability seed the simulated-lap performance model

## Verified facts

- `AIBehaviorInitialization_004BF0A0` calls `sub_4BE760(this, this+0x360, sessionData, currentTime * 1/120)` before it generates the per-vehicle simulated-lap values.
- `sub_4BE760` scans active vehicle records with `+0x32A0 == 1`, selects the smallest positive `+0x409C` and then the largest positive `+0x409C` within `1.15 * minimum`, and reads `vehicle+0x44C4` in session `this+0x360 == 7`; in every other session it reads `vehicle+0x44C0`.
- With two eligible timing values, it calculates the manager value at `this+0x34C` from the timing span and those two selected ability values, with a floor of `0.97 * minimumTiming`.  Otherwise it takes a data-driven fallback, stores the supplied time fraction at `this+0x348`, and adjusts the same `+0x34C` value by `0.15 * (1 - timeFraction)`.
- `AIBehaviorInitialization` passes that `+0x34C` manager value to `RandomVariationScaler_004BEA10` for each eligible vehicle.  That helper chooses `vehicle+0x44C4` in session 7 and `vehicle+0x44C0` otherwise, converts it with a seeded `rand % 40` variation into a clamped `[0,1]` multiplier, then returns a randomized adjustment around the supplied `+0x34C` value.
- The caller writes each returned simulated performance value into its per-entry table, applies it to the vehicle's simulated timing fields (`+0x4098`, `+0x409C`, `+0x40B8` in this path), and invokes `AIDriverSorting`.

## Consequence

`QUALIFYINGABILITY (+0x44C0)` and `RACEABILITY (+0x44C4)` are not merely parsed profile values: the session gate selects one as the ability input for simulated lap/timing generation and resulting sorter updates.  Their exact player-facing scale remains an SDK boundary; expose them as validated configuration inputs, not literal lap-time multipliers.

# 2026-08-18 — Global difficulty scalar has three direct core-AI consumers

## Verified facts

- `AIDifficultyScalar_00424750` returns exactly `1.0` when global `dword_7D01A0 >= 95`; otherwise it returns `0.75 + 0.01 * (dword_7D01A0 - 70)`.
- Its only recovered direct callers are the profile parser `sub_424080`, `AISteeringCorrection_00426CF0`, and `AIAbility_00429470`.
- `AIAbility` writes the returned scalar to its `+0x457C` working field in normal state, or `0.75 * scalar` in the two recovered exceptional state tests.  `AISteeringCorrection` separately consumes the same helper in its immediate correction path.

## SDK boundary

The global source field's UI/options ownership and supported range are not proven by this static slice.  The formula is reliable telemetry, but it is not yet a per-driver writable SDK parameter.

# 2026-08-18 — Traffic pointer limits a longitudinal correction intermediate

## Verified facts

- `AISteeringCorrection_00426CF0` tests the current vehicle's `+0x45FC` before its correction calculations.  When nonzero, it sets working cap `+0x457C = 0.75 * AIDifficultyScalar()`.
- At the function end, when global `byte_5C3160` is clear, it clamps `+0x4434` down to that `+0x457C` cap.  When the global is set, the alternate cap is `min(+0x4434, min(+0x44B8, 1.0))` instead.
- The same routine is called by `AIMainUpdate` after the normal racing-line/steering work and before the next controller cycle; `AIMainUpdate` commits `+0x4434` to physical field `+0x357C` on its normal path.

## Consequence

A selected `+0x45FC` interaction record has a direct, recovered effect beyond lateral offset: it applies a difficulty-derived cap to the `+0x4434` immediate longitudinal intermediate.  This strengthens the traffic-to-control link, but does not resolve role direction or authorize writes to the pointer/intermediate.

# 2026-08-18 — Correction: exact packet encoders for the three AI command fields

## Verified facts

- In `SetupCarLightingAndRender_004C71C0`, `+0x357C` is passed to `BitfieldInsert`, not `FloatToBitfieldPack`.
- That function passes `+0x3580` to `FloatToBitfieldEncoder`.
- It represents `+0x3584` as packet bit `0x04000000`, set exactly when the field is greater than `0.01`.
- `FloatToBitfieldPack` in the same function instead receives `+0x39A0`, a separate physical engine-RPM field.

## Correction

Replace every prior statement that `+0x357C` is encoded by `FloatToBitfieldPack`.  The broader all-vehicle packet-serialization finding remains true, but exact codec provenance is `BitfieldInsert(+0x357C)`, `FloatToBitfieldEncoder(+0x3580)`, and the threshold bit for `+0x3584`.

# 2026-08-18 — Mode-2 packet steering reaches front-wheel update calls

## Verified facts

- In the packet interpreter `VehiclePhysicsTimeStep_004C73F0`, the value decoded from packet `a2+8` is clamped to `[-1,1]` and stored at its physics object `+0x1040`.
- The function multiplies that decoded value by physics field `+0x1044`, then passes the product as the fourth argument to `SuspensionParamUpdate` for wheel indices 0 and 1.  Indices 2 and 3 receive `0.0` as that argument.
- `SetupCarLightingAndRender` is the recovered producer of that packet field from vehicle `+0x3580`; `VehiclePhysicsTimeStep` is reached through `TeamColorLoader` in the dispatcher’s mode-2 route.

## Boundary

This proves a packet-encoded steering-to-front-wheel physical-update chain for mode 2.  It does not prove that all normally AI-controlled vehicles take mode 2, nor that an SDK write to `+0x3580` is safe across other dispatcher modes.  The universal steering-action blocker remains, but is now narrowed to mode coverage/ownership rather than an absent mode-2 consumer.

# 2026-08-18 — Dispatcher mode field has only constructor/session-transition writers

## Verified facts

- `VehiclePhysicsModeDispatcher_004E4930` branches on vehicle `+0x32BC`: `0` calls pit update plus `VehiclePhysicsIntegrationStep`; `1` calls pit update plus `PhysicsIntegrationStateMachine`; `2` calls the `TeamColorLoader -> VehiclePhysicsTimeStep` packet route.
- `PhysicsTireSystemConstructor_004E4500` initializes `+0x32BC` to `-1`.
- The only other recovered writer is `SessionStateTransition_004EF5A0`, which replaces `+0x32BC` with its `a2` argument.  On a transition to value `1`, it also clears the vehicle waypoint pointers `+0x4354/+0x4358` and calls `AISpeedDeltaSetter`.

## Boundary

The raw caller arguments that assign modes 0/1/2 across a normal AI race have not been recovered.  Static evidence therefore supports the dispatcher matrix and the mode-2 steering chain, but not an assertion that a particular AI lifecycle always uses one mode.

# 2026-08-18 — Pit-state branch suppresses normal AI commands and forces a stop command

## Verified facts

- `AIMainUpdate` runs its normal route (`AIRacingLine`, `AISteering`, `sub_426100`, `AISteeringCorrection`, gear logic) only when controller state `+0x4510` is neither 4 nor 5.
- State 4/5 instead executes its pit/return gate.  If the gate does not complete, the function writes final physical command fields `+0x3580 = 0`, `+0x3584 = 1`, and `+0x357C = 0` before return.
- On the normal route, the shared final commit is `+0x3580 <- +0x442C`, `+0x3584 <- +0x4438`, and `+0x357C <- +0x4434`.

## Consequence

Read-only AI command telemetry must expose controller state.  During pit/return state 4 or 5, the ordinary planning intermediates are not the active output source; the static code forces the explicit neutral/one command triple instead.

# 2026-08-18 — Team peer is a same-TEAM active vehicle and feeds a race fuel gate

## Verified facts

- During `AIDriverStructInit_00424790`'s full initialization path, the current vehicle's TEAM string at linked vehicle `+0x46B8` is compared with every active `dword_7C54F0[i]` record's `+0x46B8`.  A non-self match is stored as the active vehicle pointer at current `+0x45F8`.
- `RaceStructInit` initializes `+0x45F8` to zero.  `AIDriverRandomSelector` clears it only when its supplied vehicle pointer equals the stored peer.
- `AIAbility_00429470` is the substantive recovered consumer.  When `+0x45F8` is nonzero and session is race (`dword_7C56A4 == 7`), it tests `FuelMultiplierValue(current) < 2`, then `0 < FuelMultiplierValue(peer) < 3`, and both `FuelWeightLimitCheck(peer)` and `FuelWeightLimitCheck(current)` false; only then it calls `ForcePitExit(current)`.

## Boundary

This is an exact same-team pointer and a coupled race fuel/pit gate, not a generic opponent pointer or a safe command field.  The final gameplay names of the two fuel helpers require their own physical-consumer mapping.

# 2026-08-18 — `TRACKAGGRESSION` is baked into AISteering candidate-space constraints

## Verified facts

- `sub_424080` initializes `+0x44F8` to `1.0`, replaces it from `TRACKAGGRESSION` if present, then writes `max(0.01, flt_7D017C * +0x44F8)` back to the same field.  Thus downstream code sees the scaled/floored value, not the raw profile number.
- `AISteering_004270A0` is the only recovered downstream consumer.  For an active candidate it computes `v167 = 4.0 - +0x44F8`; uses `(2.0 - +0x44F8)` twice in its candidate threshold `v156`; and floors that threshold at `20.0 - 10.0 * +0x44F8`.
- These values take part in candidate rejection, lane-bound adjustments, and the mode-selection path that can reach the `Overtaking` calls.  They are evaluated inside the per-candidate steering loop.

## SDK consequence

`TRACKAGGRESSION` is a live static planner/traffic parameter after initialization, not a generic overall AI-speed parameter.  Its source global `flt_7D017C` and profile value are baked together at parser time, so any future action API must model initialization timing and preserve the `0.01` floor.

# 2026-08-18 — Parser transforms the core ability inputs before controller use

## Verified facts

`sub_424080` applies these raw static transforms after profile lookup (where `Q`, `R`, `Rain`, and `Passing` are profile values):

| Input | Stored field and parser transform |
|---|---|
| `QUALIFYINGABILITY` | `+0x44C0 = (22 - Q) / 22` |
| `RACEABILITY` | First stores raw `R`; then `+0x44F4 = (1 - .01R) * flt_5EA3D8`, `+0x44D8 = .67 * (1 - +0x44F4)`, `+0x44D4 = (22 - .67R) / 22`, and finally `+0x44C4 = (22 - R) / 22`. When `dword_7D01A0 < 100`, the final `+0x44C4` is additionally multiplied by `(0.01*dword_7D01A0)^2`. |
| `RAINABILITY` | `+0x44C8 = .01 * Rain * flt_5EA3D8`; `+0x4580 = 1 - flt_8AFEE8 * +0x44C8`. |
| `PASSING` | `+0x44CC = min(1.0, .9 + .001 * Passing)`. |

## Boundary

These are initialization-time numeric transforms, not license to write derived fields independently.  Downstream static consumers have been recovered for the principal fields, but the ownership/range of the globals remains outside a safe per-driver write contract.

# 2026-08-18 — Correction: race `Overtaking` also has a same-team fallback path

## Verified facts

- `Overtaking_0042AF70` receives current record `this`, candidate active record `a2`, and mode `a3`; when it accepts, it writes `a2` to current `+0x45FC`.
- In race, a candidate whose linked vehicle `+0x403C` is greater than current `+0x403C` takes the ordinary accept route.
- If that lap comparison fails, the routine does **not** universally reject.  It continues only when `a2 == current+0x45F8` (the same-TEAM peer recovered above).  It then accepts when either its linked-vehicle progress/flag tests pass: one condition compares linked `+0x48A8` with current lap `> 3`; the other is the exact paired flag conjunction at current `+0xCD4/+0xD14/+0xD18` and candidate `+0xCD4/+0xD14/+0xD18`.
- Any accepted path still requires current `+0x3D6C != 2` and `+0xE64 > .001` before it writes `+0x45FC` and raw offset `+3.0` for mode 2 or `-3.0` otherwise.

## Correction

Retract the previous universal race claim that the writer is selected only against a lap-ahead candidate.  That is the ordinary branch, but the recovered same-team fallback is also a valid writer path.  This further rules out a universal attacker/defender/lapped role label for `+0x45FC`.

# 2026-08-18 — Current static readiness ledger (supersedes earlier blocker summaries)

## Strong static coverage

- Profile parsing, derived ability transforms, initialization defaults, same-TEAM peer linkage, start-event table, and update cadence.
- Waypoint refresh, racing-line / candidate steering loop, traffic selection writes, difficulty/traffic longitudinal caps, and normal versus pit command commits.
- Team fuel gate, pit controller entry/return protocol, simulated-lap performance model, and lap/timing race sorting.
- Gear request-to-physics application protocol; packet steering decode to mode-2 front-wheel update calls.

## Remaining static blockers for a direct writable core-AI SDK

1. Recover instruction-level call setup at `AISteering -> Overtaking`; Hex-Rays still omits the candidate argument despite the callee requiring it.
2. Recover the omitted normal downshift continuation at `JUMPOUT(0x4F62E6)`.
3. Prove normal AI dispatcher-mode assignments and the physical consumer chains for modes 0/1; mode 2 alone is insufficient for a universal steering action.
4. Recover a downstream static consumer for parsed `SCRIPT` (`+0x44E0`), or obtain a more complete static corpus that can prove its ownership.
5. Resolve left/right sign and human attacker/defender/yield intent without relying on decompiler names; raw code currently supports only geometry, gates, and raw signed offsets.

Until every item is resolved and independently validated, the safe SDK surface remains telemetry/configuration evidence rather than direct universal control writes.

# 2026-08-18 — Gear decision preconditions are recovered up to the omitted downshift tail

## Verified facts

- `PhysicsGearShiftLogicWithThresholds_00426330` returns immediately while `+0x3A10 > 0`.
- Controller state `+0x4510 == 6` requests gear `-1` when current gear `+0x39FC` is not `-1`; AI mode `+0x3D6C == 2` requests gear `0`.
- Otherwise, its recovered upshift path applies when `+0x3A18 < +0x39A0`.  It additionally requires both `+0x37CC` and `+0x38C4` above `0.8` unless current gear is `0` or `-1`; then, if current gear is below `+0x3A04`, it requests current-plus-one.
- The unrecovered `JUMPOUT(0x4F62E6)` is reached only when the upshift comparison does not take that path and current gear is greater than one.

## Boundary

The downshift *entry conditions* are now bounded, but its requested target and all downstream branches remain absent from the static corpus.  Gear remains a request-only telemetry/control protocol, not a complete writable action surface.

# 2026-08-18 — `+0x357C` packet bits still lack a matching recovered decoder

## Verified facts

- `BitfieldInsert_004B29B0`, the exact encoder used by `SetupCarLightingAndRender` for `+0x357C`, quantizes `value * 31` and replaces packet word-11 bits `12..16`.
- In the recovered mode-2 packet interpreter, `VehiclePhysicsTimeStep` calls `BitfieldExtract_004B2A30`, but that helper returns packet word-11 bits `8..11` minus one.  It is not the inverse of `BitfieldInsert` and does not decode its bit range.
- `VehicleSetupDataCopy` receives that bits-8..11 result only in the interpreter's object-mode-2 branch; it copies pose/setup state and stores the result at physics `+0x39F0`.

## Consequence

The packet producer proves serialization of `+0x357C`, but the available mode-2 decoder does not establish a terminal physical consumer for its encoded bits.  Do not infer throttle/drive semantics or widen the SDK action surface from the packet format alone.

# 2026-08-18 — `+0x3584` has a closed mode-2 packet encode/decode loop

## Verified facts

- `SetupCarLightingAndRender` sets packet bit `0x04000000` precisely when vehicle `+0x3584 > .01`.
- `VehiclePhysicsTimeStep` tests that same packet bit and writes its own `+0x3584` to exactly `1.0` or `0.0`.
- This interpreter remains exclusive to the mode-2 packet route.  The raw static corpus still does not prove the final physical effect of that physics-object field in modes 0/1.

## Consequence

The binary state transport for `+0x3584` is completely recovered for mode 2; its user-facing brake/pedal label and universal write safety remain unproven.

# 2026-08-18 — `+0x3580` has an exact reversible mode-2 packet codec

## Verified facts

- `FloatToBitfieldEncoder_004B2A40`, used for `+0x3580`, stores `((int)(value * 63) - 64) & 0x7F` in packet word-11 bits `0..6`.
- `BitfieldToFloatConversion_004B2A80`, used at the start of `VehiclePhysicsTimeStep`, returns `((packetWord11 & 0x7F) - 64) / 63`.
- That decoded value is clamped to `[-1,1]`, stored at physics `+0x1040`, and drives the mode-2 first-two-wheel `SuspensionParamUpdate` argument already documented above.

## Consequence

For mode 2, `+0x3580` has a complete AI-write → packet codec → front-wheel-update chain, with expected 1/63 quantization.  This is stronger than a mere serialization finding, but it still does not prove all normal AI vehicles use mode 2 or make the field universally writable.

# 2026-08-18 — `CRASH` and `COMPLETEDLAPS` feed a discrete outcome path

## Verified facts

- `EngineFailureCheck_004BEC55` calls `AICollision_004BEF60` while advancing simulated vehicle/lap state.  If `AICollision` returns zero, the caller advances lap/timing fields and invokes `AIDriverSorting`.
- If `AICollision` returns nonzero, the caller emits `ProgressBarEventEncode(..., 4, 26, 1, ...)`, chooses an outcome byte (fixed `6` for return `1`; random bucket `0..9` for return `2`), and passes it to `PitCrewStateMachine`.
- `AICollision`'s `CRASH` and `COMPLETEDLAPS` formulas therefore influence this discrete outcome/handling path.  They are not direct inputs to the immediate racing-line, throttle/brake, or steering controllers.

## Boundary

The final gameplay meaning of outcome bytes `0..9` requires the downstream pit/incident consumer chain.  Do not collapse these configuration keys into a single named “crash probability” SDK knob.

# 2026-08-18 — Correction: `STARTSTALLS` is also unsupported by recovered static consumers

## Verified search result

- `STARTSTALLS` parses to vehicle `+0x44BC` in `sub_424080`.
- Canonical offset evidence lists that parser as the only recovered writer and reader.
- Raw-corpus searches for decimal byte offset `17596` and for the offset token found no downstream function access.

## Correction

Earlier wording that treated `STARTSTALLS` as a recovered start-event probability consumer overclaimed.  The parser mapping is established, but this corpus contains no direct consumer.  Like `SCRIPT`, it is an unsupported/unknown configuration input, not a no-op.

## Ledger correction

The configuration coverage gap is `STARTSTALLS` **and** `SCRIPT`; all other parsed driver inputs have at least one recovered consumer path.  Add `STARTSTALLS` to the exact static-blocker item for indirect consumer recovery.

# 2026-08-18 — Superseding correction: `STARTSTALLS` has an initialization-time consumer

## Verified facts

- The same raw parser, `sub_424080`, consumes `+0x44BC` after parsing it.  In race session 7 with `dword_7CEA5C > 0` and `<= 2`, it computes `+0x44BC * 100` and compares it against `rand % 10000`.
- This makes the recovered trigger probability `STARTSTALLS / 100` per parser invocation in that session/state gate.
- On trigger, a second random draw selects either `+0x4144 = 0, +0x4148 = 5` (nine of ten outcomes) or `+0x4144 = 0, +0x4148 = 4` (one of ten outcomes).
- The alternative `dword_7CEA5C == 3` branch reads named race-event data (`STALL`, `STALLDNS`, `SUSPENSION`, `BRAKES`, `ENGINE`, `GEARBOX`) into the same initialization event-record area; it is distinct from the `STARTSTALLS` probability branch.

## Superseded correction

The preceding “no recovered consumer” conclusion was wrong because the parser is both writer and initialization-time consumer.  `STARTSTALLS` is no longer a configuration coverage gap.  The remaining untraced configuration input is `SCRIPT` only.

## Boundary

The exact gameplay semantics of state values 4 and 5 need their downstream state-machine consumers; do not call either value a specific physical failure solely from this branch.

# 2026-08-18 — `STARTSTALLS` special states and scripted component failures resolved

## Verified facts

- The five records beginning at `+0x4144` are `(lapKey, eventKind)` integer pairs: `DriverSetupParamLookupByID_0042AEB0` searches `+0x4144, +0x414C, ...` for a key and returns the immediately following word at `+0x4148, +0x4150, ...`.
- In the `dword_7CEA5C == 3` parser branch, named `RACEEVENTS` map to `eventKind`: `ENGINE=0`, `BRAKES=1`, `GEARBOX=2`, `SUSPENSION=3`, `STALL=4`, and `STALLDNS` (plus one alternate string) `=5`.  The parser converts the event's configured lap value into `lapKey`; unknown event names set its key to `-1`.
- At a session-state transition, `AIMainUpdate_00424E70` examines all five pairs when the recovered gates `vehicle+0x45F4` and `byte_5C3160` hold.  A `(0,5)` pair calls `ConditionalGate(this+12)` and, if `+0x4068` is zero, sets it to `7`, `3`, or `8` from `rand % 4`.  A `(0,4)` pair calls the same gate and schedules `+0x4168 = now + 10 + (rand & 0x14)`.
- On the later push-lap path, each pair whose `lapKey == vehicle+0x403C` and `eventKind < 4` writes a bounded random value into `vehicle+0x3D70 + 4*eventKind`.  Thus scripted `ENGINE/BRAKES/GEARBOX/SUSPENSION` events feed the four component-life slots; they are a separate path from kinds 4 and 5.
- `AICollision_004BEF60` uses the same lookup only in `dword_7CEA5C == 3`: a matched current-lap key returns `2`, which makes `EngineFailureCheck_004BEC55` select a random outcome byte and call `PitCrewStateMachine`.  The lookup's returned kind is not otherwise inspected by this caller.

## Correction

The previous boundary that left state values `4` and `5` semantically unknown is too broad.  Static code names their parser sources and recovers their separate immediate actions: kind 5 is the zero-lap `STALLDNS` special case that assigns `+0x4068`; kind 4 is the zero-lap `STALL` special case that schedules `+0x4168`.  The final presentation/gameplay meaning of the resulting reason codes and scheduled timeout remains outside this recovered chain.

# 2026-08-18 — SDK release boundary: steering is still not a canonical field

## Verified facts

- The canonical SDK catalogue returns `ThrottleFactor +0x357C` and `BrakeFactor +0x3584` as `CONFIRMED float` fields.
- The same catalogue has no canonical entry for `SteeringFactor` or for the AI-written `+0x3580` field, despite raw `AIMainUpdate` writing `+0x3580` every normal controller tick.
- `VehiclePhysicsTimeStep_004C73F0` is reached only by the mode-2 packet route (`VehiclePhysicsModeDispatcher_004E4930 -> TeamColorLoader_004F03E0 -> VehiclePhysicsTimeStep`), and it has a separate recovered `+0x3580` access under its own object identity.  This does not prove that the AI's normal local `+0x3580` commit is consumed by that packet route.

## SDK consequence

Do not add a writable steering field or claim a direct core-AI SDK yet.  The missing all-local-vehicle consumer chain is a concrete contract blocker, not merely a field-name gap.

# 2026-08-18 — Per-vehicle AI controls enter a packed control-event route

## Verified facts

- `IterateVehicles_004B3BA0` calls `TireTemperatureSimStep_004C77D0` once for every active `dword_7C54F0[i]` vehicle record.
- On its recovered timing gate, that per-vehicle function calls `SetupCarLightingAndRender_004C71C0(this, packet)`.  Despite its legacy name, the raw function packs `this+0x357C`, `this+0x3580`, and `this+0x3584` into the packet: `FloatToBitfieldPack` receives `+0x357C`, `FloatToBitfieldEncoder` receives `+0x3580`, and a packet bit is set when `+0x3584 > .01`.
- `AIMainUpdate` writes those same three fields before its normal return.  Therefore all active AI vehicles have a recovered post-controller, per-vehicle control-packet encoding path.
- `DriverInputController_00451720`, called separately after the main substep loop, reads `dword_7C54E0 + 0x3580` and transforms it into an input-device command.  `SetPlayerVehicleIndex_0042BBD0` sets that global from a player slot; `CameraDirectorResetInit_0040DA30` also changes it with the selected camera vehicle.  It is therefore a selected/player-vehicle consumer, not an all-AI consumer.

## Boundary

This closes the former claim that no local steering route was visible after the AI write: an all-vehicle serialization route is proven.  The separately recovered input-device consumer is selected-vehicle-only.  The packet's final local-physics consumer remains unproven, so this still does **not** authorize a writable steering SDK field.

# 2026-08-18 — AI gear request reaches the physics-side application protocol

## Verified facts

- `PhysicsGearShiftLogicWithThresholds_00426330` reads canonical `CurrentGear +0x39FC` and sends a request through `RaceStartCountdownStateUpdate_004EF930`; no direct AI write to current gear occurs.
- The request function stores its requested gear in `+0x3A08`, clears/uses the intermediate `+0x39F0`, and arms `+0x3A04` from either `+0x39FC` or `+0x3A00` depending on request direction.
- Physics-side `SuspensionSpringDampingRateReset_004E4F40` calls `BrakeCoolingPostTreatment_004E5080` while `+0x3A04 > 0`.  That routine decrements the timer by the physics delta `+0x34A8`; on expiry it copies `+0x3A08` into `+0x39F0`.  The reset path then observes the changed `+0x39F0` and applies its gear-dependent ratios/curves.
- `SuspensionAndWheelPhysics_004E5F60` is the sole recovered writer of `CurrentGear +0x39FC`; it also initializes the request/timing fields.  This confirms the AI-to-physics ownership boundary.

## Boundary

The normal upshift condition is recovered in `PhysicsGearShiftLogicWithThresholds`; its normal downshift continuation is still the missing `JUMPOUT(0x4F62E6)`.  The protocol is therefore mapped, but the full shift-decision policy is not.

# 2026-08-18 — Cornering configuration reaches the racing-line score

## Verified facts

- Parser `sub_424080` maps `CORNERINGADD` to `+0x4500` and `CORNERINGMULT` to `+0x4504`.
- `AIComputePassScore_0042A780`, called from `AIRacingLine`, returns `(a2 * vehicle+0x4504 + vehicle+0x4500) * vehicle+0x4580 * vehicle+0x453C * candidate[33]` after its `TireForceSolver` preparation.
- `sub_426430` also reads both values as part of waypoint/steering refresh.  They are live inputs to planning/scoring, not unused profile metadata.

## Boundary

The decompiler does not prove a player-facing physical meaning for the score's `a2`, `candidate[33]`, or the two later multipliers.  Expose these configuration fields only as planner-score parameters, not as a simple “cornering speed” control.

# 2026-08-18 — Main-tick dispatcher scope correction

## Verified facts

- `MainGameTickUpdate_0042C690` calls `AIMainUpdate(dword_7C54F0[i])` for every active record only on each tenth 0.0025-second simulation tick (0.025 s).
- Its `VehiclePhysicsModeDispatcher(v15)` call occurs on the other ticks only under a gate on the distinguished `dword_7C54E8` record: `+0x32C8 == 0`, the global alternating-tick gate passes, and `+0x48BC` bit 3 is set.
- The raw dispatcher call has neither a per-AI-record loop nor an AI-record argument.

## Correction and boundary

This scheduler does not prove that every AI driver's `+0x32BC` mode dispatches the AI command packet.  The separately recovered all-vehicle serialization route remains valid, but normal mode-0/1 terminal command routing remains a direct-SDK blocker.

# 2026-08-18 — Per-vehicle packet scheduler boundary

`IterateVehicles_004B3BA0` calls `TireTemperatureSimStep_004C77D0(dword_7C54F0[i])` once per active record.  That function returns when `vehicle+0x32C8 > 1`; otherwise, after its session/timing gate, allocates a 432-byte slot from the `dword_8AAE64` ring and calls `SetupCarLightingAndRender(vehicle, slot)`.  This is stronger evidence for per-vehicle packet *production* than the main-tick dispatcher, but it still supplies no recovered terminal decoder for modes 0/1.  Do not conflate the ring allocation or the immediately following audio/feedback call with physics application.

# 2026-08-18 — AISteering candidate/mode provenance at `Overtaking` calls

`AISteering_004270A0` iterates five 68-byte candidate slots.  For each accepted slot, `v33` is the slot base and `v34 = *(DWORD *)(v33+0x4174)` is the compared vehicle record used throughout the geometry/progress gates.  The recovered call text remains `Overtaking(this, v86)`, while raw `Overtaking_0042AF70` writes a candidate pointer to `this+0x45FC`; thus the caller still loses an argument in Hex-Rays and cannot prove the exact machine-level candidate transfer.

The visible second argument is nevertheless constrained: `v86==2 || v86==7` reaches one call block, and `v86==1 || v86==8` reaches the other.  The immediately surrounding branches update opposite lateral bounds (`v145` versus `v146`) using `v144 ± v167`, respectively.  This proves that the mode is selected from candidate geometry/planner state and that the two call blocks are opposite lateral-resolution cases.  It does **not** establish which physical side is positive, nor prove attacker/defender/yield intent or the missing candidate ABI argument.

## Correction — call block is not lateral-offset sign

Raw `Overtaking_0042AF70` sets `this+0x4420` to `+3.0` **only** when its third argument is exactly `2`; every other accepted nonzero mode, including `1`, `7`, and `8`, sets `-3.0`.  Therefore the `{2,7}` versus `{1,8}` caller grouping must not be described as the plus/minus side grouping.  It establishes planner-case provenance only; the physical sign convention remains open.

# 2026-08-18 — Proximity-writer sign is a local cross-product test

In `OpponentProximityScanTeamRecognition_0042A7D0`, the race interaction write requires a candidate to pass `sub_4C7BD0`, be within squared planar distance `<625`, and have linked `+0x403C` greater than current `+0x403C`.  It then writes the candidate record to current `+0x45FC`.  Its sign decision is exact: it sets `+0x4420=-2.5` when `(candidateZ-currentZ)*this[+0x448C] - (candidateX-currentX)*this[+0x4484] <= 0`, otherwise `+2.5`.  This proves a signed local orientation/cross-product rule, not a world-left/world-right convention; the meaning of the current direction-vector components and coordinate handedness remains unresolved.

# 2026-08-18 — Control packing is a shared event-buffer producer, not a proven physics handoff

`SetupCarLightingAndRender_004C71C0` begins each packed record with `ProgressBarEventEncode(a2, 1, 0, 52, vehicle+0x4894, now, 0)`.  `TireTemperatureSimStep` supplies `a2` from the shared 432-byte `dword_8AAE64` ring, and raw searches show that the same ring is also allocated by UI, audio, camera, penalty, and collision producers.  The function does encode the three AI-written fields into that event record, but the corpus provides no raw path from this particular event code/ring slot to `VehiclePhysicsTimeStep` or a mode-0/1 local physics consumer.

## Correction

Treat `+0x357C/+0x3580/+0x3584` packing as a per-vehicle **control-event serialization** path only.  Do not call it a physics packet or use the independently recovered mode-2 `TeamColorLoader -> VehiclePhysicsTimeStep` decoder as its terminal consumer without an explicit producer-to-decoder link.

`InputCommandDispatchToEntities_0045F4A0` consumes the shared 432-byte ring with `SessionDataCopy/AdvanceRingBuffer`; each eligible record is forwarded to `TextureCreationWrapper(..., record, 1, entity, 2000)` (or to the global-state forwarding path).  This confirms that the ring is an event-dispatch queue.  It still does not create a local vehicle-physics consumer for the encoded AI controls, so it strengthens the separation rather than closing the output chain.

# 2026-08-18 — Normal dispatcher paths remain physically separate in the recovered corpus

For `+0x32BC==0`, `VehiclePhysicsModeDispatcher_004E4930` calls `VehiclePhysicsIntegrationStep_00441650`; for mode 1 it calls `PhysicsIntegrationStateMachine_004E4E60`.  The latter advances physics substeps through `SuspensionSpringDampingRateReset`, `sub_4E58D0`, `sub_4E51A0`, `WheelForceCalculationSpringDamperTorque`, and `sub_4E5AE0`.  These raw functions operate their physics-object state and expose no recovered transfer from the vehicle-owned AI commits at `+0x357C/+0x3580/+0x3584`.  This is evidence of a missing bridge in the current corpus, not evidence that the AI fields are ignored at runtime.

# 2026-08-18 — Passing profile lifecycle correction

`AIDriverStructInit_00424790` unconditionally sets vehicle `+0x44CC` to `1.0` before its `LOBYTE(a2)` gate.  Only when that gate is true does it call the profile parser `sub_424080`, which subsequently applies the parsed `PASSING` transform.  Therefore the parsed Passing value is not an invariant of the live struct across all initializer call modes: an initialization path with a false gate leaves/reset it at `1.0`.  This is a static lifecycle fact; the caller conditions that choose the gate still need recovery before an SDK can promise persistence.

# 2026-08-18 — Configuration coverage correction: `CRASH` is also untraced

The raw-recovery index finds `+0x44D0` (`CRASH`) written by `sub_424080` but no recovered downstream reader other than the parser itself.  Consequently, the earlier statement that `SCRIPT` was the only remaining untraced profile input was too strong.  Both `SCRIPT +0x44E0` and `CRASH +0x44D0` lack a recovered consumer in this corpus; they must remain read-only preserved configuration until a raw consumer or an explicit external-data boundary is recovered.

`COMPLETEDLAPS% +0x44DC` has the same raw-index result: parser writer only and no recovered downstream reader.  The untraced profile set is therefore `CRASH`, `COMPLETEDLAPS%`, and `SCRIPT`, rather than `SCRIPT` alone.

# 2026-08-18 — Exact `PASSING` use in the racing-line horizon

`AIRacingLine_00425920` walks up to 20 path nodes from its selected route node.  On each advancing node, after `TireForce`, it updates its remaining horizon `v46` as `v46 - node[+0x3C]/v46 * vehicle[+0x44CC] * nodeScore * 0.915`, with the existing `v46<=1` / `<.5` zeroing guards.  Thus the parsed `PASSING` normalization participates directly in horizon depletion/route selection, not merely in generic telemetry.  Its effect is coupled to node geometry and `AIComputePassScore`; do not simplify it to a standalone pass probability.

# 2026-08-18 — `+0x4510` normal-state dispatch mapped

After the normal planner sequence, `AIMainUpdate_00424E70` dispatches `+0x4510`: states `0` and `6` call `SteeringAngleController`; state `1` calls `sub_4258C0`; state `2` calls `FieldZeroSetter` and returns; state `3` compares a route-distance square with `+0x461C` and may return to state `0`; state `7` forces the three controller intermediates to `+0x442C=0`, `+0x4428=1`, `+0x4424=0`, returning to state `0` below speed `.2`.  States `4/5` remain the separate pit/return branch.  These are recovered state transitions/command defaults, not final physical pedal or steering semantics.

`SteeringAngleController_00425670` refines the `0/6` path: state `6` computes the wrapped heading error from the primary route node and advances to `7` when `|error|<.5` or a timeout passes.  State `0` computes the wrapped velocity-heading error, increments/decrements a counter at `+0x446C` by its magnitude/speed gate, and on threshold `+0x4558` may request one lower gear, clear AI state flags, and enter state `1`.  Its four-second timer can toggle `0↔6` and snapshots current position/heading.  Thus states 0/6/7 are a route-alignment/recovery submachine, not independent driving styles.

`sub_4258C0` defines state `1`: it forces `+0x4428=1` and `+0x4424=0`; when speed `+0x4438<4`, or both `+0x37CC` and `+0x38C4` exceed `.9`, it changes to state `2`.  State `2` then executes `FieldZeroSetter` and returns from `AIMainUpdate`.  This closes the state-1→2 controller sequence but does not assign player-facing brake/throttle labels to those intermediates.

## Correction

`FieldZeroSetter_00425660` only writes `+0x4510=0`; it does **not** clear a controller intermediate.  State `2` is therefore a one-tick state-reset return, preserving the state-1-written `+0x4428/+0x4424` values until another path overwrites them.

# 2026-08-18 — Exact `+0x442C` target computation

`sub_426100` computes the signed normalized angular error between the current pose and a route-node-derived look target, divides by vehicle `+0x44B4`, flips the sign in state `6`, then slew-limits `+0x442C` by `±.1` per AI tick and clamps it to `[-1,1]`.  `AIMainUpdate` later commits this field to `+0x3580`.  This is an exact planner-to-signed-command calculation; the terminal physical consumer of `+0x3580` remains unproven, so retain the field as telemetry rather than writable steering ABI.

# 2026-08-18 — Longitudinal intermediate correction chain

`AISteeringCorrection_00426CF0` modifies the two longitudinal intermediates before their final commit.  It attenuates `+0x4434` by `(1-|+0x442C|*.7)` when `|+0x442C|>.1` and speed `+0x4438>20`; blends the two physical feedback values at `+0x37CC/+0x38C4`; may move `+0x4434` toward `SuspensionRatioClamp`; and writes a derived value to `+0x4028`.  Its distance-window branches then set `+0x4434` and `+0x4438` from `BrakeThermalModel`/`TireGripCoefficient`.  Finally it caps `+0x4434` by `+0x457C` (or `min(+0x44B8,1)` under `byte_5C3160`).  `AIMainUpdate` commits `+0x4434 -> +0x357C` and `+0x4438 -> +0x3584`.

This is an exact planner/feedback/cap chain into committed control fields.  It still does not prove vehicle-physics meanings for those fields, so preserve the intermediate names rather than calling them pedals.

# 2026-08-18 — Push-lap consumption of ability/rain transforms

`AIPushLap_0042A180` consumes parser-derived values.  Outside race session 7, it increases `+0x453C` by `+0x44F4 + +0x44D8` and caps it at `min(lapNumber,10)*.003 + +0x453C` as evaluated before that update.  It also computes `max(.5, 1 - flt_8AFEE8 * +0x44C8)` and writes the result to `+0x4580`.  Thus the RaceAbility-derived pair and RainAbility transform feed live pace/planner multipliers through this periodic push-lap path; the global wetness scalar's ownership and player-facing units remain unproven.

# 2026-08-18 — `AIClearStateFlags` naming correction

Raw `AIClearStateFlags_0042AE00` is only `memset(this+0x4354, 0, 0x50)`: it clears the 20-entry 4-byte route-node pointer list.  It does not clear general AI flags, the interaction pointer, or control fields.  Interpret its calls as route-list invalidation/rebuild preparation, and retract any broader “clear AI state” claim based only on the legacy name.

# 2026-08-18 — Interaction-pointer reset lifetime

`ResetDriverGridState_004C6E80` iterates every active record and calls `AIDriverRandomSelector(record, resetVehicle)`.  That helper clears the record's `+0x45FC` only when it equals `resetVehicle`; it then calls `LateralForceTorqueCalculation(record,100)` and clears `+0x4420`.  It separately clears `+0x45F8` if it equals the reset vehicle.  Therefore a reset/removal of the selected vehicle actively invalidates both interaction and teammate pointers, and removes the corresponding lateral offset; it is not a passive dangling-pointer cleanup.

# 2026-08-18 — Race-order write transaction

`AIDriverSorting_004BF390` asks `ConditionalFieldSetter_004BC2F0` to update its ranking fields.  The helper reads the field at its local `+0x2C`, and only when the value changes calls `AIDriverStateTransition(global, vehicle, oldRank, newRank)` before storing the new rank.  In the sorter, the helper's object is `vehicle+0x4034`, so the stored rank is `vehicle+0x4060`.  This proves rank changes are conditional, transition-notified writes following the sorter comparator; neither the notification nor an interaction-pointer event independently proves a physical completed pass.

`AIDriverStateTransition_00419120` itself performs no rank write: under global/race gates it constructs a record and calls `InsertDriverTableEntry`, then stores a per-driver last-notified rank.  It is a conditional notification/presentation side effect of a rank change, not the sorting authority or a causal overtake detector.

# 2026-08-18 — Pit-request primitive narrowed

Raw `ForcePitExit_0042A110` does not directly change pit state.  It conditionally calls `StateConditionalAction(vehicle+0x32C4)` and then `AIStateFlagSetter(1)`, whose only write is `vehicle+0x454C=1`.  In race it skips this when the current lap is the last lap, except under its helper/state gates; outside race it performs the calls directly.  Treat `+0x454C=1` as the recovered request flag, not proof of an immediate pit exit.

## Correction

`StateConditionalAction_004A5E40` receives the F1CPitMachine at `vehicle+0x32C4`; when its local `+0x184` is `0` or `4`, it calls `StateChangeNotify(...,1)`.  ForcePitExit therefore can immediately request pit-machine state `1` as well as set AI `+0x454C=1`.  It still does not directly prove a completed physical pit exit; the pit-machine transition and AI request remain distinct from later vehicle motion.

# 2026-08-18 — Phase-change random factor

When `AIMainUpdate` detects its phase change, it calls `AIRingBufferFieldInit_00424C80`.  That helper writes `+0x4448 = .15 + .15*randomTable[dword_8AAE70++] - .1*dword_7D01A0`.  The value is a phase-change random/difficulty-derived factor; it is not an event ring buffer.  Keep it read-only until its downstream consumers and global difficulty ownership are fully recovered.

# 2026-08-18 — Max-speed setter boundary

`ParameterValueSetter_0042ACD0` is the exact sole-field setter for vehicle `+0x4538`: it writes the supplied integer as float, except argument `18`, which writes global `flt_8ACFB4`.  Raw callers include AIAbility and the per-vehicle command paths.  This maps a bounded game-owned speed-governor primitive, but its unit/range, arbitration with pit state, and terminal physics consumer are outside this static-only report; do not promote it to a public writable core-SDK action yet.

# 2026-08-18 — Per-vehicle command dispatcher boundary

`AICommandMessageQueueDispatcher_00424CD0` processes a vehicle-local queued `(command,param)` pair, then synchronously calls `CommandQueueResponseHandler` before clearing its queue index.  Direct cases: command `1` schedules `+0x414C=now+2`; `4` and `5` route through `sub_4A46F0` with opposite arguments; command `15` clears/sets multiple pit-related fields and invokes `ParameterValueSetter(18)`.  These are game-internal stateful commands, not a safe public command API: the response handler, queue capacity/duplicate policy, and session gates remain part of the contract.

# 2026-08-18 — Interaction-reset helper naming correction

Raw `LateralForceTorqueCalculation_0042AD00` only writes `+0x453C = .01 * a2 * +0x44F4`; it does not apply a lateral force or torque.  Therefore when `AIDriverRandomSelector` invalidates a matching `+0x45FC`, its call with `a2=100` restores/recomputes `+0x453C` from `+0x44F4`, while its separate direct write clears `+0x4420`.  The interaction-reset path couples pointer invalidation to a pace-multiplier recomputation; do not infer physics from the legacy helper name.

# 2026-08-18 — `+0x453C` periodic ownership

`AIMainUpdate` calls `AIAbility_00429470` every four seconds.  In normal race session handling, that function moves `+0x453C` down by `.01` toward `+0x44F4` when `+0x4508==0`, otherwise up by `.01` toward `+0x44F4 + +0x44D8`; if `+0x450C` is nonzero, a random gate makes an additional bounded `±.01` adjustment.  It also overrides the multiplier to `.85 * +0x44F4` in one recovered state.  Thus `+0x453C` is internally re-owned on a fixed cadence; no direct writable SDK contract is safe without coordinating this updater.
### 2026-08-18 — control-output packet boundary corrected

**Verified facts (raw Hex-Rays):**

- `SetupCarLightingAndRender_004C71C0` serializes vehicle `+0x357C`, `+0x3580`, and `+0x3584` into its `a2` packet: `+0x357C` enters `BitfieldInsert`; `+0x3580` enters `FloatToBitfieldEncoder`; `+0x3584 > 0.01` controls packet bit `0x4000000`.
- `VehiclePhysicsTimeStep_004C73F0` consumes an opaque `a2` packet. It decodes and clamps one control value to `[-1, 1]`, writes it to `vehicle+0x1040`, and, in mode `vehicle+0x32C8 == 2`, copies that same value to `vehicle+0x3580`. This is direct raw evidence that `+0x3580` is a steering input/cache, not an unclassified control field.
- The same consumer decodes packet bit `0x4000000` and writes `vehicle+0x3584` to exactly `1.0` or `0.0`. Thus `+0x3584` is the packet-level brake state, even though the AI calculation that precedes its serialization can be fractional.

**Boundary still open:** raw code does not prove that `SetupCarLightingAndRender`'s packet object is the same `a2` consumed by `VehiclePhysicsTimeStep`, nor that this packet path is the authoritative local-physics path rather than presentation/network synchronization. It therefore improves field semantics but does **not** yet prove the final AI-to-simulation control bridge or authorize direct writes.

**Codec verification:** `SetupCarLightingAndRender` passes `a2+2` (a DWORD pointer) to `FloatToBitfieldEncoder_004B2A40`; its word 11 is packet address `a2+0x34`. The encoder stores `int(63*vehicle[+0x3580])-64` in its low 7 bits. `VehiclePhysicsTimeStep` passes byte address `a2+8` to `BitfieldToFloatConversion_004B2A80`; its word 11 is the same packet address `a2+0x34`, and it returns `((bits[0:6])-64)/63`. The two raw routines are exact inverses. This confirms the `+0x3580` steering representation and quantization when a packet crosses that boundary; it does not establish packet-object identity across the two separately recovered callers.

# 2026-08-18 — Shared control-event queue lifecycle and its mode-2 separation

## Verified raw facts

- `GamePostMainLoop_0042D8A0` orders the relevant work in one loop iteration as: `MainGameTickUpdate`, then `IterateVehicles`, then `SessionScoringUpdate`, then `CollisionResponseStatus`, then `BufferReset(&dword_83EE60)`.  `IterateVehicles` calls `TireTemperatureSimStep` for each active `dword_7C54F0[i]`, and the latter allocates a 432-byte `dword_8AAE64` slot before calling `SetupCarLightingAndRender`.
- `CollisionResponseStatus` calls `InputCommandDispatchToEntities` when its session-state field is nonzero.  That consumer calls `SessionDataCopy(&dword_83EE60)`, repeatedly calls `AdvanceRingBuffer(&dword_83EE60, local432)`, and forwards each eligible copied record to either `sub_465300` or `TextureCreationWrapper`.  `AdvanceRingBuffer` copies a record to its caller-provided local buffer and advances its reader by 432 bytes.
- At the end of the same main-loop iteration, `BufferReset(&dword_83EE60)` walks every remaining 432-byte entry through `sub_4B3400`, decrements the pending count, and resets the three queue pointers to the empty base.  The shared control-event slot is therefore a bounded per-loop event-queue object; no recovered queue consumer calls `VehiclePhysicsTimeStep` or either normal mode-0/1 integrator.
- The mode-2 `VehiclePhysicsTimeStep` route has a distinct input object.  `TeamColorLoader_004F03E0` allocates `int v3[108]` (432 bytes) on its own stack, passes that local buffer to `UtilityFunction_3D50`, then passes the same local-buffer address as `VehiclePhysicsTimeStep`'s `a2`.  `UtilityFunction_3D50` in turn passes that `a3` buffer only to its own collision/integration helpers.  It neither receives nor reads `dword_8AAE64`/`dword_83EE60`.
- `VehiclePhysicsModeDispatcher_004E4930` itself has only a scalar-time argument.  In mode 0 it invokes `VehiclePhysicsIntegrationStep` with global timing state; in mode 1 it invokes `PhysicsIntegrationStateMachine(a2)`; in mode 2 it invokes `TeamColorLoader(a2)`.  Its raw body neither accepts a 432-byte event record nor reads `+0x357C/+0x3580/+0x3584`.

## Evidence-backed inference

The mode-2 stack packet and the shared control-event queue are separate recovered object-lifetime domains: matching size and compatible bit layout do not establish object identity.  The post-producer queue drain also leaves no recovered forwarding step from the AI control-event record into a normal local-physics dispatcher.

## SDK boundary

This eliminates the current event ring, its ordinary entity-dispatch consumer, and the independently populated mode-2 stack packet as candidates for a proven universal AI-control-to-normal-physics bridge.  It does not prove that a bridge is absent elsewhere in the executable; continue with raw paths that can read vehicle control fields or feed normal mode-0/1 physics objects.

# 2026-08-18 — Normal mode-1 wheel-physics offsets do not consume the AI command slots

## Verified raw facts

- The mode-1 `PhysicsIntegrationStateMachine_004E4E60` calls `sub_4E5AE0` once per selected substep.  That function sets `v11 = vehicle+0x3580`, calls `sub_4E43D0(v11)`, then repeats three times with `v11 += 62` floats (248 bytes).  Thus the matching numeric offset begins a four-lane wheel-data region in this path.
- `sub_4E43D0` does not read its base `this[0]`: its first read/write is at `this[4]`, and its remaining inputs are at indices 9, 12, 13, 21, 22, 24, 27, and 28.  Accordingly, the first invocation does not read vehicle `+0x3580`, and none of the four invocations reads the AI's `+0x3580` slot as its base value.
- `TireGripLateralForceCalculation_004E9300` also selects `vehicle+0x3580` merely as a wheel-data base (or `+0x3770` for its alternate selector) and reads `base+0x90`; it does not read `vehicle+0x3580` itself.
- In the same mode-1 path, `WheelForceCalculationSpringDamperTorque_004E5470` derives `sin`/`cos` from `vehicle+0x3574`.  The raw offset index finds only `VehicleSetupInitialization_004E49B0` and reset helper `sub_4E4790` as writers of `+0x3574`; it finds no AI writer.  Setup initializes it from globals, while the reset helper zeroes it.
- The raw direct-reader index remains: `+0x357C` is read only by `AIMainUpdate` and `SetupCarLightingAndRender`; `+0x3580/+0x3584` are read only by `AIMainUpdate`, `SetupCarLightingAndRender`, and the independent `VehiclePhysicsTimeStep` packet decoder.  No normal mode-0/1 integrator is a direct reader.

## Evidence-backed inference

Numeric overlap with the mode-1 physics region is not an AI-command transfer.  The recovered mode-1 wheel routines use adjacent or later wheel-subobject members, while the mode-1 steering geometry comes from a separately owned `+0x3574` value.  This rules out the inspected normal wheel substep as the missing direct consumer of the AI commits.

## Boundary

The authoritative normal-mode steering/longitudinal bridge is still unresolved.  Do not reinterpret the mode-1 use of a `+0x3580`-based wheel-data region as a safe writable steering ABI; continue by tracing writers of normal-mode `+0x3574` and its owning object relationships.

# 2026-08-18 — `+0x3574` normal-mode source is global physics state, not AI steering

## Verified raw facts

- `VehicleSetupInitialization_004E49B0`, called by the mode-0 branch of `VehiclePhysicsModeDispatcher`, writes `vehicle+0x3570 = dbl_7C7430`, `vehicle+0x3574 = dbl_7C74AC * dbl_7C7428`, and `vehicle+0x3578 = dbl_7C7438`.
- The only other recovered `+0x3574` writer, `sub_4E4790`, clears it together with neighbouring physics workspace values.  `PhysicsTireSystemConstructor_004E4500`, called by `RaceStructInit`, initializes `+0x32BC` to `-1` and then calls that reset helper.
- The normal mode-1 wheel-force routine reads `+0x3574` in its `sin`/`cos` calculation, but no inspected writer connects it to `AIMainUpdate` or to the AI commits `+0x357C/+0x3580/+0x3584`.

## Evidence-backed inference

The recovered source formula makes `+0x3574` a value derived from global simulation state and time in the mode-0 setup/snapshot path, not a direct AI steering command.  Its later trigonometric use can establish a physics-geometry dependency, but it does not assign a safe steering semantic or connect the AI's signed `+0x3580` output to normal mode-1 physics.

## Correction and boundary

Retract the provisional description of `+0x3574` as the normal mode-1 “steering angle input.”  Raw code establishes only its source, reset behaviour, and trigonometric consumer.  The authoritative normal-mode control bridge remains open.

# 2026-08-18 — Per-vehicle mode-1 `ThrottleBrakeOverride` is not the AI longitudinal bridge

## Verified raw facts

- `MainGameTickUpdate_0042C690` calls `sub_4EE2D0(dword_7C54F0[i] + 12)` for every active record on the same 0.025-second branch that calls `AIMainUpdate`.  In `sub_4EE2D0` case `vehicle+0x32BC == 1`, the raw function calls `ThrottleBrakeOverride_004EE230`.
- Despite its legacy name, `ThrottleBrakeOverride` reads `+0x3994/+0x3998` to form a ratio, `+0x3570`, and three values at `+0x3D48/+0x3D4C/+0x3D50`.  It writes only `+0x77C/+0x790/+0x7A4`, copying each `+0x3D48..50` source unless it equals the literal sentinel `-789.0`, in which case it substitutes the computed value.
- The helper does not read `+0x357C`, `+0x3580`, or `+0x3584`.  The surrounding `sub_4EE2D0` raw access list likewise contains none of those three AI command offsets.

## Evidence-backed inference

This per-vehicle mode-1 call is a sentinel-controlled transform for three non-AI output channels, not a transfer of the AI's throttle/brake/steering commits.  Its schedule makes it a plausible candidate by proximity, but its exact inputs exclude it as the missing bridge.

## Boundary

Do not derive longitudinal-control semantics from the helper's generated name.  The authoritative normal-mode AI-control-output path remains unresolved; the next raw audit must target a path that either directly reads the three committed fields or maps them into a distinct normal-physics object.

# 2026-08-18 — Selected-vehicle `DriverInputController` is not a universal AI terminal consumer

## Verified raw facts

- The recovered writer index for `dword_7C54E0`, the single vehicle pointer read by `DriverInputController_00451720`, contains five functions: `CameraDirectorResetInit_0040DA30`, `SetPlayerVehicleIndex_0042BBD0`, `DynMan_Restart_0042C3B0`, `NetCommPlayerSlotSync_0045FC50`, and `sub_4A00A0`.
- `CameraDirectorResetInit` assigns the global from exactly one `dword_7C54F0[cameraDirectorIndex]`.  `SetPlayerVehicleIndex` assigns one fixed vehicle-array slot and locates its active-array index.  `SetPlayerVehicleIndex_bc40` separately assigns `dword_7C54E8` from that same fixed vehicle array and stores the matching active index in `dword_7C54E4`.
- In `NetCommPlayerSlotSync`, join handling calls one of the two player-selection helpers.  During an unloading path it can instead select one eligible active vehicle by assigning both `dword_7C54DC` and `dword_7C54E0`; the raw routine then rebuilds the active vehicle-pointer array.  This is session/player-slot lifecycle code, not an all-vehicle iteration.
- `MainGameTickUpdate` calls `DriverInputController` once after its all-vehicle work.  The controller reads that one global pointer, compares related state with `dword_7C54E8`, updates its own controller state, and invokes controller virtual methods.  Its recovered call list contains no normal vehicle-physics integrator, and it is not called from the all-active-vehicle loop.

## Evidence-backed inference

The selected pointer can follow player, camera, restart, or player-slot lifecycle selection, including a non-player vehicle in a fallback case, but it denotes at most one vehicle at a time.  A once-per-main-tick controller driven by that pointer cannot be the terminal consumer for all AI records.  The exact presentation/input side effects of its virtual calls remain unclassified.

## Boundary

Exclude `DriverInputController` as the missing universal AI-control-to-normal-physics bridge.  Do not promote its selected pointer or any controller-local values to a writable AI-SDK surface.

# 2026-08-18 — Shared-event dispatch endpoints are queue/network paths, not normal simulation

## Verified raw facts

- The shared-event consumer `InputCommandDispatchToEntities_0045F4A0` forwards eligible copied records to `sub_465300` or `TextureCreationWrapper_00462250`.
- `sub_465300` either calls `FloatComputation` for a narrow header/type condition, or allocates a 432-byte heap payload, copies the variable-length record bytes with `ArithmeticComparison_3a90`, and appends a 12-byte node to one of two linked queues.  Its recovered callees contain no normal vehicle-physics integrator or physics mode dispatcher.
- `ArithmeticComparison_3a90` is the raw size-prefixed copy primitive: it copies `((header >> 8) & 0x3FF) + 8` bytes and then copies the payload word at offset `0x1AC`.
- `TextureCreationWrapper` creates a temporary interface object, derives the record length from the same header field, calls `NetworkSendDispatch(a2, length, ...)`, and releases the temporary object.  Its complete recovered callee set is the interface create/release pair and `NetworkSendDispatch`.

## Evidence-backed inference

The two recovered shared-event endpoints respectively retain/categorize a copied message record or send it through the network interface.  The narrow `FloatComputation` special case is likewise downstream of the record header and calls only its own flag/orientation/copy helpers in the recovered corpus.  None provides the required identity-preserving handoff into a normal mode-0/1 vehicle integrator.

## Boundary

The shared 432-byte event producer is now excluded not only by queue lifetime but also by its recovered endpoint behavior.  Treat its control encoding as a message/network representation, not a proven normal local-physics actuation ABI.

# 2026-08-18 — Per-vehicle scene scheduling reaches physics routes, but receiver and packet identity remain unproven

## Verified raw facts

- Dynamic-manager construction allocates 104 36-byte entries.  `ShortComputation_e860` initializes each with mode `6` at `+0x1C` and a link at `+0x20` to `VEH[i]+0xC`.  `VehgenScnFileLoader` then registers the corresponding entry through `ShortComputation_0b20(dword_5EA560, vehicle+0xC)`.
- At the end of `MainGameTickUpdate`, `PerVehicleCameraUpdateIterator(dword_5EA560, time)` iterates that manager's pointer array.  For an entry in mode `6`, `ModeDispatchedRenderPhysicsCall` invokes `sub_4F0430(time)` and `WheelContactTransform(entry+0x20)`.
- The separate 25-ms `LoopWithConditionalSkipFunction(dword_5EA560, time)` iterates the same manager array.  In a mode-6 entry, `SceneObjectLoaderStateMachine` tests a capability bit through the object reached from entry `+0x20`, then invokes `VehiclePhysicsModeDispatcher(time)` and `SuspensionStateUpdate(entry+0x20)`.
- `VehiclePhysicsModeDispatcher` has a receiver layout containing `+0x32BC`, `+0x32C0`, and `+0x34AC`; its normal modes call either `VehiclePhysicsIntegrationStep` or `PhysicsIntegrationStateMachine`, while mode 2 calls `TeamColorLoader`.  The scene-entry object is only 36 bytes, so it cannot itself be that receiver.
- `sub_4F0430` has a separate case-3 route that obtains a stack-local 432-byte buffer from `sub_4B9AC0` and passes it to `VehiclePhysicsTimeStep` with a vehicle base computed from the local vehicle index.  `sub_4B9AC0`'s recovered callees are linked-list/sample dispatch helpers; no raw connection identifies its stack buffer with the AI shared event queue.

## Evidence-backed inference

The mode-6 scene entries establish that per-vehicle scene scheduling and normal physics routes coexist on the active frame path.  However, Hex-Rays does not render an explicit receiver at the scene-to-`VehiclePhysicsModeDispatcher` call.  The receiver must be an indirect larger controller object rather than the 36-byte entry, but the raw corpus currently does not prove which linked object it is or any transfer from `vehicle+0x357C/+0x3580/+0x3584` to that controller.  The independently populated case-3 stack packet is likewise not the AI event record.

## Boundary

This discovers the closest recovered scheduling route to normal per-vehicle physics, but does not close the authoritative AI-control bridge.  Do not expose a writable control contract until the dispatcher receiver and an identity-preserving control transfer are recovered.

# 2026-08-18 — Scene dispatcher receiver resolved as `vehicle+0xC`; control transfer still absent

## Verified raw facts

- `ShortComputation_e860` stores `VEH[i]+0xC` into each mode-6 dynamic-manager entry at `entry+0x20`.  `VehgenScnFileLoader` registers that same `vehicle+0xC` address through `ShortComputation_0b20`.
- The static field arithmetic is consistent with the linked receiver: the dispatcher reads receiver-relative `+0x32BC` and passes receiver-relative `+0x32C4` to `PitStateUpdateMachine`.  When the receiver is denoted `vehicle+0xC`, do not collapse those values into vehicle-base offsets without preserving that extra `+0xC`.  This excludes the 36-byte manager entry as receiver.
- `SceneObjectLoaderStateMachine` mode 6 retains the indirect linked address while testing its capability and then calls `VehiclePhysicsModeDispatcher(time)`.  This proves per-vehicle dispatcher scheduling, but mode-0's subsequent integrator call targets `PlayerPhysicsObject`; it does not prove per-vehicle normal input integration.
- The indexed direct readers remain unchanged: normal mode-0/1 integrators do not read `vehicle+0x357C`, `+0x3580`, or `+0x3584`; the only recovered readers are AI, the serializer, and the packet decoder route.

## Evidence-backed inference

The earlier ambiguity was a Hex-Rays omitted effective-`ECX` receiver at the scene-state-machine call, not a separate unknown controller object.  This resolves dispatcher scheduling and receiver ownership, but it does not establish a per-AI normal integrator: the recovered mode-0 integrator explicitly targets `PlayerPhysicsObject`.  No raw read or transfer from the AI's three committed controls is recovered.

## Boundary

The required bridge remains an un-recovered mediation or an execution path outside the indexed direct accesses.  No writable AI-SDK control contract is justified.

# 2026-08-18 — Superseding correction: mode-0 input smoothing is on `PlayerPhysicsObject`

## Verified raw facts

- In dispatcher mode 0, `VehiclePhysicsModeDispatcher_004E4930` explicitly calls `VehiclePhysicsIntegrationStep((int *)&dbl_7C7428, time)`.  The global index identifies `0x7C7428` as `PlayerPhysicsObject` [FACT].
- `VehiclePhysicsIntegrationStep` then passes that receiver directly to `VehicleMainPhysicsUpdate_004441F0`, and uses its `+0x60/+0x68` timing values for substeps.
- `VehicleMainPhysicsUpdate` invokes `sub_454DA0` while retaining the `PlayerPhysicsObject` receiver.  Its displayed first argument, `*((double *)this + 13)`, is the explicit `float a2` time value at `this+0x68`, not an input-context pointer.  The disabled `this+0x70` branch supplies local defaults.
- Thus `sub_454DA0` reads receiver-local `+0x1B20..+0x21FC` fields and produces local steering, throttle, brake, clutch, handbrake, and gear outputs.  Its exact raw body contains no read of the vehicle AI commit offsets `+0x357C`, `+0x3580`, or `+0x3584`.
- The unrelated offset-index hits remain non-evidence for cross-function identity, but do not contradict the direct same-receiver call chain above.

## Evidence-backed inference

The recovered mode-0 normal path consumes input state local to the global `PlayerPhysicsObject`, then uses the resulting local values.  It is not a per-AI-vehicle input path.  No recovered call, direct field read, or identity-preserving copy links the AI commits to that input state.

## Boundary

This rules out treating those frame-smoothed player-physics outputs as a writable AI contract.  The remaining proof must establish an AI vehicle's actual physics route and any vehicle/AI-specific transfer into it; absent that, retain the AI surface as read-only telemetry only.

# 2026-08-18 — Normal input outputs feed `PlayerPhysicsObject` directly

## Verified raw facts

- Mode-0 dispatcher calls `VehiclePhysicsIntegrationStep` on `PlayerPhysicsObject`; that function calls `VehicleMainPhysicsUpdate` on the unchanged receiver.  In the enabled-input branch, `VehicleMainPhysicsUpdate` invokes `sub_454DA0` and receives stack-local values for steering (`v280`), throttle (`v291`), brake (`v304`), clutch (`v323`), handbrake (`v324`), and gear (`v319`).
- Immediately after the input-mode/session guards, the raw routine copies those local values into receiver-local control slots: `this+0x0` from steering, `this+0x4` from throttle, `this+0x8` from brake, and `this+0x10` from handbrake.  It also uses the local gear value in its later state logic.
- `sub_454DA0` computes the locals from receiver-local source fields at `+0x1B20..+0x21FC`, including direct-mode guards and smoothed fallback paths.  It has no raw read of the three AI committed fields.

## Evidence-backed inference

This is the authoritative recovered normal control-input-to-physics path for `PlayerPhysicsObject`: source input state → `sub_454DA0` local controls → `VehicleMainPhysicsUpdate` receiver control slots → later physics work in the same `VehiclePhysicsIntegrationStep` call.

## Boundary

This does not establish an AI vehicle terminal path.  Do not write the source fields or terminal control slots through an SDK: the former are player-physics-owned and the latter are recomputed every frame.

# 2026-08-18 — Superseding receiver boundary: mode-2 dereferences its implicit receiver

## Verified raw facts

- `VehiclePhysicsModeDispatcher` renders its mode-2 call as `TeamColorLoader(time)` with no displayed first argument.
- `TeamColorLoader_004F03E0` is declared `__thiscall`; it passes `*this` to both `UtilityFunction_3d50` and `VehiclePhysicsTimeStep`, using `*this+0x4894` as the record identifier.
- The mode-0 branch instead explicitly passes `&PlayerPhysicsObject` to `VehiclePhysicsIntegrationStep`.
- Scene-manager entries do contain the linked `VEH[i]+0xC` address, but the raw call rendering alone does not prove that address is the exact `TeamColorLoader`/dispatcher `this`, nor that its first word is the AI vehicle base.

## Correction

Withdraw the stronger claim that scene-link arithmetic alone resolves the dispatcher receiver as a direct `vehicle+0xC` object.  It proves a per-entry link exists; mode-2 raw code proves a further dereference before its packet decoder.  The required object identity between the AI record, the scene link, the dispatcher receiver, and `VehiclePhysicsTimeStep`'s first argument remains open.

## SDK boundary

Mode-2 has a verified packet decoder and command codec, but lacks the identity and lifecycle proof required for a writable per-AI SDK contract.

# 2026-08-18 — Scene-link construction is tied to the embedded physics object

## Verified raw facts

- `RepeatedCallLoop_0042BB50` constructs 104 vehicle records from `unk_5EC6D8` with the 18,624-byte stride.
- `RaceStructInit_00423E80`, invoked for each record, calls `PhysicsTireSystemConstructor(this + 3)`: the physics/tire object begins at vehicle byte offset `0xC`.
- `sub_40FE50` initializes each mode-6 scene entry with the exact address `&unk_5EC6E4 + 18624*i`, which is the same vehicle-record base plus `0xC`.
- `SceneObjectLoaderStateMachine` retrieves that entry link, dereferences its first word for the capability test, and then enters the omitted-effective-receiver dispatcher call.  `TeamColorLoader` similarly dereferences its own first word before calling `VehiclePhysicsTimeStep`.

## Evidence-backed inference

The scene link is not an arbitrary nearby vehicle address: it is the embedded physics/tire object constructed at `vehicle+0xC`.  The matching dereferences make that object the strongest static bridge between scene scheduling and the packet route.  However, the corpus does not yet show the initialization or invariant for that object's first word, so it does not prove that `VehiclePhysicsTimeStep(*physicsObject, ...)` targets the same enclosing vehicle that produced the AI commands.

## SDK boundary

This narrows the remaining identity proof to the embedded physics object's first-word ownership and mode-2 lifecycle.  It does not authorize writes.

# 2026-08-18 — Embedded physics object first word is a vehicle pointer

## Verified raw facts

- `LargeConfigFunctionWithPhysicsConstants_004E45B0` operates on the embedded physics object: it reads `this+0x32BC` and, in its zero branch, calls `TireModelInit(&PlayerPhysicsObject, *this)`.
- The same function resolves driver/tire configuration through `*this+0x4898` and `*this+0x4794`, which are outer vehicle-record accesses, then stores its own physics configuration at receiver-relative `+0x3498..+0x34AC`.
- `TeamColorLoader` uses that same object convention: it passes `*this` to `UtilityFunction_3d50` for its vehicle identifier and to `VehiclePhysicsTimeStep` as the packet-decoder receiver.

## Evidence-backed inference

The embedded object’s first word is an outer vehicle-record pointer, not a vtable or unrelated object.  Coupled with construction at `vehicle+0xC` and the scene link to that address, this is strong static evidence that the mode-2 decoder is associated with the enclosing vehicle.  The corpus still lacks the direct initializing write and mode-selection lifecycle, so this remains an inference rather than SDK-grade identity proof.

## SDK boundary

The AI command codec now has an associated per-vehicle embedded-physics decode path, but no writable contract is safe until direct initialization, mode coverage, ownership arbitration, and reset behavior are recovered.

# 2026-08-18 — AI driver setup selects mode 1 in its per-slot loop

## Verified raw facts

- `AIDriverCountSetup_004BFD90` builds its selected AI count, then iterates records beginning at `unk_5EC6D8 + 18624*startIndex`.
- Each iteration invokes `SessionStateTransition(1, 0)`, then assigns driver nationality and team identity before advancing exactly one vehicle stride.
- `SessionStateTransition` is the only recovered non-constructor writer of the embedded physics object's mode field.  Its receiver is a `__thiscall` object and its explicit first argument is the requested mode.
- Hex-Rays omits the effective receiver for the loop's `SessionStateTransition(1, 0)` call, so the raw listing alone does not prove the precise `vehicle+0xC` address supplied in that call.

## Evidence-backed inference

Mode 1 is deliberately selected during AI-driver setup, while mode 2 remains a distinct packet-decoder path.  The per-record iterator and constructor layout strongly align the omitted receiver with each selected vehicle's embedded physics object, but the missing effective-register rendering prevents treating that alignment as final ownership proof.

## SDK boundary

Do not generalize the verified mode-2 codec to all AI vehicles.  The likely normal AI mode is 1, whose authoritative AI-control handoff remains unproven.

# 2026-08-18 — Mode-2 packet builder is session interpolation, not the AI command record

## Verified raw facts

- `TeamColorLoader` calls `UtilityFunction_3D50(dword_7CD25C, vehicleId, stackPacket, time)`, then passes that stack packet to `VehiclePhysicsTimeStep`.
- `UtilityFunction_3D50` obtains the packet through `CollisionTestWithThreshold` using the session/global object `dword_7CD25C`; on success it invokes `PhysicsIntegrationStep_e620` and updates interpolation state.
- `CollisionTestWithThreshold` interpolates/copies data from its session-object state into the supplied packet buffer.  `PhysicsIntegrationStep_e620` consumes and updates position/velocity-style packet values at `a3+8/+12/+16`; it has no AI-control-field access.
- `VehiclePhysicsTimeStep` decodes steering from the packet at `a2+8` and flags from later packet words, but its packet producer chain contains no recovered read of vehicle `+0x357C/+0x3580/+0x3584`.

## Conclusion

The mode-2 packet is a session-manager interpolation stream keyed by vehicle identity, not the AI serializer's shared command event.  This independently excludes mode 2 as the missing universal AI-control bridge.

# 2026-08-18 — Indexed audit confirms no recovered normal-mode consumer of AI commit fields

## Verified raw facts

- The canonical field index identifies `AIMainUpdate_00424E70` as the only indexed writer of vehicle `+0x357C` (`ThrottleFactor`).  Its only other indexed touch is `SetupCarLightingAndRender_004C71C0`.
- For vehicle `+0x3580` and `+0x3584` (`BrakeFactor`), the index lists `AIMainUpdate`, `SetupCarLightingAndRender`, and `VehiclePhysicsTimeStep_004C73F0`; the latter is the already-separated mode-2 session-packet decoder.
- Neither recovered mode-1 routine (`PhysicsIntegrationStateMachine` and its direct callees) nor the recovered mode-0 `PlayerPhysicsObject` input/integration chain appears as a direct reader of any of the three AI commit fields.

## Boundary

This is a direct-access audit, not proof that an indirect transfer cannot exist.  It does, however, exclude every currently indexed direct normal-mode consumer.  Keep `+0x357C/+0x3580/+0x3584` read-only and continue tracing an indirect AI-mode-1 handoff rather than treating the mode-2 decoder as authoritative.

# 2026-08-18 — AI racing-line correction directly reaches the embedded physics object

## Verified raw facts

- `AISteeringCorrection_00426CF0`, called by `AIMainUpdate`, conditionally calls `AISteeringRacingLineCorrection_0042B0E0` on the same vehicle receiver.
- In that correction routine, `VehicleDynamicsStateReset(this + 3)` explicitly targets the embedded object at vehicle `+0xC`.  Its immediately following `AIVehiclePathPositionTracking(v42, v44)` call has an omitted effective receiver.
- `AIVehiclePathPositionTracking` operates on the embedded physics layout (`+0x34D0..+0x34E8`), and in mode 0 alone calls `RigidBodyConstraintSolve(&PlayerPhysicsObject, ...)`; non-zero modes do not take that player-only branch.
- `VehicleDynamicsStateReset` also calls its player-global reset only when its own mode field is zero.

## Evidence-backed inference

The explicit `this+3` call and adjacency make the omitted receiver of `AIVehiclePathPositionTracking` strongly consistent with the same embedded physics object.  This proves a real AI-side route into embedded-physics state for recovery/pose correction, while reinforcing that mode-0 branches are player-global.

## Boundary

Neither routine reads the three AI commit fields or performs longitudinal/steering command consumption.  Treat this as an object-identity and lifecycle link, not the missing writable control handoff.

# 2026-08-18 — AI commits are serialized into the shared event buffer

## Verified raw facts

- `TireTemperatureSimStep_004C77D0` is invoked per vehicle by `IterateVehicles`; after its session/timer guard it reserves the next 432-byte slot at `dword_8AAE64` and calls `SetupCarLightingAndRender_004C71C0(vehicle, slot)`.
- Despite its legacy name, `SetupCarLightingAndRender` calls packet encoders and writes vehicle `+0x357C`, `+0x3580`, and `+0x3584` into the supplied slot: throttle through `BitfieldInsert`, steering through `FloatToBitfieldEncoder`, and the brake condition into flag `0x04000000`.
- The call returns to `TireTemperatureSimStep`, which calls `sub_4EF2E0(vehicle+0xC)`.  That routine independently emits force-feedback/audio-change records into the same shared 432-byte buffer and has no physics dispatcher/integrator callee.
- The previously recovered downstream consumer of this buffer is the queue/network split (`InputCommandDispatchToEntities` → `sub_465300` or `TextureCreationWrapper`), not normal local simulation.

## Conclusion

The three committed AI values have a verified producer-to-shared-record serialization path.  This is the authoritative recovered representation boundary, but it is a shared event/network output path rather than proof of a normal per-AI physics input consumer.

## SDK boundary

Do not write this record or its encoded fields as a local-control SDK.  It is shared-buffer owned and its recovered consumers are queue/network endpoints.

# 2026-08-18 — Post-main-loop record processing preserves queue semantics

## Verified raw facts

- `GamePostMainLoop_0042D8A0` orders `MainGameTickUpdate`, then the all-active-vehicle `IterateVehicles` serializer loop, then `TwoPathDispatch`, and finally resets the shared-record count.
- `TwoPathDispatch` forwards the count and vehicle-array base to `CallWrapper_9870`/`PitTimingUpdate` in its active branch.
- `PitTimingUpdate` obtains 432-byte records with `AdvanceRingBuffer` into a 108-dword stack buffer, dispatches selected header classes to `PitStallProximityCheck`, and that routine passes the record to `CollisionObjectInsertion` when its time window matches.
- `CollisionObjectInsertion` classifies `record[0] >> 29`, copies the record with `ArithmeticComparison_3A90`, and appends a 12-byte node to a per-class linked list.  Its recovered callees contain allocation/list/copy helpers, not vehicle physics.

## Conclusion

The recovered post-main-loop path continues the serialized representation as time-classified copied records and linked-list work.  It does not provide an identity-preserving call into normal vehicle simulation.

# 2026-08-18 — The serialized ring is consumed by event/network dispatch, not vehicle physics

## Verified raw facts

- `GamePostMainLoop` places `CollisionResponseStatus` after `IterateVehicles`; `CollisionResponseStatus` calls `InputCommandDispatchToEntities_0045F4A0`.
- `InputCommandDispatchToEntities` explicitly calls `SessionDataCopy(&dword_83EE60)` and repeatedly calls `AdvanceRingBuffer(&dword_83EE60, stackRecord[432])`, establishing the same shared-ring state as the post-main-loop consumer.
- For each eligible record, its recovered routes are `sub_465300(&dword_7CD2A8, stackRecord)` or `TextureCreationWrapper(..., stackRecord, ...)`; the later branch likewise forwards records from an entity-visibility linked list to `TextureCreationWrapper`.
- Neither `InputCommandDispatchToEntities` nor its recovered direct routes calls `VehiclePhysicsModeDispatcher`, `PhysicsIntegrationStateMachine`, `VehiclePhysicsIntegrationStep`, or `VehiclePhysicsTimeStep`.

## Conclusion

This closes the recovered local output representation chain: per-vehicle AI commits → 432-byte serializer record → shared ring → copied queue/network/entity dispatch.  It is not the normal vehicle-simulation input path.

# 2026-08-18 — Normal AI vehicles also take a direct racing-line movement branch

## Verified raw facts

- `sub_4C6B60` calls `sub_4BB8E0` on each vehicle record during its session tick.
- `sub_4BB8E0` reads the enclosing vehicle through its first word and, when outer vehicle `+0x32C8 <= 1`, explicitly calls `AIRacingLinePathFollowing(vehicle + 0xC)`.
- `AIRacingLinePathFollowing` operates on the embedded physics object and uses its first word as the enclosing vehicle.  It resolves track nodes, writes embedded position/orientation state at `+0x34D4..+0x34E8` / `+0x34BC..`, calls `SuspensionStateUpdate`, `VehicleBodyToWheelContactDistanceComputation`, and transform/scene updates.
- This branch directly manipulates embedded body/pose state.  Its raw body does not read vehicle `+0x357C/+0x3580/+0x3584`.

## Evidence-backed inference

For normal mode-gated AI vehicles, the recovered movement path is waypoint/racing-line state into the embedded physics/scene body, independently of the serialized command fields.  It is a stronger candidate for actual AI movement than the shared control-event ring, but its full force/integration semantics and ownership arbitration are not yet recovered.

## SDK boundary

Do not expose this embedded state as writable.  It is continuously game-owned by racing-line, suspension, contact, and scene-update code; the path explains why a direct command-field consumer may be absent, but does not establish a safe actuator API.

## Superseding timing correction

`SceneRenderUpdate` calls `sub_4C6B60` during vehicle/load/reset callers, and the other recovered caller (`sub_42D140`) invokes it only while handling a changed session-state value.  The currently recovered callers therefore do **not** prove that `AIRacingLinePathFollowing` is an every-main-tick terminal actuator.  Retain it as a verified AI/embedded-body state-update branch and candidate for further lifecycle tracing, not as the authoritative normal per-tick movement path.

# 2026-08-18 — Superseding correction: mode-1 physics directly consumes the AI steering commit through the embedded-object alias

## Verified raw facts

- The embedded physics receiver `P` begins at vehicle `V+0xC`.  Therefore `P+0x3574` is exactly `V+0x3580`.
- `PhysicsIntegrationStateMachine_004E4E60` calls `WheelForceCalculationSpringDamperTorque_004E5470` in every mode-1 substep.
- That raw function computes `v10 = this[3672] * this[3421]`, then stores `v10`, `cos(v10)`, and `sin(v10)` into its wheel/steering geometry state before calling tyre-contact and wheel spring/damper routines.
- With `this == P`, `this[3421]` is `P+0x3574`, hence the exact enclosing-vehicle field `V+0x3580` written by `AIMainUpdate` from `V+0x442C`.
- `SuspensionAndWheelPhysics_004E5F60`, reached during the reset/configuration sequence, seeds `P+14688` (`P[3672]`) from parsed vehicle-configuration inputs. The AI-local `[-1,1]` steering clamp is therefore a pre-gain bound, not a universal physical wheel-angle bound.

## Conclusion

The authoritative normal mode-1 steering chain is now statically proven:

`AIMainUpdate: V+0x442C → V+0x3580` → `mode-1 PhysicsIntegrationStateMachine` → `WheelForceCalculationSpringDamperTorque: P+0x3574 (alias V+0x3580)` → steering-angle sine/cosine and wheel-force geometry.

## Correction and SDK boundary

Withdraw prior statements that treated `P+0x3574` as unrelated to the AI command solely because its receiver-relative numeral differs.  It is the embedded alias of the AI steering commit.  This proves steering consumption, but does not yet establish a safe writable field API: mode ownership, reset/arbitration, and the longitudinal/brake paths still require the same receiver-aware audit.

# 2026-08-18 — Mode-1 longitudinal-channel aliases are also direct AI commits

## Verified raw facts

- Since `P == V+0xC`, `P+0x3570 == V+0x357C` and `P+0x3578 == V+0x3584`.
- In each mode-1 `PhysicsIntegrationStateMachine` substep, `sub_4E51A0` reads `P+0x3578` in two coefficients written to its per-wheel state, then reads `P+0x3570` into `v29`.
- The same function uses `v29` in `v27 = interpolatedValue * v29 + P+0x39AC`, stores the result at `P+0x399C`, and derives force/load values from it.  It may zero `P+0x3570` only under its explicit `P+0x3978 <= 0` guard.
- `sub_4E5AE0`, later in the same mode-1 substep, consumes the state region populated by `sub_4E51A0` while integrating wheel/body dynamics and brake-torque-related values.
- Separately, `ThrottleBrakeOverride_004EE230`, invoked by `sub_4EE2D0` in `MainGameTickUpdate` for mode 1, directly reads `P+0x3570` to derive its longitudinal override values.

## Conclusion

All three AI commits have now recovered normal mode-1 consumers through the embedded-object alias:

- `V+0x357C` longitudinal → `P+0x3570` → `sub_4E51A0` / `ThrottleBrakeOverride`.
- `V+0x3580` steering → `P+0x3574` → wheel steering geometry.
- `V+0x3584` second longitudinal channel → `P+0x3578` → mode-1 wheel coefficients.

## SDK boundary

This closes the static control-to-mode-1 simulation chain, but not a safe writable ABI.  The raw coefficient use does not by itself prove a player-facing “brake” label for `V+0x3584`.  The fields are still overwritten/guarded by game-owned mode-1 code, and mode selection, reset/arbitration, range validation, and multiplayer/replay ownership remain required contract proof.

# 2026-08-18 — Authoritative 25-ms ordering for AI commit and mode-1 consumption

## Verified raw facts

- `MainGameTickUpdate_0042C690` runs a 2.5-ms catch-up substep loop.  Every tenth substep it first iterates active vehicles with `AIMainUpdate`, then calls `LoopWithConditionalSkipFunction(dword_5EA560, time)`.
- The latter reaches each mode-6 scene entry’s `SceneObjectLoaderStateMachine`, which invokes `VehiclePhysicsModeDispatcher` on its embedded physics receiver when the vehicle capability bit permits it.
- Dispatcher mode 1 executes `PhysicsIntegrationStateMachine`; its per-substep `sub_4E51A0` and `WheelForceCalculationSpringDamperTorque` consumers therefore run after the corresponding AI commit in the same ten-substep cadence.
- After the scene loop, the main tick calls `ParticleEffectUpdateDispatch(V+0xC)` and `sub_4EE2D0(V+0xC)` for every active vehicle.  Mode 1 in `sub_4EE2D0` calls `ThrottleBrakeOverride`.
- At 400-substep cadence the same main tick invokes `FuelConsumptionAndWear` for active vehicles whose outer `+0x32C8` equals 1; that routine reads the `P+0x3570` alias.

## Conclusion

The recovered local ordering is AI planning/commit → mode-1 physics dispatcher/wheel consumption → per-vehicle post-physics override, with a slower fuel/wear consumer.  This is the authoritative static output-to-normal-simulation schedule for the normal AI mode.

# 2026-08-18 — Commit ownership and persistence boundary in `AIMainUpdate_00424E70`

## Verified raw facts

- `AIMainUpdate` returns without touching the three commits when outer `V+0x32C8 > 1`, when `sub_426430(V)` fails, or when the embedded receiver's mode check `*(DWORD *)(*(DWORD *)V + 0x32C8) != 1` fails.  The normal planner-to-commit path is therefore not an unconditional per-record write.
- In the normal state dispatch, state `V+0x4510 == 2` calls `FieldZeroSetter(V)` and returns before the shared commit block.  `FieldZeroSetter_00425660` only resets `V+0x4510` to zero; it does not reset `V+0x357C/+0x3580/+0x3584`.  The previous committed trio can consequently persist across that state-2 return.
- On the other normal planner states, the shared tail writes all three fields: `V+0x3580 <- V+0x442C`, `V+0x3584 <- V+0x4438`, and `V+0x357C <- V+0x4434`.
- The pit/return tail overwrites the trio with `V+0x3580=0`, `V+0x3584=1`, `V+0x357C=0`.  The race-start/countdown path also reaches an explicit all-three write before its return, with values derived from its countdown logic.
- The normal steering source `V+0x442C` is rate-limited and clamped to `[-1,1]` by `sub_426100`; no corresponding public range proof has yet been recovered for either committed longitudinal channel.

## SDK consequence

The fields are game-owned sampled commands, not independent persistent settings.  A static-only contract cannot safely authorize direct writes: a caller would need proven mode-1 eligibility, ordering immediately before the dispatcher, explicit handling of the state-2 persistence case, and range/arbitration rules for both longitudinal channels.  Those conditions are not yet proven.

# 2026-08-18 — Mode-1 setup provenance: exact caller boundary

## Verified raw facts

- `SessionStateTransition_004EF5A0` writes its explicit `a2` value to receiver-relative `+0x32BC`.  On transition to value `1` it clears the enclosing vehicle's waypoint pointers and calls `AISpeedDeltaSetter`; the transition is therefore a game-owned state initialization, not merely a flag store.
- `AIDriverCountSetup_004BFD90`, called by `DynMan_Init_0042C1A0`, walks `unk_5EC6D8` with the exact 18624-byte vehicle stride and invokes `SessionStateTransition(1, 0)` for every selected opponent slot before nationality/team assignment.  Its single-player fallback uses transition value `0` when `ScoringGateCheck()` is true and `1` otherwise.
- `ProcessDriverEntries_004B8DA0` also walks the same vehicle base and computes `v16 = (char *)(v24 + 3)` (`V+0xC`) before lifecycle calls.  Its load path makes transition requests `0` then `3`; its removal path requests `-1`.
- Both callers display `SessionStateTransition` without an effective receiver in the raw Hex-Rays call text, despite the callee being `__thiscall`.  The raw corpus therefore proves the transition values and enclosing-record walks, but not the final machine instruction that places `V+0xC` in the receiver register for each call.

## Evidence-backed inference

The repeated 18624-byte vehicle walk, the locally computed `V+0xC`, and the transition callee's embedded-layout writes are consistent with selected setup records entering mode 1 through their embedded physics object.  This is strong initialization evidence, not receiver-level proof that every AI tick runs mode 1.

## SDK boundary

Do not expose `+0x32BC` as a writable mode selector.  The recovered initialization and load/remove paths assign at least `-1`, `0`, `1`, and `3`, and mode 2 is independently used by packet interpolation.  A safe contract needs an authoritative receiver-level mode-eligibility proof plus replay/network and multiplayer ownership coverage.

# 2026-08-18 — Multiplayer session code explicitly owns embedded-mode transitions

## Verified raw facts

- `NetCommPlayerSlotSync_0045FC50` computes a vehicle record as `V = unk_5EC6D8 + 18624*slot`, then explicitly calls `SessionStateTransition((float *)V + 3, mode, 0)`.  This is direct raw receiver proof that the transition receiver is `V+0xC` in this session path.
- For the locally selected slot it requests mode `0`; for another loaded slot it requests mode `2`; on an unloaded slot it calls `sub_4C6E80(V)` then explicitly requests `-1` on `V+0xC`.
- `MultiplayerSessionJoinHandler_0046DE10` and `AutoJoinRetryLoop_004637A0` each walk the complete vehicle area and request `SessionStateTransition(-1, 0)` while clearing/rebuilding the active vehicle array.

## Conclusion

The embedded mode field is externally and asynchronously re-owned by multiplayer/session lifecycle code.  The same static interface selects local mode 0, remote/other mode 2, and removal mode -1; therefore a direct mode-1 control-field write cannot be a safe cross-session SDK mechanism without a session-authority gate.

## SDK boundary

Treat the mode-1 control trio as local AI-only internals until static evidence defines which session/slot authority may select mode 1 and how mode transitions synchronize with packet/replay paths.  No such writable contract is proven.

# 2026-08-18 — Dynamic-manager initialization separates generated opponents from session slots

## Verified raw facts

- `DynMan_Init_0042C1A0` is called by `Game_Init_0042D6B0`.  It scans slot records to choose/set the player vehicle index before any opponent count setup.
- Only when `byte_7C5690 == 0` does it build the driver-name context and call `AIDriverCountSetup_004BFD90`; after that branch it rebuilds the active vehicle-pointer array and loads each active vehicle scene.
- When `byte_7C5690 != 0`, `DynMan_Init` does not call `AIDriverCountSetup`; its alternate branches call other setup helpers instead.  The byte's exact session-mode name is not established by this function alone.

## Consequence

The selected-opponent mode-1 setup evidence belongs to the generated-opponent initialization branch, while explicit network slot synchronization has separate mode ownership.  This supports a session-scoped read-only AI map, but does not establish a writable cross-mode control contract.

# 2026-08-18 — Driver-state initialization follows per-vehicle physics/scene setup

## Verified raw facts

- `SceneRenderUpdate_004C6D90` invokes `VehicleRespawnReset`, `LargeConfigFunctionWithPhysicsConstants(V+0xC)`, scene/dispatch setup, then `AIDriverStructInit(V, a2)`, followed by `sub_4C6B60(V, 1)`.  It is called from restart, slot-sync, process-entry, pit-decision, and AI message paths.
- `AIDriverStructInit_00424790` always resets planner/traffic/controller state, including the interaction pointer/lateral offset, waypoint/timer sentinels, controller state, speed-governor defaults, and multiple rate/limit values.  Its Boolean `a2` branch additionally initializes five event entries, the AI message queue, a same-team vehicle pointer search, and the nearest route-node state.
- Its final difficulty-derived value comes from `AIDifficultyInterpolation`; session types `3`, `4`, and `5` bypass the recovered multiplication by `flt_5EA3E8`, while other session types apply it.  The final consumer reached through `ScaleAudioPitch` does not make this a direct control-field contract.

## SDK consequence

Profile/driver inputs are lifecycle-owned and may be reset from several non-tick paths.  A safe SDK boundary cannot write these per-driver planner fields directly; the only defensible static exposure at this point is read-only observation with lifecycle invalidation on scene, restart, pit, and session-slot events.

# 2026-08-18 — Difficulty is a global multi-path input, not a per-driver writable parameter

## Verified raw facts

- `AIDifficultyInterpolation_00424AC0` reads global `dword_7D01A0` and linearly interpolates between low/mid anchors through 100, or mid/high anchors above 100.  Neither branch clamps the input.
- The same global is independently read by `AIDifficultyScalar_00424750`, `AIDatabase_Init_004040A0`, `sub_424080`, `AIRingBufferFieldInit_00424C80`, and AI behavior initialization.  These paths affect initialization, periodic variation, and steering/traffic-related calculations.
- `LoadAIDriverNamesFromConfig_004336F0` resolves vehicle configuration entries only for active records whose outer `+0x32C8` is zero; it copies the selected source/config path into the vehicle and validates the configuration file.  This is entry/profile loading, not proof of a live per-tick control setting.

## SDK boundary

Expose the difficulty/global profile source as read-only only.  Static evidence shows broad, non-clamped, multi-subsystem fan-out and no transactional ownership or supported write lifecycle.

# 2026-08-18 — Gear-related call boundary remains unresolved

## Verified raw facts

- The normal `AIMainUpdate` sequence calls `PhysicsGearShiftLogicWithThresholds_00426330` after steering correction and before its controller-state dispatch.
- `sub_426330` gates on several receiver-relative values and calls `RaceStartCountdownStateUpdate_004EF930` to request `-1`, `0`, or one greater than a current integer state.  It contains no direct write to a recovered gearbox field.
- `RaceStartCountdownStateUpdate` itself has a `__thiscall` receiver and touches timer/state fields plus a conditional value at receiver-relative `+0x3578`; the calls from `sub_426330` and `AIMainUpdate` omit their effective receiver in the Hex-Rays text.

## Boundary

The legacy gear-shift name is not evidence of a verified AI-to-transmission write.  The raw code proves a gated state/request subpath, but not the receiver identity, final gearbox field, or a safe shift-command ABI.  Keep gear strategy read-only/unmapped for writable SDK purposes.

# 2026-08-18 — Mode-1 dispatch does not guarantee a physics inner step

## Verified raw facts

- `VehiclePhysicsModeDispatcher_004E4930` branches on receiver-relative `+0x32BC`: mode 0 performs pit update, integration, and setup; mode 1 performs pit update then calls `PhysicsIntegrationStateMachine`; mode 2 calls the separate `TeamColorLoader` route.
- In `PhysicsIntegrationStateMachine_004E4E60`, the recovered inner-step count is derived from receiver-relative timing/state fields.  If that count is non-positive, the function only updates its time field; it does not call `sub_4E51A0`, `WheelForceCalculationSpringDamperTorque`, or `sub_4E5AE0`.
- Only each positive inner iteration calls the wheel reset, `sub_4E58D0`, `sub_4E51A0`, `WheelForceCalculationSpringDamperTorque`, and `sub_4E5AE0` in that order.

## Correction

The established chain proves consumption on an executed mode-1 inner substep, not on every mode-1 dispatcher call.  Any future contract would need to synchronize to the game-owned integration count/time gates; static evidence does not expose a safe external scheduling hook.

# 2026-08-18 — Post-mode-1 longitudinal override has sentinel arbitration

## Verified raw facts

- In mode 1, `sub_4EE2D0` calls `ThrottleBrakeOverride_004EE230` after its per-wheel contact/effect work.
- The helper derives `v2 = (P+0x3994 / P+0x3998)^3 * (P+0x3570) * 0.5`; `P+0x3570` is the `V+0x357C` AI longitudinal alias.
- It then writes three outputs at `P+0x77C/+0x790/+0x7A4`.  Each output copies the corresponding game-owned source at `P+0x3D48/+0x3D4C/+0x3D50` unless that source equals the literal `-789.0` sentinel, in which case it substitutes `v2`.

## SDK boundary

The AI value is not an unconditional post-physics override.  Its downstream effect is explicitly subordinate to three independently owned sentinel-bearing fields.  Their writers, lifecycle, and safety constraints are not recovered, so none of the command fields or override outputs is safe to expose as writable.

# 2026-08-18 — Override-source initialization and reset are physics-owned

## Verified raw facts

- The direct static index identifies `VehicleSetupInitialization_004E49B0`, `SuspensionAndWheelPhysics_004E5F60`, `FuelConsumptionAndWear_004ED960`, and `sub_4F1FE0` as writers of the three receiver-relative override sources `+0x3D48/+0x3D4C/+0x3D50` read by `ThrottleBrakeOverride`.
- `VehicleSetupInitialization` seeds those sources from three globals.  In contrast, `SuspensionAndWheelPhysics` explicitly writes zero to all three at its recovered initialization/reset tail.
- `ThrottleBrakeOverride` therefore receives values managed by multiple physics/lifecycle routines, not an AI-private control buffer.

## SDK boundary

Do not write the sentinel sources to force an override.  Their initialization/reset races and the role of the configured constants remain unresolved, so forcing the sentinel would violate the recovered ownership model.

# 2026-08-18 — Current authoritative core-AI readiness ledger

This ledger supersedes earlier provisional “missing bridge” summaries where they conflict with the receiver-aware mode-1 audit.

| Objective area | Static evidence status | Writable SDK status |
|---|---|---|
| Initialization and profile | `DynMan_Init` → generated-opponent `AIDriverCountSetup`; `SceneRenderUpdate` → `AIDriverStructInit`; global difficulty and entry-config paths recovered. | Read-only only: scene/restart/pit/session paths reset the state and difficulty has multi-path fan-out. |
| Tick scheduling | `MainGameTickUpdate` invokes `AIMainUpdate` on each tenth 2.5-ms substep, then scene/mode dispatch and per-vehicle post-work. | No external scheduling hook recovered. |
| Waypoint and racing line | `sub_426430` gates waypoint acquisition; `AIRacingLine`, steering, correction, and controller-state logic generate the commit intermediates. | Read-only: normal state 2 can preserve old commits and pit/countdown paths replace them. |
| Traffic/overtake | Proximity/overlap paths write transient selection/lateral state and affect steering correction. | Read-only: pointer provenance and some omitted call arguments remain unresolved. |
| Steering/longitudinal | `V+0x442C/+0x4434/+0x4438` commit to `V+0x3580/+0x357C/+0x3584`; aliases `P=V+0xC` route all three into executed mode-1 wheel/integration work. | Not writable: command ranges and timing/ownership arbitration are incomplete; the second longitudinal channel lacks a proven player-facing label. |
| Gear | The AI calls `sub_426330`; it issues gated state requests through `RaceStartCountdownStateUpdate`. | Not writable: receiver identity and terminal gearbox effect are not proven. |
| Pit strategy | `AIAbility`/pit-machine and scene lifecycle links are recovered. | Not writable: pit machine and transition ownership are game-controlled. |
| Race order | Sorter/ability paths and related state inputs are mapped in prior evidence sections. | Read-only until source and mutation ownership are complete. |
| Output to normal simulation | Normal mode-1 path is proven on executed integration steps: AI commit → `P` aliases → wheel/force integration; post-physics override has game-owned sentinel arbitration. | Not writable: mode selection is session/multiplayer-owned, inner-step execution is conditional, and reset/replay/network coverage is incomplete. |

## Contract decision

No direct writable core-AI SDK contract is statically proven.  The safe current contract is observational only: expose session-scoped, lifecycle-invalidated telemetry and retain all AI control, mode, profile, pit, and override fields as game-owned.  Promoting any writable field requires new evidence for mode-1 authority, a supported write phase, full ranges/reset behavior, and replay/network/multiplayer arbitration.

# 2026-08-18 — Longitudinal range proof is one-sided and path-dependent

## Verified raw facts

- `AIRacingLine_00425920` writes its two longitudinal intermediates from `BrakeThermalModel` and `TireGripCoefficient` branches, with explicit zero/one defaults on some routes and a rate-limited change on one braking route.
- `AISteeringCorrection_00426CF0` can attenuate `V+0x4434`, replace it with feedback-derived values, and caps it only when it exceeds a state/difficulty-derived upper threshold.  Its `byte_5C3160` branch similarly caps it at `min(V+0x44B8, 1)`.
- The same correction writes `V+0x4438` from zero or `TireGripCoefficient`/a half-scaled result on shown branches.  The inspected raw functions do not establish a universal lower/upper clamp for either longitudinal intermediate.

## SDK consequence

Do not substitute assumed `[0,1]` validation for the game's unrecovered range contract.  The raw code supports branch-local defaults and upper caps, not a complete safe-write range for either committed longitudinal channel.

# 2026-08-18 — Mode-1 pit update precedes integration and shares vehicle ownership

## Verified raw facts

- `VehiclePhysicsModeDispatcher` calls `PitStateUpdateMachine(P+0x32C0, time)` before `PhysicsIntegrationStateMachine` for mode 1 (and before its integration/setup work for mode 0).
- `PitStateUpdateMachine_004A6E50` reads its parent pointer at `P+0x32C0`, uses that parent’s `+0x32C8` mode and control gate, and routes pit states through readiness/progress/proximity and state-change operations.
- `AIStateMachineWithModeDispatch_004A5D10` likewise reads the parent vehicle mode and invokes `AIPitStrategyState` when its event mode changes; for parent modes 2/3 it takes separate event-mode routes.

## SDK consequence

Pit state is in the same scheduled control domain as mode-1 integration and can alter eligibility before wheel consumption.  A command contract cannot treat pit policy as an independent overlay on the three AI commit fields.

# 2026-08-18 — Active-array membership is broader than normal-AI eligibility

## Verified raw facts

- `BuildActiveVehiclePointerArray_0042BC80` walks the 18624-byte vehicle records and includes every record whose outer `V+0x32C8 != -1` in `dword_7C54F0`; it does not filter to mode 1.
- `AIMainUpdate` is then scheduled over that entire active array but returns when outer `V+0x32C8 > 1`, and its normal planner path additionally requires the embedded-mode check to equal 1.
- The active-array builder also refreshes the selected/player index globals by comparing active entries to their distinguished vehicle pointers.

## SDK consequence

Membership in the main tick’s AI loop is not a mode-1 authority proof.  Any observational consumer must distinguish active, mode-eligible, and actually-integrated records; an SDK must not infer AI ownership from array membership alone.

# 2026-08-18 — Internal AI command queue is not a recovered public action ABI

## Verified raw facts

- `AICommandMessageQueueDispatcher_00424CD0` directly handles IDs `1`, `4`, `5`, and `15`, then appends a unique `(id, payload)` pair to its per-vehicle queue when capacity permits; it calls `CommandQueueResponseHandler` immediately after append.
- The response handler scans queued IDs `0`, `4`, `5`, and `14`, and combines them with session gates to reset state, change the speed-governor setter argument, and set controller flags.
- Waypoint rebuilding in `sub_426430` emits queue ID `14` on one route-set transition.  Both the dispatcher and waypoint code call `sub_4A46F0`, whose raw calling convention remains incomplete and whose target index comes from its second argument.

## SDK boundary

These are internal protocol IDs, not safe external actions.  No command-domain validation, stable payload schema, mode/session authorization, or complete `sub_4A46F0` receiver/argument proof is recovered.  Do not publish or invoke this queue as writable SDK API.

# 2026-08-18 — Recovered speed setters are unbounded internal primitives

## Verified raw facts

- `AISpeedDeltaSetter_0042ACA0` accepts only its own `0/1` control-state assignment but forwards the `1` case into the unresolved `sub_4A46F0` protocol.
- `ParameterValueSetter_0042ACD0` writes any supplied integer as a float to `V+0x4538`, except literal `18`, which substitutes a global value.  It has no local range validation and is called by AI ability and command-queue paths.

## SDK boundary

Neither helper is a safe writable SDK method.  The first depends on an incomplete protocol; the second accepts arbitrary values without a recovered unit, range, arbitration, or terminal-physics contract.

# 2026-08-18 — Per-driver profile parser and normalization are fully game-owned

## Verified raw facts

- `sub_424080`, called only by the Boolean/full branch of `AIDriverStructInit`, loads keyed per-driver entries including `STARTSDRY`, `STARTSWET`, `STARTSTALLS`, `QUALIFYINGABILITY`, `TRACKAGGRESSION`, `RAINABILITY`, `RACEABILITY`, `PASSING`, `CORNERINGADD`, `CORNERINGMULT`, `CRASH`, `COMPLETEDLAPS`, and `SCRIPT`.
- It supplies built-in defaults when keys are absent, then normalizes/scales values with session globals, weather/grip factors, randomization, and difficulty.  Shown guards include a lower clamp on scaled track aggression, an upper clamp on normalized passing, and a bounded transformation of the start-performance value.
- The parser also converts season `RACEEVENTS` into the existing per-driver event slots for engine, brakes, gearbox, suspension, stall, and stall-DNS handling.

## SDK boundary

The configuration keys are initialization inputs, not live mutable fields.  They are transformed into many derived values and can be reloaded by lifecycle paths; retain profile exposure as source/derived telemetry until a controlled reload/validation lifecycle is proven.

# 2026-08-18 — `SCRIPT` remains an unconsumed profile string in recovered raw code

## Verified raw facts

- `sub_424080` writes the default or configured `SCRIPT` text to the vehicle buffer at `V+0x44E0`.
- The canonical field index has no recovered reader or writer beyond this parser, and a raw-corpus search for the source offset finds only the two parser stores.

## Boundary

This proves profile storage, not script execution or a behavior interface.  Absence from the recovered raw corpus is an investigation limit, not proof that no external/indirect consumer exists; do not expose `SCRIPT` as a writable AI action.

# 2026-08-18 — Mode-3 `VehiclePhysicsTimeStep` packet source is separate from AI serialization

## Verified raw facts

- In `sub_4F0430`, case `P+0x32BC == 3` obtains a 432-byte local packet through `sub_4B9AC0(&dword_8AB6EC, slot, packet, sentinelTime)` and then calls `VehiclePhysicsTimeStep(unk_5EC6D8 + 18624*slot, packet, time)`.
- `sub_4B9AC0` obtains its packet through `LinkedListTraversalWithFilter` from the `dword_8AB6EC` dispatcher state and dispatches audio/sample helper paths; it is not called from the per-vehicle AI serializer.
- This differs from mode 2’s `TeamColorLoader` route, which obtains a packet from `UtilityFunction_3d50(dword_7CD25C, vehicle slot, ...)` before calling the same time-step function.

## SDK consequence

The mode-2/3 packet-decoding routes have separate packet authorities and must not be conflated with the normal mode-1 AI commit path.  They provide further static evidence against a cross-mode writable control field.

# 2026-08-18 — Race-order sorter mutates active records from session-dependent comparisons

## Verified raw facts

- `AIDriverSorting_004BF390` scans `dword_7C54F0[0..VehicleCount)` and compares an input vehicle with matching per-record order keys at `+0x4060`.
- In session type `7`, its ordering branch compares `+0x403C` first and `+0x4098` as a tie-breaker; otherwise it compares `+0x409C` under a non-negative guard.
- On a selected ordering change, it writes order-adjacent fields through `ConditionalFieldSetter` on both records.  It is called by AI behavior/tick and engine-failure paths.

## SDK boundary

Race order is session-conditional, cross-vehicle, and game-mutated.  Treat it as read-only telemetry; do not write the sorter inputs or outputs without a complete lifecycle and multi-vehicle consistency contract.

# 2026-08-18 — Explicit mode-1 transition exists outside opponent setup

## Verified raw facts

- `sub_4DA840_004DA840` explicitly calls `SessionStateTransition((float *)(dword_7C54E8 + 12), (_DWORD *)1, 0)` after its grid/pit-state gates pass.  This is direct receiver proof for `V+0xC` and mode 1.
- That request is conditioned on global/session state, an indexed slot-status array, and outer vehicle field `V+0x4064`; it is followed by game action/state dispatch.

## Correction and SDK consequence

Mode 1 is not statically exclusive to the generated-opponent setup path.  Even with a proven `V+0xC` receiver, the extra grid/pit transition demonstrates broader game/session ownership.  It strengthens the object-identity map but further prevents treating mode 1 itself as an AI-write authorization.

# 2026-08-18 — Constructor proof closes the main-AI mode-check identity

## Verified raw facts

- `RaceStructInit_00423E80` constructs the embedded physics object at `V+0xC` and initially clears `V[0]`.
- `VehicleObjectConstructor_004C6920` then calls `LargeStructFieldSetterWithStoredReference(V, V)`.  That helper explicitly writes `V[0] = V` and stores the same reference at `V+0x4034`.
- Therefore the normal `AIMainUpdate` check `*(DWORD *)(*(DWORD *)V + 0x32C8) == 1` resolves to `V+0x32C8 == 1` under the constructed self-reference.  The embedded dispatcher mode at `P+0x32BC`, with `P=V+0xC`, is the same enclosing address `V+0x32C8`.

## Conclusion

The previously separate-looking outer and indirect AI mode gates are the same constructed vehicle mode field.  This is direct construction-path evidence for the mode-1 eligibility relation used by AI planning and the embedded physics dispatcher.

## SDK boundary

The identity proof improves the map but not write safety: explicit grid/pit and multiplayer transitions still re-own the same field, and no supported external mode-authority or write phase exists.

# 2026-08-18 — Embedded-parent construction link strengthened, with receiver caveat

## Verified raw facts

- `LargeStructFieldSetterWithStoredReference_00424040`, called by `VehicleObjectConstructor(V, V)`, sets its direct receiver's first word to `V`, then calls `F_4FieldPropagation_004E4590` with explicit value `V`.
- `F_4FieldPropagation` writes its receiver's offsets `+0`, `+0x8`, `+0x6E4`, and `+0x32C0` to its explicit value.  The latter offset is exactly the pit-machine base consumed by `VehiclePhysicsModeDispatcher(P+0x32C0)`.
- Pit-machine functions dereference their first word as an enclosing vehicle record, while the physics dispatcher operates the embedded object at `V+0xC`.

## Evidence-backed inference

The omitted receiver in the `F_4FieldPropagation(V)` call is strongly consistent with `P=V+0xC`: it would establish `P[0]=V` and `(P+0x32C0)[0]=V`, matching both the embedded-parent and pit-parent consumers.  The raw Hex-Rays call text does not show that receiver register, so retain this as a construction inference rather than direct instruction-level proof.

# 2026-08-18 — Embedded command aliases have explicit reset and mode-0 seeding paths

## Verified raw facts

- `sub_4E4790`, called during physics construction/reset paths, writes zero to `P+0x3570`, `P+0x3574`, and `P+0x3578`.  These are exactly `V+0x357C/+0x3580/+0x3584` under the established `P=V+0xC` layout.
- `VehicleSetupInitialization_004E49B0`, reached only through dispatcher mode 0, subsequently seeds those three `P` fields from global simulation values.

## SDK consequence

Mode transitions/reset can erase or replace the AI commit trio independently of `AIMainUpdate`.  Reset coverage is now statically known, but it confirms—not removes—the need for mode-aware ownership arbitration before any writable contract could exist.

# 2026-08-18 — Legacy-named gear helpers are outside the per-vehicle AI path

## Verified raw facts

- `AIGearSelectionSet_0042EAA0` operates on a compact indexed table at relative offsets around `+0x6690`, is called only by `IndexedCallWith1Increment_00467340`, and has no vehicle/physics-object evidence.
- `AIShiftPattern_0042B8D0` formats/display-selects shift-pattern text and calls UI/config helpers; it likewise has no call path from `AIMainUpdate`, `PhysicsIntegrationStateMachine`, or the embedded physics dispatcher.

## Boundary

Do not use either legacy label as evidence for the unresolved per-vehicle gear request path.  The only recovered driver-AI gear-related call remains `sub_426330` and its incomplete receiver/terminal-effect chain.

# 2026-08-18 — Exact unrecovered tail of the driver gear-request branch

## Verified raw facts

- `PhysicsGearShiftLogicWithThresholds_00426330` reaches `JUMPOUT(0x004F62E6)` when its current request/state exceeds one.
- `0x004F62E6` is absent from the canonical raw recovery index, and no recovered function body or packet in the corpus covers that address.

## Boundary

The remaining gear-request tail is a specific corpus gap, not evidence that the branch is inert.  Its target behavior, receiver, and terminal vehicle effect remain unproven; it cannot support a writable gear contract.

# 2026-08-18 — Timed AI ability pass owns pace and pit cleanup state

## Verified raw facts

- `AIMainUpdate` schedules `AIAbility_00429470` when its four-second session-time timer expires.
- `AIAbility` recomputes/caps its pace multiplier and difficulty cap, can request `ForcePitExit`, runs tire/fuel decision and post-pit cleanup routes, resets planner/controller state, invokes waypoint reacquisition, and finally calls `RacePhasePitEntryTrigger`.
- The cleanup route changes controller/pit-state fields and invokes `ParameterValueSetter`; it is not a side-band advisory calculation.

## SDK boundary

Pace and pit state are periodically re-owned by the normal AI lifecycle.  A direct writable pace/pit setting would need to coordinate this timer and cleanup path; no safe external contract is proven.

# 2026-08-18 — Static direct-control contract proof audit

| Required proof | Current evidence | Result |
|---|---|---|
| Exact command producer | `AIMainUpdate` commits planner intermediates to the three fields. | Proven. |
| Normal simulation consumer | Executed mode-1 inner steps read all three through `P=V+0xC` aliases. | Proven for executed mode-1 inner steps. |
| Object/mode identity | Constructor establishes `V[0]=V`; `P+0x32BC` aliases the AI mode field.  `P[0]=V` has strong construction inference but an omitted receiver. | Strong, with one receiver caveat. |
| Commit ordering | Main tick runs planning before scene/mode dispatch; mode-1 physics runs only with a positive inner-step count. | Proven game ordering; no external write hook. |
| Reset/arbitration | Physics reset zeroes the trio; mode-0 setup seeds it; pit/countdown and post-physics sentinel paths can replace/effectively override it. | Proven game ownership; excludes naive writes. |
| Valid input range | Steering is clamped; both longitudinal channels have only branch-local/default/cap evidence. | Not proven. |
| Authority/mode scope | Opponent setup, grid/pit, finish/loading, local slot, and network paths all transition/re-own modes. | Not proven for an external writer. |
| Replay/network separation | Mode 2 and mode 3 consume packets from distinct authorities. | Proven separation; no cross-mode contract. |
| Supported action API | Queue and setter routines have incomplete protocol/range contracts. | Not proven. |

## Decision

The authoritative static output-to-normal-mode-1 simulation chain is established.  A safe writable AI-SDK contract is still **not** established: the missing range, authority, scheduling-hook, and cross-session/replay guarantees are independent required proofs, not documentation gaps.

# 2026-08-18 — Database initialization precedes dynamic-driver initialization

## Verified raw facts

- `Game_Init_0042D6B0` calls `AIDatabase_Init(dword_5EA2C0)` before `DynMan_Init()`.
- The same function initializes video/scene state before the AI database and initializes input, effects, then the dynamic manager afterward.

## Boundary

The static startup ordering supports database/profile material being established before dynamic vehicle/driver setup.  It does not prove a live reload path, mutability, or an SDK configuration surface.

# 2026-08-18 — Shared database is the waypoint/track geometry source

## Verified raw facts

- `sub_402690`, invoked only by `AIDatabase_Init`, parses `FEATURES`, grid, pit, and waypoint records; the `NUMBERWAYPOINT` record allocates `316`-byte waypoint entries and the parser fills branch, path, event, position, geometry, width, and linkage fields.
- `AIDriverStructInit`, `AIMainUpdate`, `AIRacingLine`, `AISteering`, and `sub_426430` all query `dword_5EA2C0` for waypoint/nearest-neighbor data.
- Normal non-AI paths—including `VehicleMainPhysicsUpdate` and `SurfaceHeightfieldCollisionCallback`—also query that same object.

## SDK boundary

`dword_5EA2C0` is shared track/waypoint geometry with AI consumers, not an AI-only writable profile object.  Its initialization/parser path offers no verified live-edit or external ownership guarantee.

# 2026-08-18 — Driver initialization binds profile, waypoint, and pit-planning state

## Verified raw facts

- `SceneRenderUpdate_004C6D90` is the sole recovered caller of `AIDriverStructInit_00424790`.
- When its `a2` flag is set, `AIDriverStructInit` clears/sets controller defaults, calls the driver-profile parser `sub_424080`, allocates its command-queue storage, and locates the vehicle's initial nearest waypoint through `dword_5EA2C0`.
- It then calls `sub_429960`, which initializes tire/pit-stop schedule state from vehicle tire data, session globals, seasonal strategy data where applicable, and random generation in other session modes.
- Neither function commits the `V+0x357C/+0x3580/+0x3584` simulation-command trio.

## SDK boundary

Initialization establishes inputs and strategic state but is lifecycle-owned and may include randomness/session data.  It is not a verified stable configuration or control API.

# 2026-08-18 — Traffic/overtake state is computed within the racing-line pass

## Verified raw facts

- `AIRacingLine_00425920`, called by `AIMainUpdate`, queries the shared waypoint graph and its linked route records, evaluates nearby geometry and pass scores, and walks up to twenty linked route entries.
- The normalized profile `PASSING` value at `V+0x44CC` participates directly in that traversal's distance reduction.
- The function writes per-driver traffic/pass state around `V+0x43F8..+0x452C`, including target route/passage values and brake/acceleration-related planner intermediates at `V+0x442C/+0x4430`.
- On route/traffic invalidation it clears several planner flags, resets route state, and re-enters `sub_426430` waypoint acquisition.

## Boundary

This is a stateful planner pass—not an independent external overtake command.  Its state is re-derived from waypoint geometry, nearby state, profile normalization, and session context on ordinary AI updates.

# 2026-08-18 — Overtake route scoring joins profile and waypoint inputs

## Verified raw facts

- `AIComputePassScore_0042A780`, called only by `AIRacingLine`, runs `TireForceSolver` over its supplied waypoint/route entry and returns a product of route data and vehicle controller fields.
- Its controller terms include `V+0x4500/+0x4504`, initialized by the `CORNERINGADD` and `CORNERINGMULT` profile entries in `sub_424080`, alongside other initialized controller multipliers.
- `sub_426430` independently uses the same `V+0x4500/+0x4504` pair while evaluating its acquired waypoint.

## Boundary

The profile affects planning through derived route scores; it is not a direct steering/throttle write path, and field ranges/ownership remain unproven for external use.

# 2026-08-18 — Waypoint acquisition builds the short-horizon planning frame

## Verified raw facts

- `sub_426430` reacquires a nearest waypoint if no current pointer exists or if its tracked position has diverged; it returns failure when no nearest waypoint can be found.
- On an advance it stores the current waypoint, fills nineteen linked look-ahead pointers, calculates a capped progress ratio and distance/state tier, and derives line-intersection/lateral bounds from the selected waypoint geometry.
- When the selected branch route is the special route state, it emits queue message `14` through `AICommandMessageQueueDispatcher` and calls `sub_4A46F0`; otherwise its `sub_4A46F0` call uses zero values.
- The raw code establishes neither an external message protocol nor a safe caller for either queue path.

## Boundary

Waypoint loss is an explicit no-AI-commit gate in `AIMainUpdate`, while acquisition itself is game-owned route-state construction.  The queue side effect is insufficient to constitute a supported command interface.

# 2026-08-18 — Queue records feed internal response state, not a proven external ABI

## Verified raw facts

- `AICommandMessageQueueDispatcher_00424CD0` stores a unique `(message, argument)` pair in the per-driver queue before calling `CommandQueueResponseHandler_00429EE0`.
- The response handler recognizes messages `0`, `4`, `5`, and `14`; these alter controller fields and invoke internal setters/callbacks including `AISpeedDeltaSetter` and `ParameterValueSetter`.
- `sub_4A46F0`'s recovered body is an indexed field setter, but its recovered formal signature conflicts with several raw call forms that pass scalar zero/one values.  This is a decompilation/hidden-receiver ambiguity, not a usable protocol proof.

## SDK boundary

The queue is a verified internal state transition mechanism.  Its message schema, receiver conventions, parameter ranges, timing, and cross-session authority remain unproven; it is not a safe writable SDK surface.

# 2026-08-18 — Queue side effects reach route selection and an AI steering cap

## Verified raw facts

- `AISpeedDeltaSetter_0042ACA0` accepts only `0` or `1` and writes `V+0x4550`; that field is the route/branch selector consumed by `sub_426430`, `AIRacingLine`, and `AIMainUpdate` before steering is scheduled.
- `ParameterValueSetter_0042ACD0` writes its integer argument as a float to `V+0x4538`, using a global value for the special argument `18`.
- `AISteeringCorrection_00426CF0` passes `V+0x4538` to `TrackParameterMinimumClamp_0042A740`, which constrains a separate controller field at `V+0x4484` to no less than `5.0` and no greater than that passed value.

## Boundary

The queue can indirectly alter later route and steering-planner state, but it does not bypass planning or write the physics command trio.  Its only exposed-looking setters remain internal, mode-sensitive operations with no verified external ABI or safe argument contract.

# 2026-08-18 — Candidate traffic evaluation resolves to a lateral planner target

## Verified raw facts

- `AISteering_004270A0` considers up to five nearby vehicle records, queries their route locations against the selected branch, scores collision/pass candidates, and derives bounded lateral alternatives from route width and proximity state.
- It calls `Overtaking_0042AF70` for selected decision cases.  `Overtaking` first rejects candidates through `sub_4F1C20`'s nested-record branch test, then applies session/position/vehicle-state checks before accepting one.  The helper's legacy `ReplayAIStateCheck` label is not semantic proof.
- On acceptance, `Overtaking` records the opponent pointer at `V+0x45FC` and sets the lateral planner target at `V+0x4420` to either `-3.0` or `+3.0`; no physics-command field is written there.
- `AISteering` then selects a constrained lateral target and writes it into its steering-planner state, with route-limit checks capable of setting its replanning flag.

## SDK boundary

Overtaking is an internal nested-record/session-gated choice in the steering planner.  The visible `+/-3.0` values are planner targets, not a direct vehicle-control ABI or independently safe writable range.

# 2026-08-18 — AI command commit is state-dependent with explicit default tail

## Verified raw facts

- After successful waypoint acquisition and in ordinary controller states, `AIMainUpdate_00424E70` orders `OpponentProximityScanTeamRecognition`, `AIRacingLine`, conditional `AISteering`, `sub_426100`, `AISteeringCorrection`, and `PhysicsGearShiftLogicWithThresholds` before its state switch.
- Its normal commit path copies `V+0x442C` to `V+0x357C`, `V+0x4434` to `V+0x3584`, and `V+0x4424` to `V+0x3580`, then clears the controller flag at `V+0x45FC`.
- State `2` calls `FieldZeroSetter` and returns before this commit; failed waypoint acquisition or an outer vehicle-mode mismatch also returns before it.  Those paths preserve the prior command trio.
- States `4` and `5` fall through to an explicit default tail that writes the trio as `(0.0, 0.0, 1.0)` in `(V+0x357C, V+0x3580, V+0x3584)` order.

## SDK boundary

There is no single unconditional AI output each AI tick.  Any writable contract would have to respect the state-dependent commit, no-commit preservation paths, and the default tail; static evidence still supplies no safe external scheduling point.

# 2026-08-18 — Steering is universally bounded; longitudinal intermediates are not

## Verified raw facts

- `sub_426100`, reached after `AISteering`, computes the target steering angle from the selected waypoint geometry, limits the change in `V+0x4424` to `0.1` per invocation, and clamps that field to `[-1.0, +1.0]`.
- `AIMainUpdate` commits that exact `V+0x4424` field to `V+0x3580` on its normal commit path.
- The longitudinal pair `V+0x442C/+0x4434` has writers in `AIRacingLine`, `AISteeringCorrection`, `AIMainUpdate` special-state branches, and state-`1` helper `sub_4258C0`; the observed guards/defaults include several branch-local zeros/ones and conditional corrections.

## SDK boundary

The steering channel has an explicit internal bound and slew limit.  No corresponding universal range proof exists for either longitudinal channel, so they remain unsafe SDK write targets.

# 2026-08-18 — Pit state runs before normal mode-1 integration

## Verified raw facts

- `VehiclePhysicsModeDispatcher_004E4930` reads its mode at `P+0x32BC`.  In mode `1` it calls `PitStateUpdateMachine(P+0x32C0, time)` and then `PhysicsIntegrationStateMachine(time)`.
- `PitStateUpdateMachine_004A6E50` evaluates its own state, vehicle mode/control eligibility, proximity, pit-stop progress/readiness, and state notifications before returning to that integration call.
- Mode `0` also executes the pit state machine, then a separate physics step and setup initialization; mode `2` instead routes to `TeamColorLoader`.

## SDK boundary

Pit behavior is inline with normal local simulation, not an overlay after AI control.  A writer must therefore be mode- and pit-state-aware; no static external arbitration mechanism is recovered.

# 2026-08-18 — Race-order update is a separate active-vehicle pass

## Verified raw facts

- `AITickUpdate_004BF4F0` iterates `dword_7C54F0`, updates lap/time-order fields on eligible vehicles, and calls `AIDriverSorting_004BF390` for each updated entry.
- `AIDriverSorting` compares active vehicles using session-dependent order keys, then changes rank/order fields through `ConditionalFieldSetter`; it does not call `AIMainUpdate` or write the AI command trio.
- The recovered raw callers of `AITickUpdate` are none, and the recovered raw callers of `AIDriverSorting` are its initialization/failure/tick paths—not `MainGameTickUpdate_0042C690`.

## Boundary

Race order is shared vehicle telemetry/state, not an AI-control output.  Static evidence does not prove this pass's precise phase relative to the main 2.5-ms tick, so no writable ordering hook follows from it.

# 2026-08-18 — Main tick orders all AI updates before the scene bridge every tenth step

## Verified raw facts

- `MainGameTickUpdate_0042C690` advances a catch-up loop in `0.0025` increments.  When `dword_7C5698 % 10 == 0`, it calls `AIMainUpdate` for every entry in `dword_7C54F0` before `LoopWithConditionalSkipFunction(dword_5EA560, time)`.
- The loop bridge invokes `SceneObjectLoaderStateMachine_0040F1C0` for each scene entry.  In scene state `6`, that function conditionally invokes `VehiclePhysicsModeDispatcher(time)`, then updates suspension state and scene position.
- On the other nine counter values, `MainGameTickUpdate` directly invokes `VehiclePhysicsModeDispatcher` only for `dword_7C54E8` when its explicit guards pass.

## Evidence-backed inference

The scene-state-6 dispatcher call has an omitted receiver.  Its scene object points to the vehicle record used immediately afterward, and constructor evidence strongly supports the embedded physics receiver `P=V+0xC`; this remains a receiver inference, not direct call-text proof.

## SDK boundary

The game-known AI-before-scene ordering is proven on every tenth internal 2.5-ms step.  It does not provide an external write phase, and it does not establish that every vehicle receives a physics step on every internal increment.

# 2026-08-18 — All three AI command aliases are consumed inside executed inner physics steps

## Verified raw facts

- `PhysicsIntegrationStateMachine_004E4E60` runs its wheel/force pipeline only while its computed inner-step count is positive; otherwise it updates time state without executing that pipeline.
- Each executed inner step calls `sub_4E51A0` and `WheelForceCalculationSpringDamperTorque_004E5470`.
- `sub_4E51A0` uses `P+0x3570` and `P+0x3578` in its wheel/force coefficient calculations.  `WheelForceCalculationSpringDamperTorque` uses `P+0x3574` to compute the steering trigonometry used by wheel contact/force work.
- Under the established embedded-object layout, these are `V+0x357C`, `V+0x3584`, and `V+0x3580`, respectively—the exact AI commit trio.

## Boundary

The normal simulation consumer is proven for executed mode-1 inner steps, not as an unconditional consequence of every dispatcher call.  The evidence proves game-internal consumption, not a safe external write timing or range contract.

# 2026-08-18 — Superseding correction to the authoritative readiness ledger command row

## Verified raw facts

- The direct `AIMainUpdate_00424E70` commit is `V+0x442C -> V+0x357C`, `V+0x4424 -> V+0x3580`, and `V+0x4434 -> V+0x3584`.
- `V+0x4438` is not one of the three direct final commits in that raw function.

## Ledger correction

Supersede the steering/longitudinal mapping row in the ledger headed “Current authoritative core-AI readiness ledger” with the offsets above.  Its overall decision remains unchanged: all three normal-mode consumers are statically established, but no safe writable SDK contract is proven.

## Historical-claim boundary

All earlier report prose or copied comments that map `V+0x4438 -> V+0x3584`, `V+0x4434 -> V+0x357C`, or `V+0x442C -> V+0x3580` are superseded by the direct raw assignments in `AIMainUpdate_00424E70`.  They remain preserved as historical investigation material, not current evidence.

# 2026-08-18 — Current authoritative core-AI map (supersedes earlier summaries)

| Area | Current evidence | Writable-contract result |
|---|---|---|
| Initialization/profile | `Game_Init` initializes the shared AI/track database before `DynMan_Init`; scene lifecycle calls `AIDriverStructInit`, which parses profile data and binds nearest-waypoint/pit-planning state. | Lifecycle-owned, read-only. |
| Scheduling | Every tenth 2.5-ms catch-up step calls all `AIMainUpdate` instances before the scene loop; scene state 6 conditionally reaches the physics dispatcher. | No external write phase. |
| Planning/traffic | `sub_426430` builds a waypoint horizon; `AIRacingLine`/`AISteering` derive traffic and lateral choices; `Overtaking` can set an internal `+/-3.0` lateral target. | Planner state only, not a public action ABI. |
| Final AI command commit | Normal path: `V+0x442C -> V+0x357C`, `V+0x4424 -> V+0x3580`, `V+0x4434 -> V+0x3584`; state/waypoint gates can preserve prior values; pit/countdown tail writes defaults. | Steering range is internal-proven; longitudinal ranges and safe scheduling are not. |
| Normal simulation path | The embedded receiver is strongly established as `P=V+0xC`; executed mode-1 inner steps consume `P+0x3570/+0x3574/+0x3578`, respectively. | Strong static game-path proof, with an omitted-receiver caveat at the scene dispatch call. |
| Gear | `PhysicsGearShiftLogicWithThresholds` issues internal request paths; its `0x004F62E6` tail remains absent from recovered raw code. | No terminal gearbox or writable request contract. |
| Pit/race order | Pit machine runs before mode-1 integration; race-order sorting is a separate active-vehicle mutation pass. | Both are game-owned; no external authority/timing proof. |

## Current contract decision

No safe writable core-AI SDK contract is proven by the static corpus.  The only defensible current SDK posture is observational telemetry whose lifetime is explicitly invalidated by lifecycle/mode transitions.  Do not expose control, mode, profile, pit, queue, or override fields for writing without new authority, range, timing, and replay/network evidence.

# 2026-08-18 — Gear requests have a recovered delayed application stage

## Verified raw facts

- `RaceStartCountdownStateUpdate_004EF930`, called by recovered `PhysicsGearShiftLogicWithThresholds` branches, writes a requested gear/state value to its `+0x3A08` field and arms a timing field.
- `SuspensionSpringDampingRateReset_004E4F40`, called at the start of every executed `PhysicsIntegrationStateMachine` inner step, invokes `BrakeCoolingPostTreatment_004E5080` while that timing field is positive.
- On expiry, `BrakeCoolingPostTreatment` copies its `+0x3A08` request into its `+0x39F0` current-state field; the reset helper then updates dependent threshold/ratio state when the current-state field changes.

## Boundary

The exact relationship between the AI helper receiver and the embedded physics receiver is omitted in the relevant call text, so this establishes an internal delayed request/application mechanism, not a fully receiver-resolved terminal AI-gear contract.  The unrecovered `0x004F62E6` downshift tail remains a separate gap.

# 2026-08-18 — Embedded physics offset is direct constructor evidence

## Verified raw facts

- `VehicleObjectConstructor_004C6920` calls `RaceStructInit_00423E80` on the vehicle record `V`.
- `RaceStructInit` directly calls `PhysicsTireSystemConstructor(V + 3)`, establishing the embedded physics object base `P = V + 0xC` without a receiver inference.
- The vehicle constructor subsequently calls `LargeStructFieldSetterWithStoredReference(V, V)`, which directly establishes `V[0] = V` and stores `V` at `V+0x4034`.

## Boundary

The separate `F_4FieldPropagation` call still has an omitted receiver, so a claim that it writes `P[0] = V` remains inference.  The `P=V+0xC` offset itself is direct raw constructor evidence.

# 2026-08-18 — Final-slot writer audit distinguishes normal AI from packet paths

## Verified raw facts

- Raw references to `V+0x357C` (`13692`) show direct writes only in `AIMainUpdate`; `SetupCarLightingAndRender` serializes that field separately.
- `V+0x3580` (`13696`) and `V+0x3584` (`13700`) are also written by `VehiclePhysicsTimeStep_004C73F0`, whose recovered callers are the distinct packet/mode routes.  `DriverInputController` reads selected-vehicle instances of these fields.
- `AIMainUpdate` remains the recovered normal-AI producer of all three final slots; its writes do not establish ownership against the packet/session paths.

## SDK boundary

The slot address alone cannot identify authority.  A writable contract must exclude packet/replay/session routes and selected-driver input interaction; the static corpus supplies no supported selector or arbitration API.

# 2026-08-18 — Selected-driver input reads final slots for device feedback

## Verified raw facts

- `MainGameTickUpdate_0042C690` calls `DriverInputController_00451720` after its catch-up loop.
- `DriverInputController` reads `dword_7C54E0 + 0x3580` and `+0x3584` in its selected-driver/device handling, transforms them into bounded device values, and dispatches through input-device callbacks.
- The recovered raw body does not write those final slots.

## SDK boundary

Selected-driver input interaction is a downstream consumer, not authority to write AI commands.  It reinforces the need to keep a future control contract separate from player/device and packet routes.
# 2026-08-18 — AIRacingLine direct-write correction

Raw `AIRacingLine_00425920` directly writes `V+0x4424` (`this+17460`) and
`V+0x4428` (`this+17464`) while calculating its look-ahead/traffic horizon.
It does **not** directly write `V+0x442C` or `V+0x4434` in the recovered raw
body. Therefore, any earlier statement that attributes direct writes of those
two fields to `AIRacingLine` is superseded. The direct final-slot commit remains
owned by `AIMainUpdate_00424E70`; the intervening producer relationship needs
separate evidence.

# 2026-08-18 — Final-command offset correction (authoritative)

The preceding `AIRacingLine` correction misconverted decimal offsets and is
superseded by this raw-offset audit. In `AIMainUpdate_00424E70`, the normal and
countdown commit assignments are:

- `V+0x4434` (`this+17460`) → `V+0x357C` (`this+13692`)
- `V+0x442C` (`this+17452`) → `V+0x3580` (`this+13696`)
- `V+0x4438` (`this+17464`) → `V+0x3584` (`this+13700`)

`AIRacingLine_00425920` directly writes the first and third planner fields
(`V+0x4434`, `V+0x4438`) but not `V+0x442C` in its recovered raw body. It is
therefore a direct upstream writer of two committed values, while the producer
of `V+0x442C` remains separately traced. All earlier offset mappings that
conflict with this table are non-current.

# 2026-08-18 — Verified steering branch to final simulation input

`sub_426100_00426100`, called by `AIMainUpdate_00424E70` after
`AIRacingLine`/conditional `AISteering`, is the only recovered core writer of
`V+0x442C`. It derives a signed angle from the selected look-ahead waypoint,
slews the previous value by at most `0.1`, and clamps it to `[-1.0, 1.0]`.
`AIMainUpdate` then copies that field to `V+0x3580` in the normal commit.

This proves the recovered AI steering computation-to-final-slot chain, but
does not prove a writable SDK ABI, lifetime, or arbitration guarantee.

# 2026-08-18 — Verified longitudinal arbitration before commit

`AISteeringCorrection_00426CF0` runs after `sub_426100` and before the normal
`AIMainUpdate` commit. It directly adjusts `V+0x4434` based on absolute
`V+0x442C`, grip/stability conditions, racing-line correction, and the
difficulty-derived cap; it also switches or raises `V+0x4438` in its distance
and grip branches while zeroing the opposing longitudinal field. The normal
commit copies these fields to `V+0x357C` and `V+0x3584`, respectively.

Thus the recovered per-AI-tick command chain is planner → steering target
`V+0x442C` → longitudinal arbitration (`V+0x4434`/`V+0x4438`) → final slots.
Field semantics beyond observed control behavior remain inference and are not
an SDK write contract.

# 2026-08-18 — Resolved final-slot to normal-physics layout link

`RaceStructInit_00423E80` directly calls `PhysicsTireSystemConstructor(this +
3)`, establishing the physics subobject base `P = V+0xC`. Consequently the
three committed vehicle fields translate exactly to `P+0x3570`, `P+0x3574`,
and `P+0x3578`.

`PhysicsIntegrationStateMachine_004E4E60` executes its normal inner-step
pipeline through `sub_4E51A0` and `WheelForceCalculationSpringDamperTorque`.
The former reads `P+0x3570` and `P+0x3578`; the latter directly uses
`P+0x3574` in its steering-angle trigonometry. This is static, direct evidence
that the committed three-field vector reaches normal physics, subject to the
existing mode/tick gates and reset/override ownership evidence.

# 2026-08-18 — Final-input reset ownership

`PhysicsTireSystemConstructor_004E4500` calls `sub_4E4790` during construction.
That function directly zeros `P+0x3570`, `P+0x3574`, and `P+0x3578` (the
translated final vehicle slots) and has additional recovered reset/config
callers. A value injected before this lifecycle operation is therefore not
durable. This is another reason static evidence cannot establish a safe
writable contract without lifecycle and arbitration proof.

# 2026-08-18 — AI driver initialization ordering

When its initialization flag is set, `AIDriverStructInit_00424790` first resets
AI state/defaults, then calls profile parser `sub_424080`, initializes the
internal command queue, resolves the vehicle's nearest shared-database
waypoint, and invokes `sub_429960` pit scheduling. It subsequently derives
the difficulty interpolation value. This establishes profile input as an
initialization dependency of planning/pit state, not a safe live-control
surface.

# 2026-08-18 — Profile inputs reach racing-line planning

`sub_424080` stores normalized `CORNERINGADD` and `CORNERINGMULT` at
`V+0x4500`/`V+0x4504`, and derives a rain-related factor at `V+0x4580`.
`AIComputePassScore_0042A780`, called by `AIRacingLine_00425920`, directly
multiplies those fields with `V+0x453C` and the waypoint tire-force result.
This is a verified profile → planning-data path; it does not establish that
the source profile data is safe to mutate after initialization.

# 2026-08-18 — Gear request and delayed application

`PhysicsGearShiftLogicWithThresholds_00426330` asks
`RaceStartCountdownStateUpdate_004EF930` for an upshift, neutral, or reverse
request. The latter stores the requested gear at its receiver `+0x3A08` and
arms a timer at `+0x3A04`. During each normal integration inner step,
`SuspensionSpringDampingRateReset_004E4F40` runs the timer helper; on expiry,
`BrakeCoolingPostTreatment_004E5080` copies `+0x3A08` to the current-gear
field `+0x39F0`, which the caller then uses to recompute dependent ratios.

The static dataflow establishes delayed request-to-application behavior.
Because the decompiled zero-argument helper call omits the receiver at that
edge, the identity of this physics receiver with the AI vehicle remains a
layout/calling-convention inference rather than a writable SDK contract.

# 2026-08-18 — Pit-strategy scheduling and entry handoff

`sub_429960` initializes tire/stop schedule arrays from session strategy data
or session-specific randomized schedules. `AIAbility_00429470`, invoked on
the four-second `AIMainUpdate` cadence, updates pace/pit decisions and calls
`RacePhasePitEntryTrigger_00429EB0`. The trigger reads fuel state and, when
the route selector `V+0x4550` is clear in the relevant session phase, calls
`ForcePitExit_0042A110`. This maps scheduling through the AI decision gate;
the downstream pit-state machine remains mode-owned, not an SDK write surface.

# 2026-08-18 — Pit readiness can request neutral

`PitStopReadyCheck_004A6200`, reached from `PitStateUpdateMachine`, calls
`RaceStartCountdownStateUpdate(0)` when its associated vehicle mode is `1`
before checking pit-stop readiness. This is a distinct pit-state-to-gear-
request interaction. As at the other omitted-receiver helper edges, the exact
receiver identity requires calling-convention confirmation before it could
support a writable contract.

# 2026-08-18 — Command queue is internal state machinery

`AICommandMessageQueueDispatcher_00424CD0` stores de-duplicated `(message,
argument)` pairs in an AI-owned allocation and immediately invokes
`CommandQueueResponseHandler_00429EE0`. The recovered message handling only
sets internal route/state/parameter fields and delegates to AI helpers; it
does not write the final command vector. The queue's allocation, timing, and
receiver semantics are internal, so it is not a safe SDK command API.

# 2026-08-18 — Active vehicle list is broader than AI authority

`BuildActiveVehiclePointerArray_0042BC80` rebuilds `dword_7C54F0` by including
every stride-indexed vehicle whose `+0x32C8` field is not `-1`; its callers
include dynamic initialization, loading, network synchronization, and
multiplayer join handling. Presence in the list is therefore lifecycle
membership, not proof that a vehicle is AI-controlled or safe to write.

# 2026-08-18 — Race-order path is separate from command generation

`AITickUpdate_004BF4F0` updates active-vehicle lap/timing fields and calls
`AIDriverSorting_004BF390`. The sorting routine compares race/lap timing and
reorders the relevant order fields through `ConditionalFieldSetter`; its
recovered raw body contains no AI planner, final-command, or physics-input
writes. Race order can influence surrounding state, but is not a direct member
of the authoritative control-output chain.

# 2026-08-18 — Overtake state is upstream planner state

`Overtaking_0042AF70`, called by `AISteering_004270A0`, applies session and
candidate gates, then records the selected opponent at `V+0x45FC` and sets a
lateral request at `V+0x4420` to `+3.0` or `-3.0`. Its recovered raw body does
not write the final command vector. The overtake decision is therefore
upstream traffic/planner state whose output is later incorporated by steering,
not a direct vehicle-control API.

# 2026-08-18 — Physics mode ordering caveat

Raw `VehiclePhysicsModeDispatcher_004E4930` runs `PitStateUpdateMachine`
before its mode-1 `PhysicsIntegrationStateMachine` call; mode 0 also runs pit
state before setup/integration work. `SceneObjectLoaderStateMachine_0040F1C0`
reaches this dispatcher from its vehicle scene state. The decompiler omits or
mis-types receiver arguments at these calls, so the exact scene-object-to-
physics-instance identity is an inference. The ordering is verified; an SDK
must not treat it as proof of a stable writable mode/control ABI.

# 2026-08-18 — Tick cadence and command-before-physics ordering

`MainGameTickUpdate_0042C690` advances fixed `0.0025` simulation steps. On
steps where `dword_7C5698 % 10 == 0`, it calls `AIMainUpdate` for every active
vehicle before `LoopWithConditionalSkipFunction` processes scene objects; it
then runs post-scene `sub_4EE2D0` for each physics subobject. On other steps,
it dispatches the selected vehicle's physics mode under guards. Thus the
recovered cadence places normal AI command commit before the periodic scene
physics pass, while later stages may still override/re-own inputs.

# 2026-08-18 — Post-scene mode-1 override path

On the periodic post-scene pass, `sub_4EE2D0` mode 1 calls
`ThrottleBrakeOverride_004EE230`. That helper reads `P+0x3570`, derives a
value from it, and substitutes that value only where its three independent
source fields carry the `-789.0` sentinel; otherwise it copies those source
fields to downstream outputs. This is a post-scene consumer/conditional
override path, not the normal AI final-slot commit, and it prevents treating
the observed slot alone as an uncontested control contract.

# 2026-08-18 — Physics mode has non-AI owners

`SessionStateTransition_004EF5A0` writes its receiver's `+0x32BC` mode field
and performs additional cleanup when entering mode `1`. Recovered callers
include loading, restart, finish, multiplayer/network, and AI setup paths.
Therefore the AI setup path selects participation but does not exclusively own
mode transitions. Any writable interface must account for these external
lifecycle owners; static evidence does not establish safe arbitration.

# 2026-08-18 — Waypoint horizon construction

`sub_426430` resolves/reacquires the nearest shared-database waypoint and,
when its route state changes, fills nineteen linked look-ahead waypoint
pointers. It records the selected branch in `V+0x4550`, derives speed/horizon
metrics and steering bounds, and can emit internal queue message `14` at a
route transition. This is verified planner-state construction, not a public
queue or route-selection ABI.

# 2026-08-18 — State-2 commit bypass preserves prior vector

In `AIMainUpdate_00424E70`, state `2` calls `FieldZeroSetter_00425660` and
returns before the normal final-slot assignments. The helper writes only
`V+0x4510 = 0`; it does not write `V+0x357C`, `V+0x3580`, or `V+0x3584`.
Accordingly the prior command vector is preserved on that branch, another
timing/lifetime condition that a writable contract would need to specify.

# 2026-08-18 — Packet-mode final-slot writer

`VehiclePhysicsTimeStep_004C73F0` decodes its packet argument, clamps the
decoded scalar, and when `V+0x32C8 == 2` writes it to `V+0x3580`; it also
writes `V+0x3584` from a packet bit. Recovered callers are packet-oriented
`TeamColorLoader_004F03E0` and `sub_4F0430`, not `AIMainUpdate`. Therefore
the only additional recovered final-slot writer is a distinct packet/mode
route, which must remain excluded from any AI control contract.

`TeamColorLoader_004F03E0` obtains a temporary packet through
`UtilityFunction_3d50(dword_7CD25C, vehicle-id, packet, time)` and passes that
packet to `VehiclePhysicsTimeStep`. This directly confirms the mode-2 writer's
packet provenance on that route.

`sub_4F0430` also obtains a packet through `sub_4B9AC0` in its mode-3 branch
and calls `VehiclePhysicsTimeStep` for the stride-indexed vehicle. This is a
second recovered non-AI packet path to the same final-slot writer.

# 2026-08-18 — Final inputs also enter a packet-packing path

`SetupCarLightingAndRender_004C71C0` reads its receiver's translated control
fields at `+0x357C`, `+0x3580`, and `+0x3584` and encodes them into an output
buffer. The recovered function establishes serialization/packing, not a
network authority or safe mutation point. It adds another subsystem boundary
that a writable contract would need to preserve.

# 2026-08-18 — Writable-contract completion audit (current)

The static corpus now proves the AI update order, planner-to-final-vector
assignments, normal physics consumption, reset ownership, packet-mode writers,
and serialization/input consumers. It does **not** prove the following
requirements for a safe writable SDK contract:

- a stable public object identity across the scene/physics receiver boundary;
- exclusive or arbitrated ownership against lifecycle, packet, pit, and
  post-scene paths;
- full valid ranges/semantics for the two longitudinal fields;
- a supported injection phase that survives every mode/state transition;
- replay/network parity and deterministic behavior under writes.

Accordingly, no writable AI-SDK contract is currently proven. The evidence
supports only observational use until those requirements are independently
established; this is a conclusion from missing/contradictory authority
evidence, not a claim that the AI command vector is unmapped.

# 2026-08-18 — Difficulty feeds live control stages

`AIDifficultyScalar_00424750` maps the global difficulty value to `1.0` at
`>=95`, otherwise to a linear value beginning at `0.75`. It is called by both
`AISteeringCorrection_00426CF0` and `AIAbility_00429470`, so the global
difficulty setting directly influences live longitudinal correction and pit/
pace behavior after initialization. This is a verified input dependency, not
an authorized per-driver write surface.

# 2026-08-18 — Normal longitudinal helper ranges

`BrakeThermalModel_004E87E0` and `TireGripCoefficient_004E88B0`, both used by
`AIRacingLine`/`AISteeringCorrection` to produce longitudinal planner values,
explicitly clamp their results to `[0.0, 1.0]`. This bounds those particular
normal-path sources, but does not prove a complete permissible range or stable
semantics for every final longitudinal write branch.

# 2026-08-18 — Mode-0 re-seeds normal physics inputs

`VehicleSetupInitialization_004E49B0`, called by the mode-0 dispatcher path,
writes `P+0x3570`, `P+0x3574`, and `P+0x3578` from global setup values. Thus
mode transition/setup can replace the translated AI command inputs even after
the constructor reset. This is direct re-ownership evidence and rules out
assuming injected values survive mode changes.

# 2026-08-18 — Vehicle self-reference layout evidence

`VehicleObjectConstructor_004C6920` calls
`LargeStructFieldSetterWithStoredReference_00424040(V, V)`. That helper stores
`V` at `V[0]` and at `V+0x4034`; `RaceStructInit_00423E80` constructs the
physics subobject at `V+0xC`. These are direct construction facts supporting
the vehicle/physics layout translation, while unresolved receiver edges still
prevent treating it as a stable external object ABI.

# 2026-08-18 — Proximity scan traffic records

`OpponentProximityScanTeamRecognition_0042A7D0` clears and rebuilds five
nearest-opponent records each AI update. In the relevant session/distance
branch it records a target at `V+0x45FC` and sets lateral planner state
`V+0x4420` to `-2.5` or `+2.5`; `Overtaking_0042AF70` has separate `±3.0`
writes. Neither function writes the final command vector directly.

# 2026-08-18 — `V+0x442C` writer-audit correction

The earlier statement that `sub_426100_00426100` is the only recovered core
writer of `V+0x442C` is superseded. `AISteeringRacingLineCorrection_0042B0E0`,
called conditionally by `AISteeringCorrection_00426CF0`, also writes
`this[4363]` (`V+0x442C`) from an angle calculation and clamps that result to
`[-1.0, 1.0]`. `sub_426100` remains the normal preceding steering-target
writer with its `0.1` slew limit; the correction stage can replace it in its
session-gated branch before final commit.

The indexed-field audit further identifies initialization writes in
`RaceStructInit_00423E80` and `AIDriverStructInit_00424790`; outside those
lifecycle writes, the recovered steering planner writers are
`sub_426100` and `AISteeringRacingLineCorrection`.

# 2026-08-18 — Longitudinal planner writer-audit expansion

Indexed raw writes show that `AIAbility_00429470` can set
`V+0x4434 = 0` and `V+0x4438 = 1` in its pit/pace path, while
`AISteeringRacingLineCorrection_0042B0E0` can set or cap `V+0x4434` in its
session-specific correction path. These add to `AIRacingLine` and
`AISteeringCorrection` as upstream writers before `AIMainUpdate` commits the
two fields. The final vector is therefore not sourced by one simple,
uncontested longitudinal producer.

# 2026-08-18 — Queue/pit parameter fields are not final controls

`ParameterValueSetter_0042ACD0` writes only `V+0x4538` (mapping message `18`
to a special float). `TrackParameterMinimumClamp_0042A740`, used by steering
and correction paths, separately writes/caps `V+0x4484` to a minimum of `5`.
Neither helper writes the final control vector; their differing state scopes
reinforce that queue/pit parameters are internal planner inputs.

# 2026-08-18 — Shared waypoint database record construction

`sub_402690`, invoked by `AIDatabase_Init`, reads `NUMBERWAYPOINT`, allocates
`316`-byte waypoint records, and parses per-record branch ID, path, event,
position, groove, width, and pointer fields. `sub_426430` consumes this shared
database to build each vehicle's look-ahead horizon. This is initialization
data construction, not a live per-driver writable control surface.

# 2026-08-18 — Push-lap strategy affects pace and pit exit

`AIPushLap_0042A180`, called from the scheduled `AIMainUpdate` path, adjusts
the pace field `V+0x453C`, derives the rain-related multiplier at `V+0x4580`,
and can call `ForcePitExit` based on schedule, tyre, weather, or tyre-state
conditions. It is another upstream strategy owner rather than a final-control
writer.

# 2026-08-18 — Revised authoritative static core-AI map

This summary supersedes every earlier summary in this report where an offset
mapping conflicts with it.

In particular, the earlier paragraph beginning “All earlier report prose” and
the table immediately following it (around the prior `# Current authoritative`
heading) are invalid: they inverted the correct raw mappings. The direct raw
assignments, retained in the table below, are authoritative:
`V+4434→V+357C`, `V+442C→V+3580`, and `V+4438→V+3584`.

| Area | Verified static path |
|---|---|
| Database/profile initialization | `Game_Init` → `AIDatabase_Init` → `sub_402690`; `AIDriverStructInit` → `sub_424080` → queue/nearest waypoint/pit schedule |
| Tick | `MainGameTickUpdate`: fixed `0.0025`; every tenth substep calls each `AIMainUpdate` before scene processing |
| Planning | `sub_426430` builds nearest/19-waypoint horizon; `AIRacingLine`, `AISteering`, proximity/overtake, and correction stages update planner state |
| Steering planner | `sub_426100` slews/clamps `V+442C`; session-gated `AISteeringRacingLineCorrection` can replace it, also clamped to `[-1,1]` |
| Longitudinal planner | `AIRacingLine`, `AISteeringCorrection`, `AIAbility`, and correction/pit paths update `V+4434` and `V+4438` |
| Commit | `AIMainUpdate`: `V+4434→V+357C`, `V+442C→V+3580`, `V+4438→V+3584`; state 2 preserves the existing final vector |
| Normal physics | construction gives `P=V+0xC`; thus final vector maps to `P+3570/+3574/+3578`, consumed in normal integration and wheel force computation |
| Competing owners | reset/setup, mode transitions, post-scene sentinel override, and packet modes can replace, consume, or serialize the fields |
| Gear/pit/order | AI gear requests are delayed in physics; pit state can issue a neutral request; race sorting is a separate order-only path |

The command and consumption chains are statically mapped. A safe writable SDK
contract remains unproven because its identity, lifecycle, ownership,
arbitration, and replay/network guarantees are not established by this
evidence.

# 2026-08-18 — AI default final-vector fallback

The `AIMainUpdate_00424E70` tail directly writes the final vector
`(V+0x357C, V+0x3580, V+0x3584) = (0, 0, 1)` after its non-normal/pit state
path. Countdown and state-specific branches also commit their own planner
values. A write to any one final field therefore competes with AI's explicit
per-state fallback policy even before lifecycle or packet ownership is
considered.

# 2026-08-18 — AI initialization follows respawn/physics reset

`SceneRenderUpdate_004C6D90` performs `VehicleRespawnReset`, physics
configuration, scene/delegate setup, then calls `AIDriverStructInit`. This
places driver-AI state/profile initialization after a vehicle lifecycle reset;
its callers include restart and network synchronization paths. It is another
reason initialization-derived pointers/fields cannot be assumed durable across
external lifecycle transitions.

# 2026-08-18 — Grid-reset path directly clears the normal physics inputs

`sub_4C6E80` (called from dynamic-manager, network-slot-sync, and driver-entry
paths) passes `V+0xC` to `sub_4E4790` before resetting driver data and selecting
AI drivers. `sub_4E4790` directly zeroes its `+0x3570`, `+0x3574`, and
`+0x3578` fields—the translated physical inputs corresponding to
`V+0x357C/+0x3580/+0x3584`. Thus grid/reset processing is a verified owner of
the final input vector, independently of the normal AI commit.

# 2026-08-18 — Scene initialization resets physics inputs before driver AI

The `LargeConfigFunctionWithPhysicsConstants_004E45B0` call in
`SceneRenderUpdate_004C6D90` begins with `sub_4E4790(this+3)`. Since the scene
path subsequently calls `AIDriverStructInit`, the lifecycle ordering is:
physics-input reset/configuration, then driver-AI initialization. This is
direct raw-call evidence, not a claim that AI init itself writes every final
input field.

# 2026-08-18 — Direct normal-physics consumption of all three final inputs

In `PhysicsIntegrationStateMachine`, `sub_4E51A0` reads `P+0x3570` and
`P+0x3578` (`this+13680` and `this+13688`) while calculating wheel/axle state.
Its sibling `WheelForceCalculationSpringDamperTorque_004E5470` reads
`P+0x3574` (`this[3421]`) into a trigonometric wheel-force calculation. The
normal integration path therefore has raw direct consumers for each translated
member of the AI final vector; their semantic control labels remain inference,
not an SDK write contract.

# 2026-08-18 — Correction: physics timer helper overwrites `P+0x3570`

This supersedes the earlier report claims that
`BrakeCoolingPostTreatment_004E5080` copies a `+0x3A08` gear request to
`+0x39F0`. The raw function instead decrements `a1+0x3A04`, then, while it is
positive, computes and clamps `a1+0x3570` to `[0,1]`; on expiry it copies
`a1+0x3A08` to `a1+0x39E0` (`+14832`), not `+0x39F0`. Its caller
`SuspensionSpringDampingRateReset_004E4F40` invokes it during normal
integration when `+0x3A04` is positive. This verifies a physics-side overwrite
of the AI final vector's first translated component and leaves the full
AI-request-to-current-gear chain unproven.

# 2026-08-18 — Complete translated-slot writer audit (raw numeric search)

The raw corpus occurrences of `P+0x3574` and `P+0x3578` show direct writes
only in `sub_4E4790` (zero reset) and `VehicleSetupInitialization_004E49B0`
(global-derived initialization) among recovered functions. `P+0x3578` also has
an in-step conditional write of `1.0` in `sub_4E51A0`; `P+0x3570` additionally
has the clamped timer-helper write above and an in-step zero path in that same
function. Therefore the entire vector has verified non-AI writers, including
normal-physics in-step writers for its first and third members. Numeric search
is evidence of recovered-source coverage, not proof that no missing/decompiler-
opaque writer exists.

# 2026-08-18 — Vehicle-side final-slot writer audit

For the vehicle-base locations, raw numeric searches show direct writes to
`V+0x3580` and `V+0x3584` in `AIMainUpdate_00424E70` and
`VehiclePhysicsTimeStep_004C73F0`. The other recovered numeric matches are
read/serialization sites or use `V+0x3580` only as the base of a separate
per-wheel array (`sub_4E5AE0` and `TireGripLateralForceCalculation_004E9300`).
This strengthens the ownership map but does not establish call-time arbitration
between AI, packet, and translated physics-input paths.

# 2026-08-18 — Packet overwrite conditions are explicit

`VehiclePhysicsTimeStep_004C73F0` first clamps a packet-derived scalar to
`[-1,1]`. It writes that scalar to `V+0x3580` only when `V+0x32C8 == 2`, then
unconditionally maps packet bit `0x04000000` to `V+0x3584` as `1.0` or `0.0`.
The raw function is called by `TeamColorLoader_004F03E0` and `sub_4F0430`.
These are concrete packet-side ownership conditions, but the static corpus does
not prove their ordering against `AIMainUpdate` for every session mode.

# 2026-08-18 — Physics mode dispatch separates normal and packet paths

`VehiclePhysicsModeDispatcher_004E4930` switches on receiver `+0x32BC`.
Mode `0` runs pit handling, a vehicle integration step, and
`VehicleSetupInitialization`; mode `1` runs pit handling then
`PhysicsIntegrationStateMachine`; mode `2` calls `TeamColorLoader`, which
fetches a packet and calls `VehiclePhysicsTimeStep`. The recovered decompiler
omits/mistypes the receiver at several `__thiscall` sites, so this establishes
the mode routing but not a complete per-vehicle call ABI for a writable SDK.

# 2026-08-18 — Fixed-substep schedule: AI commit and selected-vehicle dispatch

`MainGameTickUpdate_0042C690` advances fixed `0.0025` substeps (with a 201-step
catch-up cap). On substeps where `dword_7C5698 % 10 == 0`, it loops active
vehicles through `AIMainUpdate`, then invokes the scene loop and per-vehicle
post-scene functions. On the other nine substeps it conditionally calls
`VehiclePhysicsModeDispatcher` for `dword_7C54E8`. Thus raw scheduling proves
the AI batch precedes the scene loop on its tenth-substep cadence; it does not
by itself identify every receiver or establish universal write arbitration.

# 2026-08-18 — Same-substep per-object dispatch after the AI batch

`LoopWithConditionalSkipFunction_00410980` iterates scene objects through
`SceneObjectLoaderStateMachine_0040F1C0`. Its state `6` branch conditionally
calls `VehiclePhysicsModeDispatcher` when the associated vehicle's `+0x48B4`
has bit `8`, then runs `SuspensionStateUpdate`. Consequently, on the AI
substep, the recovered call order is AI batch → scene-object iteration →
per-object vehicle-mode dispatch for eligible state-6 objects. The decompiler
again omits the dispatcher receiver, so this is ordering evidence rather than
a safe injection boundary.

# 2026-08-18 — Driver-AI init seeds only the steering planner member

`AIDriverStructInit_00424790` directly sets `this[4363]` (`V+0x442C`) to zero,
along with extensive AI state/queue/profile defaults. In the recovered raw
body, it does not directly initialize `V+0x4434` or `V+0x4438`, the two
longitudinal planner members copied by the normal `AIMainUpdate` commit. The
preceding scene physics reset and subsequent planner stages are therefore
material to their initial lifetime; no field should be exposed as stable merely
because its adjacent planner member has an explicit driver-init value.

# 2026-08-18 — Racing-line planner selects between the two longitudinal members

`AIRacingLine_00425920` directly writes `V+0x4434` (`this+17460`) and
`V+0x4438` (`this+17464`) in mutually selecting branches: multiple recovery and
low-horizon paths set one member to `0` and derive/set the other, while the
look-ahead path sets `V+0x4434` to `0` and obtains `V+0x4438` from
`TireGripCoefficient` with a local per-update rise limit. This is direct
planner provenance for the two values later copied to the final vector; it does
not make either member independently writable.

# 2026-08-18 — Steering planner has a local slew/range contract only

`sub_426100` computes a look-ahead route angle, limits change against the
previous `V+0x442C` value to `±0.1` per call, then clamps the stored result to
`[-1,1]`. Its sole recovered caller is `AIMainUpdate`. This proves the local
planner constraint; it is not a global invariant because initialization and
session-gated steering correction also write the same member.

# 2026-08-18 — Correction stage can replace both longitudinal planner values

`AISteeringCorrection_00426CF0`, called by `AIMainUpdate`, attenuates and caps
`V+0x4434` using steering magnitude, physical feedback, a difficulty-derived
limit, and distance-window logic. It also zeros or derives `V+0x4438` through
the same distance logic and `TireGripCoefficient`; in one session-gated case it
calls `AISteeringRacingLineCorrection`. Therefore `AIRacingLine` is not the
last planner writer before the final AI commit, and neither longitudinal member
has a single-writer SDK boundary.

# 2026-08-18 — Overtake logic is state/lane adjustment, not final-vector output

`Overtaking_0042AF70` is called by `AISteering` and is gated by replay/session/
candidate checks. When eligible it records the target at `V+0x45FC` and writes
the lane-offset/planner field `V+0x4420` to `+3.0` or `-3.0`. It has no direct
write to the final vector or to the three commit-source members
`V+0x442C/+0x4434/+0x4438`. Traffic affects later planning state, but this raw
function is not itself an output-control API.

# 2026-08-18 — Proximity scan rebuilds bounded traffic state per AI update

`OpponentProximityScanTeamRecognition_0042A7D0`, called by `AIMainUpdate`,
first resets five candidate records, then scans active vehicles and maintains a
five-entry nearest list. In the session-7 close-target branch it records a
target at `V+0x45FC` and sets `V+0x4420` to `-2.5` or `+2.5` according to a
direction projection. Like overtaking, it has no direct write to the committed
output vector or its three source members.

# 2026-08-18 — Race-order update is structurally separate from control output

`AITickUpdate_004BF4F0` iterates active vehicles, updates lap/time-related
fields where eligible, and calls `AIDriverSorting_004BF390`. The sorter compares
rank/time state across `dword_7C54F0` and changes rank-related fields only
through `ConditionalFieldSetter`. Neither recovered body references the final
vector nor `V+0x442C/+0x4434/+0x4438`; race order is an input/context path, not
a direct command-output owner.

# 2026-08-18 — Pit/ability path can reset longitudinal planner state

`AIAbility_00429470` adjusts pace-related state, evaluates pit decisions, and
calls `RacePhasePitEntryTrigger_00429EB0`; the latter calls `ForcePitExit` only
when its fuel/session gate succeeds. In its pit transition, `AIAbility` sets
the longitudinal planner member `V+0x4434` to zero and changes AI state/lane/
route fields before re-running `sub_426430`. Thus pit strategy participates in
the pre-commit planner lifecycle but does not directly write the final vector.

# 2026-08-18 — Gear request function's verified local protocol

`RaceStartCountdownStateUpdate_004EF930` is called by `AIMainUpdate`, the AI
gear helper, steering control, and pit readiness. With a nonzero request it
stores the request at receiver `+0x3A08`, initializes timer `+0x3A04` from a
direction-dependent source, and clears `+0x39E0`; a zero request clears all
three. Combined with the corrected timer-helper evidence, the recovered local
protocol is request `+0x3A08` → timer `+0x3A04` → expiry copy to `+0x39E0`.
Receiver identity across all call sites remains decompiler-ambiguous, so this
is not an externally writable gear contract.

# 2026-08-18 — Recovered AI gear helper has an irreducible raw tail gap

`PhysicsGearShiftLogicWithThresholds_00426330`, called by `AIMainUpdate`,
requests reverse in AI state `6`, neutral for a vehicle status condition, and
an upshift when its threshold conditions hold. Its remaining downshift branch
ends in raw `JUMPOUT(0x4F62E6)`, absent from the canonical function body. The
up/neutral/reverse request paths are evidence-backed; the downshift tail and
full receiver/gear application chain remain unproven.

# 2026-08-18 — Internal AI queue can trigger a scene lifecycle transition

`AICommandMessageQueueDispatcher_00424CD0` de-duplicates command/parameter
pairs and immediately invokes `CommandQueueResponseHandler`. For command `15`,
one session branch calls `SceneRenderUpdate(0)` before updating queue/pit state.
The queue is therefore not an output-control transport: it can invoke the same
scene lifecycle path that resets/configures physics and reinitializes driver AI.
This is further evidence against treating internal AI state as externally
writable without lifecycle arbitration.

# 2026-08-18 — Waypoint planner refreshes the shared-route horizon

`sub_426430` computes vehicle speed, reacquires the shared AI-database waypoint
when missing or more than `3200` squared-distance units away, then follows
linked records to populate a 19-entry forward horizon. It updates route/state
selectors, look-ahead distance, steering-distance class, and lateral bounds;
when the route branch changes it can enqueue internal command `14`. Its callers
include `AIMainUpdate`, `AIRacingLine`, `AIAbility`, and initialization-related
paths. This is the planner's shared-data read/derivation stage, not a final
vehicle-control write.

# 2026-08-18 — Profile parser inputs and derivations

`sub_424080`, called only by `AIDriverStructInit`, reads the driver profile
keys `STARTSDRY`, `STARTSWET`, `STARTSTALLS`, `QUALIFYINGABILITY`,
`TRACKAGGRESSION`, `RAINABILITY`, `RACEABILITY`, `PASSING`, `CORNERINGADD`,
`CORNERINGMULT`, `CRASH`, `COMPLETEDLAPS`, and `SCRIPT`. It then scales/mixes
the profile values with session globals, derives the rain-related factor at
`V+0x4580`, bounds passing, and applies start/event randomness. These are
initialization inputs to AI planning, not evidence for a runtime writable
control surface.

# 2026-08-18 — Shared AI database construction

`Game_Init` calls `AIDatabase_Init_004040A0`, which initializes defaults,
opens the AI database file, and calls `sub_402690`. The loader parses feature,
grid, pit, and waypoint data; `NUMBERWAYPOINT` allocates `316 * count + 4`
bytes and constructs 316-byte waypoint records. Each record receives branch,
path, event, position, groove, width, bitfield, and link-pointer data before
index remapping/position-delta processing. This is the authoritative static
origin of the shared route data consumed by driver-AI planning.

# 2026-08-18 — Selected-vehicle device feedback is downstream-only

After fixed substeps, `MainGameTickUpdate` calls
`DriverInputController_00451720`. The controller reads the selected vehicle
`dword_7C54E0` fields `+0x3580` and `+0x3584`, transforms them into bounded
device feedback/callback parameters, and does not write the final vector.
This is a downstream consumer for the selected vehicle, distinct from normal
physics integration and not an alternative control-input authority.

# 2026-08-18 — Final vector is also serialized into vehicle packets

`SetupCarLightingAndRender_004C71C0` reads `V+0x357C`, `V+0x3580`, and
`V+0x3584` while building a packet: it packs/encodes the first two and maps the
third to packet bit `0x04000000` using a `0.01` threshold. The function has no
write to those fields. This is an outbound serialization route and reinforces
that replay/network effects of an external write cannot be inferred from the
normal physics path alone.

# 2026-08-18 — Active vehicle array is not an AI-authority classification

`BuildActiveVehiclePointerArray_0042BC80` walks the fixed `18624`-byte vehicle
stride and includes each record whose `V+0x32C8` is not `-1` in
`dword_7C54F0`; it also identifies selected/local indices. Its callers include
dynamic initialization, loading, network synchronization, multiplayer, and AI
setup paths. Therefore membership in the array used by `AIMainUpdate` is an
active-vehicle criterion, not proof that every member is AI-owned.

# 2026-08-18 — Session-gated correction can override steering and braking state

`AISteeringRacingLineCorrection_0042B0E0` is reached only through
`AISteeringCorrection`'s session gate. It can set/cap `V+0x4434`, and several
route/geometry branches replace `V+0x442C` with an `atan2`-derived value clamped
to `[-1,1]`; other branches reset or transition vehicle/AI state. This confirms
that the local `sub_426100` slew limit is not a full-call-cycle steering
contract and that session behavior can re-own planner state before commit.

# 2026-08-18 — Current writable-SDK eligibility audit

Static evidence now proves the planner-to-final commit, normal-physics
consumption, reset/setup writers, packet overwrites, packet serialization, and
several lifecycle/order paths. It does **not** prove a safe writable contract:
the decompiler omits receivers at critical dispatches; AI, packet, lifecycle,
and in-step physics writers can re-own the vector; the applicable mode/session
arbitration is not fully recovered; and replay/network round-trip behavior has
not been independently verified. The evidence currently supports observation,
not external mutation, of the mapped fields.

# 2026-08-18 — AI state-branch effects at the final commit boundary

The normal `AIMainUpdate_00424E70` branch performs waypoint, traffic,
racing-line, steering, correction, and gear stages, then commits the three
planner members. State `2` calls `FieldZeroSetter` and returns before that
commit, preserving the existing final vector. State `7` explicitly resets the
three planner sources before committing; the non-normal/pit tail writes final
`(V+0x357C,V+0x3580,V+0x3584) = (0,0,1)`. `AIAbility` is time-gated by a
four-second field in this same update. These state-specific output policies are
another direct reason a standalone field write is not a stable control API.

# 2026-08-18 — Normal physics inner-loop order after mode dispatch

`PhysicsIntegrationStateMachine_004E4E60`, reached from mode `1` dispatch,
derives the integration substep count and executes, in order:
`SuspensionSpringDampingRateReset` → `sub_4E58D0` → `sub_4E51A0` →
`WheelForceCalculationSpringDamperTorque` → `sub_4E5AE0`. This places the
verified timer-helper and final-input consumption/overwrite paths within the
same normal physics inner loop, rather than in a separate post-processing pass.

# 2026-08-18 — Shared difficulty scalar

`AIDifficultyScalar_00424750` returns `1.0` at global difficulty `>=95`; below
that it returns `(difficulty - 70) * 0.04 * 0.25 + 0.75`. It is called by the
profile parser, steering correction, and ability/pit path. Difficulty therefore
modulates several planner stages, rather than being a final-output field or a
separate control owner.

# 2026-08-18 — Construction proof for vehicle/physics address translation

`VehicleObjectConstructor_004C6920` calls `RaceStructInit(V)`, which calls
`PhysicsTireSystemConstructor(V+3)`; the latter calls `sub_4E4790` on that
same base. `LargeStructFieldSetterWithStoredReference_00424040` then stores
`V` at the vehicle base. Therefore the physics receiver is `P=V+0xC`, making
the AI final fields `V+0x357C/+0x3580/+0x3584` exactly
`P+0x3570/+0x3574/+0x3578`.

# 2026-08-18 — State-2 early-return handler has no hidden output reset

`FieldZeroSetter_00425660`, called only by `AIMainUpdate` state `2`, performs
exactly one write: it clears `V+0x4510`. It does not modify any planner source
or final-vector member. The state-2 output preservation conclusion is therefore
direct raw evidence, not merely an inference from the caller's early return.

# 2026-08-18 — Pit-ready branch also issues a neutral request

`PitStopReadyCheck_004A6200`, called by `PitStateUpdateMachine`, calls
`RaceStartCountdownStateUpdate(0)` when its associated vehicle mode field is
`1`, before tire-compound/pit operation work. This establishes a pit-side
neutral-request source independent of the AI gear helper. The decompiled
receiver linkage remains incomplete, so it does not identify an SDK-safe gear
write target.

# 2026-08-18 — Push-lap path changes pace/rain inputs and can force a pit exit

`AIPushLap_0042A180`, called by `AIMainUpdate`, adjusts pace multiplier
`V+0x453C` in the relevant mode, derives the rain factor `V+0x4580` with a
minimum of `0.5`, and can call `ForcePitExit` from lap, tire-compound, weather,
or average-tire-state conditions. It does not directly write final controls;
these are strategy inputs that feed later planning.

# 2026-08-18 — Forced pit exit is a state transition, not a control write

`ForcePitExit_0042A110` is called from ability, race-phase, and push-lap paths.
It performs session/teammate gating and invokes a pit-state action plus
`AIStateFlagSetter(1)`. The recovered body has no planner-source or final-vector
write, so pit exit changes the state machine that later governs output rather
than issuing a direct control command.

# 2026-08-18 — External lifecycle code owns the physics-mode selector

`SessionStateTransition_004EF5A0` writes its receiver `+0x32BC`, the selector
used by `VehiclePhysicsModeDispatcher`, and is called from load, restart,
finish, network synchronization, multiplayer, and AI-setup paths. A transition
to mode `1` also clears/restarts waypoint-horizon state through AI helpers.
Thus the normal-versus-packet/reset physics path is controlled by lifecycle
code outside the final AI commit.

# 2026-08-18 — Post-scene sentinel override consumes, but does not rewrite, input

`ThrottleBrakeOverride_004EE230` computes a value from `P+0x3570` and vehicle
speed ratio, then substitutes it into three separate fields only when their
independent source values equal sentinel `-789.0`. It does not write the final
vector. This is a conditional downstream use of one translated input, not an
alternative normal AI-output commit or a general overwrite path.

# 2026-08-18 — Additional AI reset path clears the steering planner source

`CameraViewportFrustumInitialization_00424B20` clears `V+0x442C`, resets route/
traffic/AI-state fields, reinitializes the internal queue/ring state, and calls
`sub_426430`. It is called by a separate lifecycle path (`sub_4C6B60`), showing
that steering-source lifetime is not limited to `AIDriverStructInit` or normal
per-tick planning.

# 2026-08-18 — State-1 handler overrides both longitudinal planner sources

`sub_4258C0`, called from `AIMainUpdate` state `1`, sets `V+0x4434` to `0` and
`V+0x4438` to `1`; under low-speed or physical-feedback conditions it advances
the AI state to `2`. This is a distinct pre-commit state override in addition
to racing-line and correction-stage writers.

# 2026-08-18 — Physics-derived longitudinal source functions are locally bounded

`BrakeThermalModel_004E87E0` and `TireGripCoefficient_004E88B0`, used by
racing-line/correction branches to derive planner values, each return a value
clamped to `[0,1]`. That establishes bounds for those individual derivations,
not for every route to `V+0x4434/+0x4438` or for the final vector after other
state, packet, reset, and lifecycle writers.

# 2026-08-18 — Profile factors feed racing-line pass scoring

`AIComputePassScore_0042A780`, called only by `AIRacingLine`, returns a tire-
force-scaled score using `CORNERINGMULT` (`V+0x4504`), `CORNERINGADD`
(`V+0x4500`), the derived rain factor (`V+0x4580`), and pace multiplier
(`V+0x453C`). This is the direct profile-to-racing-line coupling; it remains a
planner input rather than a final control output.

# 2026-08-18 — Queue parameter path targets an internal speed-like field

`ParameterValueSetter_0042ACD0` writes only `V+0x4538`, using a special global
value for command `18` and otherwise the supplied integer as a float. It is
called by the AI command queue, ability, and queue-response paths. No final
vector or its three direct planner sources are written here; this is an internal
state parameter, not a control-output injection point.

# 2026-08-18 — Steering paths share a minimum-clamped track parameter

`TrackParameterMinimumClamp_0042A740` writes `V+0x4484` to the lesser of its
current value and the supplied value, then enforces a minimum of `5.0`. It is
called by steering correction, AI steering, and racing-line steering correction.
This is a bounded planning parameter shared across steering stages, not a final
control slot.

# 2026-08-18 — Session/queue speed selector is distinct from command output

`AISpeedDeltaSetter_0042ACA0`, called by session transition and command-queue
response paths, stores selector values `0` or `1` at `V+0x4550`; selector `1`
also invokes its route/state helper. It does not write the steering or
longitudinal planner sources, nor the final vector.

# 2026-08-18 — Driver initialization also applies a separate difficulty curve

`AIDifficultyInterpolation_00424AC0`, called only by `AIDriverStructInit`,
interpolates between global difficulty constants using separate ranges above
and below `100`. Its result is passed to initialization-time audio scaling;
this is distinct from the shared `AIDifficultyScalar` used in runtime planning
and does not add a control-output owner.

# 2026-08-18 — Pit state machine runs before normal integration dispatch

`PitStateUpdateMachine_004A6E50` is called by `VehiclePhysicsModeDispatcher`
before both the mode-0 integration/setup route and the mode-1 normal physics
route. It advances pit states, invokes `PitStopReadyCheck` where applicable,
and contains vehicle-control/session gates. Pit transitions therefore occur in
the same dispatch layer that selects normal physics, but the recovered body has
no direct final-vector write.

# 2026-08-18 — Internal command responses affect state/parameters, not output

`CommandQueueResponseHandler_00429EE0` examines queued command pairs and can
clear session flags, set AI state fields, invoke `ParameterValueSetter`, and
toggle `AISpeedDeltaSetter`. It does not write `V+0x442C/+0x4434/+0x4438` or
the final vector. The queue remains a planner/lifecycle input mechanism rather
than an authoritative vehicle-control output path.

# 2026-08-18 — Correction: packet path also writes translated `P+0x3570`

This supersedes the earlier translated-slot writer audit's incomplete list.
`EffectParameterSetter_004F17A0` directly writes its receiver `+0x3570`; its
only recovered caller is `VehiclePhysicsTimeStep_004C73F0`, which invokes it in
its `V+0x32C8 == 2` packet-handling branch. Thus packet-mode processing can
write all three translated/final components through its direct vehicle and
physics paths, strengthening—not weakening—the no-writable-SDK conclusion.

# 2026-08-18 — State controller changes AI state and requests downshift only

`SteeringAngleController_00425670`, called by `AIMainUpdate` states `0` and
`6`, evaluates heading/error thresholds, changes the AI state field, and can
request `currentGear - 1` through `RaceStartCountdownStateUpdate`. It has no
direct write to the planner sources or final vector. This confirms that the
state-machine's gear/pit side effects are separate from its final control
commit.

# 2026-08-18 — Scene lifecycle re-enters the auxiliary AI reset path

`sub_4C6B60`, called by `SceneRenderUpdate` and session update code, performs
vehicle path/suspension/session actions and then unconditionally calls
`CameraViewportFrustumInitialization`. Thus scene/lifecycle processing can
rebuild steering/route state through that initializer independently of the
normal AI tick.

# 2026-08-18 — Qualification of the `sub_4C6B60` lifecycle edge

The raw corpus contains the `sub_4C6B60` call to
`CameraViewportFrustumInitialization`, but contains no recovered definition or
other call site for that symbolic callee. The direct call edge is verified; the
preceding statement that it rebuilds steering/route state is inference and is
not evidence of a final-vector write or reset. The proven lifecycle reset of
the translated slots remains `sub_4E4790(V+0xC)`.

# 2026-08-18 — Pit decision can directly zero the first longitudinal planner value

In the recovered pit-decision branch of `AIAbility_00429470`, the float-index
assignment `this[4365] = 0.0` writes `V+0x4434` (`4365 * 4 = 17460`). That
branch also sets controller/pit state and invokes `sub_426430`; it is therefore
a direct, state-gated planner writer, not a final-vector writer. The normal
`AIMainUpdate` commit can subsequently transfer that zero to `V+0x357C` when
its own gates permit. This confirms that pit strategy has a direct longitudinal
planner effect while preserving the existing no-external-write conclusion.

# 2026-08-18 — Traffic target has a bounded same-AI-update lifetime

`OpponentProximityScanTeamRecognition_0042A7D0` writes a selected vehicle
pointer to `V+0x45FC` (`this[4479]`) when its candidate test succeeds.
`Overtaking_0042AF70`, called from `AISteering_004270A0`, can replace the same
field with its `a2` target and set the lateral planner value at `V+0x4420` to
`+3.0` or `-3.0`. Later in the normal `AIMainUpdate` sequence,
`AISteeringCorrection_00426CF0` tests nonzero `V+0x45FC` before performing its
correction work; the normal final-commit block then clears `V+0x45FC`.

This establishes an observed production → correction-consumption → clear
lifetime within a successful normal AI update. It is transient traffic/planner
state, not a durable target handle or a final physics-control field.

# 2026-08-18 — Pit readiness clears request/timer state, not the final control vector

`PitStopReadyCheck_004A6200` reaches the recovered
`RaceStartCountdownStateUpdate(0)` call only under its associated mode check.
In `RaceStartCountdownStateUpdate_004EF930`, the explicit `a2 == 0` branch
clears receiver-relative `+0x3A08`, `+0x3A04`, and `+0x39F0` and returns. It
does not write `P+0x3570/+0x3574/+0x3578`. Because the recovered call omits its
effective `__thiscall` receiver, the exact receiver identity remains an
inference; however, the visible callee behavior is a request/timer-state clear,
not direct neutral/final-vector actuation. Earlier shorthand describing this as
a pit-issued “neutral request” is therefore semantic inference, not a verified
SDK operation.

# 2026-08-18 — Correction: `14832` is `0x39F0`

The prior timer-helper note's hexadecimal spelling is wrong: decimal `14832`
is `0x39F0`, not `0x39E0`. The raw `RaceStartCountdownStateUpdate_004EF930`
`a2 == 0` branch clears `+0x3A08`, `+0x3A04`, and `+0x39F0`; the related
`BrakeCoolingPostTreatment_004E5080` expiry copy also targets decimal `14832`,
therefore `+0x39F0`. This correction changes only the offset transcription,
not the existing conclusion that neither recovered operation writes the final
`P+0x3570/+0x3574/+0x3578` vector.

# 2026-08-18 — Race-order pass is reached through the race-event orchestration path

The only recovered canonical caller of `AITickUpdate_004BF4F0` is
`EngineFailureCheck_004BEC55`. After its per-vehicle event/lap-processing loop
and a time accumulation, that caller invokes `AITickUpdate(a3)` when either of
two local outcome flags is false, then restores the global time value.
`AITickUpdate` updates lap/time fields and calls `AIDriverSorting` for eligible
active vehicles; it does not write AI planner or final-control fields.

`EngineFailureCheck` carries a positive-stack warning and omitted prototype
information, so this establishes a recovered race-event scheduler edge, not a
precise placement relative to every `MainGameTickUpdate` substep. Race order
remains a separate game-owned interaction path rather than an SDK control hook.

# 2026-08-18 — Driver-AI reinitialization has multiple non-tick lifecycle entries

The canonical raw callers of `SceneRenderUpdate_004C6D90` are
`AICommandMessageQueueDispatcher_00424CD0`, `DynMan_Restart_0042C3B0`,
`NetCommPlayerSlotSync_0045FC50`, `PitStopDecisionTireCompound_0042A3D0`,
`ProcessDriverEntries_004B8DA0`, `sub_4A0250_004A0250`, and
`sub_4A00A0_004A00A0`. Since `SceneRenderUpdate` calls
`AIDriverStructInit`, these are independent lifecycle entry points capable of
reinitializing AI state outside `MainGameTickUpdate`'s normal planner cadence.
Their recovered call text includes omitted/mistyped `__thiscall` receivers, so
the exact per-vehicle target is not uniformly resolved. The multi-owner
lifecycle conclusion is direct; it reinforces that no planner or final-vector
field has a safe, externally durable write lifetime.

# 2026-08-18 — Gear-request state has multiple AI and pit owners

Canonical raw calls to `RaceStartCountdownStateUpdate_004EF930` occur in
`AIMainUpdate_00424E70`, `PhysicsGearShiftLogicWithThresholds_00426330`,
`PitStopReadyCheck_004A6200`, and `SteeringAngleController_00425670`.
The visible request values include `-1`, `0`, current-plus-one, and
current-minus-one, each behind caller-specific gates. These callers all omit
the effective `__thiscall` receiver in the recovered call text; therefore they
prove several independent internal request sources, not a common external gear
API or a direct final-control write.

# 2026-08-18 — Final-vector reset is shared by construction, configuration, and teardown

Canonical raw callers of `sub_4E4790_004E4790`, which zeroes the translated
final vector, are `PhysicsTireSystemConstructor_004E4500`,
`LargeConfigFunctionWithPhysicsConstants_004E45B0`,
`sub_4C6E80_004C6E80`, and `ShortComputation_4570_004E4570`.
The first establishes construction ownership; the second is the scene/config
path; the third is the grid/driver reset path; and the last continues into a
destructor/cleanup sequence. Thus the same vector is deliberately reset across
creation, reconfiguration, reset, and cleanup—not merely at initial vehicle
allocation. No external write lifetime can be inferred from it.

# 2026-08-18 — Network slot sync selects packet mode for non-player vehicles

`NetCommPlayerSlotSync_0045FC50` computes the vehicle base `V` from the slot
stride and directly calls `SessionStateTransition(V+0xC, 0, 0)` for the local
player slot, or `SessionStateTransition(V+0xC, 2, 0)` for a non-player slot.
It then rebuilds the active-vehicle list, registers the vehicle scene entry,
and calls `SceneRenderUpdate(V, 1)`. This is direct raw evidence that network
slot setup can place non-player vehicles into physics mode 2—the packet route
that reaches `VehiclePhysicsTimeStep`—while also fully reinitializing driver
AI state. Consequently, normal mode-1 AI-output consumption cannot be assumed
for a network-synchronized non-player slot.

# 2026-08-18 — Physics mode is selected by several lifecycle systems

Canonical `SessionStateTransition_004EF5A0` callers request values `-1`, `0`,
`1`, `2`, and `3` across AI-driver setup, loading, restart, race-finish,
season-reset, player-slot synchronization, multiplayer join/retry, and driver
entry processing. The direct network-slot calls resolve the `P=V+0xC`
receiver; many other recovered calls omit it. This establishes distributed
game-owned mode selection and prevents treating mode 1 as a stable property of
an AI record or as authority for an external control writer.

# 2026-08-18 — Construction seeds planner defaults before later lifecycle init

`VehicleObjectConstructor_004C6920` calls `RaceStructInit_00423E80`, then
stores the outer self-reference. `RaceStructInit` first constructs the embedded
physics object at `V+0xC`, then initializes planner `V+0x4434` to `0.0` and
`V+0x4438` to `1.0`; it also initializes `V+0x442C` to `0.0`. These are
construction defaults, not a safe command ABI: later `AIDriverStructInit`,
AI planning, physics reset/setup, packet paths, and mode changes independently
replace or consume related state.

# 2026-08-18 — Qualification: only the outer self-reference is direct

`LargeStructFieldSetterWithStoredReference_00424040`, called by
`VehicleObjectConstructor`, directly writes `V[0] = V` and `V+0x4034 = V`.
No recovered constructor write establishes `P[0] = V` for `P = V+0xC`.
Accordingly, earlier wording that presented a physics-subobject back-reference
as construction proof is inference and must not be used to strengthen receiver
identity or any writable SDK claim. The `P=V+0xC` base itself remains direct
from `RaceStructInit` calling `PhysicsTireSystemConstructor(V+0xC)`.

# 2026-08-18 — Active-list inclusion does not imply an AI control update

`BuildActiveVehiclePointerArray_0042BC80` includes every vehicle whose outer
`V+0x32C8` is not `-1`; it does not restrict the list to mode 1. Thus a
network-created mode-2 vehicle can be present in `dword_7C54F0` and reach the
batch loop in `MainGameTickUpdate`. `AIMainUpdate_00424E70` immediately returns
when that same field is greater than `1`, so a mode-2 packet vehicle receives
no normal AI planning/commit despite active-list membership. This resolves the
apparent conflict between all-active iteration and the packet-mode ownership
path.

# 2026-08-18 — Normal AI planning and commit require mode 1, not merely an active slot

`AIMainUpdate_00424E70` initially rejects `V+0x32C8 > 1`, but its normal
waypoint/planning path then explicitly returns unless `V[0]+0x32C8 == 1`.
`VehicleObjectConstructor` establishes `V[0] = V`; therefore the normal
planner, state dispatch, and final-vector commit require mode 1. Mode 0 can
remain in the active list but does not pass this normal planner gate, and its
dispatcher path subsequently performs setup that seeds the translated inputs.
This narrows the authoritative normal AI-output path to mode-1 execution.

# 2026-08-18 — Final command commit is conditional, and some paths preserve prior values

In `AIMainUpdate_00424E70`, the normal planner path returns if waypoint
acquisition (`sub_426430`) fails or mode is not 1. Within the later controller
state switch, state `2` calls `FieldZeroSetter_00425660` and returns before the
final-vector assignments. Conversely, successful normal and countdown paths
reach the three assignments from planner values to the final vector. Therefore
the vector is not refreshed on every active-list visit: it is conditional on
mode, waypoint acquisition, and controller state, and it can deliberately
retain a previous value. This excludes a simple per-tick external write model.

# 2026-08-18 — Exact residual longitudinal-range gap

`AISteeringCorrection_00426CF0` can replace `V+0x4434` by interpolating its
previous value toward the result of `SuspensionRatioClamp(this+0xC)`. The
interpolation weight is clamped to `[0,1]`, but the canonical raw corpus
contains no body for `SuspensionRatioClamp`; this path has no corresponding
universal lower-bound clamp before the planner value can be committed. The
remaining shown paths provide zeros, ones, branch-local caps, or known clamped
helpers, but they do not close this opaque-source path. Therefore `[0,1]`
remains an unsupported external validation range for the first longitudinal
planner/final component.

# 2026-08-18 — Superseding correction: `CameraViewportFrustumInitialization_00424B20` is recovered

The preceding qualification that this symbolic callee lacked a recovered body
is superseded. `CameraViewportFrustumInitialization_00424B20` directly resets
AI route/controller fields, sets `V+0x442C` to zero, invokes
`AICommandMessageQueueDispatcher(0, 0)`, clears controller state, and calls
`sub_426430` to reacquire waypoint/horizon state. `sub_4C6B60` therefore has a
verified lifecycle route into an auxiliary AI reset/reacquisition path. The
recovered initializer still does not directly write the final vector, so this
strengthens planner-lifetime evidence without creating a writable output path.

# 2026-08-18 — Steering planner has a recovered local range, not external authority

The canonical direct writer set for `V+0x442C` is construction/driver/lifecycle
initialization (zero), `sub_426100` (slew then `[-1,1]` clamp),
`AISteeringRacingLineCorrection_0042B0E0` (atan2-derived then `[-1,1]` clamp),
and countdown branches in `AIMainUpdate` (zero). This proves the AI-local
planner range in recovered source. It does not prove a safe writer contract:
mode-1 eligibility, lifecycle resets/reacquisition, commit gates, and packet
ownership still decide whether and when this value reaches physical steering.

# 2026-08-18 — Gear request path boundary is now exact

`PhysicsGearShiftLogicWithThresholds_00426330` is a recovered physical-side
gear decision path: it calls `RaceStartCountdownStateUpdate` with `-1`, `0`,
or `current + 1` using the field at `P+0x39FC` (decimal 14844). The recovered
callee writes the gear-request state at `P+0x3A08` (14856), its timer at
`P+0x3A04` (14852), and a related state at `P+0x39F0` (14832); it does not
write the final AI steering/longitudinal vector. The sole downshift branch in
the canonical corpus exits at `JUMPOUT(0x4F62E6)`, whose target body is absent.
Thus physical gear handling is evidenced, but its complete downshift semantics
and any safe external AI gear-write contract remain unproven.

# 2026-08-18 — Superseding correction: gear request is in the AI update frame

`AIMainUpdate_00424E70` directly calls
`PhysicsGearShiftLogicWithThresholds(this)` immediately after
`AISteeringCorrection(this)` and before controller-state dispatch/final-vector
commit. Therefore its displayed offsets are relative to the outer AI/vehicle
receiver `V`: the prior notation `P+0x39FC`, `P+0x3A08`, `P+0x3A04`, and
`P+0x39F0` is not supported and is superseded by `V+` for the recovered code.
The decompiler omits the effective receiver at the subsequent
`RaceStartCountdownStateUpdate(...)` calls, so only their argument values and
the callee's offset writes are verified; receiver identity across that call is
not. The recovered ordering does prove that the AI's gear decision occurs in
the normal AI frame after steering planning, while the missing `0x4F62E6`
tail still prevents a complete gear contract.

# 2026-08-18 — Gear thresholds are lifecycle-owned inputs

`SceneRenderUpdate_004C6D90` calls
`LargeConfigFunctionWithPhysicsConstants_004E45B0`, which first invokes
`sub_4E4790` and then `SuspensionAndWheelPhysics`. The latter initializes the
gear state block at the outer receiver: `V+0x39FC` and `V+0x3A00` derive from
vehicle-configuration values, while `V+0x3A04` and `V+0x3A08` are reset to
zero. `PhysicsGearShiftLogicWithThresholds_00426330` subsequently consumes
those values during `AIMainUpdate`. This establishes configuration/lifecycle
ownership of its thresholds and timer, further excluding them from a safe
external AI write surface. It does not resolve the absent downshift target or
the decompiler-omitted receiver of the request-update call.

# 2026-08-18 — Superseding correction: do not merge the AI and physics gear blocks

`SceneRenderUpdate_004C6D90` passes `this + 3` to
`LargeConfigFunctionWithPhysicsConstants_004E45B0`; its
`SuspensionAndWheelPhysics` gear initialization is therefore at `P` (the
physics subobject), not at `V`. In contrast,
`AIMainUpdate_00424E70` passes outer `V` directly to
`PhysicsGearShiftLogicWithThresholds_00426330`, so that helper's displayed
`V+0x39FC` and related offsets cannot be identified with the `P+` fields merely
because their numeric offsets match. The previous lifecycle-ownership claim
across that boundary is superseded: recovered source proves two distinct
same-offset blocks and an omitted-receiver call to
`RaceStartCountdownStateUpdate`; it does not prove the bridge between them.
This ambiguity is itself a hard blocker for an external gear-write contract.

# 2026-08-18 — Pit request is mode-1-gated but receiver-ambiguous

`VehiclePhysicsModeDispatcher_004E4930` calls
`PitStateUpdateMachine(P+0x32C0, time)` before
`PhysicsIntegrationStateMachine` on its normal mode-1 route.
`PitStateUpdateMachine_004A6E50` passes that pit-controller receiver to
`PitStopReadyCheck_004A6200`; the latter obtains the vehicle as `*this` and
calls `RaceStartCountdownStateUpdate(0)` only if
`(*this)+0x32C8 == 1`. This verifies that the pit-side zero request is
mode-1-gated and precedes integration. The call remains bare in recovered C:
its effective receiver is not represented, so it does not prove a write into
either the outer-AI or physics-subobject gear block. No external pit/gear
write contract follows from this path.

# 2026-08-18 — Direct normal output-slot consumption map

The `AIMainUpdate_00424E70` final stores at `V+0x357C/80/84` translate to
`P+0x3570/74/78` because `P = V+0xC`. Recovered normal-physics code directly
uses all three translated slots: `ThrottleBrakeOverride_004EE230` derives its
sentinel-gated longitudinal override from `P+0x3570`;
`WheelForceCalculationSpringDamperTorque_004E5470` multiplies its steering
angle by `P+0x3574`; and `sub_4E51A0` reads `P+0x3578` as a multiplier for
per-wheel terms. `sub_4E51A0` can also force `P+0x3578 = 1` under its own
recovered condition and clear `P+0x3570` when its speed-related condition
holds. Thus each commit component has a direct downstream normal-physics use,
but the physics layer retains conditional write-back authority.

`sub_4E4790` resets all three translated slots, while mode-0
`VehicleSetupInitialization_004E49B0` seeds all three from globals.
Separately, `VehiclePhysicsTimeStep_004C73F0` writes the displayed
`V+0x3580` and `V+0x3584` fields only on mode 2 and is the only recovered
caller of `EffectParameterSetter_004F17A0`, which writes the first translated
slot through an omitted receiver. This proves a competing packet path without
establishing a normal-mode external write surface.

# 2026-08-18 — Decimated tick order reaches the longitudinal consumer

On each tenth 0.0025-second iteration, `MainGameTickUpdate_0042C690` first
iterates `AIMainUpdate(V)` over the active array, then invokes its recovered
scene-loop dispatch, and then iterates `sub_4EE2D0(V+0xC)` over that same
array. `sub_4EE2D0` calls `ThrottleBrakeOverride(P)` immediately before its
subsequent force/effect work. This is direct same-decimated-phase evidence for
the first committed component reaching the longitudinal override after AI
planning. The mode-specific scene-loop callee chain still governs whether the
normal physics dispatcher/integration ran before that consumer, so this does
not weaken the mode-1 or packet-authority gates.

# 2026-08-18 — Race-order update is an independent, incompletely phased subsystem

`AITickUpdate_004BF4F0` iterates the active vehicles, updates its lap/time
state (`V+0x403C`, `V+0x4098`, and `V+0x40B8` in recovered offsets), assigns
the applicable status at `V+0x4064`, and invokes `AIDriverSorting(V)`. It has
no recovered access to the three translated output slots. Its only recovered
call site is an indirect `AITickUpdate(a3)` invocation near the completion of
`EngineFailureCheck_004BEC55`, after that routine's per-vehicle event/lap
logic and game-time adjustment. `EngineFailureCheck` has a positive-stack
warning and no canonical caller reference, so its exact phase relative to
`MainGameTickUpdate` is unproven. Race order is therefore evidenced as a
separate state/sorting input, not as a proven output-command authority or a
safe SDK hook point.

# 2026-08-18 — Profile `SCRIPT` is parse-only in recovered source

`sub_424080_00424080` initializes `V+0x44E0` (decimal 17632) to its default
script string and replaces it from the keyed `SCRIPT` profile entry when one
exists. A canonical corpus search finds no other access to that offset. The
same parser transforms the other driver profile inputs into the documented
AI fields and can set event/failure state, but recovered source does not show
the `SCRIPT` text driving waypoint, traffic, or final-output behavior. Thus
`SCRIPT` must remain a parse-only input with unknown runtime semantics, not an
SDK control field.

# 2026-08-18 — Traffic target and pass direction feed the steering frame

Within the normal `AIMainUpdate_00424E70` planner sequence,
`OpponentProximityScanTeamRecognition_0042A7D0(V)` runs before `AIRacingLine`
and `AISteering`. Its qualifying nearby-vehicle branch stores the target at
`V+0x45FC` and sets `V+0x4420` to a signed pass direction.
`Overtaking_0042AF70` can update those same fields (`V+0x45FC = target`,
`V+0x4420 = +3/-3`) after its recovered eligibility tests. `AISteering_004270A0`
has recovered `Overtaking(this, v86)` calls in its pass branches, although the
decompiler omits the helper's displayed third argument. The target is therefore
verified as transient normal-AI traffic state that influences steering planning;
it is not a persistent externally owned target API. In one recovered final
commit branch `AIMainUpdate` clears `V+0x45FC`, reinforcing that lifetime
boundary without proving every state branch clears it.

# 2026-08-18 — Network slots are lifecycle-initialized packet authorities

`NetCommPlayerSlotSync_0045FC50` passes `P = V+0xC` to
`SessionStateTransition_004EF5A0`: it requests mode 0 for the local slot and
mode 2 for each non-local slot. `SessionStateTransition` writes `P+0x32BC`,
which aliases outer `V+0x32C8`. The sync path then rebuilds the active list,
loads scene data, and invokes `SceneRenderUpdate(V, 1)`. Thus network slots
receive the same lifecycle initialization but enter a distinct mode-2 packet
route. Since `AIMainUpdate_00424E70` rejects modes above 1 and
`VehiclePhysicsTimeStep_004C73F0` has mode-2 packet writes to competing output
fields, normal AI-output authority and packet authority are statically
separated. This still does not establish replay ordering or an external writer
contract.

# 2026-08-18 — Waypoint acquisition is a concrete pre-commit gate

`sub_426430_00426430` is a recovered route-horizon builder. It caches the
nearest route node at `V+0x4354`, reacquires it through
`SpatialNearestNeighborQueryWithPlaneTest` when absent or sufficiently far
from the vehicle pose, and returns zero if that query fails. On reacquisition
it seeds a 19-entry forward horizon beginning at `V+0x4358`, updates route
mode/state, derives speed/look-ahead values, and calculates constrained heading
intersections from vehicle pose and route geometry. Its later geometry path
explicitly returns without that mode-specific refinement unless outer
`V+0x32C8 == 1`.

`AIMainUpdate_00424E70` returns before normal planner/controller/final-commit
work when `sub_426430(V)` returns zero or mode is not 1. The same acquisition
routine is called by initialization, racing-line/ability paths, and
`CameraViewportFrustumInitialization_00424B20` reset/reacquisition. Thus
route state is resettable, spatially reacquired, and a hard normal-output
eligibility condition rather than a stable writable SDK input.

# 2026-08-18 — Longitudinal planner bounds remain asymmetric and incomplete

The normal order in `AIMainUpdate_00424E70` is `AIRacingLine`, then steering
work, then `AISteeringCorrection_00426CF0`, followed by final commit.
`AIRacingLine_00425920` supplies explicit zero/one brake/drive branches and
ramps its result; `sub_4258C0` likewise sets `V+0x4434 = 0` and
`V+0x4438 = 1`. `AISteeringCorrection` can attenuate `V+0x4434`, replace it by
interpolation toward `SuspensionRatioClamp(V+0xC)`, force zero in several
proximity branches, and apply recovered upper caps in its later branches.
The interpolation weight is clamped, but the canonical corpus has no body for
`SuspensionRatioClamp` and this routine shows no universal lower clamp on its
result before final commit. Therefore a complete external numeric range for
the longitudinal component remains unproven; the recovered branch constants
must not be promoted into an SDK validation contract.

# 2026-08-18 — Scheduler bridge to normal physics is recovered

The scene-loop call in `MainGameTickUpdate_0042C690` resolves to
`LoopWithConditionalSkipFunction_00410980`, which iterates registered scene
records and calls `SceneObjectLoaderStateMachine_0040F1C0(record, time)`.
In scene state 6, that state machine conditionally calls
`VehiclePhysicsModeDispatcher(time)` when the vehicle enable bit is present,
then updates suspension state. The dispatcher receives the vehicle physics
subobject through its scene record and routes mode 1 to
`PitStateUpdateMachine(P+0x32C0, time)` followed by
`PhysicsIntegrationStateMachine(P, time)`. This closes the static scheduler
chain from decimated `AIMainUpdate(V)` commit through scene dispatch to normal
physics consumption, subject to the recovered scene-state/enable/mode gates.

# 2026-08-18 — `V`/`P` construction relation is direct, but `P[0]` is not a back-pointer

`RaceStructInit_00423E80` constructs `P` by calling
`PhysicsTireSystemConstructor(V + 0xC)`. That constructor initializes
`P+0x32BC` to `-1`, resets the translated final slots through `sub_4E4790`,
and does not write `P[0]`. Later `VehicleObjectConstructor_004C6920` calls
`LargeStructFieldSetterWithStoredReference_00424040(V, V)`, which directly
writes `V[0] = V` and `V+0x4034 = V`. Therefore code such as
`AIMainUpdate`'s `V[0]+0x32C8` gate is a verified outer-self reference, while
any claim that `P[0]` is the same reference is unsupported. This distinction
is required for the output-slot and gear-receiver analysis.

# 2026-08-18 — Steering planner range is directly recovered

`sub_426100_00426100` computes the route-relative steering request at
`V+0x442C`, limits its per-update change to `0.1`, and clamps the stored result
to `[-1, 1]`. `AISteeringRacingLineCorrection_0042B0E0` also derives its
route/camera corrections from `atan2` and clamps the same steering-planner
field to `[-1, 1]`. The normal final commit copies this field to
`V+0x3580 = P+0x3574`, which
`WheelForceCalculationSpringDamperTorque_004E5470` directly uses. This is a
recovered internal range and downstream physical use, not a safe external
writer contract: mode eligibility, acquisition, state-return paths, lifecycle
resets, and mode-2 packet writers remain authoritative.

# 2026-08-18 — Profile parse is full-lifecycle-only

`AIDriverStructInit_00424790` performs common AI-field defaults on every
invocation, but only its `LOBYTE(a2)` branch calls the profile parser
`sub_424080`, allocates/resets the AI command queue, resolves teammate linkage,
and initializes the nearest route node. The only recovered direct call is
`SceneRenderUpdate_004C6D90(V, a2)`, which runs this initialization before its
auxiliary reset/reacquisition path. Consequently profile-derived state is a
full lifecycle input, while common AI state can still be reset without parsing
a profile. Neither branch is a safe persistent SDK configuration surface.

# 2026-08-18 — Static writable-SDK contract audit: not yet provable

The requested safe writable AI-SDK contract requires, at minimum, a stable
owner, a bounded value domain, an authoritative write phase, and isolation
from packet/replay/lifecycle writers. Current recovered evidence fails all four
as a proof: `AIMainUpdate_00424E70` writes the normal vector conditionally;
`sub_4E4790` resets it; mode-0 `VehicleSetupInitialization_004E49B0` seeds it;
`sub_4E51A0` conditionally overwrites components during normal integration;
and mode-2 `VehiclePhysicsTimeStep_004C73F0` plus its packet helper competes
for translated fields. The longitudinal range contains an opaque helper, the
gear path has both an omitted receiver and a missing `0x4F62E6` tail, and
replay ordering is not recovered. No recovered external insertion phase or
ownership handshake resolves these conflicts. Therefore the static map has
strengthened the rejection criteria, but it has not proven a writable SDK
surface and must not be represented as one.

# 2026-08-18 — Mode is distributed game lifecycle state

The recovered caller set of `SessionStateTransition_004EF5A0` includes driver
loading/setup, loading-phase restoration, restart, race finish, season reset,
and multiplayer/network synchronization. It requests values `-1`, `0`, `1`,
`2`, and `3` at `P+0x32BC` (outer `V+0x32C8`). This mode is therefore not
owned by the AI planner: it is distributed game/session lifecycle state whose
value controls active-list inclusion, normal planner eligibility, scene
physics routing, and packet behavior. An external writable contract cannot
safely treat it as an AI configuration switch.

# 2026-08-18 — Active-list membership is broader than AI authority

`BuildActiveVehiclePointerArray_0042BC80` places every vehicle whose outer
`V+0x32C8` mode is not `-1` into `dword_7C54F0`; it does not restrict the list
to normal AI mode. `MainGameTickUpdate_0042C690` therefore calls
`AIMainUpdate` for active mode-2 records as well, but `AIMainUpdate` returns
immediately when the mode exceeds 1 and its normal planner later requires
exactly 1. Active membership is consequently only a lifecycle/iteration
property, not evidence of core-AI output authority. This prevents treating
the active vehicle array as an external AI-control enumeration.

# 2026-08-18 — AI command queue can re-enter lifecycle reset

`AICommandMessageQueueDispatcher_00424CD0` receives commands from full driver
initialization, waypoint acquisition, camera/reset code, pit progress, and
timer/display paths. In recovered command case 15, one state branch calls
`SceneRenderUpdate(0)` and `StateChangeNotify(0)` before resetting controller
flags and queue state. Thus command processing can re-enter the vehicle
lifecycle/reset path rather than merely alter a planner value. This is further
evidence that AI planner/output fields cannot be assumed persistent across
queue events, and it excludes the queue as a safe external output-write hook.

# 2026-08-18 — Local input controller observes, not writes, the vector

`MainGameTickUpdate_0042C690` calls `DriverInputController_00451720` only
after completing its fixed-step update loop. The recovered input controller
reads the displayed outer command fields corresponding to translated steering
and the third component (`V+0x3580`, `V+0x3584`) for its device/control logic;
no recovered write to the three final AI command fields occurs in that
function. Its own guards distinguish the selected local vehicle and vehicle
mode. This identifies a post-step local-input observer/consumer, not an
authoritative human-input writer or an SDK insertion point.

# 2026-08-18 — Final-vector serialization is read-only from this path

`SetupCarLightingAndRender_004C71C0` packs the displayed outer final fields
`V+0x357C`, `V+0x3580`, and `V+0x3584` into its output/event buffer, including
the third component as a packet bit. Its recovered callers are tire/vehicle
simulation and pit-timing paths. The routine reads/encodes these values but
does not write them. This proves that final AI commands enter a serialized
output path; it does not identify a replay/network authority or a writable SDK
interception phase.

# 2026-08-18 — Scene lifecycle unconditionally clears steering planner state

After its scene/suspension/state handling, `sub_4C6B60_004C6B60` unconditionally
calls `CameraViewportFrustumInitialization_00424B20(V)`. The recovered callee
resets the five-entry traffic/horizon buffers, controller/timer flags, route
state, and specifically writes `V+0x442C = 0`; it then dispatches queue command
0 and calls `sub_426430(V)` to reacquire the route. `SceneRenderUpdate_004C6D90`
calls `sub_4C6B60(V, 1)` after driver initialization. Thus scene lifecycle has
a verified direct steering-planner reset plus route reacquisition, while it
does not directly write the translated final vector. Any external steering
write before this lifecycle point is transient.

# 2026-08-18 — Final commit has three distinct state outcomes

In `AIMainUpdate_00424E70`, successful countdown and normal planner paths
reach the shared copy at `LABEL_86`, transferring planner values
`V+0x4434/2C/38` to the final vector `V+0x357C/80/84` and clearing the traffic
target. Controller state 2 instead calls `FieldZeroSetter` and returns before
that copy, preserving the prior final vector. States 4/5 bypass normal planner
work and fall through to an explicit neutral final overwrite
(`0, 0, 1`). Thus neither active-list membership nor a fixed tick guarantees a
fresh planner vector: output depends on the controller state in addition to
mode and waypoint acquisition.

# 2026-08-18 — Pit strategy is a periodic planner reset, not a final-output writer

`AIMainUpdate_00424E70` invokes `AIAbility_00429470` only after its
four-second timer gate. `AIAbility` evaluates pit/ability conditions, can call
`ForcePitExit`, `PitStopDecisionTireCompound`, and
`RacePhasePitEntryTrigger`, and in its recovered pit-reset branch clears
planner/controller state, sets `V+0x4434 = 0` and `V+0x4438 = 1`, and calls
`sub_426430(V)` to reacquire the route horizon. It also reinitializes
associated state/timers before returning. This places pit strategy upstream of
the normal planner and shows that lifecycle-like pit decisions can overwrite
planner defaults on a coarse cadence; it is not an independent authoritative
write to the translated final vector or a safe SDK pit-control contract.

# 2026-08-18 — Profile inputs reach planning, but only through lifecycle-owned state

`sub_424080_00424080` parses the driver profile during the full
`AIDriverStructInit_00424790` lifecycle branch. It converts `PASSING` into
`V+0x44CC` (`this[4403]`) as `min(value * .001 + .9, 1.0)`; the normal
`AIRacingLine_00425920` horizon loop multiplies its forward-distance reduction
by that same field. Thus `PASSING` affects route-horizon deceleration before
the planner writes longitudinal output, rather than directly writing a
command.

The parser writes `CORNERINGADD`/`CORNERINGMULT` to `V+0x4500/+0x4504`
(`this[4416/4417]`). `sub_426430_00426430` combines those terms while deriving
lookahead, and `AIComputePassScore_0042A780` uses them in the route-node score
that `AIRacingLine` consumes. `RAINABILITY` becomes a derived multiplier at
`V+0x4580` (`this[4448]`), which is also a factor in that score. These are
verified upstream profile influences on racing-line planning.

`TRACKAGGRESSION` is scaled and floor-clamped into `V+0x44F8`
(`this[4414]`); `AISteering_004270A0` uses it in traffic candidate distance and
window calculations. `RACEABILITY` is transformed into the speed/ability terms
at `V+0x44C4/+0x44D4/+0x44D8/+0x44F4`, then `AIAbility_00429470` uses them to adjust
its runtime multiplier. This is evidence of profile influence, not a safe SDK
write contract: the parser recomputes these fields and the ability routine
rewrites the derived runtime term.

# 2026-08-18 — Late longitudinal correction has conditional replacement and a difficulty cap

On the normal `AIMainUpdate_00424E70` route, `AIRacingLine_00425920`,
`AISteering_004270A0`, `sub_426100`, and then
`AISteeringCorrection_00426CF0` execute before gear logic and the final-vector
copy. `AISteeringCorrection` first attenuates `V+0x4434` when steering magnitude
exceeds `.1` at speed above `20`. Under its grip/state gate it then interpolates
that same value toward the opaque `SuspensionRatioClamp(V+0xC)` result; only the
interpolation weight is statically bounded `[0,1]`, so this does not establish
the target's domain.

The routine subsequently has explicit near-event brake/drive replacement
branches and, absent the `byte_5C3160` path, caps `V+0x4434` to
`V+0x457C` (`this[4447]`). That cap is initialized from `AIDifficultyScalar()`
by the profile parser and is refreshed by `AIAbility_00429470`; the correction
itself can set it to `AIDifficultyScalar() * .75` under a state flag. Therefore
the longitudinal planner value has a verified late, lifecycle-owned cap but no
proved universal lower/upper external-input domain or stable write phase.

# 2026-08-18 — Independent offset-alignment evidence for the physics subobject

Let `V` denote the outer vehicle record and `P = V + 0x0C` the working
physics-subobject hypothesis.  `VehiclePhysicsModeDispatcher_004E4930` reads
its mode at receiver offset `+12988`; `MainGameTickUpdate_0042C690` tests the
corresponding registered-vehicle mode at `V+13000`.  Since
`0x0C + 12988 == 13000`, those raw offsets independently align with the
`P = V+0x0C` model.

The same translation maps the normal AI committed fields
`V+0x357C/+0x3580/+0x3584` to `P+0x3570/+0x3574/+0x3578`, the locations read
by the recovered physics integration routines.  In dispatcher mode 2,
`TeamColorLoader_004F03E0` dereferences its receiver word zero and passes that
value to `VehiclePhysicsTimeStep_004C73F0`; the latter writes its packet-derived
steering and third command at outer offsets `+13696/+13700`.

This is strong static layout and consumption evidence, not proof of the
assignment or lifetime of `P[0]`.  The recovered corpus still contains no raw
write that establishes `P[0] = V`; a writable SDK boundary cannot rely on that
unrecovered initialization fact.

`SceneRenderUpdate_004C6D90(V, full)` calls
`VehicleRespawnReset_004E0800(P, full)` and then
`LargeConfigFunctionWithPhysicsConstants_004E45B0(P)`. Both routines
dereference `P[0]` as an outer vehicle pointer (`+13000`, `+18580/+18584`, and
`+18324` accesses); neither writes `P[0]`. The intervening
`MultiSystemStructInitializer_004E0DB0` and `LazyInitCallback_004E0D00` also
contain no write to that word. Thus the back-reference is a verified
precondition of reset/configuration, while its establishment remains outside
the recovered raw path.

# 2026-08-18 — Translated slots have distinct normal-physics consumers

The AI final-vector copy aliases the physics object as `P=V+0xC`, so its
three destinations are `P+0x3570/+0x3574/+0x3578`. In normal mode,
`PhysicsIntegrationStateMachine_004E4E60` calls `sub_4E51A0`, then
`WheelForceCalculationSpringDamperTorque_004E5470`, then `sub_4E5AE0` in that
order. The wheel-force routine directly forms its steering angle from
`P+0x3574`; it is a direct steering consumer.

`sub_4E51A0` can first set `P+0x3578` to `1` and uses that slot to derive
wheel-side parameters. It can also zero `P+0x3570` under its state gate.
`sub_4E5AE0` subsequently uses `P+0x3570` in its normal-mode drive/brake
state update. Separately, the decimated post-scene `sub_4EE2D0(P)` invokes
`ThrottleBrakeOverride_004EE230`, which transforms that same slot only when
per-wheel override entries equal the `-789.0` sentinel. Thus longitudinal
reaches normal vehicle-state calculations, but there are documented
same-cycle overwriters and a sentinel-gated side path; this still cannot prove
exclusive AI ownership or a safe external write point.

More exactly, `sub_4E51A0` writes `P+0x3578 = 1.0` only when its
`P+14740` state is zero, and writes `P+0x3570 = 0.0` when `P+14712 <= 0`.
`sub_4E5AE0` reads `P+0x3570` in its shown update only under its
`P+14832 == 1 && byte(P+14828)` branch. These are raw conditional accesses,
not recovered semantic names; they demonstrate why the final vector is not
write-once or independently authoritative even on the normal integration path.

# 2026-08-18 — Gear requests are planner-adjacent, not part of the final vector

Immediately after `AISteeringCorrection_00426CF0`, normal
`AIMainUpdate_00424E70` calls `PhysicsGearShiftLogicWithThresholds_00426330(V)`.
The recovered caller-side logic returns under a timer gate, requests `-1` for
controller state 6, requests `0` for a mode/state test, and requests the next
gear when its current-gear and threshold conditions pass. Its downshift path
for current gear greater than one leaves the corpus via `JUMPOUT(0x4F62E6)`.

`RaceStartCountdownStateUpdate_004EF930` writes shift-request/current/timer
state at receiver offsets `+0x3A08/+0x3A04/+0x39F0`; the normal integration
then reads related state in `sub_4E51A0` and `BrakeCoolingPostTreatment_004E5080`.
However, the recovered source omits the effective receiver at the gear helper's
bare calls, and the downshift tail is absent. The nearby call order establishes
that gear selection is executed after steering/longitudinal correction, but it
does not prove an outer-to-physics ownership bridge or a writable SDK gear API.

# 2026-08-18 — Race progress affects traffic and pit decisions, not final-slot ownership

`AITickUpdate_004BF4F0` updates each active vehicle's lap/progress fields
(`V+0x403C`, timing values including `V+0x4098`) and calls
`AIDriverSorting_004BF390`. The sorter assigns order state at `V+0x4060` by
comparing lap count and session timing. Neither routine reads or writes the
planner/final command slots.

Race progress nevertheless feeds core decisions. On each normal planner frame,
`OpponentProximityScanTeamRecognition_0042A7D0` can select a nearby vehicle as
the traffic target when its `V+0x403C` lap exceeds the current driver's lap;
that target and lateral direction feed later steering/overtake processing.
`Overtaking_0042AF70` also compares these lap fields. Separately,
`FuelWeightLimitCheck_0042AD50` computes remaining laps from the same field,
and `AIAbility_00429470` uses that check in its pit-decision path. This proves
race-order/progress influence on traffic and pit strategy, while preserving the
separate result that race-order code is not a final-vector writer and its phase
relative to the decimated AI tick remains unrecovered.

# 2026-08-18 — Pit state is a separate physics-side controller

`VehiclePhysicsModeDispatcher_004E4930` invokes
`PitStateUpdateMachine_004A6E50(P+0x32C0, dt)` before normal integration for
the applicable physics modes. That state machine advances pit phases through
collision/proximity checks, `PitStopProgress`, and `PitStopReadyCheck_004A6200`.
The ready check tests vehicle motion, only performs its recovered gear-neutral
request when the referenced vehicle mode is `1`, then invokes tire-compound and
pit-operation timing work. No recovered instruction in either pit routine
writes `V+0x4434/2C/38` or the translated final slots.

The bare gear-update call again has an omitted effective receiver, so the
precise gear-object bridge remains unproven. What is proven is the ordering:
pit control is a physics-side state machine before normal integration, whereas
AIAbility's pit decisions are upstream planner resets. Neither path is a safe
external final-output contract.

# 2026-08-18 — Traffic reaches steering through lateral-target state

`AISteering_004270A0` evaluates traffic candidates and calls
`Overtaking_0042AF70` for selected candidate states. The overtake routine can
set the transient target pointer `V+0x45FC` and preferred lateral direction
`V+0x4420` (`this[4360]`). `AISteering` clamps/adjusts that direction into its
lateral target/bounds state (`this[4354/4355]`) while resolving candidate
clearance and lane constraints; it does not directly write the final steering
slot.

Immediately afterward `AIMainUpdate_00424E70` invokes `sub_426100(V)`. That
routine derives route-relative steering from the selected horizon geometry and
lateral target, slews it by at most `.1` per call, and clamps `V+0x442C` to
`[-1, 1]`. The later final-vector copy transfers that steering value to
`P+0x3574`, which `WheelForceCalculationSpringDamperTorque_004E5470` consumes.
This is the verified traffic/overtake-to-steering path; the traffic target is
cleared by the normal final-copy branch, so it is not persistent API state.

# 2026-08-18 — Start profile inputs become a conditional longitudinal cap

`sub_424080_00424080` reads `STARTSDRY` and `STARTSWET`, interpolates them by
the session wetness scalar, adds bounded random variation, and stores the
derived value at `V+0x44B8` (`this[4398]`). `AIRacingLine_00425920` selects
that field as its longitudinal ramp factor on the `byte_5C3160` start-state
path. `AISteeringCorrection_00426CF0` later caps `V+0x4434` to the same value
when that start-state path is active.

`AIMainUpdate_00424E70` separately has countdown-specific direct planner
outputs that reach the normal final copy. The profile-derived start value is
therefore an upstream conditional cap, not an initial final-command value, and
it remains lifecycle/random-state owned rather than externally writable SDK
configuration.

# 2026-08-18 — Mode-2 packet path writes overlapping command fields

For dispatcher mode 2, `VehiclePhysicsModeDispatcher_004E4930` enters
`TeamColorLoader_004F03E0`; that routine obtains a packet and calls
`VehiclePhysicsTimeStep_004C73F0` on the controller pointer stored by the
physics-side object. In its mode-2 branch, `VehiclePhysicsTimeStep` clamps the
packet steering scalar to `[-1,1]` and writes it to `V+0x3580` (the same memory
as `P+0x3574`), calls `EffectParameterSetter` for the overlapping command-side
state, and writes `V+0x3584` from a packet bit. The normal serializer
`SetupCarLightingAndRender_004C71C0` independently encodes
`V+0x357C/+0x3580/+0x3584` into an output packet.

`AIMainUpdate_00424E70` rejects mode greater than 1, so normal AI and this
mode-2 packet writer are statically separated by the current mode. Transition
ordering and the physics-side controller backpointer are not fully recovered;
therefore this proves a competing lifecycle route, not a safe SDK interception
phase or packet/replay ordering guarantee.

# 2026-08-18 — Packet-controller backpointer remains unproven

`RaceStructInit_00423E80(V)` constructs the physics object at `P=V+0xC` through
`PhysicsTireSystemConstructor_004E4500(P)`. The recovered constructor and its
first initialization helpers (`sub_4F6F20(P+8)`, `sub_4DFBB0(P+1764)`) initialize
their own regions but contain no recovered write to `P[0]`. Yet the mode-2
`TeamColorLoader_004F03E0` dereferences its controller's first word to obtain
the argument to `VehiclePhysicsTimeStep`.

This leaves the static pointer provenance unresolved: the packet write itself
and its mode gate are verified, but the decompiled constructor corpus does not
prove where the controller-to-outer-vehicle reference is established. It must
not be promoted to a guaranteed SDK object-layout contract.

# 2026-08-18 — Remaining profile inputs feed race initialization and events

`QUALIFYINGABILITY` is transformed into `V+0x44C0` by
`sub_424080_00424080`. `RandomVariationScaler_004BEA10`, used during
`AIBehaviorInitialization_004BF0A0` race-progress initialization, selects that
term outside the session-7 branch (which uses the corresponding race-ability
term). It therefore shapes initialized timing/progress variation, not a direct
planner command.

`CRASH` (`V+0x44D0`) and `COMPLETEDLAPS` (`V+0x44DC`) are consumed by
`AICollision_004BEF60` as scaled probabilities for collision/event outcomes.
`STARTSTALLS` (`V+0x44BC`) is read by the profile parser's race-event branch to
probabilistically seed a start stall state. These profile keys are verified
inputs to event/race initialization; no recovered path makes them writable
per-tick AI controls or final-vector fields.

# 2026-08-18 — Raw command-slot writer audit remains non-exclusive

The outer final vector has recovered literal writers in
`AIMainUpdate_00424E70` (normal copy plus explicit neutral state) and, in
mode 2, `VehiclePhysicsTimeStep_004C73F0` (packet steering and third-component
bit). Through the `P=V+0xC` alias, physics-relative writers include lifecycle
reset `sub_4E4790`, mode-0 seed `VehicleSetupInitialization_004E49B0`, normal
integration `sub_4E51A0`, `BrakeCoolingPostTreatment_004E5080`, and
`EffectParameterSetter_004F17A0` called by the mode-2 packet path.

This audit is evidence of multiple writers, not proof of an exhaustive binary
write set: decompiled indirect/opaque helpers may hide writes, and identical
numeric offsets refer to different addresses when the receiver is `V` versus
`P`. It is sufficient to reject exclusive ownership of the slots and therefore
insufficient to authorize any writable SDK contract.

# 2026-08-18 — Pit controller transitions are event-driven

`PitStateUpdateMachine_004A6E50` advances its controller through
`StateChangeNotify_004A5C80`; the notifier emits a state-change event and calls
`AIStateMachineWithModeDispatch_004A5D10` only on an actual transition.
`AIStateMachineWithModeDispatch` observes the referenced vehicle mode and has
additional handling for modes 2/3, while the recovered event-dispatch path
invokes it for the mode-2 controller case. This confirms that pit state and
packet-mode state machinery share lifecycle/event infrastructure, but neither
routine writes the normal final AI vector. It reinforces that no standalone
pit/AI state field can be exposed as a stable writable contract.

# 2026-08-18 — Current evidence gate: core map broad; SDK contract unproven

The investigation now has direct static paths for initialization/profile input,
decimated AI scheduling, waypoint horizon/racing-line selection, traffic to
steering, longitudinal correction, pit strategy, race-progress effects, and
the normal planner-final-vector-physics-consumer route. Partial areas are
explicitly marked: gear has an omitted receiver plus missing tail; race-order
phase relative to the main tick is unrecovered; packet-controller pointer
provenance and transition ordering are unrecovered; and opaque helpers prevent
universal domains for longitudinal/gear behavior.

A safe writable SDK contract remains unproven because no recovered phase
establishes all required properties simultaneously: stable object provenance,
exclusive or arbitrated ownership, bounded input domains, lifecycle/reset
survival, and packet/replay isolation. The evidence therefore supports a
read-only mapping and rejection of direct field writes, not a writable SDK
surface. This is a status gate, not completion of the requested SDK contract.

# 2026-08-18 — Alternate consumer scheduling can use stale planner output

The ordinary `MainGameTickUpdate_0042C690` decimated branch calls
`AIMainUpdate`, scene/physics work, and then `sub_4EE2D0(P)` for each active
vehicle. Separately, `ConditionalMultiPathDispatcher_004BA180` can call
`sub_4B9B80_004B9B80`; whenever its time crosses a `.025` interval,
`sub_4B9B80` calls `sub_4EE2D0(P)` for every active vehicle without a preceding
`AIMainUpdate` in that routine.

`GamePostMainLoop_0042D8A0` and the loading-phase `StateTriggerCheck_004B8AE0`
place this dispatcher before their subsequent `MainGameTickUpdate` call. The
surrounding dispatcher state is still not fully classified, so this does not
establish replay semantics or prove stale consumption over a complete outer
loop. It does prove a second recovered consumer pass prior to the regular main
tick, with no `AIMainUpdate` inside that pass, and therefore excludes assuming
that the regular planner-copy sequence is the sole command-consumption phase.

# 2026-08-18 — Third planner component has no proved Boolean domain

The planner's third component `V+0x4438` is copied to `P+0x3578` and is used
by `sub_4E51A0` as a multiplier. Its recovered writers include `0`, `1`,
countdown-derived fractional values, and `TireGripCoefficient(V+0xC)` from
`AISteeringCorrection_00426CF0`; the latter's range is not recovered.
`AIDriverStructInit_00424790` also initializes the field to `50` before later
state/lifecycle logic establishes operational values.

`SetupCarLightingAndRender_004C71C0` encodes the translated final third
component as a packet bit using a `.01` threshold, but that serialization rule
does not constrain the internal planner or physics multiplier. Any SDK claim
that calls this component Boolean, normalized, or safely writable is therefore
unsupported by the static evidence.

# 2026-08-18 — Core planner domain helpers are absent from the recovered corpus

The canonical raw-function search finds `TireGripCoefficient` and
`BrakeThermalModel` only as call sites in `AIRacingLine_00425920` and
`AISteeringCorrection_00426CF0`; no corresponding recovered body is present.
Those helpers directly supply values assigned to the longitudinal and third
planner components. Together with the absent `SuspensionRatioClamp` body, this
prevents deriving universal safe numeric domains for those controls from the
available static corpus.

# 2026-08-18 — Profile SCRIPT has parser-only evidence

A canonical raw-function search for `V+0x44E0`/`17632` finds only the default
and profile-string copies in `sub_424080_00424080`; no recovered reader,
dispatcher, or executor accesses that storage. Therefore `SCRIPT` is verified
as parsed/copied profile data, but its runtime semantics are absent from this
corpus and it cannot be presented as a driver-AI scripting or SDK hook.

# 2026-08-18 — No recovered external insertion around the AI main update

The canonical raw-function caller search finds `AIMainUpdate_00424E70` only in
the decimated loop of `MainGameTickUpdate_0042C690`. A complementary search
finds no recovered AI SDK, plugin, external-control, or AI callback hook in
the canonical function corpus. This cannot prove the absence of un-recovered
binary behavior, but it provides no static basis for an SDK insertion phase
between planner evaluation and final-vector/physics consumption.

# 2026-08-18 — Physics-dispatch receiver is an inferred base, not a proved layout contract

Several decompiled calls to `VehiclePhysicsModeDispatcher_004E4930` omit the
effective `this` receiver. Its field offsets are consistent with the previously
used physics-subobject label `P`, and downstream code reaches the translated
slot aliases under that interpretation. However, the recovered constructor
path does not prove the controller backpointer required by the mode-2 helper,
and no recovered call site independently fixes the dispatcher's exact base.

Accordingly, `P=V+0xC` remains a useful offset-alias working model for the
normal output chain, but not a guaranteed public object-layout contract.
Statements in this investigation about dispatcher-relative offsets are static
data-flow evidence, not authorization to dereference or write those offsets
from an SDK.

# 2026-08-18 — Physics subobject-to-vehicle use is verified; its initialization is not

`sub_4C6B60_004C6B60(V)` directly passes `V+0xC` to
`SuspensionStateUpdate`, supporting the `P=V+0xC` subobject interpretation.
`AIRacingLinePathFollowing_004E9CA0`, when operating on that physics-side
context, dereferences `P[0]` and writes an outer-vehicle field through it. This
verifies the *use* of `P[0]` as an outer-vehicle reference in the recovered
physics/scene path.

The constructor-path searches still do not recover the assignment that creates
that reference. Thus the P-to-V relationship is behaviorally supported but its
initialization/provenance remains unproved; it must not be turned into an SDK
object-lifetime guarantee.

# 2026-08-18 — Superseding correction: the normal mode-1 steering alias is direct

The earlier sections titled “Normal mode-1 wheel-physics offsets do not consume
the AI command slots” and “`+0x3574` normal-mode source is global physics
state, not AI steering” predate the receiver-aware alias audit and must not be
used for final conclusions. Their literal `+0x3574` search was a
physics-receiver-relative search; it did not account for
`P+0x3574 == V+0x3580` when `P=V+0x0C`.

The corrected direct path is
`AIMainUpdate: V+0x442C -> V+0x3580 == P+0x3574 ->
WheelForceCalculationSpringDamperTorque_004E5470`, which multiplies that value
by `P[3672]` and derives sine/cosine for wheel-force geometry. The prior mode-0
setup/reset writes remain real competing owners, but they do not negate this
normal mode-1 AI-to-steering consumption path. This correction changes neither
the unrecovered `P[0]` initialization nor the no-writable-SDK conclusion.

# 2026-08-18 — Superseding correction: normal-mode consumption is mapped, not exclusive

Earlier report passages saying that no direct all-AI actuator consumer of the
copied scalar trio was recovered are superseded by the translated-slot audit.
For mode-1 eligible vehicles, the recovered normal chain directly consumes
`P+0x3574 == V+0x3580` in wheel steering geometry, conditionally uses
`P+0x3570 == V+0x357C` during normal integration/override work, and conditionally
uses `P+0x3578 == V+0x3584` in per-wheel coefficient derivation. The remaining
qualification is ownership and lifecycle, not absence of a normal physical
consumer: setup, reset, in-step gates, packet mode, and unrecovered `P[0]`
provenance still preclude a safe writable contract.

# 2026-08-18 — Superseding correction: two planner helper bodies and bounds are recovered

The earlier “Core planner domain helpers are absent” entry is superseded for
`BrakeThermalModel_004E87E0` and `TireGripCoefficient_004E88B0`. Both raw
bodies are present in the canonical function corpus and explicitly clamp their
returns to `[0,1]` (with zero returns on the shown invalid/zero denominators in
the brake helper). Their uses in `AIRacingLine_00425920` and
`AISteeringCorrection_00426CF0` therefore have bounded helper-derived values.

This does not establish a universal external range for `V+0x4434` or
`V+0x4438`: `SuspensionRatioClamp` remains unrecovered, and other planner,
setup, packet, and lifecycle writers can replace the helper-derived results.

# 2026-08-18 — Superseding correction: `SuspensionRatioClamp` is recovered and bounded

`SuspensionRatioClamp_004E8780` is present in the canonical raw corpus. It
returns `0` when `P[3691]` is zero, otherwise computes `-P[3690]/P[3691]` and
clamps that result to `[0,1]`. The `AISteeringCorrection_00426CF0` blend toward
this helper therefore has a bounded target and a separately bounded blend
weight. Earlier entries that described this helper as absent or opaque are
superseded.

This removes one normal-route range gap but not the complete external contract:
the countdown-table branch, packet/setup/lifecycle writers, output ownership,
and write-phase identity remain independently unproved.

# 2026-08-18 — Constructor-side `P[0]` candidate remains receiver-inferred

The recovered construction order is
`VehicleObjectConstructor_004C6920 -> RaceStructInit_00423E80 ->
PhysicsTireSystemConstructor_004E4500(V+0xC)`, followed by
`LargeStructFieldSetterWithStoredReference_00424040(V, V)`. The latter first
writes `V[0]=V` and then calls `F_4FieldPropagation_004E4590(V)` with a
decompiler-omitted effective receiver. `F_4FieldPropagation` writes fields
`[0]`, `[2]`, `[441]`, and `[3248]`; those are the same structural field
positions initialized by the `V+0xC` physics-subobject constructor path.

This is the strongest recovered static candidate for establishing `P[0]=V`,
but it is not proof: the raw C does not preserve the call's effective receiver
or any explicit `P[0]=V` store. Treat the backpointer initialization and its
lifetime as an inference only. The verified normal AI-output consumption chain
therefore remains unsuitable as a writable SDK memory contract.

# 2026-08-18 — Superseding correction: `P[0]=V` is directly proven

Read-only instruction-level inspection of `LargeStructFieldSetterWithStoredReference`
at `0x00424040` resolves the omitted receiver exactly. With `ESI=V` and its
sole argument `EDI=V`, the code executes `lea ecx,[esi+0xC]`, stores
`[esi]=edi`, pushes `edi`, and calls `F_4FieldPropagation_004E4590`.
`F_4FieldPropagation` then executes `mov [ecx],eax` before its other stores.
Therefore the constructor directly establishes `P=V+0xC` and `P[0]=V`.

The earlier entry headed “Constructor-side `P[0]` candidate remains
receiver-inferred” is superseded with respect to initialization/provenance.
This removes the embedded-physics backpointer ambiguity from the normal AI
output path. It does not create a safe writable SDK contract: command-slot
ownership, range, timing, reset, and packet/replay arbitration remain separate
requirements.

# 2026-08-18 — Exact static-recovery bound for the missing gear continuation

`PhysicsGearShiftLogicWithThresholds_00426330` exits to `0x004F62E6` for its
current-gear-greater-than-one branch. The existing static recovery index has
no function at that address: its nearest recovered predecessor is
`TheSvmHdvVehicleFileParser_004F4270`, and its nearest recovered successor is
`ParameterizedCurveInterpolation_004F6720`. A search across the recovery
index, name index, knowledge graph, and canonical function source finds no
alternate body or symbol for `0x004F62E6`.

The normal downshift decision is consequently an explicitly bounded missing
static range, not an omitted search step. The recovered gear request and
application paths remain valid only as a partial mapping; they cannot support
a complete writable gearbox or AI-command contract.

# 2026-08-18 — Superseding correction: the gear downshift tail is recovered

The raw-function `JUMPOUT(0x004F62E6)` is a decompiler rendering error, not
the actual control-flow target. Read-only disassembly of the existing game
executable at `0x00426330` shows the local continuation at `0x004263D9`.
After the already recovered upshift comparison fails, it:

1. returns unless current gear (`V+0x39FC`) is greater than one;
2. returns unless engine speed (`V+0x39A0`) is strictly below the indexed
   per-gear threshold at `V+0x3A1C + 4*currentGear`;
3. returns unless both `V+0x37CC` and `V+0x38C4` are positive against the
   same zero constant used by the earlier branch; and
4. invokes `RaceStartCountdownStateUpdate_004EF930(V+0xC, currentGear-1)`.

The upshift branch remains `currentGear < V+0x3A04` after its own RPM and
positive-gate checks, and requests `currentGear+1` through the same embedded
receiver. This completes the static shift-request decision map. It does not
turn the gearbox path into a writable SDK API: the request routine's terminal
receiver/application ownership, mode/lifecycle arbitration, and any supported
external write phase remain unproved. Earlier entries describing
`0x004F62E6` as an absent normal downshift body are superseded.

# 2026-08-18 — Gear request-to-application chain is fully mapped

With the now-proven `P=V+0xC`, the request and application fields resolve
without an omitted receiver. `RaceStartCountdownStateUpdate_004EF930(P, gear)`
writes pending target `P+0x3A08 == V+0x3A14` and a delay timer at
`P+0x3A04 == V+0x3A10`. `BrakeCoolingPostTreatment_004E5080(P)` decrements
that timer by the physics time step; on expiry it copies
`P+0x3A08` into `P+0x39F0 == V+0x39FC`, the current-gear field read by
`PhysicsGearShiftLogicWithThresholds_00426330`.

Thus the verified normal chain is AI shift decision -> embedded request/timer
-> physics-step timer expiry -> current gear. During the timer, the same
physics routine also conditionally overrides the longitudinal control alias;
the shift path is therefore internally authoritative but explicitly
game-owned. No external write ABI, ownership handshake, or safe cross-mode
contract follows from this complete internal map.

# 2026-08-18 — Core-AI map completion audit; writable-contract gate remains open

The requested core mapping is now covered by direct static evidence:

| Goal area | Verified result |
| --- | --- |
| Initialization/profile | Vehicle construction proves `P=V+0xC` and `P[0]=V`; driver profile parsing and its planning consumers are mapped. |
| Tick scheduling | `MainGameTickUpdate_0042C690` establishes the 2.5-ms loop, 25-ms AI update, and following scene/physics work. |
| Waypoint/racing line | `sub_426430`, `AIRacingLine`, and their route/profile inputs are traced to the planner trio. |
| Traffic/overtake | Proximity scan, overtaking state, steering target adjustment, and normal target clear are mapped. |
| Steering/longitudinal/gear/pit | The planner trio commits into normal mode-1 physics aliases; direct wheel/integration consumers, pit-state overrides, and the complete gear request/application chain are mapped. |
| Race order | Lap/timing update and sorting paths, plus their planner/pit interactions, are mapped. |
| Output to simulation | `V+0x4434/+0x442C/+0x4438 -> V+0x357C/+0x3580/+0x3584 == P+0x3570/+0x3574/+0x3578` is verified through scheduled normal mode-1 consumption. |

This closes the *core behavior map*. The remaining objective is not a missing
behavioral branch but a separate SDK safety proof. A writable contract still
requires an externally supported insertion phase, definitive writer ownership
across reset/pit/packet/replay paths, complete input-domain rules, and
cross-session/multiplayer arbitration. The recovered game code supplies no
such API or handshake. Until new authority/evidence exists, the evidence-backed
SDK result is read-only observation, not writable control.

# 2026-08-18 — Countdown-table data recovered; range gap narrowed, not removed

Static inspection of the existing game executable's `.data` section (read-only;
no execution or modification) resolves the table bytes used by
`AIMainUpdate_00424E70`. The `unk_5C30E0 - CRTFtol(v18)` branch has 26
contiguous `float32` values for indices `0..25`, rising from `0.0` to
`0.949`. The `dword_5C3144[CRTFtol(v18)]` address begins with seven float32
values `0.949, 0.9636, 0.9757, 0.9854, 0.9927, 0.9975, 0.9998`; index seven is
the non-float word `0x00000001`, followed by string data.

The recovered code clamps the time-derived input to one second and multiplies
it by `-25`, but does not show a branch-local index bound for the second
address expression. Thus the first countdown table is now directly bounded,
and the second table's initial values are known, while the effective index
domain of its raw access is still not proven. This refines the countdown
longitudinal range evidence; it does not establish a universal writable input
range or change the no-writable-SDK decision.

# 2026-08-18 — `SCRIPT` has no direct native-executable consumer

Read-only disassembly of the complete existing game executable finds exactly
one `+0x44E0` field-displacement reference: `sub_424080_00424080` loads
`V+0x44E0` into a local pointer and uses it solely for the default-string copy
and the configured `SCRIPT` string copy. No other executable instruction
directly addresses `V+0x44E0`.

This strengthens the previous parser-only result: native recovered code has no
direct `SCRIPT` reader or dispatch path, so the field does not participate in
the mapped core AI behavior. It still cannot prove that an un-recovered
indirect/data-driven extension never obtains the buffer; therefore the field
remains non-writable and is not presented as a supported script hook.

# 2026-08-18 — Superseding correction: both countdown branches use the same bounded ramp

Instruction-level inspection of `AIMainUpdate_00424E70` corrects the apparent
second-table overrun. The time fraction is multiplied by the executable value
`-25.0` before integer conversion. When `V+0x4568` is nonzero, the code reads
`0x5C30E0 - 4*negativeIndex`, selecting ramp elements `0..25` forward. When it
is zero, it negates that negative index and reads `0x5C3144 - 4*positiveIndex`.
`0x5C3144` is the same ramp's element 25, so this selects the same 26 values in
reverse order—not the bytes after `0x5C3144`.

The countdown longitudinal output is therefore statically bounded to the
verified `0.0..0.949` ramp in either branch. The preceding table note's claim
that the second effective index domain was unproven is superseded. This is a
branch-specific producer bound only; lifecycle, competing-writer, and SDK
ownership constraints remain unchanged.

# 2026-08-18 — Correction to core-map completion wording

The earlier “Core-AI map completion audit” correctly records the major
architecture and normal control path, but its word “complete” overstates the
current evidence. Two core-system boundaries remain only partially phased:

1. `AITickUpdate_004BF4F0` and `AIDriverSorting_004BF390` establish race-order
   state and its traffic/pit inputs, but their `EngineFailureCheck_004BEC55`
   scheduling phase relative to `MainGameTickUpdate_0042C690` is not recovered.
2. `ConditionalMultiPathDispatcher_004BA180` can invoke
   `sub_4B9B80 -> sub_4EE2D0(P)` before `MainGameTickUpdate` in the main and
   loading loops. It is a conditional pre-tick consumer pass; its complete
   state/replay classification is not recovered.

`SCRIPT` has no direct native consumer and both countdown table branches are
now resolved, so neither remains a primary core-behavior gap. The accurate
status is a high-coverage core architectural map with the two scheduler/
lifecycle boundaries above still open, plus the separate safe writable SDK
contract gate.

# 2026-08-18 — Race-order phase reaches a static callback boundary

Read-only executable disassembly finds one direct call to
`EngineFailureCheck_004BEC55`, from the unindexed thunk at `0x0040FD64`, which
loads `ECX = 0x008AB710` and returns immediately after the call. A complete
instruction scan finds no direct call/jump to that thunk, and an exact address
search finds no raw absolute pointer reference. The recovery index likewise
has no caller for `EngineFailureCheck`.

Therefore the static corpus proves the race-order update's local work and
immediate thunk, but not the callback registration/outer scheduling phase.
This is a precise static-boundary result, not evidence that race ordering is
inactive. Resolving it requires a recovered callback-registration path or
runtime scheduling evidence; it cannot be inferred from the normal AI tick.

# 2026-08-18 — Correction: the thunk's callback status is not proved

Further read-only executable inspection shows that `0x0040FD64` starts
immediately after a `ret` at `0x0040FD63`; its two instructions are
`mov ecx, 0x008AB710; call 0x004BEC55`, followed by `pop esi; ret`. Complete
instruction scans find no direct branch to `0x0040FD64`; a whole-file exact
scan finds no little-endian absolute pointer `64 FD 40 00`; and the PE has no
base-relocation directory. These results strengthen the absence of a static
incoming edge, but do not identify a callback registration mechanism.

Accordingly, “callback boundary” in the preceding heading is descriptive, not
verified. The thunk may be reached through runtime-computed/indirect state, or
may be unreachable residue in this executable. Static evidence cannot choose
between those alternatives. The only verified conclusion is unchanged: the
outer phase of `EngineFailureCheck_004BEC55` is not statically recovered, and
no scheduler placement may be inferred from this thunk.

# 2026-08-18 — Conditional vehicle pass: phase and rate recovered

The second listed scheduler/lifecycle gap is narrower than previously stated.
Both direct static wrappers call `ConditionalMultiPathDispatcher_004BA180`
immediately before `MainGameTickUpdate_0042C690`:

- `GamePostMainLoop_0042D8A0` does so in its normal continued-session loop.
- `StateTriggerCheck_004B8AE0` does so in its loading/progress loop, after a
  positive progress-delta gate.

`ConditionalMultiPathDispatcher` itself proceeds only when its object type is
`2` and either a packed flag is set or its current float differs from the
stored float/flag state. It then calls `sub_4B9B80`. That function always
processes its timed-event range, but iterates vehicles and calls
`sub_4EE2D0(V+0xC)` only when the two endpoints cross a floor bucket at
`40.0 * time` (a 25-ms/40-Hz boundary). Neither function calls
`AIMainUpdate_00424E70`.

Thus this is a conditional, pre-`MainGameTick` vehicle-physics helper pass in
both a normal-session loop and a loading/progress loop—not an alternative AI
planner tick. The exact semantic meaning of the gate object and any replay
mode are still not identified, but replay classification is no longer needed
to place this pass or distinguish it from the 25-ms AI planner schedule.

# 2026-08-18 — Race-order write semantics recovered

`AIDriverSorting_004BF390` changes the vehicle race-position field at
`V+0x4060` through `ConditionalFieldSetter_004BC2F0(V+0x4034, newPosition)`.
The setter compares the existing `V+0x4060` value at its `this+0x2C`, invokes
`AIDriverStateTransition(dword_5EB978, *(int **)this, old, new)` only when it
changes, then stores the new value. The historical function name
`AIDriverStateTransition` must not be read as proof that `V+0x4060` is an AI
planner state: direct sorting code compares it as the per-car race position.

The sorting writer is reached from the session/behavior-initialization path
(`AIBehaviorInitialization_004BF0A0`), the timed update path
(`AITickUpdate_004BF4F0`), and the collision/failure pass
(`EngineFailureCheck_004BEC55`). It writes race-order state and emits its
change notification; it does not write the AI planner trio
`V+0x442C/+0x4434/+0x4438` or the normal physics aliases. This closes the
race-order field-write and output-separation portion of the core map. The
outer invocation phase of `EngineFailureCheck` remains separately unresolved.

# 2026-08-18 — Race-position notification is a guarded driver-event path

`AIDriverStateTransition_00419120`, reached only from the conditional
race-position setter above, does not write a planner or physics-control field
in recovered code. It gates on active race state, nonzero track condition,
race phase not equal to `8`, and an actual old/new position change. For race
session type `7`, it conditionally builds and inserts an entry into the driver
data table (`flt_5EA618`) using timing, player/driver identity, and randomized
selection. Its observable persistent destination is a per-driver position
mirror at `this[a2[4645] + 108]` after a valid entry is built.

No network-send call or write to `V+0x442C/+0x4434/+0x4438` or
`P+0x3570/+0x3574/+0x3578` appears in this path. Race-order therefore has a
verified event/announcement side effect in addition to position ordering, but
not a verified direct actuation side effect. This is static code evidence;
the human-facing meaning of individual driver-table IDs remains unlabelled.

# 2026-08-18 — Existing SDK metadata does not prove a writable control ABI

Read-only front-door metadata (`python tools/f1c_mod.py sdk-info --json`,
`capabilities --json`, and `tool-info control-ai-pace --json`) reports SDK
version `1.0.0`, broker ABI `10`, and a specialist `control-ai-pace` command.
That command is explicitly classified `live-write` and requires an
acknowledgement flag; its public description is only “adjust or restore a
named AI driver's proven live pace input.” No invocation, runtime observation,
SDK-file inspection, or modification was performed.

Metadata alone does not identify its target field, scheduling phase, writer
arbitration, domain, reset behavior, or replay/network handling. It therefore
cannot serve as evidence for a safe writable contract for the planner trio or
normal physics aliases. The evidence-backed status remains: existing specialist
pace control may be a bounded feature, while a general writable core-AI output
ABI is unproven.

# 2026-08-18 — Native reference audit: control aliases are phase-local

A complete read-only native-disassembly search for direct references to
`P+0x3570`, `P+0x3574`, and `P+0x3578` confirms the planner commit aliases are
not a stable three-float control ABI. In the normal
`PhysicsIntegrationStateMachine_004E4E60` substep sequence,
`sub_4E51A0(P)` runs before `WheelForceCalculationSpringDamperTorque_004E5470`.
`sub_4E51A0` directly clears/replaces `P+0x3570` in its suspension/damper
logic and can set `P+0x3578` to `1.0`; `WheelForceCalculation...` reads
`P+0x3574` as its steering-angle input for the sin/cos wheel transform.

This preserves the verified planner copy as the normal-path handoff, but
refines its lifetime: at least the longitudinal/third aliases are shared,
phase-local physics workspace after handoff and can be overwritten during the
same normal integration cycle. Direct external writes there would race both
the planner and physics writers. The binary scan also finds initialization/
mode writers and later physics reads of all three slots. Consequently the
control-output path is authoritative for observing the handoff and steering
consumption, not a proof of three independently writable persistent channels.

# 2026-08-18 — Full direct-writer classification for the three aliases

Instruction-level boundaries classify the direct writers found by the native
scan:

| Writer | Phase | `P+0x3570/+0x3574/+0x3578` effect |
| --- | --- | --- |
| `sub_4E4790` (called by `PhysicsTireSystemConstructor_004E4500`) | construction | clears all three slots |
| mode-0 branch of `VehiclePhysicsModeDispatcher_004E4930` (`sub_4E49B0`) | mode-0 update | writes all three from global input/state values |
| `AIMainUpdate_00424E70` | 25-ms planner handoff | copies the three planner values through `V+0x357C/+0x3580/+0x3584` |
| mode-1 `PhysicsIntegrationStateMachine_004E4E60 -> sub_4E51A0` | normal integration substep | can replace `P+0x3570` and sets/replaces `P+0x3578`; retains `P+0x3574` for wheel steering consumption |
| mode-2 branch | packet/alternate mode | has a separate writer path |

The dispatcher selects mode `0`, `1`, or `2` from `P+0x32BC`; mode `1` calls
the normal integration state machine. This is direct binary evidence of
cross-mode and intra-step ownership. It removes any remaining basis for
treating the three aliases as a writable SDK vector, while retaining the
specific verified planner-to-mode-1 steering handoff.

# 2026-08-18 — Current goal evidence matrix (not a completion claim)

| Requested area | Current evidence status | Boundary still open |
| --- | --- | --- |
| Initialization and profile inputs | Verified: `V`, `P=V+0xC`, `P[0]=V`, profile parser/keys, and planning consumers are recovered. | No externally writable profile/control contract follows. |
| Tick scheduling | Verified: 2.5-ms base stepping; every tenth step runs `AIMainUpdate` for the active array, then the scene iterator at the same time; race-order has a separate gated caller. | No public external insertion phase is recovered. |
| Waypoint/racing-line planning | Verified through nearest-node/lookahead and `AIRacingLine` to the planner handoff. | None material to the static behavioral map. |
| Traffic/overtake | Verified through proximity target, dual latch/side-offset writers, steering use, and reset paths. | Overtaking's exact omitted candidate argument remains an ABI detail, not a behavioral-map or SDK contract proof. |
| Steering / longitudinal / gear / pit | Steering planner handoff and normal wheel consumption, gear request/application, and pit-state branches are verified. | Longitudinal/third handoff aliases are phase-local/reused; no durable external input domain is proved. |
| Race order | Position comparison, field update, event-table side effect, initialization/timed/failure call sites, and the surrounding `AIOvertake` scheduler chain are verified. | No race-order field is a control input or safe write surface. |
| AI output to normal vehicle simulation | Verified: planner copy reaches `P+0x3570/0x3574/0x3578`; normal mode-1 physics consumes longitudinal in `sub_4E5AE0`, steering in wheel-force calculation, and the third component in `sub_4E51A0`. | The three fields are not a standalone persistent vector: constructors, mode paths, and normal substeps overwrite them. |
| Safe writable SDK contract | **Not proved.** Public pace metadata and generic SDK tests are insufficient. | Needs an inspectable supported insertion phase, ownership arbitration, validated domains/lifetimes, and independent runtime/replay/network/session evidence. |

This matrix is the authoritative current readiness statement for this
investigation. It distinguishes the high-coverage static core map from the
unmet writable-SDK proof; neither unresolved item may be silently treated as
completion.

# 2026-08-18 — Read-only live confirmation of race-progress input

Authorized elevated hidden runtime observation used the supported front door
with the running `F1 Challenge Online.exe`; it made no game-memory write.
The preserved observation is
`runtime_memory/observations/ai_core_probe_20260818_01/observation.json`.
Over 10.016 seconds at 20 Hz, all 22 active vehicle slots were readable with
zero unreadable reads. The known `V+0x403C` lap-number field was
`STRONGLY_SUPPORTED` (100%): four natural, monotonic `7 -> 8` transitions
occurred in separate vehicle slots, within total-race-laps `53`.

This live evidence confirms the static race-progress input used by sorting and
pit/race logic in the actual running process. It does not locate or invoke
`EngineFailureCheck_004BEC55`, establish its scheduling phase, or authorize a
write to any race-order or control field.

# 2026-08-18 — `EngineFailureCheck` runtime-caller probe was inconclusive

An authorized elevated, hidden x32dbg headless attach was attempted against
the running `F1 Challenge Online.exe` to log the return address on entry to
`EngineFailureCheck_004BEC55`. The debugger attached, but its supplied script
did not load: its log contains no `004BEC55` breakpoint installation or hit,
and no stack artifact was produced. The probe was then detached through the
operating system debug-object API (`NtRemoveProcessDebug` returned success),
and a subsequent elevated query reported no debug object; the game remained
running and responsive.

This attempt supplies no execution or non-execution evidence for
`EngineFailureCheck_004BEC55`. In particular, its absence of a hit must not be
used to label the function inactive, unreachable, or unscheduled. The outer
invocation phase remains an open evidence boundary.

Two follow-up attempts used headless stdin command delivery, which the current
tool's own source exposes as its command interface. In this target, its `run`
command did not return to process the queued timeout-detach command, and both
attempts required the same verified OS-level detach. Neither emitted a stable
breakpoint-installation or hit artifact before cleanup. This is a debugger
lifecycle/tooling limitation, not evidence about `EngineFailureCheck`.

# 2026-08-18 — `EngineFailureCheck` outer scheduler recovered from raw bytes

The prior standalone-callback boundary is superseded. Read-only disassembly of
the active build at `0x004BEB00..0x004BEF30` proves that
`AIOvertake_004BEB10` and the decompiler's `EngineFailureCheck_004BEC55` are
one contiguous machine-code function. After its setup and optional
`AIBehaviorInitialization_004BF0A0` call, the routine initializes the vehicle
array iterator at `0x004BEBF1..0x004BEC03` and performs a direct
`jmp 0x004BEC10`. The bytes at `0x004BEC10..0x004BEC4E` advance the per-car
timer and apply the participation/lap gates; `0x004BEC55` is the fall-through
session gate in that same loop, not an externally callable entry point.

The loop ends at `0x004BEEF2`; its tail directly calls `AITickUpdate_004BF4F0`
at `0x004BEF12`. The normal outer call chain is therefore recovered as
`DispatchChainWithVTableCalls_0046DA20 -> sub_46BF10 ->
AIOvertake_004BEB10 (contiguous 004BEC10/004BEC55 loop) ->
AITickUpdate_004BF4F0`. `sub_46DC60` is a second recovered direct caller of
`sub_46BF10` under its session gate.

This closes the `EngineFailureCheck` scheduler/reachability gap for the static
core map. It does not prove a public writable insertion phase, command-domain
limits, or replay/network authority; those remain the separate SDK-contract
gate.

The inspected executable hashes to
`1A70E5ED0C4A059F7F66741B1682D0AEDB14921AA6140CDB70B09549FDF3A003`,
matching the corpus's `analysis/canonical_variant_profile.json`; this is
canonical-variant evidence, not a conclusion drawn from a different build.

# 2026-08-18 — Reviewed SDK surface audit confirms no general control contract

The repository's supported front door (`python tools/f1c_mod.py`) reports a
healthy canonical SDK (`doctor --json`: `ok: true`, target verified). Its public
capability catalogue exposes `control-ai-pace` only as a `specialist`,
acknowledged-risk `live-write` operation whose scope is one named driver's
“proven live pace input.” It supplies no declared steering, gear, pit, or
planner-vector control capability.

Canonical field queries list `ThrottleFactor` at `V+0x357C` and `BrakeFactor`
at `V+0x3584` as `CONFIRMED`, but both cite only the historical `f1cui` source.
`V+0x3580` has no canonical field name. The supported evidence query identifies
`AIMainUpdate_00424E70` and `VehiclePhysicsTimeStep_004C73F0` as writers, then
explicitly cautions that receiver identity is function-local. It does not add
a bounded value domain, a post-owner write slot, exclusive/arbitrated ownership,
or replay/network/session semantics.

Therefore the reviewed SDK surface corroborates the static boundary rather than
closing it: pace is a narrow, risk-acknowledged specialist feature; no safe
writable general AI control-output contract is presently proved.

# 2026-08-18 — Exact post-AI, pre-physics candidate phase recovered

Read-only canonical-build disassembly resolves the only viable ownership phase
for a future general controller, while deliberately not claiming that the
phase is exposed today. On every tenth fixed tick, `MainGameTickUpdate_0042C690`
executes `AIMainUpdate(V)` for every active vehicle at
`0x0042C741..0x0042C755`. It then immediately invokes the global object loop
at `0x0042C757..0x0042C768`:
`LoopWithConditionalSkipFunction_00410980(dword_5EA560, tickTime)`.

In its mode-6 scene-object branch, raw `SceneObjectLoaderStateMachine_0040F1C0`
loads `P` from the object's `+0x20`, checks the active-control bit through
`P[0]` (the verified outer `V`) at `V+0x48BC`, and calls
`VehiclePhysicsModeDispatcher_004E4930` with `ECX=P` at
`0x0040F26F..0x0040F28B`. Thus the normal sequence is:

`all V: AIMainUpdate commits V+357C/+3580/+3584` → `global scene loop` →
`per eligible P=V+0xC: VehiclePhysicsModeDispatcher`.

This is the exact game-thread insertion *candidate* for an eventual brokered
override: after the complete AI loop and before the object-loop call, with
explicit mode/scene/control-bit filtering. It is not a safe writable contract
yet: no reviewed broker callback occupies it; the allowed ranges, priority
against physics/packet writers, restoration rules, and replay/network behavior
still have no proof.

# 2026-08-18 — Steering-only candidate is narrower than a control-vector API

The planner-side steering scalar is `V+0x442C`. Raw
`sub_426100_00426100` moves it by no more than `0.1` per invocation and clamps
the resulting value to `[-1.0, +1.0]`. `AIMainUpdate_00424E70` copies it into
the final commit `V+0x3580 == P+0x3574`. In normal mode 1,
`PhysicsIntegrationStateMachine_004E4E60` calls `sub_4E51A0(P)` and then
`WheelForceCalculationSpringDamperTorque_004E5470(P)`; the former owns and
can replace `P+0x3570/P+0x3578`, whereas the latter consumes `P+0x3574` as its
steering input.

Consequently, the recovered post-AI/pre-physics candidate phase can only be
considered for a bounded **steering-only** override. A future implementation
would need to write `P+0x3574` (equivalently `V+0x3580`) in `[-1,1]`, on the
game thread, after the completed AI pass, and only for the verified active
mode-1 scene object. It must not advertise `V+0x357C/+0x3584` as parallel
external throttle/brake channels: mode-1 reclaims their aliases before their
next physical use.

This is an evidence-backed candidate specification, not an exposed or safe SDK
operation. It still lacks reviewed broker ownership, conflict/arbitration
policy, reset/replay/network validation, and controlled live tests.

# 2026-08-18 — Mode-1 steering lifetime closed through the integration tail

The normal mode-1 substep has now been traced through its final callee.  In
`PhysicsIntegrationStateMachine_004E4E60`, the order is exactly
`sub_4E51A0(P)` → `WheelForceCalculationSpringDamperTorque_004E5470(P)` →
`sub_4E5AE0(P)`.  `WheelForceCalculation...` reads `P+0x3574` to produce the
steering-angle sin/cos transform.  The following `sub_4E5AE0` creates its
four-wheel iterator at `P+0x3580` and its recovered scalar accesses begin at
other offsets; it contains no access to `P+0x3574`.

Thus no later write to the committed steering scalar occurs in the recovered
normal mode-1 integration tail after wheel-force consumption.  This closes the
*intra-substep* lifetime question for that one scalar.  It does not expand the
candidate into a general control vector: construction/reset (`sub_4E4790`),
mode-0 setup, and mode-2 packet paths remain independent writers across other
lifecycles, and no broker exposes the narrowly bounded mode-1 phase.

# 2026-08-18 — Alternate packed-state writer is outside the normal path

The mode-2 alternative has a separate verified call chain:
`PerVehicleCameraUpdateIterator_004109D0` selects its global mode-2 loop and
calls `sub_4F0430`; its case-3 raw bytes call `sub_4B9AC0` and then call
`VehiclePhysicsTimeStep_004C73F0` at `0x004F0BDB` for a `0x48C0`-stride
vehicle-physics entry.  `VehiclePhysicsTimeStep` conditionally writes
`P+0x3580` from the packed state and separately controls `P+0x3584`.

The origin and authority of that packed state are not named as replay or
network by this evidence, so neither label is asserted.  What is proved is
enough for contract scope: this is an alternate lifecycle, not a continuation
of the normal `AIMainUpdate -> mode-1 wheel-force` handoff.  A future
steering-only API must reject it rather than inherit the mode-1 candidate.

Raw `MainGameTickUpdate_0042C690` ordering further separates the paths:
the normal fixed-step AI and scene loop occur within the `0x0042C710` loop,
whereas `PerVehicleCameraUpdateIterator_004109D0` is called only at
`0x0042C9DE`, after that loop completes.  This is direct ordering evidence,
not an interpretation of the packed-state source.

# 2026-08-18 — The 432-byte `dword_8AAE64` queue is not the normal AI-control bridge

Raw `TireTemperatureSimStep_004C77D0` reserves one 432-byte slot from the
global cursor `dword_8AAE64` (bounded by `dword_83EE60 < 1023`) and passes it
to `SetupCarLightingAndRender_004C71C0`.  That encoder starts the slot with
`ProgressBarEventEncode(a2, 1, 0, 52, ...)`, then packs vehicle fields
including `+0x357C/+0x3580/+0x3584`.  This alone is only compatible format.

The queue has now been traced to its actual consumer.  In
`GamePostMainLoop_0042D8A0`, `MainGameTickUpdate_0042C690` and
`IterateVehicles_004B3BA0` run before `CollisionResponseStatus_00463CD0`.
That function calls `InputCommandDispatchToEntities_0045F4A0`, which copies
and advances the `dword_83EE60` queue and forwards each record through
`sub_465300` or `TextureCreationWrapper`; `GamePostMainLoop` then resets the
queue with `BufferReset(&dword_83EE60)`.  Raw `InputCommandDispatchToEntities`
has no call to `VehiclePhysicsTimeStep_004C73F0`,
`VehiclePhysicsModeDispatcher_004E4930`, or either normal integration path.
Unrelated raw writers (camera shake, audio, penalties, UI/progress, and
vehicle events) share the same cursor, confirming this is a generic event
dispatch queue rather than an AI-only control transport.

Separately, the only recovered `VehiclePhysicsTimeStep_004C73F0` caller is
case 3 of `sub_4F0430`: it allocates a local `v95[108]` (432 bytes), fills it
via `sub_4B9AC0(&dword_8AB6EC, vehicleIndex, v95, ...)`, and passes that local
record as `a2`.  It does not pass `dword_8AAE64`.  Raw
`VehiclePhysicsModeDispatcher_004E4930` also confirms that normal mode 0
calls `VehiclePhysicsIntegrationStep_00441650`, while normal mode 1 calls
`PhysicsIntegrationStateMachine_004E4E60`; neither calls
`VehiclePhysicsTimeStep`.

Therefore the earlier shared-format observation is now classified as
**compatible format only**, not forwarding evidence: no recovered producer
record from the `dword_8AAE64` queue reaches a normal mode-0/1 local physics
consumer.  The authoritative normal AI-control-output bridge remains the
direct committed-field path already recovered for mode 1, not this queue.

# 2026-08-18 — `CRASH` and `COMPLETEDLAPS%` feed collision outcomes

Raw profile initialization `sub_424080_00424080` loads `CRASH` into
`V+0x44D0` (`+17616`) and `COMPLETEDLAPS%` into `V+0x44DC` (`+17628`).
Their direct recovered consumer is `AICollision_004BEF60`, reached from
`EngineFailureCheck_004BEC55`.

For eligible session and wheel-state conditions, `AICollision` samples the
global RNG against `CRASH * 0.01 / this[+0x35C] * dt`; a successful sample
sets return result `1`.  If its independent `+0x341` gate is set and that
first result is not `1`, it samples against
`(1 - COMPLETEDLAPS% * 0.01) / this[+0x35C] * dt * this[+0x344]` and returns
`2` on success.  These are verified data-flow facts; the gameplay meanings
of return values `1` and `2` remain unlabelled.

`SCRIPT` is still copied into `V+0x44E0`, but no raw reader of that exact
buffer was recovered in the current corpus.  It remains unresolved rather
than being inferred from the field name.

`EngineFailureCheck_004BEC55` consumes the nonzero `AICollision` result.  It
emits a type-26 event, maps result `1` directly to code `6`, maps result `2`
to a further RNG-selected code in `0..9`, and passes that code to
`PitCrewStateMachine` with `a5+0x4034`.  The code values' gameplay names are
not recovered, so this establishes collision-path control flow only.

# 2026-08-18 — Public SDK surface does not expose a safe core-AI control contract

The supported front-door capability inventory was checked directly.  Its only
AI live-write capability is `control-ai-pace`, explicitly a specialist
operation for a named driver's pace input.  No public capability exposes
bounded steering, throttle, brake, gear, pit intent, AI-output ownership, or
per-command application/acknowledgement.  The canonical SDK query index also
returns no FACT-level `pace`, `call`, or `vehicle` function entry matching a
public AI-control API.

This is interface evidence, not a claim that no internal code exists.  In
combination with the recovered writer lifetimes and pre-AI broker timing, it
means the required safe writable core-AI SDK contract is still unproven and
must not be represented as available.

# 2026-08-18 — `PASSING` and cornering profile fields reach racing-line planning

`sub_424080_00424080` stores `PASSING` at `V+0x44CC` (`+17612`),
`CORNERINGADD` at `V+0x4500` (`+17664`), and `CORNERINGMULT` at
`V+0x4504` (`+17668`).  In `AIRacingLine_00425920`, each nonterminal
lookahead-node speed is reduced by a term containing
`waypoint[+0x3C] / currentSpeed * PASSING * candidateSpeed * 0.915`; the
result is written into the 20-entry speed profile at `V+0x43A4`.

In `sub_426430_00426430`, the cornering fields form
`speedMagnitude * CORNERINGMULT + CORNERINGADD`, capped at `75`.  The
resulting ratio chooses `V+0x4468`'s band `0..3` using thresholds 15, 30, and
65 (with a special branch for state 1); that band selects the waypoint used
for downstream steering geometry.  This is verified profile-to-planner data
flow, without assigning unsupported qualitative labels such as “more/less
aggressive”.

# 2026-08-18 — Ability profile inputs bound longitudinal response by session mode

After initialization transforms, `QUALIFYINGABILITY` is held at `V+0x44C0`
(`+17600`) and `RACEABILITY` at `V+0x44C4` (`+17604`).  Raw
`RandomVariationScaler_004BEA10` selects the latter when its session object's
`+0x360` equals 7, otherwise the former, before deriving a clamped random
multiplier.  `sub_4BE760` makes the same mode-dependent selection while
comparing eligible vehicles' recorded values.

In the normal planner, `AIRacingLine_00425920` uses `V+0x44C4 * 0.2` as the
maximum incremental rise of its longitudinal target `V+0x4434` when its
alternate branch is inactive.  This is a direct profile-to-longitudinal path.
`TRACKAGGRESSION` is retained at `V+0x44F8` (`this[4414]`) after its
initialization scaling and minimum clamp.  `AISteering_004270A0` directly
uses it in candidate clearance/state thresholds, including `4 - value`,
`2 - value`, and the floor `20 - 10*value`.  This proves profile-to-traffic
decision data flow; the direction of resulting real-world aggressiveness is
not inferred from those formulae alone.

# 2026-08-18 — Overtake ABI boundary remains explicit and bounded

Raw `AISteering_004270A0` iterates the five ranked proximity records and
invokes `Overtaking_0042AF70` for controller states `2/7` and `1/8`.
The recovered caller text supplies `(this, state)`, while the recovered callee
signature reads a further `a2` candidate pointer.  The omitted machine-level
argument placement is therefore still unresolved; no candidate selection is
promoted from the decompiler artefact.

The callee's output is exact: after its eligibility checks succeed, it stores
that `a2` pointer at `V+0x45FC`.  It writes `V+0x4420 = +3.0` when the passed
state is `2`, otherwise `-3.0`.  This is a transient traffic-control latch,
not race order or a completed-pass record.

Raw `AIMainUpdate_00424E70` orders the normal branch as proximity scan →
`AIRacingLine` → `AISteering` → steering controller →
`AISteeringCorrection` → gear/state logic → final output commit.  The
correction sees a non-null `V+0x45FC` and sets its longitudinal cap
`V+0x457C` to `AIDifficultyScalar()*0.75`; it then caps `V+0x4434` against
that value.  At the shared final-commit label, `AIMainUpdate` copies
`V+0x4434/+442C/+4438` to `P+0x3570/+3574/+3578` and clears `V+0x45FC`.
This proves the ordinary latch's in-tick lifetime and longitudinal effect.

# 2026-08-18 — Pit strategy owns its own pace and state transitions

`AIAbility_00429470`, called by `AIMainUpdate` on its four-second timer,
recomputes `V+0x453C` from multiple branches (including bounded `±0.01`
adjustments and a random branch).  External writes to that field therefore
are not durable.  In the same routine, pit-context branches call
`PitStopDecisionTireCompound`, `PostPitCleanup`, `ForcePitExit`, and the
final `RacePhasePitEntryTrigger`.

Its recovered pit path also invokes the named speed-setting helper and
`ParameterValueSetter(18)`, resets planning state, chooses AI state `4` or
`5` by session type, reacquires waypoints, and finally calls the pit-entry
trigger.  This confirms pit strategy is upstream coordination and owns its
own limiter/state transitions; it does not directly replace the final
`V+0x4434/+442C/+4438` commit vector.

# 2026-08-18 — Existing pace control is a profile-baseline write, not core output control

The public `control-ai-pace` specialist declares a risk-acknowledged
live-write operation.  Its own argument contract identifies the target as
`V+0x44F4`, the session pace baseline consumed by `AIAbility`, and describes
the resulting `V+0x453C` change as the game's own gradual response.  Raw
`AIAbility_00429470` corroborates that `+0x44F4` participates in its
internally owned pace calculations.

This is deliberately distinct from the committed control fields
`V+0x4434/+442C/+4438`: it gives a narrow profile-level pace adjustment, has
no post-AI insertion phase, and does not establish writable steering,
longitudinal, gear, pit, identity, or acknowledgement semantics for a core
AI SDK contract.

# 2026-08-18 — Race order is independent of traffic latches

`AITickUpdate_004BF4F0` excludes terminal states 2/3, advances a driver's
lap-related field at `+0x403C`, updates its timing-related fields, and calls
`AIDriverSorting_004BF390`.  In race session 7, the sort compares those lap
and time fields; in other sessions it compares its separate progress field.
It shifts position fields by calls to `ConditionalFieldSetter`.

Neither `AITickUpdate` nor `AIDriverSorting` reads `V+0x45FC` or the
overtake lateral request at `V+0x4420`.  Traffic interaction and race order
are consequently separate recovered mechanisms.

# 2026-08-18 — Gear request tail reaches the applied gear state

`PhysicsGearShiftLogicWithThresholds_00426330` requests a gear through
`RaceStartCountdownStateUpdate_004EF930`, which writes the requested gear to
`P+0x3A08` and arms the delay at `P+0x3A04`.  Normal mode-1 integration calls
`SuspensionSpringDampingRateReset_004E4F40`; while that delay is positive it
calls `BrakeCoolingPostTreatment_004E5080`.

That raw callee decrements the delay by the physics substep value.  When the
delay expires, it copies `P+0x3A08` into `P+0x39F0`.  On the following reset
pass, `P+0x39F0` is compared with its cached state at `P+0x39F4`, and the
result selects the applicable gear-ratio parameters.  This closes the
recovered AI gear-request → applied-gear-state path.  It does not make gear
a safe external SDK channel: it remains lifecycle-owned and shares the
normal physics state machine.

# 2026-08-18 — Rain ability reaches racing-line speed scoring

Initialization transforms `RAINABILITY` from `V+0x44C8` into a wet factor at
`V+0x4580`.  `AIPushLap_0042A180` recalculates that factor as
`max(0.5, 1 - wetness * V+0x44C8)`; `AIComputePassScore_0042A780` multiplies
its waypoint/racing-line score by it, and `AIRacingLine_00425920` uses that
score to construct the speed profile.  This is a verified weather-profile to
longitudinal-planning path.

`STARTSTALLS` is parsed to `V+0x44BC`, but the current raw corpus has no
reader beyond initialization.  Its downstream behavior remains unresolved
rather than inferred from the token name.

# 2026-08-18 — Current-gear field is not the recovered request destination

The sole indexed raw writer of `P+0x39FC` is
`SuspensionAndWheelPhysics_004E5F60`.  Its caller,
`LargeConfigFunctionWithPhysicsConstants_004E45B0`, first resets the physics
object, parses vehicle configuration files, and then invokes that writer;
the path is setup, called from `SceneRenderUpdate_004C6D90`, rather than the
normal mode-1 substep.  No recovered normal-tick edge transfers the proven
applied request state `P+0x39F0` into `P+0x39FC`.

Accordingly, the established gear chain ends precisely at the applied
ratio-selection state `P+0x39F0`; `P+0x39FC` is not labelled a runtime gear
commit without additional evidence.

# 2026-08-18 — Profile input lifecycle joins driver initialization

`SceneRenderUpdate_004C6D90` calls `AIDriverStructInit_00424790`.  In the
flagged initialization branch, that raw function first clears/reseeds AI
state, invokes `sub_424080_00424080` for the profile defaults and `.rcd`
parse, then allocates its command-state buffer and acquires an initial spatial
waypoint.  This establishes the lifecycle boundary for the parsed profile
inputs without inferring that every scene-render call reparses them: the parse
is conditional on the initializer's flag.

# 2026-08-18 — AI command messages coordinate state, not committed controls

`AICommandMessageQueueDispatcher_00424CD0` applies a small set of message
codes, keeps a deduplicated `(code, argument)` buffer, and invokes
`CommandQueueResponseHandler_00429EE0`.  The response handler changes AI and
session flags, calls `ParameterValueSetter`, and calls `AISpeedDeltaSetter`.
Neither raw function writes the final AI fields
`V+0x4434/+442C/+4438`, their physical aliases, or the normal mode-1
integration call path.  This command queue is therefore evidenced as state/
pace coordination, not an authoritative control-output channel.

The exact reachable fields are bounded: `AISpeedDeltaSetter_0042ACA0` sets
the boolean-like `V+0x4550` only for values 0/1, and
`ParameterValueSetter_0042ACD0` writes `V+0x4538` (with a special global
value for argument 18).  `sub_4A46F0_004A46F0`, also reached from this chain,
is only an indirect indexed-field flag setter.  No numeric steering or final
longitudinal vector field is reached by this recovered command chain.

# 2026-08-18 — Race-start branch is a separate direct output writer

The start-state branch in `AIMainUpdate_00424E70` bypasses ordinary waypoint
planning.  It derives launch values from its countdown/timing state, clamps
them, and immediately writes `V+0x357C`, `V+0x3580`, and `V+0x3584` before
returning.  Since `P = V+0xC`, those are the same physical control aliases
as `P+0x3570/+3574/+3578`.

The normal non-start branch instead runs proximity scan, racing-line,
steering, correction, and gear logic, then reaches its shared final commit.
Thus any future output contract must explicitly either exclude the race-start
branch or supply a separately proven precedence rule; it cannot treat the
ordinary planner commit as the only AI writer.

# 2026-08-18 — Waypoint gate and refresh conditions are recovered

Before ordinary planning, `AIMainUpdate_00424E70` requires successful return
from `sub_426430_00426430`.  That routine computes vehicle speed, obtains a
spatial nearest waypoint when none is held, and reacquires it when its planar
squared distance exceeds `3200.0`; failure to obtain a node is the explicit
zero return that stops the update.  On refresh it follows the waypoint links
to populate the current plus 19 successors, derives the speed band from
velocity thresholds, and calculates heading/line-intersection targets used
by the subsequent steering work.

This makes the waypoint chain a hard precondition to the normal planner, not
merely advisory racing-line data.

# 2026-08-18 — AI state 1 changes the normal committed vector

After the common planner stages, `AIMainUpdate_00424E70` dispatches AI state
1 to `sub_4258C0_004258C0`.  That raw helper writes `V+0x4438 = 1.0` and
`V+0x4434 = 0.0`, then may advance the AI state to 2 when its low-speed or
two threshold tests hold.  The caller subsequently reaches the normal shared
commit, so these values do reach the physical aliases.

No semantic labels are assigned to the two scalars from this write alone, but
the control-vector authority is verified.  `SteeringAngleController_00425670`
(the state 0/6 companion) was also checked and only adjusts recovery state,
gear/countdown state, and timer snapshots; it does not write the vector.

# 2026-08-18 — AI state 2 does not refresh the physical output

For AI state 2, `AIMainUpdate_00424E70` calls
`FieldZeroSetter_00425660` and returns before the shared commit.
`FieldZeroSetter` writes only `V+0x4510 = 0`; it touches neither planning
vector nor physical aliases.  Therefore this branch does not itself publish
a new AI control value.  The persistence/overwrite behavior of the already
resident physical fields then belongs to the normal physics lifecycle and is
not inferred here.

# 2026-08-18 — AI state 7 is another committed-vector override

The state-7 arm in `AIMainUpdate_00424E70` writes `V+0x4424 = 0`,
`V+0x4438 = 1`, and `V+0x4434 = 0`; it may reset its state to 0 below the
`0.2` speed threshold, and then reaches the same shared commit.  Thus state
7, like state 1, overrides two committed-vector components after the common
planner stages.  State 3 only updates its transition test and then proceeds
to the shared commit without an additional vector write.

# 2026-08-18 — A pending gear transition overwrites physical longitudinal output

Normal mode-1 integration calls `SuspensionSpringDampingRateReset_004E4F40`,
which calls `BrakeCoolingPostTreatment_004E5080` while the gear-delay field
`P+0x3A04` is positive.  That raw routine computes a value from drivetrain
state and writes/clamps it directly to `P+0x3570`, the physical longitudinal
alias.  When the delay expires it instead copies the requested gear to
`P+0x39F0`.

Consequently, even after AI has committed `V+0x4434` to the same physical
field, a pending gear transition can overwrite that longitudinal component in
the following normal physics integration.  The final-chain authority is
therefore phase- and gear-state-dependent, which rules out a simple direct
longitudinal SDK write contract.

The remaining indexed `P+0x3570` writer, `EffectParameterSetter_004F17A0`,
is called only by `VehiclePhysicsTimeStep_004C73F0`, the separately recovered
alternate lifecycle.  It is not promoted to a normal mode-1 overwrite.

# 2026-08-18 — Normal physics overwrites have recovered conditions

`sub_4E51A0_004E51A0`, called after the gear-delay helper in the normal
mode-1 sequence, does not unconditionally replace both residual output
fields.  It writes `P+0x3570 = 0` when `P+0x3978 <= 0`, and writes
`P+0x3578 = 1` when `P+0x3994 == 0`; outside those conditions those specific
assignments are absent.  The gear-delay helper's direct `P+0x3570` write is
therefore followed by this additional conditional physics rule.

The safe conclusion is conditional ownership/overwrite of the longitudinal
and third components—not that every normal substep unconditionally destroys
the AI values.  Steering remains distinct: no normal writer of `P+0x3574`
was recovered.

# 2026-08-18 — Longitudinal value reaches a later main-tick consumer

`MainGameTickUpdate_0042C690` also calls `sub_4EE2D0_004EE2D0`.  In that
function's mode-1 arm, `ThrottleBrakeOverride_004EE230` reads `P+0x3570`,
combines it with drivetrain state, and derives three downstream override
values.  This is a further normal main-tick consumer of the physical
longitudinal field after the integration-stage rules.  The recovered code
does not by itself justify API-level throttle/brake labels for those three
derived fields.

# 2026-08-18 — Scheduler separates AI publication from vehicle integration

Raw `MainGameTickUpdate_0042C690` advances a `0.0025` fixed-step counter.
For counter values where `counter % 10 != 0`, it dispatches
`VehiclePhysicsModeDispatcher_004E4930` for the eligible primary vehicle.
At `counter % 10 == 0`, it instead runs `AIMainUpdate` for every AI driver,
then the global loop, effect update, and `sub_4EE2D0` per driver; that branch
does not call `VehiclePhysicsModeDispatcher`.

The immediately following global loop is
`LoopWithConditionalSkipFunction_00410980`, which iterates scene objects and
calls `SceneObjectLoaderStateMachine_0040F1C0`.  Its state-6 arm tests the
object vehicle eligibility flag and calls `VehiclePhysicsModeDispatcher_004E4930`
with the embedded physics object at scene-object `+0x20`.  Therefore an AI
driver's ordinary vector is committed before this same 25-ms branch's scene
object integration pass.  The earlier direct dispatcher call is a separate
primary-vehicle path, not the only integration route.

# 2026-08-18 — Physics mode is a lifecycle transition, not an AI invariant

`VehiclePhysicsModeDispatcher_004E4930` selects its normal mode-1 path only
when `P+0x32BC == 1`: it calls `PitStateUpdateMachine(P+0x32C0, dt)` and then
`PhysicsIntegrationStateMachine`.  Mode 0 calls the alternate
`VehiclePhysicsIntegrationStep` path, while mode 2 uses a separate handler.

The indexed writer `SessionStateTransition_004EF5A0` changes `P+0x32BC` and,
on a transition into mode 1, clears AI waypoint state and calls
`AISpeedDeltaSetter` on the outer vehicle.  Thus mode selection is
lifecycle-owned and dynamic.  Static evidence proves the mode-1 output path
when selected; it does not justify treating mode 1 as an unconditional
property of every AI vehicle.

# 2026-08-18 — Canonical SDK has no declared commit-field contract

The canonical front-door queries `sdk-query field 4434`, `sdk-query field
442c`, and `sdk-query field 4438` each return no matching SDK entry.  Combined
with the public capability manifest (whose only AI live-write is the narrow,
risk-acknowledged pace operation), this is direct evidence that the recovered
planner commit fields lack a supported writable SDK contract.  This proves
absence in the current canonical SDK catalogue, not safety of an undeclared
memory write.

`PhysicsTireSystemConstructor_004E4500`, called by `RaceStructInit_00423E80`,
initializes `P+0x32BC` to `-1` and invokes the physics reset.  Active mode is
therefore selected after construction by lifecycle code; constructor state is
not evidence for a running vehicle's integration path.

`RaceStructInit_00423E80` calls `PhysicsTireSystemConstructor(this + 3)`
before resetting the outer driver-AI fields.  With 32-bit elements, this is
direct initialization evidence for `P = V+0xC`, the alias relation used by
the control-output map.

# 2026-08-18 — Pit decision transition has exact planner-state effects

When its pit branch qualifies, `AIAbility_00429470` invokes
`PitStopDecisionTireCompound`, then performs `PostPitCleanup`, sets its
parameter/pace coordination fields, clears AI planning state, and assigns
`V+0x4510` to 4 for session 7 or 5 otherwise.  It sets the waypoint-refresh
flag, calls `sub_426430_00426430` to reacquire planning data, and finally
calls `RacePhasePitEntryTrigger`.

This establishes pit strategy as an upstream owner of AI mode and planning
transition.  It does not write the final committed vector directly; the
ordinary `AIMainUpdate` state dispatch governs later output publication.

# 2026-08-18 — Race-order routine has a separate unresolved schedule

`AITickUpdate_004BF4F0` iterates drivers excluding states 2/3, advances its
lap/time-related fields, and calls `AIDriverSorting_004BF390`; the sorter uses
lap/time in session 7 and separate progress otherwise to shift position
fields via `ConditionalFieldSetter`.  Neither reads the traffic latch.

Canonical evidence resolves `EngineFailureCheck_004BEC55` as the direct
`AITickUpdate` caller.  It invokes that tick conditionally after its
per-driver incident/lap loop.  The higher-level cadence of
`EngineFailureCheck` itself remains unresolved, so race-order work is still
not equated with the 25-ms `AIMainUpdate` scheduler.

# 2026-08-18 — Late longitudinal shaping occurs after traffic and racing line

`AISteeringCorrection_00426CF0`, called after `AISteering`, directly scales,
sets, and caps `V+0x4434`; a non-null traffic latch sets its cap field
`V+0x457C` to `AIDifficultyScalar()*0.75`.  It conditionally invokes
`AISteeringRacingLineCorrection_0042B0E0` only when session state is below 5
and the session type is 7.  That callee is an additional context-dependent
writer of `V+0x4434` and can adjust AI/pit state in its special branches.

The later correction then applies its own speed/thermal/start-related
longitudinal rules before the gear logic and shared commit.  Thus a final
control contract would need to supersede this entire late-shaping region, not
only `AIRacingLine`'s earlier longitudinal output.

# 2026-08-18 — Steering reset writer is not an active planner override

`CameraViewportFrustumInitialization_00424B20` is an externally called AI
state reset/reacquire routine.  It clears `V+0x442C`, resets planning/timer
state, dispatches its initialization command, and calls `sub_426430` to
obtain waypoint data.  Its write accounts for the remaining indexed steering
writer but occurs as a reset boundary, not in the ordinary per-tick planner.

# 2026-08-18 — Racing line owns two output components; steering is separate

`AIRacingLine_00425920` derives the waypoint speed profile and directly
writes `V+0x4434` and `V+0x4438` in its normal, low-speed, and special
transition branches.  It does not write `V+0x442C`.  That planner steering
component is handled by `sub_426100_00426100` after `AISteering`.

The commit vector is therefore not the result of one monolithic planner:
waypoint/racing-line work supplies two components, traffic/steering work
supplies the steering side, and late correction/state branches can replace
the former values before publication.

# 2026-08-18 — Steering controller geometry and bounds are exact

`sub_426100_00426100` selects the current waypoint-band target, transforms
its geometry against vehicle heading, computes a signed normalized steering
target, and writes `V+0x442C`.  Each AI update changes that value by at most
`0.1`, followed by a hard clamp to `[-1, 1]`; state 6 reverses the computed
sign before the limiter.  This is the direct planner source of the value later
committed to `P+0x3574` and consumed by wheel-force steering.

# 2026-08-18 — Scheduler driver array is rebuilt from active outer vehicles

`AIDriverCountSetup_004BFD90` performs opponent selection, calls
`BuildActiveVehiclePointerArray_0042BC80`, and applies session transitions.
The builder populates `dword_7C54F0[]` from outer vehicle records whose
`V+0x32C8` is not `-1`; it then resolves indices for the designated primary
and selected vehicles.  This supplies the AI-driver array iterated by
`MainGameTickUpdate_0042C690`, rather than that scheduler discovering driver
objects independently.

# 2026-08-18 — Racing-line profile score formula is recovered

`AIComputePassScore_0042A780`, called by `AIRacingLine`, returns the product
of `(waypoint_term * V+0x4504 + V+0x4500)`, wet factor `V+0x4580`, internal
pace `V+0x453C`, and a waypoint-local factor.  This directly joins
`CORNERINGMULT`, `CORNERINGADD`, rain-derived state, and AIAbility-owned pace
to the racing-line speed profile.

The indexed static readers differ between the ability twins:
`RACEABILITY` (`V+0x44C4`) is read by `AIRacingLine`, whereas
`QUALIFYINGABILITY` (`V+0x44C0`) has no downstream indexed reader beyond its
parser normalization.  Its effective runtime consumer remains unresolved in
this corpus rather than being inferred from its token name.

# 2026-08-18 — Crash-profile gates lead to incident handling, not vector output

`AICollision_004BEF60` performs the recovered CRASH and COMPLETEDLAPS%-based
random gates only in race session 7, after its vehicle-state checks.
`EngineFailureCheck_004BEC55` invokes it; outcome 1 becomes event code 6,
while outcome 2 selects a further randomized code, and both reach
`PitCrewStateMachine`.  These profile effects belong to incident handling and
race state, not to the ordinary AI control-vector commit.

# 2026-08-18 — Proximity scan itself can set the traffic latch

`OpponentProximityScanTeamRecognition_0042A7D0` resets and ranks up to five
eligible active vehicles by planar distance before `AISteering` processes
them.  Independently of `Overtaking_0042AF70`, a session-7 proximity branch
with its own state and lap checks writes the selected vehicle to `V+0x45FC`
and writes a signed lateral request to `V+0x4420`.

Therefore `V+0x45FC` is a shared traffic latch with at least two recovered
writers.  Its later correction/cap effect and final clear still apply, but
its source cannot be attributed solely to the overtaking helper.

`AIDriverRandomSelector_0042AE20`, called from `sub_4C6E80`, supplies another
lifetime boundary: when passed the latched candidate it clears `V+0x45FC`,
reinitializes its associated lateral state, and writes `V+0x4420 = 0`.
Traffic-latch lifetime is consequently bounded both by ordinary final commit
and by this candidate-specific external cleanup path.

# 2026-08-18 — AI gear decision and request are bounded

`PhysicsGearShiftLogicWithThresholds_00426330` evaluates its current gear,
AI recovery/state, and speed/wheel thresholds, then requests downshift,
neutral/reset, or upshift through `RaceStartCountdownStateUpdate_004EF930`.
That raw helper writes the requested gear to `P+0x3A08` and arms its delay at
`P+0x3A04`; a zero request clears its relevant gear-state fields.  The later
normal-substep delay expiry and applied-state transfer remain the authoritative
application phase.

# 2026-08-18 — Rain ability also reaches tyre/pit decisions

`AIPushLap_0042A180` recalculates wet factor `V+0x4580` as
`max(0.5, 1 - wetness * V+0x44C8)`.  Beyond its racing-line score use, its
tyre-compound/weather branches can call `ForcePitExit`.  Rain ability therefore
affects both speed-profile scoring and an upstream tyre/pit decision path;
neither effect is a direct final-vector write.

`PitStopDecisionTireCompound_0042A3D0` selects stint/tire state from session,
lap/stint counters, blocking conditions, and wetness; its blocking branch
performs cleanup and its remaining branches update tyre-selection state.  This
is pit-strategy coordination upstream of AI planning, not a supported writable
control-output API.  Canonical `doctor --json` validates the present SDK
generally, while the commit-field queries still establish no core AI contract.

# 2026-08-18 — Player-device control is a separate pipeline

`DriverInputController_00451720`, called once by `MainGameTickUpdate`, operates
through `dword_7C54E0` and its device/controller objects.  It is distinct from
the `dword_7C54F0[]` AI-driver loop and does not create an alternate AI
control-output path.  AI publication remains the planner commit followed by
the scene-object physics dispatch.

Canonical field queries for physical `0x3570`, `0x3574`, and `0x3578` also
return no SDK entries.  Neither the planner vector nor its physical aliases
currently has a supported writable SDK contract.

The canonical SDK does confirm `AIMainUpdate(F1CVehicle*)` as a game-thread
`thiscall` ABI, with active-array entry passed in `ecx`.  That establishes a
call signature, not a safe SDK control surface: no corresponding public
vector-control operation or mode-dispatcher contract is declared.

# 2026-08-18 — Live pace has an exact baseline-reset path

`LateralForceTorqueCalculation_0042AD00` writes
`V+0x453C = argument * V+0x44F4 * 0.01`.  Both profile initialization and the
candidate-specific traffic cleanup call it with argument 100, restoring the
live pace factor to its profile baseline.  This reinforces that the supported
pace input is upstream and lifecycle-owned, not a durable core-vector control.

# 2026-08-18 — Third committed component reaches wheel-side coefficients

`sub_4E51A0_004E51A0`, in each normal physics substep, uses `P+0x3578` as a
multiplier while forming coefficient values for the four wheel-side regions.
When its separate drivetrain condition holds it first forces that field to
`1.0`; otherwise the AI-committed value participates directly.  This is the
recovered third-component route into normal wheel dynamics, with its own
conditional physics ownership.

# 2026-08-18 — Committed steering reaches all wheel-force calculations

Within `WheelForceCalculationSpringDamperTorque_004E5470`, normal physics
multiplies `P+0x3574` by its vehicle steering scale, stores the resulting
angle, derives sine/cosine transforms, and runs the wheel contact/force and
spring/damper routines for all four wheels.  This is direct raw evidence from
the committed AI steering field into normal vehicle force simulation.

# 2026-08-18 — Committed longitudinal state reaches rotational dynamics

Later in the same normal physics substep,
`sub_4E5AE0_004E5AE0` reads `P+0x3570` in its drivetrain-conditioned branch
and combines it with wheel/dynamic state before updating rotational and body
integration values.  This closes the static longitudinal route from the
committed physical alias into normal vehicle simulation, subject to the
previously documented conditional overwrite rules.

# 2026-08-18 — Steering has no recovered normal integration overwrite

The indexed raw writers of physical `P+0x3574` are only
`sub_4E4790_004E4790` (reset) and
`VehicleSetupInitialization_004E49B0` (setup).  Normal
`WheelForceCalculationSpringDamperTorque_004E5470` reads it; no normal
mode-1 writer is indexed.  This supports the narrower conclusion that the
AI-committed steering component survives normal integration until a lifecycle
reset/setup event, unlike the longitudinal component.  It remains unsafe as
an SDK write target because no supported insertion/ownership contract is
proved.

# 2026-08-18 — MaxSpeed is declared by the SDK but lacks a proved control hook

The canonical SDK labels `V+0x4538` (`MaxSpeed`) a factual `command_input` and
points at `ParameterValueSetter_0042ACD0`.  Raw code proves that setter writes
only `V+0x4538`; its `AIAbility_00429470` caller reaches it during a pit
transition cleanup branch, while its other callers are command-dispatch paths.
This does not prove an ordinary per-tick, precedence-safe external control
insertion point.  `MaxSpeed` is therefore useful SDK metadata but is not yet a
safe writable AI-control contract and is not a replacement for
`V+0x4434/0x442C/0x4438` or their physical aliases.

# 2026-08-18 — All recovered MaxSpeed setter calls are event-driven

`AICommandMessageQueueDispatcher_00424CD0` invokes
`ParameterValueSetter_0042ACD0(18)` only for command `15`.
`CommandQueueResponseHandler_00429EE0` invokes it for queued commands `0`,
`4`, and `5` (the last with `99999`); `AIAbility_00429470` invokes it in the
documented pit-transition branch.  These are discrete state/command events,
not the ordinary `AIMainUpdate_00424E70` control cadence.  No recovered caller
therefore establishes a normal-tick external MaxSpeed write path.

# 2026-08-18 — Core output fields have no canonical SDK contract

The canonical catalogue confirms `AIMainUpdate_00424E70` as an ABI entry, but
has no entries for logical outputs `V+0x4434`, `V+0x442C`, or `V+0x4438`, nor
for committed physical aliases `P+0x3570`, `P+0x3574`, or `P+0x3578`.
Consequently the recovered static path is evidence for behavior and timing,
not authorization for an SDK write.  A safe writable core-AI contract still
requires an explicit supported API plus a precedence-safe insertion rule.

# 2026-08-18 — Traffic candidate transfer remains an ABI ambiguity

Raw `Overtaking_0042AF70` has the recovered prototype
`(this, candidate, state)`: on success it stores the candidate in `V+0x45FC`
and writes lateral request `V+0x4420` to `+3.0` or `-3.0`.  The raw
`AISteering_004270A0` call display is only `Overtaking(this, v86)` even though
the callee reads both candidate and state.  This is a decompiler/prototype
mismatch, so the exact call-site candidate transfer is unresolved.  The
traffic latch outputs and their later steering effect remain verified; this
specific ABI edge is not used as an SDK contract.

# 2026-08-18 — Existing pace interface is documented, not safety-proved

Public SDK metadata exposes `control-ai-pace` as a live-write specialist for a
named driver's pace input.  Its factual `MaxSpeed` metadata identifies
`V+0x4538`, points to the game's `ParameterValueSetter_0042ACD0`, and declares
race-phase and `PitStatus` guards.  This documents an intended bounded pace
interface.  It does not, without an inspected implementation and independent
runtime validation, prove a safe writable SDK contract—even for pace—and it
does not expose or authorize the recovered core
steering/longitudinal/third-control vector.

# 2026-08-18 — Race-order update has an exact local gate, not a proved cadence

`EngineFailureCheck_004BEC55` iterates driver state, performs its incident/lap
work, and then invokes `AITickUpdate_004BF4F0` unless both of its local flags
are set.  That tick in turn owns the recovered ordering update path.  The
indexed corpus has no caller for `EngineFailureCheck_004BEC55`; therefore its
outer scheduler and frequency remain unknown.  This is an explicit boundary,
not evidence that race ordering shares the 0.0025-second AI control cadence.

# 2026-08-18 — Canonical SDK gate is valid, but intentionally incomplete

The read-only canonical SDK doctor and smoke gate passed against the verified
target: 101 vehicle fields and 22 reviewed ABIs are currently published, with
60 declared gaps.  The six recovered core-output fields are absent from that
published set.  This validates the existing pace capability's published SDK
surface; it does not prove its safe runtime behavior or convert absent
core-vector fields into supported writes.

# 2026-08-18 — Exact AI initialization order is recovered

`AIDriverStructInit_00424790`, called by `SceneRenderUpdate_004C6D90`, first
resets AI traffic/output state and default pace/control values.  When its
initialization flag is set it then: clears per-candidate slots; calls profile
parser `sub_424080`; rebuilds the ten-entry command queue; finds the
same-name active-vehicle target; acquires the initial spatial waypoint; and
performs its follow-up AI setup call.  This is the verified lifecycle point
for profile inputs and initial planner state, rather than an inference from
the parser alone.

# 2026-08-18 — Profile parser normalizes inputs before controllers see them

`sub_424080` establishes defaults, optionally reads `StartDry`, `StartWet`,
`StartStalls`, `QualifyingAbility`, `TrackAggression`, `RainAbility`,
`RaceAbility`, `Passing`, `CorneringAdd`, `CorneringMult`, `Crash`,
`CompletedLaps`, and `Script`, then transforms several values in place.
Notably, `TrackAggression` is globally scaled and floored; `RainAbility` is
scaled by session wetness; `RaceAbility` is converted to the internal pace
terms before `LateralForceTorqueCalculation(..., 100)` establishes the pace
baseline; and `Passing` becomes a capped multiplier.  Start-stall selection
is handled only in the race-start conditional branch.  Downstream controller
claims must refer to these normalized internal fields, not raw profile values.

# 2026-08-18 — Normal AIMainUpdate ordering and exceptional states are exact

After its waypoint eligibility gate, `AIMainUpdate_00424E70` executes the
normal path in this order: `OpponentProximityScanTeamRecognition`,
`AIRacingLine`, conditional `AISteering`, `sub_426100`,
`AISteeringCorrection`, `PhysicsGearShiftLogicWithThresholds`, state-specific
logic, then the common commit to physical `P+0x3570/0x3574/0x3578`.  State
`2` clears its field and returns before that common commit; states `4` and `5`
take the pit-transition path instead.  Its race-start branch writes the
physical controls directly and returns, so it is outside the ordinary planner
and must remain explicitly excluded from any future control insertion rule.

# 2026-08-18 — Scheduler timing and AI/physics phase order are exact

`MainGameTickUpdate_0042C690` advances fixed 0.0025-second substeps.  On
substeps where `tick % 10 == 0`, it iterates the active AI vehicle array and
calls `AIMainUpdate_00424E70` for each, then immediately calls the scene
iterator `LoopWithConditionalSkipFunction` with that same substep time.
Other substeps dispatch the player vehicle through
`VehiclePhysicsModeDispatcher_004E4930`.  Thus the normal AI output commit
precedes same-branch scene/vehicle simulation; it is not a delayed input for
the next AI update.

# 2026-08-18 — Authoritative output-to-simulation chain is continuous

On the AI scheduler branch, the shared `AIMainUpdate_00424E70` commit reaches
the scene iterator immediately.  `LoopWithConditionalSkipFunction_00410980`
calls `SceneObjectLoaderStateMachine_0040F1C0` for every scene object; its
state `6` passes embedded physics at object `+0x20` to
`VehiclePhysicsModeDispatcher_004E4930`.  In mode `1` the dispatcher performs
pit-state update then enters `PhysicsIntegrationStateMachine_004E4E60`.
Each positive normal substep executes, in order:
`SuspensionSpringDampingRateReset`, `sub_4E58D0`, `sub_4E51A0`,
`WheelForceCalculationSpringDamperTorque`, and `sub_4E5AE0`.  This is the
verified normal vehicle-simulation consumer path for the committed controls;
alternate dispatcher modes must not be conflated with it.

# 2026-08-18 — Racing-line longitudinal ownership is exact

`AIRacingLine_00425920` reacquires the relevant line node, calculates a
bounded look-ahead profile across up to 20 successor nodes, and writes the
logical longitudinal component `V+0x4434` plus third component `V+0x4438`.
Its no-profile/braking branch sets longitudinal control to zero and derives a
bounded third-component value; its drive branch sets the third component from
grip and clears longitudinal braking.  It does not write steering
`V+0x442C`.  Later `AISteeringCorrection` remains a separate, later
longitudinal owner, so racing-line output alone is not the final authority.

# 2026-08-18 — Steering command synthesis is exact and rate-limited

`sub_426100` chooses the indexed waypoint-band target, forms its signed
normalized directional error relative to the vehicle heading, divides by the
steering scale, and reverses sign in AI state `6`.  It then changes logical
steering `V+0x442C` by at most `0.1` per AI update and clamps it to `[-1, 1]`.
This is the ordinary logical steering writer immediately before later
correction and the shared physical commit.

# 2026-08-18 — Late longitudinal ownership and traffic cap are exact

After `AIRacingLine`, `AISteeringCorrection_00426CF0` attenuates logical
longitudinal output `V+0x4434` for steering, applies stability and thermal /
speed corrections, and may invoke the race-session racing-line correction.
If traffic latch `V+0x45FC` is non-null it sets cap `V+0x457C` to
`AIDifficultyScalar() * 0.75`; the final branch limits `V+0x4434` to that cap.
It also applies the bounded `MaxSpeed`/`V+0x4538` clamp.  Therefore this late
function, not `AIRacingLine` alone, is the final normal-path longitudinal
authority before the shared commit.

# 2026-08-18 — AI gear command is a delayed request state, not direct gear

`PhysicsGearShiftLogicWithThresholds_00426330` uses AI state, current gear,
wheel/engine thresholds, and its recovery conditions to call
`RaceStartCountdownStateUpdate_004EF930`.  That callee stores the requested
gear in `P+0x3A08` and initializes delay state `P+0x3A04`; a zero request
clears request, delay, and the related current-gear state.  It does not write
the active gear directly.  Any SDK gear control would therefore need the
subsequent physical delay/transfer path and cannot safely treat `P+0x39F0` as
an AI output field.

# 2026-08-18 — Gear delay transfer is in normal physics

At the start of each normal physics substep,
`SuspensionSpringDampingRateReset_004E4F40` calls
`BrakeCoolingPostTreatment_004E5080`.  It decrements `P+0x3A04` by the physics
step; while positive it derives a bounded drivetrain control value, and on
expiry copies requested gear `P+0x3A08` to active gear `P+0x39F0`.
`sub_4E51A0` then uses active gear and drivetrain state in the same normal
substep, conditionally zeroing `P+0x3570` and forcing `P+0x3578` to `1.0`.
This proves the request-to-gear transfer but also proves that gear and control
ownership remains inside physical state management.

# 2026-08-18 — Traffic latch has two verified writers

`OpponentProximityScanTeamRecognition_0042A7D0` ranks up to five active
nearby vehicles.  In its session-7, close-ahead, later-lap branch it stores
the selected vehicle in `V+0x45FC` and writes lateral request `V+0x4420` to
`-2.5` or `+2.5` according to the signed direction test.  Separately,
`Overtaking_0042AF70` writes the same latch and uses `-3.0` or `+3.0` on its
success path.  Traffic behavior therefore has dual writer ownership; neither
writer is a safe external SDK target.

# 2026-08-18 — Physical mode transition resets AI waypoint state

`SessionStateTransition_004EF5A0` replaces the physics-mode value at
`P+0x32BC`.  On the transition from a value other than `1` to mode `1`, it
calls `SessionCleanupFlagClear`, invokes `AISpeedDeltaSetter`, and clears two
outer AI waypoint references.  A future control contract must therefore
reacquire planner state across this lifecycle edge; persistent control data
cannot assume a continuous waypoint binding through mode transitions.

# 2026-08-18 — Blue-flag/yield failure diagnosis

The automatic race yield branch in
`OpponentProximityScanTeamRecognition_0042A7D0` is much narrower than a
general “faster car behind” rule.  It runs only when the candidate:

- has `V+0x4894` equal to the vehicle at the global current-player index
  (`sub_4C7BD0` / `IsDriverPlayer`);
- is within planar squared distance `< 625` (roughly a 25-unit radius);
- is in race session `7`, is active, and has a strictly greater lap count.

Therefore an AI car lapping another AI car does not enter this automatic
yield branch unless it happens to share the current player's identity key.
Further, a non-null `FindNearestVehicle_004A4710` causes the function to skip
the full active-array scan containing that branch.  When the branch does run,
it requests only a lateral offset (`+/-2.5`); later correction applies a
longitudinal cap, not a hard braking/yield command.  These gates explain
intermittent failures to let faster cars through and time loss behind a slower
AI car.
