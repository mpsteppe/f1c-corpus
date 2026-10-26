## VehicleLookupByName_004c3f80 — VehicleNameLookup

**Summary:** Searches the global vehicle array for a vehicle matching a given name string. Iterates entries (stride 1060), compares the name field (first string pointer in each entry) via string comparison. Stores matching index in dword_8AC38C if found; no return value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NamedEntryLookupInFormatList (00415230), ShortComputation_5730 (00415730), AIDriverCountSetup (004bfd90), sub_4C0850 (004c0850), SceneNameLookupBySeason (004c0a20), SceneNamePointer (004c0a80), ConditionalDispatch_40b0 (004c40b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory, fallback when vehicle name is null |
| 008ac38c | dword_8AC38C | W | set to matching vehicle index when found |
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] — number of vehicles in array |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] — base of vehicle data array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | string comparison function (returns 0 on match) |

**Guard conditions:** a1 (search name) must be non-null. dword_8AC390 must be > 0. If no matching entry found after full iteration, function returns without modifying dword_8AC38C.
