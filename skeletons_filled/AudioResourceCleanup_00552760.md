## AudioResourceCleanup_00552760 — FontTextureCleanup

**Summary:** Cleans up font/texture resources. Calls sub_53CB90 on the source surface pointer (offset 0x64) then zeroes it. If texture mode flag (bit 0x20000 in offset 0x24) is set, also releases the audio surface via ObjectResetWithVirtualRelease, frees the raw pointer at offset 0xC, and frees the font texture object at offset 0x868.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCompareLinkedListSearch (0053d130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Raw surface/object pointer (freed conditionally) |
| this | 0x24 | R | — | Flags (bit 0x20000 = texture mode; cleanup varies by path) |
| this | 0x64 | RW | 0 | Source surface pointer (cleared to 0 after sub_53CB90 call) |
| this | 0x868 | R | — | Font texture object pointer (freed via EmptyStub + FreeWrapper) |

**Written-by note (persistence):**
- this 0x64: zeroed after cleanup; survives external poke (value set to 0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager global — used for ObjectResetWithVirtualRelease |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053cb90 | sub_53CB90 | Releases/dereferences the source surface object |
| 00540eb0 | ObjectResetWithVirtualRelease | Resets a graphics object via virtual release; takes SoundManager and object pointer |
| 00557470 | EmptyStub_7470 | Empty stub (no-op) |
| 00587bcf | FreeWrapper_7bcf | Memory free wrapper |

**Guard conditions:** Always performs light cleanup (sub_53CB90, zero field). Full cleanup (ObjectResetWithVirtualRelease, FreeWrapper calls) only when bit 0x20000 is set in offset 0x24 (texture mode). BIT 0x20000 BLOCKED: skips audio/object cleanup path. BIT 0x20000 PASSED: performs full cleanup of audio surface, raw pointer, and font texture.
