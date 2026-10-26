## BitStreamWriter_00539690 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BitstreamEncoder (00537fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x16AB | RW | 0 | [LLM] |
| this | 0x16AC | R | — | [LLM] |
| this | 0x16AD | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x16AB: recalc every frame — external poke does NOT persist
- this 0x16AD: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
