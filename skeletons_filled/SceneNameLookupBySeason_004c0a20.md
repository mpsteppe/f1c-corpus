## SceneNameLookupBySeason_004c0a20 — Scene name copy to buffer

**Summary:** Looks up the current vehicle's scene name and copies it into an output buffer with length limit. Gets vehicle name from object field, resolves it via vehicle lookup, and returns the scene-name string.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ChampionshipPointsAccumulator (0041f220), MemoryAllocation_fb10 (0041fb10), SessionStateSearch (0041fc60), ConfigSectionSearchByKeyValue (0041fe00), SceneElementScanWithConditionCheck (0041ff10), ShortComputation_12e0 (004212e0), CountActiveEntitiesByState (00421380), sub_47C360 (0047c360), sub_4A08E0 (004a08e0), sub_4C13C0 (004c13c0), PathFileComparisonCounter (004c1450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | vehicle name string for lookup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path (fallback for null vehicle name) |
| 008ac388 | unk_8AC388 | R | vehicle file path buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c3f80 | VehicleLookupByName | resolve vehicle name to vehicle data pointer |
| 004c4080 | CurrentVehicleAccessor | get current vehicle entry from lookup cache |
| 00587dd0 | sub_587DD0 | copy string with length limit (snprintf-style) |

**Guard conditions:** Returns immediately if output buffer a2 is NULL. Sets a2[0] = 0 (empty string) before proceeding. Returns without copying if CurrentVehicleAccessor returns NULL (vehicle not found). Only copies if a3 > 1 (buffer has room for at least 1 char + null terminator).
