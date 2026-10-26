## ServerCloseTrackSignal_00461020 — TrackCloseSignalDispatch

**Summary:** Sends "closing track" network signal, clears session open flag, and appends a log entry to the debug linked list under photo/free camera mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalStateDispatch (00463760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B774) | 0x4 | RW | — | Next pointer in the linked list log node (append position) |
| this | 0x29 | RW | 0 | Track opened/closed flag (0=closed, set after signal) |
| this | 0x3FB8 | R | — | COM interface pointer for virtual dispatch |
| this | 0x1B770 | RW | — | Linked list head pointer for debug log entries |
| this | 0x1B774 | RW | — | Linked list tail pointer for debug log entries |
| this | 0x1B778 | RW | — | Linked list secondary pointer (set to first node) |
| this | 0x1B77C | RW | — | Linked list node count |

**Written-by note (persistence):**
- *(this+0x1B774) 0x4: once per call when appending to linked list; persists until freed
- this 0x29: cleared once per call to 0 (track closed); external write survives until overwritten
- this 0x1B770: written on first node allocation only; persists for session
- this 0x1B774: updated each append; persists
- this 0x1B778: written on first node allocation only; persists
- this 0x1B77C: incremented each append; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c60f8 | aClosingTrack | R | "ClosingTrack" message string copied to buffer |
| 005ea438 | byte_5EA438 | R | Default application directory string (fallback for log path) |
| 007c569c | dword_7C569C | R | Session type (5=server) — guards dev logging |
| 007d0398 | dword_7D0398 | R | Photo/free camera mode flag — enables log list append |
| 008ad25c | dword_8AD25C | R | Debug message buffer pointer |
| 008afea0 | dbl_8AFEA0 | R | Session time (passed to ProgressBarEventEncode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | Encode progress bar event (track closing progress) |
| 004d7a50 | StringSplitLoop | Guard check for dev logging verbosity |
| 004d7aa0 | DebugLogWrite | Write debug log message |
| 00566650 | StringCopyWithBufferRealloc | Copy "ClosingTrack" string into allocated buffer |
| 0057a680 | COMVTableCallVia0x60 | Query COM vtable interface at offset 0x60 |
| 0057a690 | VirtualMethodDispatch | Release/destroy the COM temporary object |
| 0057a6a0 | NetworkSendDispatch | Send close-track network packet |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate heap memory for log node and buffer |

**Guard conditions:** Entry has no early-return guard. DebugLogWrite blocked when dword_7C569C==5 (server session) or StringSplitLoop returns 0. Linked list append blocked when dword_7D0398==0 (photo mode off); instead, buffer is freed.
