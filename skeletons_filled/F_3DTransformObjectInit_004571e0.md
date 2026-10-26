## F_3DTransformObjectInit_004571e0 — 3D transform object constructor/initializer

**Summary:** Constructor for a 3D transform/track object that sets up vtable pointer, copies a base directory path, and initializes ~40 fields to default values: FOV angles (60°/45°), zoom/speed scalars (1.0, 0.5), clip distances (500.0), and other transform parameters. Part of the 3D scene/camera object system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StaticCameraSceneLoader (0040b030), F_3DTransformObjectInit_83b0 (004583b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_59EFEC) |
| this | 0x4 | RW | 0 | zeroed integer field (likely object ID/index) |
| this | 0x8 | RW | 18446744073709551615 | invalid handle sentinel (-1) |
| this | 0xC | RW | 0 | zeroed state field |
| this | 0x10 | RW | 0 | zeroed state field |
| this | 0x14 | RW | 0 | zeroed state field |
| this | 0x18 | RW | 0 | zeroed state field |
| this | 0x1C | RW | 0 | zeroed state field |
| this | 0x20 | RW | 0 | zeroed state field |
| this | 0x24 | RW | 0 | zeroed state field |
| this | 0x28 | RW | 0 | zeroed state field |
| this | 0x2C | RW | 0 | zeroed state field |
| this | 0x30 | RW | 1114636288 → 60.0f | FOV horizontal or field-of-view angle |
| this | 0x34 | RW | 1110704128 → 45.0f | FOV vertical or secondary angle |
| this | 0x38 | RW | 1114636288 → 60.0f | duplicate FOV/reset value (same as 0x30) |
| this | 0x3C | RW | 1110704128 → 45.0f | duplicate secondary angle (same as 0x34) |
| this | 0x40 | RW | 1056964608 → 0.5f | zoom/camera speed scalar 0.5 |
| this | 0x44 | RW | 1140457472 → 500.0f | far clip distance or view range |
| this | 0x48 | RW | 1065353216 → 1.0f | x-axis scale factor 1.0 |
| this | 0x4C | RW | 1065353216 → 1.0f | y-axis scale factor 1.0 |
| this | 0x50 | RW | 1065353216 → 1.0f | z-axis scale factor 1.0 |
| this | 0x54 | RW | 1056964608 → 0.5f | dampening/interpolation factor 0.5 |
| this | 0x58 | RW | 1056964608 → 0.5f | second dampening factor 0.5 |
| this | 0x5C | RW | 0 | zeroed byte flag |
| this | 0x60 | RW | 0 | zeroed state field |
| this | 0x64 | RW | 0 | zeroed state field |
| this | 0x68 | RW | 0 | zeroed state field |
| this | 0x6C | RW | 0 | zeroed state field |
| this | 0x70 | RW | 1 | enabled/active flag defaulting to true |
| this | 0x74 | RW | 0 | zeroed state field |
| this | 0x78 | RW | 0 | zeroed state field |
| this | 0x7C | RW | 0 | zeroed state field |
| this | 0x80 | RW | 0 | zeroed state field |
| this | 0x84 | RW | 0 | zeroed state field |
| this | 0x88 | RW | 1103626240 → 25.0f | default speed or transition rate |
| this | 0x90 | RW | 0 | zeroed state field |
| this | 0x94 | RW | 0 | zeroed state field |
| this | 0x98 | RW | 0 | zeroed state field |
| this | 0x9C | RW | 0 | zeroed byte flag at end of struct |

**Written-by note (persistence):**
- this 0x0: set once at construction — external poke would overwrite vtable (unsafe)
- this 0x4: set once at construction — external poke survives until next construction
- this 0x8: set once at construction — external poke survives until next construction
- this 0xC: set once at construction — external poke survives until next construction
- this 0x10: set once at construction — external poke survives until next construction
- this 0x14: set once at construction — external poke survives until next construction
- this 0x18: set once at construction — external poke survives until next construction
- this 0x1C: set once at construction — external poke survives until next construction
- this 0x20: set once at construction — external poke survives until next construction
- this 0x24: set once at construction — external poke survives until next construction
- this 0x28: set once at construction — external poke survives until next construction
- this 0x2C: set once at construction — external poke survives until next construction
- this 0x30: set once at construction — external poke survives until next construction
- this 0x34: set once at construction — external poke survives until next construction
- this 0x38: set once at construction — external poke survives until next construction
- this 0x3C: set once at construction — external poke survives until next construction
- this 0x40: set once at construction — external poke survives until next construction
- this 0x44: set once at construction — external poke survives until next construction
- this 0x48: set once at construction — external poke survives until next construction
- this 0x4C: set once at construction — external poke survives until next construction
- this 0x50: set once at construction — external poke survives until next construction
- this 0x54: set once at construction — external poke survives until next construction
- this 0x58: set once at construction — external poke survives until next construction
- this 0x5C: set once at construction — external poke survives until next construction
- this 0x60: set once at construction — external poke survives until next construction
- this 0x64: set once at construction — external poke survives until next construction
- this 0x68: set once at construction — external poke survives until next construction
- this 0x6C: set once at construction — external poke survives until next construction
- this 0x70: set once at construction — external poke survives until next construction
- this 0x74: set once at construction — external poke survives until next construction
- this 0x78: set once at construction — external poke survives until next construction
- this 0x7C: set once at construction — external poke survives until next construction
- this 0x80: set once at construction — external poke survives until next construction
- this 0x84: set once at construction — external poke survives until next construction
- this 0x88: set once at construction — external poke survives until next construction
- this 0x90: set once at construction — external poke survives until next construction
- this 0x94: set once at construction — external poke survives until next construction
- this 0x98: set once at construction — external poke survives until next construction
- this 0x9C: set once at construction — external poke survives until next construction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059efec | off_59EFEC | R | VTable_ObjectBase [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copy default directory path into object's string buffer |

**Guard conditions:** No conditional branches — all fields are unconditionally initialized. The function is a straight-line constructor with no guards.
