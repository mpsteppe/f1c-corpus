## MutexCreateRecreate_00586500 — MutexCreateRecreate

**Summary:** Conditionally closes existing mutex handle at offset 0x4 if flag at offset 0xC is set and CloseHandle succeeds, then creates a new unnamed mutex via CreateMutexA. Sets flag at offset 0xC to 1 on success and returns flag value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BA10 (0057ba10), sub_5837F0 (005837f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | Mutex handle: created via CreateMutexA; closed and cleared to 0 if old handle exists |
| this | 0xC | RW | 1 | Byte flag: 1 if mutex handle is valid; set to 1 on successful create, checked before CloseHandle |

**Written-by note (persistence):**
- this 0x4: overwritten each call with new CreateMutexA result; cleared to 0 if previous handle was closed
- this 0xC: set to 1 if CreateMutexA succeeds; persists as flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | Close previous mutex handle if flag is set |
| 0059e1ac | CreateMutexA | R | Create unnamed mutex with SECURITY_ATTRIBUTES (non-inheritable, no descriptor) |
| ff00000000005450 | byte_FF00000000005450 | W | unknown |
| ff00000000005451 | byte_FF00000000005451 | W | unknown |
| ff00000000005452 | byte_FF00000000005452 | W | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If flag at 0xC is non-zero AND CloseHandle succeeds, handle at 0x4 is cleared to 0 before creating new mutex. CreateMutexA is always called; flag at 0xC set to 1 only if CreateMutexA returns non-NULL.
