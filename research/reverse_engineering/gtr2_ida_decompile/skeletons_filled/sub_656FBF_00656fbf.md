## sub_656FBF_00656FBF — A1R5G5B5 unpacker to float4 (1-bit alpha)

**Summary:** Expands this[0x68] 16-bit A1R5G5B5 words from the buffer at this[0x20] (offset by a2/a3 strides) into float4 quads — the three 5-bit fields (bits 14-10, 9-5, 4-0) scaled by 1/31, alpha taken from bit 15 as 0.0 or 1.0 — then optionally runs the sub_650019 and sub_650286 post-passes over the produced block (gated by this[0x18] and this[0x10]).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | flag: non-zero runs the sub_650286 post-pass over the converted float4 block |
| this | 0x18 | R | — | flag: non-zero runs the sub_650019 post-pass over the converted float4 block |
| this | 0x20 | R | — | base pointer of the source buffer of 16-bit packed-color words (run address derived from it per span) |
| this | 0x60 | R | — | per-a2 stride in bytes (a2 * this[0x60] offsets the source address) |
| this | 0x64 | R | — | per-a3 stride in bytes (a3 * this[0x64] offsets the source address) |
| this | 0x68 | R | — | element count: loop bound (source advances 2 bytes per element) and rewind count for the block start (&a4[-4*this[0x68]]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0071be60 | flt_71BE60 | R | constant-pool float read by this function (the 5-bit channel scale, 1/31; folded to an inline literal in the decompiled C) — exact value/role unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00650019 | sub_650019 | post-pass over the converted float4 block, given this and the block start (&a4[-4*this[0x68]]) (gated by this[0x18]) |
| 00650286 | sub_650286 | second post-pass over the converted float4 block, given this and the block start (gated by this[0x10]) |

**Guard conditions:** The conversion loop runs this[0x68] times (end pointer = source + 2*this[0x68]); with this[0x68] == 0 it performs no iterations. After it: this[0x18] ≠ 0 → sub_650019(this, block start); this[0x10] ≠ 0 → sub_650286(this, block start). Neither post-pass runs when its flag is zero.
