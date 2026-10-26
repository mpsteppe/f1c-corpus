## ArithmeticComparison_5660_004a5660 — PitstopModeSelector

**Summary:** Sets the pitstop operation mode and selector flags based on input `a2`. When a2=0, sets mode to 1 with flags cleared. When a2≠0 and mode is not already 2, transitions to mode 2 with flags set. Always dispatches through ConditionalDispatch_55e0 after updating state.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitPartStateCopy (004a5330), ArrayShiftConditionalDispatch (004bbf70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | 1 | Operation mode: 1 = inactive/reset, 2 = active |
| this | 0x2C | RW | 0 | Selector flag forwarded to ConditionalDispatch_55e0 |
| this | 0x30 | RW | 0 | Additional status flag (set same as this[0x2C]) |

**Written-by note (persistence):**
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a55e0 | ConditionalDispatch_55e0 | Selects between two pitstop transition targets based on `this[0x2C]` flag |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | != | 2 | Guard against redundant mode-2 transition |

**Guard interpretation:** When `a2` is non-zero and mode is already 2, skips the state-change block (mode, flags remain unchanged) and falls through to the unconditional dispatch. When mode is not 2, updates state before dispatch.