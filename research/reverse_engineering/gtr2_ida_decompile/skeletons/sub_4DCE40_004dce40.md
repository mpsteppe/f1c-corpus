## sub_4DCE40_004dce40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DD1F0 (004dd1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | RW | — | [LLM] |
| this | 0x2FE | R | — | [LLM] |
| this | 0x300 | R | — | [LLM] |
| this | 0x308 | R | — | [LLM] |
| this | 0x30C | R | — | [LLM] |
| this | 0x310 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x2F8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x310: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e532e | SEH_4DCE40 | R | [LLM] |
| 00712824 | asc_712824 | R | [LLM] |
| 007128c4 | aSurface | R | [LLM] |
| 007128cc | aPosWH | R | [LLM] |
| 007128d4 | aLocation | R | [LLM] |
| 00712c78 | aName | R | [LLM] |
| 00712cdc | aGizmo | R | [LLM] |
| 00712ce4 | aPagePointer | R | [LLM] |
| 00712cf4 | aLocation2 | R | [LLM] |
| 00712d00 | aEsctarget | R | [LLM] |
| 00712d0c | aEntertarget | R | [LLM] |
| 0075ad58 | unk_75AD58 | R | [LLM] |
| 0075af70 | byte_75AF70 | R | [LLM] |
| 016c9950 | off_16C9950 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dac90 | sub_4DAC90 | [LLM] |
| 004dbcd0 | sub_4DBCD0 | [LLM] |
| 004dc3c0 | sub_4DC3C0 | [LLM] |
| 004df040 | sub_4DF040 | [LLM] |
| 004df500 | sub_4DF500 | [LLM] |
| 004df750 | sub_4DF750 | [LLM] |
| 004e0080 | sub_4E0080 | [LLM] |
| 004e0a60 | sub_4E0A60 | [LLM] |
| 004e0e80 | sub_4E0E80 | [LLM] |
| 004e2a80 | ShortComputation_a9c0 [exact] | [LLM] |
| 004e2aa0 | RectangleEdgeOffsetCalculator [exact] | [LLM] |
| 004e2b70 | sub_4E2B70 | [LLM] |
| 006131c0 | sub_6131C0 | [LLM] |
| 006134b0 | sub_6134B0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 0063099c | __ftol2 | [LLM] |
| 00630a80 | _strstr | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x300 | < | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `SURFACE`
- `POS-W-H`
- `LOCATION`
- `NAME`
- `GIZMO`
- `PAGE_POINTER`
- `LOCATION2`
- `ESCTARGET`
- `ENTERTARGET`
