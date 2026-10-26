## BufferPoolAllocatorInitialization_004b71e0 — Buffer Pool Allocator Init

**Summary:** Full reinitialization of buffer pool lists and circular buffer. Transfers linked lists, frees file-stream list nodes, clears list pointers, allocates pit stall circular buffer (size selected by enum at this+0x9A4), and initializes all 44-byte sub-entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x0) | 0x4 | R | — | Node data pointer's second field (freed if flag set) |
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | Second node's data pointer field |
| *(this+0x6C0) | 0x0 | R | — | File stream list head node pointer |
| *(this+0x6C0) | 0xC | R | — | Node flag byte (if set, free data before freeing node) |
| *(this+0x9A4) | 0x0 | RW | — | Buffer size enum (0=16, 1=24, 2=32, 3=48, 4=96 entries) |
| this | 0x6C0 | RW | 0 | File stream list head (zeroed) |
| this | 0x6C4 | RW | 0 | File stream list field (zeroed) |
| this | 0x6C8 | RW | 0 | File stream list current (zeroed) |
| this | 0x6CC | RW | 0 | File stream list byte flag (zeroed) |
| this | 0x6D0 | RW | 0 | File stream list flag (zeroed) |
| this | 0x9A4 | R | — | Buffer size selector (enum 0-4) |
| this | 0x9B0 | RW | 0 | Allocated circular buffer pointer (set after alloc) |
| this | 0x9B4 | RW | 96 | Buffer size in entries (set by switch: 16/24/32/48/96) |
| this | 0x9B8 | RW | 18446744073709551615 | Write index (set to -1 = invalid) |
| this | 0x9BC | RW | 18446744073709551615 | Read index (set to -1 = invalid) |
| this | 0xF38 | RW | 0 | Flag field (zeroed) |
| this | 0xF3C | RW | 0 | Flag field (zeroed) |
| this | 0xF8C | RW | 5 | Counter/flag field (set to 5) |

**Written-by note (persistence):**
- *(this+0x9A4) 0x0: Written with entry count (alloc header); persists for buffer lifetime.
- this 0x6C0: Zeroed after list freed; persists.
- this 0x6C4: Zeroed; persists.
- this 0x6C8: Zeroed; persists.
- this 0x6CC: Zeroed; persists.
- this 0x6D0: Zeroed; persists.
- this 0x9B0: Set to allocated buffer or 0; persists.
- this 0x9B4: Set by switch case (16/24/32/48/96); persists.
- this 0x9B8: Set to -1; persists until buffer used.
- this 0x9BC: Set to -1; persists until buffer used.
- this 0xF38: Zeroed; persists.
- this 0xF3C: Zeroed; persists.
- this 0xF8C: Set to 5; persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b52a0 | ListRebuildWithNodeTransfer | Rebuild/reinitialize node list |
| 004b5e50 | sub_4B5E50 | Per-slot list reinitialization (104 slots) |
| 004b5f60 | LinkedBufferTransfer | Transfer doubly-linked buffer to output list |
| 00587bcf | FreeWrapper_7bcf | Free nodes and their payloads |

**Guard conditions:** The switch on *(this+0x9A4) determines buffer allocation size. Cases 0-4 set entry count (16/24/32/48/96), allocate 176*count+4 bytes, zero-init 44-byte sub-entries, and store at this+0x9B0. Default case returns immediately without allocation.
