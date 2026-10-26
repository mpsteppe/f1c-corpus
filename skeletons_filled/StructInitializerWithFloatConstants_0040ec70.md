## StructInitializerWithFloatConstants_0040ec70 — PhysicsStructInitWithFloatConstants

**Summary:** Initializes a physics/collision-related struct: writes two caller-supplied values and constant 5 to fields, builds a float-array of 2D offset vectors (Y-only non-zero), then stores collision mass data, bulk-sets 6 float constants, and conditionally runs a short computation if a4 non-zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | caller-supplied __int16 identifier/flag |
| this | 0x1C | RW | 5 | physics parameter count or type constant |
| this | 0x20 | RW | — | caller-supplied int parameter (a3) |

**Written-by note (persistence):**
- this 0x8: written once per call with a2; persists until next call that overwrites it
- this 0x1C: written once per call with constant 5; persists until next call
- this 0x20: written once per call with a3; persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e770 | ShortComputation_e770 | conditional short computation on this struct when a4 is non-zero |
| 00459950 | CollisionInvMassStore | stores collision inverse mass data with float 10.0 and vector array |
| 00459990 | F_6FieldBulkSetter | bulk-sets 6 float fields on this struct to physics constants |

**Guard conditions:** if a4 (4th param) is zero → skip ShortComputation_e770 call; non-zero → execute it with (this, a4, 0)
