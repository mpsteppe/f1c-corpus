## sub_5EFFC0_005effc0 — Font glyph quad emitter

**Summary:** Given a character code and screen position, looks up the 24-byte glyph record (records start at this+0xB8, index 32 = space) and either emits a 6-vertex textured quad into the dynamic vertex buffer at this+0xA8 or delegates to sprite helper sub_5E7540; returns the glyph advance/width. Part of the bitmap-font/text rendering path.

**Called by:** sub_5F0DD0 (005f0dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xA8) | 0x0 | RW | — | X coordinate (float) of the vertex being emitted |
| *(this+0xA8) | 0x4 | RW | — | Y coordinate (float) of the vertex being emitted |
| *(this+0xA8) | 0x8 | RW | 0 | Z coordinate (written 0) |
| *(this+0xA8) | 0xC | RW | 1065353216 → 1.0f | RHW/W component (written 1.0f) |
| *(this+0xA8) | 0x10 | RW | — | Vertex color, copied from this+0x54 |
| *(this+0xA8) | 0x14 | RW | — | U texture coordinate (glyph record +8 or +16) |
| *(this+0xA8) | 0x18 | RW | — | V texture coordinate (glyph record +12 or +20) |
| *(this+0xA8) | 0x1C | RW | — | Vertex stride boundary — the write pointer is advanced 28 bytes per vertex |
| this | 0x10 | R | — | Flags: bit0 = vertex-buffer path vs sprite-helper path; bit1 = per-glyph width/height bytes vs defaults |
| this | 0x54 | R | — | Vertex color DWORD copied into every emitted vertex |
| this | 0x5C | R | — | Value passed as argument 9 to sub_5E7540 (sprite path); role not determinable from this code |
| this | 0x64 | R | — | Default glyph width used when flag bit1 is clear |
| this | 0x68 | R | — | Default glyph height used when flag bit1 is clear |
| this | 0x7C | R | — | Glyph/character slot count; upper bound for the character code a2 |
| this | 0x84 | RW | — | Written with glyph record byte +7 (signed per-glyph advance/offset) after the vertex path |
| this | 0x98 | R | — | X scale factor applied to glyph position and advance |
| this | 0x9C | R | — | Y scale factor applied to glyph position |
| this | 0xA0 | RW | — | Vertex count of the dynamic vertex buffer; incremented by 6 per emitted glyph |
| this | 0xA8 | RW | — | Write pointer into the dynamic vertex buffer; advanced 28 bytes per vertex |
| this | 0xAC | R | — | Texture/buffer object pointer passed to the sprite draw helper sub_5E7540 |

**Written-by note (persistence):**
- *(this+0xA8) 0x0: appended for each vertex while the vertex path runs; an external poke survives until the buffer is written again (next vector-path glyph) or reused/reset by other code.
- *(this+0xA8) 0x4: same as 0x0 — rewritten per vertex on every vector-path glyph.
- *(this+0xA8) 0x8: rewritten (0) per vertex on every vector-path glyph.
- *(this+0xA8) 0xC: rewritten (1.0f) per vertex on every vector-path glyph.
- *(this+0xA8) 0x10: rewritten (color copy) per vertex on every vector-path glyph.
- *(this+0xA8) 0x14: rewritten per vertex on every vector-path glyph.
- *(this+0xA8) 0x18: rewritten per vertex on every vector-path glyph.
- *(this+0xA8) 0x1C: not an independent value — the region is revisited via the 28-byte pointer advance; overwritten by the next vertex emitted.
- this 0x84: written once per vector-path glyph (record byte +7); an external poke survives until the next vector-path glyph draws.
- this 0xA0: incremented by 6 per vector-path glyph; poke survives only until the next such draw (or an external reset of the buffer).
- this 0xA8: advanced by 28 per vertex (6 times per glyph) in the vector path; poke survives only until the next vertex emission.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16c8 | flt_6F16C8 | R | unknown (not visible in the decompiled body; possibly referenced by an inlined floating-point helper) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e7540 | sub_5E7540 | Sprite/tile draw helper for the non-vertex-buffer path — receives the texture object, glyph column/row, a5, position a3/a4, glyph width, glyph height-1, this+0x5C, 0, 0 |
| 0063099c | __ftol2 | Compiler helper converting the double advancement result to a 64-bit integer for the return value |

**Guard conditions:** `a2 < 0x20 || a2 >= *(this+124)`: if the character code is below 0x20 or at/above the slot count, the function returns 0 immediately (BLOCKED); otherwise it proceeds (PASS). `(*(this+16) & 1)`: SET → vector path (emit 6 vertices); clear → call sprite helper sub_5E7540. `(*(this+16) & 2)`: SET → glyph width/height come from record bytes +4/+5; clear → defaults this+0x64/this+0x68. `(a6 & 0x40)`: SET → scaling is skipped for the start coordinates, the end coordinate uses the raw (a3+width)+0.5 form, and the return becomes a scale-applied advance; clear → returns the raw record width byte (+4). `a6 >= 0`: when scaling applies, selects the scaled end coordinate (width*scale + start) versus the unscaled (a3+width)+0.5 form.
