## DisqualificationHandler_004bc0e0 — DisqualificationHandler

**Summary:** Displays a "Disqualified:" message with driver name to HUD and logs disqualification event (type 4, ID 28) to ring buffer, guarded by this[12] != 3 to prevent double-disqualification.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A5EA0 (004a5ea0), sub_4A5F20 (004a5f20), LapCompletion (004bc4e0), sub_4BC9B0 (004bc9b0), sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | penalty state flag (checked == 0) |
| this | 0x0 | R | — | pointer to disqualification state object |
| this | 0x4 | R | — | driver/vehicle identifier |
| this | 0x30 | R | — | disqualification state (checked != 3 blocks) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5d30 | aSS_2 | R | Str_DriverSettingsSuffix [DERIVED] |
| 005d2588 | aDisqualified | R | String_Disqualified [DERIVED] |
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
| 0041a940 | sub_41A940 | dispatch disqualification to vehicle |
| 00423a00 | BinarySearchInStringTable | look up string in message table |
| 0045bd10 | TextLineWrappingAndRendering | render message text to HUD |
| 004b33b0 | ProgressBarEventEncode | encode disqualification event to ring buffer |
| 00587dd0 | sub_587DD0 | string copy with length limit |
| 0058815f | StringFormatWithBufferOverflowCheck | format disqualification message string |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x30 | != | 3 | disqualification state guard |

**Guard interpretation:** BLOCKED entirely when this[12] == 3 (already disqualified — anti-double-DQ). The outer check this[12] != 3 must pass before any code runs. Inner guards: message display blocked when a2 is NULL or obj+0x32C8 is non-zero; ring buffer event logging always runs regardless of message success.
