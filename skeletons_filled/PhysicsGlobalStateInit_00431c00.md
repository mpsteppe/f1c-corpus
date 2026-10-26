## PhysicsGlobalStateInit_00431c00 — GlobalPhysicsStateReset

**Summary:** Resets global physics state variables to default values. Writes -1 to three sentinel/identity fields and 0 to all other state fields, then calls DualLinkedListCleanup on the global physics state block.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c73e8 | dword_7C73E8 | RW | DeviceIdentityHandle1 [DERIVED] |
| 007c73ec | dword_7C73EC | W | InitSentinel_1 [DERIVED] |
| 007c73f0 | dword_7C73F0 | W | GraphicsStateResetBlock [DERIVED] |
| 007c73f4 | dword_7C73F4 | W | InitSentinelValue_Neg1 [DERIVED] |
| 007c73f8 | dword_7C73F8 | W | InitFlagsBlock [DERIVED] |
| 007c73fc | dword_7C73FC | W | MutexGroupInitNegOne [DERIVED] (also: ` — set to -1) |
| 007c7404 | dword_7C7404 | W | CollisionInitZeroBlock [DERIVED] |
| 007c7408 | dword_7C7408 | W | PhysicsStateInitBlock [DERIVED] (also: ` to `_DAT_007c7424` — set to 0) |
| 007c740c | dword_7C740C | W | Unknown_Camera_7C740C [DERIVED] |
| 007c7410 | dword_7C7410 | W | Int_RenderListHead [DERIVED] |
| 007c7418 | dword_7C7418 | W | InputDeviceListHead [DERIVED] (also: ` — set to 0) |
| 007c741c | dword_7C741C | W | LinkedListTail_7C741C [DERIVED] |
| 007c7420 | dword_7C7420 | W | Unknown_List_7C7420 [DERIVED] |
| 007c7424 | dword_7C7424 | W | InitFlagField_7424 [DERIVED] (also: ` — set to 0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional initialization.
