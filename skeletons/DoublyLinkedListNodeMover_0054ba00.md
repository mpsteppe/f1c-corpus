## DoublyLinkedListNodeMover_0054ba00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitCrewMeshLoader (004a2010), LazyInitCallback (004e0d00), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x90)+0x4C) | 0x4C | RW | — | [LLM] |
| *(this+0x90) | 0x4C | R | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x230 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x90)+0x4C) 0x4C: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00544c50 | TreeNodeAccumulator | [LLM] |
| 00560eb0 | AppendNodeToDoublyLinkedListTail | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
