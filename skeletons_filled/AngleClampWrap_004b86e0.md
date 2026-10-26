## AngleClampWrap_004b86e0 — AngleClampWrap

**Summary:** Clamps or wraps an angle value to a configurable range [this+0xF30, this+0xF34]. In wrapping mode (byte at this+0xF81 == 0), value exceeding range wraps around. In clamp mode (byte non-zero), value is hard-clamped to bounds. Saves previous angle to this+0xF3C. Part of physics/steering animation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameDataFileIO (004b7300), LoadingPhase1 (004b87c0), LoadingPhase2 (004b8940), sub_4B8C40 (004b8c40), PitServiceSteeringAnimationStep (004b9e40), sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF30 | R | — | lower bound of angle range |
| this | 0xF34 | R | — | upper bound of angle range |
| this | 0xF38 | RW | — | current angle value (written with new clamped/wrapped value) |
| this | 0xF3C | RW | — | previous angle value (saved before update) |
| this | 0xF81 | R | — | mode flag: 0 = wrap, non-zero = hard clamp |

**Written-by note (persistence):**
- this 0xF38: updated each call with new angle; persists as current angle
- this 0xF3C: updated each call with old angle; persists as previous angle

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes. The mode byte at this+0xF81 determines wrap vs clamp behavior. All values pass through, but are constrained to range.
