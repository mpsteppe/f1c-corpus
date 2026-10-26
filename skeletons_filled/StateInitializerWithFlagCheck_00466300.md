## StateInitializerWithFlagCheck_00466300 — ScenePostInitWithFlagCheck

**Summary:** Post-initialization after scene load. Sets field 0x124 to -1.0, calls CUBESceneLoaderEntry and FieldSetterCall(2), runs sub_466350 and sub_466650, then conditionally calls sub_541CA0(1) if flag at 0xEC is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSceneLoadAndPositionTires (004681b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | R | — | flag at index 59, gates call to sub_541CA0 |
| this | 0x124 | RW | 18446744072627421184 → -1.0f | field 73, reset to -1.0 (disabled timer) |

**Written-by note (persistence):**
- this 0x124: overwritten to -1.0 every call. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466350 | sub_466350 | position/velocity update |
| 00466650 | sub_466650 | secondary physics update |
| 0048e8d0 | CUBESceneLoaderEntry | scene loader entry point |
| 004988a0 | FieldSetterCall | set field state, param 2 |
| 00541ca0 | sub_541CA0 | conditional extra init (called when this+0xEC is set) |

**Guard conditions:** If this+0xEC (field 59) is non-zero → call sub_541CA0(1) (PASS). Otherwise skipped (BLOCKED).
