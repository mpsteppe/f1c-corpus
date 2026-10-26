## ComponentTransformInitializer_00459010 — TransformComponentInit

**Summary:** Initializes a transform/physics component to default state. Zeros position/transform fields via StructFieldCopy, sets counter/state fields (0xBC=0, 0xCC=0), sets scale factor (0xAC=1.0f), copies initial position to saved slot at 0x90 via VectorCopy, and sets active flag (0xA0=1).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA0 | RW | 1 | active flag: set to 1 to mark component as initialized/active |
| this | 0xAC | RW | 1065353216 → 1.0f | scale factor / multiplier field |
| this | 0xBC | RW | 0 | counter or state field, zero-initialized |
| this | 0xCC | RW | 0 | byte field, zero-initialized |

**Written-by note (persistence):**
- this 0xA0: written once to 1. Survives until externally modified.
- this 0xAC: written once to 1.0f. Survives until externally modified.
- this 0xBC: written once to 0. Survives until externally modified.
- this 0xCC: written once to 0. Survives until externally modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456130 | VectorCopy | copy initial position/transform from base to saved slot at offset 0x90 |
| 00456150 | StructFieldCopy | zero-initialize base struct fields (position/velocity) from zero vector |

**Guard conditions:** None — unconditional initialization of all fields.
