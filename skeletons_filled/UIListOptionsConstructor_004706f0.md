## UIListOptionsConstructor_004706f0 — UIListOptionsWithRaceModeConstructor

**Summary:** UI list options constructor: calls base init (sub_48C070 with flag=1), sets vtable to off_5A0480, initializes field at 0x31C to 406, inserts UI text handle into linked list, and calls RaceModeScreenSetup. Returns initialized object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0480 |
| this | 0x31C | RW | 406 | numeric field / type ID, initialized to 406 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0480; overwritten if external code changes vtable
- this 0x31C: set once to 406; overwritten if external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0480 | off_5A0480 | R | vtable pointer assigned to this object |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — inserted as linked list entry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004707c0 | RaceModeScreenSetup | race mode screen configuration after base init |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert node into linked list (-1 = append) |
| 0048c070 | sub_48C070 | base UI list constructor (flag=1) |

**Guard conditions:** No guards — unconditional initialization sequence.
