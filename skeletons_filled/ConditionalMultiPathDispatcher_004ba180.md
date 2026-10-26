## ConditionalMultiPathDispatcher_004ba180 — Key-priority multi-path dispatcher

**Summary:** Dispatches between steering animation and alternative handler based on KeyPriorityChain result. Then conditionally processes driver entries if float field mismatch or flag is set. Resets flag after processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0xF80 | RW | 0 | Processing flag; cleared after driver entry update |
| this | 0x0 | R | — | Type/sentinel identifier (must ==2 to proceed) |
| this | 0x8 | R | — | Pointer to sub-data struct passed to handlers |

**Written-by note (persistence):**
- *(this+0x8) 0xF80: cleared to 0 after driver entry processing; persists if condition not met

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b8bd0 | KeyPriorityChain | Get current key priority/action ID (returns 2 for steering animation path) |
| 004b8c40 | sub_4B8C40 | Alternative handler when key priority != 2 |
| 004b9a00 | PackedFlagRead_9a00 | Read packed bit flag at this+0x8 (skips KeyPriorityChain if set) |
| 004b9e40 | PitServiceSteeringAnimationStep | Step pit service steering animation |
| 004c8dc0 | GuardedVirtualCall | Guarded call with parameter (steering animation trigger) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 2 | Type/sentinel identifier |

**Guard interpretation:** BLOCKS (early return) when this[0] != 2. PASSES when this[0] == 2.
