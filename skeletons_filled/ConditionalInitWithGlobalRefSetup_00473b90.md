## ConditionalInitWithGlobalRefSetup_00473b90 — ResourceCheckAndFieldInit

**Summary:** Retrieves resource object by ID 11 via GameCommandDispatchInterface, optionally calls ObjectNameComparison if resource exists, then unconditionally stores pointer to UITextEncodingFlag at offset 0x320 and value 278 at offset 0x31C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x31C | RW | 278 | value / ID / counter preset |
| this | 0x320 | RW | — | pointer to UITextEncodingFlag (byte_7D0474) |

**Written-by note (persistence):**
- this 0x31C: once (literal 278); survives external poke
- this 0x320: once (pointer to UITextEncodingFlag); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface — dispatch interface used to retrieve resource by ID 11 |
| 007d0474 | byte_7D0474 | R | UITextEncodingFlag — text encoding flag referenced by pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477280 | ObjectNameComparison | compare names of two objects |

**Guard conditions:**
- `v2` (return from dispatch interface virtual call) is null → **BLOCKED**: skip ObjectNameComparison
- Non-null `v2` → **PASSES**: compare names
- Field init at offsets 0x320 and 0x31C always executes regardless
