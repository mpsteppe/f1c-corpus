## AccumulatorWithStateSwitch_004a4050 — ModeSwitchAccumulator

**Summary:** Accumulates `a2` into an internal float value (offset 0x84) and forwards it to sub_4A2840. Behavior depends on state at offset 0x78: 0 = disabled (no action), 1 = reset accumulator to 0 then forward, other = accumulate and forward.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalDispatch_55a0 (004a55a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x78 | R | — | Mode/state selector: 0=disabled, 1=reset, other=accumulate |
| this | 0x84 | RW | 0 | Accumulator float value, reset to 0 when mode=1 |

**Written-by note (persistence):**
- this 0x84: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a2840 | sub_4A2840 | Receives the accumulator value for further processing (animation/state update) |

**Guard conditions:** Checks `*(_DWORD *)(this + 120)` (offset 0x78). PASSES when value is non-zero (mode 1 or other). BLOCKED entirely when value is 0 (disabled).