## SimpleVTableNullInit_0048c9a0 — UIElementVTableInit

**Summary:** Initializes object with UIElementVTable at this+0x0 and zeroes field at this+0x4. Called during linked list node setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeAppend (0048d2b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | &off_5AC044 | VTable pointer set to UIElementVTable |
| this | 0x4 | RW | 0 | Next-node pointer or type field (zeroed) |

**Written-by note (persistence):**
- this 0x0: written once per call with UIElementVTable. Survives until overwritten.
- this 0x4: written once per call with 0. Survives until overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac044 | off_5AC044 | R | UIElementVTable — assigned as object vtable |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — always executes unconditionally.
