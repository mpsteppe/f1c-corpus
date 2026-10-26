## ObjectFieldInitWithIndirectLookup_00499b80 — ConstructorWithIndirectOffsetLookup

**Summary:** Initializes several object fields, zeroing offsets 0x00 and 0x08, storing the `a2` parameter at offset 0x20, and conditionally reading two values through two-level pointer indirection (a2->[12]->[28] and a2->[12]->[32]) into offsets 0x04 and 0x0C. When a2 is NULL, those fields are zeroed instead.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileIconDFTBmpDefaultIconLoader (00478020)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | flag/field zeroed unconditionally |
| this | 0x4 | RW | 0 | field copied from a2->[12]->[28] if a2 non-NULL, else 0 |
| this | 0x8 | RW | 0 | flag/field zeroed unconditionally |
| this | 0xC | RW | — | field copied from a2->[12]->[32] if a2 non-NULL, else 0 via v3 default |
| this | 0x20 | RW | — | stores a2 parameter (source pointer) |

**Written-by note (persistence):**
- this 0x0: written once to 0; external poke survives
- this 0x4: written once from indirect lookup; external poke survives
- this 0x8: written once to 0; external poke survives
- this 0xC: written once from indirect lookup or 0; external poke survives
- this 0x20: written once to store a2; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 (second parameter) checked non-NULL — if non-NULL, offsets 0x04 and 0x0C populated via two-level indirect field read (a2+12 → +28, a2+12 → +32). If NULL, offset 0x04 zeroed, offset 0x0C defaulted to 0 via v3 init.
