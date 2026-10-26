## FieldResetWithSubCall_005870e0 — Reset fields with sub-call initializer

**Summary:** Calls SimpleSetter_7500 on field at offset 0x4, then resets fields at offsets 0x10→0, 0x14→-1, 0x18→0, 0x19→0. Acts as a multi-field reset/initializer for a TaskBase-like struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 0 | Reset to zero |
| this | 0x14 | RW | 18446744073709551615 | Reset to -1 (all bits set) |
| this | 0x18 | RW | 0 | Reset to zero |
| this | 0x19 | RW | 0 | Reset to zero |

**Written-by note (persistence):**
- this 0x10: written 0 every call; external poke overwrites it
- this 0x14: written -1 every call; external poke overwrites it
- this 0x18: written 0 every call; external poke overwrites it
- this 0x19: written 0 every call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587500 | SimpleSetter_7500 | Called on field at offset 0x4 to perform sub-init |

**Guard conditions:** None — all operations execute unconditionally.
