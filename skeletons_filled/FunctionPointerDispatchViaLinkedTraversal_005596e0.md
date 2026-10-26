## FunctionPointerDispatchViaLinkedTraversal_005596e0 — FunctionPointerDispatchViaLinkedTraversal

**Summary:** Walk linked list of function dispatch entries, compare selector field (+0x14) against target (+0x220), and call the matching handler via function pointer at +0x20. Also check direct handler slot on context object as fallback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x220) | 0x14 | R | — | Selector value on matched dispatch entry |
| *(obj+0x220) | 0x18 | R | — | Handler context pointer for matched entry |
| *(this+0x230) | 0x14 | R | — | Selector comparison value on alternate context |
| *(this+0x230) | 0x18 | R | — | Function pointer argument on alternate context |
| *(this+0x230) | 0x2C | R | — | Function pointer offset on alternate context |
| *(this+0x230) | 0x30 | R | — | Call argument on alternate context |
| obj | 0x220 | R | — | Pointer to dispatch list or handler object |
| this | 0x0 | R | — | Root context pointer for dispatch |
| this | 0x8 | R | — | Pointer to linked list of dispatch handlers |
| this | 0x20 | RW | — | Output/call parameter field set before indirect call |
| this | 0x22C | R | — | unknown |
| this | 0x230 | R | — | Pointer to alternate handler context |
| this | 0x234 | R | — | unknown |

**Written-by note (persistence):**
- this 0x20: Written before each indirect function call; set from handler context field

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | != | 0 | Dispatch list head — must be non-null for walk |
| *(this+0x230) | 0x14 | == | *(v2+0x220) | Selector match — must equal target selector |
| *(*(this+0x230)+0x2C) | 0x14 | != | 0 | Function pointer — must be non-null for call |
| this | 0x0 | != | 0 | Root context — must be non-null for fallback dispatch |
| *(this+0x0)+0x220 | 0x14 | != | 0 | Fallback handler function pointer — must be non-null |

**Guard interpretation:** Walk dispatches linked via +4 offset. For each entry: compare selector (+0x14) against target; PASS on match then check handler pointer (+0x2C → call via +0x20). Fallback path: check root context (+0x220) has handler; if so, call via +0x20. BLOCKED for entries that don't match selector.
