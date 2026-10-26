## ShortComputation_2340_00472340 — UIPathFormatComponentConstructor

**Summary:** Constructor for a UI component that initializes via sub_48C070, sets vtable to off_5A1E00, then calls VirtualFactoryPathFormat to format and display a factory path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Virtual method table pointer |

**Written-by note (persistence):**
- this 0x0: Written once during construction (vtable)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a1e00 | off_5A1E00 | R | Vtable for this UI component type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00472400 | VirtualFactoryPathFormat | Format and display factory path string |
| 0048c070 | sub_48C070 | Unknown initialization routine with param 1 |

**Guard conditions:** No guard conditions. Always executes all steps unconditionally.
