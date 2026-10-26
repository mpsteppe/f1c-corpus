## TimedAnimationTrigger_00486730 — TimedAnimationFrameAdvance

**Summary:** Accumulates time delta (from float at this+0x40); when threshold exceeded, advances animation frame index, decrements repeat count, and optionally triggers string-keyed renderer. Part of UI timed animation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_486830 (00486830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | source float — time delta per frame |
| this | 0x80 | RW | 0 | accumulated animation progress (float, wraps at threshold) |
| this | 0x84 | R | — | parameter passed to ConditionalDelegation — animation config selector |
| this | 0x88 | RW | 0 | current animation frame index |
| this | 0xDC | RW | — | remaining repeat count (decremented each cycle) |

**Written-by note (persistence):**
- this 0x80: written every call (accumulator updated); external poke overwritten
- this 0x88: written conditionally when animation triggers; external poke may survive between triggers
- this 0xDC: decremented conditionally; external poke survives between triggers

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486280 | UIStringAccessor_6280 | get string name from UI element (renderer key) |
| 00486460 | ConditionalDelegation_6460 | resolve animation configuration block from this+132 |
| 00497e80 | sub_497E80 | lookup renderer object by string name |
| 00498030 | RendererAlphaBlendSetter | set alpha blend mode on renderer |
| 00498730 | FloatFieldAccessor | read float from field at offset 0x40 (time delta) |

**Guard conditions:** 1) If ConditionalDelegation_6460 returns null → return 0 (blocked). 2) If config field at offset 40 is zero → reset frame index to 0, return 0 (blocked). 3) If accumulated float ≤ threshold (config+24) → return 0 (no animation trigger this frame). 4) If repeat count > 0 and string exists → trigger renderer lookup and alpha blend set.
