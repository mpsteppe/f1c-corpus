## UIScreenConstructor_3f50_00473f50 — UIScreenWithWeatherFlagInit

**Summary:** Initializes a UI element: sets vtable to off_5A33C0, stores pointer to WeatherStateFlag (dword_7CFC68) at offset 0x31C, configures flags (2/0/1/1), sets value 386 at 0x334, and registers three text-handle nodes (standard, RegisteredDataPtr, "High" label).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (off_5A33C0) |
| this | 0x31C | RW | — | pointer to WeatherStateFlag (dword_7CFC68) |
| this | 0x324 | RW | 2 | flag / counter field |
| this | 0x328 | RW | 0 | flag / counter field |
| this | 0x32C | RW | 1 | flag / counter field |
| this | 0x330 | RW | 1 | flag / counter field |
| this | 0x334 | RW | 386 | value / limit / counter preset |

**Written-by note (persistence):**
- this 0x0: once (constructor vtable); survives external poke
- this 0x31C: once (pointer to WeatherStateFlag); survives external poke
- this 0x324: once (literal 2); survives external poke
- this 0x328: once (literal 0); survives external poke
- this 0x32C: once (literal 1); survives external poke
- this 0x330: once (literal 1); survives external poke
- this 0x334: once (literal 386); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a33c0 | off_5A33C0 | R | vtable for this UI element type |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 — UI/text handle for first label |
| 005c32a4 | off_5C32A4 | R | RegisteredDataPtr — text handle for second label |
| 005c32a8 | aHigh | R | RegisteredCtrlPtr — text handle for "High" label |
| 007cfc68 | dword_7CFC68 | R | WeatherStateFlag — weather state flag referenced by pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | basic field initialization / zeroing |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert text-handle node into element's linked list |

**Guard conditions:** none — straight-line, no conditional branches.
