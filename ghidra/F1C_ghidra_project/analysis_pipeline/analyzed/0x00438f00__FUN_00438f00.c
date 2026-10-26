// Function: FUN_00438f00 @ 00438f00
// Size (bytes): 405


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00438f00(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  double *pdVar4;
  float10 fVar5;
  float10 fVar6;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  double local_20;
  double local_18;
  double local_10;
  
  fVar1 = *param_3;
  puVar3 = (undefined4 *)(param_1 + 0x1614);
  pdVar4 = &local_68;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pdVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    pdVar4 = (double *)((int)pdVar4 + 4);
  }
  local_68 = (double)fVar1 + local_68;
  local_60 = (double)(param_3[1] + (float)local_60);
  puVar3 = *(undefined4 **)(param_1 + 0x1e8);
  local_58 = (double)(param_3[2] + (float)local_58);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if (puVar3 != (undefined4 *)0x0) {
    iVar2 = *(int *)(param_1 + 0x15f0);
    local_40 = local_68 * *(double *)(iVar2 + 0x4c) +
               local_60 * *(double *)(iVar2 + 0x54) + local_58 * *(double *)(iVar2 + 0x5c);
    local_20 = local_68 * *(double *)(iVar2 + 0x1c) +
               local_60 * *(double *)(iVar2 + 0x24) + local_58 * *(double *)(iVar2 + 0x2c) +
               *(double *)(iVar2 + 4);
    local_18 = local_68 * *(double *)(iVar2 + 0x34) +
               local_60 * *(double *)(iVar2 + 0x3c) + local_58 * *(double *)(iVar2 + 0x44) +
               *(double *)(iVar2 + 0xc);
    local_10 = local_40 + *(double *)(iVar2 + 0x14);
    pdVar4 = &local_20;
    for (iVar2 = 6; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *(undefined4 *)pdVar4;
      pdVar4 = (double *)((int)pdVar4 + 4);
    }
    iVar2 = *(int *)(param_1 + 0x15f0);
    fVar5 = (float10)FUN_00588570();
    local_50 = (double)-fVar5;
    if (ABS(*(double *)(iVar2 + 0x44)) == _DAT_0059e420) {
      fVar5 = (float10)fpatan(-(float10)*(double *)(iVar2 + 0x4c),(float10)*(double *)(iVar2 + 0x1c)
                             );
      local_40 = 0.0;
    }
    else {
      fVar5 = (float10)fpatan((float10)*(double *)(iVar2 + 0x2c),(float10)*(double *)(iVar2 + 0x5c))
      ;
      fVar6 = (float10)fpatan((float10)*(double *)(iVar2 + 0x34),(float10)*(double *)(iVar2 + 0x3c))
      ;
      local_40 = (double)fVar6;
    }
    local_48 = (double)fVar5;
    FUN_005691d0(&local_50);
  }
  FUN_00435410(*(undefined4 *)(param_1 + 0x1e8),param_2,&local_68,&local_38);
  return;
}


