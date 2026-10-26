## ResourceCheckVirtualCall_00473650 — ResourceNameCheckAndVirtualCall

**Summary:** Retrieves resource object by ID 19 via GameCommandDispatchInterface vtable, optionally compares its name with `this` using ObjectNameComparison, then invokes virtual method at vtable offset 172 on `this`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xAC | R | — | field on retrieved resource object used in name comparison |
| this | 0x0 | R | — | vtable pointer for virtual dispatch at offset 172 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface — dispatch interface pointer used to retrieve resource by ID |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477280 | ObjectNameComparison | compare names of two objects |

**Guard conditions:**
- `v2` (return from dispatch interface virtual call) is null → **BLOCKED**: skip ObjectNameComparison
- Non-null `v2` → **PASSES**: compare names, then always fall through to virtual call at offset 172
