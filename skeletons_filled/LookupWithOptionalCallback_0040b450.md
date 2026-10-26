## LookupWithOptionalCallback_0040b450 — Lookup With Optional Callback

**Summary:** Searches for a2 in the stride-160 array via LinearSearchWithStride0xA0, stores the found index via BoundedIndexSetter, and optionally calls virtual callback at vtable+16 if a3 flag is set. Returns 1 on match, 0 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionPhaseDispatchWithCascadeChecks (0040d1b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | R | — | this pointer forwarded to LinearSearchWithStride0xA0 and BoundedIndexSetter |
| this | 0x0 | R | — | Vtable pointer (calls vtable+16 for optional callback) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040ad60 | LinearSearchWithStride0xA0 | Linear search for a2 in stride-160 array; returns index or -1 |
| 0040ad90 | BoundedIndexSetter | Stores found index in this[5] if within valid bounds |

**Guard conditions:** a2 must be non-null. LinearSearchWithStride0xA0 must return index >= 0 (match found). a3 flag controls whether vtable+16 callback fires after successful lookup.
