# Cross-Validation Results: docs/20-math-utilities.md vs Source

## FUN_004B32A0 — FAIL

**Doc claim:** R = (*p1<<8)*DAT_0059e780; G = composite*same; B = composite*same; sub-function calls

**Source observation:**
- R extraction: `local_18 = (float)(*param_1 << 8) * _DAT_0059e780;` — correct
- G extraction: `local_14 = (float)(int)((*(ushort *)((int)param_1 + 2) & 0xff00) + param_1[1] * 0x10000) * _DAT_0059e780;` — doc oversimplified, actually masks/shifts packed values from ushort + int
- B extraction: `local_10 = (float)(int)(((uint)param_1[1] >> 8 & 0xffff00) + (uint)*(byte *)(param_1 + 2) * 0x1000000) * _DAT_0059e780;` — same, more complex than "composite*same"
- **Missing 8 called sub-functions:** FUN_004b2480, FUN_004b25d0, FUN_004b2750, FUN_004b2310, FUN_004b2bf0, FUN_004b29b0, FUN_004b2c50, FUN_004b2930. Doc says "sub-function calls" but lists none.
- Also writes `*(undefined4 *)(param_2 + 4) = param_3` — not documented.

**Corrections needed:**
1. Expand G/B extraction detail — not simple composite multiply, involves masking/shifting packed R5G5B5 or similar format
2. List all 8 called sub-functions (likely color space conversion helpers)
3. Document final write to `param_2 + 4` with param_3

## FUN_004F1A60 — PASS

**Doc claim:** Loops 4× calling FUN_004f18c0(i, param_1, 0); if param_2 calls FUN_004e8010(0)

**Source observation:**
```c
iVar1 = 0;
do {
  FUN_004f18c0(iVar1, param_1, 0);
  iVar1 = iVar1 + 1;
} while (iVar1 < 4);
if (param_2 != '\0') {
  FUN_004e8010(0);
}
```
- Loop count 4: correct
- FUN_004f18c0 args: correct (iVar1 as i, param_1, 0)
- Conditional call on param_2 != 0: correct
- FUN_004e8010(0): correct

**No corrections needed.**

## FUN_0052E550 — PASS

**Doc claim:** If -1 < param_2 < 9: param_1[param_2] = param_3

**Source observation:**
```c
if ((-1 < param_2) && (param_2 < 9)) {
  *(undefined1 *)(param_2 + param_1) = param_3;
}
```
- Bounds check: correct (-1 < param_2 && param_2 < 9, 9-element array)
- Byte write: correct
- Function is `__thiscall` (param_1 = this pointer) — doc omits but logic matches

**No corrections needed.**

## FUN_005862C0 — PASS (minor notes)

**Doc claim:** CloseHandle existing at +0x50 if active; CreateMutexA(inherit=TRUE); store at +0x50; set flag at +0x58

**Source observation:**
```c
if (*(char *)(param_1 + 0x58) != '\0') {
  BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x50));
  if (BVar1 != 0) { *(undefined4 *)(param_1 + 0x50) = 0; }
}
local_c.nLength = 0xc; local_c.lpSecurityDescriptor = 0; local_c.bInheritHandle = 1;
pvVar2 = CreateMutexA(&local_c, 0, 0);
*(HANDLE *)(param_1 + 0x50) = pvVar2;
if (pvVar2 != 0) { *(undefined1 *)(param_1 + 0x58) = 1; }
return *(undefined1 *)(param_1 + 0x58);
```
- CloseHandle condition: doc says "existing at +0x50 if active" — source checks flag at +0x58 first, not handle directly. Minor imprecision.
- CreateMutexA with SECURITY_ATTRIBUTES (bInheritHandle=1): correct
- Store at +0x50: correct
- Flag at +0x58 set on success: correct
- **Return value not documented** — returns flag byte at +0x58 after creation

**Minor corrections:**
1. More precise: "if flag at +0x58 is set, CloseHandle existing handle at +0x50"
2. Document return value (flag at +0x58 indicating success)

## FUN_0058F6C7 — PASS

**Doc claim:** In-place conversion of digit chars ('0'-'9') to numeric values (0-9), stripping semicolons (';') from a string.

**Source observation:**
```c
cVar2 = *param_1;
do {
  if (cVar2 == '\0') { return; }
  if ((cVar2 < '0') || ('9' < cVar2)) {
    if (cVar2 != ';') { param_1++; }
    else {
      do {
        *pcVar3 = pcVar3[1];
        pcVar3++;
      } while (*pcVar3 != '\0');
    }
  } else {
    *param_1 = cVar2 + -0x30;
    param_1++;
  }
  cVar2 = *param_1;
} while (true);
```
- Null terminator check: correct
- Digit conversion (`cVar2 + -0x30` to 0-9): correct
- Semicolon stripping via left-shift of remaining chars: correct
- Non-digit/non-semicolon chars advanced past unchanged: correct

