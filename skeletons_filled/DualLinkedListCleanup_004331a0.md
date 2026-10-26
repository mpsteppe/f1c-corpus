## DualLinkedListCleanup_004331a0 — DualLinkedListFullCleanup

**Summary:** Frees all nodes and their contained data across two linked lists (session config items and secondary allocations), then zeroes all list structure fields. Physics session/configuration cleanup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsShutdown (00431c70), TextFileReader (004b09a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x0) | 0x0 | R | — | first list node: pointer to config data block |
| *(*(this+0x1C)+0x0) | 0x8 | R | — | first list node: active flag byte |
| *(*(this+0x1C)+0x0) | 0x14 | R | — | first list node: pointer at offset 0x14 within data block |
| *(*(this+0x1C)+0x4) | 0x4 | R | — | first list node: next node pointer |
| *(*(this+0x30)+0x4) | 0x4 | R | — | second list node: next node pointer |
| *(this+0x1C) | 0x0 | R | — | first list head pointer |
| *(this+0x1C) | 0x8 | R | — | first list node active flag |
| *(this+0x30) | 0x0 | R | — | second list head pointer |
| *(this+0x30) | 0x8 | R | — | second list node active flag |
| this | 0x18 | RW | 0 | first list count/size field, zeroed on cleanup |
| this | 0x1C | RW | 0 | first list head pointer, zeroed on cleanup |
| this | 0x20 | RW | 0 | first list tail pointer, zeroed on cleanup |
| this | 0x24 | RW | 0 | first list extra pointer, zeroed on cleanup |
| this | 0x28 | RW | 0 | first list extra pointer, zeroed on cleanup |
| this | 0x2C | RW | 0 | first list flags byte, zeroed on cleanup |
| this | 0x30 | RW | 0 | second list head pointer, zeroed on cleanup |
| this | 0x34 | RW | 0 | second list tail pointer, zeroed on cleanup |
| this | 0x38 | RW | 0 | second list extra pointer, zeroed on cleanup |
| this | 0x3C | RW | 0 | second list extra pointer, zeroed on cleanup |

**Written-by note (persistence):**
- this 0x18: zeroed once on cleanup — no external value survives
- this 0x1C..0x2C: zeroed once on cleanup — no external value survives
- this 0x30..0x3C: zeroed once on cleanup — no external value survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432cc0 | SessionConfigDefaultInit | initialize/reinit a session configuration data block from defaults |
| 00566650 | StringCopyWithBufferRealloc | re-read or reallocate string buffer for default directory path |
| 00587bcf | FreeWrapper_7bcf | free heap-allocated memory with null check |

**Guard conditions:** first list: skips nodes where active flag (offset 0x8) is 0; skips freeing data when data pointer is null. second list: only executes if head pointer (this+0x30) is non-null; per-node active flag check before freeing data.
