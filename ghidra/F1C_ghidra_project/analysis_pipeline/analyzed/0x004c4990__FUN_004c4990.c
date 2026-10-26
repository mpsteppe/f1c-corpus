// Function: FUN_004c4990 @ 004c4990
// Size (bytes): 271


int __thiscall FUN_004c4990(int param_1,int *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar1 = DAT_008ac390;
  iVar3 = 0;
  local_8 = 0;
  if (((*param_2 != 0) && (0 < param_3)) && (iVar7 = 0, 0 < DAT_008ac390)) {
    local_c = 0;
    do {
      cVar2 = FUN_004c4cb0(iVar7);
      if ((cVar2 == '\0') && (local_c + DAT_008ac394 != 0)) {
        iVar3 = 0;
        if (0 < param_3) {
          do {
            iVar4 = FUN_00566810();
            if (iVar4 == 0) break;
            iVar3 = iVar3 + 1;
          } while (iVar3 < param_3);
        }
        if (iVar3 == param_3) {
          piVar5 = operator_new(4);
          *piVar5 = iVar7;
          puVar6 = operator_new(0xc);
          if (puVar6 == (undefined4 *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            *puVar6 = piVar5;
            puVar6[1] = 0;
            *(undefined1 *)(puVar6 + 2) = 1;
          }
          if (*(int *)(param_1 + 8) == 0) {
            *(undefined4 **)(param_1 + 8) = puVar6;
            *(undefined4 **)(param_1 + 0x10) = puVar6;
          }
          else {
            *(undefined4 **)(*(int *)(param_1 + 0xc) + 4) = puVar6;
          }
          *(undefined4 **)(param_1 + 0xc) = puVar6;
          local_8 = local_8 + 1;
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        }
      }
      iVar7 = iVar7 + 1;
      local_c = local_c + 0x424;
      iVar3 = local_8;
    } while (iVar7 < iVar1);
  }
  return iVar3;
}


