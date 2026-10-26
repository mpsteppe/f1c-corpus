## UIScreenConstructor_00470670 — UIScreenWithListOptionsConstructor

**Summary:** UI screen constructor: calls base init (ShortComputation_6d60), sets vtable to off_5A03C0, initializes fields (pointer at 0x31C, flags at 0x324/0x328/0x32C/0x330, value 405 at 0x334), inserts two linked list entries (UI text handle and "On" string), and calls SwitchOnActionIDVirtualCall for dispatch. Returns initialized object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A03C0 |
| this | 0x31C | RW | — | pointer field, set to unk_7D1250 |
| this | 0x324 | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x328 | RW | 0 | boolean/flag field, initialized to 0 |
| this | 0x32C | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x330 | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x334 | RW | 405 | numeric field, initialized to 405 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A03C0; overwritten if external code changes vtable
- this 0x31C: set once to pointer unk_7D1250; overwritten if external code writes to this field
- this 0x324: set once to 1; overwritten if external code or virtual methods change it
- this 0x328: set once to 0; same
- this 0x32C: set once to 1; same
- this 0x330: set once to 1; same
- this 0x334: set once to 405; same

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a03c0 | off_5A03C0 | R | vtable pointer assigned to this object |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — inserted as linked list entry |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] — "On" string inserted as linked list entry |
| 007d1250 | unk_7D1250 | R | pointer stored in field at 0x31C |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | base screen initialization (flag=1) |
| 004670e0 | SwitchOnActionIDVirtualCall | vtable dispatch after list insertions |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert node into linked list (-1 = append) |

**Guard conditions:** No guards — unconditional initialization sequence.
