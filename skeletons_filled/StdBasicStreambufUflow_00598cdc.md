## StdBasicStreambufUflow_00598cdc — StreambufUflow

**Summary:** Implements std::streambuf::uflow() (underflow) virtual method. Calls the virtual overflow/sync function at vtable offset 0x10 (slot 4) to refill the get area; if successful (not -1), reads one byte via MSVCStreambufGninc and returns it. Standard GCC/MSVC streambuf underflow implementation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | R | — | vtable offset for virtual overflow/sync function (slot 4) |
| this | 0x0 | R | — | vtable pointer used to dispatch virtual call |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00599475 | MSVCStreambufGninc | increment get pointer and return next byte from get area |

**Guard conditions:** Branch on result of virtual overflow call: if result == -1 (EOF/error) → return -1 without reading. If result != -1 → read and return next byte via MSVCStreambufGninc.
