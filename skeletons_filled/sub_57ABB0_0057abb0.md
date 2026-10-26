## sub_57ABB0_0057abb0 — NetworkModuleCreateAndRegister

**Summary:** Creates a network socket object from 12 parameter DWORDs, validates it via status flag and vtable method at offset 0x48, registers it into a global doubly-linked list (ModuleInitListHead). Allocates a 16-byte list node with flag byte at +12 set to 1. Increments pool alloc counter on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StackBufferCopyPredicateCall (0057aaf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c79b | SEH_57ABB0 | R | SEH exception registration for this function |
| 008d3bfc | dword_8D3BFC | RW | ModuleInitListHead [DERIVED] — linked list head, updated on first insert |
| 008d3c00 | dword_8D3C00 | RW | GenericList_Tail [DERIVED] — linked list tail, updated each insert |
| 008d3c04 | dword_8D3C04 | W | TaskListTail [DERIVED] — set on first insert |
| 008d3c08 | dword_8D3C08 | RW | PoolAllocCounter [DERIVED] — incremented each success |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | no-op stub |
| 0057a420 | NetworkSocketObjectCreate | creates network socket object from parameter block |
| 00585cc0 | FieldGetter_5cc0 | retrieves sub-object from created socket |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation (4 bytes for socket, 16 bytes for list node) |

**Guard conditions:** If NetworkSocketObjectCreate returns null, or status byte (a13 low) set, or vtable method at offset 0x48 on socket returns non-zero → return 1 (BLOCKED). All clear → proceed to registration (PASSES).

