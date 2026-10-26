## RenderingContextSetup_00497750 — SearchRenderingContextByName

**Summary:** Initializes a stack-based rendering context via PassthroughWrapper, processes `this` via sub_4998E0, then searches for an item whose name string (at offset 0x34) matches `a2`. Uses FieldAccessor/sub_499910 to iterate. Returns matching item pointer or 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492160 (00492160), sub_4988D0 (004988d0), sub_49A5D0 (0049a5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default name string when item name is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499840 | PassthroughWrapper | Initializes stack-based context structure |
| 004998e0 | sub_4998E0 | Processes `this` into the rendering context |
| 00499910 | sub_499910 | Advances context iterator to next item |
| 004b0170 | EmptyStub_0170 | Cleanup/teardown of context (called on both found and not-found paths) |
| 0053d880 | FieldAccessor | Retrieves current item pointer from context |
| 00588410 | sub_588410 | String comparison function (returns 0 on match) |

**Guard conditions:** FieldAccessor result after initialization must be non-null to enter search loop — null skips to cleanup and returns 0. During loop, FieldAccessor check for null exits to cleanup (not-found).
