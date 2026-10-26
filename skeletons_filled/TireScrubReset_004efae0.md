## TireScrubReset_004efae0 — TireScrubReset

**Summary:** Resets tire scrub value to zero when wear mode is active and vehicle has rigid body. Part of tire wear/physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | Rigid body constraint pointer (validity check) |
| this | 0x3D64 | RW | — | Tire scrub value (reset to 0.0 if positive) |

**Written-by note (persistence):**
- this 0x3D64: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks EngineWearMode (dword_7CEA5C): if zero, returns immediately (BLOCKED — wear not active). Then checks rigid body ptr (this+0x32BC): if nonzero and scrub (this+0x3D64) > 0.0, resets scrub to 0.0. If rigid body ptr is zero and global dbl_7C91DC exceeds DBL_MIN, resets global to DBL_MIN.
