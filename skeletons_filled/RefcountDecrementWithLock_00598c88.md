## RefcountDecrementWithLock_00598c88 — RefcountDecrementWithLock

**Summary:** Under lock, decrements the reference count field at offset 0x4 if non-zero and not -1 (sentinel). Returns the object pointer if the count reaches zero (indicating caller should clean up), otherwise returns 0. Part of the reference counting mechanism for locale/lock objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NullCheckWithVirtualDispatch (00598c70), sub_59AAB9 (0059aab9), ObjectTeardownWithIteratorCleanup (0059ac7f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | reference count field |

**Written-by note (persistence):**
- this 0x4: conditional — decremented each call if non-zero and not -1; reaches zero triggers cleanup signal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a54d | sub_59A54D | acquire lock/synchronization primitive |
| 0059a5e9 | sub_59A5E9 | release lock/synchronization primitive |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 0 | refcount sentinel — skip decrement if zero or -1 |

**Guard interpretation:** If this+4 is 0 or -1 → skip decrement (value unchanged). If non-zero and not -1 → decrement. After decrement, if result is 0 → return this (cleanup needed), else return 0 (still referenced).
