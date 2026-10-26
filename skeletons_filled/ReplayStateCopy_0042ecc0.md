## ReplayStateCopy_0042ecc0 — GearConfigToReplayStateCopy

**Summary:** Reads gear ratio configuration from file via GearRatioConfigFileReader, then copies 8 consecutive DWORDs from config buffer (offset 0x1970) into replay state fields (starting at offset 0x1680) with stride 16 per field.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1640 | RW | — | replayGearRatioCount |
| this | 0x1680 | RW | — | replayGearRatioBuffer |
| this | 0x1970 | R | — | configGearRatioData (RatioCalculator table) |
| this | 0x1978 | R | — | configFinalDriveData |

**Written-by note (persistence):**
- this 0x1640: recalc every frame — external poke does NOT persist
- this 0x1680: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042de10 | GearRatioConfigFileReader | Reads gear ratio and final drive config into struct at this+0x1970 |

**Guard conditions:** None — always executes the file read and copy. File read failure inside GearRatioConfigFileReader returns 0, which is stored as count.
