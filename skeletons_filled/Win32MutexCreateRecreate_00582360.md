## Win32MutexCreateRecreate_00582360 — Mutex create/recreate with close existing

**Summary:** If flag at this+0x18 indicates mutex exists, closes old handle via CloseHandle and zeros it. Creates new unnamed inheritable mutex via CreateMutexA with default security attributes, stores at this+0x10. Sets flag at this+0x18 to 1 on success. Returns flag value (1=mutex ready, 0=failed).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BA10 (0057ba10), sub_5837F0 (005837f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 0 | Mutex handle; closed if existing then set to new CreateMutexA result |
| this | 0x18 | RW | 1 | Byte flag indicating mutex validity; set to 0 on close, set to 1 on successful create |

**Written-by note (persistence):**
- this 0x10: Updated every call — old handle closed, new handle stored. Persists until next call.
- this 0x18: Set to 1 on successful create, 0 on close. Persists as mutex state.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | Close existing mutex handle before recreating |
| 0059e1ac | CreateMutexA | R | Create unnamed inheritable mutex with default security |
| ff00000000005450 | byte_FF00000000005450 | W | Unknown — written byte |
| ff00000000005451 | byte_FF00000000005451 | W | Unknown — written byte |
| ff00000000005452 | byte_FF00000000005452 | W | Unknown — written byte |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks flag at this+0x18. If non-zero, closes handle at this+0x10 via CloseHandle; zeros handle on success. Always creates new mutex afterward (unconditional).
