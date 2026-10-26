## DirectXTextureSurfaceFormatInitialization_0050afe2 — DirectX Texture Surface Wrapper Initialization

**Summary:** Initializes a DirectX texture surface wrapper object by setting the vtable, mapping source surface format flags to internal state, selecting FourCC-specific function pointers (for encoding/decoding), and computing aligned surface dimensions with stride values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50B797 (0050b797), ObjectInit_b7cb (0050b7cb), ConstructorWithInit_b7e3 (0050b7e3), ShortComputation_b7fb (0050b7fb), ShortComputation_b813 (0050b813)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer: set to off_5ADB90 (D3D wrapper vtable) |
| this | 0x4 | R | — | FourCC pixel format code (used in switch to select function pointers) |
| this | 0x1030 | R | — | source surface width (from a2+24 = offset 0x18 in source struct) |
| this | 0x1034 | R | — | source surface height (from a2+28) |
| this | 0x1038 | R | — | source surface: raw width (unaligned, from a2+0x1038) |
| this | 0x103C | R | — | source surface: raw height (unaligned, from a2+0x103C) |
| this | 0x1040 | R | — | source surface: pitch/stride (from a2+0x1040) |
| this | 0x1044 | R | — | source surface: depth or additional dimension (from a2+0x1044) |
| this | 0x1074 | RW | — | internal format type flag (0=identity, 1=standard, 3=fallback; derived from a2 surface type) |
| this | 0x1078 | RW | 3 | format negotiation result for source surface dim 1 (0/1/2→0/1/3 mapped) |
| this | 0x107C | RW | 3 | format negotiation result for source surface dim 2 (0/1/2→0/1/3 mapped) |
| this | 0x1080 | RW | 16 | bytes-per-pixel or block size (8 or 16, selected by FourCC switch) |
| this | 0x1084 | RW | — | function pointer slot 1: format-specific encoder/processor (e.g. FileIOWrapper) |
| this | 0x1088 | RW | — | function pointer slot 2: format-specific decoder/validator (e.g. KeyframeQuadInterpolation) |
| this | 0x108C | RW | — | aligned source width (raw width aligned to 4-byte boundary) |
| this | 0x1090 | RW | — | aligned source height (raw height aligned to 4-byte boundary) |
| this | 0x1094 | RW | — | aligned width (computed: (raw_width+3) & ~3) |
| this | 0x1098 | RW | — | aligned height (computed: (raw_height+3) & ~3) |
| this | 0x109C | RW | — | horizontal block count: (aligned_width - aligned_src_width) / 4 |
| this | 0x10A0 | RW | — | source pitch/stride (copied from a2+0x1044) |
| this | 0x10A4 | RW | — | vertical block count: (aligned_height - aligned_src_height) / 4 |
| this | 0x10A8 | RW | — | pitch difference: source_pitch - source_width (stride delta) |
| this | 0x10AC | RW | — | total byte size or additional stride field |
| this | 0x10B0 | RW | 18446744073709551615 | sentinel / invalid handle marker (-1, ~0xFFFFFFFF) |
| this | 0x10B4 | RW | 18446744073709551615 | sentinel / invalid handle marker 2 (-1) |
| this | 0x10B8 | RW | 0 | frame counter or lock state zeroed |
| this | 0x10BC | RW | 0 | frame counter or lock state 2 zeroed |
| this | 0x10C0 | RW | 0 | frame counter or lock state 3 zeroed |

**Written-by note (persistence):**
- this 0x0: vtable set once at construction — external poke may survive until re-init
- this 0x1074: written once from source surface type — external poke does NOT persist across re-init
- this 0x1078: written once from source surface dims — external poke does NOT persist across re-init
- this 0x107C: written once from source surface dims — external poke does NOT persist across re-init
- this 0x1080: written once per FourCC — external poke does NOT persist across re-init
- this 0x1084: written once per FourCC — external poke does NOT persist across re-init
- this 0x1088: written once per FourCC — external poke does NOT persist across re-init
- this 0x108C: written once from source dims — external poke does NOT persist across re-init
- this 0x1090: written once from source dims — external poke does NOT persist across re-init
- this 0x1094: computed from aligned width — external poke does NOT persist across re-init
- this 0x1098: computed from aligned height — external poke does NOT persist across re-init
- this 0x109C: computed block count — external poke does NOT persist across re-init
- this 0x10A0: copied from source pitch — external poke does NOT persist across re-init
- this 0x10A4: computed block count — external poke does NOT persist across re-init
- this 0x10A8: computed stride delta — external poke does NOT persist across re-init
- this 0x10AC: computed size field — external poke does NOT persist across re-init
- this 0x10B0: sentinel init — external poke does NOT persist across re-init
- this 0x10B4: sentinel init — external poke does NOT persist across re-init
- this 0x10B8: zeroed on init — external poke does NOT persist across re-init
- this 0x10BC: zeroed on init — external poke does NOT persist across re-init
- this 0x10C0: zeroed on init — external poke does NOT persist across re-init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00514fee | KeyframeQuadInterpolationWithBitPackedSelector | R | function pointer for FourCC 0x31534D44 ("DMS1"): decoder/processor |
| 0051512c | sub_51512C | R | function pointer for FourCC 0x33534D44 ("DMS3"): decoder |
| 005151af | sub_5151AF | R | function pointer for FourCC 0x35534D44 ("DMS5"): decoder |
| 005152eb | FileIOWrapper | R | function pointer for FourCC 0x31534D44: encoder/file-io |
| 00515303 | QuantizationColorSpaceConversion | R | function pointer for FourCC 0x33534D44: encoder/color conversion |
| 00515417 | sub_515417 | R | function pointer for FourCC 0x35534D44: encoder |
| 00515869 | FileOpenAndValidate | R | function pointer for FourCC 0x32534D44 ("DMS2"): decoder |
| 0051588c | sub_51588C | R | function pointer for FourCC 0x34534D44 ("DMS4"): decoder |
| 005158af | DelegationWithErrorCheck | R | function pointer for FourCC 0x32534D44: encoder/delegation |
| 005158e3 | InitProcessWrapper | R | function pointer for FourCC 0x34534D44: encoder |
| 005adb90 | off_5ADB90 | R | VTable_D3DWrap [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | creates the underlying DirectX texture object with mipmap chain, setting up the D3D surface |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1078 | != | 3 | format type flag 1: when both flags are non-default (both !=3), sets combined flag at 0x1074 to TRUE |
| this | 0x107C | != | 3 | format type flag 2: combined with flag 1 via OR — both must be non-3 for the active flag |

**Guard interpretation:** After mapping source surface dimension types (1→0, 2→1, else→3), the two dimension format flags at offsets 0x1078 and 0x107C are compared to the sentinel value 3. If BOTH are != 3 (both dimensions were type 1 or 2, PASSES), the combined active flag at offset 0x1074 is set to 1 (TRUE). If either is 3 (BLOCKED for that dimension), the flag is set to 0 (FALSE). This combined flag likely controls whether the surface supports hardware-accelerated format conversion.
