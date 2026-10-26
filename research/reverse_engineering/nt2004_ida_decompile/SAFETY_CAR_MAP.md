# NT2004 Safety Car / Caution System — Complete Map

Binary: `NASCAR_Thunder_2004.exe`, image base 0x400000, non-ASLR.
Tier: all addresses/offsets/globals = **extraction** (from `functions/*.c` ground-truth text,
produced by Hex-Rays on the full IDB). Semantic interpretation = **DERIVED** (verify before
building a mod on it). Nothing here is GUESS.

Target consumer: F1 Challenge 99-02 corpus (`f1c_ida_decompiled`). Same engine lineage
(33 shared MSVC `__FILE__` paths, same `skeleton_extract.py` schema, 51% crossmatch).
**F1C has NO caution/pace-car system** (verified: zero "yellow/pace/caution" strings in F1C's
`strings_index.json`); NT2004's is a complete, self-contained implementation. This doc maps it.

---

## 1. Architecture at a glance

The system is five cooperating layers, all driven from the same per-frame session tick:

```
  [1] STEWARD (flags)        sub_4F99C0 / sub_4F9670 / sub_4F93E0 / sub_4F9920
        │ throws flag states 0..8 (green/yellow-phases/red)
        ▼
  [2] COMMAND QUEUE          sub_4D0D00 (enqueue) → sub_4D0D50 (dispatch)
        │ 208-byte ring @ dword_7D3C44; flags/pace commands ride as type-4 sub-cmds
        ▼
  [3] PACE-LAP STATE MACHINE sub_4FB270 (substates) + sub_42F950 (phase setter)
        │ dword_75CBB0==7 ⇒ session in pace-lap; dword_75CBB4 = substate 0..8
        ▼
  [4] PER-CAR CONTROL        sub_4F8D30 (flag-mode per car) · sub_4FA900 (field order)
        │                     sub_4DC260 (pace speed) · sub_4F87B0/4F9040 (order cmds)
        ▼
  [5] FIELD OBJECT           pace car = roster vehicle named "pace car", slot 48+
                             (sub_4E29B0, sub_42E180); per-track PaceCarReleaseDist
```

Player-facing extras on top: manual-pace control (`sub_4FB930`, `sub_4FA450`), yellow-flag
infraction enforcement (`sub_4DF490`), "stay behind the pace car" HUD (`sub_4DCEB0`),
weather-triggered yellow (`sub_52B1D0`), and per-session enable flags (`AllowAutoPace`,
driving-aid bit 11).

---

## 2. Key globals (extraction)

| Global | Meaning | Set by |
|---|---|---|
| `dword_75CBA8` | **pace-lap phase** 0..8 (1=init, 5=racing, 6=caution, 7=red…) | `unknown_libname_16_42F540` (init=1), `sub_4BA1A0` (=6), `sub_42F950` |
| `dword_75CBAC` | mode bitfield, **bit0 = manual pace lap** (player drives pace lap) | `sub_42FE80`, `sub_4302B0`, `_WinMain`, `sub_465370`, `sub_465E80`, `sub_47CA00` |
| `dword_75CBB0` | **race phase** 0..8 (**5=racing, 7=caution/pace-lap, 8=red**; 1-4=pre-race/warmup/qualify/practice) | read in 144 fns; only direct write at init (`=1`) |
| `dword_75CBB4` | **pace-lap substate** 0..8 (5=green/racing, 6=caution active, 7=red, 0-4=transition) | `sub_42F950` (writes `&dword_75CBA8` +12), init `=0` |
| `byte_75CBB8` | pace-lap processing enable gate | `sub_4FCB50` reads; `sub_4BA1A0` |
| `dword_7D3C44` | **command-queue write pointer** (208-byte ring) | every enqueuer via `sub_4D0D00` |
| `dword_79FC40` | queue entry count, guard `< 1023` | same |
| `dbl_7DA9D0` | **race clock**, seconds (double); every "delay/timer" is `>=`-compared against it | BSS, written at runtime |
| `dbl_7DA9C8` | **frame delta time** | BSS |
| `dword_764D68` | message bus (announcement bar) | `sub_45D100` / `sub_45D270` |
| `off_5FD348` / `unk_62BF68` | **vehicle roster array**, stride **25304**, slot 0 = leader/pace target | dynman |
| `dword_75AAD0` | array of active car pointers | dynman |
| `NumOfElements` | active car count | dynman |
| `dword_75AACC` | player session/car object | — |
| `dword_7D5DA4` | session mode (**2 = hot-seat**, disables pace processing) | — |
| `dword_766120/4/8` | pace-lap UI timer ("press space to skip", 20s timeout) | `sub_4FCB50` |
| `byte_766222`, `dword_766224`, `dword_766228`, `flt_76622C` | caution light/timing state | `sub_4F99C0`, `sub_4F9670` |
| `dword_630030`/`unk_6310CC`/`unk_632230` | per-car arrays, stride 25304 (state/order/pos) | — |
| `dword_6310F4` | per-car pace-order position | `sub_4FADA0` (cmd 0x2A) |
| `byte_7D7558` | order buffer | `sub_4D0D50` cmd 0x07 |
| `dword_7D78F0` / `dword_6119AC` | incident-scanner rotating window | `sub_4F93E0` |
| `dword_7D6A5C`/`dword_7D6A58` | **driver roster**, stride 1232, **name at +246** | roster loader |
| `dword_75AB90` | car pointer array (grid) | `sub_42E180` |
| `byte_60077C` | **AllowAutoPace** session-options byte | `sub_468B10`, dialog `sub_467380` |
| `dword_7668D0` | player's **auto-pace-lap driving-aid** value | player file |

