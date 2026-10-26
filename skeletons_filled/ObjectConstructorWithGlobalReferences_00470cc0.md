## ObjectConstructorWithGlobalReferences_00470cc0 — UIListWithExternalRefConstructor

**Summary:** UI list constructor: calls base init (ShortComputation_6d60 with flag=1), sets vtable to off_5A0840, initializes fields (pointer at 0x31C to unk_7CF014, flags 1/0/1/1, value 408 at 0x334), inserts two linked list entries (UI text handle and "On" string), and returns the object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0840 |
| this | 0x31C | RW | — | pointer field, set to unk_7CF014 (external reference) |
| this | 0x324 | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x328 | RW | 0 | boolean/flag field, initialized to 0 |
| this | 0x32C | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x330 | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x334 | RW | 408 | numeric field / type ID, initialized to 408 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0840; overwritten if external code changes vtable
- this 0x31C: set once to unk_7CF014 pointer; overwritten if external code writes to this field
- this 0x324: set once to 1; survives unless external code or virtual methods change it
- this 0x328: set once to 0; same
- this 0x32C: set once to 1; same
- this 0x330: set once to 1; same
- this 0x334: set once to 408; same

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0840 | off_5A0840 | R | vtable pointer assigned to this object |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — inserted as first linked list entry |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] — "On" string inserted as second linked list entry |
| 007cf014 | unk_7CF014 | R | ExternalReferencePtr [DERIVED] — pointer stored in field at 0x31C |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | base screen initialization (flag=1) |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert node into linked list (-1 = append) |

**Guard conditions:** No guards — unconditional initialization sequence.
