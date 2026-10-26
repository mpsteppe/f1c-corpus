## StateResetWithCallback_00537000 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ArithmeticComparison_5620 (00535620), sub_5357E0 (005357e0), MultiBlockAllocator (00537070), TripleVTableCall (00537ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x30: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00539f60 | IndirectCallViaVTable0x24 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
