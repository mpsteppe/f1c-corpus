## MSVCCRTFileClose_00587d33 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FileCloseWithLock (00587d02)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a05a | BufferFlushWrite | [LLM] |
| 0058aa6f | sub_58AA6F | [LLM] |
| 0058c331 | sub_58C331 | [LLM] |
| 0058c411 | sub_58C411 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
