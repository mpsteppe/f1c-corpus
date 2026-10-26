## UIComponentInit5_0048fe60 — UICompInit5

**Summary:** Initialization function for a UI component. Calls base initializer, sets vtable pointer, and initializes two fields to default values (1 and 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionFlagPointerSelector (0046fe80), SeasonDatabaseObjectFactory (0047f440), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer |
| this | 0xE0 | RW | 1 | UI state/flag initialized to 1 |
| this | 0xE4 | RW | 0 | UI state/flag initialized to 0 |

**Written-by note (persistence):**
- this 0x0: Once — set to vtable pointer at construction; survives unless deliberately changed.
- this 0xE0: Once — initialized to 1; persists until modified.
- this 0xE4: Once — initialized to 0; persists until modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac6b0 | off_5AC6B0 | R | VTable_5AC6B0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | Base/sub-object initialization routine |

**Guard conditions:** None — unconditional initializer; no branches.
