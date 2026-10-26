## QueueResourceCleanup_0054c410 — Queued resource cleanup

**Summary:** Frees multiple types of queued resources: audio resources, linked-list managed objects, an array of 56-byte structures, and a single object pointer. Called during scene graph teardown to release all pending allocations.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneGraph (0054a770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x110 | RW | 0 | Pointer to array of 56-byte objects; freed and zeroed |
| this | 0x118 | R | — | Audio resource count (guard > 0) |
| this | 0x11C | R | — | Pointer to audio resource array (64-byte stride per element) |
| this | 0x13C | R | — | Linked list head pointer (each node next at +0x24) |
| this | 0x144 | RW | 0 | Single object cleanup pointer; freed and zeroed |
| this | 0x184 | R | — | unknown |

**Written-by note (persistence):**
- this 0x110: set to 0 after array freed; survives until then
- this 0x144: set to 0 after single object freed; survives until then

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | No-op stub called during each array element cleanup |
| 00540cb0 | AudioResourceFree | Frees an audio resource via the SoundManager |
| 00545f40 | ValueGetter | Retrieves UI root context pointer from global |
| 00547710 | sub_547710 | Removes/cleans up a resource reference from UI context |
| 005511a0 | ObjectDestructorWithArrayCleanup | Destructor for linked-list nodes containing sub-arrays |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x118 | > | 0 | Audio resource count |

**Guard interpretation:** If this[70] (audio resource count at +0x118) > 0, PASSES: iterates and frees each audio resource entry. If <= 0, BLOCKED: entire audio cleanup loop skipped. Additionally, this[68] (+0x110) and this[81] (+0x144) each guard their own cleanup block (non-null → free and zero).
