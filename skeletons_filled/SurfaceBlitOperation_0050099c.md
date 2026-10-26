## SurfaceBlitOperation_0050099c — SurfaceBlitOperation

**Summary:** Performs D3D surface blit between source and destination surfaces. Attempts direct hardware blit when surfaces are compatible (same pixel format/size), falls back to CPU-side lock-copy via D3DTextureSurfaceLockCopy and NetworkPacketSendReceive. Cleans up render resources on exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DSurfaceCopyBlit (00500bc8), sub_53FC30 (0053fc30), DirectXDeviceSurfaceCreationWithFormatCapability (0053fd40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x20 | R | — | Vtable entry offset 32 (GetSurfaceDesc / surface info query) |
| this | 0x0 | R | — | Vtable pointer for D3D surface object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050070d | NetworkPacketSendReceive | Perform D3D surface data transfer (lock source, copy pixels, unlock destination) |
| 00500eac | sub_500EAC | Increment/decrement lock state counter (arg 1 = enter, 0 = leave) |
| 005064bf | ZeroInit4Ints_64bf | Zero-initialize temporary render resource struct |
| 00506554 | j_RenderResourceTeardown | Release temporary render resources |
| 00506559 | D3DTextureSurfaceLockCopy | Lock source texture and copy pixel data (fallback path) |

**Guard conditions:** If a1 (source) is NULL → return -2005530516 (D3DERR_INVALIDCALL). If a4 (destination) is NULL → return -2005530516. Color key check: if a7 != 5 AND !a8 AND surfaces are identical (same pointer or memcmp returns 0 for 0x400 bytes) → attempt direct blit. If rectangle dimensions mismatch → fallback to lock-copy path. If a1 == a9 (same surface) → use 65537 (D3DLOCK_READONLY?) flag for lock.
