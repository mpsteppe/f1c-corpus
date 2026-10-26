## sub_45EFE8_0045efe8 — DirectInput game-controller device init (exclusive, buffered)

**Summary:** Initializes a second DirectInput device on the object at a2: fills 8 float slots (0x20-0x3C) with 0.05f and 8 dwords (0x2F8-0x314) with a1, ensures device enumeration counted 20 entries (else runs EnumDevices for class 4 with callback sub_45E800), creates the device, QueryInterfaces unk_726A04 into a2[32], then configures the device — Unacquire, SetDataFormat(&unk_7268BC), SetCooperativeLevel(9 = exclusive|background), GetCapabilities into a2[178] (dwSize 44), a DIPROPHEADER-like SetProperty with zero value — acquires it, and tail-calls sub_45DFC0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045e800 | sub_45E800 | R | enumeration callback passed to EnumDevices (records/picks devices during the class-4 scan) |
| 007268bc | unk_7268BC | R | device data-format descriptor passed to SetDataFormat |
| 00726a04 | unk_726A04 | R | interface IID used by the QueryInterface that fills a2[32] |
| 00b69668 | dword_B69668 | R | global DirectInput object used for EnumDevices (vtable+16) and CreateDevice (vtable+12) |
| 00b6a3f0 | dword_B6A3F0 | W | scratch global cleared (set to 0) immediately before the enumeration scan |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045dfc0 | sub_45DFC0 | tail-called with the object pointer as the final init step; its return value becomes this function's result |

**Guard conditions:** Device-count guard: if a2[189] != 20 the function zeroes dword_B6A3F0, runs EnumDevices on dword_B69668 with device class 4, callback sub_45E800, pvRef 20 and flags 1, then requires a2[189]==20 again — otherwise returns -1. Each interface call is a failure gate: vtable+12 create-device step, the QueryInterface (nonzero result, or a2[32]==0 afterwards), SetDataFormat, SetCooperativeLevel, GetCapabilities all return -1 on failure; the SetProperty (+24) and Acquire (+28) results are ignored. The successful path ends in sub_45DFC0(a2), whose value is returned verbatim.

**Guard interpretation:** PASS requires the object to already hold a2[189]==20 (skipping enumeration) or the enumeration to produce it. After that, any failing device call aborts with -1: create, QueryInterface into a2[32] (with null output also treated as failure), SetDataFormat(&unk_7268BC), SetCooperativeLevel(v16, 9), and GetCapabilities(a2+178). Notably the +8 call on a3 and the +32 call (Unacquire) on the queried interface are not checked, and the DIPROPHEADER-style SetProperty(5, {20,16,0,0,0}) and the final Acquire have their results ignored — a failed Acquire still falls through to sub_45DFC0, which decides the final return value.
