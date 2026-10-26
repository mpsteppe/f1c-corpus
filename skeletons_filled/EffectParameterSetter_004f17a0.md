## EffectParameterSetter_004f17a0 — EffectParameterSetter

**Summary:** Sets three effect parameters: throttle/climb value, a scaled parameter using tire choice multiplier, and another parameter. Part of vehicle effect/parameter system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3570 | RW | — | Effect parameter set from a4 |
| this | 0x3978 | RW | — | Scaled effect value (a3 * tireChoice multiplier) |
| this | 0x397C | R | — | tireChoice [CONFIRMED] |
| this | 0x3994 | RW | — | Throttle/climb effect parameter set from a2 |

**Written-by note (persistence):**
- this 0x3570: recalc every frame — external poke does NOT persist
- this 0x3978: recalc every frame — external poke does NOT persist
- this 0x3994: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always sets all three fields and returns.
