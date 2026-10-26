## RefCountDecrementWithCheck_00599ad9 — Ref count decrement with zero-check cleanup

**Summary:** Decrements reference counter at dword_5EA04C; if counter reaches zero, dispatches cleanup/status check on three objects (byte_8D4568, dword_8D4400, dword_8D4440). Wrapped by SEH frame setup/teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea04c | dword_5EA04C | W | ReferenceCounter [DERIVED] |
| 008d4400 | dword_8D4400 | R | DynamicsSolverBase_8D4400 [DERIVED] |
| 008d4440 | dword_8D4440 | R | DynamicsConstraintData [DERIVED] |
| 008d4568 | byte_8D4568 | R | ExceptionTypeDescriptor [DERIVED] (also: ` — static type descriptor used in MSVC exception handling data) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598aa0 | StatusCheckWithErrorDispatch | status/error dispatch routine for cleanup path |
| 0059a54d | sub_59A54D | SEH frame init or critical-section enter |
| 0059a5e9 | sub_59A5E9 | SEH frame teardown or critical-section leave |

**Guard conditions:** Checks `dword_5EA04C-- == 1` (was 1 before decrement → becomes 0). If true (ref reached zero), runs cleanup: three calls to StatusCheckWithErrorDispatch. If false (ref > 0 after decrement), skips cleanup and returns.
