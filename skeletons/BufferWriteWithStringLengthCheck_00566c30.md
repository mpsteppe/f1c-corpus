## BufferWriteWithStringLengthCheck_00566c30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSetupFileWriter (0042fd00), AutoLoadEntryWriter (00432bf0), sub_456670 (00456670), sub_457670 (00457670), sub_458190 (00458190), sub_458A60 (00458a60), DebugCoordinateFormat (004a7040), DebugLogFormat (004b1b10), ConfigKeyValueSerialize (004b1c80), ConfigKeyValueWrite (004b1e20), UIConfigEntrySerialization (004b1fc0), SettingsIniFileWriter (004c0690), PlayerOpponentStateWriter (004c0cc0), CareerStatsWriter (004c2420), sub_4D24D0 (004d24d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00535220 | BufferFillWithTimeout | [LLM] |
| 0058a163 | FileWriteWrapperWithLock | [LLM] |
| 0058ac95 | SafeStringFormat | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
