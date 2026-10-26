## CollisionAvoidanceCheck_004a6b80 — Collision avoidance state machine

**Summary:** Checks vehicle's movement direction against all other vehicles' projected trajectories to detect imminent collisions. Transitions collision avoidance state between checking and clear. Part of vehicle physics/tick.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x34E0 | R | — | Vehicle velocity/direction X component |
| obj | 0x34E4 | R | — | Vehicle velocity/direction Y component |
| obj | 0x34E8 | R | — | Vehicle velocity/direction Z component |
| obj | 0x39A0 | R | — | Movement threshold flag (>0.0 = vehicle is moving, enable collision check) |
| this | 0x0 | R | — | Pointer to obj struct |
| this | 0x4 | R | — | Vehicle index in global array |
| this | 0x14 | R | — | Pointer to collision avoidance sub-object (this[5]) |
| this | 0x78 | R | — | Pointer used for FlagFieldBitManipulation |
| this | 0x8C | RW | 2 | Collision avoidance state (2 = clear/no collision, 1 = collision predicted) |

**Written-by note (persistence):**
- this 0x8C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e918 | flt_59E918 | R | ProximityDistThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e9630 | PositionChangeMonitor | Get vehicle position change data for movement direction calculation |

**Guard conditions:** this[5] (this+0x14) must be non-null to proceed. When null, BLOCKED — returns 0 immediately. When non-null, PASSES into collision raycast loop against other vehicles.
