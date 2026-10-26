## WheelForceParameterSet_004f1ba0 — wheel force parameter storage / direct apply

**Summary:** Stores four wheel force/torque parameters into struct fields or applies them directly to rigid body based on enable flag. Called during pit stop wheel operations.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | enable flag: non-zero = store params, zero = direct apply |
| this | 0x3664 | RW | — | wheel force/torque parameter 1 (a2) |
| this | 0x375C | RW | — | wheel force/torque parameter 2 (a3) |
| this | 0x3854 | RW | — | wheel force/torque parameter 3 (a4) |
| this | 0x394C | RW | — | wheel force/torque parameter 4 (a5) |

**Written-by note (persistence):**
- this 0x3664: recalc every frame — external poke does NOT persist
- this 0x375C: recalc every frame — external poke does NOT persist
- this 0x3854: recalc every frame — external poke does NOT persist
- this 0x394C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Field 0x32BC non-zero → stores a2-a5 into struct fields. Field 0x32BC zero → bypasses storage, calls ForceTorqueApplicationToRigidBodyWithInertiaTens directly.
