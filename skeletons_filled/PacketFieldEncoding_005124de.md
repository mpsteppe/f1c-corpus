## PacketFieldEncoding_005124de — Encode packet format fields from state flags

**Summary:** Reads session state flags (bits at offsets 0x60/0x61) and configures an output packet header's encoding type, bit depth, channel count, and total size; copies camera rotation data when video flag is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDispatchWithGuard (00511b5c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | flags DWORD; bits 0x40 and 0x4 control encoding type modifiers |
| this | 0x61 | R | — | flags byte; bits 0x10, 0x20, 0x4, and sign bit control packet format fields |
| this | 0x10A | R | — | WORD checked for non-zero; controls encoding type branching |
| this | 0x130 | R | — | DWORD (camera rotation float) copied to packet when bit 0x20 set |
| this | 0x174 | R | — | DWORD pointer checked for non-null; gates encoding type override to 3 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x61 | < | 0 | sign bit (bit 7) of flags byte; controls stride increment |
| this | 0x10A | != | 0 | WORD at offset 0x10A (camera rotation flag); modifies encoding type |

**Guard interpretation:** When bit 0x10 of flags byte (0x61) is SET, packet encoding type at a2+25 is modified based on WORD at offset 0x10A. When bit 0x20 is SET, float at 0x130 is copied to packet. When bit 0x4 of flags byte is SET AND packet bit-depth is 16, downgrades to 8. When bit 0x40 of flags DWORD (0x60) is SET AND encoding type is 2 or 6 AND pointer at 0x174 is non-null AND bit-depth is 8, overrides encoding type to 3. When bit 0x4 of flags DWORD is SET AND packet bit-depth < 8, forces bit-depth to 8. Sign bit of flags byte adds 1 to channel count when encoding type is 0 or 2.
