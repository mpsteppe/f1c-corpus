## SmallStructInitWithVtable_004b1970 — Small struct init with UITexture vtable

**Summary:** Constructor for small 5-dword object called from UIControlWindowInitialization. Sets UITextureVTable pointer from off_5ACBD8 at +0x00, initializes two range-bound pairs: first pair (0x4=0, 0x8=-1), second pair (0xC=0, 0x10=-1). Same layout as SmallStructConstructor_004b1950 but with different vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIControlWindowInitialization (004a70e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable/interface pointer from off_5ACBD8 (UITextureVTable) |
| this | 0x4 | RW | 0 | Range pair 1 minimum bound |
| this | 0x8 | RW | 18446744073709551615 | Range pair 1 maximum bound (-1 = unlimited) |
| this | 0xC | RW | 0 | Range pair 2 minimum bound |
| this | 0x10 | RW | 18446744073709551615 | Range pair 2 maximum bound (-1 = unlimited) |

**Written-by note (persistence):**
- this 0x0: once by constructor; survives external poke unless re-initialized
- this 0x4: once by constructor; survives external poke unless re-initialized
- this 0x8: once by constructor; survives external poke unless re-initialized
- this 0xC: once by constructor; survives external poke unless re-initialized
- this 0x10: once by constructor; survives external poke unless re-initialized

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acbd8 | off_5ACBD8 | R | UITextureVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional constructor with no branches.
