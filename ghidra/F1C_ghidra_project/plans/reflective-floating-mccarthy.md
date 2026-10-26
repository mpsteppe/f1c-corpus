# Red Flag Script — Proof of Concept Plan (review-ready)

> **For the reviewer (read first).** This plan is self-contained — you do not need
> to open the repo to review it. Every address, function, and assumption is inline.
> Your job: judge feasibility and risk, not restate the plan. Focus on:
> 1. **Confidence tiers** — each fact is tagged `[FACT]` (from raw decompiled `.c` or
>    the live process), `[DOC]` (LLM-written docs, ~90% accurate, unverified), or
>    `[OPEN]` (not yet located/proven). Challenge anything built on `[DOC]`/`[OPEN]`.
> 2. **Iron rule 5** — injected code must NEVER call a game function that is
>    `__thiscall`/`__fastcall(this)` or cleans its own stack (`ret imm`). Flag any
>    step that does. The whole restart design exists to obey this.
> 3. **Verification order** — is each mechanism proven live *before* it is composed?
>    A red gate must stop the phase. Flag any "write code first, test the whole mod"
>    step (1-bit feedback over unproven facts = coin flip).
> Deliver: a per-phase GO / NO-GO with the single riskiest assumption named.

## Glossary (so no repo lookup is needed)

| Term | Meaning |
|------|---------|
| F1C | F1 Challenge 99-02, `F1 Challenge Online.exe`, x86 PE32, MSVC 2002, **no ASLR**, base `0x00400000` → absolute virtual addresses are stable and usable directly. |
| `[FACT]` | Verified against raw decompiled `.c` or the running process. Trust. |
| `[DOC]` | From `docs/` (LLM-generated, ~90% per-fact). Verify before building on. |
| `[OPEN]` | Not yet located or proven. Must close before the dependent phase. |
| poke | `tools/poke.py` — read/write a live memory address in the running game. |
| preflight | `tools/preflight.py run facts.json` — batch-verify facts vs the live game. |
| tick DLL | Injected DLL, background thread polls a hotkey / writes globals each frame. Proven pattern (`ai_pit_retire`). Pure data writes only. |
| SessionType | Global `0x007c56a4`, `7` = Race. |
| veh | A vehicle struct pointer; per-vehicle stride `0x48C0`. |

## Context (why this exists)

The F1C community wants a working **red flag** for single-player. Matias scoped a
PoC to three mechanisms proven independently, then a target flow:

1. Red flag fires → snapshot current standings.
2. AI cars pit + retire to the garage (reuse the mechanical-retirement path).
3. Player drives into the pits → fire the game's own **Restart Race**, seed the grid
   from the snapshot, set lap count to the pre-flag value.
4. Race restarts normally (pre-race intro, standing start), runs the remaining laps.

**Confirmed decisions:** restart = reuse the stock Restart command + override grid &
lap count. Trigger = **manual hotkey first** (auto-detect heuristics are Phase 5).
SP only. Player is **not** "retired" — pit entry is the restart trigger (avoids the
MP-only race-retire path that dumps to the menu).

## Mechanism 1 — AI retire  `[FACT]` primitive, `[OPEN]` in-game effect

