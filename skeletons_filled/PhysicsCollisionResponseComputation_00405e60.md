## PhysicsCollisionResponseComputation_00405e60 — ComputeCollisionAudioFeedback

**Summary:** Computes collision response intensity for audio feedback. Copies collision position/velocity parameters to struct, evaluates collision intensity via virtual function calls, clamps to [0,1], and either cleans up (no collision) or computes distance delta for audio triggering.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MilesAudioSamplePlaybackSetup (00405900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x54)+0x0) | 0x30 | R | — | vtable offset 12 (func to get collision intensity multiplier) |
| *(*(this+0x54)+0x0) | 0x58 | R | — | vtable offset 22 (func to check collision type) |
| *(this+0x54) | 0x0 | R | — | vtable pointer of collision object |
| *(this+0x54) | 0x58 | R | — | pointer to reference position for distance delta |
| *(this+0x54) | 0x5C | R | — | reference position Y component |
| *(this+0x54) | 0x60 | R | — | reference position Z component |
| obj | 0x8 | R | — | vtable offset 2 (cleanup/reset function) |
| this | 0x0 | R | — | vtable pointer of this audio response struct |
| this | 0x18 | R | — | flag byte at this[6], bit 3 (0x08) checked for collision type |
| this | 0x28 | RW | — | collision position X (a4[0]) |
| this | 0x2C | RW | — | collision position Y (a4[1]) |
| this | 0x30 | RW | — | collision position Z (a4[2]) |
| this | 0x34 | RW | — | collision velocity/force X (a5[0]) |
| this | 0x38 | RW | — | collision velocity/force Y (a5[1]) |
| this | 0x3C | RW | — | collision velocity/force Z (a5[2]) |
| this | 0x40 | RW | — | collision intensity (v10, clamped [0,1]) |
| this | 0x48 | RW | — | collision parameter (a3, stored as int) |
| this | 0x54 | R | — | pointer to collision object with vtable |

**Written-by note (persistence):**
- this 0x28: conditional write — external poke may persist between invocations
- this 0x2C: conditional write — external poke may persist between invocations
- this 0x30: conditional write — external poke may persist between invocations
- this 0x34: conditional write — external poke may persist between invocations
- this 0x38: conditional write — external poke may persist between invocations
- this 0x3C: conditional write — external poke may persist between invocations
- this 0x40: conditional write — external poke may persist between invocations
- this 0x48: conditional write — external poke may persist between invocations

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e4d8 | flt_59E4D8 | R | physics constant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Multiple guards: (1) a2 < 0.001953125 → clamped to 0.0. (2) Virtual function vtable[22] on v8 returns 1 → compute intensity via vtable[12] * a2, capped at 1.0; else v10 = 0.0. (3) v10 == 0.0 → call vtable[2] cleanup on this, return 1 (PASS — no collision). (4) v10 > 0.0 AND byte at this[6] bit 3 set → a6 = 0.0 (BLOCKED distance). (5) v10 > 0.0 AND bit clear → compute distance in a7/a6, return 0 (PASS — collision feedback).
