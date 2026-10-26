## sub_5BCD20_005bcd20 — Init record and swap ref-counted member

**Summary:** Initializes the a2-th 8-byte record in the array at this[2] (vtable = off_7296C4), takes the object pointer from a3+4 as its member at +4, acquires it via the pointer's first vtable slot, and releases the previously held member via vtable slot +4. Reference-counted handoff pattern.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | base pointer of the 8-byte-record array (element = {vtable, member}) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ea93a | SEH_5BCE20 | R | compiler-generated SEH handler/funclet address referenced by this routine's unwind data |
| 007296c4 | off_7296C4 | R | vtable pointer stored into dword 0 of the record |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `if (v4)` computed record pointer non-null → proceed (base array always non-null in practice). `if (v5)` (member pointer from a3+4) non-null → call its vtable slot 0 (acquire/AddRef). Old member saved before overwrite; `if (v6)` old member non-null → tail-call its vtable slot +4 (release). Null new member or null old member skips the respective virtual call.
