## ConditionalFreeByFlag_28b0_005528b0 — ConditionalFreeByFlag

**Summary:** Conditionally frees a graphics surface object. If flag bit 0x20000 at offset 0x24 is set, calls ObjectResetWithVirtualRelease on the pointer at offset 0xC, frees it via FreeWrapper_7bcf, and zeroes the field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderTargetCleanup (0053f270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | Graphics surface/object pointer (freed and zeroed) |
| this | 0x24 | R | — | Flags (bit 0x20000 = texture/surface mode gate) |

**Written-by note (persistence):**
- this 0xC: zeroed after conditional free; survives external poke (set to 0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager global — passed to ObjectResetWithVirtualRelease |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | Resets/releases a graphics surface object via virtual function |
| 00587bcf | FreeWrapper_7bcf | Memory free wrapper |

**Guard conditions:** BIT 0x20000 NOT set: skip entirely, return 0 immediately. BIT 0x20000 SET: reset via ObjectResetWithVirtualRelease, free heap pointer, zero field.
