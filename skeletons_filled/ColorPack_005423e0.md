## ColorPack_005423e0 — Pack RGB color components into DWORD

**Summary:** Packs three byte-like values (a2, a3, a4) into a single 32-bit value as (a2<<16 | a3<<8 | a4) and stores result at offset 0x7C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_548AD0 (00548ad0), sub_55A060 (0055a060), sub_560C10 (00560c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | RW | — | packed RGB color value |

**Written-by note (persistence):**
- this 0x7C: overwritten with packed RGB each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes.
