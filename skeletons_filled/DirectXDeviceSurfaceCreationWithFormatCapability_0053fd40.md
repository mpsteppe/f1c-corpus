## DirectXDeviceSurfaceCreationWithFormatCapability_0053fd40 — DirectX surface blit with format-aware sourcing

**Summary:** Selects source and destination surfaces based on flag bitmask (a3/a5 params: 1/2/4/8), performs blit via SurfaceBlitOperation with alpha fill color, releases temporary surfaces via vtable[2] call, and optionally performs D3DSurfaceCopyBlit when a4[11] > 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5429B0 (005429b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | stores return values from vtable calls |

**Written-by note (persistence):**
- this 0x0: overwritten by each call — last error code persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050099c | SurfaceBlitOperation | performs surface blit with fill color |
| 00500bc8 | D3DSurfaceCopyBlit | copies surface data (when a4[11] > 1) |
| 0053f720 | sub_53F720 | allocates/initializes the destination surface |
| 0055c650 | sub_55C650 | format conversion helper |

**Guard conditions:** a6 & 0x1000000 — if set, skips entire blit pipeline. Source/destination selected based on a3/a5 bits (1=first surface, 2=second, 4=fourth, 8=fifth). Sub-object (a2/a4) fields checked for null before vtable[15] call.
