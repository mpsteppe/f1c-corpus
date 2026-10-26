## VTableSetWithFlag_00488f90 — TrackSceneVTableInit

**Summary:** Zero-initializes via ShortComputation_5e30, sets vtable to TrackSceneVTable, and sets flag at 0xE4 to 1. Constructor fragment for track scene objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIMenuItemCreator (00489600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer — set to TrackSceneVTable |
| this | 0xE4 | RW | 1 | Boolean flag — set to 1 (active/visible) |

**Written-by note (persistence):**
- this 0x0: Written once during construction. Not modified after.
- this 0xE4: Written once during construction. May be modified later.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abcd0 | off_5ABCD0 | R | TrackSceneVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | Zero-initialize fields / base init |

**Guard conditions:** None — unconditional init.
