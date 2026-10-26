## sub_5BCDA7_005bcda7 — Init record and swap ref-counted member (alt entry)

**Summary:** Same body as sub_5BCD20 but with the alternate vtable off_7296C8: initializes the a2-th 8-byte record in the array at this[2], stores the pointer from a3+4 as its member, acquires it via the pointer's first vtable slot, and releases the previous member via vtable slot +4. Reached as an entry 7 bytes into sub_5BCDA0 (positive-SP entry artifact).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | base pointer of the 8-byte-record array (element = {vtable, member}) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007296c8 | off_7296C8 | R | vtable pointer stored into dword 0 of the record |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `if (v4)` computed record pointer non-null → proceed (always true in practice). `if (v5)` member pointer from a3+4 non-null → call its vtable slot 0 (acquire). `if (v6)` previously held member non-null → tail-call its vtable slot +4 (release). Null member pointers skip the corresponding virtual call.
