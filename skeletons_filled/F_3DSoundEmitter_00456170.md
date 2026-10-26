## F_3DSoundEmitter_00456170 — F_3DSoundEmitter_Constructor

**Summary:** Constructor/initializer for a 3D sound emitter object — sets the vtable, copies a default application directory path string, and initializes all spatial parameters (cone angles, distances, volumes, flags) to their default values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraPositionDefinitions (00408870), CameraViewSystem (00408e20), F_3DTransformObjectAllocator (0040aa20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to ObjectConstructorVtable) |
| this | 0x4 | RW | 0 | internal state / ID field (dword, zeroed) |
| this | 0x8 | RW | 18446744073709551615 | handle / identifier (set to all-bits-set sentinel) |
| this | 0xC | RW | 0 | string buffer pointer (initialized via StringCopyWithBufferRealloc) |
| this | 0x10 | RW | 0 | field initialized by TripleFieldSetter (param 1) |
| this | 0x14 | RW | 0 | field initialized by TripleFieldSetter (param 2) |
| this | 0x18 | RW | 0 | field initialized by TripleFieldSetter (param 3) |
| this | 0x1C | RW | 0 | auxiliary field, zeroed |
| this | 0x20 | RW | 0 | auxiliary field, zeroed |
| this | 0x30 | RW | 1114636288 → 60.0f | inner cone angle (degrees) |
| this | 0x34 | RW | 1110704128 → 45.0f | outer cone angle (degrees) |
| this | 0x38 | RW | 1114636288 → 60.0f | max distance / far attenuation range |
| this | 0x3C | RW | 1110704128 → 45.0f | min distance / reference distance |
| this | 0x40 | RW | 1056964608 → 0.5f | volume / gain factor |
| this | 0x44 | RW | 1140457472 → 500.0f | doppler factor or distance scaling |
| this | 0x48 | RW | 1065353216 → 1.0f | rolloff factor / attenuation multiplier |
| this | 0x4C | RW | 1065353216 → 1.0f | pitch / playback rate multiplier |
| this | 0x50 | RW | 1065353216 → 1.0f | orientation weight / cone outside volume |
| this | 0x54 | RW | 1056964608 → 0.5f | cone outside volume / orientation blend |
| this | 0x58 | RW | 1056964608 → 0.5f | pan / balance parameter |
| this | 0x5C | RW | 0 | spatial flag or reserved (zeroed) |
| this | 0x60 | RW | 0 | byte flag at offset 96 (zeroed) |
| this | 0x64 | RW | 0 | reserved / padding field (zeroed) |
| this | 0x68 | RW | 0 | reserved / padding field (zeroed) |
| this | 0x6C | RW | 0 | reserved / padding field (zeroed) |
| this | 0x70 | RW | 0 | reserved field (zeroed) |
| this | 0x74 | RW | 0 | reserved field (zeroed) |
| this | 0x78 | RW | 0 | reserved field (zeroed) |
| this | 0x80 | RW | 0 | position X component or buffer (zeroed) |
| this | 0x84 | RW | 0 | position Y component or buffer (zeroed) |
| this | 0x88 | RW | 0 | velocity / direction X (zeroed) |
| this | 0x8C | RW | 0 | velocity / direction Y (zeroed) |
| this | 0x90 | RW | 0 | velocity / direction Z (zeroed) |
| this | 0x94 | RW | 0 | emission state or timer (zeroed) |
| this | 0x98 | RW | 0 | play count or instance ID (zeroed) |
| this | 0x9C | RW | 0 | loop flag or state (zeroed) |
| this | 0xA0 | RW | 0 | priority or channel (zeroed) |
| this | 0xA4 | RW | 0 | fade in/out parameter (zeroed) |
| this | 0xA8 | RW | 0 | occlusion / obstruction factor (zeroed) |
| this | 0xAC | RW | 0 | listener-relative flag or group ID (zeroed) |
| this | 0xB0 | RW | 0 | reserved field (zeroed) |
| this | 0xB4 | RW | 0 | reserved field (zeroed) |
| this | 0xB8 | RW | 0 | reserved field (zeroed) |
| this | 0xBC | RW | 0 | reserved field (zeroed) |
| this | 0xC0 | RW | 0 | reserved field (zeroed) |
| this | 0xC4 | RW | 0 | reserved field (zeroed) |

**Written-by note (persistence):**
- this 0x0: write-once constructor — external poke persists until next construction
- this 0x4: write-once constructor — external poke persists until next construction
- this 0x8: write-once constructor — external poke persists until next construction
- this 0xC: write-once constructor — external poke persists until next construction
- this 0x10: write-once constructor — external poke persists until next construction
- this 0x14: write-once constructor — external poke persists until next construction
- this 0x18: write-once constructor — external poke persists until next construction
- this 0x1C: write-once constructor — external poke persists until next construction
- this 0x20: write-once constructor — external poke persists until next construction
- this 0x30: write-once constructor — external poke persists until next construction
- this 0x34: write-once constructor — external poke persists until next construction
- this 0x38: write-once constructor — external poke persists until next construction
- this 0x3C: write-once constructor — external poke persists until next construction
- this 0x40: write-once constructor — external poke persists until next construction
- this 0x44: write-once constructor — external poke persists until next construction
- this 0x48: write-once constructor — external poke persists until next construction
- this 0x4C: write-once constructor — external poke persists until next construction
- this 0x50: write-once constructor — external poke persists until next construction
- this 0x54: write-once constructor — external poke persists until next construction
- this 0x58: write-once constructor — external poke persists until next construction
- this 0x5C: write-once constructor — external poke persists until next construction
- this 0x60: write-once constructor — external poke persists until next construction
- this 0x64: write-once constructor — external poke persists until next construction
- this 0x68: write-once constructor — external poke persists until next construction
- this 0x6C: write-once constructor — external poke persists until next construction
- this 0x70: write-once constructor — external poke persists until next construction
- this 0x74: write-once constructor — external poke persists until next construction
- this 0x78: write-once constructor — external poke persists until next construction
- this 0x80: write-once constructor — external poke persists until next construction
- this 0x84: write-once constructor — external poke persists until next construction
- this 0x88: write-once constructor — external poke persists until next construction
- this 0x8C: write-once constructor — external poke persists until next construction
- this 0x90: write-once constructor — external poke persists until next construction
- this 0x94: write-once constructor — external poke persists until next construction
- this 0x98: write-once constructor — external poke persists until next construction
- this 0x9C: write-once constructor — external poke persists until next construction
- this 0xA0: write-once constructor — external poke persists until next construction
- this 0xA4: write-once constructor — external poke persists until next construction
- this 0xA8: write-once constructor — external poke persists until next construction
- this 0xAC: write-once constructor — external poke persists until next construction
- this 0xB0: write-once constructor — external poke persists until next construction
- this 0xB4: write-once constructor — external poke persists until next construction
- this 0xB8: write-once constructor — external poke persists until next construction
- this 0xBC: write-once constructor — external poke persists until next construction
- this 0xC0: write-once constructor — external poke persists until next construction
- this 0xC4: write-once constructor — external poke persists until next construction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059efac | off_59EFAC | R | ObjectConstructorVtable [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456280 | TripleFieldSetter_6280 | initializes three consecutive dword fields at offsets 0x10–0x18 to zero |
| 00566650 | StringCopyWithBufferRealloc | copies the default application directory path into the sound emitter's string buffer |

**Guard conditions:** No guard conditions — this is a pure constructor with unconditional initialization of all fields.
