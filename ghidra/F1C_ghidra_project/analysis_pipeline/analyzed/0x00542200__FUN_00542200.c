// Function: FUN_00542200 @ 00542200
// Size (bytes): 445


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00542200(int param_1,undefined4 param_2,undefined4 param_3,float param_4,float param_5,
            int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if (param_6 == 0) {
    fVar1 = (float)DAT_008b8dd8;
    if (param_4 < (float)_DAT_0059e420 != (param_4 == (float)_DAT_0059e420)) {
      param_4 = param_4 * (float)DAT_008b8dd4;
    }
    if (param_5 < (float)_DAT_0059e420 != (param_5 == (float)_DAT_0059e420)) {
      param_5 = fVar1 * param_5;
    }
    if (((float)DAT_008b8dd4 < param_4) || (DAT_0059e440 <= param_4)) {
      uVar4 = __ftol();
      *(undefined4 *)(param_1 + 0x54) = uVar4;
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    if (param_5 <= fVar1) goto LAB_00542230;
  }
  else {
    if (DAT_0059e440 <= param_4) {
      uVar4 = __ftol();
      *(undefined4 *)(param_1 + 0x54) = uVar4;
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
LAB_00542230:
    if (param_5 < DAT_0059e440) {
      *(undefined4 *)(param_1 + 0x58) = 0;
      goto LAB_005422fb;
    }
  }
  uVar4 = __ftol();
  *(undefined4 *)(param_1 + 0x58) = uVar4;
LAB_005422fb:
  iVar5 = __ftol();
  *(int *)(param_1 + 0x68) = iVar5;
  iVar6 = __ftol();
  iVar5 = (*(int *)(param_1 + 0x54) >> 1) + iVar5;
  *(int *)(param_1 + 0x5c) = iVar5;
  *(float *)(param_1 + 0x14) = (float)iVar5;
  *(int *)(param_1 + 100) = iVar6;
  iVar6 = iVar6 + (*(int *)(param_1 + 0x58) >> 1);
  *(int *)(param_1 + 0x60) = iVar6;
  *(float *)(param_1 + 0x18) = (float)iVar6;
  fVar2 = (float)*(int *)(param_1 + 0x54);
  fVar1 = (_DAT_0059e450 * fVar2) / *(float *)(param_1 + 0x1c);
  *(float *)(param_1 + 0xc) = fVar1;
  fVar3 = (float)*(int *)(param_1 + 0x58);
  *(float *)(param_1 + 0x10) = (_DAT_0059e450 * fVar3) / *(float *)(param_1 + 0x20);
  *(float *)(param_1 + 0x74) = fVar2 / fVar3;
  if ((*(byte *)(param_1 + 0x80) & 0x10) != 0) {
    *(float *)(param_1 + 0xc) = -fVar1;
  }
  return;
}


