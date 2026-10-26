## PerElementConditionalActionDispatcher_004a34a0 — PitPartFlagStateMachine

**Summary:** Manages per-part flag state in a pitstop operation. In normal mode (a2=0), conditionally sets or clears Bit12 on each non-null part object based on completion state (float == 99999.0) and a pending-interaction byte flag. In clear-all mode (a2≠0), clears Bit12 on every part unconditionally.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopOperationTimer (004a6340), PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Count of elements in the array |
| this | 0x10 | R | — | Pointer to base of 120-byte-element array of part operation structures |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e928 | flt_59E928 | R | FloatCompareConst [DERIVED] (also: Float comparison constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c190 | BitClear | Clears a flag bit (inverse of Bit12FlagSet) on the target part object |
| 0054c1a0 | Bit12FlagSet | Sets bit 12 (activation/enable flag) on the target part object |

**Guard conditions:** Checks `!a2` — when a2 is non-zero (clear-all mode), the entire conditional branch is skipped; function enters forced-clear mode instead. Within the per-element loop, individual elements are skipped when field at +72 (some ID/index) equals -1 or field at +100 (target object pointer) is null.