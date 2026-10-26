## ObjectAllocationWithSEH_005830c0 — SocketAddressCallbackBlockAlloc

**Summary:** Allocates a 8316-byte callback block for 2 socket address entries (each 4156 bytes). Initializes via NTimeCallbackLoopWithSEH_a6eb with SocketAddressInit and EmptyStub_aa60 callbacks. Stores pointer to callback area in *this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), NetworkAccept (00580190)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Pointer to allocated callback block (points past 4-byte header to entries) |

**Written-by note (persistence):**
- this 0x0: set once to callback block pointer, or 0 on allocation failure. External poke overwrites.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047aa60 | EmptyStub_aa60 | R | No-op callback — second parameter to timer loop init |
| 00582110 | SocketAddressInit | R | Callback to initialize socket address structure |
| 0059ce2b | SEH_5830C0 | R | SEH handler registration for exception protection |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 8316-byte callback block |
| 0058a6eb | NTimeCallbackLoopWithSEH_a6eb | Initialize 2 callback entries of 4156 bytes each |

**Guard conditions:** none — allocation result checked but no field-based guard.
