## LazyInitSingletonWithFlagGuard_005921c5 — LazyInitSingletonWithGuard

**Summary:** Thread-safe lazy initialization of CRT singleton via double-checked locking.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_589E6C (00589e6c), sub_591EDF (00591edf)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4078 | dword_8D4078 | RW | CRTInitFlag [DERIVED] (also: Initialization flag (0 = uninitialized, >0 = initialized) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058dfea | CriticalSectionLazyInitEnter | Enter critical section with lazy init |
| 0058e04b | CritSectLeave | Leave critical section |
| 005921f3 | sub_5921F3 | Actual singleton initialization function |

**Guard conditions:** If `dword_8D4078` (CRTInitFlag) is non-zero, skip initialization entirely (PASS: already initialized). Double-checked: re-checks after acquiring critical section lock.
