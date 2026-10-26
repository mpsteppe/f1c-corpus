## ConditionalNetworkUtility_00563160 — AllocateAndDispatchNetworkStruct

**Summary:** Allocates a new struct via StructAllocInitWithSwitchBasedType using type selector this+0x94, then dispatches it through a callback/function pointer at this+0x4 via SingleFunctionCallWrapper_48c0. Returns the allocated struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkConnection (00563260), sub_563410 (00563410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | callback/function pointer for dispatching allocated struct |
| this | 0x94 | R | — | type selector parameter for StructAllocInitWithSwitchBasedType |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005642f0 | StructAllocInitWithSwitchBasedType | allocates struct with type determined by switch parameter |
| 005648c0 | SingleFunctionCallWrapper_48c0 | calls a single-argument function pointer (callback) |

**Guard conditions:** this == NULL → return 0 (skip allocation and dispatch).

