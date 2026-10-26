## TwoPathDispatch_004ba6c0 — Type-sentinel two-path dispatcher

**Summary:** Dispatches between session/ring-buffer update (type 1) and weather particle update (type 2) based on sentinel at this[0]. Path 1 also gates on byte_7C56AC enable flag and session state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Type sentinel (1=session path, 2=weather path) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 007cc4c8 | dword_7CC4C8 | R | CheckFlag [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007d0080 | dword_7D0080 | R | Dword_GameState2 [DERIVED] |
| 0083ee60 | dword_83EE60 | R | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461db0 | SessionStateCheckWrapper | Check if game session is active |
| 004b9870 | CallWrapper_9870 | Session update wrapper with ring buffer count and time |
| 004b9890 | sub_4B9890 | Scoring/state update with game state value |
| 004b9a00 | PackedFlagRead_9a00 | Read packed flag at this+0x8 (weather path guard) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | Type sentinel (session path) |

**Guard interpretation:** Path 1 selected when this[0]==1; within path, gated on !byte_7C56AC and SessionStateCheckWrapper. Path 2 selected when this[0]==2; within path, gated on PackedFlagRead_9a00(this+0x8)==0.
