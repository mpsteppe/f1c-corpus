## MutexCallbackDispatch_0057e3a0 — PendingCallbackQueueProcess

**Summary:** Acquires mutex, walks a callback/action linked list, invoking CounterIncrementDecrementByFlag(0) for each entry. Releases mutex after traversal. Drains queued callbacks in a network/audio context.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57E280 (0057e280)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAC8) | 0x0 | R | — | first callback node data |
| *(this+0xAD4) | 0x0 | R | — | next callback node data via cursor |
| this | 0xAC8 | R | — | callback linked list head (this[690]) |
| this | 0xAD0 | RW | — | traversal cursor (this[692]); set to list head at start |
| this | 0xAD4 | R | — | node next pointer (at this[693] offset) |
| this | 0xAD8 | R | — | mutex handle (WaitForSingleObject/ReleaseMutex) |
| this | 0xADC | R | — | mutex wait timeout |

**Written-by note (persistence):**
- this 0xAD0: conditional — traversal cursor; overwritten each call when list non-empty

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | kernel32 import — wait on mutex handle |
| 0059e1a4 | ReleaseMutex | R | kernel32 import — release mutex after queue drain |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587230 | CounterIncrementDecrementByFlag | process/consume each callback queue entry |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAC8 | == | 0 | callback linked list head |

**Guard interpretation:** If callback queue head at this+0xAC8 is NULL, the traversal loop is skipped entirely — no callbacks processed. Non-NULL passes through to process every entry in the list.
