## SessionStringNameLookup_004122c0 — SessionStringFieldLookup

**Summary:** Looks up a string and three metadata fields (offset 8, 12, 16) from a session linked-list node indexed by a3. Has two paths: (1) if camera flag off and championship mode, extracts vehicle data (v7+124); (2) otherwise reads one of 8 field offsets within the node selected by (a2, a4, a5). Copies string path and fields to output a1. If all outputs match default sentinel values, optionally does further processing via LinkedListIndexScannerWithValidation and TextAttributeLookup_34d0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceEventMessageDispatcher (00411bf0), SoundEventDispatcher (00411e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to string path (may be null → defaults to byte_5EA438) |
| this | 0x8 | RW | — | first metadata field (compared to -1 as sentinel) |
| this | 0xC | RW | — | second metadata field (compared to -1 as sentinel) |
| this | 0x10 | RW | — | third metadata field (byte, checked for non-zero) |

**Written-by note (persistence):**
- this 0x8: written each call with field from source node; persists until overwritten
- this 0xC: written each call with field from source node; persists until overwritten
- this 0x10: written each call with byte from source node; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — default file path used when string pointer is null |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] — unknown reference |
| 007d0398 | dword_7D0398 | R | PhotoFreeCameraFlag [DERIVED] — if zero, allows vehicle data path |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] — if == 5 (RaceMode), enables vehicle data path |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] — base for vehicle data at node+8 indexed * 1060 + 124 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004134d0 | TextAttributeLookup_34d0 | final text attribute lookup for vehicle data path |
| 00415550 | LinkedListIndexScannerWithValidation | scans linked list for validation (vehicle path only) |
| 00415650 | LinkedListIndexedAccessor | accesses linked list node by index a3 |
| 00566650 | StringCopyWithBufferRealloc | copies file path string from source to buffer |
| 00587bcf | FreeWrapper_7bcf | frees memory (used for previous string) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | != | 18446744073709551615 | sentinel check: first metadata field != -1 |
| this | 0xC | != | 18446744073709551615 | sentinel check: second metadata field != -1 |

**Guard interpretation:** After copying: if (string==default && metadata[0]==-1 && metadata[1]==-1 && metadata[2]==0) → return 1 (all defaults, no match). Otherwise if vehicle path flag (v15) set → do further scanning + TextAttributeLookup_34d0. If v15 not set → return -1.
