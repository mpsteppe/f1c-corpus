## F_2DSurfaceBlitFill_005404d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatClampWithEventDispatch (004082b0), sub_53F720 (0053f720), RenderDrawOperationWithClipping (00543440), sub_5434A0 (005434a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x90 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1100 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00540750 | jpt_54063B | R | [LLM] |
| 00540758 | byte_540758 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055ca90 | sub_55CA90 | [LLM] |
| 0055ceb0 | RGBAByteExtraction | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
