## F_3DTransformObjectAllocator_0040aa20 — 3D Transform Object Allocator

**Summary:** Lazily allocates up to 5 3D sound/transform objects via F_3DSoundEmitter (4 fixed 200-byte + one 204-byte variant), initializing rotation angles to 360.0f and default transform parameters. Ensures each sub-object is allocated exactly once.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40C140 (0040c140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x1C | R | — | Zeroed transform parameter within the 5th sub-object |
| this | 0x10 | RW | 1135869952 → 360.0f | 1st sub-object pointer (lazy alloc); its offset +0x88 stores rotation angle |
| this | 0x14 | RW | 1135869952 → 360.0f | 2nd sub-object pointer (lazy alloc) |
| this | 0x18 | RW | 1135869952 → 360.0f | 3rd sub-object pointer (lazy alloc) |
| this | 0x1C | RW | 1135869952 → 360.0f | 4th sub-object pointer (lazy alloc) |
| this | 0x20 | RW | — | 5th sub-object pointer (204-byte variant with refcount, lazy alloc) |
| this | 0xA8 | RW | 1135869952 → 360.0f | Rotation angle X in sub-object (at subobject+0x88) |
| this | 0xAC | RW | 1135869952 → 360.0f | Rotation angle Y in sub-object |
| this | 0xB0 | RW | 1135869952 → 360.0f | Rotation angle Z in sub-object |

**Written-by note (persistence):**
- this 0x10: Written once when null (lazy init). External poke survives after first allocation since subsequent calls skip if non-null.
- this 0x14: Same lazy-init pattern.
- this 0x18: Same lazy-init pattern.
- this 0x1C: Same lazy-init pattern.
- this 0x20: Same lazy-init pattern (204-byte variant).
- this 0xA8: Written once per sub-object at allocation, set to 360.0f. Not touched on subsequent calls.
- this 0xAC: Same as 0xA8.
- this 0xB0: Same as 0xA8.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default file path string copied by StringCopyWithBufferRealloc |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456170 | F_3DSoundEmitter | Initializes a 200-byte 3D sound/transform object |
| 00566650 | StringCopyWithBufferRealloc | Copies default path string into allocated object |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates heap memory (200 or 204 bytes) |

**Guard conditions:** Each this[4..8] checked for null before allocation. If already non-null, that sub-object is skipped. After allocation, writes 360.0f to three rotation fields at subobject+0x88, +0x8C, +0x90.
