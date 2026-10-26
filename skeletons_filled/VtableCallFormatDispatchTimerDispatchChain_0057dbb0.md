## VtableCallFormatDispatchTimerDispatchChain_0057dbb0 — DispatchTimerPacketChain

**Summary:** Dispatches timer-driven packet construction chain: calls vtable getter (offset 0x58), reads guarded timer, wraps timer value, constructs network packet from getter result, and thread-safely dispatches via mutex.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57E0A0 (0057e0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x58 | R | — | vtable method pointer at vtable+0x58 (context getter) |
| this | 0x0 | R | — | vtable pointer (dispatched through for getter call) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057afa0 | NetworkPacketConstructor | build network packet using data from v6+0x48 and a2 parameter |
| 00584c70 | ThreadSafeCallWithMutex | dispatch/execute with mutex protection on v6 |
| 00584f90 | MutexGuardedTimerRead | read timer value from this object with mutex guard |
| 00586800 | sub_586800 | system call with fixed parameters (0, 11, 0, 2, -1) |
| 00586a00 | SingleFunctionCallWrapper_6a00 | wrap/process timer value (4 bytes) |

**Guard conditions:** none — always executes unconditionally.
