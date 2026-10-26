# 36 — Mod Surface Index

**Purpose:** plan ANY tweak from one page. Pick a domain → see its readiness,
owning source file(s), key globals, the *right* intervention rung, and what's
already been modded. Built 2026-07-21 from the IDA re-audit.

## How to read this

- **Readiness** = mean structural verify score for that subsystem's doc
  (`tools/ida_doc_verification.csv`). ≥0.92 = map is trustworthy; lower = verify
  offsets before building.
- **Offset%** = fraction of documented `+0xNNN` claims that match real code.
  This is the number that decides whether a *memory-poke* mod will hit the right
  field. <80% = pin the offset in IDA first.
- **Rung** = cheapest intervention that works (per `MODDING_PLAYBOOK.md`):
  **data** (edit a game file, no binary) < **memory** (poke / tick DLL) <
  **patch** (byte redirect / branch flip) < **detour** (last resort).
- Every fact below is GUESS tier until **live-verified** (`tools/preflight.py`).
  Names/offsets are IDA-derived, ~88–90% right. Confirm the specific field before code.

## Iron reminders (do not skip)

- Names in IDA are ~77% specific, ~1% wrong (commentary range `0x419xxx` is the
  known mislabel pocket — treat "AI ..." labels there as commentary emitters).
- A correct offset ≠ a writable value. Physics **recomputes** outputs each tick;
  poke may be overwritten. `preflight.py` tells you input-vs-output. See
  `feedback_mod_sessions_fail_cold`.
- Locate entry points with `python tools/investigate.py find "<concept>"` — never
  guess a function address from this table.

---

## Domain matrix

| Domain | Ready | Offset% | Source file | Primary rung | Notes |
|---|---|---|---|---|---|
| Track / camera / scene | 0.96 | 93 | camera.cpp | data + memory | 2SEATER/3SEATER cam defs confirmed |
| Session / race rules / scoring | 0.95 | 92 | steward.cpp, game.cpp | **patch** | penalties/flags/DQ live here |
| Pit stops / crew / tyre change | 0.95 | 85 | pitcrew.cpp, steward.cpp | memory/patch | PITORDER loader confirmed |
| Rendering / HUD / effects | 0.94 | 94 | render.cpp, onscreen.cpp | data + memory | |
| Audio / commentary / netcode | 0.94 | 86 | sound.cpp, NetComm.cpp | data (event table) | commentary emitters mislabeled as AI |
| Dynamics / suspension / forces | 0.93 | 92 | dynman.cpp | memory | DynMan_* lifecycle named |
| Collision / contact | 0.92 | 85 | (collision) | memory/patch | |
| **Vehicle physics (grip/tyre/aero/engine)** | 0.90 | **72** | hdvehicle.cpp, tire_manager.cpp, vehgfx.cpp | **data** (HDV/TBC) + memory | ⚠ offsets weakest — pin in IDA first |
| Data files (.veh/.gen/setup/gears) | 0.90 | 82 | vehload.cpp, setup.cpp | **data** | gear/setup/veh parsers confirmed |
| **AI behaviour (difficulty/pace/pit)** | 0.89 | **78** | ai_db.cpp | **data** (.rcd) + memory | ⚠ offsets weak — AI-profile struct not typed |
| Core engine / game loop / state | 0.81 | 86 | game.cpp | memory | infrastructure, rarely a direct target |

---

## Per-domain planning notes

### Race rules / penalties / flags — READY, patch-tier
The proven path. `cut_track_dq` **in-game confirmed** (byte redirect to
`FUN_004bc0e0`). steward.cpp is 0.95-ready. Candidate patch points ranked in
`docs/35-mod-targets.md`. Flags, track limits, pit rules, DQ all here.
Key global: `SessionType 0x007c56a4` (7=race), `RaceActiveFlag 0x007d0308`.

### Vehicle physics — WEAK offsets, prefer data files
grip/tyre/aero/engine. **Offset accuracy only 72%** — poke-first mods here are a
coin flip until offsets are pinned. Much of this is **data-file moddable** (HDV
physics, TBC tyres) with NO binary work. For live tweaks: vehicle struct stride
`0x48C0`, tire sub-struct stride `0xF8`, base array `0x005F0DEC` (F1CUI-confirmed).
Tyre-temp field NOT yet pinned — needs IDA `xrefs_to_field` after struct decl.

### AI behaviour — WEAK offsets, prefer .rcd data
difficulty/pace/aggression/pit-strategy/rain. **Offset 78%**. Per-driver ability
lives in editable `.rcd`/talent data — **data-rung, no binary**. Live behaviour
tweaks need the AI-profile struct typed (offsets `+0x112e` region, docs/13). AI
labels in `0x419xxx` are actually commentary — ignore those for behaviour work.

### Damage / failures / DNF — memory-tier, partially proven
`engine_blowup` (SPACE → FinishState=2, ReasonCode=1) facts-ready, not race-proven.
`ai_pit_retire` (F8 → AI DNF) writes land but in-game effect unconfirmed.
Confirmed: `veh+0x4068` ReasonCode (1=Engine..9=Fuel), pit flag `=3` in 0x48C0 block.
Source: engine-wear-damage domain.

### Session / weather — memory-tier
SessionType/RacePhase/weather globals. `SessionType 0x007c56a4`,
`GameState 0x007d00ec`, `RacePhase 0x007c56a8`. weather.cpp small. Session-state
pokes are among the most reliable (input values, not recomputed outputs).

### Pit stops — READY
pitcrew.cpp/steward.cpp 0.95. PITORDER loader, pit timer state machine documented.
Pit-lane speed, timing, crew, tyre-change all reachable.

### Commentary / audio — data-tier
Event table `DAT_005bf9a0` → PWS clip map (see `project_commentary_data_dump`).
The `0x419xxx` "AI" functions are the **event emitters** (`FUN_004144F0` build →
`FUN_00418560` dispatch). Mod = edit event→clip mapping, not code.

### Track / camera / rendering / HUD — READY, data+memory
0.94–0.96. Camera defs, scene loaders, onscreen displays all well-mapped.

---

## Known mods (ledger snapshot — see `mods/_README.md` for live status)

| Mod | Domain | Status |
|---|---|---|
| `cut_track_dq` | race rules | **in-game confirmed** |
| `ai_drying` | physics (grip vs wet) | validated via mod_pipeline |
| `engine_blowup` | damage | facts only, not race-proven |
| `ai_pit_retire` | AI/damage | writes land, effect unconfirmed |
| `safety_car` | race rules | v3 untested, 0x453C guess |
| `red-flag-dll` | race rules | restoring cut feature |
| `replay-ai-fix` | AI bug | no working patch yet |

---

## When a domain shows weak offsets (physics/AI): the fix

1. `python tools/investigate.py find "<field>"` → the writer function.
2. IDA: decompile it, read the REAL offset (don't trust docs/13's number).
3. Declare/extend the struct type in IDA, apply to the param → typed fields +
   `xrefs_to_field` finds every access.
4. `tools/preflight.py probe` the field live → input-vs-output before any mod.

Re-run the readiness matrix any time: it's derived from
`tools/ida_doc_verification.csv` (regenerate with `tools/ida_verify_docs.py`).
