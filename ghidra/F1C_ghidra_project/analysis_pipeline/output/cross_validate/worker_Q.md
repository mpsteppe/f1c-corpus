## FUN_0044A2D0 — PASS
## FUN_00494A70 — PASS
## FUN_00494900 — PASS
## FUN_0044D910 — PASS
## FUN_0044D400 — PASS
## FUN_0044CE60 — PASS
## FUN_0044E210 — PASS
## FUN_0044D580 — PASS
## FUN_0044CFE0 — PASS
## FUN_0044E390 — PASS
## FUN_0044D700 — PASS
## FUN_0044D160 — PASS
## FUN_0044E510 — PASS
## FUN_00456F70 — PASS
## FUN_0044C550 — PASS
## FUN_0044E8A0 — PASS
## FUN_0049B200 — PASS
## FUN_004BAD70 — PASS
## FUN_0059DA54 — PASS
## FUN_0045AE00 — PASS
## FUN_004423B0 — PASS
## FUN_0056EE40 — PASS
## FUN_0043BA20 — PASS
## FUN_00449ED0 — PASS
## FUN_00431390 — PASS
## FUN_00432920 — PASS
## FUN_00431930 — PASS
## FUN_00449340 — PASS
## FUN_004363D0 — PASS
## FUN_004B8090 — PASS
## FUN_005691D0 — PASS
## FUN_0050C2E3 — PASS
## FUN_004E0ED0 — PASS
## FUN_00414FE0 — PASS
## FUN_004874E0 — PASS
## FUN_0048B030 — PASS
## FUN_00497980 — PASS
## FUN_004669A0 — PASS
## FUN_0055E320 — PASS
## FUN_00507496 — PASS
## FUN_0044FCC0 — PASS
## FUN_00542200 — PASS
## FUN_00510ACC — PASS
## FUN_00530840 — PASS
## FUN_0054B570 — PASS
## FUN_00554CC0 — PASS
## FUN_0045BD10 — PASS
## FUN_004CD8D0 — PASS
## FUN_0057A5A0 — PASS
## FUN_0055CEE0 — PASS
## FUN_00488180 — PASS
## FUN_0052E170 — PASS
## FUN_00489560 — PASS
## FUN_0054FC50 — PASS

--- FAIL ENTRIES ---

## FUN_00582DC0 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_CATEGORY] Entry says "Thread synchronization — create/signal/close event kernel object" but source is a linked list destructor — iterates two linked lists, frees nodes via FUN_00587bcf, zeros head/tail/count fields.

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_00582DC0 — Linked List Destructor (Double List)
Source: unknown. Frees all nodes in two linked lists and resets list state.

**Key logic:**
- Iterates list 1 (*param_1, linked through +4), frees each node via FUN_00587bcf
- Iterates list 2 (param_1+4, linked through +4), frees each node via FUN_00587bcf
- Zeros head/tail/count fields for both lists

**Calls:** FUN_00587bcf (heap free)

**Moddability:** hardcoded

## FUN_0045C0A0 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_DESCRIPTION] Entry says "Function Call Wrapper — forwards call to another function" but source shows struct zero-initializer: zeros 6 fields at +0, +1, +4, +8, +0xc, +0x10

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_0045C0A0 — Struct Zero-Initializer
Source: unknown. Zeros 6 fields of an undefined4 struct.

**Key logic:**
- Sets *(byte *)(param_1 + 0) = 0 (byte field)
- Sets *(byte *)(param_1 + 1) = 0 (byte field)
- Sets 4 uint fields at +4, +8, +0xc, +0x10 to 0

**Calls:** none

**Moddability:** hardcoded

## FUN_005653F0 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_DESCRIPTION] Entry says "Audio thunk — forwards to BinkSoundOpen" but source shows complex string relocation at +0x198, FUN_005897ca hash lookups, DAT_005c30ac/DAT_005c32d8 comparisons — not a thunk, no BinkSoundOpen call

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_005653F0 — String Registry/Hash Lookup
Source: unknown. Copies string from param_1+0x198, performs hash/registry lookup.

**Key logic:**
- Copies string from +0x198 to local buffer
- Calls FUN_005897ca (hash/registry function)
- Compares against DAT_005c30ac and DAT_005c32d8 globals
- Returns match/status result

**Globals:**
- `DAT_005c30ac` — comparison target
- `DAT_005c32d8` — comparison target

**Calls:** FUN_005897ca (hash/registry lookup)

**Moddability:** hardcoded

