## ObjectInitWithVTableFieldSet_0057b780 — InitDynamicsObjectWithVTable

**Summary:** Initializes object with DynamicsObj vtable pointer and zeros field at offset 0x1C. Delegates base vtable chain setup to ObjectInitWithVTableSetup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57E280 (0057e280), SEHWrappedConstructor (0057ef20), NetworkPacketSend_0c10 (00580c10), sub_580DE0 (00580de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to DynamicsObj vtable) |
| this | 0x1C | RW | 0 | unknown field (zeroed on init) |

**Written-by note (persistence):**
- this 0x0: unconditionally set per init; external poke does not survive reinit
- this 0x1C: unconditionally set to 0 per init; external poke does not survive reinit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8a64 | off_5B8A64 | R | VTable_DynamicsObj_5B8A64 [DERIVED] — vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587030 | ObjectInitWithVTableSetup | set up base vtable chain and initial field defaults for the object |

**Guard conditions:** none — always executes unconditionally.
