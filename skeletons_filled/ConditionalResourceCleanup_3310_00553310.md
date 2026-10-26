## ConditionalResourceCleanup_3310_00553310 — ResourceCleanupByTypeFlag

**Summary:** Frees graphics resources based on type flags at offset 0x0. If bit 0 or bit 1 set: frees the raw pointer at offset 0x18. Always: if pointer at offset 0x14 is non-null, calls ObjectResetWithVirtualRelease then FreeWrapper_7bcf and zeroes field. Calls global EmptyStub_0170.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCascadeCleanup (005539f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Resource type flags (bit 0 = type A, bit 1 = type B; if either set, frees offset 0x18) |
| this | 0x14 | RW | 0 | Primary resource pointer (released via ObjectResetWithVirtualRelease, then freed) |
| this | 0x18 | RW | 0 | Secondary resource pointer (freed directly if type flags indicate) |

**Written-by note (persistence):**
- this 0x14: zeroed after cleanup; survives external poke (set to 0)
- this 0x18: zeroed after conditional cleanup; survives external poke (set to 0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager global — passed to ObjectResetWithVirtualRelease |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | Releases a graphics surface object via virtual function dispatch |
| 00587bcf | FreeWrapper_7bcf | Memory free wrapper |

**Guard conditions:** BITS 0/1 at offset 0x0: if NEITHER set, skips freeing offset 0x18. Always frees offset 0x14 if non-null, regardless of flags. No guard on offset 0x14 pointer: only freed if non-null.
