## RenderTargetCleanup_0053f270 — Comprehensive render target cleanup

**Summary:** Conditionally releases render target resources when flag at this+0x5032 has 0x10000000 bit set. Frees audio network stream, D3D resources, UI iterator objects via multiple helper calls, and resets state fields to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RendererResourceCleanup (0053ead0), sub_555E50 (00555e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x1580)+0x870)+0x868) | 0x54 | R | — | D3D device method at offset 0x54 from device ptr chain |
| *(*(this+0x1580)+0x870) | 0x868 | R | — | intermediate pointer in device chain |
| *(*(this+0x1580)+0x870) | 0x870 | R | — | intermediate pointer in device chain |
| *(this+0x1518) | 0x30 | R | — | vtable offset on sub-object for D3D release |
| *(this+0x1518) | 0x34 | RW | 0 | sub-object release result — set to 0 |
| *(this+0x1518) | 0x40 | R | — | vtable offset on sub-object for D3D release |
| *(this+0x1518) | 0x84 | R | — | UI cleanup flag check — if non-zero, calls UICleanupIterator |
| this | 0x113C | RW | 0 | resource pointer 1 — freed via ObjectResetWithVirtualRelease+FreeWrapper_7bcf |
| this | 0x1140 | RW | 0 | resource pointer 2 — freed via ObjectResetWithVirtualRelease+FreeWrapper_7bcf |
| this | 0x1144 | RW | 0 | resource pointer 3 — freed via DrainingLoopFinalizer+FreeWrapper_7bcf |
| this | 0x13A0 | RW | 1 | state counter — reset to 1 during cleanup |
| this | 0x13A8 | RW | — | state counter — reset to 0 during cleanup |
| this | 0x14F0 | RW | 0 | state flags — reset to 0 during cleanup |
| this | 0x14F4 | RW | 0 | state flags — reset to 0 during cleanup |
| this | 0x14F8 | RW | 0 | state flags — reset to 0 during cleanup |
| this | 0x14FC | RW | 0 | state flags — reset to 0 during cleanup |
| this | 0x1500 | RW | 0 | state flags — reset to 0 during cleanup |
| this | 0x1504 | RW | 0 | state flags — reset to 0 during cleanup |
| this | 0x1518 | R | — | sub-object pointer for D3D resource list |
| this | 0x1580 | R | — | device pointer used to traverse D3D chain |

**Written-by note (persistence):**
- *(this+0x1518) 0x34: set to 0 during cleanup
- this 0x113C: set to 0 after freeing resource pointer 1
- this 0x1140: set to 0 after freeing resource pointer 2
- this 0x1144: set to 0 after freeing resource pointer 3
- this 0x13A0: set to 1 during cleanup
- this 0x13A8: set to 0 during cleanup
- this 0x14F0-0x1504: all set to 0 during cleanup
- this 0x5032: 0x10000000 bit cleared at end

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | resets resource objects via virtual release |
| 00541040 | DrainingLoopFinalizer | drains/finalizes a resource list |
| 00544af0 | AudioNetworkStreamCleanup | cleans up audio network stream |
| 00545f40 | ValueGetter | retrieves a D3D resource value for release |
| 005528b0 | ConditionalFreeByFlag_28b0 | conditionally frees resources by flag |
| 00554cc0 | D3DResourceRelease | releases D3D surface/resource |
| 00554d70 | UICleanupIterator | iterates UI for cleanup |
| 00554e10 | D3DResourceListCleanup | cleans up D3D resource list |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory |

**Guard conditions:** Guarded by (this+0x5032 & 0x10000000) != 0. If bit not set, entire cleanup skipped. Internal guards on each resource pointer being non-null before freeing.
