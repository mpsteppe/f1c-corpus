// Function: FUN_0055d720 @ 0055d720
// Size (bytes): 466


void __thiscall FUN_0055d720(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_005414f0();
  uVar2 = param_1[0xe];
  if (iVar1 == 0) {
    if (((uVar2 & 0x100) != 0) && ((uVar2 & 0x400) == 0)) {
      return;
    }
    param_1[0xe] = uVar2 & 0xfffffbff | 0x100;
    if (*(int *)(param_1[6] + 0x13c) != 0) {
      return;
    }
    if (param_3 != 0) {
      uVar2 = FUN_00540f00(param_1[7],0xa0,param_1[0xb],param_1[2]);
      param_1[8] = uVar2;
    }
    puVar3 = (undefined4 *)param_1[8];
    puVar4 = (undefined4 *)param_1[3];
    uVar2 = param_1[2];
    if ((param_1[0xe] & 0x800) == 0) {
      if (0 < (int)uVar2) {
        do {
          *puVar3 = *puVar4;
          puVar3[1] = puVar4[1];
          puVar3[2] = puVar4[2];
          puVar3 = puVar3 + 0x10;
          puVar4 = puVar4 + 0xc;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
    }
    else if (0 < (int)uVar2) {
      do {
        *puVar3 = *puVar4;
        puVar3[1] = puVar4[1];
        puVar3[2] = puVar4[2];
        puVar3[8] = puVar4[8];
        puVar3[9] = puVar4[9];
        puVar3 = puVar3 + 0x10;
        puVar4 = puVar4 + 0xc;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((*param_1 & 2) == 0) {
      if ((*param_1 & 1) == 0) {
        FUN_0055d900(param_2);
      }
      else {
        FUN_0055da50(param_2);
      }
    }
    else {
      FUN_0055e320(param_2);
    }
    if ((*(uint *)(param_1[6] + 0x14) & 0x400000) != 0) {
      FUN_0055eb30();
    }
  }
  else {
    if ((uVar2 & 0x100) != 0) {
      return;
    }
    param_1[0xe] = uVar2 | 0x100;
    if (((uVar2 & 0x200) != 0) && (-1 < *(char *)(param_1[1] + 0x9c))) {
      return;
    }
    if (param_3 != 0) {
      uVar2 = FUN_00540f00(param_1[7],0xa0,param_1[0xb],param_1[2]);
      param_1[8] = uVar2;
    }
    if ((param_1[0xe] & 0x200) == 0) {
      uVar2 = param_1[2];
      puVar3 = (undefined4 *)param_1[8];
      puVar4 = (undefined4 *)param_1[3];
      if (0 < (int)uVar2) {
        do {
          *puVar3 = *puVar4;
          puVar3[1] = puVar4[1];
          puVar3[2] = puVar4[2];
          puVar3 = puVar3 + 0x10;
          puVar4 = puVar4 + 0xc;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      param_1[0xe] = param_1[0xe] | 0x200;
    }
    if (*(char *)(param_1[1] + 0x9c) < '\0') {
      FUN_0055eba0(param_2);
    }
  }
  if (param_3 != 0) {
    FUN_00540f90(param_1[7]);
  }
  return;
}


