## VehicleSubsystemCleanup_00424010 — CleanupVehicleSubsystem

**Summary:** Frees dynamically allocated resource at this[4394] if non-null, calls stub, then cleans up vehicle subsystem at this+12.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44A8 | R | — | Dynamically allocated resource pointer (buffer/object) to free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Empty stub function (debug placeholder or disabled feature) |
| 00587bcf | FreeWrapper_7bcf | Free dynamically allocated memory (wrapper for free) |

**Guard conditions:** this[4394] == NULL: skip FreeWrapper_7bcf call (no resource to free). Passes always — stub and subsystem cleanup execute unconditionally.
