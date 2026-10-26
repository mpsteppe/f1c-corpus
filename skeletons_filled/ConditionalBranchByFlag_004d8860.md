## ConditionalBranchByFlag_004d8860 — FlagBranchWithIndexReset

**Summary:** If flag a2 is non-zero, calls IndexValidationSetter(0) and returns 0. If a2 is zero, sets this[2] = -1 (reset index) and returns 0.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatClampWithEventDispatch (004082b0), StructInitWithConditionalNotify (004083e0), CameraModeViewportUpdate (00409a00), MainCameraDirectorUpdate (0040ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 18446744073709551615 | index/state field reset to -1 when a2 is zero |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 is non-zero (flag true), dispatches via IndexValidationSetter. If a2 is zero (flag false), resets this[2] to -1.
