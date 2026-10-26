// Function: FUN_00543bf0 @ 00543bf0
// Size (bytes): 940


undefined4 __fastcall FUN_00543bf0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xf8);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x1b8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1b8)) {
      FUN_00544ef0(*(undefined4 *)(iVar2 + 0x1b4));
      iVar1 = iVar2;
    }
    FUN_00544ef0(iVar1);
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x100);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x104); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x104)) {
      FUN_0054a240(*(undefined4 *)(iVar2 + 0x100));
      iVar1 = iVar2;
    }
    FUN_0054a240(iVar1);
    *(undefined4 *)(param_1 + 0x100) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x108);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      FUN_00545150(*(undefined4 *)(iVar2 + 0x48));
      iVar1 = iVar2;
    }
    FUN_00545150(iVar1);
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  if ((*(int *)(param_1 + 0x110) != 0) && (iVar1 = FUN_005487e0(), iVar1 != 0)) {
    return 0xffffffff;
  }
  FUN_00544af0();
  iVar1 = *(int *)(param_1 + 0x120);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x6c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x6c)) {
      FUN_005454a0(*(undefined4 *)(iVar2 + 0x68));
      iVar1 = iVar2;
    }
    FUN_005454a0(iVar1);
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x128);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x6c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x6c)) {
      FUN_005454a0(*(undefined4 *)(iVar2 + 0x68));
      iVar1 = iVar2;
    }
    FUN_005454a0(iVar1);
    *(undefined4 *)(param_1 + 0x128) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x130);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x6c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x6c)) {
      FUN_005454a0(*(undefined4 *)(iVar2 + 0x68));
      iVar1 = iVar2;
    }
    FUN_005454a0(iVar1);
    *(undefined4 *)(param_1 + 0x130) = 0;
  }
  if (*(int *)(param_1 + 0x1ac) != 0) {
    FUN_00560b30();
  }
  iVar1 = *(int *)(param_1 + 0x1b8);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_00557280();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x1c0);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_00557280();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x1c8);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_00557280();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x1d0);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_00557280();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x138);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x150);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  if (DAT_008b8f2c != 0) {
    FUN_005593d0();
  }
  iVar1 = *(int *)(param_1 + 0x140);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x178);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x118);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x30); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x30)) {
      FUN_005519e0(*(undefined4 *)(iVar2 + 0x2c));
      iVar1 = iVar2;
    }
    FUN_005519e0(iVar1);
    *(undefined4 *)(param_1 + 0x118) = 0;
  }
  return 0;
}


