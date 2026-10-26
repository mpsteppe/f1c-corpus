## LinkedListDestructionWithVTableCall_0048d230 — LinkedListFullDestroyAndReset

**Summary:** Destroys linked list at this+0x31C, frees all nodes (with vtable destructor call on non-terminal nodes), then resets all collision/scroll fields (0x31C-0x340) to zero except direction byte at 0x33C set to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerProfileScanner (00468ee0), sub_46A2A0 (0046a2a0), ObjectConstructorWithZeroedFields (0048c9f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x31C)+0x0)+0x0) | 0x0 | R | — | First node's vtable function pointer (indirect destructor) |
| *(*(this+0x31C)+0x0) | 0x0 | R | — | First node's vtable pointer |
| *(*(this+0x31C)+0x4) | 0x4 | R | — | First node's next pointer |
| *(this+0x31C) | 0x0 | R | — | Head node's first DWORD (vtable or data) |
| *(this+0x31C) | 0xC | R | — | Head node's active flag byte |
| this | 0x31C | RW | 0 | Linked list head pointer (zeroed) |
| this | 0x320 | RW | 0 | Linked list tail pointer (zeroed) |
| this | 0x324 | RW | 0 | List size/count (zeroed) |
| this | 0x328 | RW | 0 | Item count / multiplier (zeroed) |
| this | 0x32C | RW | 0 | Step size (zeroed) |
| this | 0x330 | RW | 0 | Max dimension 2 (zeroed) |
| this | 0x334 | RW | 0 | Current scroll position (zeroed) |
| this | 0x338 | RW | 0 | Target index (zeroed) |
| this | 0x33C | RW | 1 | Direction byte flag (set to 1, NOT zeroed) |
| this | 0x340 | RW | 0 | Float accumulator (zeroed) |

**Written-by note (persistence):**
- this 0x31C-0x340: all zeroed (except 0x33C=1). Complete reset — all state cleared.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Frees each linked list node from memory |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x31C) | 0xC | == | 0 | Per-node flag: if 0, node is terminal (no destructor) |

**Guard interpretation:** For each node in list: if byte at node+0xC == 0 → BLOCKED: vtable destructor skipped, node only freed. If byte != 0 AND node has vtable pointer → PASSES: destructor called with arg 1 before freeing. If head pointer (this+0x31C) is null → BLOCKED: loop body skipped entirely.
