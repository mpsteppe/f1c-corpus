## InitWithVTableFlags_00487ed0 — UI object init with flags and vtable set

**Summary:** UI object constructor: calls ShortComputation_5e30 for setup, stores two byte flags at 0xE0 and 0xE1, sets vtable to off_5ABAC8, and zeroes DWORD at 0x84.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_467720 (00467720), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ABAC8 | vtable pointer; set to UIObject vtable |
| this | 0x84 | RW | 0 | state/counter field; initialized to 0 |
| this | 0xE0 | RW | a2 | first byte parameter (enable/state flag) |
| this | 0xE1 | RW | a3 | second byte parameter (additional state flag) |

**Written-by note (persistence):**
- this 0x0: written once during construction; persists for object lifetime
- this 0x84: written once to 0; may be modified externally
- this 0xE0: written once with a2; may be toggled externally
- this 0xE1: written once with a3; may be toggled externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abac8 | off_5ABAC8 | R | VTable_UIObject_BAC8 — vtable set during initialization |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | performs initial setup computation before fields are written |

**Guard conditions:** none — unconditional straight-line init
