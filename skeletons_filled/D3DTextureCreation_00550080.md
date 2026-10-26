## D3DTextureCreation_00550080 — TextureCreationWithScalingAndFormatSelect

**Summary:** Creates D3D texture with mip level calculation, size scaling against sound manager limits, and render format selection based on flags and device capabilities.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleNodeCreation (0049e930), AudioSoundCreateWithHandle (0049e9a0), sub_4D8CF0 (004d8cf0), sub_4DCBA0 (004dcba0), sub_546450 (00546450), sub_546AA0 (00546aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x2C | RW | — | Texture internal mip/LOD field (written with computed level) |
| this | 0x44 | R | — | Texture creation flags bitfield (bit 0 controls size-scaling skip) |
| this | 0x50 | RW | — | Computed mip level, read/written during dimension halving loop |
| this | 0x54 | R | — | Pointer to D3D texture object / internal resource struct |

**Written-by note (persistence):**
- *(this+0x54) 0x2C: Written once after sub_5429B0 succeeds; external poke persists until next creation call
- this 0x50: Written conditionally; external poke overwritten by subsequent creation call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005b8908 | dbl_5B8908 | R | Unknown_dbl_5B8908 [DERIVED] |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |
| 008b8e28 | dword_8B8E28 | R | AudioInitialized [DERIVED] |
| 008b8e2c | dword_8B8E2C | R | RendererMipmapFlag [DERIVED] |
| 008b8e4c | dword_8B8E4C | R | MipLODBiasCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d890 | IndexedArrayAccess_d890 | Access sound manager working array for size limit check |
| 005427d0 | sub_5427D0 | Parse texture description string into width/height values |
| 005429b0 | sub_5429B0 | Create D3D texture with computed parameters |
| 005435c0 | sub_5435C0 | Set color key on texture when 0x800 flag is set |
| 0054fe50 | sub_54FE50 | Initialize texture creation context |
| 005502c0 | DestructorWithConditionalFreeFlagClear | Clean up and free on creation failure |
| 0055bfc0 | SimpleFieldGetter_bfc0 | Get current sound manager slot index |
| 0055c3c0 | GetVTableParamBasedOnFlagBits | Query render device for texture format |
| 0055c7f0 | KeyEventDispatchToSubHandlers | Resolve format variant via event dispatch with 0x200000 param |
| 0055c9a0 | MaskedFieldGetter | Check renderer state mask for mipmap condition |
| 00587bdc | CRTFtol | Convert double to int (mip level log2 calculation) |

**Guard conditions:** 
- sub_5427D0 returns -1: parse failure → jump to LABEL_2 (destructor + return -1). PASS when != -1.
- sub_5429B0 returns non-zero: texture creation failure → jump to LABEL_2. PASS when returns 0.
- this+0x44 bit 0 set: skip entire size-scaling loop (lines 38-80). PASS when bit 0 clear (scaling runs), BLOCKED when bit 0 set.
- v22 < *(v11+284) && v13 < *(v11+288): exit dimension halving loop early (PASS loop, BLOCKED when within limits).
