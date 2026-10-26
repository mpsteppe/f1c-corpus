## ArithmeticComparison_b0d0_0053b0d0 — RenderCompositorSingletonAllocInit

**Summary:** Allocates and initializes a render compositor singleton for the UI rendering system. Stores the pointer in both NetConfigData and D3DDeviceWrapperPtr globals.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderUISystemGlobalInit (0053c360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8938 | off_5B8938 | R | VTableRef_5B8938 [DERIVED] |
| 008b8f18 | dword_8B8F18 | W | NetConfigData [DERIVED] |
| 008b8f24 | dword_8B8F24 | W | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-initializes memory block after allocation |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation wrapper for 4-byte object |

**Guard conditions:** Checks allocation result: if OperatorNewNhMallocWrapper returns NULL, both globals are set to 0 and function returns 0 (allocation failure path). If allocation succeeds, object vtable is set and pointer is stored in both globals.
