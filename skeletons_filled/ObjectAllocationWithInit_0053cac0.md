## ObjectAllocationWithInit_0053cac0 — AudioChannelObjectAllocInit

**Summary:** Allocates and initializes a 48-byte audio channel object. Stores result in output pointer and returns status from a subsequent guarded initialization call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioMixerChannelInitializer (005435d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output pointer storing allocated object address |

**Written-by note (persistence):**
- this 0x0: conditional — written only once during allocation; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005473d0 | MultiFieldZeroInitConstructor | Zero-initializes newly allocated object (constructor) |
| 00547400 | GuardedCallWithStatus | Guarded initialization call (parameter 0) |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation wrapper for 48-byte object |

**Guard conditions:** Checks OperatorNewNhMallocWrapper result: if NULL, zero is stored to output pointer instead of initialized object. Also uses GuardedCallWithStatus return value: returns -1 if status non-zero (success), 0 if zero (failure).
