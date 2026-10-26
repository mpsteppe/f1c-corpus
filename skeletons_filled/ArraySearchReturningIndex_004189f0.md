## ArraySearchReturningIndex_004189f0 — SearchAndResetByID

**Summary:** Linear search through 20-entry table (at this+0x864, 8-DWORD stride) for entries matching an ID. Each match resets entry via StructInitWithSentinelValues. Returns 1 if any entry matched, 0 otherwise. Used to clear/reset entries for specific driver/entity IDs.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BooleanOROfTwoChecks (00418a20), AIDriverStateTransition (00419120), PitSelectionStateMachine (0041b3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x864 | R | — | Start of 20-entry search table (each entry 8 DWORDs, first DWORD is ID field) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Resets/initializes an 8-DWORD entry to sentinel/default values after match |

**Guard conditions:** No guard — always iterates all 20 entries. Entry passes if its first DWORD (ID) equals a2; matching entry is reset via StructInitWithSentinelValues.
