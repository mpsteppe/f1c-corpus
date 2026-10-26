## SuspensionFloatClamp_0047a290 — SuspensionFloatClampLoop

**Summary:** Suspension float clamp: reads a value from a virtual call (vtable+0xB4), then iterates a float array clamping each element within per-element min/max bounds. Array stride is 27 floats (0x6c bytes) per entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | Virtual function slot (vtable+0xB4) returning the value to clamp |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0x100 | R | — | Enable flag byte — when non-zero, clamp loop executes |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface |
| 007d17cc | unk_7D17CC | R | SuspensionFloatArray (stride 0x6c) — start of iteration |
| 007d1b2c | flt_7D1B2C | R | Upper bound address for array iteration (loop ends before this) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466910 | SetupValueDisplayFormatter | Initializes display formatting context for this object |
| 00490190 | ZeroCheckGetter | Validates command dispatch object state (checks for zero/null before iteration) |

**Guard conditions:** Three nested checks: (1) v2 from command dispatch (cmd 9) must be non-null; (2) byte at this+0x100 must be non-zero; (3) ZeroCheckGetter(v2) must pass. All three must pass for clamp loop to execute.
