// Function: FUN_004c8650 @ 004c8650
// Size (bytes): 469


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c8650(undefined4 *param_1,float param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int aiStack_14 [4];
  undefined1 uStack_4;
  
  if (param_2 <= DAT_0059e440) {
    param_2 = (float)_DAT_008afe90;
  }
  if (((*(char *)(param_1 + 4) != '\0') && (DAT_008ac4c8 != (int *)0x0)) &&
     (DAT_0059e440 < (float)DAT_008ac4c8[1])) {
    iVar3 = (**(code **)(*DAT_008ac4c8 + 8))();
    if (iVar3 == 0) {
      aiStack_14[0] = 0;
      aiStack_14[1] = 0xffffffff;
      FUN_00566650(&DAT_005ea438);
      uVar2 = DAT_005d3254;
      aiStack_14[2] = 0xffffffff;
      aiStack_14[3] = 0xffffffff;
      uStack_4 = 0;
      if ((int)param_1[3] < 1) {
        uVar1 = *(undefined4 *)(&DAT_005acdec + DAT_008ac4c0 * 4);
        FUN_00566650(&DAT_005ea438);
        DAT_008ac4c0 = DAT_008ac4c0 + 1;
        aiStack_14[3] = uVar2;
        uStack_4 = 0;
        aiStack_14[2] = uVar1;
        if (3 < DAT_008ac4c0) {
          DAT_008ac4c0 = 0;
        }
      }
      else {
        if (param_1[2] != 0) {
          param_1[2] = *(undefined4 *)(param_1[2] + 4);
        }
        if (((int *)param_1[2] == (int *)0x0) || (*(int *)param_1[2] == 0)) {
          param_1[2] = *param_1;
        }
        if ((undefined4 *)param_1[2] == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = *(undefined4 **)param_1[2];
        }
        puVar4 = (undefined1 *)*puVar5;
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        FUN_00566650(puVar4);
      }
      (**(code **)(*DAT_008ac4c8 + 4))(aiStack_14,1,0);
      if (aiStack_14[0] != 0) {
        FUN_00587bcf(aiStack_14[0]);
      }
    }
    else if (param_1[5] != 0) {
      if (param_1[5] == 1) {
        param_2 = param_2 * (float)param_1[6] + (float)DAT_008ac4c8[1];
        if (param_2 < DAT_007cf380) goto LAB_004c871b;
        param_2 = DAT_007cf380;
      }
      else {
        param_2 = (float)DAT_008ac4c8[1] - param_2 * (float)param_1[6];
        if (param_2 < DAT_0059e440 == (param_2 == DAT_0059e440)) goto LAB_004c871b;
        param_2 = 0.0;
      }
      param_1[5] = 0;
LAB_004c871b:
      (**(code **)(*DAT_008ac4c8 + 0x1c))(param_2);
      (**(code **)(*DAT_008ac4c8 + 0x18))();
      return;
    }
    (**(code **)(*DAT_008ac4c8 + 0x18))();
  }
  return;
}


