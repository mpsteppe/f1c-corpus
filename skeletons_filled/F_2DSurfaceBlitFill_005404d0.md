## F_2DSurfaceBlitFill_005404d0 — SurfaceBlitFillDispatch

**Summary:** Dispatches 2D surface blit/fill operations based on surface flags. Handles texture blit path (0x40000 flag), surface lock/unlock via vtable calls, and pixel fill loops for 32-bit RGBA (case 8) and 16-bit (default) formats using memset32. Part of 2D rendering/surface management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatClampWithEventDispatch (004082b0), sub_53F720 (0053f720), RenderDrawOperationWithClipping (00543440), sub_5434A0 (005434a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x90 | R | — | sub-object field read during surface operation dispatch |
| this | 0x0 | RW | — | output status/result, set from surface lock/unlock return values |
| this | 0x1100 | R | — | sub-object pointer (surface/texture context) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00540750 | jpt_54063B | R | jump table for pixel format switch in fill loop |
| 00540758 | byte_540758 | R | pixel format mapping/lookup table |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055ca90 | sub_55CA90 | unknown, called before/after texture blit operation |
| 0055ceb0 | RGBAByteExtraction | extract RGBA byte values from pixel format for fill operations |

**Guard conditions:**
- `a2[6] & 0x40000`: texture blit path — call sub_55CA90, dispatch via vtable+144, return 0 (skip fill)
- `a2[6] & 1`: select surface handle from a2[2]; `a2[6] & 2`: select from a2[3]; if surface is 0/null: skip lock/unlock
- `a2[6] & 4`: select surface handle from a2[4]; `a2[6] & 8`: select from a2[5]; if 0/null: skip lock/unlock
- Case 8 (32-bit RGBA): fast memset32 fill loop with pitch adjustment
- Default case (16-bit etc): RGBAByteExtraction then memset32 with 16-bit pattern, handles odd-pixel remainder
- Post-fill: surface unlock via vtable+40 (if flag&1/2) and vtable+68 (if flag&4/8)
- BLOCKED: surface lock failure returns -1
