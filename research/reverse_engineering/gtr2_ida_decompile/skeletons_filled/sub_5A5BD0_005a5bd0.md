## sub_5A5BD0_005a5bd0 — queue drain variant B: dequeue+dispatch items, free second list

**Summary:** Same mutex-guarded queue-drain pattern as sub_5A5A90 but on a second queue pair: pops nodes from the queue at this+0x570 clearing each node's byte flag, dispatching non-null payloads via the virtual method at vtable+0x5C, then drains the list at this+0x58C and frees nodes plus flag-marked payloads. Asynchronous item-queue/worker system for a second channel.

**Called by:** sub_5A01D0 (005a01d0), sub_5A03A0 (005a03a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x58C)+0x4) | 0x0 | R | — | Second-list node payload pointer — checked non-null, then destroyed/freed during cleanup |
| *(*(this+0x58C)+0x4) | 0x4 | R | — | Second-list node forward link — read while relinking/advancing the removal walk |
| *(*(this+0x58C)+0x4) | 0x8 | R | — | Second-list node owns-payload flag byte — non-zero means payload is destructed via sub_5A6920 and freed |
| *(this+0x570) | 0x0 | R | — | Head node pointer of the mutex-guarded dequeue queue |
| *(this+0x570) | 0x8 | RW | 0 | Byte flag on the dequeued node — cleared to 0 before sub_59F9F0 pops it |
| *(this+0x58C) | 0x0 | R | — | Head node pointer of the second list, re-read each drain iteration |
| *(this+0x58C) | 0x4 | RW | — | Forward-link field of second-list nodes rewritten while unlinking |
| obj | 0x5C | R | — | Vtable slot 0x5C (index 23) — virtual item-processing callback invoked with each dequeued payload |
| this | 0x0 | R | — | Vtable pointer, used to resolve the callback at +0x5C |
| this | 0x570 | R | — | First queue header (head pointer at +0), protected by mutex at 0x580 |
| this | 0x580 | R | — | Mutex handle for the first queue; waited on before each pop |
| this | 0x584 | R | — | Wait timeout for the first queue mutex |
| this | 0x58C | RW | — | Second list head pointer; mutated while unlinking nodes |
| this | 0x590 | RW | — | Second list auxiliary link pointer; updated when the removed node matches |
| this | 0x594 | RW | — | Second list tail pointer; advanced/reassigned when the removed node matches |
| this | 0x598 | R | — | Second list item count; drain loop runs while > 0 |
| this | 0x59C | R | — | Mutex handle for the second list; held during cleanup, released at exit |
| this | 0x5A0 | R | — | Wait timeout for the second list mutex |

**Written-by note (persistence):**
- *(this+0x570) 0x8: written per dequeued node each call (cleared to 0 right before the pop); a poke to this field on a queued node is transient and overwritten when that node is drained.
- *(this+0x58C) 0x4: node link fields rewritten during the unlink walk whenever cleanup runs; recalculated state, a poke would be overwritten on the next drain.
- this 0x58C: head pointer mutated whenever nodes are removed; recalculated/consumed on every call — an external poke would be overwritten by the next drain.
- this 0x590: auxiliary link updated on removal; recalculated state, poke would not survive a drain.
- this 0x594: tail pointer updated on removal; recalculated state, poke would not survive a drain.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1184 | ReleaseMutex | R | kernel32 import — releases the first-queue mutex (0x580) after each pop and the second-list mutex (0x59C) at exit |
| 006f1188 | WaitForSingleObject | R | kernel32 import — acquires both queue mutexes with their stored timeouts; return 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) is accepted |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059f9f0 | sub_59F9F0 | Pop/remove operation on the first queue (this+0x570); returns non-zero on success (arg 3 = 1) |
| 005a6920 | sub_5A6920 | Payload destructor invoked for second-list nodes whose owns-payload flag byte is set |
| 006308d3 | j__free | Heap free for a node's payload and for the node itself |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x598 | > | 0 | Second list item count — cleanup loop body runs only while the count is positive |

**Guard interpretation:** Second list: cleanup only starts if the mutex handle at 0x59C is non-null and WaitForSingleObject on it returns 0 or 128; then the loop passes while count (0x598) > 0 and both the head pointer (0x58C) and the head node's payload are non-null — each passing iteration unlinks and frees one node (and its payload if the node flag byte is set). It is BLOCKED and exits when count <= 0, the head is null, the payload is null, or the mutex wait returns anything other than 0/128 (then v9 = 0 and the loop is not entered). First queue: each iteration passes only if a mutex handle exists at 0x580, the pop (sub_59F9F0) succeeds, and the popped payload is non-null; otherwise the loop breaks without dispatching.
