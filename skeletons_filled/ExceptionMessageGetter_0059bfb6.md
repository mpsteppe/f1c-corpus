## ExceptionMessageGetter_0059bfb6 — ExceptionWhat

**Summary:** Returns exception message string (equivalent to `std::exception::what()`): returns pointer from this[1] if non-null, otherwise returns "Unknown exception".

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Exception message string pointer (returned if non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9dc8 | aUnknownExcepti | R | String_UnknownExcepti [DERIVED] — "Unknown exception" fallback string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[1] is null, returns global string "Unknown exception"; otherwise returns this[1].
