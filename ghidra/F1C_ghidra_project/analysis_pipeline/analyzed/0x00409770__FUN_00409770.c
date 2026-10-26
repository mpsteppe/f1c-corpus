// Function: FUN_00409770 @ 00409770
// Size (bytes): 282


undefined4 __thiscall FUN_00409770(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int local_1c [7];
  
  if (param_2 != 0) {
    FUN_0058ba36(param_2,0x80);
    FUN_005668b0();
    if (param_3 == 0) {
      FUN_00566a70(param_2,0,1,1);
    }
    else {
      FUN_00566940(param_2,0,1,1);
    }
    if (local_1c[0] != 0) {
      piVar1 = *(int **)(param_1 + 0x10);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(local_1c,0);
      }
      piVar2 = *(int **)(param_1 + 0x14);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(local_1c,0);
      }
      piVar3 = *(int **)(param_1 + 0x18);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(local_1c,0);
      }
      piVar4 = *(int **)(param_1 + 0x1c);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 8))(local_1c,0);
      }
      bVar5 = piVar4 != (int *)0x0 ||
              (piVar3 != (int *)0x0 || (piVar2 != (int *)0x0 || piVar1 != (int *)0x0));
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x38)) {
        iVar7 = 0;
        bVar5 = true;
        do {
          (**(code **)(*(int *)(iVar7 + *(int *)(param_1 + 0x20)) + 8))(local_1c,0);
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + 200;
        } while (iVar6 < *(int *)(param_1 + 0x38));
      }
      FUN_00566b90();
      if (bVar5) {
        FUN_005668d0();
        return 0;
      }
    }
    FUN_005668d0();
  }
  return 1;
}


