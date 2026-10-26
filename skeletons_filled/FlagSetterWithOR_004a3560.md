## FlagSetterWithOR_004a3560 — PitOpValueStoreAndDirtyFlag

**Summary:** Stores a caller-supplied value into `this[4]` and sets the dirty/change flag (bit 1 on `this[0]`) to signal that the stored value was updated. Called by PitStopOperationTimer to record a pit operation parameter change.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Flags field; bit 1 set to indicate a value-change event |
| this | 0x4 | W | — | Stores the caller-supplied parameter value |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; always executes full body.