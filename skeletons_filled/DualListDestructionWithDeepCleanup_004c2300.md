## DualListDestructionWithDeepCleanup_004c2300 — PitStop State Teardown with Dual LinkedList Cleanup

**Summary:** Destroys two linked lists of pit-stop memory allocations: the first list has simple node-cleanup, the second has deep nested cleanup (freeing sub-objects within each node). Resets all pit-stop state fields and restores a UI option value. Part of the pit-stop memory management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_5StepInit (004b0720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | next node pointer in first linked list |
| *(this+0x10) | 0x0 | R | — | first list head pointer (pit-stop plan list) |
| *(this+0x10) | 0x8 | R | — | byte flag: skip deep cleanup if 0 (shallow-free flag) |
| *(this+0x14) | 0x4 | R | — | next node pointer in second linked list |
| obj | 0x0 | R | — | data payload pointer in first-list node |
| obj | 0x8 | R | — | byte flag in first-list node (deep-free guard: 0=skip PitStopMemoryCleanup) |
| this | 0x0 | RW | 0 | first linked-list head pointer (pit-stop task list A) |
| this | 0x4 | RW | 0 | first linked-list tail pointer |
| this | 0x8 | RW | 0 | first linked-list count / sentinel |
| this | 0xC | RW | 0 | first linked-list secondary sentinel |
| this | 0x10 | RW | 0 | second linked-list head pointer (pit-stop task list B) |
| this | 0x14 | RW | 0 | second linked-list tail pointer |
| this | 0x18 | RW | 0 | second linked-list count / secondary ptr (deep-free flag = 0) |
| this | 0x1C | RW | 0 | second linked-list sentinel field |
| this | 0x20 | RW | 0 | unlisted field (zeroed block) |
| this | 0x24 | RW | 0 | unlisted field (zeroed block) |
| this | 0x28 | RW | 0 | unlisted field (zeroed block) |
| this | 0x2C | RW | 0 | unlisted field (zeroed block) |
| this | 0x30 | RW | 0 | unlisted field (zeroed block) |
| this | 0x34 | RW | 0 | unlisted field (zeroed block) |
| this | 0x38 | RW | 0 | unlisted field (zeroed block) |
| this | 0x3C | RW | 0 | unlisted field (zeroed block) |
| this | 0x40 | RW | 0 | unlisted field (zeroed block) |
| this | 0x44 | RW | 0 | unlisted field (zeroed block) |
| this | 0x48 | RW | 0 | unlisted field (zeroed block) |
| this | 0x4C | RW | 0 | unlisted field (zeroed block) |
| this | 0x50 | RW | 0 | unlisted field (zeroed block) |
| this | 0x54 | RW | 0 | unlisted field (zeroed block) |
| this | 0x58 | RW | 0 | unlisted field (zeroed block) |
| this | 0x5C | RW | 0 | unlisted field (zeroed block) |
| this | 0x60 | RW | 0 | unlisted field (zeroed block) |
| this | 0x64 | RW | 0 | unlisted field (zeroed block) |
| this | 0x68 | RW | 0 | unlisted field (zeroed block) |
| this | 0x6C | RW | 1 | reset-to-default flag (boolean, set true) |
| this | 0x70 | RW | 0 | unlisted field (zeroed block) |
| this | 0x74 | RW | 0 | unlisted field (zeroed block) |
| this | 0x78 | RW | 0 | unlisted field (zeroed block) |
| this | 0x7C | RW | 0 | unlisted field (zeroed block) |
| this | 0x80 | RW | — | UI option restore value (copied from global) |
| this | 0x84 | RW | 0 | unlisted field (zeroed block) |
| this | 0x88 | RW | 0 | unlisted field (zeroed block) |
| this | 0x8C | RW | 0 | unlisted field (zeroed block) |

**Written-by note (persistence):**
- this 0x0: written once during teardown — external poke does NOT persist (overwritten by zero)
- this 0x4: written once during teardown — external poke does NOT persist
- this 0x8: written once during teardown — external poke does NOT persist
- this 0xC: written once during teardown — external poke does NOT persist
- this 0x10: written once during teardown — external poke does NOT persist
- this 0x14: written once during teardown — external poke does NOT persist
- this 0x18: written once during teardown — external poke does NOT persist
- this 0x1C: written once during teardown — external poke does NOT persist
- this 0x20: written once during teardown — external poke does NOT persist
- this 0x24: written once during teardown — external poke does NOT persist
- this 0x28: written once during teardown — external poke does NOT persist
- this 0x2C: written once during teardown — external poke does NOT persist
- this 0x30: written once during teardown — external poke does NOT persist
- this 0x34: written once during teardown — external poke does NOT persist
- this 0x38: written once during teardown — external poke does NOT persist
- this 0x3C: written once during teardown — external poke does NOT persist
- this 0x40: written once during teardown — external poke does NOT persist
- this 0x44: written once during teardown — external poke does NOT persist
- this 0x48: written once during teardown — external poke does NOT persist
- this 0x4C: written once during teardown — external poke does NOT persist
- this 0x50: written once during teardown — external poke does NOT persist
- this 0x54: written once during teardown — external poke does NOT persist
- this 0x58: written once during teardown — external poke does NOT persist
- this 0x5C: written once during teardown — external poke does NOT persist
- this 0x60: written once during teardown — external poke does NOT persist
- this 0x64: written once during teardown — external poke does NOT persist
- this 0x68: written once during teardown — external poke does NOT persist
- this 0x6C: written once during teardown — external poke does NOT persist
- this 0x70: written once during teardown — external poke does NOT persist
- this 0x74: written once during teardown — external poke does NOT persist
- this 0x78: written once during teardown — external poke does NOT persist
- this 0x7C: written once during teardown — external poke does NOT persist
- this 0x80: written once during teardown — external poke does NOT persist
- this 0x84: written once during teardown — external poke does NOT persist
- this 0x88: written once during teardown — external poke does NOT persist
- this 0x8C: written once during teardown — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d0a24 | dword_7D0A24 | R | UIOptionRestoreValue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0b10 | PitStopMemoryCleanup | deep-clean a pit-stop task node (free nested allocations) |
| 00587bcf | FreeWrapper_7bcf | generic memory deallocation wrapper (operator delete) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x8 | == | 0 | first-list node shallow-free flag: skip PitStopMemoryCleanup on this node |
| this | 0x18 | == | 0 | second-list node deep-free flag: skip nested pointer cleanup in node |

**Guard interpretation:** In list 1, when a node's byte at offset 0x8 is 0, the node's data payload is freed directly (FreeWrapper_7bcf) without calling PitStopMemoryCleanup (shallow free). When non-zero, PitStopMemoryCleanup is called first for deep cleanup. In list 2, the guard at this+0x18 controls whether nested sub-pointers (at offsets 0 and 8 within the payload) are individually freed before the payload itself. Zero means BLOCK deep cleanup (skip nested frees); non-zero PASSES through to deep cleanup.