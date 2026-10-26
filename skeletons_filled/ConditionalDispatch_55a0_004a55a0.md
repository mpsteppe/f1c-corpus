## ConditionalDispatch_55a0_004a55a0 — ThreeTargetAnimationDispatcher

**Summary:** Dispatches to up to three sub-objects for per-frame update: calls sub_4A3570 (AnimationTargetPropagator) on `this[4]` and `this[3]`, and AccumulatorWithStateSwitch on `this[5]`, passing the caller's float parameters through. Each call is guarded by null-pointer check.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Pointer to second animation target (sub_4A3570) |
| this | 0x10 | R | — | Pointer to first animation target (sub_4A3570) |
| this | 0x14 | R | — | Pointer to accumulator target (AccumulatorWithStateSwitch) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a3570 | sub_4A3570 | AnimationTargetPropagator — computes and distributes animation target values |
| 004a4050 | AccumulatorWithStateSwitch | ModeSwitchAccumulator — accumulates float delta with mode selection |

**Guard conditions:** Each of the three callee pointers is null-guarded independently. PASSES when the pointer is non-null. BLOCKED (call skipped) when pointer is null.