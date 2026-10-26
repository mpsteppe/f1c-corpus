## RGBColorPacking_00448ee0 — Pack RGB color channels into DWORD

**Summary:** Packs three color channels from a collision body (byte at offset 0x19, second byte of `this` value, word at offset 0x1A) into a single DWORD and writes it to the output pointer. Used during mesh/vertex color setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44B110 (0044b110), BezierPatchTessellation (0044b370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x19 | R | — | Blue (or first) color channel byte |
| this | 0x1A | R | — | Red+Alpha (or combined) color word — packed as high 16 bits of output |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — unconditional pack and store.
