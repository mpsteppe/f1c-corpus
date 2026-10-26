## DirectXTextureCreationWithMipmapChain_00507496 — DirectXTextureSurfaceConstructor

**Summary:** Constructs a DirectX texture/surface object from a source descriptor — copies format metadata, converts packed color to float RGBA, loads 256-entry palettes for indexed formats (types 40/41), and initializes the mipmap chain with a sub-object constructor. Render system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithSizeCountInit (0050a7c5), RenderBufferVertexAllocator (0050a7e1), RenderFormatConstructor (0050a8d9), VTableSetterWithSubInit (0050a8f5), sub_50A911 (0050a911), ShortComputation_ab19 (0050ab19), sub_50AB35 (0050ab35), ConstructorWithVTableSubInit (0050ae22), InitWithClass8 (0050ae3e), Constructor_ae5a (0050ae5a), ConstructorSize0x10 (0050ae76), RenderObjectConstructor (0050ae92), ObjectInitWithVTable_af3b (0050af3b), sub_50AFC6 (0050afc6), DirectXTextureSurfaceFormatInitialization (0050afe2), InitVTableSet_b1d4 (0050b1d4), ObjectInit_b1f0 (0050b1f0), ConstructorWithInit (0050b20c), ShortComputation_b228 (0050b228), sub_50B260 (0050b260), ObjectConstructor_b37d (0050b37d), RenderObjectConstructor_b399 (0050b399), RenderFormatConstructor2 (0050b3b5), VTableSetterWithSubInit_b3d1 (0050b3d1), sub_50B3ED (0050b3ed), ShortComputation_b409 (0050b409), sub_50B42A (0050b42a), ConstructorWithVTableSubInit_b446 (0050b446), InitWithClass0x10 (0050b462), Constructor_b727 (0050b727), ConstructorSize0x30 (0050b743), ObjectInitWithVTable_b77b (0050b77b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADB80) |
| this | 0x4 | RW | — | texture format/type ID (copied from source a2[1]) |
| this | 0x8 | RW | — | parameter a4 (usage hint / flags) |
| this | 0xC | RW | — | mip-level flag (a3 != 0, set to 1 if mipmaps present) |
| this | 0x10 | RW | — | color-key/ARGB packed DWORD from source a2[17] |
| this | 0x14 | RW | 1 | palette-format flag (1 for formats 40/41, else 0) |
| this | 0x18 | RW | — | first float from source (*a2) |
| this | 0x1C | RW | — | float color R channel (BYTE2 of packed color / 255) |
| this | 0x20 | RW | — | float color G channel (BYTE1 / 255) |
| this | 0x24 | RW | — | float color B channel (byte0 / 255) |
| this | 0x28 | RW | — | float color A channel (HIBYTE / 255) |
| this | 0x2C | RW | — | pointer to render-target/temp data (unk_5D7748 or unk_5D76C8) |
| this | 0x34 | RW | — | palette entry 0 (RGBA float) for 256-entry palette |
| this | 0x38 | RW | — | palette entry 1 |
| this | 0x3C | RW | — | palette entry 2 |
| this | 0x1030 | RW | — | texture dimension field (from a2[10]) |
| this | 0x1034 | RW | — | texture dimension field (from a2[11]) |
| this | 0x1038 | RW | — | texture dimension field (from a2[12]) |
| this | 0x103C | RW | — | texture dimension field (from a2[13]) |
| this | 0x1040 | RW | — | texture dimension field (from a2[14]) |
| this | 0x1044 | RW | — | texture dimension field (from a2[2]) |
| this | 0x1048 | RW | — | texture dimension field (from a2[3]) |
| this | 0x104C | RW | — | computed width delta (a2[13]-a2[11]) |
| this | 0x1050 | RW | — | computed height delta (a2[15]-a2[14]) |
| this | 0x1054 | RW | — | computed depth/size delta |
| this | 0x1058 | RW | — | mipmap stride/pitch (a3 >> 3) |
| this | 0x105C | RW | — | adjusted dimension (delta * mip-stride) |
| this | 0x1060 | RW | — | zeroed accumulator (float) |
| this | 0x1064 | RW | — | zeroed accumulator (float) |
| this | 0x1068 | RW | — | adjusted dimension (copied from delta) |

**Written-by note (persistence):**
- this 0x0: written once (construction) — external poke does NOT survive
- this 0x4: written once (construction) — external poke does NOT survive
- this 0x8: written once (construction) — external poke does NOT survive
- this 0xC: written once (construction) — external poke does NOT survive
- this 0x10: written once (construction) — external poke does NOT survive
- this 0x14: written once (construction) — external poke does NOT survive
- this 0x18: written once (construction) — external poke does NOT survive
- this 0x1C: written once (construction) — external poke does NOT survive
- this 0x20: written once (construction) — external poke does NOT survive
- this 0x24: written once (construction) — external poke does NOT survive
- this 0x28: written once (construction) — external poke does NOT survive
- this 0x2C: written once (construction) — external poke does NOT survive
- this 0x34: written once (construction) — external poke does NOT survive
- this 0x38: written once (construction) — external poke does NOT survive
- this 0x3C: written once (construction) — external poke does NOT survive
- this 0x1030: written once (construction) — external poke does NOT survive
- this 0x1034: written once (construction) — external poke does NOT survive
- this 0x1038: written once (construction) — external poke does NOT survive
- this 0x103C: written once (construction) — external poke does NOT survive
- this 0x1040: written once (construction) — external poke does NOT survive
- this 0x1044: written once (construction) — external poke does NOT survive
- this 0x1048: written once (construction) — external poke does NOT survive
- this 0x104C: written once (construction) — external poke does NOT survive
- this 0x1050: written once (construction) — external poke does NOT survive
- this 0x1054: written once (construction) — external poke does NOT survive
- this 0x1058: written once (construction) — external poke does NOT survive
- this 0x105C: written once (construction) — external poke does NOT survive
- this 0x1060: written once (construction) — external poke does NOT survive
- this 0x1064: written once (construction) — external poke does NOT survive
- this 0x1068: written once (construction) — external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | callback passed to sub_5008C2 for sub-object initialization |
| 0059e460 | flt_59E460 | R | AlphaScaleFactor [DERIVED] |
| 005adb80 | off_5ADB80 | R | VTable_5ADB80 [DERIVED] |
| 005d76c8 | unk_5D76C8 | R | TextureTempDataPointer [DERIVED] (also: ` — constant data pointer for temporary state) |
| 005d7748 | unk_5D7748 | R | TextureRenderTargetData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | initializes embedded sub-object (mipmap chain handler) with size 16, count 256, and callback sub_5007EC |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | mip-level flag — if 0 (no mipmaps) BLOCKED: skip delta-rect adjustment computation |

**Guard interpretation:** Single guard at the end: if this+0xC (the mip-level flag, set earlier from `a3 != 0`) equals 0, BLOCKED — the texture dimension delta adjustment code is skipped. If non-zero, PASSES — accumulated origin + delta * stride computation executes, advancing the mip rect origin for the next level.
