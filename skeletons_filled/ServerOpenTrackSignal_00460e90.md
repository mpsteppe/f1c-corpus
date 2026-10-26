## ServerOpenTrackSignal_00460e90 — ServerOpenTrackSignal

**Summary:** Sends server open-track signal with progress event and COM object dispatch. Optionally appends track info node to linked list when photo/free camera mode is active; otherwise frees the temporary allocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalStateDispatch (00463760), SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B774) | 0x4 | RW | — | Linked list tail node's next pointer (updated when appending) |
| this | 0x29 | RW | 1 | Open track flag byte, set to 1 on signal |
| this | 0x3FB8 | R | — | COM interface pointer for COMVTableCallVia0x60 |
| this | 0x1B770 | RW | — | Linked list head pointer (set when first node added) |
| this | 0x1B774 | RW | — | Linked list tail pointer (updated on each append) |
| this | 0x1B778 | RW | — | Linked list end/tail pointer (set alongside head) |
| this | 0x1B77C | RW | — | Linked list count (incremented on each append) |

**Written-by note (persistence):**
- *(this+0x1B774) 0x4: conditional — updated to point to new node when appending to linked list
- this 0x29: once per call — set to 1 unconditionally
- this 0x1B770: conditional — set on first node add; persists
- this 0x1B774: conditional — updated on each node add; persists
- this 0x1B778: conditional — set on first node add; persists
- this 0x1B77C: conditional — incremented on each node add; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c60e8 | aOpening | R | OpeningString [DERIVED] — "Opening" track name string |
| 005ea438 | byte_5EA438 | R | Default application directory (fallback path) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] — guards debug logging |
| 007d0398 | dword_7D0398 | R | PhotoFreeCameraFlag [DERIVED] — when set, append node to linked list |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | Encode progress bar event (type 4, subtype 38) |
| 004c5920 | TrackNameReader | Read track name into buffer |
| 004d7a50 | StringSplitLoop | Sanitize debug message string |
| 004d7aa0 | DebugLogWrite | Write debug log with track info |
| 005665b0 | sub_5665B0 | Process track name data |
| 00566650 | StringCopyWithBufferRealloc | Copy "Opening" string with reallocation |
| 0057a680 | COMVTableCallVia0x60 | Create COM object via vtable method |
| 0057a690 | VirtualMethodDispatch | Dispatch virtual method on COM object |
| 0057a6a0 | NetworkSendDispatch | Send COM object data over network |
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate heap memory (8 or 12 bytes) |

**Guard conditions:**
- Always: encode progress event, create COM object, set byte +4 = 1, send network dispatch, set this+0x29 = 1.
- Allocate 8-byte node (data=0, next=(-1)). Allocation fails → v4 = 0.
- StringCopyWithBufferRealloc for "Opening" string.
- TrackNameReader reads track name into buffer; sub_5665B0 processes it.
- Debug log only when dword_7C569C != 5 (not server).
- If dword_7D0398 (photo/free camera) != 0 and v4 != null:
  - Allocate 12-byte linked list node, wrap v4 as data.
  - If list head (this+0x1B770) is empty: set head = tail = new node.
  - Else: append to tail (this+0x1B774), update tail pointer.
  - Increment list count (this+0x1B77C).
- If dword_7D0398 == 0 and v4 != null: free the 8-byte allocation (data + node itself).
