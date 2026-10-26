## BitstreamEncoder_00537fe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_535E80 (00535e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x16A7 | RW | 7 | [LLM] |
| this | 0x16AB | RW | 0 | [LLM] |
| this | 0x16AC | R | — | [LLM] |
| this | 0x16AD | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x16A7: recalc every frame — external poke does NOT persist
- this 0x16AB: recalc every frame — external poke does NOT persist
- this 0x16AD: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00539690 | BitStreamWriter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
