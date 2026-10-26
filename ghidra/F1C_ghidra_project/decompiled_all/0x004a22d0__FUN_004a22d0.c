// Function: FUN_004a22d0 @ 004a22d0
// Strings:  [D:\dev\F1_1999_2002\Source\pitcrew.cpp, CUBE error loading animation file %s: %s]


undefined4 __thiscall
FUN_004a22d0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_10c;
  int local_108;
  undefined4 local_104;
  undefined1 local_100 [256];
  
  local_104 = DAT_008afe88;
  if (*(int *)(param_1 + 100) != 0) {
    iVar8 = *(int *)(param_1 + 0x70);
    piVar2 = operator_new((iVar8 + 1) * 0x1c + 4);
    if (piVar2 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = piVar2 + 1;
      *piVar2 = iVar8 + 1;
      if (-1 < iVar8) {
        iVar8 = iVar8 + 1;
        do {
          FUN_004a1fb0();
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
    iVar8 = 0;
    if (0 < *(int *)(param_1 + 0x70)) {
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)(*(int *)(param_1 + 0x74) + iVar3);
        puVar10 = (undefined4 *)(iVar3 + (int)piVar7);
        for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        *(undefined4 *)(iVar3 + 0x14 + *(int *)(param_1 + 0x74)) = 0;
        iVar8 = iVar8 + 1;
        iVar3 = iVar3 + 0x1c;
      } while (iVar8 < *(int *)(param_1 + 0x70));
    }
    iVar8 = *(int *)(param_1 + 0x74);
    if (iVar8 != 0) {
      iVar3 = *(int *)(iVar8 + -4);
      local_108 = iVar8 + -4;
      if (-1 < iVar3 + -1) {
        do {
          FUN_004dd4d0();
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      FUN_00587bcf(local_108);
    }
    *(int **)(param_1 + 0x74) = piVar7;
    pvVar4 = operator_new(*(int *)(param_1 + 0x68) << 2);
    *(void **)(*(int *)(param_1 + 0x70) * 0x1c + 0x14 + *(int *)(param_1 + 0x74)) = pvVar4;
    iVar8 = 0;
    if (0 < *(int *)(param_1 + 0x68)) {
      do {
        iVar3 = *(int *)(param_1 + 0x70) * 0x1c;
        iVar6 = iVar3 + *(int *)(param_1 + 0x74);
        *(undefined4 *)(*(int *)(iVar3 + 0x14 + *(int *)(param_1 + 0x74)) + iVar8 * 4) = 0;
        iVar3 = FUN_005518a0(&local_10c,param_3,0);
        if ((iVar3 == -1) || (iVar3 = FUN_00551560(local_10c), iVar3 != 0)) {
          FUN_0053c5b0(0,local_100);
          cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_pitcr_005cd174,0x147);
          if (cVar1 != '\0') {
            FUN_004d7aa0(&DAT_008ad25c,s_CUBE_error_loading_animation_fil_005cd19c,param_3,local_100
                        );
          }
          break;
        }
        uVar5 = FUN_00551830(param_2);
        *(undefined4 *)(*(int *)(iVar6 + 0x14) + iVar8 * 4) = uVar5;
        if (iVar8 == 0) {
          *(undefined4 *)(iVar6 + 0xc) = param_5;
          *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(local_10c + 8);
          if (param_4 == 0) {
            *(undefined4 *)(iVar6 + 0x18) = 0x18;
          }
          else {
            uVar5 = FUN_004a24d0();
            *(undefined4 *)(iVar6 + 0x18) = uVar5;
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(param_1 + 0x68));
    }
    if (iVar8 == *(int *)(param_1 + 0x68)) {
      *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    }
  }
  return 0;
}


