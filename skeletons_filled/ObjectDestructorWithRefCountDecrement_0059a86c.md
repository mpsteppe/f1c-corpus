## ObjectDestructorWithRefCountDecrement_0059a86c — Object destructor with reference count array decrement

**Summary:** Destructor that decrements object's reference count in a global array at byte_8D463C. If count reaches zero or index is null, calls sub_59A980 for full cleanup. Calls NullCheckWithVirtualDispatch on offset 0x20.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SubCallConditionalFree_a8bc (0059a8bc)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d4cb | loc_59D4CB | R | SEH continuation/landing pad address |
| 005b9d3c | off_5B9D3C | R | CRT_RefCount_5B9D3C [DERIVED] |
| 008d463c | byte_8D463C | RW | RefCountArray [DERIVED] (also: Reference count array (indexed by extraout_ECX[9]) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 00598c70 | NullCheckWithVirtualDispatch | Null-check pointer at this+0x20 and dispatch virtual call |
| 0059a980 | sub_59A980 | Full object cleanup (free callback chains) |

**Guard conditions:** `if (!v3 || --byte_8D463C[v3] <= 0)` — PASSES (triggers sub_59A980 cleanup) when v3 is null OR ref count at slot v3 drops to 0 or below. BLOCKED when v3 is non-zero and ref count stays positive.