Vehicle-struct offsets used by this system (relative to the 25304-byte roster entries that
`dword_75AAD0` points into):

| Off | Meaning |
|---|---|
| `+0x0000` | per-car **flag mode** (0=normal, 1=caution, 2=red, 3=green…) — `sub_4F8D30` |
| `+0x84` | waypoint position scalar (`sub_51C7A0`) |
| `+0x514C` (20812) | control/session flags |
| `+0x5150` (20816) | `sub_4DF490` penalty object base |
| `+0x5154` (20820) | pace-lap target speed (`sub_4DD120`) |
| `+0x5168` (20840) | order target index |
| `+0x516C` (20844) | car state (9 = green-pending per `sub_4DF490`) |
| `+0x5170` (20848) | lap count |
| `+0x5174` (20852) | pace-mode flag (2 = pacing; `sub_4FA450` sets it) |
| `+0x5178` (20856) | **computed pace-lap speed** (recomputed per frame by `sub_4FB270`/`sub_4FA900`/`sub_4FAEF0`) |
| `+0x519C` (20892) | car number |
| `+0x40C0` (16576) | active-flag / session state |
| `+0x40CC` (16588) | pit/garage pos pointer |
| `+0x40D8` (16600) | ? |
| `+0x4A00` (18944) | ? |
| `+0x5260` (21088) | ? |
| `+0x5280` (21120) | ? (reset by `sub_4FA450`) |
| `+0x62A0` (25248) | **slot/car number byte** (self-identifies a live slot) |
| `+0x62D4` (25300) | grid slot |

---

## 3. The command queue (layer 2)

The game's async command bus. **Same mechanism F1C has** (F1C's AI command queue, "cmd 0xe"
in the F1C corpus) — this is the correct integration point for an F1C port.

- **`sub_4D0D00(this, a2, a3, a4, a5, a6, a7)`** — enqueue at `dword_7D3C44`, advance by 208,
  cap 1023 (`dword_79FC40`). Word packs: `a5 + ((a4 + ((a3 + ((dword_75CBB0 + 16*(a7+4*a2))<<6))<<10))<<6)`.
  - top nibble of the word = **race phase** (`dword_75CBB0 & 0xF`)
  - `byte2 & 0x3F` = **sub-command** (`a3`)
  - payload floats/bytes go in `this[1]`, `this+8..`
- **`sub_4D0D50(this)`** — the per-frame **dispatcher**: `switch (word>>28)` then
  `switch (byte2&0x3F)`. The safety-car sub-commands (type 4):

