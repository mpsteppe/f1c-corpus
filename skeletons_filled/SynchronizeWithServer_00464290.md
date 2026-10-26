## SynchronizeWithServer_00464290 — Server Synchronization State Machine

**Summary:** Synchronizes multiplayer session with server. If state at +0x3FC4 is non-zero: initializes arrays, clears player slots, optionally runs collision detection loop. If sync flag not set, initializes structs in a loop. Based on state value (1/2 vs other), configures byte field or sets timeout/retry values. Always clears accumulated fields and runs array initialization. Returns state value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | RW | 5.0 (float) | retry timeout set when state not 1 or 2 |
| obj | 0x14 | RW | 1 | active flag set when state not 1 or 2 |
| obj | 0x28 | RW | 1 | sync flag; checked/set for init path selection |
| obj | 0x380 | RW | 0 | accumulated/cleared value (scoring-related) |
| obj | 0x388 | RW | 0 | accumulated/cleared value (scoring-related) |
| obj | 0x390 | RW | 1008981770 → 0.01f | float threshold set when state not 1 or 2 |
| obj | 0x3FB8 | R | — | sub-object pointer for byte field setter |
| obj | 0x3FC4 | R | — | state value: 1 or 2 selects one path, 3 selects collision detection, else sets timeout |
| obj | 0x1B790 | R | — | byte flag checked for additional init call |
| obj | 0x1B791 | R | — | second byte flag checked with first for init |
| this | 0x0 | R | — | vtable/primary pointer |

**Written-by note (persistence):**
- obj 0x10: written conditionally when state not 1 or 2; survives until next write
- obj 0x14: written conditionally when state not 1 or 2; survives until next write
- obj 0x28: written once per call when first-time sync; survives until next sync
- obj 0x380: written to 0 every call; overwritten each invocation
- obj 0x388: written to 0 every call; overwritten each invocation
- obj 0x390: written conditionally when state not 1 or 2; survives until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f0a0 | flt_59F0A0 | R | MulticastTimeout [DERIVED] |
| 0059f0b8 | flt_59F0B8 | R | NetSyncTimeout [DERIVED] (also: ` — float constants (timeout/default) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6634 | aEnteringSynchr | R | EnteringSyncString [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007d105c | byte_7D105C | R | NetworkSyncFlag [DERIVED] (also: ` — session flag) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c8b0 | ArrayInitializationLoop | final array init at this+0x68F0 |
| 0045f390 | RunCollisionDetectionLoop | runs collision detection during sync |
| 00460c60 | ArrayInitWithSentinelInLoop | initializes array with sentinel values at start of sync |
| 00460cb0 | ClearPlayerSlots | clears multiplayer player slots |
| 004d7a50 | StringSplitLoop | dev-mode check for debug logging guard |
| 004d7aa0 | DebugLogWrite | writes "Entering synchronization" debug log |
| 004fffa0 | ThunkWithStructInitSubCalls | initializes structs in range (218-byte stride, 22672 range) |
| 0057a570 | ByteFieldSetterAtOffset0x5d | sets byte at offset 0x5d on sub-object based on session type |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3FC4 | == | 3 | sync state for collision detection |

**Guard interpretation:** State at +0x3FC4 must be non-zero to enter sync path at all. If zero: BLOCKED entirely. When state == 3: runs collision detection loop. When state is 1 or 2: configures byte field via session type. Otherwise: sets timeout/retry values.
