## RefCountDecrementWithCleanup_00598994 — RefCountDecrementWithCleanup

**Summary:** Decrements a global reference counter (dword_5E9EF4) and, if it reaches zero, performs cleanup by dispatching status/error checks on locale management and exception type descriptor globals. Locked via sub_59A54D/sub_59A5E9. Part of CRT locale/exception infrastructure teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e9ef4 | dword_5E9EF4 | W | RefCount [DERIVED] (also: reference counter) |
| 008d4210 | dword_8D4210 | R | ExceptionTypeDesc [DERIVED] (also: passed as second argument; not in docs/12) |
| 008d42a0 | unk_8D42A0 | R | ExceptionTypeDescriptor [DERIVED] (also: static type descriptor used in MSVC exception handling data) |
| 008d43c8 | dword_8D43C8 | R | LocaleManagementStruct [DERIVED] (also: locale management structure) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598aa0 | StatusCheckWithErrorDispatch | dispatch status/error check on a global context |
| 0059a54d | sub_59A54D | acquire lock/synchronization primitive |
| 0059a5e9 | sub_59A5E9 | release lock/synchronization primitive |

**Guard conditions:** Checks whether dword_5E9EF4 was 1 before decrement (post-decrement check: old value == 1). If true (counter reached zero), calls StatusCheckWithErrorDispatch on three globals (unk_8D42A0, dword_8D43C8, dword_8D4210) for cleanup. Otherwise returns lock release result without cleanup.
