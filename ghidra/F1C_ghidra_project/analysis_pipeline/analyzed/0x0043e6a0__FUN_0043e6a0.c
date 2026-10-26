// Function: FUN_0043e6a0 @ 0043e6a0
// Size (bytes): 200


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043e6a0(int param_1,double *param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  iVar2 = FUN_00567740();
  iVar1 = *(int *)(param_1 + 0x15f0);
  local_20 = *param_2 + *(double *)(iVar1 + 4);
  local_18 = *(double *)(iVar1 + 0xc) + param_2[1];
  local_10 = *(double *)(iVar1 + 0x14) + param_2[2];
  fVar3 = (float10)FUN_00588570();
  local_38 = (double)-fVar3;
  if (ABS(*(double *)(iVar1 + 0x44)) == _DAT_0059e420) {
    fVar3 = (float10)fpatan(-(float10)*(double *)(iVar1 + 0x4c),(float10)*(double *)(iVar1 + 0x1c));
    local_28 = 0.0;
  }
  else {
    fVar3 = (float10)fpatan((float10)*(double *)(iVar1 + 0x2c),(float10)*(double *)(iVar1 + 0x5c));
    fVar4 = (float10)fpatan((float10)*(double *)(iVar1 + 0x34),(float10)*(double *)(iVar1 + 0x3c));
    local_28 = (double)fVar4;
  }
  local_30 = (double)fVar3;
  FUN_0056f100(iVar1,&local_20,&local_38,0);
  if (iVar2 != 0x200) {
    FUN_00567780();
  }
  return;
}


