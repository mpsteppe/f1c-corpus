## PhysicsShutdown_00431c70 — PhysicsSystemShutdown

**Summary:** Tears down the global physics system state. Walks and frees linked lists (input devices, collision geometry), deallocates flagged blocks (graphics state, device identity), and resets all heads to zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007c73f0 | dword_7C73F0 | R | GraphicsStateResetBlock [DERIVED] |
| 007c73f8 | dword_7C73F8 | R | InitFlagsBlock [DERIVED] |
| 007c7404 | dword_7C7404 | RW | CollisionInitZeroBlock [DERIVED] |
| 007c7408 | dword_7C7408 | W | PhysicsStateInitBlock [DERIVED] (also: ` to `_DAT_007c7424` — set to 0) |
| 007c740c | dword_7C740C | W | Unknown_Camera_7C740C [DERIVED] |
| 007c7410 | dword_7C7410 | W | Int_RenderListHead [DERIVED] |
| 007c7418 | dword_7C7418 | RW | InputDeviceListHead [DERIVED] (also: ` — set to 0) |
| 007c741c | dword_7C741C | W | LinkedListTail_7C741C [DERIVED] |
| 007c7420 | dword_7C7420 | W | Unknown_List_7C7420 [DERIVED] |
| 007c7424 | dword_7C7424 | W | InitFlagField_7424 [DERIVED] (also: ` — set to 0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004331a0 | DualLinkedListCleanup | Initializes/cleans up doubly-linked list header |
| 00434240 | RecursiveNodeDeletion | Recursively deletes a linked-list node and its children |
| 00582290 | ConditionalFreeByFlagCheck | Frees memory if associated flag indicates allocation is valid |
| 00587bcf | FreeWrapper_7bcf | Low-level memory deallocation wrapper |

**Guard conditions:** Four non-null checks on global pointers: dword_7C7418 (input device list head) is walked and freed if non-null; dword_7C7404 (collision geometry list head) is walked and freed if non-null; dword_7C73F8 is freed if non-null; dword_7C73F0 is freed if non-null. dword_7C73E8 is freed if non-null (also used as return value).
