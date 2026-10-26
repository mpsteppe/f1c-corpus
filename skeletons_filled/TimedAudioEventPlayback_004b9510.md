## TimedAudioEventPlayback_004b9510 — TimedAudioEventRangePlayback

**Summary:** Plays timed audio events within a time window [a2, a3] by walking a sorted linked list of event nodes. Each event triggers stream read, ring buffer write, and audio control operations. Part of audio/event playback system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9B80 (004b9b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x71C)+0x4)+0x0) | 0x0 | R | — | float timestamp of second event node in list |
| *(*(*(this+0x71C)+0x8)+0x0) | 0x0 | R | — | float timestamp of previous/prev node |
| *(*(this+0x714)+0x0) | 0x0 | R | — | head node data pointer (float timestamp) |
| *(*(this+0x714)+0x0) | 0x4 | R | — | head node resource handle |
| *(*(this+0x714)+0x0) | 0x8 | R | — | head node event count/flag (WORD) |
| *(*(this+0x71C)+0x4) | 0x0 | R | — | next node data pointer (float timestamp) |
| *(*(this+0x71C)+0x8) | 0x0 | R | — | prev node data pointer (float timestamp) |
| *(this+0x714) | 0x0 | R | — | head node (start of event list) |
| *(this+0x718) | 0x0 | R | — | tail node (end of event list) |
| *(this+0x71C) | 0x0 | R | — | current cursor node data pointer |
| *(this+0x71C) | 0x4 | R | — | cursor node's next pointer |
| *(this+0x71C) | 0x8 | R | — | cursor node's prev pointer |
| this | 0x714 | R | — | head pointer of timed event linked list |
| this | 0x718 | R | — | tail pointer of timed event linked list |
| this | 0x71C | RW | — | cursor pointer for current playback position |
| this | 0xF30 | R | — | lower bound of angle/range |
| this | 0xF34 | R | — | upper bound of angle/range |

**Written-by note (persistence):**
- this 0x71C: updated during traversal as playback position advances; survives between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd68 | flt_5ACD68 | R | UIScrollRange [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | processes event data into ring buffer format |
| 004b4360 | StreamReadWithScale | reads timed event data from stream |
| 004b4450 | WrapperPassThrough | pass-through wrapper for event processing |
| 004b44a0 | sub_4B44A0 | initialises event processing context |
| 00566db0 | sub_566DB0 | releases resource handle from processed event node |

**Guard conditions:** If a2 == a3 (zero-width window), no events are processed. Otherwise clamps time window to max 1.667 seconds based on direction flag a4. If all three list pointers (head/tail/cursor) are null after range check, entire playback is skipped.
