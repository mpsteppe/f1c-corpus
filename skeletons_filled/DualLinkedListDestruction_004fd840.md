## DualLinkedListDestruction_004fd840 — DualLinkedListDestruction

**Summary:** Destroys two linked lists: first list iterated from this+0x3C (node next at +0xC), second from this+0x54 (each node: pointer at +0, next at +4, flag at +8). Frees all nodes and conditionally frees sub-pointers if flag is non-zero. Clears tracking fields at offsets 0x38-0x3C and 0x54-0x60.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0), sub_4FCC30 (004fcc30), sub_4FD8B0 (004fd8b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x54)+0x4) | 0x4 | R | — | second list node's next pointer |
| *(this+0x3C) | 0xC | R | — | first list node's next pointer (offset 12 within node) |
| *(this+0x54) | 0x0 | R | — | second list node's sub-pointer (freed if flag set) |
| *(this+0x54) | 0x8 | R | — | second list node's flag byte (0 = skip sub-pointer free) |
| this | 0x38 | RW | 0 | first list count/field (cleared to 0) |
| this | 0x3C | RW | — | first list head pointer (iterated, nodes freed) |
| this | 0x54 | RW | 0 | second list head pointer (iterated, cleared to 0) |
| this | 0x58 | RW | 0 | second list tracking field (cleared to 0) |
| this | 0x5C | RW | 0 | second list tracking field (cleared to 0) |
| this | 0x60 | RW | 0 | second list tracking field (saved then cleared to 0) |

**Written-by note (persistence):**
- this 0x38: unconditionally cleared to 0
- this 0x3C: conditionally iterated (nodes freed), then left as-is after iteration
- this 0x54: unconditionally cleared to 0 after second list iteration
- this 0x58: unconditionally cleared to 0
- this 0x5C: unconditionally cleared to 0
- this 0x60: unconditionally cleared to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | heap memory deallocation (frees nodes and sub-pointers) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x54) | 0x8 | == | 0 | second list node's flag byte |

**Guard interpretation:** Check applies per-node in second list. PASSES (sub-pointer freed) when flag byte is non-zero. BLOCKED (sub-pointer preserved) when flag == 0 — node itself is still freed, but sub-pointer memory is left alone. First list always frees all nodes unconditionally.
