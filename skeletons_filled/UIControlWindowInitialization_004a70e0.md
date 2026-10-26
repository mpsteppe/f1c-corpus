## UIControlWindowInitialization_004a70e0 — UIControlWindowConstructor

**Summary:** Constructor that fully initializes a UI control window object by zeroing its core fields and setting up hundreds of sub-control slots with sentinel values (-1 = no target) and vtable pointers. Forms part of the game's UI system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | postProcessInput [CONFIRMED] |
| this | 0x4 | RW | 0 | input event handler / unknown flag |
| this | 0x8 | RW | 0 | unknown state field, zeroed |
| this | 0xC | RW | 0 | unknown state field, zeroed |
| this | 0x10 | RW | 0 | byte flag (bool), zeroed |
| this | 0x14 | RW | 0 | unknown state field, zeroed |
| this | 0x114 | RW | 0 | state field, zeroed during init |
| this | 0x118 | RW | — | sub-control block #0 vtable pointer |
| this | 0x124 | RW | — | sub-control block #1 vtable pointer |
| this | 0x130 | RW | 0 | sub-control block #1 state, inactive |
| this | 0x134 | RW | 18446744073709551615 | sub-control block #1 target sentinel (no target) |
| this | 0x138 | RW | 0 | sub-control block #1 state field 2, inactive |
| this | 0x13C | RW | 18446744073709551615 | sub-control block #1 target sentinel 2 (no target) |
| this | 0x140 | RW | — | sub-control block #2 vtable pointer |
| this | 0x14C | RW | 0 | sub-control block #2 state, inactive |
| this | 0x150 | RW | 18446744073709551615 | sub-control block #2 target sentinel (no target) |
| this | 0x154 | RW | 0 | sub-control block #2 state field 2, inactive |
| this | 0x158 | RW | 18446744073709551615 | sub-control block #2 target sentinel 2 (no target) |
| this | 0x15C | RW | — | sub-control block #3 vtable pointer |
| this | 0x168 | RW | 0 | sub-control block #3 state, inactive |
| this | 0x16C | RW | 18446744073709551615 | sub-control block #3 target sentinel (no target) |
| this | 0x170 | RW | 0 | sub-control block #3 state field 2, inactive |
| this | 0x174 | RW | 18446744073709551615 | sub-control block #3 target sentinel 2 (no target) |
| this | 0x178 | RW | — | sub-control block #4 vtable pointer |
| this | 0x184 | RW | — | sub-control block #4+5 anchor vtable |
| this | 0x190 | RW | 0 | sub-control block state, inactive |
| this | 0x194 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x198 | RW | 0 | sub-control block state field 2, inactive |
| this | 0x19C | RW | 18446744073709551615 | sub-control block target sentinel 2 (no target) |
| this | 0x1A0 | RW | — | sub-control block vtable pointer |
| this | 0x1AC | RW | 0 | sub-control block state, inactive |
| this | 0x1B0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1B4 | RW | 0 | sub-control block state field 2, inactive |
| this | 0x1B8 | RW | 18446744073709551615 | sub-control block target sentinel 2 (no target) |
| this | 0x1BC | RW | — | sub-control block vtable pointer |
| this | 0x1C8 | RW | 0 | sub-control block state, inactive |
| this | 0x1CC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1D0 | RW | 0 | sub-control block state field 2, inactive |
| this | 0x1D4 | RW | 18446744073709551615 | sub-control block target sentinel 2 (no target) |
| this | 0x1D8 | RW | — | sub-control block vtable pointer |
| this | 0x1E4 | RW | 0 | sub-control block state, inactive |
| this | 0x1E8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1EC | RW | 0 | sub-control block state field 2, inactive |
| this | 0x1F0 | RW | 18446744073709551615 | sub-control block target sentinel 2 (no target) |
| this | 0x1F4 | RW | — | sub-control block vtable pointer |
| this | 0x200 | RW | — | sub-control block vtable pointer (block start) |
| this | 0x20C | RW | 0 | sub-control block state, inactive |
| this | 0x210 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x224 | RW | — | sub-control block vtable pointer |
| this | 0x230 | RW | 0 | sub-control block state, inactive |
| this | 0x234 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x248 | RW | — | sub-control block vtable pointer |
| this | 0x254 | RW | 0 | sub-control block state, inactive |
| this | 0x258 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x26C | RW | — | sub-control block vtable pointer |
| this | 0x278 | RW | 0 | sub-control block state, inactive |
| this | 0x27C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x290 | RW | — | sub-control block vtable pointer |
| this | 0x29C | RW | 0 | sub-control block state, inactive |
| this | 0x2A0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x2B4 | RW | — | sub-control block vtable pointer |
| this | 0x2C0 | RW | 0 | sub-control block state, inactive |
| this | 0x2C4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x2D8 | RW | — | sub-control block vtable pointer |
| this | 0x2E4 | RW | 0 | sub-control block state, inactive |
| this | 0x2E8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x2FC | RW | — | sub-control block vtable pointer |
| this | 0x308 | RW | 0 | sub-control block state, inactive |
| this | 0x30C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x320 | RW | — | sub-control block vtable pointer |
| this | 0x32C | RW | 0 | sub-control block state, inactive |
| this | 0x330 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x344 | RW | — | sub-control block vtable pointer |
| this | 0x350 | RW | 0 | sub-control block state, inactive |
| this | 0x354 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x368 | RW | — | sub-control block vtable pointer |
| this | 0x374 | RW | 0 | sub-control block state, inactive |
| this | 0x378 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x38C | RW | — | sub-control block vtable pointer |
| this | 0x398 | RW | 0 | sub-control block state, inactive |
| this | 0x39C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x3A4 | RW | — | sub-control block vtable pointer |
| this | 0x3B0 | RW | 0 | sub-control block state, inactive |
| this | 0x3B4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x3C8 | RW | — | sub-control block vtable pointer |
| this | 0x3D4 | RW | 0 | sub-control block state, inactive |
| this | 0x3D8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x3E0 | RW | — | sub-control block vtable pointer |
| this | 0x3EC | RW | 0 | sub-control block state, inactive |
| this | 0x3F0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x3F8 | RW | — | sub-control block vtable pointer |
| this | 0x404 | RW | 0 | sub-control block state, inactive |
| this | 0x408 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x41C | RW | — | sub-control block vtable pointer |
| this | 0x428 | RW | 0 | sub-control block state, inactive |
| this | 0x42C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x440 | RW | — | sub-control block vtable pointer |
| this | 0x44C | RW | 0 | sub-control block state, inactive |
| this | 0x450 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x464 | RW | — | sub-control block vtable pointer |
| this | 0x470 | RW | 0 | sub-control block state, inactive |
| this | 0x474 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x488 | RW | — | sub-control block vtable pointer |
| this | 0x494 | RW | 0 | sub-control block state, inactive |
| this | 0x498 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x4AC | RW | — | sub-control block vtable pointer |
| this | 0x4B8 | RW | 0 | sub-control block state, inactive |
| this | 0x4BC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x4D0 | RW | — | sub-control block vtable pointer |
| this | 0x4DC | RW | 0 | sub-control block state, inactive |
| this | 0x4E0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x4E8 | RW | — | sub-control block vtable pointer |
| this | 0x4F4 | RW | 0 | sub-control block state, inactive |
| this | 0x4F8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x500 | RW | — | sub-control block vtable pointer |
| this | 0x50C | RW | 0 | sub-control block state, inactive |
| this | 0x510 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x524 | RW | — | sub-control block vtable pointer |
| this | 0x530 | RW | 0 | sub-control block state, inactive |
| this | 0x534 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x548 | RW | — | sub-control block vtable pointer |
| this | 0x554 | RW | 0 | sub-control block state, inactive |
| this | 0x558 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x56C | RW | — | sub-control block vtable pointer (with extra state fields) |
| this | 0x578 | RW | 0 | sub-control block state, inactive |
| this | 0x57C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x580 | RW | 0 | sub-control block extra state, inactive |
| this | 0x584 | RW | 18446744073709551615 | sub-control block extra target sentinel (no target) |
| this | 0x588 | RW | — | sub-control block vtable pointer (with extra state fields) |
| this | 0x594 | RW | 0 | sub-control block state, inactive |
| this | 0x598 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x59C | RW | 0 | sub-control block extra state, inactive |
| this | 0x5A0 | RW | 18446744073709551615 | sub-control block extra target sentinel (no target) |
| this | 0x5A4 | RW | — | sub-control block vtable pointer (special block) |
| this | 0x6AC | RW | — | sub-control block vtable pointer |
| this | 0x6B8 | RW | — | sub-control block vtable pointer |
| this | 0x6C4 | RW | 0 | sub-control block state, inactive |
| this | 0x6C8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x6D0 | RW | — | sub-control block vtable pointer |
| this | 0x6DC | RW | 0 | sub-control block state, inactive |
| this | 0x6E0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x6E8 | RW | — | sub-control block vtable pointer |
| this | 0x6F4 | RW | 0 | sub-control block state, inactive |
| this | 0x6F8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x700 | RW | — | sub-control block vtable pointer |
| this | 0x70C | RW | 0 | sub-control block state, inactive |
| this | 0x710 | RW | 18446744073709551615 | directionInTrack.x [CONFIRMED] |
| this | 0x718 | RW | — | directionInTrack.y [CONFIRMED] |
| this | 0x724 | RW | 0 | sub-control block state, inactive |
| this | 0x728 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x730 | RW | — | sub-control block vtable pointer |
| this | 0x73C | RW | 0 | sub-control block state, inactive |
| this | 0x740 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x748 | RW | — | sub-control block vtable pointer |
| this | 0x754 | RW | 0 | sub-control block state, inactive |
| this | 0x758 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x76C | RW | — | sub-control block vtable pointer |
| this | 0x778 | RW | 0 | sub-control block state, inactive |
| this | 0x77C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x784 | RW | — | sub-control block vtable pointer |
| this | 0x790 | RW | 0 | sub-control block state, inactive |
| this | 0x794 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x7A8 | RW | — | sub-control block vtable pointer |
| this | 0x7B4 | RW | 0 | sub-control block state, inactive |
| this | 0x7B8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x7CC | RW | — | sub-control block vtable pointer |
| this | 0x7D8 | RW | 0 | sub-control block state, inactive |
| this | 0x7DC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xD78 | RW | — | sub-control block vtable pointer |
| this | 0xD84 | RW | — | sub-control block vtable pointer |
| this | 0xD90 | RW | 0 | sub-control block state, inactive |
| this | 0xD94 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xDA8 | RW | — | sub-control block vtable pointer |
| this | 0xDB4 | RW | 0 | sub-control block state, inactive |
| this | 0xDB8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xDCC | RW | — | sub-control block vtable pointer |
| this | 0xDD8 | RW | 0 | sub-control block state, inactive |
| this | 0xDDC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xDF0 | RW | — | sub-control block vtable pointer |
| this | 0xDFC | RW | 0 | sub-control block state, inactive |
| this | 0xE00 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xE08 | RW | — | sub-control block vtable pointer |
| this | 0xE14 | RW | 0 | sub-control block state, inactive |
| this | 0xE18 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xE20 | RW | — | sub-control block vtable pointer |
| this | 0xE2C | RW | 0 | sub-control block state, inactive |
| this | 0xE30 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xE44 | RW | — | sub-control block vtable pointer |
| this | 0xE50 | RW | 0 | sub-control block state, inactive |
| this | 0xE54 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xE68 | RW | — | sub-control block vtable pointer |
| this | 0xE74 | RW | 0 | sub-control block state, inactive |
| this | 0xE78 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xE8C | RW | — | sub-control block vtable pointer |
| this | 0xE98 | RW | 0 | sub-control block state, inactive |
| this | 0xE9C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xEB0 | RW | — | sub-control block vtable pointer |
| this | 0xEBC | RW | 0 | sub-control block state, inactive |
| this | 0xEC0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xED4 | RW | — | sub-control block vtable pointer |
| this | 0xEE0 | RW | 0 | sub-control block state, inactive |
| this | 0xEE4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xEF8 | RW | — | sub-control block vtable pointer |
| this | 0xF04 | RW | 0 | sub-control block state, inactive |
| this | 0xF08 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xF1C | RW | — | sub-control block vtable pointer |
| this | 0xF28 | RW | 0 | sub-control block state, inactive |
| this | 0xF2C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xF40 | RW | — | sub-control block vtable pointer |
| this | 0xF4C | RW | 0 | sub-control block state, inactive |
| this | 0xF50 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xF64 | RW | — | sub-control block vtable pointer |
| this | 0xF70 | RW | 0 | sub-control block state, inactive |
| this | 0xF74 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xF88 | RW | — | sub-control block vtable pointer |
| this | 0xF94 | RW | 0 | sub-control block state, inactive |
| this | 0xF98 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xFAC | RW | — | sub-control block vtable pointer |
| this | 0xFB8 | RW | 0 | sub-control block state, inactive |
| this | 0xFBC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xFD0 | RW | — | sub-control block vtable pointer |
| this | 0xFDC | RW | 0 | sub-control block state, inactive |
| this | 0xFE0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0xFF4 | RW | — | sub-control block vtable pointer |
| this | 0x1000 | RW | 0 | sub-control block state, inactive |
| this | 0x1004 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1018 | RW | — | sub-control block vtable pointer |
| this | 0x1024 | RW | 0 | sub-control block state, inactive |
| this | 0x1028 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x103C | RW | — | sub-control block vtable pointer |
| this | 0x1048 | RW | 0 | sub-control block state, inactive |
| this | 0x104C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1060 | RW | — | sub-control block vtable pointer |
| this | 0x106C | RW | 0 | sub-control block state, inactive |
| this | 0x1070 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1084 | RW | — | sub-control block vtable pointer |
| this | 0x1090 | RW | 0 | sub-control block state, inactive |
| this | 0x1094 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x10A8 | RW | — | sub-control block vtable pointer |
| this | 0x10B4 | RW | 0 | sub-control block state, inactive |
| this | 0x10B8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x10CC | RW | — | sub-control block vtable pointer |
| this | 0x10D8 | RW | 0 | sub-control block state, inactive |
| this | 0x10DC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x10F0 | RW | — | sub-control block vtable pointer |
| this | 0x10FC | RW | 0 | sub-control block state, inactive |
| this | 0x1100 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1114 | RW | — | sub-control block vtable pointer |
| this | 0x1120 | RW | 0 | sub-control block state, inactive |
| this | 0x1124 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1138 | RW | — | sub-control block vtable pointer |
| this | 0x1144 | RW | 0 | sub-control block state, inactive |
| this | 0x1148 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x115C | RW | — | sub-control block vtable pointer |
| this | 0x1168 | RW | 0 | sub-control block state, inactive |
| this | 0x116C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1180 | RW | — | sub-control block vtable pointer |
| this | 0x118C | RW | — | sub-control block vtable pointer |
| this | 0x1198 | RW | 0 | sub-control block state, inactive |
| this | 0x119C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x11B0 | RW | — | sub-control block vtable pointer |
| this | 0x11BC | RW | 0 | sub-control block state, inactive |
| this | 0x11C0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x11D4 | RW | — | sub-control block vtable pointer |
| this | 0x11E0 | RW | 0 | sub-control block state, inactive |
| this | 0x11E4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x11F8 | RW | — | sub-control block vtable pointer |
| this | 0x1204 | RW | 0 | sub-control block state, inactive |
| this | 0x1208 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x121C | RW | — | sub-control block vtable pointer |
| this | 0x1228 | RW | 0 | sub-control block state, inactive |
| this | 0x122C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1240 | RW | — | sub-control block vtable pointer |
| this | 0x124C | RW | 0 | sub-control block state, inactive |
| this | 0x1250 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1264 | RW | — | sub-control block vtable pointer |
| this | 0x1270 | RW | 0 | sub-control block state, inactive |
| this | 0x1274 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x127C | RW | — | sub-control block vtable pointer |
| this | 0x1288 | RW | 0 | sub-control block state, inactive |
| this | 0x128C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1294 | RW | — | sub-control block vtable pointer |
| this | 0x12A0 | RW | 0 | sub-control block state, inactive |
| this | 0x12A4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x12B8 | RW | — | sub-control block vtable pointer |
| this | 0x12C4 | RW | 0 | sub-control block state, inactive |
| this | 0x12C8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x12DC | RW | — | sub-control block vtable pointer |
| this | 0x12E8 | RW | 0 | sub-control block state, inactive |
| this | 0x12EC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1300 | RW | — | sub-control block vtable pointer |
| this | 0x130C | RW | 0 | sub-control block state, inactive |
| this | 0x1310 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1324 | RW | — | sub-control block vtable pointer |
| this | 0x1330 | RW | 0 | sub-control block state, inactive |
| this | 0x1334 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1348 | RW | — | sub-control block vtable pointer |
| this | 0x1354 | RW | 0 | sub-control block state, inactive |
| this | 0x1358 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x136C | RW | — | sub-control block vtable pointer |
| this | 0x1378 | RW | 0 | sub-control block state, inactive |
| this | 0x137C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1390 | RW | — | sub-control block vtable pointer |
| this | 0x139C | RW | 0 | sub-control block state, inactive |
| this | 0x13A0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x13B4 | RW | — | sub-control block vtable pointer |
| this | 0x13C0 | RW | 0 | sub-control block state, inactive |
| this | 0x13C4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x13D8 | RW | — | sub-control block vtable pointer |
| this | 0x13E4 | RW | 0 | sub-control block state, inactive |
| this | 0x13E8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x13FC | RW | — | sub-control block vtable pointer |
| this | 0x1408 | RW | 0 | sub-control block state, inactive |
| this | 0x140C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1420 | RW | — | sub-control block vtable pointer |
| this | 0x142C | RW | 0 | sub-control block state, inactive |
| this | 0x1430 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1444 | RW | — | sub-control block vtable pointer |
| this | 0x1450 | RW | 0 | sub-control block state, inactive |
| this | 0x1454 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1468 | RW | — | sub-control block vtable pointer |
| this | 0x1474 | RW | 0 | sub-control block state, inactive |
| this | 0x1478 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x148C | RW | — | sub-control block vtable pointer |
| this | 0x1498 | RW | 0 | sub-control block state, inactive |
| this | 0x149C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x14A4 | RW | — | sub-control block vtable pointer |
| this | 0x14B0 | RW | 0 | sub-control block state, inactive |
| this | 0x14B4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x14C8 | RW | — | sub-control block vtable pointer |
| this | 0x14D4 | RW | 0 | sub-control block state, inactive |
| this | 0x14D8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x14EC | RW | — | sub-control block vtable pointer |
| this | 0x14F8 | RW | 0 | sub-control block state, inactive |
| this | 0x14FC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1510 | RW | — | sub-control block vtable pointer |
| this | 0x151C | RW | 0 | sub-control block state, inactive |
| this | 0x1520 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1528 | RW | — | sub-control block vtable pointer |
| this | 0x1534 | RW | 0 | sub-control block state, inactive |
| this | 0x1538 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1540 | RW | — | sub-control block vtable pointer |
| this | 0x154C | RW | 0 | sub-control block state, inactive |
| this | 0x1550 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1558 | RW | — | sub-control block vtable pointer |
| this | 0x1564 | RW | 0 | sub-control block state, inactive |
| this | 0x1568 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x157C | RW | — | sub-control block vtable pointer |
| this | 0x1588 | RW | 0 | sub-control block state, inactive |
| this | 0x158C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x15A0 | RW | — | sub-control block vtable pointer |
| this | 0x15AC | RW | 0 | sub-control block state, inactive |
| this | 0x15B0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x15C4 | RW | — | sub-control block vtable pointer |
| this | 0x15D0 | RW | 0 | sub-control block state, inactive |
| this | 0x15D4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x15E8 | RW | — | sub-control block vtable pointer |
| this | 0x15F4 | RW | 0 | sub-control block state, inactive |
| this | 0x15F8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x160C | RW | — | sub-control block vtable pointer |
| this | 0x1618 | RW | 0 | sub-control block state, inactive |
| this | 0x161C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1630 | RW | — | sub-control block vtable pointer |
| this | 0x163C | RW | 0 | sub-control block state, inactive |
| this | 0x1640 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1654 | RW | — | sub-control block vtable pointer |
| this | 0x1660 | RW | 0 | sub-control block state, inactive |
| this | 0x1664 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1678 | RW | — | sub-control block vtable pointer |
| this | 0x1684 | RW | 0 | sub-control block state, inactive |
| this | 0x1688 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x169C | RW | — | sub-control block vtable pointer |
| this | 0x16A8 | RW | 0 | sub-control block state, inactive |
| this | 0x16AC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x16C0 | RW | — | sub-control block vtable pointer |
| this | 0x16CC | RW | 0 | sub-control block state, inactive |
| this | 0x16D0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x16E4 | RW | — | sub-control block vtable pointer |
| this | 0x16F0 | RW | 0 | sub-control block state, inactive |
| this | 0x16F4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1708 | RW | — | sub-control block vtable pointer |
| this | 0x1714 | RW | 0 | sub-control block state, inactive |
| this | 0x1718 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x172C | RW | — | sub-control block vtable pointer |
| this | 0x1738 | RW | 0 | sub-control block state, inactive |
| this | 0x173C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1750 | RW | — | sub-control block vtable pointer |
| this | 0x175C | RW | 0 | sub-control block state, inactive |
| this | 0x1760 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1774 | RW | — | sub-control block vtable pointer |
| this | 0x1780 | RW | 0 | sub-control block state, inactive |
| this | 0x1784 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1798 | RW | — | sub-control block vtable pointer |
| this | 0x17A4 | RW | 0 | sub-control block state, inactive |
| this | 0x17A8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x17BC | RW | — | sub-control block vtable pointer |
| this | 0x17C8 | RW | 0 | sub-control block state, inactive |
| this | 0x17CC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x17E0 | RW | — | sub-control block vtable pointer |
| this | 0x17EC | RW | 0 | sub-control block state, inactive |
| this | 0x17F0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1804 | RW | — | sub-control block vtable pointer |
| this | 0x1810 | RW | 0 | sub-control block state, inactive |
| this | 0x1814 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x181C | RW | — | sub-control block vtable pointer |
| this | 0x1828 | RW | 0 | sub-control block state, inactive |
| this | 0x182C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1840 | RW | — | sub-control block vtable pointer |
| this | 0x184C | RW | 0 | sub-control block state, inactive |
| this | 0x1850 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1864 | RW | — | sub-control block vtable pointer |
| this | 0x1870 | RW | 0 | sub-control block state, inactive |
| this | 0x1874 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1888 | RW | — | sub-control block vtable pointer |
| this | 0x1894 | RW | 0 | sub-control block state, inactive |
| this | 0x1898 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x18AC | RW | — | sub-control block vtable pointer |
| this | 0x18B8 | RW | 0 | sub-control block state, inactive |
| this | 0x18BC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x18D0 | RW | — | sub-control block vtable pointer |
| this | 0x18DC | RW | 0 | sub-control block state, inactive |
| this | 0x18E0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x18F4 | RW | — | sub-control block vtable pointer |
| this | 0x1900 | RW | 0 | sub-control block state, inactive |
| this | 0x1904 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1918 | RW | — | sub-control block vtable pointer |
| this | 0x1924 | RW | 0 | sub-control block state, inactive |
| this | 0x1928 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x193C | RW | — | sub-control block vtable pointer |
| this | 0x1948 | RW | 0 | sub-control block state, inactive |
| this | 0x194C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1960 | RW | — | sub-control block vtable pointer |
| this | 0x196C | RW | 0 | sub-control block state, inactive |
| this | 0x1970 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1974 | RW | 0 | sub-control block state, inactive |
| this | 0x1978 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x197C | RW | — | sub-control block vtable pointer |
| this | 0x1988 | RW | 0 | sub-control block state, inactive |
| this | 0x198C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x19A0 | RW | — | sub-control block vtable pointer |
| this | 0x19AC | RW | 0 | sub-control block state, inactive |
| this | 0x19B0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x19C4 | RW | — | sub-control block vtable pointer |
| this | 0x19D0 | RW | 0 | sub-control block state, inactive |
| this | 0x19D4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x19DC | RW | — | sub-control block vtable pointer |
| this | 0x19E8 | RW | 0 | sub-control block state, inactive |
| this | 0x19EC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x19F4 | RW | — | sub-control block vtable pointer |
| this | 0x1A00 | RW | 0 | sub-control block state, inactive |
| this | 0x1A04 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1A18 | RW | — | sub-control block vtable pointer |
| this | 0x1A24 | RW | 0 | sub-control block state, inactive |
| this | 0x1A28 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1A3C | RW | — | sub-control block vtable pointer |
| this | 0x1A48 | RW | 0 | sub-control block state, inactive |
| this | 0x1A4C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1A54 | RW | — | sub-control block vtable pointer |
| this | 0x1A60 | RW | — | sub-control block vtable pointer |
| this | 0x1A6C | RW | 0 | sub-control block state, inactive |
| this | 0x1A70 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1A84 | RW | — | sub-control block vtable pointer |
| this | 0x1A90 | RW | 0 | sub-control block state, inactive |
| this | 0x1A94 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1A9C | RW | — | sub-control block vtable pointer |
| this | 0x1AA8 | RW | 0 | sub-control block state, inactive |
| this | 0x1AAC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1AB4 | RW | — | sub-control block vtable pointer |
| this | 0x1AC0 | RW | 0 | sub-control block state, inactive |
| this | 0x1AC4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1AD8 | RW | — | sub-control block vtable pointer |
| this | 0x1AE4 | RW | 0 | sub-control block state, inactive |
| this | 0x1AE8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1AFC | RW | — | sub-control block vtable pointer |
| this | 0x1B08 | RW | 0 | sub-control block state, inactive |
| this | 0x1B0C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1B20 | RW | — | sub-control block vtable pointer |
| this | 0x1B2C | RW | 0 | sub-control block state, inactive |
| this | 0x1B30 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1B44 | RW | — | sub-control block vtable pointer |
| this | 0x1B50 | RW | 0 | sub-control block state, inactive |
| this | 0x1B54 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1B68 | RW | — | sub-control block vtable pointer |
| this | 0x1B74 | RW | 0 | sub-control block state, inactive |
| this | 0x1B78 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1B8C | RW | — | sub-control block vtable pointer |
| this | 0x1B98 | RW | 0 | sub-control block state, inactive |
| this | 0x1B9C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1BB0 | RW | — | sub-control block vtable pointer |
| this | 0x1BBC | RW | 0 | sub-control block state, inactive |
| this | 0x1BC0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1BD4 | RW | — | sub-control block vtable pointer |
| this | 0x1BE0 | RW | 0 | sub-control block state, inactive |
| this | 0x1BE4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1BF8 | RW | — | sub-control block vtable pointer |
| this | 0x1C04 | RW | 0 | sub-control block state, inactive |
| this | 0x1C08 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1C1C | RW | — | sub-control block vtable pointer |
| this | 0x1C28 | RW | 0 | sub-control block state, inactive |
| this | 0x1C2C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1C40 | RW | — | sub-control block vtable pointer |
| this | 0x1C4C | RW | 0 | sub-control block state, inactive |
| this | 0x1C50 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1C64 | RW | — | sub-control block vtable pointer |
| this | 0x1C70 | RW | 0 | sub-control block state, inactive |
| this | 0x1C74 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1C88 | RW | — | sub-control block vtable pointer |
| this | 0x1C94 | RW | 0 | sub-control block state, inactive |
| this | 0x1C98 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1CAC | RW | — | sub-control block vtable pointer |
| this | 0x1CB8 | RW | 0 | sub-control block state, inactive |
| this | 0x1CBC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1CD0 | RW | — | sub-control block vtable pointer |
| this | 0x1CDC | RW | 0 | sub-control block state, inactive |
| this | 0x1CE0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1CF4 | RW | — | sub-control block vtable pointer |
| this | 0x1D00 | RW | 0 | sub-control block state, inactive |
| this | 0x1D04 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1D18 | RW | — | sub-control block vtable pointer |
| this | 0x1D24 | RW | 0 | sub-control block state, inactive |
| this | 0x1D28 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1D3C | RW | — | sub-control block vtable pointer |
| this | 0x1D48 | RW | 0 | sub-control block state, inactive |
| this | 0x1D4C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1D60 | RW | — | sub-control block vtable pointer |
| this | 0x1D6C | RW | 0 | sub-control block state, inactive |
| this | 0x1D70 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1D84 | RW | — | sub-control block vtable pointer |
| this | 0x1D90 | RW | 0 | sub-control block state, inactive |
| this | 0x1D94 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1DA8 | RW | — | sub-control block vtable pointer |
| this | 0x1DB4 | RW | 0 | sub-control block state, inactive |
| this | 0x1DB8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1DCC | RW | — | sub-control block vtable pointer |
| this | 0x1DD8 | RW | 0 | sub-control block state, inactive |
| this | 0x1DDC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1DF0 | RW | — | sub-control block vtable pointer |
| this | 0x1DFC | RW | 0 | sub-control block state, inactive |
| this | 0x1E00 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1E14 | RW | — | sub-control block vtable pointer |
| this | 0x1E20 | RW | 0 | sub-control block state, inactive |
| this | 0x1E24 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1E38 | RW | — | sub-control block vtable pointer |
| this | 0x1E44 | RW | 0 | sub-control block state, inactive |
| this | 0x1E48 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1E5C | RW | — | sub-control block vtable pointer |
| this | 0x1E68 | RW | 0 | sub-control block state, inactive |
| this | 0x1E6C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1E80 | RW | — | sub-control block vtable pointer |
| this | 0x1E8C | RW | 0 | sub-control block state, inactive |
| this | 0x1E90 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1EA4 | RW | — | sub-control block vtable pointer |
| this | 0x1EB0 | RW | 0 | sub-control block state, inactive |
| this | 0x1EB4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1EC8 | RW | — | sub-control block vtable pointer |
| this | 0x1ED4 | RW | 0 | sub-control block state, inactive |
| this | 0x1ED8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1EEC | RW | — | sub-control block vtable pointer |
| this | 0x1EF8 | RW | 0 | sub-control block state, inactive |
| this | 0x1EFC | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1F10 | RW | — | sub-control block vtable pointer |
| this | 0x1F1C | RW | 0 | sub-control block state, inactive |
| this | 0x1F20 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1F34 | RW | — | sub-control block vtable pointer |
| this | 0x1F40 | RW | 0 | sub-control block state, inactive |
| this | 0x1F44 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1F4C | RW | — | sub-control block vtable pointer |
| this | 0x1F58 | RW | 0 | sub-control block state, inactive |
| this | 0x1F5C | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1F64 | RW | — | sub-control block vtable pointer |
| this | 0x1F70 | RW | 0 | sub-control block state, inactive |
| this | 0x1F74 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1F88 | RW | — | sub-control block vtable pointer |
| this | 0x1F94 | RW | 0 | sub-control block state, inactive |
| this | 0x1F98 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1F9C | RW | 0 | sub-control block state field, inactive |
| this | 0x1FA0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1FA4 | RW | — | sub-control block vtable pointer |
| this | 0x1FB0 | RW | 0 | sub-control block state, inactive |
| this | 0x1FB4 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1FC8 | RW | — | sub-control block vtable pointer |
| this | 0x1FD4 | RW | 0 | sub-control block state, inactive |
| this | 0x1FD8 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x1FE0 | RW | — | sub-control block vtable pointer |
| this | 0x1FEC | RW | 0 | sub-control block state, inactive |
| this | 0x1FF0 | RW | 18446744073709551615 | sub-control block target sentinel (no target) |
| this | 0x49A8 | RW | 0 | final zero-init area (dword) |
| this | 0x49A9 | RW | 0 | final zero-init area (byte) |
| this | 0x49B0 | RW | 0 | player options reference (set by PlayerOptionsInitializer) |

