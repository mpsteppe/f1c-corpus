## NetworkPacketSend_0c10_00580c10 — alloc and queue network packet with counter

**Summary:** Allocates and enqueues a network packet: increments send counter (under mutex at 0xB3C), allocates 32-byte data block, initializes via ObjectInitWithVTableFieldSet, optionally copies additional buffer headers (under mutex at 0x640), links into list (at 0xAC8) with 12-byte node. Returns 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x640 | R | — | Third mutex handle (for copy-buffer header path) |
| this | 0x644 | R | — | Third mutex timeout |
| this | 0xAC8 | RW | — | List head pointer (set on first insert) |
| this | 0xACC | RW | — | List tail pointer (updated each insert) |
| this | 0xAD0 | RW | — | List cursor (set = head on first insert) |
| this | 0xAD4 | R | — | List node count (incremented each insert) |
| this | 0xAD8 | R | — | First list mutex handle |
| this | 0xADC | R | — | First list mutex timeout |
| this | 0xB38 | R | — | Send counter (incremented under mutex, value passed to packet) |
| this | 0xB3C | R | — | Second mutex handle (protects counter) |
| this | 0xB40 | R | — | Second mutex timeout |

**Written-by note (persistence):**
- this 0xAC8: written once on first insert; persists until list cleared
- this 0xACC: written each insert; reflects tail node position
- this 0xAD0: written on first insert (= head); persists until cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059cacb | SEH_580C10 | R | SEH handler registration |
| 0059e1a0 | WaitForSingleObject | R | Wait on all three mutexes |
| 0059e1a4 | ReleaseMutex | R | Release all three mutexes |
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY |
| 0059e2f4 | __imp_htons | R | Convert port |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b780 | ObjectInitWithVTableFieldSet | Initialize 32-byte packet data with vtable and fields |
| 0057b9f0 | Copy4DwordsStructToStruct | Copy 16-byte sockaddr_in to this+0xA84 |
| 0057dd40 | sub_57DD40 | Direct init path (when a4 is false) |
| 00587370 | CopyBufferHeaderFieldsCallInit | Copy additional buffer header fields (when a4 is true) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 32-byte data block and 12-byte list node |

**Guard conditions:**
- If second counter mutex handle is null or wait fails → skip counter increment; counter not updated
- If first list mutex handle is null or wait fails → v21 becomes 0 (null deref risk on *v21++)
- If data allocation fails (v13=0) → skip ObjectInit, v14=0, no node allocation either
- If a3 > 2 or a3 <= 0 → skip both copy-buffer and direct-init paths
- If node allocation fails after data allocation → data orphaned (memory leak), no list insert
- If list head (*v21) is null → first insert: set head = cursor = node; else link after tail
