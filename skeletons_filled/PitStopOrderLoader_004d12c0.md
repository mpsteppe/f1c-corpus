## PitStopOrderLoader_004d12c0 — PitStopOrderDataLoader

**Summary:** Load and parse pit stop order data for teams. Queries team list from string-keyed linked list, allocates array for team entries, checks if reverse pit order is enabled. If reverse, iterates teams in reverse order; otherwise forward.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** IndexedArrayAccessor (004d1410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A8 | RW | 0 | team entry count |
| this | 0x1AC | RW | — | pointer to allocated team data array |

**Written-by note (persistence):**
- this 0x1A8: recalc every frame — external poke does NOT persist
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3a28 | aPitorder | R | String_PitOrder [DERIVED] |
| 005d3a34 | aTeam | R | TeamString [DERIVED] |
| 005d3bd8 | aFalse_0 | R | FalseString [DERIVED] |
| 005d3be0 | aReversepitorde | R | ReversepitordeString [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049adb0 | ShortComputation_adb0 | advance to next linked list element |
| 004c58a0 | StringCopyWithValidation | validate string equality |
| 00566650 | StringCopyWithBufferRealloc | realloc string buffer |
| 00567970 | DataEntryAccessor | extract data entry from linked list element |
| 005679c0 | StringKeyedLinkedListSearch | search linked list by string key |
| 00568210 | AudioChannelStop | stop audio channel for "pitorder" string |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for team data array |
| 00588410 | sub_588410 | string comparison function |

**Guard conditions:** AudioChannelStop("pitorder") must return non-zero (pit order data available). If false, entire load is skipped.