| sub | poster | action |
|---|---|---|
| `0x07` | `sub_4FA900` | **apply pace-line order** — walk order bytes, `sub_4DEB20(pos)` per car, set car `+0xB0`/`+0xB4` prev/next links (doubly-linked pace line), leader target positions, `byte_7D7558` |
| `0x08` | `sub_4F9040`/`sub_4DD490` | per-car position/order update (`sub_4DD350` or `sub_4DD490`) |
| `0x09` | `sub_4F9200` | pace-gap alpha shading to car `+0x5160` |
| `0x0A/0x0B` | `sub_4FA7F0` | pace display refresh |
| `0x14` | `sub_4FB180` | pace-lap entry: per-car pace speed, substate 4 |
| `0x15` | `sub_4FAF30` | **begin pace lap** (`sub_4FAF90`) — resets timers, "Beginning Pace Lap" |
| `0x16` | `sub_4F9920` | **set flag state** → `sub_4F99C0` (only when substate ∈{5,6,7} ∧ auto-pace off) |
| `0x1C` | — | per-car pace-lap end |
| `0x21/0x22` | — | `byte_7D7528` = 1/0 (pit-open HUD) |
| `0x25` | — | `sub_4F8900` order display (auto-pace only) |
| `0x26` | `sub_4FAFF0` | **green-flag restart** — `sub_42F950(5)`, all cars `sub_4DC260(speed)`, "Withholding Green"+"Green Flag" (auto-pace only) |
| `0x28` | — | `byte_766222=1`, caution light on |
| `0x29` | `sub_4FADA0` | manual-pace reorder on a pass (manual only, `dword_75CBB0==6`) |
| `0x2A` | — | set `dword_6310F4` pace-order array (auto-pace only) |
| `0x2B` | — | teleport car to waypoint (`sub_4F7F20` if manual) |
| `0x2C/0x2D` | — | per-car pace positioning (`sub_4F81A0`/`sub_4F8240`, manual only) |
| `0x2E/0x2F` | — | engine-sound state |

Note the manual/auto gating: auto-pace mode runs the machine through commands; manual mode
(player drives the pace lap) bypasses those commands and runs `sub_4FB930`'s substate switch
instead.

---

## 4. The steward: flags (layer 1)

**Flag-state enum** (steward `this+0x118`, the `a2` of `sub_4F99C0`):

| val | meaning | string |
|---|---|---|
| 0 | green / resume | "Green Flag: Resume" |
| 1 | yellow detected, pits closed | "Yellow Flag: Detected (Car #%s), Pits Closed" |
| 2 | yellow, pits closed | "Yellow Flag: Pits Closed" |
| 3 | pits open, lead lap | "Yellow Flag: Pits Open To Lead Lap Vehicles" |
| 4/5 | pits open, all | "Yellow Flag: Pits Open To All Vehicles" |
| 6 | prepare to restart | "Yellow Flag: Prepare to Re-start" |
| 7 | green pending | "Green Flag: May Pass" / "Withholding Green" |
| 8 | red flag | "Red Flag: Detected" |

Functions:

- **`sub_4F99C0(steward, flag, carIdx)`** — apply a flag state. Broadcasts the announcement,
  sets `dword_75CBB4` via `sub_42F950(6)` (yellow) / `(5)` (green) / `(7)` (red), closes pits
  (`sub_427260` per car), on green clears per-car 0x5280 (`car+21116`=0) and resets the
  flag-timer struct (`sub_4F7ED0`), then `sub_4F9F50` pushes per-car flag modes.
- **`sub_4F9920(steward, flag, carIdx)`** — enqueue flag change (cmd 0x16), embed the offending
  car's number (from `car+25248`), then call `sub_4F99C0`. This is the *only* flag transition path.
- **`sub_4F9670(steward, trigger, carIdx)`** — the **caution decision machine** (per-frame):
  - state 0 (green): if trigger → `sub_4F7ED0` + `sub_4F9920(1, car)`, set caution-lap count 5.
  - state 1: `sub_4DEB10` validity check → **full vs quickie** via `sub_4F95D0`; display
    "Full Caution"/"Quickie Caution"; `this+0x11C` = 5 (full) or 4 (quickie); if rain override
    → 2; `sub_4F9920(2, -1)` → pits closed.
  - state 2: `sub_4FA660(0)` field-past-pits check → `sub_4F9920(3)` (full) or `(4)` (quickie);
    `sub_427540` reset per car.
  - state 3: `sub_4FA660(1)` → `sub_4F9920(4)` (pits open all).
  - state 4/5: when `dword_766228 >= this+0x11C - 1` (caution laps elapsed) → `sub_4F9920(6)`
    prepare restart (or `(8)` red if `sub_460A50` weather flag). **`sub_460A50()` is a stub
    returning 0** (2026-07-31, `functions/sub_460A50_00460a50.c`) — the rain→red trigger is
    **dead code as shipped**. Red-flag machinery (state 8 → substate 7, per-car mode 2, plus
    `sub_4FB270` substate-1 auto-red at leader gap > 900) exists but has no live automatic
    trigger — same dormant state as F1C's red-flag physics. F1C port note: NT2004's red flag
    is one gate away from working, not an unbuildable feature.
  - state 6: light off + fade + `sub_4FA1A0` field-bunched check → `sub_4F9920(7)`.
  - state 7: field clear → `sub_4F9920(0)` → green.
  - tail: if state ≥ 2 and player controlling → `sub_4FAE10` (light timer).
