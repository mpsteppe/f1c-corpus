// Function: FUN_004e2610 @ 004e2610
// Size (bytes): 332


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e2610(int param_1,int param_2,float *param_3,float *param_4,float *param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float10 fVar7;
  
  iVar1 = param_2 * 0x128 + 0xd4 + param_1;
  fVar2 = *param_3 - *(float *)(param_1 + 0x48);
  fVar3 = param_3[1] - *(float *)(param_1 + 0x4c);
  fVar4 = param_3[2] - *(float *)(param_1 + 0x50);
  *(float *)(iVar1 + 0x74) = fVar2;
  *(float *)(iVar1 + 0x78) = fVar3;
  *(float *)(iVar1 + 0x7c) = fVar4;
  *(float *)(iVar1 + 0xb8) = fVar2;
  *(float *)(iVar1 + 0xbc) = fVar3;
  *(float *)(iVar1 + 0xc0) = fVar4;
  pfVar6 = (float *)(iVar1 + 0x8c);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar6 = *param_4;
    param_4 = param_4 + 1;
    pfVar6 = pfVar6 + 1;
  }
  fVar7 = (float10)FUN_00588570();
  *(float *)(iVar1 + 0x80) = (float)-fVar7;
  if (ABS(*(float *)(iVar1 + 0xa0)) == (float)_DAT_0059e420) {
    *(undefined4 *)(iVar1 + 0x88) = 0;
    fVar7 = (float10)fpatan(-(float10)*(float *)(iVar1 + 0xa4),(float10)*(float *)(iVar1 + 0x8c));
    *(float *)(iVar1 + 0x84) = (float)fVar7;
  }
  else {
    fVar7 = (float10)fpatan((float10)*(float *)(iVar1 + 0x94),(float10)*(float *)(iVar1 + 0xac));
    *(float *)(iVar1 + 0x84) = (float)fVar7;
    fVar7 = (float10)fpatan((float10)*(float *)(iVar1 + 0x98),(float10)*(float *)(iVar1 + 0x9c));
    *(float *)(iVar1 + 0x88) = (float)fVar7;
  }
  pfVar6 = (float *)(iVar1 + 0xd0);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar6 = *param_5;
    param_5 = param_5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  fVar7 = (float10)FUN_00588570();
  *(float *)(iVar1 + 0xc4) = (float)-fVar7;
  if (ABS(*(float *)(iVar1 + 0xe4)) != (float)_DAT_0059e420) {
    fVar7 = (float10)fpatan((float10)*(float *)(iVar1 + 0xd8),(float10)*(float *)(iVar1 + 0xf0));
    *(float *)(iVar1 + 200) = (float)fVar7;
    fVar7 = (float10)fpatan((float10)*(float *)(iVar1 + 0xdc),(float10)*(float *)(iVar1 + 0xe0));
    *(float *)(iVar1 + 0xcc) = (float)fVar7;
    return;
  }
  fVar7 = (float10)fpatan(-(float10)*(float *)(iVar1 + 0xe8),(float10)*(float *)(iVar1 + 0xd0));
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(float *)(iVar1 + 200) = (float)fVar7;
  return;
}


