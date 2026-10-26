## VTableSetCleanup_00487f30 — VTable reset to UIObject then delegated cleanup

**Summary:** Resets object vtable to off_5ABAC8 (UIObject), then calls delegated cleanup function; returns its result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeDestructor (004677e0), Destructor_7f10 (00487f10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ABAC8 | vtable pointer; reset to UIObject vtable before delegated cleanup |

**Written-by note (persistence):**
- this 0x0: written once during destruction; memory freed afterward

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abac8 | off_5ABAC8 | R | VTable_UIObject_BAC8 — vtable set before delegated teardown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable reset + delegate call
