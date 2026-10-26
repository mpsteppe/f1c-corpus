// Function: FUN_004d6830 @ 004d6830
// Size (bytes): 104


float10 __thiscall
FUN_004d6830(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  
  dVar1 = ((double)CONCAT44(param_5,param_4) / (double)CONCAT44(param_3,param_2)) *
          *(double *)(param_1 + 8);
  fVar4 = (float10)FUN_005895a2(dVar1);
  uVar2 = (uint)ROUND((float)fVar4);
  if (*(uint *)(param_1 + 0x10) <= uVar2) {
    uVar2 = *(uint *)(param_1 + 0x10) - 1;
  }
  iVar3 = uVar2 * 0x20 + *(int *)(param_1 + 0x14);
  return (((float10)dVar1 * (float10)*(double *)(uVar2 * 0x20 + *(int *)(param_1 + 0x14)) +
          (float10)*(double *)(iVar3 + 8)) * (float10)dVar1 + (float10)*(double *)(iVar3 + 0x10)) *
         (float10)dVar1 + (float10)*(double *)(iVar3 + 0x18);
}


