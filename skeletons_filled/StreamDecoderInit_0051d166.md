## StreamDecoderInit_0051d166 — Stream decoder sub-struct initialization

**Summary:** Allocates and initializes a 48-byte stream decoder sub-struct. Sets function pointers for stream processing, decoder logic, and state handling based on a mode flag: audio path (flag=2) with sample stream functions and buffer allocation, or texture/palette path with dispatch wrapper and color lookup functions. Delegates to WheelGeometryDataInitialization for final setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | Vtable[0]: memory allocator — allocates 48 bytes for decoder sub-struct |
| *(this+0x4) | 0x4 | R | — | Vtable[1]: buffer allocator — allocates streaming buffer (audio path only) |
| this | 0x4 | R | — | Vtable pointer for allocation dispatch |
| this | 0x5C | R | — | Dimension 1 — multiplied with offset 0x64 for buffer size |
| this | 0x64 | R | — | Dimension 2 — multiplied with offset 0x5C for buffer size |
| this | 0x110 | R | — | Mode flag — 2 selects audio stream path; other values select texture/palette path |
| this | 0x19C | RW | — | Pointer to allocated 48-byte decoder sub-struct (v1) |

**Written-by note (persistence):**
- this 0x19C: Written once with allocation result. Pointer persists until reallocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051cd3e | PhysicsObjectStateSetter | R | State handler — stored as v1[0] (first function pointer) |
| 0051cd53 | AudioSampleStream | R | Audio sample stream processor — installed as v1[1] for audio path |
| 0051cdf9 | VirtualDispatchWrapper_cdf9 | R | Generic virtual dispatch wrapper — installed as v1[1] for texture path |
| 0051ce2a | TexturePaletteColorLookup | R | Palette color lookup decoder — installed as v1[3] for texture path |
| 0051cf80 | sub_51CF80 | R | Stream decoder function — installed as v1[3] for audio path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x110 | == | 2 | Mode flag — if 2, initialize audio stream path (sample stream + buffer allocation). Otherwise, initialize texture palette path (dispatch wrapper + color lookup). |

**Guard interpretation:** If this+0x110 == 2 (audio mode): allocate streaming buffer of size (this+0x5C * this+0x64), set v1[1]=AudioSampleStream, v1[3]=sub_51CF80. If != 2 (texture mode): set v1[8]=0 (no buffer), v1[1]=VirtualDispatchWrapper_cdf9, v1[3]=TexturePaletteColorLookup. Both paths set v1[0]=PhysicsObjectStateSetter, v1[8+0] byte = 0, v1[10]=dimension product. Always finishes by calling WheelGeometryDataInitialization.
