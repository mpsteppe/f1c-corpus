// Function: FUN_004c5e50 @ 004c5e50
// Strings:  [Filter Properties]


int __thiscall FUN_004c5e50(int param_1,int *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_10c;
  int local_108;
  undefined1 local_100;
  undefined4 local_ff;
  
  iVar1 = DAT_008ac488;
  iVar7 = 0;
  iVar3 = 0;
  local_10c = 0;
  if (((*param_2 != 0) && (0 < param_3)) && (0 < DAT_008ac488)) {
    local_108 = 0;
    do {
      cVar2 = FUN_004c4cb0(iVar7);
      if ((cVar2 == '\0') && (DAT_008ac490 + local_108 != 0)) {
        local_100 = DAT_005ea438;
        puVar8 = &local_ff;
        for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        *(undefined2 *)puVar8 = 0;
        *(undefined1 *)((int)puVar8 + 2) = 0;
        iVar3 = FUN_004c58a0(&local_100,0x100,s_Filter_Properties_005d31ec,
                             DAT_008ac490 + local_108 + 0x104);
        if (iVar3 == 0) {
          iVar3 = 0;
          if (0 < param_3) {
            do {
              iVar4 = FUN_00566810();
              if (iVar4 == 0) break;
              iVar3 = iVar3 + 1;
            } while (iVar3 < param_3);
          }
          if (((iVar3 == param_3) && (pvVar5 = operator_new(0x10), pvVar5 != (void *)0x0)) &&
             (iVar3 = FUN_004c5c80(iVar7,&local_100), iVar3 != 0)) {
            piVar6 = operator_new(0xc);
            if (piVar6 == (int *)0x0) {
              piVar6 = (int *)0x0;
            }
            else {
              *piVar6 = iVar3;
              piVar6[1] = 0;
              *(undefined1 *)(piVar6 + 2) = 1;
            }
            if (*(int *)(param_1 + 8) == 0) {
              *(int **)(param_1 + 8) = piVar6;
              *(int **)(param_1 + 0x10) = piVar6;
            }
            else {
              *(int **)(*(int *)(param_1 + 0xc) + 4) = piVar6;
            }
            *(int **)(param_1 + 0xc) = piVar6;
            local_10c = local_10c + 1;
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          }
        }
      }
      iVar7 = iVar7 + 1;
      local_108 = local_108 + 0x18c;
      iVar3 = local_10c;
    } while (iVar7 < iVar1);
  }
  return iVar3;
}


