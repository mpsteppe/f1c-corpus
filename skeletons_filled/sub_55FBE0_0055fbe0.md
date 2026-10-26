## sub_55FBE0_0055fbe0 — cube map struct zero-init + name set

**Summary:** Initializes a cube map texture struct: zeroes entire struct via helper, copies cube map filename string at base, then explicitly zeroes selected DWORD/byte fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53CBC0 (0053cbc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x10 | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x14 | RW | 0 | Cube map field (byte), explicitly zeroed |
| this | 0x114 | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x118 | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x11C | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x120 | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x124 | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x128 | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x12C | RW | 0 | Cube map field, explicitly zeroed |
| this | 0x130 | RW | 0 | Cube map field, explicitly zeroed |

**Written-by note (persistence):**
- this 0xC: written once at init; static init, no external runtime update expected
- this 0x10: written once at init; static init, no external runtime update expected
- this 0x14: written once at init (byte); static init, no external runtime update expected
- this 0x114: written once at init; static init, no external runtime update expected
- this 0x118: written once at init; static init, no external runtime update expected
- this 0x11C: written once at init; static init, no external runtime update expected
- this 0x120: written once at init; static init, no external runtime update expected
- this 0x124: written once at init; static init, no external runtime update expected
- this 0x128: written once at init; static init, no external runtime update expected
- this 0x12C: written once at init; static init, no external runtime update expected
- this 0x130: written once at init; static init, no external runtime update expected

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005dbc08 | aCubemas410 | R | CubeMapFileName [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-fill whole struct at this |

**Guard conditions:** None — no conditional branches; always executes full init sequence.
