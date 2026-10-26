## RendererResourceCleanup_0053ead0 — Renderer resource cleanup with sub-resource release

**Summary:** Calls RenderTargetCleanup, then frees three sub-resources (this[1355], this[1353], this[1354]) via sub_53F6E0/EmptyStub_7470/FreeWrapper_7bcf, and releases sub-object at this+0x1100 via vtable[2] call, nulling all pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53E070 (0053e070), GlobalDispatch (0055c040)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x8 | R | — | vtable[2] (offset 8) on sub-object — release method |
| this | 0x0 | RW | — | stores return value from vtable release call |
| this | 0x1100 | RW | 0 | sub-object pointer — read, released via vtable, set to 0 |
| this | 0x1524 | RW | 0 | resource pointer 1 (this[1353]) — freed via EmptyStub_7470+FreeWrapper_7bcf |
| this | 0x1528 | RW | 0 | resource pointer 2 (this[1354]) — freed via EmptyStub_7470+FreeWrapper_7bcf |
| this | 0x152C | RW | 0 | resource pointer 3 (this[1355]) — freed via sub_53F6E0+EmptyStub_7470+FreeWrapper_7bcf |

**Written-by note (persistence):**
- this 0x0: written with vtable call result — overwritten each call
- this 0x1100: set to 0 after vtable release — null until re-created
- this 0x1524: set to 0 after FreeWrapper_7bcf — freed
- this 0x1528: set to 0 after FreeWrapper_7bcf — freed
- this 0x152C: set to 0 after FreeWrapper_7bcf — freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053f270 | RenderTargetCleanup | cleans up render target resources |
| 0053f6e0 | sub_53F6E0 | releases sub-object via vtable call |
| 00557470 | EmptyStub_7470 | stub/pre-release for resource |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory |

**Guard conditions:** Each resource pointer checked non-null before freeing. If null, skip that resource.
