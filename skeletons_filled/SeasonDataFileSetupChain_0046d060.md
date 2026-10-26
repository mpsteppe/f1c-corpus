## SeasonDataFileSetupChain_0046d060 — Season data file setup chain

**Summary:** Initializes session structure on stack, writes vehicle setup file for current track (or default directory if no track selected), triggers auto-load config file processing, deallocates score slot array, and frees temporary buffer if allocated. Part of season mode data file management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory string |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile flag/pointer |
| 007ce668 | dword_7CE668 | R | TrackNameStringPtr — current track name display string; null if no track selected |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ddd0 | ScoreSlotDeallocator | deallocates score slot memory array (v4) |
| 0042e320 | SessionStructInit | initializes session structure on stack (v2) |
| 0042fd00 | VehicleSetupFileWriter | writes vehicle setup file for given track path |
| 004b0770 | sub_4B0770 | processes auto-load config file at byte_7CE498 with parameter 1 |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory block |
| 005881c0 | __alloca_probe | stack probing for large stack frame allocation |

**Guard conditions:** No early-return guard at entry. If dword_7CE668 (TrackNameStringPtr) is null, falls back to byte_5EA438 (default application directory) as path for VehicleSetupFileWriter. After ScoreSlotDeallocator, if v3 (stack slot) is non-null, freed via FreeWrapper_7bcf; otherwise returns null.
