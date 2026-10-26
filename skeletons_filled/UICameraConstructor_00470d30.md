## UICameraConstructor_00470d30 — UICameraOptionListConstructor

**Summary:** UI camera option list constructor: calls base init (ShortComputation_6d60 with flag=1), sets vtable to off_5A0900, initializes fields (pointer at 0x31C to dword_7CF038, flags 1/0/1/1, value 409 at 0x334), inserts two linked list entries (UI text handle and "On" string), and returns the object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0900 |
| this | 0x31C | RW | — | pointer field, set to dword_7CF038 (option byte data) |
| this | 0x324 | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x328 | RW | 0 | boolean/flag field, initialized to 0 |
| this | 0x32C | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x330 | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x334 | RW | 409 | numeric field / type ID, initialized to 409 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0900; overwritten if external code changes vtable
- this 0x31C: set once to dword_7CF038 pointer; overwritten if external code writes to this field
- this 0x324: set once to 1; survives unless external code changes it
- this 0x328: set once to 0; same
- this 0x32C: set once to 1; same
- this 0x330: set once to 1; same
- this 0x334: set once to 409; same

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0900 | off_5A0900 | R | vtable pointer assigned to this object |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — inserted as first linked list entry |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] — "On" string inserted as second linked list entry |
| 007cf038 | dword_7CF038 | R | OptionByte_7CF038 [DERIVED] — pointer stored in field at 0x31C |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | base screen initialization (flag=1) |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert node into linked list (-1 = append) |

**Guard conditions:** No guards — unconditional initialization sequence.
