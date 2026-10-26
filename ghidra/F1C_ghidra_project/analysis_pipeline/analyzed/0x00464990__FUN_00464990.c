// Function: FUN_00464990 @ 00464990
// Size (bytes): 86


void __thiscall FUN_00464990(int *param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = *param_1;
  fVar2 = *(float *)(iVar1 + 0x75) - *(float *)(param_2 + 0x34e0);
  fVar4 = *(float *)(iVar1 + 0x79) - *(float *)(param_2 + 0x34e4);
  fVar3 = *(float *)(iVar1 + 0x7d) - *(float *)(param_2 + 0x34e8);
  param_1[1] = (int)(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
  return;
}


