## ForcePitExit_0042a110 — ForcePitExit

**Summary:** Forces AI driver to exit pits by setting a state flag. For race sessions, only acts when NOT on the last lap AND when teammate part lookup returns 0, 4, or driver has FinishState 1. For non-race sessions always forces exit. Calls StateConditionalAction and AIStateFlagSetter.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), AIPushLap (0042a180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x403C | R | — | lapNumber [CONFIRMED] — compared against last lap to block pit exit |
| this | 0x4064 | R | — | FinishState [FACT] — value 1 (finished) bypasses teammate check |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — 7 = race session |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] — last lap number = total - 1 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ac70 | AIStateFlagSetter | sets AI state flag to 1 (pit exit requested) |
| 004a5c40 | TeammatePartValueLookup | checks teammate/team status value; values 0 or 4 allow pit exit |
| 004a5e40 | StateConditionalAction | performs conditional state transition for pit exit |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4064 | == | 1 | FinishState [FACT] == finished |

**Guard interpretation:** For race sessions (dword_7C56A4 == 7): BLOCKED (no pit exit) if current lap == totalLaps - 1 (last lap), OR if TeammatePartValueLookup returns non-zero AND non-4 AND FinishState != 1. PASSES (forces exit) when not last lap AND (teammate check returns 0, 4, or FinishState == 1). For non-race sessions: always PASSES unconditionally.
