## F_3DTransformObjectInit_83b0_004583b0 — Camera 3D Node Initialization

**Summary:** Initializes a 3D camera/transform node object — calls base transform init, zeroes sub-struct, sets vtable, copies a resource path string, and fills default camera parameters (FOV, near/far clip, scale, mode).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainView (0040b850), sub_4348B0 (004348b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to CameraNode vtable from off_59F00C) |
| this | 0xC | RW | 0 | transform/state field (zeroed) |
| this | 0x10 | RW | 0 | transform/state field (zeroed) |
| this | 0x14 | RW | 0 | transform/state field (zeroed) |
| this | 0x18 | RW | 0 | transform/state field (zeroed) |
| this | 0x1C | RW | 0 | transform/state field (zeroed) |
| this | 0x20 | RW | 0 | transform/state field (zeroed) |
| this | 0x24 | RW | 0 | transform/state field (zeroed) |
| this | 0x28 | RW | 0 | transform/state field (zeroed) |
| this | 0x2C | RW | 0 | transform/state field (zeroed) |
| this | 0x30 | RW | 1114636288 → 60.0f | horizontal FOV (degrees) |
| this | 0x34 | RW | 1110704128 → 45.0f | vertical FOV (degrees) |
| this | 0x38 | RW | 1114636288 → 60.0f | horizontal FOV copy / backup |
| this | 0x3C | RW | 1110704128 → 45.0f | vertical FOV copy / backup |
| this | 0x40 | RW | 1056964608 → 0.5f | aspect ratio or viewport fraction |
| this | 0x44 | RW | 1140457472 → 500.0f | far clipping plane distance |
| this | 0x48 | RW | 1065353216 → 1.0f | X-axis scale factor |
| this | 0x4C | RW | 1065353216 → 1.0f | Y-axis scale factor |
| this | 0x50 | RW | 1065353216 → 1.0f | Z-axis scale factor |
| this | 0x54 | RW | 1056964608 → 0.5f | parameter / damping factor |
| this | 0x58 | RW | 1056964608 → 0.5f | parameter / damping factor (copy) |
| this | 0x5C | RW | 0 | state field (zeroed) |
| this | 0x60 | RW | 0 | byte flag / state (zeroed) |
| this | 0x64 | RW | 0 | state field (zeroed) |
| this | 0x68 | RW | 0 | state field (zeroed) |
| this | 0x6C | RW | 0 | state field (zeroed) |
| this | 0x70 | RW | 2 | camera mode / projection type (2 = perspective) |
| this | 0x74 | RW | 0 | state field (zeroed) |
| this | 0x78 | RW | 0 | state field (zeroed) |
| this | 0x7C | RW | 0 | state field (zeroed) |
| this | 0x80 | RW | 0 | state field (zeroed) |
| this | 0x84 | RW | 0 | state field (zeroed) |
| this | 0x88 | RW | 1103626240 → 25.0f | near clipping plane distance |
| this | 0x90 | RW | 0 | state field (zeroed) |
| this | 0x94 | RW | 0 | state field (zeroed) |
| this | 0x98 | RW | 0 | state field (zeroed) |
| this | 0x9C | RW | 0 | byte flag (zeroed) |
| this | 0xA0 | RW | 0 | byte flag (zeroed) |
| this | 0xA4 | RW | 0 | state field (zeroed) |
| this | 0xA8 | RW | 0 | state field (zeroed) |
| this | 0xAC | RW | 1065353216 → 1.0f | multiplier / weight factor |

**Written-by note (persistence):**
- this 0x0: init once — external poke persists until object reinit
- this 0xC: init once — external poke persists until reinit
- this 0x10: init once — external poke persists until reinit
- this 0x14: init once — external poke persists until reinit
- this 0x18: init once — external poke persists until reinit
- this 0x1C: init once — external poke persists until reinit
- this 0x20: init once — external poke persists until reinit
- this 0x24: init once — external poke persists until reinit
- this 0x28: init once — external poke persists until reinit
- this 0x2C: init once — external poke persists until reinit
- this 0x30: init once — external poke persists until reinit
- this 0x34: init once — external poke persists until reinit
- this 0x38: init once — external poke persists until reinit
- this 0x3C: init once — external poke persists until reinit
- this 0x40: init once — external poke persists until reinit
- this 0x44: init once — external poke persists until reinit
- this 0x48: init once — external poke persists until reinit
- this 0x4C: init once — external poke persists until reinit
- this 0x50: init once — external poke persists until reinit
- this 0x54: init once — external poke persists until reinit
- this 0x58: init once — external poke persists until reinit
- this 0x5C: init once — external poke persists until reinit
- this 0x60: init once — external poke persists until reinit
- this 0x64: init once — external poke persists until reinit
- this 0x68: init once — external poke persists until reinit
- this 0x6C: init once — external poke persists until reinit
- this 0x70: init once — external poke persists until reinit
- this 0x74: init once — external poke persists until reinit
- this 0x78: init once — external poke persists until reinit
- this 0x7C: init once — external poke persists until reinit
- this 0x80: init once — external poke persists until reinit
- this 0x84: init once — external poke persists until reinit
- this 0x88: init once — external poke persists until reinit
- this 0x90: init once — external poke persists until reinit
- this 0x94: init once — external poke persists until reinit
- this 0x98: init once — external poke persists until reinit
- this 0x9C: init once — external poke persists until reinit
- this 0xA0: init once — external poke persists until reinit
- this 0xA4: init once — external poke persists until reinit
- this 0xA8: init once — external poke persists until reinit
- this 0xAC: init once — external poke persists until reinit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f00c | off_59F00C | R | VTable_CameraNode [DERIVED] |
| 005ea438 | byte_5EA438 | R | resource directory/file path string for camera | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004571e0 | F_3DTransformObjectInit | initializes base 3D transform object fields (position, rotation, matrix) |
| 00457cd0 | StructFieldZeroInit | zeros sub-structure at offset 0xB0 within the camera node |
| 00566650 | StringCopyWithBufferRealloc | copies a resource path string (e.g., directory or file path) into the object |

**Guard conditions:** None — pure initialization function with no conditional branches. All fields are written unconditionally on every call.
