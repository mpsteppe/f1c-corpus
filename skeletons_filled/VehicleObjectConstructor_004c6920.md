## VehicleObjectConstructor_004c6920 — Vehicle object constructor

**Summary:** Initialises a vehicle object struct: calls RaceStructInit to zero-init fields, sets field at +0x4894 to -1 (invalid/unset), clears driver info, and stores a self-reference via LargeStructFieldSetterWithStoredReference.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RepeatedCallLoop (0042bb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4894 | RW | 18446744073709551615 | default-initialised handle/ID, set to -1 (all bits set) indicating uninitialised |

**Written-by note (persistence):**
- this 0x4894: written once with -1 during construction; persists as initial default

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423e80 | RaceStructInit | zero-initialise race/vehicle struct fields |
| 00424040 | LargeStructFieldSetterWithStoredReference | store persistent self-reference pointer in the object |
| 004c79e0 | VehicleDriverInfoClear | clear driver info substructure fields |

**Guard conditions:** none — unconditional init, all calls and assignments always execute
