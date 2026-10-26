## UIElementListDestructor_00477440 — UISliderListDestructor

**Summary:** Destructor for a UI slider list. Traverses a linked list, conditionally destroys each node's child object, frees nodes, zeroes list fields, and optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x0) | 0x0 | R | — | dereferenced value pointer from first list node |
| *(this+0xF0) | 0x0 | R | — | first list node contents (value pointer) |
| *(this+0xF4) | 0x4 | R | — | target of list cursor at offset 0xF4, offset 4 (next pointer) |
| this | 0x0 | RW | — | vtable pointer (set to UISlider vtable during destruction) |
| this | 0xF0 | RW | 0 | linked list head pointer (zeroed at end) |
| this | 0xF4 | RW | 0 | linked list tail/cursor (zeroed at end) |
| this | 0xF8 | RW | 0 | linked list count (zeroed at end) |
| this | 0xFC | RW | 0 | linked list sentinel (zeroed at end) |

**Written-by note (persistence):**
- this 0x0: set once during destruction; object dead after
- this 0xF0-0xFC: zeroed at end; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4550 | off_5A4550 | R | VTable_UISlider [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | base class destructor / additional cleanup |
| 00587bcf | FreeWrapper_7bcf | frees a heap-allocated block |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | == | 0 | end-of-list sentinel / list empty marker |

**Guard interpretation:** `this[60]` (offset 0xF0, list head) == 0 → list is empty, skip traversal; non-zero → iterate nodes until next pointer becomes 0 (termination)