- **`sub_4F93E0(steward)`** — the **incident scanner**. Rotates a window over cars
  (`dword_7D78F0 mod dword_6119AC`), checks each for stopped (`speed<0.1`), off-pace, off-track,
  damaged; on hit calls `sub_4F9670(1, carIdx)` (first caution) or keeps stepping an active
  caution. Called from `sub_4F9040` (which runs under `sub_4FB930`).

  **The auto-trigger gates, in full (2026-07-31 trace):** `sub_4F9040` only invokes the scanner
  when ALL of: (1) `dword_75CBB0 == 7` (race phase = caution — it does NOT scan during green
  racing), (2) `dword_6310D8[car] < steward+0x90` (current car's value still inside the
  caution-lap window), (3) `dword_767310 == 2` (**rule-enforcement level = All**; the same
  `== 2` gate guards the public API `sub_4F9D50`, so below "All" the game never auto-throws).
  `dword_767310` has no direct writer in the decompile (read-only in all 7 referencing fns) —
  assigned through the options indirection; its threshold role is confirmed by `sub_4DD160`
  (`dword_767310 >= a2`).
  **Scan:** field split into `dword_6119AC` rotating segments, ONE segment per frame
  (round-robin). If steward flag state (`this+0x118`) is already nonzero → skip scan, just
  step `sub_4F9670(0,0)`. Else three trigger predicates per car:
  - **stopped**: `speed < 0.1` ∧ not in grace ∧ on-track (`sub_51C730`, |signed dist to line| ≤ 2.0) ∧ not pit-lane (`veh+0x4404`)
  - **damaged**: `veh+0x5118` (float damage accumulator) `> 0`
  - **off-pace/spun**: `speed > 0.1` ∧ `|sub_51C630| < 0.5` (velocity mostly perpendicular) ∧ `veh+0x4408 != 3` ∧ not pit-lane ∧ on-track
  **Grace** = 10 s after the caution timer base (`raceclock < this+0x94 + 10.0`) during which
  stopped cars do NOT trigger — the field settling for the pace line is not an incident.
  A trigger is **masked if every car** has byte `+0x5188` set. Throw path: `sub_4F9670` state 0
  → `sub_4F9920(1, car)` → `sub_4F99C0(1, car)` → "Yellow Flag: Detected (Car #%s), Pits Closed",
  pits closed, substate 6, per-car mode 1, caution-lap count 5.
  **OPEN (2026-07-31):** the scanner only runs at phase 7, so the *initial* 5→6→7 phase advance
  (who DECLARES a caution during green racing) is an upstream layer — `sub_4B99F0` (sequential
  advance), `sub_4B9B20` (phase sync from session object), `sub_4D6A80`, `sub_460F00` — driven by
  session state + netcode; not fully traced. As shipped the scanner's role reads as *attributing*
  the yellow to a car and *extending* cautions, with the rain path being the only green-phase
  trigger.
- **`sub_4F9D50(msg)`** — public "throw a caution" API: display `msg`, then
  `sub_4F9670(&unk_7D7428, 1, -1)`. Only path outside the scanner. Caller: **`sub_52B1D0`**
  (weather — throws yellow when rain intensity crosses 0.18). **Gated `dword_767310 == 2`.**
- **`sub_4F95D0(steward)`** — full-caution test: counts cars needing attention across 18 slots;
  `count >= this+0x120 + 3` ⇒ full; `this+0x163` (rain override) ⇒ quickie.
- **`sub_4F7ED0`** — reset the flag-timer struct (order arrays, counters).
- **`sub_4F84C0`/`sub_4F83E0`/`sub_4F8410`/`sub_4F8460`** — flag-timer / order-list helpers.

---

