## ObjectInitWithVTablePathRegistration_00470af0 — UIListOnToggleConstructor

**Summary:** UI list constructor: calls base init (sub_48C070 with flag=1), sets vtable to off_5A0780, initializes field 0x31C to 407, inserts two linked list entries (UI text handle and "On" string), and returns the object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0780 |
| this | 0x31C | RW | 407 | numeric field / type ID, initialized to 407 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0780; overwritten if external code changes vtable
- this 0x31C: set once to 407; overwritten if external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0780 | off_5A0780 | R | vtable pointer assigned to this object |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — inserted as first linked list entry |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] — "On" string inserted as second linked list entry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | insert node into linked list (-1 = append) |
| 0048c070 | sub_48C070 | base UI list constructor (flag=1) |

**Guard conditions:** No guards — unconditional initialization sequence.
