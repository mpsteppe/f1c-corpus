## ConditionalFieldSetter_0d40_00540d40 — Conditional buffer/surface setter via bitmask

**Summary:** Conditionally allocates buffer lock at a1[8] (via BufferLockAllocate) when a2 bit 4 set, and surface blit lock at a1[10] (via SurfaceBlitLockWithFlagCheck) when a2 bit 8 set. No-op if a1 is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557670 (00557670), sub_558310 (00558310)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | this[2] — parameter passed to BufferLockAllocate |
| this | 0x10 | R | — | this[4] — parameter passed to SurfaceBlitLockWithFlagCheck |
| this | 0x1C | R | — | this[7] — first arg to BufferLockAllocate (buffer pointer) |
| this | 0x20 | RW | — | this[8] — receives result of BufferLockAllocate |
| this | 0x24 | R | — | this[9] — first arg to SurfaceBlitLockWithFlagCheck (surface pointer) |
| this | 0x28 | RW | — | this[10] — receives result of SurfaceBlitLockWithFlagCheck |
| this | 0x2C | R | — | this[11] — parameter passed to BufferLockAllocate |
| this | 0x30 | R | — | this[12] — parameter passed to SurfaceBlitLockWithFlagCheck |

**Written-by note (persistence):**
- this 0x20: written by BufferLockAllocate — persists until cleaned/replaced
- this 0x28: written by SurfaceBlitLockWithFlagCheck — persists until cleaned/replaced

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540f00 | BufferLockAllocate | allocates buffer lock resource |
| 00541090 | SurfaceBlitLockWithFlagCheck | allocates surface blit lock with flag validation |

**Guard conditions:** If a1 is null → no-op. If a2 & 4 → allocate buffer lock at this[8]. If a2 & 8 → allocate surface blit lock at this[10].
