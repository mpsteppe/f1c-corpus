## ZeroFillArraysAndCallInitRoutineRepeatedly_0056d880 — VehiclePhysicsJointInitRoutine

**Summary:** Zero-fills arrays of 8-byte elements pointed to by each pointer in a2, then calls sub_568FB0 init routine for each vehicle physics joint struct (stride 580 bytes) in this struct's array.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of vehicle physics joint structs to initialize |
| this | 0x4 | R | — | Pointer to array of vehicle physics joint structs (stride 580) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568fb0 | sub_568FB0 | Initialize one vehicle physics joint struct |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Count of joint structs to init |

**Guard interpretation:** PASSES when *this > 0 — iterates and calls sub_568FB0 on each joint struct. BLOCKED (skipped) when *this <= 0, leaving joints uninitialized.
