## PackedFlagRead_9a00_004b9a00 — AngleClampModeRead

**Summary:** Reads the angle clamp/wrap mode byte at offset 0xF81 from a dereferenced object pointer. Returns non-zero for hard-clamp mode, zero for wrap mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalStateUpdate (004ba150), ConditionalMultiPathDispatcher (004ba180), TwoPathDispatch (004ba6c0), WeatherParticleUpdate (004cfcc0), SteeringAckermannComputation (004db170), StringNameMatching (004fc700), CarPositionTargetCheck (004fe060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF81 | R | — | angle clamp mode flag (0=wrap, non-zero=hard clamp) |
| this | 0x0 | R | — | pointer to actual object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always reads the byte and returns it.
