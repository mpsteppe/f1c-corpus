## DriverEntrantSetupEntry_00462550 — DriverEntrantSetupHandler

**Summary:** Sets up a driver entrant by creating a COM query object, copying name and config data, dispatching a virtual function call; on failure, resets session state, clears the log linked list, appends a directory path node, and triggers file scanning.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x3FC8)+0x4) | 0x4 | R | — | Linked list node next pointer (read during free loop traversal) |
| *(obj+0x3FC8) | 0x0 | R | — | First node's data/buffer pointer (checked for free) |
| *(obj+0x3FC8) | 0x8 | R | — | First node's flag byte (checked for buffer ownership) |
| obj | 0x1AC | R | — | Track config/rule value (checked for zero to use default) |
| obj | 0x3FB8 | R | — | COM interface pointer for vtable query |
| obj | 0x3FC4 | RW | 2 | Session state — set to 1 or 2 on setup failure |
| obj | 0x3FC8 | RW | 0 | Linked list head pointer (freed and reset to 0) |
| obj | 0x3FCC | RW | 0 | Linked list tail pointer (reset to 0) |
| obj | 0x3FD0 | RW | 0 | Linked list secondary pointer (reset to 0) |
| obj | 0x3FD4 | RW | 0 | Linked list node count (reset to 0) |
| this | 0x0 | R | — | This pointer dereference |

**Written-by note (persistence):**
- obj 0x3FC4: written on failure path only; persists
- obj 0x3FC8: cleared to 0 on failure; persists
- obj 0x3FCC: cleared to 0 on failure; persists
- obj 0x3FD0: cleared to 0 on failure; persists
- obj 0x3FD4: cleared to 0 on failure; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default application directory fallback |
| 007cd270 | unk_7CD270 | R | Default HUD layout data (12 DWORDs) |
| 007ce64c | dword_7CE64C | R | Game filter data path |
| 007d0fc4 | dword_7D0FC4 | R | Default track config byte (fallback when this+0x1AC <= 0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c240 | FileScanner | Scan directory for track/filter files |
| 0045e590 | BufferFillWith0xFFFFFFFF | Fill linked list buffer with sentinel value |
| 004615f0 | BitFlagTestAt0x6E | Test bit flag at offset 0x6E to decide session state |
| 00461cd0 | SessionStateCheck | Query current session state (skip path append when ==1) |
| 00463710 | StringCopyToStructField | Copy string to a struct field |
| 0057a200 | MemcpyLikeCopyWithWordByteSplitSizeStore | Copy data with size tracking |
| 0057a4f0 | VirtualFunctionDispatchWithStackFrames | Dispatch virtual function with stack frame arguments |
| 0057a880 | VTableQueryWithStackBufferResult | Query COM interface for temporary object |
| 0057a8b0 | VTableCallViaOffset0x7c | Release COM temporary object via vtable |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory (buffer and nodes) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate heap memory for log node and path buffer |
| 00587dd0 | sub_587DD0 | Copy string with length limit |

**Guard conditions:** On virtual dispatch failure: when BitFlagTestAt0x6E(a2, 0) is non-zero, sets state to 1; else sets state to 2. New directory path node skipped when SessionStateCheck returns 1 (already initializing).
