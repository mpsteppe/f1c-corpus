## ConfigFileParser_004330d0 — ConfigFileParser

**Summary:** Writes auto-load entries from internal linked list to a config file. Builds physics file path, opens file, iterates linked list nodes writing each entry via AutoLoadEntryWriter, then closes file.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AddVehicleConfigEntryToLinkedList (00433b60), sub_4B0770 (004b0770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x28) | 0x0 | R | — | linked list node validity flag / data pointer at offset 0 |
| this | 0x1C | R | — | pHead: linked list head pointer |
| this | 0x24 | RW | — | pCurrent: iterator pointer advanced through list |
| this | 0x28 | R | — | pointer to first node's data area |

**Written-by note (persistence):**
- this 0x24: written once (head copy), then repeatedly in loop to advance. Last write is final node's next pointer (may be 0 at list end). Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432bf0 | AutoLoadEntryWriter | write a single auto-load entry to the file |
| 00432cf0 | PhysicsFilePathBuild | build physics file path from config path |
| 005668b0 | ZeroInitSmallStruct | zero-initialize a small struct |
| 005668d0 | SubCallWithConditionalFieldFree | conditional cleanup with field free |
| 00566940 | sub_566940 | open file for writing |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | close file handle |
| 00568620 | sub_568620 | set file buffer size |
| 0058ba36 | ToggleFileReadOnlyAttributeViaWin32API | set file read-only attribute |

**Guard conditions:** `PhysicsFilePathBuild` return value guards: if non-zero, skip entire write and return early. `sub_566940` (file open) return guards: if zero, skip file operations. Head pointer `this[7]` (0x1C) checked: if null or its first DWORD is zero, loop body never executes. Loop stops when next pointer is null or next node's first DWORD is zero.
