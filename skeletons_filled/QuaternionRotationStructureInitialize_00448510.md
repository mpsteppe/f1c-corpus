## QuaternionRotationStructureInitialize_00448510 — QuaternionRotationStructureInitialize

**Summary:** Initializes a quaternion/rotation structure (0x60 bytes): copies first 4 dwords from input source, duplicates axes 2 and 3 into offsets +0x10 and +0x14, zeroes a 0x2C-byte block (offsets 0x1C-0x47), sets sentinel at +0x48 to -1, and zeroes remaining fields. Called from spatial tree and mesh adjacency builder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpatialTreeInsertion (004485d0), TriangleMeshAdjacencyBuilder (004493a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | quaternion/rotation component 0 (copied from a2[0]) |
| this | 0x4 | W | — | quaternion/rotation component 1 (copied from a2[1]) |
| this | 0x8 | W | — | quaternion/rotation component 2 (copied from a2[2]) |
| this | 0xC | W | — | quaternion/rotation component 3 (copied from a2[3]) |
| this | 0x10 | W | — | duplicate of component 1 (a2[1]) |
| this | 0x14 | W | — | duplicate of component 2 (a2[2]) |
| this | 0x18 | W | 0 | zeroed field |
| this | 0x48 | W | 18446744073709551615 | sentinel (-1, 0xFFFFFFFF) |
| this | 0x4C | W | 0 | zeroed field |
| this | 0x50 | W | 0 | zeroed field |
| this | 0x54 | W | 0 | zeroed field |
| this | 0x58 | W | 0 | zeroed field |
| this | 0x5C | W | 0 | zeroed field |

**Written-by note (persistence):**
- this 0x0: set from input; external poke survives (only written once)
- this 0x4: set from input; external poke survives
- this 0x8: set from input; external poke survives
- this 0xC: set from input; external poke survives
- this 0x10: set from a2[1]; external poke survives
- this 0x14: set from a2[2]; external poke survives
- this 0x18: set to 0 every call; external poke overwritten
- this 0x48: set to -1 every call; external poke overwritten
- this 0x4C: set to 0 via memset; external poke overwritten
- this 0x50: set to 0 via memset; external poke overwritten
- this 0x54: set to 0 via memset; external poke overwritten
- this 0x58: set to 0 via memset; external poke overwritten
- this 0x5C: set to 0 via memset; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard. Unconditional initialization from input a2.
