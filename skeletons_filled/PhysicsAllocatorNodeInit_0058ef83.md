## PhysicsAllocatorNodeInit_0058ef83 — PhysicsAllocatorNodeInit

**Summary:** Initializes a physics allocator node and exception handler chain. If dword_8D3F44 (CRT DLL switch) is nonzero, allocates 172-byte block, initializes via sub_58F014, stores in off_5E99D0 (IOFunctionPtr), replaces old CRT exception handler (dword_8D3F58) with new block and frees old one. If switch is zero, sets IO function pointer to D3D callback and clears exception handler.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e99d0 | off_5E99D0 | W | IOFunctionPtr [DERIVED] — physics IO function set (allocated block or D3D callback) |
| 005e99d8 | off_5E99D8 | R | D3DDeviceCallbackPtr [DERIVED] — default callback used when CRT switch is off |
| 008d3f44 | dword_8D3F44 | R | CRTDllSwitch [DERIVED] — nonzero = MSVCRT DLL in use, zero = static CRT |
| 008d3f58 | dword_8D3F58 | RW | CRT_ExceptionHandler [DERIVED] — current CRT exception handler pointer (replaced on init) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058aa6f | sub_58AA6F | Free memory block (old exception handler or failed alloc) |
| 0058ab58 | sub_58AB58 | Allocate zero-initialized memory (172 bytes, flag=1) for new allocator node |
| 0058f014 | sub_58F014 | Initialize the allocated physics allocator node structure |
| 0058f362 | sub_58F362 | Finalize/terminate an allocator node before freeing |

**Guard conditions:**
- `dword_8D3F44` (CRT DLL switch) nonzero → allocate new block, init, replace handler
- `dword_8D3F44` zero → use D3D callback pointer, clear exception handler
- `sub_58AB58(1, 172)` returns NULL → return 1 (allocation failure)
- `sub_58F014(v0)` succeeds (nonzero) → cleanup and return 1 (initialization failed/cancelled)
- Success path → return 0
