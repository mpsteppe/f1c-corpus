## UtilityFunction_fc10_0048fc10 — CachedValueSyncDispatch

**Summary:** Reads a value from a referenced object at offset 0x254 (this[56]+372) and compares it with cached field at 0xE4 (this[57]). If they differ, updates the cache and invokes virtual method at vtable+44 with argument 1 to signal change. Always calls virtual method at vtable+168 for final dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | virtual method offset for change notification |
| obj | 0xA8 | R | — | virtual method offset for final dispatch |
| this | 0x0 | R | — | vtable pointer |
| this | 0xE0 | R | — | pointer to referenced external object |
| this | 0xE4 | RW | — | cached value synced from external object |
| this | 0x254 | R | — | field offset within referenced object to read from |

**Written-by note (persistence):**
- this 0xE4: updated when external value changes; survives until next sync

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- if (this[56] == 0) → BLOCKED (skip cache comparison, go to final dispatch)
- if (this[56] != 0) → PASS: compare cached value at 0xE4 vs external value at *(this[56]+372)
  - if equal → BLOCKED (skip update and change notification)
  - if different → PASS: update cache, fire virtual method at vtable+44 with arg 1
- Always: call virtual method at vtable+168 for final dispatch
