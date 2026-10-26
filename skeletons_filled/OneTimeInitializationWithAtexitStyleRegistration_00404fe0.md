## OneTimeInitializationWithAtexitStyleRegistration_00404fe0 — StaticSingletonInitializer

**Summary:** One-time initialization of a static object at unk_5EA440: checks init flag, constructs a generic vtable-backed object, registers an atexit-style cleanup/load-path wrapper, and returns the static buffer handle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsSaveWrapper (00405030), ShortComputation_5050 (00405050), MemoryAllocation_5160 (00405160), BinaryDataDeserialization (004054e0), ShortComputation_6100 (00406100), FileLoadWithRetryLoop (004f9b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00405020 | InitLoadPathWrapper | R | function pointer for atexit/load-path initialization wrapper |
| 005ea440 | unk_5EA440 | R | StaticBufferHandle [DERIVED] — static object buffer |
| 005ea4e0 | byte_5EA4E0 | RW | InitGateFlag [DERIVED] (also: ` — init flag (bit 0=initialized) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406ab0 | GenericObjectConstructorWithVTable | constructs a generic object with vtable pointer at given address |
| 00587b3e | BooleanToIntConversion | converts boolean to int, used as callback registration wrapper |

**Guard conditions:** Checks byte_5EA4E0 bit 0. PASSES (bit 0 clear): performs initialization and sets bit 0. BLOCKED (bit 0 set): skips initialization, returns existing static buffer handle.
