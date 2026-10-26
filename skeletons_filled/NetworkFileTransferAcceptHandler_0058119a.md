## NetworkFileTransferAcceptHandler_0058119a — File transfer accept/reject handler with mutex sync

**Summary:** Accepts or rejects file transfer request based on NegatedPredicate check. Acquires mutex at this+0x640 before decision, releases before return. On accept path (predicate false), increments counter and calls sub_57E280 with this and 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x640 | R | — | Mutex handle for thread synchronization |
| this | 0x644 | R | — | Wait timeout (ms) for mutex acquisition via WaitForSingleObject |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex handle with timeout |
| 0059e1a4 | ReleaseMutex | R | Release mutex after decision |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057e280 | sub_57E280 | Called on accept path with this and float 1.0 — likely initiates transfer processing |
| 00587100 | NegatedPredicate | Evaluates accept/reject condition; returns true to reject, false to accept |
| 00587230 | CounterIncrementDecrementByFlag | Increments counter on accept path (called with arg=1) |

**Guard conditions:** NegatedPredicate(a2, a3) branch: if true → reject path (release mutex, return 0); if false → accept path (counter increment, release mutex, call sub_57E280(this, 1.0), return 1). Mutex is always released before return regardless of path.
