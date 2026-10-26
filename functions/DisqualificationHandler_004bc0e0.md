## DisqualificationHandler_004bc0e0 — Disqualification display and event logging

**Summary:** Displays "Disqualified:" text overlay and logs a disqualification event via ProgressBarEventEncode. Guarded by this[12] (offset +0x30) != 3 to prevent double-trigger. Does NOT write the DQ state field — only reads guard. Text construction uses string table lookup + concatenation. ON_FRAME_PATH — runs per frame but guard prevents repeat execution for same vehicle.

**Struct fields accessed:**

| Offset (dec) | Offset (hex) | Read/Write | Init value (if written as literal) | Purpose inferred from code |
|---|---|---|---|---|
| this[12] | 0x0030 | Read | — | Anti-double-DQ guard: blocks re-entry when ==3 |
| *this + 13000 | *(DWORD*)this + 0x32C8 | Read | — | Gate: must be 0 to show "Disqualified:" text |
| this[1] | 0x0004 | Read | — | Vehicle index/ID (passed to ProgressBarEventEncode) |

**Guard conditions:**

| Field | Checked values | What PASSES | What is BLOCKED |
|---|---|---|---|
| this[12] (offset +0x30) | != 3 | NOT 3 (enter handler) | 3 (skip — already DQ'd) |
| a2 (string ptr) AND *(*this + 0x32C8) | NULL or non-zero | a2 not NULL AND indirect==0 | a2 NULL OR indirect!=0 (skip text display) |

**Written-by note:** Writes no persistent vehicle struct fields. Writes to global event buffer (dword_83EE60, dword_8AAE64). The guard field this[12] is READ ONLY — DQ state field at +0x4064 is also NOT written here. ON_FRAME_PATH → guard read executed every frame but body only enters when NOT 3, so text/log only triggers once until guard resets.

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x005EC4C0 | byte_5EC4C0 | Read | String table for "Disqualified:" lookup |
| 0x005EC4CC | byte_5EC4CC | Read, Write | String table buffer (used for lookup + copy) |
| 0x007CD204 | dword_7CD204 | Read | Text rendering context |
| 0x0083EE60 | dword_83EE60 | Read, Write | Event counter (incremented, checked against 1023 cap) |
| 0x008AAE64 | dword_8AAE64 | Read, Write | Event buffer pointer (advanced by 432 per event) |
| 0x008AFEA0 | dbl_8AFEA0 | Read | Master game time (encoded into progress bar event) |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| 0x004CF650 | BinarySearchInStringTable | Look up string in string table |
| 0x00587DD0 | sub_587DD0 | String copy with length limit (63) |
| 0x004DD770 | StringFormatWithBufferOverflowCheck | Safe string format ("%s %s") |
| 0x004D7640 | TextLineWrappingAndRendering | Render wrapped text to HUD |
| 0x004D6C90 | ProgressBarEventEncode | Encode event into progress bar/log system |
| 0x0041A940 | sub_41A940 | Log event to telemetry/log system |

**Call frequency:** per-frame tick (ON_FRAME_PATH). Body only executes once per DQ incident due to guard on this[12]==3.
