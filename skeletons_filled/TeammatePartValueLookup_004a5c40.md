## TeammatePartValueLookup_004a5c40 — TeammatePartValueReader

**Summary:** Scans the global vehicle array for a teammate (same team ID, different vehicle) and returns a part-related value (offset 0x3450) from the matching vehicle. Used by ForcePitExit to read teammate pit status.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ForcePitExit (0042a110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48A4 | R | — | Team identifier field on the current vehicle |
| this | 0x0 | R | — | Holds the current vehicle pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `dword_5C329C > 0` (at least one vehicle exists). PASSES: enters teammate search loop. BLOCKED: returns 0 if no vehicles. Also exits with 0 when loop completes without finding a teammate.