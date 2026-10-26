## MediaBufferManagerDestructor_00476730 — MediaBufferManagerDestructor

**Summary:** Destructor for a media buffer manager. Frees the main buffer, destroys a linked list of buffer references, zeros list state, and optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x0) | 0x0 | R | — | value pointer from first list node |
| *(this+0xF0) | 0x0 | R | — | first list node's contents (value pointer) |
| this | 0x0 | RW | — | vtable pointer (set to UISlider vtable during destruction) |
| this | 0xF0 | RW | 0 | linked list head pointer (zeroed at end) |
| this | 0xF4 | RW | 0 | linked list count/tail (zeroed at end) |
| this | 0xF8 | RW | 0 | linked list cursor/state (zeroed at end) |
| this | 0xFC | RW | 0 | linked list sentinel/end marker (zeroed at end) |
| this | 0x188 | R | — | main media buffer pointer |

**Written-by note (persistence):**
- this 0x0: set once during destruction; object dead after, external poke irrelevant
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
| this | 0xFC | == | 0 | end-of-list sentinel (empty list check) |

**Guard interpretation:** `this[63]` (offset 0xFC) == 0 → linked list is empty (no nodes to traverse); non-zero → list has nodes, each is freed during traversal
