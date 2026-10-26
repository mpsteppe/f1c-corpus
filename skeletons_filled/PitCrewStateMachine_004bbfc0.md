## PitCrewStateMachine_004bbfc0 — PitStopStateMachine

> **PROSE CORRECTED 2026-07-24 (live evidence — fact table below is untouched).**
> The "audio / pit sound flag" reading in the Summary and field table is WRONG.
> `obj 0x105D` is **DriverModelVisible** (1 = driver drawn, 0 = hidden): it gates the
> HELMET[549]/ARMS[550]/BODY[551] scene nodes in `sub_4E0ED0`. POKE-PROVEN on
> M. SALO — writing 0 made the helmet and arms vanish on screen while the car kept
> driving; the game clears the same byte on a genuine retirement. `obj 0x1054` is the
> **render mode** (0..3), not a sound event ID. `sub_4E0ED0` is the vehicle
> **render-state update**, not an audio controller (it is misnamed).
> This is the driver-removal step of a real AI retirement.
> Detail: `mods/ai_pit_retire/RETIRE_SOLVED_2026-07-24.md`.


**Summary:** Manages pit entry/exit state transitions with audio feedback. On pit-entry trigger (object matches expected type), sets state=2, stores car index, disables pit sound flag, plays audio, resets AI state. On exit (non-pit object), resets state to 0, restores pit sound flag to 1, plays audio.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400), EngineFailureCheck (004bec55)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1054 | R | — | sound event ID for pit entry/exit audio |
| obj | 0x105D | RW | 1 | pit sound flag: 1=enable audio, 0=mute |
| this | 0x0 | R | — | pointer to vehicle/car object (dereferenced for AIStateReset and sound) |
| this | 0x30 | RW | 0 | pit state: 0=idle, 2=entering/pitting |
| this | 0x34 | RW | — | stored car index byte from pit-trigger object (+8 offset) |

**Written-by note (persistence):**
- obj 0x105D: set to 0 on pit entry, set to 1 on pit exit; external poke survives until next transition
- this 0x30: set to 2 on entry, reset to 0 on exit; external poke survives until next transition
- this 0x34: written once on first entry (if null); external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00680000 | unk_680000 | R | VEH[32].0x2128 — sentinel mask for pit-trigger object type identification |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042af40 | AIStateReset | resets AI state machine on pit entry |
| 004e0ed0 | AudioSoundEffectController | plays pit entry/exit sound effect |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x105D | != | 1 | pit sound flag: if already 0 (muted), skip sound on entry |
| this | 0x30 | == | 2 | pit state: if state == 2, reset to 0 on non-pit trigger (exit) |

**Guard interpretation:** PASSES = pit entry trigger when state=0 → enters pit sequence (state→2, play sound). BLOCKED = pit entry trigger while state already != 0 → skip; non-pit trigger while state != 2 → skip exit logic.
