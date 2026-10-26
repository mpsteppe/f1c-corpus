## TwoFieldInitializer_e0b4_0058e0b4 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TLSAllocationThreadIDInit (0058e060), TLSValueRetrievalWithInit (0058e0c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | 1 | [LLM] |
| this | 0x50 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e7810 | unk_5E7810 | R | VtablePtr_5E7810 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
