## CollisionContactImpulse_004599c0 — CollisionContactImpulse

**Summary:** Computes collision contact impulse by scaling a direction vector by a magnitude factor, computing a delta from contact body state, and performing cross-product rotation accumulation. Sets contact impulse magnitude at 0x20 and offset magnitude at 0x24. Part of collision response system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ModeDispatchWithSwitch (0040f4b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | Contact impulse magnitude (offset +100) stored as float |
| this | 0x24 | RW | — | Contact impulse magnitude (a3) stored as float |
| this | 0xD8 | R | — | Contact body position/delta X (double, index 54 field 1) |
| this | 0xE0 | R | — | Contact body position/delta Y (double, index 54 field 3) |
| this | 0xE8 | R | — | Contact body position/delta Z (double, index 54 field 5) |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00569670 | F_3DVectorCrossProductRotationAccumulation | Compute cross product of scaled direction vector and position delta for rotational impulse contribution |

**Guard conditions:** No guard conditions — always computes and accumulates impulse, no early return.
