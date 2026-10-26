// Function: FUN_0045ae00 @ 0045ae00
// Size (bytes): 324


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045ae00(int param_1,float param_2)

{
  int iVar1;
  double *pdVar2;
  undefined4 *puVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60 [2];
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_20;
  undefined4 local_18 [6];
  
  if (*(int *)(param_1 + 0xd0) != 0) {
    param_2 = param_2 - *(float *)(param_1 + 0x24);
    local_78 = (double)(param_2 * (float)*(double *)(param_1 + 0x138) +
                       (float)*(double *)(param_1 + 0xd8));
    local_70 = (double)(param_2 * (float)*(double *)(param_1 + 0x140)) + *(double *)(param_1 + 0xe0)
    ;
    local_68 = (double)(param_2 * (float)*(double *)(param_1 + 0x148)) + *(double *)(param_1 + 0xe8)
    ;
    local_90 = (double)(param_2 * (float)*(double *)(param_1 + 0x150));
    local_88 = (double)(param_2 * (float)*(double *)(param_1 + 0x158));
    local_80 = (double)(param_2 * (float)*(double *)(param_1 + 0x160));
    pdVar2 = &local_90;
    puVar3 = local_18;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *(undefined4 *)pdVar2;
      pdVar2 = (double *)((int)pdVar2 + 4);
      puVar3 = puVar3 + 1;
    }
    puVar3 = (undefined4 *)(param_1 + 0xf0);
    pdVar2 = local_60;
    for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pdVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      pdVar2 = (double *)((int)pdVar2 + 4);
    }
    FUN_0056c020(local_18);
    fVar4 = (float10)FUN_00588570();
    if (ABS(local_38) == _DAT_0059e420) {
      fVar5 = (float10)fpatan(-(float10)local_30,(float10)local_60[0]);
      fVar6 = (float10)_DAT_0059e430;
    }
    else {
      fVar5 = (float10)fpatan((float10)local_50,(float10)local_20);
      fVar6 = (float10)fpatan((float10)local_48,(float10)local_40);
    }
    FUN_0054b4d0((float)local_78,(float)local_70,(float)local_68,(float)-fVar4,(float)fVar5,
                 (float)fVar6);
  }
  return;
}


