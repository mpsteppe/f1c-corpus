## F_3DTransformWithSIMD_00534120 — MMX subband synthesis transform

**Summary:** MMX-accelerated subband synthesis / IMDCT transform for audio decoder. Takes 8 __m64 input values, computes sum/difference pairs, applies 32 stages of pmaddwd matrix multiplication with constant tables (unk_8D7200–unk_8D73F8, qword_8D7000), writes 272 16-bit output words to two buffers (a1[0..256], a2[0..240]). Core polyphase filter bank computation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioResampler (00532aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output buffer slot 0 (a1[0], first transform result word) |
| this | 0x20 | RW | — | output buffer slot at stride 32 bytes (a1[16]) |
| this | 0x40 | RW | — | output buffer slot at stride 64 bytes (a1[32]) |
| this | 0x60 | RW | — | output buffer slot at stride 96 bytes (a1[48]) |
| this | 0x80 | RW | — | output buffer slot at stride 128 bytes (a1[64]) |
| this | 0xA0 | RW | — | output buffer slot at stride 160 bytes (a1[80]) |
| this | 0xC0 | RW | — | output buffer slot at stride 192 bytes (a1[96]) |
| this | 0xE0 | RW | — | output buffer slot at stride 224 bytes (a1[112]) |
| this | 0x100 | RW | — | output buffer slot at stride 256 bytes (a1[128]) |
| this | 0x120 | RW | — | output buffer slot at stride 288 bytes (a1[144]) |
| this | 0x140 | RW | — | output buffer slot at stride 320 bytes (a1[160]) |
| this | 0x160 | RW | — | output buffer slot at stride 352 bytes (a1[176]) |
| this | 0x180 | RW | — | output buffer slot at stride 384 bytes (a1[192]) |
| this | 0x1A0 | RW | — | output buffer slot at stride 416 bytes (a1[208]) |
| this | 0x1C0 | RW | — | output buffer slot at stride 448 bytes (a1[224]) |
| this | 0x1E0 | RW | — | output buffer slot at stride 480 bytes (a1[240]) |
| this | 0x200 | RW | — | output buffer slot at stride 512 bytes (a1[256]) |

**Written-by note (persistence):**
- this 0x0 through this 0x200: all output slots overwritten every call; no persistent state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d7000 | qword_8D7000 | R | PMADDWDConstants [DERIVED] — 26× constant tables for pmaddwd (second half of transform) |
| 008d7200 | unk_8D7200 | R | VertexTransformConstants [DERIVED] — pmaddwd coefficient tables (first half of transform) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches. Always computes all 272 output words unconditionally.
