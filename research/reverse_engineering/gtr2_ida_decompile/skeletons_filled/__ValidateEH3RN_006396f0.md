## __ValidateEH3RN_006396f0 — SEH registration/scope-table validator (_ValidateEH3RN)

**Summary:** CRT structured-exception-handling validation routine used by except_handler3: verifies an exception registration record — stack bounds, scope-table ordering, filter usage, and image-mapped code address — before any scope handler is allowed to run.

**Called by:** __except_handler3 (00631f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | Scope-table entry field 0: the enclosing try-level index; must be -1 or strictly less than the entry's own index (ordering check) |
| *(this+0x8) | 0x4 | R | — | Scope-table entry field 1: filter-function pointer; nonzero marks an entry with an exception filter and increments the filter counter (v28) |
| this | 0x8 | R | — | Pointer to the scope table (array of 3-dword entries) held in the registration record |
| this | 0xC | R | — | Last/current try-level index (v5): -1 makes the record trivially valid; otherwise entries 0..v5 are scanned |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1274 | InterlockedExchange | R | Import thunk used to acquire/release the Target lock around scope-table cache updates; nonzero return means the lock was already held |
| 006f1278 | VirtualQuery | R | Import thunk used to inspect the memory region containing the code address v2, expecting an image-mapped region |
| 00fb8360 | dword_FB8360 | RW | Number of valid entries in the scope-table page cache; searched as a bound, capped at 16, incremented when a new entry is appended |
| 00fb8368 | dword_FB8368 | R | Cache array of 4KB-aligned page addresses of scope tables already validated; hit lets the function return 1 without re-validating |
| 00fb83a8 | Target | R | Lock word manipulated through InterlockedExchange (1 = locked, 0 = released) guarding cache mutation |
| 01000000 | dword_1000000 | R | Expected value of the memory-region Type (MEM_IMAGE = 0x1000000) for the queried address |
| ff0000000000a61a | byte_FF0000000000A61A | R | unknown — not traceable in the decompiled body |
| ff0000000000a61e | byte_FF0000000000A61E | R | unknown — not traceable in the decompiled body |
| ff0000000000a61f | byte_FF0000000000A61F | R | unknown — not traceable in the decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x8) | 0x0 | != | 18446744073709551615 | Scope-table entry enclosing-level field compared against the -1 sentinel: either the sentinel or a value < entry index passes; an in-range non-sentinel value fails the record |

**Guard interpretation:** Early exit 0 when the scope-table pointer `*(this+8)` has low bits set (`& 3` → misaligned), or when the code address falls inside the current thread's stack (`StackLimit <= v2 < StackBase`). `trylevel == -1` returns 1 (no scopes to validate). The entry scan fails (return 0) when an enclosing-level field is neither -1 nor less than the current entry index, and later when any filter exists and the pointer at `this−8` does not lie in the current stack below the record. Image-address validation fails (return 0) when the queried region is not a PE image or the address is in a writable/non-executable or non-code section; unrecognized region type returns -1. All passing paths (cache hit, cache append, validated image) return 1.
