## CollisionInvMassStore_00459950 — CollisionInvMassStore

**Summary:** Stores a mass value and its reciprocal (1/mass) into struct fields at offsets 0x180 and 0x188, then performs a reciprocal-division copy on a separate parameter. Part of collision/body initialization system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StructInitWithFloatConstantsAndSubCalls (0040e8f0), StructInitWithFloatConstantsAndSubCalls_e990 (0040e990), sub_40EA30 (0040ea30), CameraProjectionMatrixInitWithFloatConstants (0040eb30), UtilityFunction_ebd0 (0040ebd0), StructInitializerWithFloatConstants (0040ec70), SwitchBasedFloatProcessing (0040eec0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x180 | RW | — | Mass value (stored as double) |
| this | 0x188 | RW | — | Inverse mass (1.0 / mass, stored as double) |

**Written-by note (persistence):**
- this 0x180: recalc every frame — external poke does NOT persist
- this 0x188: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005697a0 | StructCopyWithReciprocalDivision | Perform reciprocal-division copy on parameter a3 (unknown specific usage) |

**Guard conditions:** No guard conditions — unconditionally stores mass and inverse mass, then calls StructCopyWithReciprocalDivision.
