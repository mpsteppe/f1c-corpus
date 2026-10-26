## GenericObjectConstructorWithVTable_00406ab0 — AudioStreamObjectConstructor

**Summary:** Constructs an audio stream object: sets vtable to VTable_StreamObject, zeroes all data fields, initializes specific parameters (count=1, float=1.0f, index=2), and allocates Miles sound samples.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OneTimeInitializationWithAtexitStyleRegistration (00404fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to VTable_StreamObject) |
| this | 0x4 | RW | 1 | count/index (set to 1) |
| this | 0x8 | RW | 0 | zeroed data field |
| this | 0xC | RW | 0 | zeroed data field |
| this | 0x10 | RW | 0 | zeroed data field |
| this | 0x14 | RW | 0 | zeroed data field |
| this | 0x18 | RW | 0 | zeroed data field |
| this | 0x1C | RW | 0 | zeroed data field |
| this | 0x20 | RW | 0 | zeroed data field |
| this | 0x24 | RW | 0 | zeroed data field |
| this | 0x28 | RW | 0 | zeroed data field |
| this | 0x2C | RW | 0 | zeroed data field |
| this | 0x30 | RW | 0 | zeroed data field |
| this | 0x34 | RW | 0 | zeroed data field |
| this | 0x38 | RW | 0 | zeroed data field |
| this | 0x3C | RW | 0 | zeroed data field |
| this | 0x40 | RW | 0 | zeroed data field |
| this | 0x44 | RW | 0 | zeroed data field |
| this | 0x48 | RW | 0 | zeroed data field |
| this | 0x54 | RW | 2 | sample count/selector (set to 2) |
| this | 0x88 | RW | 0 | zeroed flag/field |
| this | 0x8C | RW | 1065353216 → 1.0f | float value initialized to 1.0 |
| this | 0x90 | RW | 0 | driver handle (initially zero) |
| this | 0x94 | RW | 0 | zeroed data field |
| this | 0x98 | RW | 0 | zeroed data field |
| this | 0x9C | RW | 0 | zeroed data field |

**Written-by note (persistence):**
- this 0x0: written once during construction — external poke changes vtable/destroys type identity
- this 0x4: written once during construction — external poke changes count
- this 0x8-0x48: written once during construction — external poke survives (fields zeroed once)
- this 0x54: written once during construction — external poke changes sample count
- this 0x88: written once during construction — external poke survives
- this 0x8C: written once during construction — external poke changes float value
- this 0x90: written once during construction — external poke changes driver handle
- this 0x94-0x9C: written once during construction — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e530 | off_59E530 | R | VTable_StreamObject [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004072e0 | MilesSoundSystemSampleAllocator | allocates Miles sound samples with initial count parameter 0 |

**Guard conditions:** none — constructor always executes fully
