## FieldSetterCall_004988a0 — Field Setter With Cursor Select

**Summary:** Writes a value to the field at offset 0x58 and calls CursorSelectorFromArray with a rendering state value and the same argument, returning the selection result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameObjectUpdateFrame (004661b0), FlagSetter (00466250), ShortComputation_6270 (00466270), FlagClearZeroBytes (00466290), UIStateReset (004662c0), StateInitializerWithFlagCheck (00466300), sub_466650 (00466650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | UI state/index field set to parameter a2 |

**Written-by note (persistence):**
- this 0x58: Overwritten unconditionally each call with value a2; persists until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cb24c | dword_7CB24C | R | Render state value passed to cursor selection function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** (none — always executes unconditionally)
