// Function: FUN_004072e0 @ 004072e0
// Size (bytes): 293


void __thiscall FUN_004072e0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if (*(int *)(param_1 + 0x48) != 0) {
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x4c)) {
      iVar7 = 0;
      do {
        piVar2 = *(int **)(iVar7 + *(int *)(param_1 + 0x48));
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))();
        }
        iVar1 = *(int *)(iVar7 + 0x10 + *(int *)(param_1 + 0x48));
        if (iVar1 != 0) {
          _AIL_release_sample_handle_4(iVar1);
          *(undefined4 *)(iVar7 + 0x10 + *(int *)(param_1 + 0x48)) = 0;
        }
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x14;
      } while (iVar6 < *(int *)(param_1 + 0x4c));
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0x48) + -4);
    }
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  *(int *)(param_1 + 0x4c) = param_2;
  if (0 < param_2) {
    piVar2 = operator_new(param_2 * 0x14 + 4);
    if (piVar2 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = piVar2 + 1;
      *piVar2 = param_2;
      piVar2 = piVar3;
      if (-1 < param_2 + -1) {
        do {
          *piVar2 = 0;
          piVar2[1] = 0;
          piVar2[2] = 0;
          *(undefined1 *)(piVar2 + 3) = 0;
          piVar2[4] = 0;
          param_2 = param_2 + -1;
          piVar2 = piVar2 + 5;
        } while (param_2 != 0);
      }
    }
    *(int **)(param_1 + 0x48) = piVar3;
    if (piVar3 == (int *)0x0) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      return;
    }
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x4c)) {
      iVar7 = 0;
      do {
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0x48) + iVar7);
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        *(undefined1 *)(puVar4 + 3) = 0;
        puVar4[4] = 0;
        if (*(int *)(param_1 + 0x90) != 0) {
          uVar5 = _AIL_allocate_sample_handle_4(*(int *)(param_1 + 0x90));
          *(undefined4 *)(iVar7 + 0x10 + *(int *)(param_1 + 0x48)) = uVar5;
          iVar1 = *(int *)(iVar7 + 0x10 + *(int *)(param_1 + 0x48));
          if (iVar1 != 0) {
            _AIL_init_sample_4(iVar1);
          }
        }
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x14;
      } while (iVar6 < *(int *)(param_1 + 0x4c));
    }
  }
  return;
}


