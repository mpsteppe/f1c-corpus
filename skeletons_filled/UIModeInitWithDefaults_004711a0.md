## UIModeInitWithDefaults_004711a0 — UIModeDefaultsConstructor

**Summary:** UI mode initialization constructor: calls base init (ShortComputation_6d60 with flag=1), sets vtable to off_5A0B40, stores pointer to SessionVehicleCount (dword_7D0A20) at 0x31C, and initializes mode fields (99, 2, 1, 1). No linked list insertions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0B40 |
| this | 0x31C | RW | — | pointer field, set to dword_7D0A20 (SessionVehicleCount) |
| this | 0x324 | RW | 99 | mode/limit value, initialized to 99 |
| this | 0x328 | RW | 2 | mode/state field, initialized to 2 |
| this | 0x32C | RW | 1 | boolean/flag field, initialized to 1 |
| this | 0x330 | RW | 1 | boolean/flag field, initialized to 1 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0B40; overwritten if external code changes vtable
- this 0x31C: set once to pointer dword_7D0A20; overwritten if external code writes to this field
- this 0x324: set once to 99; survives unless external code changes it
- this 0x328: set once to 2; same
- this 0x32C: set once to 1; same
- this 0x330: set once to 1; same

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0b40 | off_5A0B40 | R | vtable pointer assigned to this object |
| 007d0a20 | dword_7D0A20 | R | SessionVehicleCount [DERIVED] — pointer stored in field at 0x31C |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | base screen initialization (flag=1) |

**Guard conditions:** No guards — unconditional initialization sequence.
