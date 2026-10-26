## BufferWriteWithStringLengthCheck_00566c30 — formatted string write with file/buffer dispatch

**Summary:** Formats variadic string via SafeStringFormat. If mode flag at this[4] is zero, writes directly to file via FileWriteWrapperWithLock. If non-zero, formats to local buffer and writes via BufferFillWithTimeout, verifying all bytes written. Config/data serialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSetupFileWriter (0042fd00), AutoLoadEntryWriter (00432bf0), sub_456670 (00456670), sub_457670 (00457670), sub_458190 (00458190), sub_458A60 (00458a60), DebugCoordinateFormat (004a7040), DebugLogFormat (004b1b10), ConfigKeyValueSerialize (004b1c80), ConfigKeyValueWrite (004b1e20), UIConfigEntrySerialization (004b1fc0), SettingsIniFileWriter (004c0690), PlayerOpponentStateWriter (004c0cc0), CareerStatsWriter (004c2420), sub_4D24D0 (004d24d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | handle (file handle or buffer ID) |
| this | 0x10 | R | — | mode flag: 0=file write, non-zero=buffer write |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00535220 | BufferFillWithTimeout | write formatted string to memory buffer |
| 0058a163 | FileWriteWrapperWithLock | write formatted string to file with locking |
| 0058ac95 | SafeStringFormat | safe variadic string formatting into buffer |

**Guard conditions:** If this[4] == 0 → FileWriteWrapperWithLock path (returns 0). If this[4] != 0 → format to buffer, validate strlen > 0, then BufferFillWithTimeout. Returns true only if all formatted bytes were written.
