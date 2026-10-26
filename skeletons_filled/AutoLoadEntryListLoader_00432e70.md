## AutoLoadEntryListLoader_00432e70 — AutoLoadEntryListLoader

**Summary:** Loads auto-load entry list from a config file (AutoLoadConfigFile). Parses physics file path, reads session track/class entries, appends unresolved entries to internal linked list, and sets completion flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LookUpVehicleConfigEntry (004339e0), PlayerFileInit (004b0540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x4) | 0x4 | R | — | linked list node next pointer (tail->next) |
| *(this+0x1C) | 0x0 | R | — | linked list node data pointer |
| *(this+0x1C) | 0x8 | R | — | linked list node flag (1=has content to free) |
| *(this+0x20) | 0x4 | RW | — | tail node's next pointer on append |
| this | 0x18 | RW | 1 | bLoaded: completion flag set to 1 after load |
| this | 0x1C | RW | 0 | pHead: linked list head pointer |
| this | 0x20 | RW | 0 | pTail: linked list tail pointer |
| this | 0x24 | RW | 0 | pFirst: first node reference |
| this | 0x28 | RW | 0 | nCount: entry count in list |

**Written-by note (persistence):**
- *(this+0x20) 0x4: written once on each append, last write is final tail node's next (=0). Survives.
- this 0x18: written once (set to 1) at end of function. Survives.
- this 0x1C: set to 0 at start (after cleanup), then first node address. Survives.
- this 0x20: set to 0 at start, then each new tail. Last write is final tail. Survives.
- this 0x24: set to 0 at start, then first node address (never changed after). Survives.
- this 0x28: set to 0 at start, incremented per new entry. Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3f88 | off_5C3F88 | R | Off_ButtonBinding [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432a70 | TrackSessionClassesReader | parse track/session/class from config entry; returns non-zero if entry consumed (entry can be freed) |
| 00432cc0 | SessionConfigDefaultInit | zero-initialize or reset a session config struct |
| 00432cf0 | PhysicsFilePathBuild | build physics file path from config file path |
| 00432df0 | sub_432DF0 | set up config file path for reading |
| 00433090 | PhysicsObjectDestructor | free physics object resources |
| 005651b0 | sub_5651B0 | check for empty/invalid line in config reader |
| 005668b0 | ZeroInitSmallStruct | zero-initialize a small struct |
| 005668d0 | SubCallWithConditionalFieldFree | conditional cleanup with field free |
| 00566b20 | AudioStreamOpen | open a file stream for reading |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | close file handle with flag dispatch |
| 00566cc0 | ConditionalDispatchBasedOnFlag | read next line/entry from config file |
| 00587bcf | FreeWrapper_7bcf | free allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory (operator new / malloc) |
| 00588410 | sub_588410 | parse/compare config entry data |

**Guard conditions:** At entry, reads `*(this+0x1C)` (head pointer). If non-null, iterates linked list. For each node where `*(node+8)` (flag) is non-zero, destroys PhysicsObject and frees node data. Then clears head/tail/count (0x1C,0x20,0x24,0x28=0). After setup, `PhysicsFilePathBuild` return value guards the main load: if zero, proceeds to open file and parse entries. If non-zero, skips entire load, sets `this+0x18=1`, returns. If `AudioStreamOpen` returns false (zero), skips file parsing. If `sub_5651B0` returns zero and `sub_588410` matches, processes entry; otherwise skips it.
