## FieldReadDelegate_004e16c0 — FieldReadDelegate

**Summary:** Reads three DWORDs and three floats from struct offsets 8-28 and forwards them to sub_54B4D0. Simple data-binding delegate for UI state update.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleTelemetryPositionAccumulator (004ec080)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | First DWORD parameter (element ID/index) |
| this | 0xC | R | — | Second DWORD parameter |
| this | 0x10 | R | — | Third DWORD parameter |
| this | 0x14 | R | — | First float value for state |
| this | 0x18 | R | — | Second float value for state |
| this | 0x1C | R | — | Third float value for state |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b4d0 | sub_54B4D0 | Applies the six parameters as UI element state |

**Guard conditions:** None — always executes sub_54B4D0 with the six field values.
