## PhysicsForceScaleDispatch_0043ebd0 — ForceScaleDispatchToDamperAndSpring

**Summary:** Dispatches a force input scaled by 0.25 to SuspensionDamperForceAccumulation and 0.75 to ClampedSpringIntegrator. Splits a single force value between damper and spring subsystems. Part of vehicle physics force distribution.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatParameterForwarder (004ed1c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e890 | SuspensionDamperForceAccumulation | accumulates damper force with 0.25 weight |
| 0043e980 | ClampedSpringIntegrator | accumulates spring force with 0.75 weight |

**Guard conditions:** no branches — always dispatches to both subsystems
