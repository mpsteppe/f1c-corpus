## ObjectConstructorWithZeroedFields_0048c9f0 — ExtendedObjectConstructor

**Summary:** Constructs extended object: calls HUDTimerConstructor sub_48C070(this,0), zeroes four extra fields at offsets 0x31C-0x328, overrides vtable to off_5AC048, then calls LinkedListDestructionWithVTableCall for list node initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithVTable (0046a220), SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | &off_5AC048 | VTable pointer overridden to UnknownVTable_B |
| this | 0x31C | RW | 0 | Zeroed DWORD — extended field |
| this | 0x320 | RW | 0 | Zeroed DWORD — extended field |
| this | 0x324 | RW | 0 | Zeroed DWORD — extended field |
| this | 0x328 | RW | 0 | Zeroed DWORD — extended field |

**Written-by note (persistence):**
- this 0x0: written twice (first by sub_48C070 as HUDTimerVTable, then overridden to off_5AC048). Final vtable persists.
- this 0x31C: written once per call with 0. Survives.
- this 0x320: written once per call with 0. Survives.
- this 0x324: written once per call with 0. Survives.
- this 0x328: written once per call with 0. Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac048 | off_5AC048 | R | UnknownVTable_B — final vtable assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c070 | sub_48C070 | HUDTimerConstructor — base init (vtable + fields) with arg 0 |
| 0048d230 | LinkedListDestructionWithVTableCall | LinkedList node initialization/setup (called despite "Destruction" name) |

**Guard conditions:** No guards — always executes unconditionally.