## 5. Pace-lap state machine (layer 3)

**Pace-lap substates** (`dword_75CBB4`; driven per-frame by `sub_4FB270`):

| substate | meaning |
|---|---|
| 0 | caution called — timer runs; on expiry `sub_42F950(1)`, cars → mode 1 |
| 1 | catching the field; if leader gap > 900 units → red; else on expiry advance |
| 2 | field being repositioned into the pace line (teleport + steer) |
| 3 | pits open phase; player free to pit; `sub_51F3D0(1,4)` camera, player car paced |
| 4 | **countdown to green** — 5-4-3-2-1 (`sub_4FA8E0` stages), then go |
| 5 | **restart** — cars released to race speed |
| 6 | caution active (set by `sub_4F99C0` on yellow) |
| 7 | red flag (set by `sub_4F99C0` on red) |
| 8 | late restart / end |

Functions:

- **`sub_4FB270(session)`** — the big per-frame driver (the "steward's pace control").
  Uses `session+0x94`/`0x98` (timers/speeds), `session+0xC4` (NaN sentinel 0x7F7FFFFF),
  `session+0xE0` (the session's own car object → `sub_4F8D30`), `session+0x100` (restart flag).
  Runs the 0-5 substate progression above; posts the "press space" timer and the go-countdown;
  every frame recomputes per-car `+0x5178` pace speed (`sub_51C7A0`) when auto-pace.
  Gated: only when `dword_75CBB0 > 0`; phases 1-6 use the racing branch, phase 7 the pace switch.
- **`sub_42F950(&dword_75CBA8, substate)`** — substate setter. When phase `dword_75CBA8==5`
  reacts: substate 0/2/4 → `sub_4EDFE0(0)` per car + order refresh; 3 → `sub_4DEB50(0)` per car
  + "Beginning Pace Lap"; 5 → reset order + restart the player's penalty tracker
  (`sub_4DF490(0,1)`).
- **`sub_4BA1A0(mode, speed)`** — **"skip pace lap / AI takes over"** API: sets phase 6,
  gates on `dword_629124`, posts "trackside", `sub_51BC20(1,0)`, `sub_4BA5B0`. Called from
  `sub_4FCB50` after the 20 s "Press SPACE to skip" timeout.
- **`sub_4BA660`** — auto-pace takeover driver (under `sub_4FA130` gate: manual mode + phase 7
  + substate 3 or 5-8 + not hot-seat + not paused).
- **`sub_4FA130`** — gate check for `sub_4BA660`.
- **`sub_4FA0D0`** — post cmd 9 "field ready" when `sub_4BA430()`.
- **`sub_4FA660(mode)`** — "has the field cleared the pits" (pits-open decision): leader
  waypoint inside the pit window, caution-lap count, AI race-time config (`aAiracetimemid`).
- **`sub_4FA1A0(session)`** — "field bunched for restart" + **"Withholding Green"** detection:
  leader speed vs 75% of `flt_6290D0`, waypoint geometry, posts "Withholding Green" when a
  car is out of line.
- **`sub_4FAE90`** — all cars past restart gate.
- **`sub_4FAE10`** — caution-light 1 s timer.
- **`sub_4F9200`** — pace-gap alpha (HUD shading) → cmd 0x09.
- **`sub_4FAEF0`** — set all cars to "go" (state ≤ 1 → `sub_4DD970(car+20836, 1.0)`).

---

## 6. Player pace-lap control (manual mode)

- **`sub_4FB930(session)`** — player's per-frame pace-lap control (runs when
  `(dword_75CBAC & 1) != 0`). Substate switch:
  - 0/1: pace target speed posting (`sub_4FAF30(2, ...)` / `(3, ...)`);
  - 2: force AI control of player car, `sub_4FA0D0`, `sub_41BDD0`;
  - 3: field-bunch wait → "Press SPACE To Skip Pace Lap" + "Beginning Pace Lap" (manual take
    over via `sub_4FA450`), or auto `sub_4FA1A0` → restart;
  - 4: NaN-guard → `sub_4FB0B0`;
  - 5-8: when field slows to a stop → return control to player (`sub_4FA900` + `sub_4F9040`).
  Calls `sub_4FA900` + `sub_4F9040` on the racing branch too (0-6).