Reuse existing `mods/ai_pit_retire`: press F8 → every AI car flagged pit + DNF,
player untouched. Writes (all `[FACT]`, plain data on the game thread's structs):

| Write | Addr / offset | Value |
|-------|---------------|-------|
| Vehicle ptr array | `0x007C54F0` → `[i]` | iterate |
| Vehicle count | `0x005C329C` | loop bound |
| Player ptr (skip) | `0x007C54E8` | — |
| FinishState | `veh+0x4064` | `2` = DNF |
| ReasonCode | `veh+0x4068` | `1..9` (e.g. `6`=Accident) |
| Pit flag | driver block `0x005F073C + i*0x48C0` | `3` = pitting |

`[OPEN]` **Status: LOG-CONFIRMED only** — the writes land (`retired 21 AI cars`) but
the user has never confirmed the cars actually retire on screen. **Gate 1 = confirm
in-game.** If they don't retire, the game likely reads a different field →
`f1c-debug-failed-mod`.

## Mechanism 2 — Restart  `[FACT]` chain located, `[OPEN]` trigger flag

Fully traced in the decompiled `.c` (see `mods/red_flag_v2/FINDINGS.md`):

| Fn | Addr | Role | Tier |
|----|------|------|------|
| Main state pump | `0x0045b200` | Polls a restart gate (`FUN_0042d6b0`); when open, calls Restart from the game's own loop. | `[FACT]` |
| `Game::Restart()` | `0x0042d7a0` | `__fastcall(Game* this)`. Sets `*this = 4` (state=restart), runs full chain: steward reset + car respawn + 15 subsystem resets. | `[FACT]` |
| steward Restart | `0x004d3cf0` | `__fastcall(steward* this)`. **Case 7 (race): reads `DAT_007d05a0` → race lap count**; fires `PreRacePresentation` (the intro Matias wants). | `[FACT]` |
| NetComm slot load | `0x0045fc50` | Reads `VehicleGridArray` `0x005ef9a0` (stride `0x1230`, slot-indexed via `veh+0x40`, `-1`=empty). Grid placement. | `[FACT]` |

**Design (obeys rule 5):** Restart is **state-driven**. `Game::Restart` and steward
Restart are both `__fastcall(this)` — **must not be called from injected code.**
Instead **set the game's restart-request state and let the game's own loop invoke
Restart with the correct `this`** = pure memory write.

`[OPEN]` **The exact global/field the "Restart Race" input action sets is not yet
located.** Candidates: the Game state field (`Game+0`, value `4`) and/or a request
flag read by `FUN_0042d6b0` / `FUN_0042d5d0` / `FUN_0042d370`. **Closing this needs
one IDA xref** (input-action reg `0x004aa270`/`0x00455290` → dispatch → setter) and
the `Game*` base for read-back. This is the single most important `[OPEN]` item.

## Mechanism 3 — Lap count & grid override

- **Lap count:** `DAT_007d05a0` `[FACT]` is the value steward Restart copies into the
  session on a race restart. Write it before triggering restart to change remaining
  laps. (A second global `DAT_008acf8c` `[DOC]` "TotalRaceLaps" is used elsewhere in
  lap/penalty tracking — reconcile live which one the on-screen count follows.)
- **Grid order:** `VehicleGridArray` `0x005ef9a0`, stride `0x1230`, slot/team-indexed
  `[FACT]`. **Risk:** slot-indexing may not map 1:1 to finishing order → seeding the
  grid from standings likely needs a translation layer. `[OPEN]`

## Mechanism 4 — Player-in-pits detection  `[OPEN]`

Need a reliable "player has entered the pit lane" signal to gate the restart. Likely
the player's pit flag in the `0x48C0` driver block (`==1` in pits) via
`PlayerVehiclePtr 0x007C54E8`. Prove live in Phase 2.

## Blocking prerequisite — live rig

Every gate past Phase 1 needs the live rig:
- **IDA + IDA MCP** (`.mcp.json` → `http://127.0.0.1:13337/mcp`) for the `[OPEN]`
  xrefs. NOTE: if IDA is started *after* the Claude session, the MCP tools are not
  registered — reconnect the MCP / restart the session, or drive the HTTP endpoint
  directly.
- **`F1 Challenge Online.exe` running in a race** (SessionType==7) for
  poke / preflight / Frida.

## Phases (each gate is GO/NO-GO)

**Phase 0 — rig up.** IDA + MCP answering on `:13337`; game in a race. No code.

**Phase 1 — locate + fact-sheet.** DONE for restart & lap/grid (this doc +
`FINDINGS.md`). Remaining `[OPEN]`: restart-request flag + `Game*` base (IDA xref),
player-in-pits offset. Output already scaffolded: `mods/red_flag_v2/facts.json`.

**Phase 2 — poke-prove each fact live** (`tools/preflight.py run mods/red_flag_v2/facts.json`
+ hand pokes; log read-backs — iron rule 6):
- **G1** run `ai_pit_retire` (F8) → user confirms AI cars retire on screen.
- **G2** hand-poke the restart-request flag → game restarts; write `DAT_007d05a0` →
  lap count honored; map grid array to standings.
- **G3** confirm the player-in-pits signal.
A red gate stops the phase — fix facts, re-poke; do not paper over with code.

**Phase 3 — Frida prototype** (reversible, on the live game, no baked exe): script
the full loop once — snapshot → AI retire → wait player-in-pits → seed grid+lap →
set restart flag. Risk collapses here.

**Phase 4 — bake orchestrator DLL** (tick DLL, hotkey `R`). State machine:
`IDLE → SNAPSHOT → AI_RETIRE → WAIT_PLAYER_PIT → SEED_GRID_LAP → SET_RESTART_FLAG → IDLE`.
Only pure data writes; the "restart" is a flag write, never a call into game code.
Ship `mods/red_flag_v2/`: `facts.json`, Frida `.js`, DLL, `apply_*.py`, `_README`
status line; update `mods/_README.md` ledger.

**Phase 5 — triggers** (post-PoC): Discord auto-trigger heuristics (retirements in a
window, cars stationary under speed, track-width blocked, prolonged yellow) +
presentation (FTINGAME01 red-flag icon, radio message).

## Verification (end-to-end)
1. Rig up: MCP `:13337` answers; game in a race.
2. Every Phase-2 gate green with logged read-back values.
3. Phase-3 Frida run completes the full loop once, observed in-game.
4. Phase-4 DLL: hotkey mid-race → AI retire → drive to pits → race restarts with the
   pre-flag order and correct remaining laps. **User confirms in-game** (writes
   landing ≠ game reacting — in-game confirmation is the only real pass).

## Risks (ranked)
1. `[OPEN]` restart-request flag un-findable or has side effects → fall back to
   input-injection or a call-site byte redirect at `0x0045b200`'s call to
   `Game::Restart`.
2. `[OPEN]` grid array (`0x1230`, slot-indexed) not 1:1 with finishing order →
   translation layer needed.
3. `[OPEN]` `ai_pit_retire` never in-game confirmed → could block G1.
4. `[OPEN]` player-in-pits detection reliability.
5. `[DOC]` two lap globals (`007d05a0` vs `008acf8c`) — wrong one → count desyncs.
