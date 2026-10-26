## ConstructorWithByteParams_00487220 — WidgetConstructorWithByteParams

**Summary:** Widget constructor that calls base constructor (ShortComputation_5e30), sets vtable to WidgetBase (off_5AB968), and stores two byte parameters at offsets 0xE0 and 0xE1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_d5f0 (0046d5f0), ObjectConstructorWithVTable_d680 (0046d680), sub_46DD10 (0046dd10), ConstructorWithVTableAndParamStore (0046f610), ShortComputation_f890 (0046f890), ObjectCreateWithVtable (0046fcf9), SimpleObjectConstructor (00474ff0), SeasonDatabaseObjectFactory (0047f440), LargeZeroInitConstructor (0048d740), ShortComputation_e300 (0048e300), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer — set to off_5AB968 (WidgetBase) |
| this | 0xE0 | RW | — | first byte parameter (a2) — constructor argument |
| this | 0xE1 | RW | — | second byte parameter (a3) — constructor argument |

**Written-by note (persistence):**
- this 0x0: set once (constructor); persists until destruction
- this 0xE0: set once; persists (constructor init)
- this 0xE1: set once; persists (constructor init)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ab968 | off_5AB968 | R | VTable_WidgetBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | base class constructor call |

**Guard conditions:** None (constructor — unconditional initialization).
