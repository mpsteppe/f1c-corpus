## ProcessingDispatch_0046e590 — Processing dispatch

**Summary:** Calls cleanup on device identity handle, accesses UI list element at index 0, and sets a path register field with flag 0x40000000. Short processing chain for UI list item interaction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c73e8 | dword_7C73E8 | W | DeviceIdentityHandle1 — cleaned up via CleanupWrapper |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00433eb0 | CleanupWrapper | cleanup/deallocation on device identity handle |
| 00487010 | UIListIndexedAccessor | accesses UI list element at given index |
| 00498d00 | PathRegisterFieldSet | sets field on path register object with specified flags (0x40000000) |

**Guard conditions:** No guards. All three calls execute unconditionally.
