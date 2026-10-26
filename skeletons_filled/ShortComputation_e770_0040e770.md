## ShortComputation_e770_0040e770 — ShortComputation_e770

**Summary:** Multi-mode dispatch function: toggles scene node visibility, optionally calls audio-physics mixing for modes 0-2, computes dual matrix transform, dispatches virtual method on sub-object with matrix data write, then calls cleanup subroutines. Part of camera/view/scene graph system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StructInitWithFloatConstantsAndSubCalls (0040e8f0), StructInitWithFloatConstantsAndSubCalls_e990 (0040e990), sub_40EA30 (0040ea30), CameraProjectionMatrixInitWithFloatConstants (0040eb30), UtilityFunction_ebd0 (0040ebd0), StructInitializerWithFloatConstants (0040ec70), WheelControllerInputDecoder (00410bc0), ShortComputation_1330 (00411330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x0 | R | — | Virtual method table on sub-object (called with vtable+0) |
| this | 0x1C | R | — | Mode selector (this[7], values 0-5) for dispatch and audio-mix guard |
| this | 0x20 | RW | — | Pointer to sub-object with vtable and matrix storage space |
| this | 0x24 | RW | — | Matrix field X1 (v8[1]) written after virtual dispatch |
| this | 0x28 | RW | — | Matrix field Y1 (v8[2]) written after virtual dispatch |
| this | 0x2C | RW | — | Matrix field Z1/X2 (v8[3]) written after virtual dispatch |
| this | 0xF0 | RW | — | Field written by sub_40ED10 subroutine |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040e83c | jpt_40E7C4 | R | Jump table for 5-case mode switch (0-5) |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e2b0 | AudioPhysicsMixWithLerp | Physics/audio mixing (called for modes 0-2) |
| 0040ed10 | sub_40ED10 | Subroutine operating on this struct |
| 004be010 | sub_4BE010 | Cleanup subroutine (called when a3 == 0) |
| 0054b530 | DualMatrixTransformMultiply | Computes dual matrix transform (6 output values) |
| 0054fb40 | SceneNodeVisibilityToggle | Toggles scene node visibility |

**Guard conditions:** this[7] (mode, offset 0x1C) <= 2 → call AudioPhysicsMixWithLerp with mode as parameter. Switch on this[7]: case 0-5 → store a2 in sub-object + virtual dispatch + matrix write. case 0 uses different virtual dispatch pattern than 1-5. default → skip. a3 == 0 → call sub_4BE010 cleanup.
