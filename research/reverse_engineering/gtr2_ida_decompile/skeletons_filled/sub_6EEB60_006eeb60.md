## sub_6EEB60_006eeb60 — std::strstreambuf destructor thunk

**Summary:** Thin destruction helper that invokes the C++ std::strstreambuf destructor on the object referenced by the global dword_91BE2C. Typically emitted for a translation unit or static-lifetime strstreambuf instance requiring explicit cleanup.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091be2c | dword_91BE2C | R | Holds the strstreambuf object pointer/address destroyed by this thunk |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional call to the destructor; no null check or branching in this wrapper.
