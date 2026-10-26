## TwoFieldInitializer_e0b4_0058e0b4 — Object vtable and field initializer

**Summary:** Initializes a C++ object's vtable pointer at offset +0x50 and an integer field at offset +0x14 to 1. Constructor fragment or init helper called during TLS/thread object setup.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TLSAllocationThreadIDInit (0058e060), TLSValueRetrievalWithInit (0058e0c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | 1 | Object state flag or count; initialized to 1 |
| this | 0x50 | RW | — | Vtable pointer for C++ object dispatch |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e7810 | unk_5E7810 | R | Vtable pointer assigned to object at offset +0x50 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — unconditionally initializes both fields and returns the input pointer.
