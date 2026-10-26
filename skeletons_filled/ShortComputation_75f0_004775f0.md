## ShortComputation_75f0_004775f0 — StateChangeMonitorDispatch

**Summary:** Monitors a value at offset 0x174 of a tracked object. When it differs from the cached copy at offset 0x184, updates the cache and triggers a virtual callback at offset 160.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | unknown field from the UtilityFunction_7810 result |
| this | 0x0 | R | — | vtable pointer (virtual call at offset 160 on state change) |
| this | 0x184 | RW | — | cached value of monitored state; updated when changed |

**Written-by note (persistence):**
- this 0x184: written only when monitored value differs; persists between checks

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477810 | UtilityFunction_7810 | retrieves tracked object with state data at offset 0x174 |

**Guard conditions:** `UtilityFunction_7810` must return non-null; `v3` (tracked object's state at offset 0x174) must differ from `this[97]` (cached at offset 0x184) → update cache and invoke callback
