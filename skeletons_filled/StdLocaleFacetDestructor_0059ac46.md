## StdLocaleFacetDestructor_0059ac46 — std::locale::facet destructor with conditional free

**Summary:** Destructor for `std::locale::facet`. Resets vtable to facet vtable, then conditionally frees the object if flag `(a2 & 1)` is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer, reset to facet vtable during destruction |

**Written-by note (persistence):**
- this 0x0: Once — vtable pointer overwritten during destruction. External poke would not survive (object subsequently freed).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9d54 | ??_7facet@locale@std@@6B@ | R | VTable_StdfacetLocale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated facet object |

**Guard conditions:** `if ((a2 & 1) != 0)` — PASSES (flag bit 0 set) → frees this via FreeWrapper_7bcf. BLOCKED (bit 0 clear) → skip free.
