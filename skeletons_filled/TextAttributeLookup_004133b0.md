## TextAttributeLookup_004133b0 — TextAttributeFieldLookup

**Summary:** Looks up text attribute string and metadata from a linked-list node indexed by a3. Selects one of 4 field offsets within the node based on a2 (0/1) and a4 (0/1). Copies string path and three metadata fields (offset 8, 12, 16) to output a1. Returns 1 if any output differs from default sentinel values, -1 if all match defaults (string==default path, metadata==-1,-1, byte==0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceEventMessageDispatcher (00411bf0), SoundEventDispatcher (00411e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to string path (may be null → defaults to byte_5EA438) |
| this | 0x8 | RW | — | first metadata field (compared to -1 as sentinel) |
| this | 0xC | RW | — | second metadata field (compared to -1 as sentinel) |
| this | 0x10 | RW | — | third metadata byte (checked for non-zero) |

**Written-by note (persistence):**
- this 0x8: written each call with field from source node; persists until overwritten
- this 0xC: written each call with field from source node; persists until overwritten
- this 0x10: written each call with byte from source node; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — default file path used when string pointer is null |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] — unknown reference |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415680 | LinkedListIndexedAccessor_5680 | accesses linked-list node by index a3 |
| 00566650 | StringCopyWithBufferRealloc | copies file path string from source to buffer |
| 00587bcf | FreeWrapper_7bcf | frees memory (used for previous string) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 18446744073709551615 | sentinel: first metadata == -1 |
| this | 0xC | == | 18446744073709551615 | sentinel: second metadata == -1 |

**Guard interpretation:** if (string==default && metadata[0]==-1 && metadata[1]==-1 && byte==0) → return -1 (all defaults, no match found). Otherwise → return 1 (data found).
