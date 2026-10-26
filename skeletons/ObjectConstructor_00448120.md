## ObjectConstructor_00448120 — Object constructor with D3D state initialization

**Summary:** Constructs an object by zeroing field at offset 0x4 (initialization flag or reference counter) and initializing Direct3D rendering state. Called by Steward_Init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Init (004d38f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | initialization flag or reference counter zeroed at construction |

**Written-by note (persistence):**
- this 0x4: unconditional — external poke overwritten every call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004482d0 | D3DStateInit | initializes Direct3D rendering state for the object |

**Guard conditions:** None — always executes fully, no conditional branches.