--- PASS ENTRIES (139 total) ---
## FUN_005934E1 — PASS
## FUN_00582650 — PASS
## FUN_00586AA0 — PASS
## FUN_0059807B — PASS
## FUN_00552BA0 — PASS
## FUN_0057CA10 — PASS
## FUN_005572B0 — PASS
## FUN_00550AD0 — PASS
## FUN_00598CDC — PASS
## FUN_0049A5A0 — PASS
## FUN_00540DA0 — PASS
## FUN_005930E8 — PASS
## FUN_004630D0 — PASS
## FUN_0059C428 — PASS
## FUN_00499F00 — PASS
## FUN_004C7DD0 — PASS
## FUN_0050D84A — PASS
## FUN_00548A30 — PASS
## FUN_0059D2BF — PASS
## FUN_0040B630 — PASS
## FUN_0046A510 — PASS
## FUN_0048FEC0 — PASS
## FUN_004B8C40 — PASS
## FUN_004F8330 — PASS
## FUN_005355F0 — PASS
## FUN_0058BF45 — PASS
## FUN_00415060 — PASS
## FUN_0049A9C0 — PASS
## FUN_00535620 — PASS
## FUN_0055FBC0 — PASS
## FUN_00411A50 — PASS
## FUN_00471650 — PASS
## FUN_00491CF0 — PASS
## FUN_004B4800 — PASS
## FUN_004DF0A0 — PASS
## FUN_00535660 — PASS
## FUN_00591E57 — PASS
## FUN_00479850 — PASS
## FUN_004533A0 — PASS
## FUN_00491300 — PASS
## FUN_004B3C60 — PASS
## FUN_004DD3A0 — PASS
## FUN_005177B6 — PASS
## FUN_0055BFC0 — PASS
## FUN_0059C85C — PASS
## FUN_00457B00 — PASS
## FUN_0047ABB0 — PASS
## FUN_00499CE0 — PASS
## FUN_004C81F0 — PASS
## FUN_005160AD — PASS
## FUN_0058CC00 — PASS
## FUN_0059CF86 — PASS
## FUN_00421A30 — PASS
## FUN_004782C0 — PASS
## FUN_00498880 — PASS
## FUN_004BBF20 — PASS
## FUN_004F9230 — PASS
## FUN_00534AC0 — PASS
## FUN_00583A80 — PASS
## FUN_0059067E — PASS
## FUN_004A0DA0 — PASS
## FUN_0050CBB0 — PASS
## FUN_0040C520 — PASS
## FUN_00467720 — PASS
## FUN_0048E0D0 — PASS
## FUN_004B19D0 — PASS
## FUN_004D89D0 — PASS
## FUN_005123B3 — PASS
## FUN_0054EAC0 — PASS
## FUN_0059987C — PASS
## FUN_0058803F — PASS
## FUN_00546F70 — PASS
## FUN_004DFBB0 — PASS
## FUN_004C8350 — PASS
## FUN_004950C0 — PASS
## FUN_00473C40 — PASS
## FUN_00415730 — PASS
## FUN_004CA410 — PASS
## FUN_0050C134 — PASS
## FUN_005435C0 — PASS
## FUN_005998C0 — PASS
## FUN_0058DF5C — PASS
## FUN_00408210 — PASS
## FUN_0046B5E0 — PASS
## FUN_0048FC50 — PASS
## FUN_004B2580 — PASS
## FUN_004DBC90 — PASS
## FUN_00515303 — PASS
## FUN_005573A0 — PASS
## FUN_0055D2E0 — PASS
## FUN_00410B80 — PASS
## FUN_004702A0 — PASS
## FUN_00491760 — PASS
## FUN_004B4360 — PASS
## FUN_004DD6A0 — PASS
## FUN_00517E85 — PASS
## FUN_0055C9B0 — PASS
## FUN_00560F40 — PASS
## FUN_00418900 — PASS
## FUN_00473ED0 — PASS
## FUN_00495140 — PASS
## FUN_004BA830 — PASS
## FUN_004F6BC0 — PASS
## FUN_0052E060 — PASS
## FUN_0057B680 — PASS
## FUN_0059BEFD — PASS
## FUN_00466290 — PASS
## FUN_00492030 — PASS
## FUN_004B54A0 — PASS
## FUN_004ED750 — PASS
## FUN_0052179F — PASS
## FUN_0057A260 — PASS
## FUN_0059BF56 — PASS
## FUN_0049A460 — PASS
## FUN_005064BF — PASS
## FUN_00585CC0 — PASS
## FUN_004218F0 — PASS
## FUN_00587510 — PASS
## FUN_004116B0 — PASS
## FUN_00474440 — PASS
## FUN_00495300 — PASS
## FUN_004BA980 — PASS
## FUN_004F6F20 — PASS
## FUN_00529700 — PASS
## FUN_0057A590 — PASS
## FUN_00599BE5 — PASS
## FUN_00459A40 — PASS
## FUN_0047C6E0 — PASS
## FUN_00499EB0 — PASS
## FUN_004C3130 — PASS
## FUN_00503888 — PASS
## FUN_0053C5B0 — PASS
## FUN_0058BABB — PASS
## FUN_00487E10 — PASS
## FUN_004A4000 — PASS
## FUN_0059CA50 — PASS
## FUN_0059C7FC — PASS
## FUN_0059C948 — PASS
## FUN_0059C6C0 — PASS
## FUN_0050E174 — PASS
## FUN_00406130 — PASS
## FUN_00597388 — PASS
## FUN_005285F2 — PASS
## FUN_00510D60 — PASS
## FUN_00564680 — PASS
## FUN_00563DC0 — PASS
## FUN_00598684 — PASS
## FUN_00551FB0 — PASS
## FUN_005007EF — PASS


