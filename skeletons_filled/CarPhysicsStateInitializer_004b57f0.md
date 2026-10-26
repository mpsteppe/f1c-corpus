## CarPhysicsStateInitializer_004b57f0 — Car Physics State Initializer / Constructor

**Summary:** Initializes a car physics state object by zeroing most fields and setting default sentinels, timer state, and configuration constants. Called once per car physics object creation during game setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArithmeticComparison_9780 (004b9780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | physics state word 0 (zeroed) |
| this | 0x4 | RW | 0 | physics state word 1 (zeroed) |
| this | 0x8 | RW | 0 | physics state word 2 (zeroed) |
| this | 0xC | RW | 0 | physics state word 3 (zeroed) |
| this | 0x20 | RW | 0 | physics vector/scalar field 8 (zeroed) |
| this | 0x24 | RW | 0 | physics vector/scalar field 9 (zeroed) |
| this | 0x28 | RW | 0 | physics vector/scalar field 10 (zeroed) |
| this | 0x2C | RW | 0 | physics vector/scalar field 11 (zeroed) |
| this | 0x40 | RW | 0 | zeroed array element (from memset loop at this+16) |
| this | 0x44 | RW | 0 | zeroed array element (from memset loop at this+17) |
| this | 0x48 | RW | 0 | zeroed array element (from memset loop at this+18) |
| this | 0x4C | RW | 0 | zeroed array element (from memset loop at this+19) |
| this | 0x6C0 | RW | 0 | zeroed DWORD at this[432] |
| this | 0x6C4 | RW | 0 | zeroed DWORD at this[433] |
| this | 0x6C8 | RW | 0 | zeroed DWORD at this[434] |
| this | 0x6CC | RW | 0 | zeroed DWORD at this[435] |
| this | 0x6D4 | RW | 0 | zeroed DWORD at this[437] |
| this | 0x6D8 | RW | 0 | zeroed DWORD at this[438] |
| this | 0x6DC | RW | 0 | zeroed DWORD at this[439] |
| this | 0x6E0 | RW | 0 | zeroed DWORD at this[440] |
| this | 0x700 | RW | 0 | this[448] (zeroed late, after timer init block) |
| this | 0x704 | RW | 0 | this[449] = 0 (after ZeroInitSmallStruct) |
| this | 0x708 | RW | 18446744073709551615 | this[450] = -1 (sentinel / invalid index) |
| this | 0x70C | RW | 0 | this[451] = 0 |
| this | 0x710 | RW | 18446744073709551615 | this[452] = -1 (sentinel / invalid index) |
| this | 0x714 | RW | 0 | this[453] = 0 |
| this | 0x718 | RW | 0 | this[454] = 0 |
| this | 0x71C | RW | 0 | this[455] = 0 |
| this | 0x720 | RW | 0 | this[456] = 0 |
| this | 0x724 | RW | 0 | this[457] = 0 |
| this | 0x728 | RW | 18446744073709551615 | this[458] = -1 (sentinel / invalid index) |
| this | 0x72C | RW | 0 | this[459] = 0 |
| this | 0x730 | RW | 18446744073709551615 | this[460] = -1 (sentinel / invalid index) |
| this | 0x9A4 | RW | 4 | this[617] = 4 (default physics config value) |
| this | 0x9A8 | RW | 2 | this[618] = 2 (default physics config value, short) |
| this | 0x9AC | RW | 2 | this[619] = 2 (default physics config value, short) |
| this | 0x9B0 | RW | 0 | this[620] = 0 (zeroed) |
| this | 0x9B4 | RW | 0 | this[621] = 0 (zeroed) |
| this | 0x9B8 | RW | 0 | this[622] = 0 (zeroed) |
| this | 0x9BC | RW | 0 | this[623] = 0 (zeroed) |
| this | 0xD28 | RW | 0 | this[842] = 0 (zeroed before timer init) |
| this | 0xD78 | RW | 18446744073685857945 | this[862] = -23693671 (init constant for deformation/damage struct) |
| this | 0xF24 | RW | 0 | this[969] = 0 (zeroed after memset range) |
| this | 0xF28 | RW | 0 | this[970] = 0 (zeroed after memset range) |
| this | 0xF2C | RW | 0 | this[971] = 0 (zeroed after memset range) |
| this | 0xF30 | RW | 0 | this[972] = 0 (zeroed after memset range) |
| this | 0xF34 | RW | 0 | this[973] = 0 (zeroed after memset range) |
| this | 0xF38 | RW | 0 | this[974] = 0 (zeroed before sentinel) |
| this | 0xF3C | RW | 0 | this[975] = 0 (zeroed before sentinel) |
| this | 0xF40 | RW | 18446744073709551615 | this[976] = -1 (sentinel / invalid index) |
| this | 0xF44 | RW | 0 | this[977] = 0 (zeroed) |
| this | 0xF48 | RW | 0 | this[978] = 0 (zeroed) |
| this | 0xF4C | RW | 0 | this[979] = 0 (zeroed) |
| this | 0xF50 | RW | 0 | this[980] = 0 (zeroed) |
| this | 0xF64 | RW | 0 | this[985] = 0 (after QuadZeroInit) |
| this | 0xF68 | RW | 0 | this[986] = 0 (after QuadZeroInit) |
| this | 0xF6C | RW | 0 | this[987] = 0 (after QuadZeroInit) |
| this | 0xF70 | RW | 0 | this[988] = 0 (after QuadZeroInit) |
| this | 0xF74 | RW | 18446744073658219970 | this[989] = -51331646 (init constant) |
| this | 0xF78 | RW | 1 | byte at this+3960 = 1 (flag, enabled) |
| this | 0xF79 | RW | 1 | byte at this+3961 = 1 (flag, enabled) |
| this | 0xF7A | RW | 1 | byte at this+3962 = 1 (flag, enabled) |
| this | 0xF7C | RW | — | float: 1.0/8.0 = 0.125 (timestep or damping factor written via float* cast) |
| this | 0xF81 | RW | 0 | byte at this+3969 = 0 (flag, disabled) |
| this | 0xF8C | RW | 5 | this[995] = 5 (default config value) |
| this | 0xF90 | RW | 1147207680 → 900.0f | this[996] = 900.0f (default config float) |
| this | 0xF94 | RW | 0 | this[997] = 0 (zeroed before sentinel) |
| this | 0xF98 | RW | 18446744073709551615 | this[998] = -1 (sentinel / invalid index) |

**Written-by note (persistence):**
- this 0x0: initializer — external poke persists until next call of this function
- this 0x4: initializer — external poke persists until next call of this function
- this 0x8: initializer — external poke persists until next call of this function
- this 0xC: initializer — external poke persists until next call of this function
- this 0x20: initializer — external poke persists until next call of this function
- this 0x24: initializer — external poke persists until next call of this function
- this 0x28: initializer — external poke persists until next call of this function
- this 0x2C: initializer — external poke persists until next call of this function
- this 0x40: initializer — external poke persists until next call of this function
- this 0x44: initializer — external poke persists until next call of this function
- this 0x48: initializer — external poke persists until next call of this function
- this 0x4C: initializer — external poke persists until next call of this function
- this 0x6C0: initializer — external poke persists until next call of this function
- this 0x6C4: initializer — external poke persists until next call of this function
- this 0x6C8: initializer — external poke persists until next call of this function
- this 0x6CC: initializer — external poke persists until next call of this function
- this 0x6D4: initializer — external poke persists until next call of this function
- this 0x6D8: initializer — external poke persists until next call of this function
- this 0x6DC: initializer — external poke persists until next call of this function
- this 0x6E0: initializer — external poke persists until next call of this function
- this 0x700: initializer — external poke persists until next call of this function
- this 0x704: initializer — external poke persists until next call of this function
- this 0x708: initializer — external poke persists until next call of this function
- this 0x70C: initializer — external poke persists until next call of this function
- this 0x710: initializer — external poke persists until next call of this function
- this 0x714: initializer — external poke persists until next call of this function
- this 0x718: initializer — external poke persists until next call of this function
- this 0x71C: initializer — external poke persists until next call of this function
- this 0x720: initializer — external poke persists until next call of this function
- this 0x724: initializer — external poke persists until next call of this function
- this 0x728: initializer — external poke persists until next call of this function
- this 0x72C: initializer — external poke persists until next call of this function
- this 0x730: initializer — external poke persists until next call of this function
- this 0x9A4: initializer — external poke persists until next call of this function
- this 0x9A8: initializer — external poke persists until next call of this function
- this 0x9AC: initializer — external poke persists until next call of this function
- this 0x9B0: initializer — external poke persists until next call of this function
- this 0x9B4: initializer — external poke persists until next call of this function
- this 0x9B8: initializer — external poke persists until next call of this function
- this 0x9BC: initializer — external poke persists until next call of this function
- this 0xD28: initializer — external poke persists until next call of this function
- this 0xD78: initializer — external poke persists until next call of this function
- this 0xF24: initializer — external poke persists until next call of this function
- this 0xF28: initializer — external poke persists until next call of this function
- this 0xF2C: initializer — external poke persists until next call of this function
- this 0xF30: initializer — external poke persists until next call of this function
- this 0xF34: initializer — external poke persists until next call of this function
- this 0xF38: initializer — external poke persists until next call of this function
- this 0xF3C: initializer — external poke persists until next call of this function
- this 0xF40: initializer — external poke persists until next call of this function
- this 0xF44: initializer — external poke persists until next call of this function
- this 0xF48: initializer — external poke persists until next call of this function
- this 0xF4C: initializer — external poke persists until next call of this function
- this 0xF50: initializer — external poke persists until next call of this function
- this 0xF64: initializer — external poke persists until next call of this function
- this 0xF68: initializer — external poke persists until next call of this function
- this 0xF6C: initializer — external poke persists until next call of this function
- this 0xF70: initializer — external poke persists until next call of this function
- this 0xF74: initializer — external poke persists until next call of this function
- this 0xF78: initializer — external poke persists until next call of this function
- this 0xF79: initializer — external poke persists until next call of this function
- this 0xF7A: initializer — external poke persists until next call of this function
- this 0xF7C: initializer — external poke persists until next call of this function
- this 0xF81: initializer — external poke persists until next call of this function
- this 0xF8C: initializer — external poke persists until next call of this function
- this 0xF90: initializer — external poke persists until next call of this function
- this 0xF94: initializer — external poke persists until next call of this function
- this 0xF98: initializer — external poke persists until next call of this function

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005acd08 | flt_5ACD08 | R | CameraModelVTable [DERIVED] |
| 005acd24 | dword_5ACD24 | R | D3DRenderDefaultColor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ba820 | QuadZeroInit | zeroes 4 consecutive DWORDs (used for small struct/vector zeroing) |
| 004baac0 | ConditionalArrayAlloc | conditional memory allocation returning array pointer |
| 004bb150 | ListAppendWithSubListGeneration | appends a node to a list, generating sub-lists as needed |
| 004ff670 | PassthroughWrapper_f670 | passthrough wrapper initializing a sub-struct at this+624 |
| 005668b0 | ZeroInitSmallStruct | zeroes a small sub-struct (passed this+441) |
| 00568ba0 | StructZeroInit_8ba0 | zeroes a larger sub-struct (passed this+843, timer-related) |
| 00568be0 | QPCTimerInitialization | initializes QueryPerformanceCounter-based timer subsystem |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | resets/initializes a QPC timer at this+843 |
| 00587c03 | OperatorNewNhMallocWrapper | wrapper for operator new / heap allocation |

**Guard conditions:** No guard conditions — unconditional initialization, all writes always execute.