**Written-by note (persistence):**
- All fields: once (init-only during construction; no conditional guards; external writes survive until next init call)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004a8af0 | VTableInitWithDefaults | R | init function: sets up struct with vtable and default values |
| 004a8b50 | sub_4A8B50 | R | init function: specialized struct init with 28-byte stride |
| 004b1950 | SmallStructConstructor | R | init function: constructs a small struct (36-byte stride) |
| 004b1990 | VTableFieldsInit | R | init function: initializes vtable + fields in a struct |
| 005acb6c | off_5ACB6C | R | ScreenEffectVTable [DERIVED] |
| 005acb78 | off_5ACB78 | R | Unknown_VTable_5ACB78 [DERIVED] |
| 005acb84 | off_5ACB84 | R | ControlBindingVTable [DERIVED] |
| 005acb90 | off_5ACB90 | R | PTR_VTable_FUN004A70E0 [DERIVED] |
| 005acb9c | off_5ACB9C | R | VTablePtr_5ACB9C [DERIVED] |
| 005acba8 | off_5ACBA8 | R | SoundManagerVTable [DERIVED] |
| 005acbb4 | off_5ACBB4 | R | WidgetVTableRef [DERIVED] |
| 005acbc0 | off_5ACBC0 | R | VTableRef_5ACBC0 [DERIVED] |
| 005acbcc | off_5ACBCC | R | VTable_UIElement_ACBCC [DERIVED] |
| 005acbd8 | off_5ACBD8 | R | UITextureVTable [DERIVED] |
| 005acbe4 | off_5ACBE4 | R | PTR_LABEL_5ACBE4 [DERIVED] |
| 005acbf0 | off_5ACBF0 | R | VTable_VideoPlayback_5ACBF0 [DERIVED] |
| 005acbfc | off_5ACBFC | R | UIWidgetVTableSlot [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401000 | sub_401000 | batch-init: calls a constructor function N times over a stride-length array of sub-objects |
| 004a8af0 | VTableInitWithDefaults | initializes a sub-struct by setting vtable pointer and default field values |
| 004a8b10 | InitWithSentinelValues | sets up sentinel/default values in a struct block before specific field overrides |
| 004a8b30 | ShortConstructor | lightweight initializer for a small struct |
| 004aa270 | PlayerOptionsInitializer | initializes player-specific options and settings within the UI window |
| 004b1950 | SmallStructConstructor | initializes a 36-byte small sub-struct to clean state |
| 004b1970 | SmallStructInitWithVtable | initializes a 24-byte struct with vtable pointer |
| 004b1990 | VTableFieldsInit | initializes vtable pointer and zeroes fields in a struct |
| 004b19b0 | VTablePatternedFieldInit | vtable-patterned initializer for a sub-control struct |
| 004b19d0 | sub_4B19D0 | variant struct initializer (36-byte stride loop) |
| 004b19f0 | ShortComputation_19f0 | quick computation/init helper for a sub-control field |
| 004b1a10 | FunctionCallWrapper_1a10 | dispatch wrapper calling a sub-init function |
| 004b1a30 | VTableInitWithDefaults_1a30 | alternate vtable init with defaults (7-byte stride variant) |
| 004b1a50 | InitWithSentinelPattern | initializes struct with sentinel value pattern |
| 004b1a70 | ShortConstructor_1a70 | lightweight struct constructor variant |
| 004b1a90 | StructInitWithVTableSentinels | initializes struct with both vtable pointer and sentinel guard values |
| 004c16b0 | LargeStructZeroInit_16b0 | zeroes a large struct region (bulk zero-init) |

**Guard conditions:** none — this is a pure initialization function with no conditional branches on input; all writes execute unconditionally.
