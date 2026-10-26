## AppendNodeToDoublyLinkedListTail_00560eb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DoublyLinkedListNodeMover (0054ba00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x60)+0x34) | 0x34 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x60)+0x34) 0x34: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
