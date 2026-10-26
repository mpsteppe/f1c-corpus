## VehicleForceAerodynamicsComputation_004b6a10 — State Serialization Export

**Summary:** Serializes vehicle/race state to a conditional dispatch stream: writes path strings, byte flags, 104 slot lists (via sub_4B4FB0), a linked list (via FileStreamWriter), and a range-filtered list of entries. Returns success if processed count matches expected.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7500 (004b7500), sub_4B7DE0 (004b7de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x714)+0x0) | 0x0 | R | — | Range-filtered list node data pointer (checked for NULL) |
| *(*(this+0x714)+0x0) | 0x8 | R | — | Node short value (accumulated in v31) |
| *(this+0x48) | 0x0 | R | — | Slot list head pointer for traversal |
| *(this+0x48) | 0x4 | R | — | Slot list entry value |
| *(this+0x6C0) | 0x0 | R | — | File stream list head pointer |
| *(this+0x6C8) | 0x4 | R | — | File stream list next link |
| *(this+0x714) | 0x0 | R | — | Range-filtered list head pointer |
| *(this+0x71C) | 0x0 | R | — | Range-filtered list current pointer |
| *(this+0x71C) | 0x4 | R | — | Range-filtered list next link |
| this | 0x48 | RW | — | Slot list current/temp pointer (updated during traversal) |
| this | 0x6C0 | R | — | File stream linked list head |
| this | 0x6C8 | RW | — | File stream list current pointer |
| this | 0x6CC | R | — | Byte flag (serialized to stream) |
| this | 0x714 | R | — | Range-filtered list head pointer |
| this | 0x71C | RW | — | Range-filtered list current pointer |
| this | 0x724 | R | — | File path string pointer (first, with fallback to global) |
| this | 0x72C | R | — | File path string pointer (second, with fallback) |
| this | 0xF1C | R | — | Byte flag (serialized to stream) |
| this | 0xF20 | R | — | Byte flag (serialized to stream) |

**Written-by note (persistence):**
- this 0x48: Updated per slot during traversal; per-call.
- this 0x6C8: Updated as file stream list is walked; per-call.
- this 0x71C: Updated as range list is walked; per-call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d2434 | off_5D2434 | R | SerializeMagic [DERIVED] |
| 005d2438 | flt_5D2438 | R | CheckpointTime [DERIVED] |
| 005ea438 | byte_5EA438 | R | Default application directory path (fallback) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b41e0 | FileStreamWriter | Serialize linked list entry to stream |
| 004b4fb0 | sub_4B4FB0 | Process/serialize a slot list entry |
| 004b5e30 | sub_4B5E30 | Get expected count of items to process |
| 00566bd0 | ConditionalDispatch_6bd0 | Write data to conditional dispatch stream (strings, bytes, ints, floats) |
| 00566d30 | ConditionalAllocInitDispatch | Initialize dispatch stream for serialization |

**Guard conditions:** If first path string at this+0x724 is NULL, fall back to global default path. Same for second path at this+0x72C. If list at this+0x714 (range list head) is NULL, return 0. If first node's data pointer at *(this+0x714) is NULL, return 0. For range filter: scan entries, only those with float value in [a3, a4] range are counted/accumulated; if no matching entry found (v20 or v19 is 0), return 0.
