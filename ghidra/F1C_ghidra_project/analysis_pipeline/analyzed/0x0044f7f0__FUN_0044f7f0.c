// Function: FUN_0044f7f0 @ 0044f7f0
// Size (bytes): 241


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0044f7f0(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,float param_6,
            float param_7)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *unaff_retaddr;
  undefined4 local_18;
  int local_14;
  float *local_10;
  undefined4 local_c;
  float *pfStack_4;
  
  piVar2 = *(int **)(param_1 + 0x80);
  if (piVar2 != (int *)0x0) {
    local_10 = param_2;
    local_18 = 0x18;
    local_14 = 0x10;
    local_c = 1;
    iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2,4,&local_18);
    if (iVar5 == 0) {
      fVar1 = (float)local_14;
      fVar4 = (float)(int)local_10;
      *param_4 = (float)local_14;
      *param_3 = 0.0;
      if (fVar1 != fVar4) {
        *param_3 = _DAT_0059e43c / (fVar4 - fVar1);
      }
      *pfStack_4 = param_7 * (fVar4 - fVar1) + fVar1;
      fVar3 = (fVar4 - fVar1) * param_6 * _DAT_0059e450;
      *param_5 = fVar3;
      fVar3 = fVar3 + fVar1;
      fVar1 = *param_5;
      *unaff_retaddr = 0.0;
      if (*pfStack_4 != fVar3) {
        *unaff_retaddr = _DAT_0059e43c / (*pfStack_4 - fVar3);
      }
      *param_2 = 0.0;
      if (fVar4 - fVar1 != *pfStack_4) {
        *param_2 = _DAT_0059e43c / ((fVar4 - fVar1) - *pfStack_4);
        return;
      }
    }
  }
  return;
}


