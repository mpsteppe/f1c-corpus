## ServerOpenedClosedNotification_00461190 — TrackOpenCloseNotify

**Summary:** Notifies when a server track is opened or closed: formats message "*** The server {opened/closed} {trackname}", appends to debug log linked list, and renders text to UI resource.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalStateDispatch (00463760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B774) | 0x4 | RW | — | Next pointer in linked list log node (append position) |
| this | 0x29 | RW | 0 | Track opened flag (cleared to 0 when closed) |
| this | 0x2C | RW | 18446744072627421184 → -1.0f | Track opening progress timer (set to -1.0f when closed) |
| this | 0x1B770 | RW | — | Linked list head pointer for debug log entries |
| this | 0x1B774 | RW | — | Linked list tail pointer for debug log entries |
| this | 0x1B778 | RW | — | Linked list secondary pointer (set to first node) |
| this | 0x1B77C | R | — | Linked list node count (incremented) |

**Written-by note (persistence):**
- *(this+0x1B774) 0x4: once per call when appending; persists until freed
- this 0x29: set to 0 on "closed" branch; persists until overwritten
- this 0x2C: set to -1.0f (closed) or 1.0f (opened); persists
- this 0x1B770: written on first node allocation; persists
- this 0x1B774: updated each append; persists
- this 0x1B778: written on first node allocation; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f0b4 | flt_59F0B4 | R | Initial track open speed value [DERIVED] |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c610c | aTheServerSS | R | Format string "*** The server %s %s" |
| 005c6124 | aClosed | R | "closed" string literal |
| 005c612c | aOpened | R | "opened" string literal |
| 005ea438 | byte_5EA438 | R | Default application directory fallback path |
| 007c569c | dword_7C569C | R | Session type (5=server) — guards dev logging |
| 007cd204 | dword_7CD204 | R | Resource dispatch target for text rendering |
| 007d0398 | dword_7D0398 | R | Photo/free camera mode flag — guards entire operation |
| 008ac368 | unk_8AC368 | R | Vehicle setup base [DERIVED] |
| 008ad25c | dword_8AD25C | R | Debug message buffer pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bd10 | TextLineWrappingAndRendering | Render formatted message to UI |
| 004c5920 | TrackNameReader | Read current track name string |
| 004d7a50 | StringSplitLoop | Guard check for dev logging verbosity |
| 004d7aa0 | DebugLogWrite | Write debug log message |
| 00566650 | StringCopyWithBufferRealloc | Copy formatted message into allocated buffer |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate heap memory for log buffer and node |
| 0058815f | StringFormatWithBufferOverflowCheck | Format "*** The server %s %s" string |

**Guard conditions:** Entire body guarded by dword_7D0398 (photo/free camera mode) — when 0, function returns immediately. DebugLogWrite additionally blocked when dword_7C569C==5 (server session) or StringSplitLoop returns 0.
