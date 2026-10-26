## ??1ios_base@std@@UAE@XZ_6_005c6fd0 — std::ios_base destructor with cleanup call

**Summary:** std::ios_base destructor: installs the derived vtable (off_72A438), and if the predicate sub_4FB7D0(this) signals there is io state, calls virtual slot +12 to obtain an object pointer and releases it via its own vtable slot 0 with argument 1; finally installs the base vtable off_72A1F8.

**Called by:** sub_5C6FB0 (005c6fb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | field at +0xC of the object, read by the predicate called on this (io-state related data) |
| this | 0x0 | RW | — | vtable pointer; set to derived vtable off_72A438, later to base vtable off_72A1F8 |

**Written-by note (persistence):**
- this 0x0: written unconditionally on every destructor invocation (first the derived vtable, then the base vtable); as a one-shot destructor the final value persists until the object is destroyed again, so an external poke would survive only until the next destructor call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006eb2b8 | ??1ios_base@std@@UAE@XZ_6_SEH | R | SEH/unwind metadata for the destructor |
| 0072a1f8 | off_72A1F8 | R | base std::ios_base vtable pointer assigned at function exit |
| 0072a438 | off_72A438 | R | derived-class vtable pointer assigned at function entry |
| 0072a444 | off_72A444 | R | vtable slot at +12 of off_72A438 — the virtual method invoked to fetch the object being cleaned up |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fb7d0 | FieldAccessor [exact] | predicate read on this (field accessor); when non-zero the destructor performs the extra virtual cleanup |

**Guard conditions:** sub_4FB7D0(this) non-zero → resolve virtual slot +12 of the current vtable; if the returned pointer v2 is non-NULL, call (**v2)(v2, 1) to release it. Zero predicate result, or NULL v2, → the cleanup block is skipped and only the vtable assignments happen.
