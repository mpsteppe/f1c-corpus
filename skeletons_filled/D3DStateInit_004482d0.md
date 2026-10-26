## D3DStateInit_004482d0 — D3DRenderStateReset

**Summary:** Resets D3D render state structure: releases vtable-bound object at offset +4 via its destructor/release method (first vtable entry), zeroes most fields, and sets state mask at offset +0x18 to 0xFF7FFFFF. Called from both constructor and post-init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructor (00448120), Steward_Post (004d4600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | function table of object at this[1]; first entry invoked (release/reset call) |
| this | 0x0 | RW | 0 | D3D state handle/cookie, zeroed to invalid |
| this | 0x4 | RW | 0 | pointer to D3D vtable object, released then set null |
| this | 0x8 | RW | 0 | D3D state parameter, zeroed |
| this | 0xC | RW | 0 | D3D state parameter, zeroed |
| this | 0x10 | RW | 0 | D3D state parameter, zeroed |
| this | 0x18 | RW | 18446744073701163007 | D3D render state mask/flags (0xFF7FFFFF, clears bit 23) |

**Written-by note (persistence):**
- this 0x0: set to 0 every call; external poke survives (not re-read)
- this 0x4: released then set to 0 every call; external poke would leak
- this 0x8: set to 0 every call; external poke survives
- this 0xC: set to 0 every call; external poke survives
- this 0x10: set to 0 every call; external poke survives
- this 0x18: set to 0xFF7FFFFF every call; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this+0x4 (vtable pointer) must be non-null to trigger object release via first vtable entry. When null, release is skipped.
