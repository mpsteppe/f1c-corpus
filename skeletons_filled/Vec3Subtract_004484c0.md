## Vec3Subtract_004484c0 — Vec3Subtract

**Summary:** Element-wise subtraction of two structures (float + double + float) — result = a2 - a3. Used in triangle edge subdivision for collision geometry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RecursiveTriangleEdgeSubdivisionForCollision (0044aae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output float: a2.float0 - a3.float0 |
| this | 0x4 | RW | — | output double: a2.double4 - a3.double4 |
| this | 0xC | RW | — | output float: a2.float12 - a3.float12 |

**Written-by note (persistence):**
- this 0x0: overwritten every call; external poke survives
- this 0x4: overwritten every call; external poke survives
- this 0xC: overwritten every call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard. Unconditional element-wise subtract of two input pointers into output.
