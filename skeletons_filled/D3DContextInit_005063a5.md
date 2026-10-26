## D3DContextInit_005063a5 — D3D surface pair creation and transfer attempt chain

**Summary:** Initialises a D3D texture copy context: validates parameters, creates source and destination surfaces via DirectXTextureSurfaceFactoryDispatchingFourCCCod, then attempts a chain of surface copy/resampling methods (SurfacePixelCopy, MemoryAllocationWithVectorConstructor, sub_504731, Direct3DTextureResampling, COMInterfaceVectorProcessingMethod, MultiLevelBufferAllocationWithVectorOps, sub_5054EC, VertexBufferAllocationAndStageTransformation, sub_506003, sub_502F31). First success wins; otherwise returns failure. Releases surfaces on exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketSendReceive (0050070d), AudioSoundBufferSetup (005007ef)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | source surface vtable pointer (for Release call) |
| *(this+0x4) | 0x0 | R | — | dest surface vtable pointer (for Release call) |
| obj | 0x0 | R | — | parameter a6 (surface type flags) |
| this | 0x0 | RW | 0 | source surface pointer, initialised to 0 |
| this | 0x4 | RW | 0 | dest surface pointer, initialised to 0 |
| this | 0x8 | RW | — | a6 parameter (surface type / mode flags) stored here |

**Written-by note (persistence):**
- this 0x0: once — set to DirectXTextureSurfaceFactory result; destroyed at function end via vtable Release(1)
- this 0x4: once — set to DirectXTextureSurfaceFactory result; destroyed at function end via vtable Release(1)
- this 0x8: once — set to input a6; not modified by external calls within this function

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00502f31 | sub_502F31 | final fallback surface processing (tried if all others fail) |
| 00504508 | SurfacePixelCopy | direct pixel row copy (tries first) |
| 00504640 | MemoryAllocationWithVectorConstructor | staging buffer alloc + fill via surface methods |
| 00504731 | sub_504731 | dual staging buffer surface transfer with overlap |
| 00504933 | Direct3DTextureResampling | 3D texture resampling with fixed-point scaling |
| 00504b37 | COMInterfaceVectorProcessingMethod | texture resize/compositing dispatch (try-all chain) |
| 00504f5a | MultiLevelBufferAllocationWithVectorOps | 3D texture downscale with trilinear averaging |
| 005054ec | sub_5054EC | bilinear texture resample with weighted float averaging |
| 005058d2 | VertexBufferAllocationAndStageTransformation | 3D trilinear texture resample with coord tables |
| 00506003 | sub_506003 | vertex weighted-blend transform with freelist |
| 005076fe | TextureCopyRealloc | validates/reallocates texture surface memory |
| 0050b8a9 | DirectXTextureSurfaceFactoryDispatchingFourCCCod | creates D3D texture surface objects by FourCC code |

**Guard conditions:** If a6 is zero, > 5, or has high bits set (0xFFF00000) → returns -2005530516 (D3DERR_INVALIDCALL). If source surface creation fails → jumps to cleanup returns -2147467259. If dest surface creation fails → jumps to cleanup. PASS: tries each transfer method in chain; first to return >= 0 → returns 0. If all fail → returns -2147467259.
