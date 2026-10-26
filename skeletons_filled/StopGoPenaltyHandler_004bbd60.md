## StopGoPenaltyHandler_004bbd60 — StopGoPenaltyHandler

**Summary:** Displays a "Stop/Go Penalty" message with driver name to HUD and logs the penalty event (type 4, ID 23) to the ring buffer with driver identifier and session time.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BC9B0 (004bc9b0), sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | penalty state flag (checked == 0) |
| this | 0x0 | R | — | pointer to vehicle/object for penalty dispatch |
| this | 0x4 | R | — | driver/vehicle identifier |
| this | 0x30 | R | — | penalty pending flag (checked != 0 blocks) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5d30 | aSS_2 | R | Str_DriverSettingsSuffix [DERIVED] |
| 005d2574 | aStopGoPenalty | R | StopGoPenaltyString [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041a720 | sub_41A720 | dispatch penalty to vehicle |
| 00423a00 | BinarySearchInStringTable | look up string in message table |
| 0045bd10 | TextLineWrappingAndRendering | render message text to HUD |
| 004b33b0 | ProgressBarEventEncode | encode penalty event to ring buffer |
| 00587dd0 | sub_587DD0 | string copy with length limit |
| 0058815f | StringFormatWithBufferOverflowCheck | format stop/go penalty message string |

**Guard conditions:** BLOCKED when this[12] (offset 0x30) is non-zero (penalty already active). BLOCKED when a2 is NULL or obj+0x32C8 is non-zero (state not ready). The ring buffer event logging always executes regardless of message display success.
