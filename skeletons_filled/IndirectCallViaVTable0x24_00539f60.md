## IndirectCallViaVTable0x24_00539f60 — VTableDispatch0x24

**Summary:** Dispatches a virtual method call through vtable offset 0x24 (function pointer at a2+36) with context argument at a2+40 and pass-through parameter a1. Acts as a generic thunk for indirect method invocation. Part of object-oriented dispatch system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StateResetWithCallback (00537000), sub_537110 (00537110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | function pointer (vtable method slot at offset 0x24), called with (this+0x28, a1) |
| this | 0x28 | R | — | context/this pointer argument passed to the vtable method |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function always executes the indirect call unconditionally. No null checks on either the function pointer or the context argument.
