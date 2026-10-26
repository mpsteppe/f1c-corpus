// Function: FUN_0040ef70 @ 0040ef70
// Size (bytes): 320


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040ef70(int param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  double *pdVar4;
  float *pfVar5;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  double local_8;
  
  pfVar2 = param_2;
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
  case 2:
  case 4:
    fVar1 = *param_2;
    iVar3 = *(int *)(param_1 + 0x20);
    *(float *)(iVar3 + 0x24) = fVar1;
    *(float *)(iVar3 + 0x20) = fVar1 + _DAT_0059e6f8;
    param_2 = (float *)(*(int *)(param_1 + 0x20) + 0xd4);
    break;
  case 1:
  case 3:
  case 5:
    fVar1 = *param_2;
    iVar3 = *(int *)(param_1 + 0x20);
    *(float *)(iVar3 + 0x24) = fVar1;
    *(float *)(iVar3 + 0x20) = fVar1 + _DAT_0059e6f8;
    param_2 = (float *)(*(int *)(param_1 + 0x20) + 0xd4);
  }
  pfVar5 = pfVar2 + 1;
  *(float *)(param_1 + 0xc) = *pfVar5;
  *(float *)(param_1 + 0x10) = pfVar2[2];
  *(float *)(param_1 + 0x14) = pfVar2[3];
  FUN_0054b4d0(*pfVar5,pfVar2[2],pfVar2[3],pfVar2[4],pfVar2[5],pfVar2[6]);
  local_48 = (double)*pfVar5;
  local_40 = (double)pfVar2[2];
  local_38 = (double)pfVar2[3];
  pdVar4 = &local_48;
  pfVar5 = param_2;
  for (iVar3 = 6; pfVar5 = pfVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *(float *)pdVar4;
    pdVar4 = (double *)((int)pdVar4 + 4);
  }
  local_30 = (double)pfVar2[4];
  local_28 = (double)pfVar2[5];
  local_20 = (double)pfVar2[6];
  FUN_005691d0(&local_30);
  local_48 = (double)pfVar2[7];
  local_40 = (double)pfVar2[8];
  local_38 = (double)pfVar2[9];
  pdVar4 = &local_48;
  pfVar5 = param_2 + 0x19;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *(float *)pdVar4;
    pdVar4 = (double *)((int)pdVar4 + 4);
    pfVar5 = pfVar5 + 1;
  }
  local_18 = (double)pfVar2[10];
  local_10 = (double)pfVar2[0xb];
  local_8 = (double)pfVar2[0xc];
  FUN_00569280(&local_18);
  FUN_0040f0d0();
  return;
}


