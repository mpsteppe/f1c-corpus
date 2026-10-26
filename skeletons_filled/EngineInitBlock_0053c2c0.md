## EngineInitBlock_0053c2c0 — EngineStateBlockInit

**Summary:** Initializes an engine state block by zeroing fields and setting global renderer/audio state constants. Empties MMX state via _m_empty(). Called during system initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SystemInitAllocatorWrapper (0053d470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Engine block first DWORD field |
| this | 0x4 | RW | 0 | Engine block second DWORD field |
| this | 0x2C | RW | 0 | Engine block eleventh DWORD field (index/count) |

**Written-by note (persistence):**
- this 0x0: once on init; external poke survives
- this 0x4: once on init; external poke survives
- this 0x2C: once on init; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b6bd0 | unk_8B6BD0 | R | UTF16_Buffer [DERIVED] |
| 008b6c20 | qword_8B6C20 | W | RendererStateFlag [DERIVED] |
| 008b8e40 | qword_8B8E40 | W | AudioMixFixedPointConst [DERIVED] |
| 008b8ed8 | qword_8B8ED8 | W | AudioPlaybackRate [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-initializes the entire engine block |
| 00556260 | sub_556260 | Initialization sub-routine called with parameter 1 |

**Guard conditions:** No guard conditions — function unconditionally initializes the block and globals.
