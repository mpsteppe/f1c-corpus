## BitmapDecompression_00513022 — BitmapDecompressWithChromaKey

**Summary:** Multi-phase bitmap decompression: phase 1 unpacks 1/2/4-bit packed pixels to bytes; phase 2 applies chroma-key transparency using a key-color table (a3). Handles both indexed and direct-color formats, outputting 2 or 4 bytes per pixel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51389E (0051389e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pixel count |
| this | 0x4 | RW | — | output byte count |
| this | 0x8 | RW | 4 | format/phase (0=unpack, 2=direct color convert, 4/6=set on completion) |
| this | 0x9 | RW | 8 | sub-state (1/2/4=bit depth unpack; 8/16=chroma-key format step) |
| this | 0xA | RW | 2 | bytes per pixel output |
| this | 0xB | RW | 8 | output stride/pitch |

**Written-by note (persistence):**
- this 0x4: written after each phase — survives until overwritten
- this 0x8: written to 4 or 6 on completion — survives until overwritten
- this 0x9: written to 8 after unpack, then checked again for chroma step — survives
- this 0xA: written to 2 or 4 — survives until overwritten
- this 0xB: written to final stride (8/16/32) — survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Condition | Value | Meaning |
|-----------|-------|---------|
| this+0x8 | == 0 | bit-unpacking path — expand 1/2/4-bit to 8-bit |
| this+0x8 | == 2 | direct-color path — convert 3/6-byte to 4/8-byte with chroma key |
| this+0x9 | < 8 | bit-unpack sub-state (1/2/4) |
| this+0x9 | == 8 | chroma-key on 8-bit indices (1-byte check) |
| this+0x9 | == 16 | chroma-key on 16-bit indices (2-byte check) |
| param a3 | != NULL | key table present — enables chroma-key processing |
| param a3 | == NULL | no key table — skip chroma-key (v4==0 path only) |

**Guard interpretation:** Outer dispatch on this+0x8. PASSES v4==0: bit-unpack (0x9 in {1,2,4}) then chroma-key if a3!=NULL (0x9 in {8,16}) → sets 0x8=4, 0xA=2. PASSES v4==2: requires a3!=NULL, then chroma-key convert (0x9==8: 3→4 bpp; 0x9==16: 6→8 bpp) → sets 0x8=6, 0xA=4. BLOCKED (early return) when v4 not in {0,2}.
