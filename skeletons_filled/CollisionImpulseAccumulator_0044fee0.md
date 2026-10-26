## CollisionImpulseAccumulator_0044fee0 — CollisionImpulseAccumulator

**Summary:** Accumulates collision impulse vectors into a contact impulse buffer. Adds three components each from two input vectors (a2, a3) to six consecutive double fields (linear + angular impulse accumulation). Part of collision response system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AccumulateAngularImpulse (0043e5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x560 | RW | — | Accumulated impulse X component from vector a2 |
| this | 0x568 | RW | — | Accumulated impulse Y component from vector a2 |
| this | 0x570 | RW | — | Accumulated impulse Z component from vector a2 |
| this | 0x578 | RW | — | Accumulated impulse X component from vector a3 |
| this | 0x580 | RW | — | Accumulated impulse Y component from vector a3 |
| this | 0x588 | RW | — | Accumulated impulse Z component from vector a3 |

**Written-by note (persistence):**
- this 0x560: recalc every frame — external poke does NOT persist
- this 0x568: recalc every frame — external poke does NOT persist
- this 0x570: recalc every frame — external poke does NOT persist
- this 0x578: recalc every frame — external poke does NOT persist
- this 0x580: recalc every frame — external poke does NOT persist
- this 0x588: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — always accumulates both input vectors (a2 and a3) into the six impulse fields unconditionally.
