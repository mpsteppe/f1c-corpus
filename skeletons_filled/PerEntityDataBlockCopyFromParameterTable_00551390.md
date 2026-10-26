## PerEntityDataBlockCopyFromParameterTable_00551390 — PerEntityDataCopyFromParameterTable

**Summary:** Copies parameter data from a parameter table into per-entity data blocks (136-byte stride) based on indexed entries, sets a flag, and optionally clears a bitmask on the source.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityFlagSetSubInitChain (00551440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Flags field — bit 0x10000 set after data copy completes |
| this | 0x8 | RW | — | Entity data index (clamped to parameter table max) |
| this | 0x14 | R | — | Number of per-entity data blocks to process (loop count) |
| this | 0x18 | R | — | Base pointer to per-entity data block array (136-byte stride) |
| this | 0x1C | R | — | Pointer to parameter table struct |
| this | 0x2C | R | — | Parameter table field |
| this | 0x30 | R | — | Parameter table field |
| this | 0x4C | RW | — | Per-entity data field (copied from parameter table entry+4) |
| this | 0x50 | RW | — | Per-entity data field (copied from parameter table entry+8) |
| this | 0x54 | RW | — | Per-entity data field (copied from parameter table entry+12) |

**Written-by note (persistence):**
- this 0x4: OR-ed with 0x10000 on every call; external poke may survive (bitwise OR)
- this 0x8: Written unconditionally (clamped); external poke overwritten
- this 0x4C: Written from parameter table; external poke overwritten on next copy
- this 0x50: Written from parameter table; external poke overwritten on next copy
- this 0x54: Written from parameter table; external poke overwritten on next copy

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b4c0 | sub_53B4C0 | Copy 4 consecutive floats (16 bytes) from parameter table to entity data block |
| 0054b330 | BitmaskClear | Clear bitmask at a2+312 (64 bits, offset 32) when a2 is non-null |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x18 | != | 255 | Byte tag within each data block — if 255, skip block (invalid/unused) |

**Guard interpretation:** 
- *(uint8_t*)v5 == 255 (entry tag byte): skip that data block — no copy performed. PASS when != 255 (copy runs).
