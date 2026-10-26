// Function: FUN_004b0ef0 @ 004b0ef0
// Size (bytes): 669


undefined4 __thiscall FUN_004b0ef0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 < 1) || (6 < param_2)) {
    return 0;
  }
  *(int *)(param_1 + 0x1f78) = param_2;
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x1f84));
  *(undefined4 *)(param_1 + 0x5c4) = *(undefined4 *)(param_1 + (param_2 * 9 + 0x171) * 4);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x5d0));
  iVar1 = param_1 + param_2 * 0x24;
  *(undefined4 *)(param_1 + 0x7f8) = *(undefined4 *)(param_1 + 0x7f8 + param_2 * 0x24);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x804));
  *(undefined4 *)(param_1 + 0x8f4) = *(undefined4 *)(iVar1 + 0x8f4);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x900));
  *(undefined4 *)(param_1 + 0x9f0) = *(undefined4 *)(iVar1 + 0x9f0);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x9fc));
  *(undefined4 *)(param_1 + 0xaec) = *(undefined4 *)(iVar1 + 0xaec);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0xaf8));
  *(undefined4 *)(param_1 + 0xbe8) = *(undefined4 *)(iVar1 + 0xbe8);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0xbf4));
  *(undefined1 *)(param_1 + 0xce4) = *(undefined1 *)(param_1 + 0xce4 + param_2 * 0x18);
  FUN_00464720(*(undefined1 *)(param_1 + 0xce7));
  *(undefined4 *)(param_1 + 0x200c) = *(undefined4 *)(iVar1 + 0x200c);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2018));
  *(undefined4 *)(param_1 + 0x2108) = *(undefined4 *)(iVar1 + 0x2108);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2114));
  *(undefined4 *)(param_1 + 0x2204) = *(undefined4 *)(iVar1 + 0x2204);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2210));
  *(undefined4 *)(param_1 + 0x2300) = *(undefined4 *)(iVar1 + 0x2300);
  FUN_004646c0(*(undefined4 *)(param_1 + 0x2308),*(undefined4 *)(param_1 + 0x230c));
  *(undefined4 *)(param_1 + 0x24f8) = *(undefined4 *)(iVar1 + 0x24f8);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2504));
  *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(iVar1 + 0x26cc);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x26d8));
  *(undefined4 *)(param_1 + 0x27c8) = *(undefined4 *)(iVar1 + 0x27c8);
  if (*(int *)(param_1 + 0x27c8) < *(int *)(param_1 + 0x27d0)) {
    *(int *)(param_1 + 0x27c8) = *(int *)(param_1 + 0x27d0);
  }
  else if (*(int *)(param_1 + 0x27d4) < *(int *)(param_1 + 0x27c8)) {
    *(int *)(param_1 + 0x27c8) = *(int *)(param_1 + 0x27d4);
  }
  iVar1 = *(int *)(iVar1 + 0x23fc);
  *(int *)(param_1 + 0x23fc) = iVar1;
  if (iVar1 < *(int *)(param_1 + 0x2404)) {
    *(int *)(param_1 + 0x23fc) = *(int *)(param_1 + 0x2404);
  }
  else if (*(int *)(param_1 + 0x2408) < iVar1) {
    *(int *)(param_1 + 0x23fc) = *(int *)(param_1 + 0x2408);
  }
  if (param_2 == 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x1c60);
    *(undefined4 *)(param_1 + 0x1c54) = 1;
  }
  else {
    if (param_2 != 2) goto LAB_004b1173;
    uVar2 = *(undefined4 *)(param_1 + 0x1c60);
    *(undefined4 *)(param_1 + 0x1c54) = 7;
  }
  FUN_0047f1f0(uVar2);
LAB_004b1173:
  FUN_004b1190(0xbf800000);
  return 1;
}


