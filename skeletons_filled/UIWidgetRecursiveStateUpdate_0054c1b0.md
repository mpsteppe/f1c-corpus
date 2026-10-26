## UIWidgetRecursiveStateUpdate_0054c1b0 — UI widget recursive state update

**Summary:** Recursively propagates a state update to linked child widgets, then sets or clears a global state flag based on parameter `a2`.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A3390 (004a3390), FlagBasedLoopConditionalCall (004a3440), VehicleVisibilityCulling (004b3dc0), AudioSoundEffectController (004e0ed0), sub_4FA7E0 (004fa7e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | R | — | First child widget pointer (recurse when a3 non-zero) |
| this | 0x4C | R | — | Second child widget pointer (recurse when (a3 & a4) != 0) |
| this | 0x230 | R | — | Flag state object pointer (triggers global flag set/clear) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c1b0 | UIWidgetRecursiveStateUpdate | Recursive self-call to propagate to children |
| 00560fc0 | Bit1FlagSet | Sets global bit 1 flag (when a2 is non-zero) |
| 00560fd0 | StateFlagBitClear | Clears state flag (when a2 is zero) |

**Guard conditions:** Child at 0x44: recurses only if non-null AND `a3 != 0`. Child at 0x4C: recurses only if non-null AND `(a3 & a4) != 0`. Flag set/clear: skipped entirely if `this[0x230]` is null.
