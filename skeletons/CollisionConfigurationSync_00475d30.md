## CollisionConfigurationSync_00475d30 — CollisionConfigSyncOnFrameChange

**Summary:** Compares stored collision config version against current frame counter; if different, updates version and synchronizes collision parameters (contact stiffness, collision arrays, module data) via physics configuration functions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DRectangleDrawingWithOutline (00475d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] — physics module pointer array |
| 007cd2b0 | flt_7CD2B0 | R | CollisionParamArrayA [DERIVED] — collision parameter set A |
| 007cd458 | flt_7CD458 | R | ContactStiffnessArray [DERIVED] — contact stiffness parameters |
| 007cd45c | flt_7CD45C | R | CollisionParamArray [DERIVED] — collision parameters |
| 007cd610 | flt_7CD610 | R | CollisionParamArray3 [DERIVED] — collision parameter set 3 |
| 007cd614 | dword_7CD614 | RW | CollisionConfigVersion [DERIVED] — stored version for change detection |
| 007ce250 | dword_7CE250 | R | CollisionConfigVersion [DERIVED] — current frame counter/version |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] — passed as float parameter to collision config |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00454da0 | sub_454DA0 | Configures collision parameters (stiffness, contact, collision arrays) |
| 00455bd0 | ShortComputation_5bd0 | Computes/updates physics module data from pointer array |

**Guard conditions:** Sync block (lines 8-12) PASSES only when dword_7CD614 != dword_7CE250 (version changed). If equal (no change), BLOCKED — nothing executed.
