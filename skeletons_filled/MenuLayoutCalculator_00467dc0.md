## MenuLayoutCalculator_00467dc0 — MenuLayoutCalculator

**Summary:** Computes menu layout position (midpoint between two bounds) and processes credits text data and HTML output sections. Calls CreditsTxtParser and HTMLOutputSectionProcessor, then calculates center position and loads a resource via sub_497AD0. Belongs to menu layout system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | left/start position bound |
| this | 0x8 | R | — | right/end position bound |
| this | 0x40 | R | — | pointer to data for sub_497AD0 resource load |
| this | 0xB8 | R | — | path string pointer (defaults to byte_5EA438 if null) |
| this | 0xEC | RW | — | computed midpoint (start + (end-start)/2) |
| this | 0x108 | RW | — | result handle/pointer from sub_497AD0 resource load |

**Written-by note (persistence):**
- this 0xEC: computed as midpoint; overwritten on every call.
- this 0x108: result of sub_497AD0; overwritten on every call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00467e40 | CreditsTxtParser | parses credits.txt file into a linked list of strings |
| 00467f90 | HTMLOutputSectionProcessor | processes HTML output section headers from parsed data |
| 00497ad0 | sub_497AD0 | loads/references a resource by path and key pointer |

**Guard conditions:** Checks this[46] (path at offset 0xB8) for null; if null, uses byte_5EA438 as default path. No early return — both paths proceed to sub_497AD0 call.
