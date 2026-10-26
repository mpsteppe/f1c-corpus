// Function: FUN_00550080 @ 00550080
// Size (bytes): 570


undefined4 __thiscall FUN_00550080(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  FUN_0054fe50(param_2);
  iVar1 = FUN_005427d0(param_2,&local_4,&local_8,0);
  if (iVar1 == -1) {
    FUN_005502c0();
    return 0xffffffff;
  }
  log2((float10)local_4);
  iVar2 = __ftol();
  log2((float10)local_8);
  iVar3 = __ftol();
  iVar1 = *(int *)(param_1 + 0x50);
  if (((iVar1 == 0) || (iVar2 < iVar1)) || (iVar3 < iVar1)) {
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
    *(int *)(param_1 + 0x50) = iVar3;
  }
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    uVar4 = FUN_0055bfc0();
    iVar1 = FUN_0053d890(uVar4);
    if (iVar1 != 0) {
      while ((*(int *)(iVar1 + 0x11c) < local_4 || (*(int *)(iVar1 + 0x120) < local_8))) {
        local_4 = local_4 >> 1;
        local_8 = local_8 >> 1;
        iVar5 = iVar5 + 1;
        if (1 < *(int *)(param_1 + 0x50)) {
          *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
        }
      }
      if (iVar5 != 0) goto LAB_0055018d;
    }
    if (((*(byte *)(param_1 + 0x44) & 1) == 0) && (DAT_008b8e4c != 0)) {
      iVar1 = *(int *)(param_1 + 0x50);
      iVar5 = DAT_008b8e4c;
      do {
        local_4 = local_4 >> 1;
        local_8 = local_8 >> 1;
        if (1 < iVar1) {
          iVar1 = iVar1 + -1;
        }
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      *(int *)(param_1 + 0x50) = iVar1;
    }
  }
LAB_0055018d:
  if ((param_4 & 0x800000) != 0) {
    uVar4 = 8;
    goto LAB_00550240;
  }
  if ((DAT_008b8e2c == 0) || (iVar1 = FUN_0055c9a0(), iVar1 == 0)) {
    if ((param_4 & 0x800) != 0) {
      uVar4 = 5;
      goto LAB_00550240;
    }
    if ((param_4 & 0x40000) != 0) {
      uVar4 = FUN_0055c7f0(0x200000);
      goto LAB_00550240;
    }
  }
  else {
    if ((((*(byte *)(param_1 + 0x44) & 1) == 0) && (7 < local_4)) && (7 < local_8)) {
      uVar4 = 9;
      goto LAB_00550240;
    }
    if ((param_4 & 0x800) != 0) {
      uVar4 = 5;
      goto LAB_00550240;
    }
    if ((param_4 & 0x40000) != 0) {
      uVar4 = FUN_0055c7f0(0x200000);
      goto LAB_00550240;
    }
  }
  uVar4 = FUN_0055c3c0(DAT_008b8dc8);
LAB_00550240:
  if ((param_4 & 0x800) != 0) {
    if (param_3 == 0) {
      param_3 = 0xff00ff;
    }
    FUN_005435c0(param_3);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2c) = *(undefined4 *)(param_1 + 0x50);
  if (DAT_008b8e28 == 0) {
    param_4 = param_4 | 0x1000000;
  }
  iVar1 = FUN_005429b0(param_2,local_4,local_8,uVar4,param_4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2c);
    return 0;
  }
  FUN_005502c0();
  return 0xffffffff;
}


