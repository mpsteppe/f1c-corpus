## VehicleSetupDriverNumber_004c7b50 — Lookup and store driver number from config

**Summary:** Looks up the driver number from a named entry list using the driver's full name and nationality path. Falls back to vehicle array name lookup if the initial search fails. Also scans a linked list for a long description match and stores the result as a secondary ID. Writes results to +0x489C (driver number) and +0x48A0 (secondary ID).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehgenScnFileLoader (004c6c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4898 | R | — | driver index (set by NationalityDriverInfoLoader) |
| this | 0x489C | RW | — | DriverID [FACT] driver number looked up from named entry list |
| this | 0x48A0 | RW | — | secondary ID from long description linked-list scan |

**Written-by note (persistence):**
- this 0x489C: set from NamedEntryLookupInFormatList result; persists until overwritten
- this 0x48A0: set from LinkedListIndexScannerWithValidation result; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415230 | NamedEntryLookupInFormatList | look up driver number by name in formatting list |
| 00415550 | LinkedListIndexScannerWithValidation | scan linked list for matching long description and return index |

**Guard conditions:** Guard: if NamedEntryLookupInFormatList returns < 0 (not found), fall back to lookup using vehicle array entry name with nationality path.