- **`sub_4FA450(session)`** — the manual-pace takeover sequence: positions **every** car onto
  the grid from the waypoint table (`flt_628F60`, `sub_51BE20` teleport), sets car `+0x5174`=2,
  caution light off, "Prepare For Manual...", substate 5, `sub_4FAFF0` green release,
  `sub_51BC20(1,1)`, camera timing globals.
- **`sub_4FAF30`** — post cmd 0x15 begin-pace (mode, speed).
- **`sub_4FAFF0(session, speed, x)`** — **green-flag release**: `session+0x94 = speed`,
  `sub_4DC260(car+20836, speed, x)` for all cars, post cmd 0x26, "Green Flag",
  `sub_41BA10(0,-1)`. This single call is the "go racing" point.
- **`sub_4FB0B0`** — post cmd 0x14 hold timer (restart spacing, 1.5 s / 3.0 s).
- **`sub_4FAF90(session, ev)`** — begin-pace-lap init: reset `session+0xA1`, timers from
  `ev+12`, `sub_42F950(4)`, "Beginning Pace Lap" if `ev+8 == 3`.
- **`sub_4FB180(session, ev)`** — cmd 0x14 entry: per-car pace speed, substate 4.
- **`sub_4FADA0(car)`** — manual reorder: when `car` reaches the front, `dword_6310F4` slot
  updates and everyone behind shifts.

---

## 7. Per-car control (layer 4)

- **`sub_4F8D30(car, mode)`** — set `car[0] = mode` and `sub_5A2930(mode,0,0)`. Modes:
  0=normal, 1=caution/pace, 2=red, 3=green (dispatch from `sub_4F9F50`), 4/5 countdown stages.
- **`sub_4F9F50(steward)`** — push a flag-mode to every car in the session list
  (`this+0xEC` head, `this+0xF8` count): mode 3 on green, 1 on caution, 2 on red, 0 otherwise.
  Also posts the order command.
- **`sub_4FA900(steward)`** — the field-ordering engine. Computes per-car pace target position
  (`+0x5178`), tracks `this+0x128` timer (0.25 s), posts order-change cmds 33/34, qsorts the
  order: **pace order** (`sub_4F8B20`: state → lap → pace-pos) when `dword_75CBB0==7`,
  else **race order** (`sub_4F8A50`: state → race-pos → lap), writes the order list
  (`this+0x130` array), posts the pace-line order (cmd 0x07 with 3 float positions + car list).
- **`sub_4F9040(steward)`** — pace-order dispatch: posts cmd 10/11 (position list, 16/batch)
  and calls `sub_4F93E0` (the incident scanner).
- **`sub_4F87B0(steward)`** — posts combined order cmd 37 (pace list A `this+0x188` + race
  list B `this+0x04`, bitflags 0x40/0x80/0xC0 mark pit-in-progress cars).
- **`sub_4DC260(car+20836, speed, x)`** — set a car's pace/race target speed.
- **`sub_4DD120(car+20836, speed)`** — per-car substate speed.
- **`sub_4DD350`** — restart ordering: on green-pending + field bunched + substate 3 →
  `sub_4FAFF0` + `sub_42F950(5)`.
- **`sub_4DD490`** — per-car order update on a pass.
- **`sub_4F7F20` / `sub_4F81A0` / `sub_4F8240`** — per-car pace-lap track positioning /
  teleport (manual mode cmds 0x2B/0x2C/0x2D).
- **`sub_4F8A50` / `sub_4F8B20`** — qsort comparators: racing vs pace-line order.
- **`sub_4F7CF0` / `sub_4F7CC0` / `sub_4F7DC0`** — order-list get/reset/set (lists at
  `this+0x4` and `this+0x188`, 2 dwords per slot).

---

## 8. The pace car vehicle (layer 5)

- **`sub_4E29B0()`** — called from **`sub_42E180`** (dynman field setup) when the grid is full
  (48 cars) and not hot-seat. For each roster index:
  - `sub_51BC20(2 or 1, 0)` — garage/pit assignment (2 if `dword_75CBAC==2`),
  - index 0: scan the **driver roster** (`dword_7D6A5C`, stride 1232) for the entry whose
    **name at +246 == "pace car"** (`_strcmpi`), then `sub_4EEAE0(idx)` copies that roster
    entry into the vehicle struct; other indices: `sub_4E33C0(1)` random driver,
  - `sub_4EDDB0(i + 48)` — **slot 48+** (pace car is always slot 48, the line leader).
