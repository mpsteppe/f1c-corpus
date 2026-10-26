## SimpleSetterWithFlag_00431a50 — FlaggedValueSetter

**Summary:** Sets a field at this+0x1CBC to input value a2 and sets a changed/dirty flag at this+0x1CB8 to 1. Always writes both fields.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelDynamicsInit (0043e230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1CB8 | RW | 1 | valueChangedFlag |
| this | 0x1CBC | RW | — | targetValue |

**Written-by note (persistence):**
- this 0x1CB8: recalc every frame — external poke does NOT persist
- this 0x1CBC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always writes both fields unconditionally.
