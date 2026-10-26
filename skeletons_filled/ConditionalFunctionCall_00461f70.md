## ConditionalFunctionCall_00461f70 — ConditionalNetworkSubCall

**Summary:** Calls sub_563410 on the network system pointer if non-null, otherwise returns the this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalChain (00475570)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1B79C | R | — | Network system pointer (checked non-null before call) |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Blocked when network system pointer (this+0x1B79C) is null — skips sub_563410 call and returns this pointer value.