**No corrections needed for documented behavior.**

## FUN_004562A0 — PASS

**Doc claim:** Sets `*param_1 = &PTR_FUN_0059efcc` (vtable); if `param_1[1] != 0` calls FUN_00587bcf(param_1[1]) (free sub-object)

**Source observation:**
```c
*param_1 = &PTR_FUN_0059efcc;
if (param_1[1] != 0) {
  FUN_00587bcf(param_1[1]);
}
```
- Vtable assignment: correct
- Conditional free on param_1[1] != 0: correct
- FUN_00587bcf call: correct

**No corrections needed.**

## FUN_0047A8F0 — PASS

**Doc claim:** Constructor with float init (0.05f, 1.0f), vtable assignment `&PTR_FUN_005a6628`

**Source observation:**
```c
FUN_004668e0(0x3d4ccccd, 0x3f800000);
*param_1 = &PTR_FUN_005a6628;
return param_1;
```
- 0x3d4ccccd = 0.05f: correct
- 0x3f800000 = 1.0f: correct
- Vtable `&PTR_FUN_005a6628`: correct
- Returns param_1 (fluent constructor) — doc omits return but not critical

**No corrections needed.**

## FUN_0049BAD0 — PASS

**Doc claim:** Reads float from vehicle struct via FUN_004f0050(); passes to FUN_004d1cf0; if !=2 calls FUN_004d1d40; if !=2 returns 0; else returns 1

**Source observation:**
```c
fVar2 = (float10)FUN_004f0050();
iVar1 = FUN_004d1cf0((float)fVar2);
if (iVar1 != 2) {
  iVar1 = FUN_004d1d40((float)fVar2);
  if (iVar1 != 2) { return 0; }
}
return 1;
```
- FUN_004f0050() returns float: correct
- FUN_004d1cf0(result) routing: correct
- If != 2, FUN_004d1d40(result): correct
- Returns 0 if both != 2, else 1: correct
- Function takes no params (void) — doc implies param_1 but logic still matches

**No corrections needed.**

## FUN_004C9960 — PASS

**Doc claim:** If *(param_1 + 0x1c) != 0: calls first virtual method with arg 1, then sets pointer to 0

**Source observation:**
```c
if (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0) {
  (**(code **)**(undefined4 **)(param_1 + 0x1c))(1);
  *(undefined4 *)(param_1 + 0x1c) = 0;
}
```
- Check pointer at +0x1c for non-null: correct
- Dereference twice (vtable[0]) and call with arg 1: correct (virtual destructor pattern)
- Clear pointer after call: correct

**No corrections needed.**

## FUN_0050FF84 — PASS (vague but labeled low confidence)

**Doc claim:** Uses unaff_ESI (this pointer); sets timer +0x14 = 0x65 or 0x3c based on flag; virtual calls at +0x04 and +0x00; loop initializes byte fields around +0xda; sets various zero/one flags

**Source observation:**
```c
*(undefined4 *)(*unaff_ESI + 0x14) = 0x65;           // timer = 101
(**(code **)(*unaff_ESI + 4))();                      // virtual at +0x04
if (*(char *)(unaff_ESI[100] + 0x50) != '\0') {
  *(undefined4 *)(*unaff_ESI + 0x14) = 0x3c;         // timer = 60
  (**(code **)*unaff_ESI)();                          // virtual at +0x00
}
puVar1 = (undefined1 *)((int)unaff_ESI + 0xda);      // base for loop
iVar2 = 0x10;
do {                                                   // 16 iterations
  puVar1[-0x10] = 0;  *puVar1 = 1;  puVar1[0x10] = 5;
  puVar1++;
} while (iVar2 != 0);
unaff_ESI[0x3f] = 0;  unaff_ESI[9] = 0;               // various zero/one flags
*(undefined1 *)(unaff_ESI + 0x42) = 0;
*(undefined1 *)(unaff_ESI + 0x40) = 0;
```
- unaff_ESI register use: correct (no declared params, uses register var)
- Timer at +0x14: sets to 0x65 always, then conditionally to 0x3c — doc correct
- Virtual calls at +0x04 and +0x00: correct
- Loop from offset 0xca to 0xea (around 0xda): correct
- Various zero/one flags: correct
- Labeled "Unidentified Logic" and "Confidence: low" — appropriate given incomplete understanding

**No corrections needed given confidence level.**
