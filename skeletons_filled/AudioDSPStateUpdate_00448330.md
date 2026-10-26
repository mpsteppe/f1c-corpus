## AudioDSPStateUpdate_00448330 — AudioDSPStateUpdate

**Summary:** Per-frame audio DSP state update: accumulates time with stored offset, dispatches interrupt, iterates scene graph children with conditional dispatch, calls DSP parameter update on audio object, and manages scrolling/animation transition based on state comparison. Called from sub_4D4580.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0x4 | R | — | vtable offset +4: DSP update method pointer |
| *(this+0x4) | 0x0 | R | — | audio DSP object vtable pointer |
| this | 0x0 | R | — | scene graph root handle/pointer |
| this | 0x4 | R | — | audio DSP object pointer |
| this | 0x8 | R | — | threshold float (guards dispatch block if > 0.0) |
| this | 0xC | R | — | scene entity reference for conditional dispatch |
| this | 0x10 | R | — | scrolling/animation linked data pointer |
| this | 0x14 | R | — | time/position accumulator (added to input a2) |
| this | 0x18 | RW | — | previous state value (compared with a2 for transition detection) |

**Written-by note (persistence):**
- this 0x18: updated every call to input a2; external poke overwritten next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b950 | SceneNodePositionGetter | retrieves scene node position vector |
| 0054c210 | SceneGraphChildCount | counts children of scene graph root |
| 0054c230 | LinkedListIndexedAccessor_c230 | indexed accessor for scene graph children |
| 005505a0 | LinkedListAnimationTimerDecrement | decrements animation timer on linked data |
| 00550620 | ScrollingDataOffsetAcrossLinkedEntries | links data into scrolling offset (used on state match) |
| 00551810 | ConditionalDispatchByFlag | conditional dispatch to scene entity if flag set |
| 0058957a | InterruptDispatch | dispatches audio interrupt with accumulated time |

**Guard conditions:** this+0x8 > 0.0 gates the interrupt dispatch and scene graph iteration block. When <= 0.0, scene position get, DSP update, and animation management still execute. For animation path: this+0x10 (linked data) must be non-null for ScrollingDataOffsetAcrossLinkedEntries or LinkedListAnimationTimerDecrement; when null, only this+0x18 update occurs.
