## NetworkSocketObjectCreate_0057a420 — NetworkSocketObjectAllocInit

**Summary:** Allocates and initializes a 3064-byte network socket object. Validates config parameter (must be <= 1), allocates memory, calls sub_57BA10 for initialization. On error, cleans up via vtable destructor call and nulls the output pointer. Returns this (pointer slot).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57ABB0 (0057abb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | output pointer slot for new socket object (nulled on error) |

**Written-by note (persistence):**
- this 0x0: written with allocated object address or 0 on error; survives as caller's pointer to socket

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c75b | SEH_57A420 | R | SEH handler for exception safety during allocation/init |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057ba10 | sub_57BA10 | initializes the 3064-byte network socket structure |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 3064 bytes for socket object |

**Guard conditions:** if *a2 (config value) > 1, skips allocation and sets error flag (*a3 = 1). If allocation fails, sets *this = 0. If init fails (*a3 set), calls vtable destructor at offset 0x44 and nulls *this.
