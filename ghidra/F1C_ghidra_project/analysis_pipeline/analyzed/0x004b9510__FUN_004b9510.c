// Function: FUN_004b9510 @ 004b9510
// Size (bytes): 610


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b9510(int param_1,float param_2,float param_3,char param_4)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  float *pfVar4;
  int iVar5;
  uint local_1b0 [108];
  
  if (param_2 == param_3) {
    return;
  }
  if (param_4 == '\0') {
    fVar1 = param_2;
    fVar2 = param_2 + _DAT_005acd68;
    if (param_2 + _DAT_005acd68 < param_3) goto LAB_004b958b;
  }
  else {
    fVar1 = param_3 - _DAT_005acd68;
    fVar2 = param_3;
    if (param_2 < param_3 - _DAT_005acd68) goto LAB_004b958b;
  }
  fVar1 = param_2;
  fVar2 = param_3;
LAB_004b958b:
  param_3 = fVar2;
  param_2 = fVar1;
  if ((*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) ||
     (pfVar4 = (float *)**(undefined4 **)(param_1 + 0x71c), pfVar4 == (float *)0x0)) {
    if (param_2 <=
        (*(float *)(param_1 + 0xf34) - *(float *)(param_1 + 0xf30)) + *(float *)(param_1 + 0xf30)) {
      puVar3 = *(undefined4 **)(param_1 + 0x714);
    }
    else {
      puVar3 = *(undefined4 **)(param_1 + 0x718);
    }
    *(undefined4 **)(param_1 + 0x71c) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    pfVar4 = (float *)*puVar3;
    if (pfVar4 == (float *)0x0) {
      return;
    }
  }
  if (*pfVar4 <= param_2) {
    do {
      if (*(int *)(param_1 + 0x71c) == 0) {
        return;
      }
      puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x71c) + 4);
      *(undefined4 **)(param_1 + 0x71c) = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        return;
      }
      pfVar4 = (float *)*puVar3;
      if (pfVar4 == (float *)0x0) {
        return;
      }
    } while (*pfVar4 < param_2);
  }
  else {
    do {
      if (*(int *)(param_1 + 0x71c) == 0) {
LAB_004b9643:
        puVar3 = *(undefined4 **)(param_1 + 0x714);
        *(undefined4 **)(param_1 + 0x71c) = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          return;
        }
        pfVar4 = (float *)*puVar3;
        goto LAB_004b9699;
      }
      puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x71c) + 8);
      *(undefined4 **)(param_1 + 0x71c) = puVar3;
      if ((puVar3 == (undefined4 *)0x0) || ((float *)*puVar3 == (float *)0x0)) goto LAB_004b9643;
    } while (param_2 <= *(float *)*puVar3);
    if (*(int *)(param_1 + 0x71c) != 0) {
      *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 4);
    }
    if (*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) {
      return;
    }
    pfVar4 = (float *)**(undefined4 **)(param_1 + 0x71c);
  }
LAB_004b9699:
  if (pfVar4 != (float *)0x0) {
    while (*pfVar4 < param_3 != (*pfVar4 == param_3)) {
      FUN_00566db0(pfVar4[1]);
      FUN_004b4450();
      FUN_004b44a0(param_1 + 0x6e4);
      iVar5 = 0;
      if (*(short *)(pfVar4 + 2) != 0) {
        do {
          FUN_004b4360(param_1 + 0x6e4,*pfVar4,local_1b0);
          if ((local_1b0[0] & 0xe0000000) != 0x20000000) {
            if (DAT_0083ee60 < 0x3ff) {
              DAT_0083ee60 = DAT_0083ee60 + 1;
              DAT_008aae64 = DAT_008aae64 + 0x1b0;
            }
            FUN_004b3a90(local_1b0);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)(uint)*(ushort *)(pfVar4 + 2));
      }
      if (*(int *)(param_1 + 0x71c) != 0) {
        *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) {
        return;
      }
      pfVar4 = (float *)**(undefined4 **)(param_1 + 0x71c);
      if (pfVar4 == (float *)0x0) {
        return;
      }
    }
  }
  return;
}


