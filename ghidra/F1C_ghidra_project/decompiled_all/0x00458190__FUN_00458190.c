// Function: FUN_00458190 @ 00458190
// Strings:  [MovementPath]


undefined4 __thiscall FUN_00458190(int *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_108 [65];
  
  uVar1 = 0;
  if (0 < (int)param_3) {
    puVar5 = local_108;
    for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar5 = 0x20202020;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = param_3 & 3; uVar1 = param_3, uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = 0x20;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  *(undefined1 *)((int)local_108 + uVar1) = 0;
  if ((*param_1 != 0) && (3 < param_1[1])) {
    FUN_00566c30(param_2,s__s_s_005c5aa0,local_108,s_MovementPath_005c5aa8);
    FUN_00566c30(param_2,&DAT_005c5988,local_108);
    iVar6 = 0;
    if (0 < param_1[1]) {
      iVar4 = 0;
      do {
        pfVar3 = (float *)(*param_1 + iVar4);
        FUN_00566c30(param_2,s__s_ControlPoint___f___f___f__005c5a80,local_108,(double)*pfVar3,
                     (double)pfVar3[1],(double)pfVar3[2]);
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (iVar6 < param_1[1]);
    }
    FUN_00566c30();
    return 0;
  }
  return 1;
}