- **`sub_4EDDB0(car, slot)`** — set slot in 5 places: `car+25248`, `+0x44`, `+0x58`,
  `+0x40D0`, `+0x5180`.
- **`sub_4EEAE0(car, idx)`** — copy roster→vehicle: name/vehicle file/number/team at
  `+0x6104/+0x6144/+0x614C/+0x61C0`, index at `+0x62A4`.
- **`sub_4E33C0(n)`** — resolve the n-th "SeasonRaces" driver by name (roster walk).
- So the pace car is a **normal roster vehicle named "pace car"**, fielded at slot 48, and the
  whole caution machine treats it as car 0 / the pace line's target (it's the `off_5FD348`
  leader that `sub_4BBF20`/`sub_4BBF40`/`sub_4BBF10` read).

**Track config**: `PaceCarReleaseDist` in the `.aiw` (parsed by **`sub_402C00`**, line 274) →
two floats at track `+0`/`+4`, each must be in [0,1] (else reset to 0.80 / 0.87) — the
fraction of the track where the pace car releases.

---

## 9. Enforcement, display, penalties

- **`sub_4DF490(car+20836, dt, trigger)`** — the per-car yellow-flag infraction tracker
  (called per frame from the steward path and pace-lap reset). Enforces:
  - "Warning: Driving Too Slow Under Yellow" (accumulator `this+0x124` > 9.5 s → penalty via
    `sub_4DC690`),
  - "Illegally Passed..." / "Passed On Left During Caution" (passing the pace line),
  - "Lapped Field" lap deductions via **`sub_4DF420`** (`this[3] -= laps`, "%d Laps Also
    Deducted"),
  - "Warning: Accelerate / You Are..." (closing on the line too fast).
  Offsets used: `this+0x44` (`v4` last distance), `+0x48` (accumulators), `+0x4C`, `+0x48`
  flags; guard state 9 = green-pending.
- **`sub_4DCEB0`** — HUD: "Under Caution:" (substate > 3) / "Pace Lap:", "Stay Behind the
  Pace Car [On Inside Line]" vs "Stay Behind Car #%s".
- **`sub_4C19D0`** — pit lane: "Cannot serve stop/go under a yellow flag!" — pits closed
  during caution blocks pit-out actions.
- **`sub_4B1850`** — flag-icon asset loader (`Flag_Yellow.bmp` among the 18 flag bitmaps).

---

## 10. Config / driving aids

| config/UI token | destination | via |
|---|---|---|
| `AllowAutoPace` | `byte_60077C` (session options) | `sub_468B10` (read), `sub_469050` (write) |
| dialog checkbox 1015 | `byte_60077C` | `sub_467380` |
| session creation | driving-aid **bit 11** = auto pace lap (`sub_4CE720(11, byte_60077C)` → session `+0x3540` mask) | `sub_46B260` |
| "Auto Pace Lap" driving aid (default 0) | aid-list group at `+0x4DC` | `sub_4C6680` |
| `DRIVEAIDS_auto_pace_lap` | player file, from `dword_7668D0` | `sub_4FCC70` (results writer) |
| `PaceCarReleaseDist` | `.aiw` track floats +0/+4 | `sub_402C00` |

`dword_75CBAC & 1` (manual pace) is the runtime "does the player drive the pace lap" bit —
everything gated on it in the command table and `sub_4FCB50`.

---

## 11. Lifecycle walkthrough

```
green flag running
   │  dword_75CBB0=5, dword_75CBB4=5, steward flag=0
   ▼
incident (sub_4F93E0 scanner) ─ or ─ rain (sub_52B1D0 → sub_4F9D50)
   │  sub_4F9670(1, car) → full/quickie decision (sub_4F95D0)
   ▼
sub_4F9920(2,-1) → cmd 0x16 → sub_4F99C0(2,-1)
   │  "Yellow Flag: Pits Closed" · pits closed per car (sub_427260)
   │  dword_75CBB4=6 (sub_42F950(6)) · cars → mode 1 (sub_4F9F50→sub_4F8D30)
   ▼
field bunches → sub_4F9670(2) → sub_4FA660 → sub_4F9920(3/4)
   │  "Pits Open" · sub_427540 reset · pace line formed (sub_4FA900 cmd 0x07)
   │  sub_4FB270 drives substates 0→1→2→3 (catch field, reposition, pits open)
   ▼
caution laps elapsed (dword_766228 >= count-1) → sub_4F9670(4/5) → sub_4F9920(6)
   │  "Prepare to Re-start"
   ▼
sub_4F9670(6) → sub_4FA1A0 field-bunched → sub_4F9920(7) → "Withholding Green"/"May Pass"
   ▼
sub_4FB270 substate 4 → 5-4-3-2-1 countdown (sub_4FA8E0) → sub_4FAEF0 go
   ▼
sub_4F9670(7) → sub_4F9920(0) → sub_4F99C0(0)
   │  "Green Flag: Resume" · dword_75CBB4=5 · cars → mode 3
   │  sub_4FAFF0 → all cars race speed + cmd 0x26 restart
   ▼
green flag running again
```

Manual-mode variant: the player drives the pace lap behind the pace car; `sub_4FB930`
substates 0-3 show "Press SPACE To Skip Pace Lap"; the game takes over after 20 s
(`sub_4FCB50` timer → `sub_4BA1A0(1)`); `sub_4FA450` is the manual restart.

---

## 12. F1C comparison — what exists / what to port

F1C (verified against its corpus):
- **No** "yellow/pace/caution/safety" strings at all. F1C has *blue* flags and the
  `IgnoredBlueFlags` penalty; its "Flag Rules" race option governs those only.
- **No** steward caution machine. F1C's `steward.cpp` (`Steward_Init/Setup/Restart/Post_4d3xxx`)
  is race management, not flags.
- **Does** have the red-flag *physics* infrastructure (`DAT_008acfd4/c8/d8`, waypoint
  guidance → AI drives to an assembly point and stops) — never wired to a trigger
  (`mods/red-flag.md`). This is the only field-bunching primitive F1C has.
- **Does** have the AI **command queue** (F1C's "cmd 0xe", `dword_7D3C44`-analog) — the
  same bus NT2004 rides its flag/pace commands on.
- Prior art `mods/safety_car/` = fake safety car: retire Maylander (F1C's real SC driver),
  revive on demand, poke `veh+0x4538 maxSpeed` (m/s) to cap the field to 150 km/h. Known
  failure: `veh+0x453C/0x443C` are recalculated per frame (poke can't hold) — the note
  already says "correct path = hook the writers or the AI command queue (cmd 0xe)". This NT2004
  map is exactly that missing machinery.

**Port surface for F1C** (in dependency order):
1. Steward flag machine: `sub_4F9670`+`sub_4F99C0`+`sub_4F9920`+`sub_4F93E0`+`sub_4F95D0`,
   re-homed onto F1C's command queue (cmd 0xe).
2. Pace-lap substate driver: `sub_4FB270`+`sub_42F950`+`sub_4FA660`+`sub_4FA1A0`.
3. Per-car flag modes + field ordering: `sub_4F8D30`, `sub_4F9F50`, `sub_4FA900`,
   `sub_4F9040`, `sub_4F87B0`, comparators.
4. Pace car vehicle: needs a `"pace car"` roster entry + grid slot 48 (`sub_4E29B0`,
   `sub_42E180`-analog in F1C dynman) — F1C already *has* Maylander (Bernd Maylander = the
   real F1 safety car driver, confirmed in the safety_car mod), so the roster entry is half done.
5. Track config: `PaceCarReleaseDist` in `.aiw` (F1C's `.aiw` parser is `sub_402690`,
   verified via `tools/ask.py token` + config_schema — the earlier `sub_424080` note was
   wrong; `sub_424080` is F1C's AI-driver struct init).
6. Option plumbing: `AllowAutoPace` + driving-aid bit 11 (`sub_4CE720`-analog).

F1C's existing red-flag waypoint-guidance physics is the closest native primitive to NT2004's
field-bunching and could be reused/retargeted for the "field follows the pace car" step.

## 13. Open questions (live-verify targets)

- Exact numeric meaning of `dbl_7DA9D0` at runtime (assumed race clock; check live).
- `dword_75CBAC` bit0 inversion semantics (manual=1 seems to gate player control; confirm
  against the options dialog state).
- Whether NT2004's scanner (`sub_4F93E0`) is the only first-caution trigger outside weather.
- Full/substate numeric overlap between steward flag states and `dword_75CBB4` during a real
  caution (both are 0-8; the exact coupling is only statically derived here).
