## TextureAllocationWithFormatSizeFlags_00558d10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_558A30 (00558a30), sub_558B30 (00558b30), PixelAttributeWriteToTexture (00558dc0), PixelWriteToTextureBuffer (00558e10), sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540f00 | BufferLockAllocate | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
