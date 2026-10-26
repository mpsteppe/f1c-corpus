## UIComponentDtor_0047fba0 — UIComponentDtor

**Summary:** Destructor for a generic UI component: sets vtable to off_5A6E98, calls FunctionCallWrapper_9440 for sub-object cleanup, then optionally frees self if a2 & 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer set to off_5A6E98 |

**Written-by note (persistence):**
- this 0x0: set at entry; persists until overwritten by FunctionCallWrapper_9440 chain

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6e98 | off_5A6E98 | R | VTableRef_5A6E98 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489440 | FunctionCallWrapper_9440 | dispatches to base destructor or cleanup handler |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** No field-based guards; only the a2 flag controls self-deallocation.
