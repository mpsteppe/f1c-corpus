## ConditionalDelegateDispatch_004d1100 — GridPositionConditionalCopy

**Summary:** If grid position index (this[0x48A4]) is unset (< 0), recalculate via sub_4C6F10. Then copy grid position data from setup scene via ArrayOfStructIndexedFieldCopy.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0), PitCrewAnimationLoader (004a2a90), AIStateMachineWithModeDispatch (004a5d10), SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48A4 | R | — | allocated grid position index (-1 = unset) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403f70 | ArrayOfStructIndexedFieldCopy | copy grid slot position data from setup scene |
| 004c6f10 | sub_4C6F10 | allocate/find a free grid position for this vehicle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x48A4 | < | 0 | grid position index < 0 means unallocated |

**Guard interpretation:** Passes (recalculates) when this[0x48A4] < 0 (no grid slot allocated yet). After recalculation, always copies data. If index >= 0, skips sub_4C6F10 and copies directly.
