## FileScanner_0045c240 — FileScanner

**Summary:** Clears previous scan results, frees linked list of file entries, then re-scans directory for .gdb, .hdv, and terrain.ini files using type-specific check functions. Initializes random seed bytes. Part of resource file enumeration for scene loading.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverEntrantSetupEntry (00462550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0x0 | R | — | Inner data pointer in linked list node |
| *(*(this+0x4)+0x4) | 0x4 | R | — | Next pointer in linked list node |
| *(this+0x4) | 0x0 | R | — | First pointer in node (data or inner struct) |
| *(this+0x4) | 0x8 | R | — | Node flag byte (1 = has inner data to free) |
| this | 0x0 | RW | — | Random flag byte (seed derived, %247+8) |
| this | 0x1 | RW | — | Random mode byte (seed derived, %247) |
| this | 0x4 | RW | 0 | Linked list head pointer |
| this | 0x8 | RW | 0 | Linked list tail pointer |
| this | 0xC | RW | 0 | Linked list cached tail pointer |
| this | 0x10 | RW | 0 | Linked list item count |

**Written-by note (persistence):**
- this 0x0: written once per scan with random value; external poke survives until next scan
- this 0x1: written once per scan with random value; external poke survives until next scan
- this 0x4: cleared to 0 at end of scan (head reset); external poke overwritten
- this 0x8: cleared to 0 at end of scan (tail reset); external poke overwritten
- this 0xC: cleared to 0 at end of scan; external poke overwritten
- this 0x10: cleared to 0 at end of scan; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5b88 | aTerrainIni | R | TerrainIniString [DERIVED] — "terrain.ini" string constant |
| 005c5b94 | aHdv_0 | R | HDVString [DERIVED] — ".hdv" extension string |
| 005c5b9c | aGdb | R | GdbField [DERIVED] — ".gdb" extension string |
| 005ea438 | byte_5EA438 | R | Fallback directory path when dword_5EC3D8 is null |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] — preferred directory path for file scan |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c0c0 | sub_45C0C0 | Scans directory for matching files, populates result linked list |
| 00587bcf | FreeWrapper_7bcf | Frees heap-allocated node data during cleanup |
| 005884ed | RandLCGRandomNumberGenerator | Generates random seed bytes for this struct |

**Guard conditions:** While loop over linked list continues while next pointer non-null. Node flag byte at offset 8 must be set to 1 for inner-data freeing path; if 0, only the node wrapper is freed. Directory scan uses dword_5EC3D8 if non-null, else falls back to byte_5EA438.
