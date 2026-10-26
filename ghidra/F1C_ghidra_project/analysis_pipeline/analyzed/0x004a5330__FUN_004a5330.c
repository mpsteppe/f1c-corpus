// Function: FUN_004a5330 @ 004a5330
// Size (bytes): 609


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a5330(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = (undefined4 *)(param_2 + 0xcb0);
  puVar6 = (undefined4 *)(param_1 + 0x58);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined1 *)(param_1 + 0x75) = 0;
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x18c4);
  puVar5 = (undefined4 *)(param_2 + 0x1270);
  puVar6 = (undefined4 *)(param_1 + 0xd8);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xec);
  *(undefined1 *)(param_1 + 0xf5) = 0;
  uVar1 = FUN_004d7880(param_2 + 0x70);
  *(undefined4 *)(param_1 + 0x158) = uVar1;
  if (((*(int *)(param_1 + 0x15c) < 0) && (4 < DAT_007c56a4)) && (DAT_007c56a4 < 8)) {
    uVar1 = *(undefined4 *)(param_2 + 0xbc4);
    iVar4 = FUN_004d7570(uVar1);
    if (*(char *)(iVar4 + 0x14) == '\0') {
      *(undefined4 *)(param_1 + 0x15c) = uVar1;
    }
  }
  FUN_004a57f0();
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  if (0 < *(int *)(param_1 + 0xa8)) {
    do {
      iVar2 = FUN_004d7570(*(undefined4 *)(param_2 + 0xbc4));
      iVar3 = FUN_004a5820(iVar4);
      if (iVar3 == iVar2) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xa8));
  }
  *(int *)(param_1 + 0xac) = iVar4;
  if (*(int *)(param_1 + 0xa8) <= iVar4) {
    *(undefined4 *)(param_1 + 0xac) = 1;
  }
  FUN_004a5660(0);
  FUN_004a56b0(0);
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_2 + 0x1884);
  *(float *)(param_1 + 0x17c) = (float)*(double *)(param_2 + 0x1994);
  if (*(double *)(param_2 + 0x1994) == _DAT_0059e430) {
    uVar1 = *(undefined4 *)(param_2 + 0x18c4);
    *(undefined4 *)(param_1 + 0x164) = 0x400;
    *(undefined4 *)(param_1 + 0x168) = uVar1;
    uVar1 = *(undefined4 *)(param_2 + 0x1904);
    *(undefined4 *)(param_1 + 0x16c) = 0x800;
    *(undefined4 *)(param_1 + 0x170) = uVar1;
    uVar1 = *(undefined4 *)(param_2 + 0x1944);
    *(undefined4 *)(param_1 + 0x174) = 0xc00;
    *(undefined4 *)(param_1 + 0x178) = uVar1;
  }
  else {
    iVar2 = __ftol();
    iVar4 = DAT_007d0374;
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_2 + 0x18c4);
    *(int *)(param_1 + 0x164) = iVar2 - iVar4;
    iVar3 = __ftol();
    iVar3 = iVar3 - DAT_007d0374;
    *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_2 + 0x1904);
    iVar3 = iVar3 + (iVar2 - iVar4);
    *(int *)(param_1 + 0x16c) = iVar3;
    uVar1 = *(undefined4 *)(param_2 + 0x1944);
    iVar4 = __ftol();
    iVar4 = iVar4 - DAT_007d0374;
    *(undefined4 *)(param_1 + 0x178) = uVar1;
    *(int *)(param_1 + 0x174) = iVar4 + iVar3;
  }
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_004a3440();
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_004a3440();
  }
  FUN_004a5600(*(undefined4 *)(param_1 + 0xc));
  return;
}


