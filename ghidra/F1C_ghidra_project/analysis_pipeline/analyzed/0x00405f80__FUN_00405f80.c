// Function: FUN_00405f80 @ 00405f80
// Size (bytes): 160


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00405f80(int param_1,float *param_2)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *(int *)(param_1 + 0x54);
  fVar2 = ((*(float *)(iVar1 + 0x80) * param_2[1] +
            *(float *)(iVar1 + 0x7c) * *param_2 + *(float *)(iVar1 + 0x84) * param_2[2] +
           _DAT_0059e4e4) /
          (*(float *)(param_1 + 0x34) * *param_2 +
           *(float *)(param_1 + 0x38) * param_2[1] + *(float *)(param_1 + 0x3c) * param_2[2] +
          _DAT_0059e4e4)) * *(float *)(param_1 + 0x48);
  if (fVar2 < _DAT_0059e4e0) {
    *(undefined4 *)(param_1 + 0x48) = 0x3e000000;
    return;
  }
  if (_DAT_0059e4dc < fVar2) {
    *(undefined4 *)(param_1 + 0x48) = 0x41000000;
    return;
  }
  *(float *)(param_1 + 0x48) = fVar2;
  return;
}


