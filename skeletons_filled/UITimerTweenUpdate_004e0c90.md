## UITimerTweenUpdate_004e0c90 — UITimerTweenValueUpdate

**Summary:** Updates UI timer/tween countdown value by dt * 0.2 speed factor and applies result to UI element state. Part of UI animation/tween system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleGraphicsSceneLoader (004dfce0), SteeringForceWithRandom (004f0dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x894 | R | — | Active flag for the timer/tween |
| this | 0x930 | R | — | Current tween value being decremented |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b420 | TripleFieldQuery | Gets three UI element state pointers/IDs for value application |
| 0054b4d0 | sub_54B4D0 | Applies the computed interpolated value to UI state |

**Guard conditions:** Checks this+0x894 (timer active flag). If zero, skips entire update (returns without action). If non-zero, decrements this+0x930 by a2*0.2 and applies to UI.
