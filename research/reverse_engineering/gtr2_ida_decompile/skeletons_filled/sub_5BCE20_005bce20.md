## sub_5BCE20_005bce20 — Init record and swap ref-counted member (variant CC)

**Summary:** Third copy of the record-init/ref-handoff routine: sets the a2-th 8-byte record in the array at this[2] with vtable off_7296CC, adopts the pointer from a3+4 as its member (acquire via first vtable slot) and releases the previous member via vtable slot +4.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | base pointer of the 8-byte-record array (element = {vtable, member}) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ea93a | SEH_5BCE20 | R | compiler-generated SEH handler/funclet address referenced by this routine's unwind data |
| 007296cc | off_7296CC | R | vtable pointer stored into dword 0 of the record |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `if (v4)` record pointer non-null → proceed (always true in practice). `if (v5)` new member from a3+4 non-null → acquire call via vtable slot 0. `if (v6)` old member non-null → tail-call its vtable slot +4 (release). Nulls skip the corresponding virtual call.
