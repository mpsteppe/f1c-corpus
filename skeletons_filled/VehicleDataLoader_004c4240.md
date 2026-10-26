## VehicleDataLoader_004c4240 — VehicleDataSorter

**Summary:** Selection-sorts the global vehicle array by composite string key. For each position, finds the best-matching remaining entry via CompositeStringCompare, swaps it into place using a local temporary buffer. Copies strings, integer fields, and raw byte blocks (16B to 256B chunks) during each swap. Called after vehicle files are loaded.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleFileLoader (004c3d80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] — number of entries to sort |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] — array to be sorted |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | null-safe dereference of string pointer before realloc-copy |
| 004c3050 | sub_4C3050 | initialize a temporary vehicle entry buffer |
| 004c3130 | MultiFieldCleanup | cleanup temporary buffer after sorting |
| 004c3890 | CompositeStringCompare | compare two vehicle entries to determine sort order |
| 004c45d0 | VehicleDataCopy | copy a vehicle entry (1060 bytes) between array positions |
| 00566650 | StringCopyWithBufferRealloc | realloc-copy a string during swap |

**Guard conditions:** dword_8AC390 must be > 0 for sort loop to run. Inner loop compares each remaining entry via CompositeStringCompare; if the best match is already at current position, no swap is performed.
