## FlagFieldBitManipulation_0054c030 — Flag field bit manipulation with recursive propagation

**Summary:** Sets or clears bits 1 (0x2) and 2 (0x4) in flag field at offset 0x3C based on parameters `a2` and `a3`. Optionally propagates the operation to linked child objects when `a4==1`.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_45A8E0 (0045a8e0), VehicleSceneLoadAndPositionTires (004681b0), ModeDependentSubsystemCall (004a2770), PitCrewAnimationLoader (004a2a90), ShortComputation_3fe0 (004a3fe0), UtilityFunction_4000 (004a4000), CollisionAvoidanceCheck (004a6b80), VehicleVisibilityCulling (004b3dc0), sub_4D1670 (004d1670), VehicleGraphicsSceneLoader (004dfce0), ConditionalResourceRelease (004e0d70), ArrayEntryCleanup (004e0e20), SubslotCleanup (004e0e70), AudioSoundEffectController (004e0ed0), VehicleStateUpdate_19d0 (004e19d0), CameraViewportRenderSetup (004fbd70), sub_5503A0 (005503a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | RW | — | Flags field; bit 1 = 0x2, bit 2 = 0x4 |
| this | 0x44 | R | — | First child/sub-object pointer (for recursive propagation) |
| this | 0x4C | R | — | Second child/sub-object pointer (for recursive propagation when a5 set) |

**Written-by note (persistence):**
- this 0x3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c030 | FlagFieldBitManipulation | Recursive self-call to propagate to child objects |

**Guard conditions:** Recursion: only when `a4==1` AND the child pointer is non-null. Bit manipulation: when `a2` is 1 → clear bit 1; when `a2` is 0 → set bits 1 and 2; otherwise skip. When `a3` is 1 → clear bit 2; when `a3` is 0 → set bit 2; otherwise skip.
