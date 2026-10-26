## sub_58AFE1_0058afe1 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_5354E0 (005354e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e7898 | unk_5E7898 | R | DefaultBufferDescriptor [DERIVED] |
| 008d4920 | dword_8D4920 | R | CriticalSectionArray (stride 0x24) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a05a | BufferFlushWrite | [LLM] |
| 0058c1b1 | StreamBufferLockViaCriticalSection | [LLM] |
| 0058c203 | AddressRangeCriticalSectionLeave | [LLM] |
| 0058c724 | sub_58C724 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
