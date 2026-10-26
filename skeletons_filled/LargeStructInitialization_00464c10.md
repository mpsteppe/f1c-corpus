## LargeStructInitialization_00464c10 — CollisionSensorArrayInit

**Summary:** Initializes a large collision-sensor structure: zeroes sub-regions, creates 104 sensor entries each with an allocated tracking node and collision sensor init, sets sentinel and scale defaults, and initializes QPC timer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SingleFunctionCallWrapper_4930 (00464930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | RW | 18446744073709551615 | sentinel value (-1 int64, uninitialized/max-id marker) |
| this | 0x54 | RW | 18446744073709551615 | sentinel value (-1 int64, uninitialized/max-id marker) |
| this | 0x60 | RW | 1065353216 → 1.0f | default scale/normalization factor (1.0f) |
| this | 0x64 | RW | 1065353216 → 1.0f | default scale/normalization factor (1.0f) |
| this | 0x6C | RW | 0 | zero-init sensor sub-field (part of StructZeroInit region) |
| this | 0x70 | RW | 0 | zero-init sensor sub-field |
| this | 0x74 | RW | 0 | zero-init sensor sub-field |
| this | 0x78 | RW | 0 | zero-init sensor sub-field |
| this | 0x7C | RW | 0 | zero-init sensor sub-field |
| this | 0x80 | RW | 0 | zero-init sensor sub-field |
| this | 0x84 | RW | 0 | zero-init sensor sub-field |
| this | 0x88 | RW | 0 | zero-init sensor sub-field |
| this | 0x2AC | RW | 0 | per-sensor entry zero-init (within 104-iteration loop, entry offset +0x220) |
| this | 0x2B0 | RW | 0 | per-sensor entry zero-init (entry offset +0x224) |
| this | 0x2B4 | RW | 0 | per-sensor entry zero-init as WORD (entry offset +0x228) |
| this | 0x2B8 | RW | — | per-sensor allocated tracking node pointer (8 bytes, stores backref + -1.0f sentinel) |
| this | 0xE40C | RW | 0 | tail region counter/flag zeroed after loop |
| this | 0xE5B0 | RW | 0 | tail zero-init: array slot 14700 |
| this | 0xE5B4 | RW | 0 | tail zero-init: array slot 14701 |
| this | 0xE5B8 | RW | 0 | tail zero-init: array slot 14702 |
| this | 0xE5BC | RW | 0 | tail zero-init: array slot 14703 |
| this | 0xE5C0 | RW | 0 | tail zero-init: array slot 14704 |
| this | 0xE5C4 | RW | 0 | tail zero-init: array slot 14705 |
| this | 0xE5C8 | RW | 0 | tail zero-init: array slot 14706 |
| this | 0xE5CC | RW | 0 | tail zero-init: array slot 14707 |

**Written-by note (persistence):**
- this 0x50: once per call; constructor-style init, unconditionally written
- this 0x54: once per call; constructor-style init, unconditionally written
- this 0x60: once per call; constructor-style init, unconditionally written
- this 0x64: once per call; constructor-style init, unconditionally written
- this 0x6C: once per call via StructZeroInit, unconditionally written
- this 0x70: once per call via StructZeroInit, unconditionally written
- this 0x74: once per call via StructZeroInit, unconditionally written
- this 0x78: once per call via StructZeroInit, unconditionally written
- this 0x7C: once per call via StructZeroInit, unconditionally written
- this 0x80: once per call via StructZeroInit, unconditionally written
- this 0x84: once per call via StructZeroInit, unconditionally written
- this 0x88: once per call via StructZeroInit, unconditionally written
- this 0x2AC: once per call per entry (loop 104x), unconditionally written
- this 0x2B0: once per call per entry (loop 104x), unconditionally written
- this 0x2B4: once per call per entry (loop 104x), unconditionally written
- this 0x2B8: once per call per entry (loop 104x), unconditionally written via allocation
- this 0xE40C: once per call, unconditionally written
- this 0xE5B0: once per call, unconditionally written
- this 0xE5B4: once per call, unconditionally written
- this 0xE5B8: once per call, unconditionally written
- this 0xE5BC: once per call, unconditionally written
- this 0xE5C0: once per call, unconditionally written
- this 0xE5C4: once per call, unconditionally written
- this 0xE5C8: once per call, unconditionally written
- this 0xE5CC: once per call, unconditionally written

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00464d20 | sub_464D20 | R | callback function pointer passed to sub_401000 as iterator/visitor for each sensor entry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401000 | sub_401000 | iterator/initializer called per sensor entry with callback, takes struct pointer, count params |
| 00464a40 | CollisionSensorInit | initializes collision sensor subsystem for a single sensor entry |
| 00568ba0 | StructZeroInit_8ba0 | zero-initializes large struct region starting at this+4 |
| 00568be0 | QPCTimerInitialization | initializes high-resolution QPC (QueryPerformanceCounter) timer with parameter 1 |
| 00587c03 | OperatorNewNhMallocWrapper | no-throw malloc/new wrapper for allocating 8-byte tracking nodes |

**Guard conditions:** no guard conditions — function always executes unconditionally. All init writes are unguarded.