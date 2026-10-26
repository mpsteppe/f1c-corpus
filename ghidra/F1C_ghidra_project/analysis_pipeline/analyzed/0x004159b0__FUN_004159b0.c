// Function: FUN_004159b0 @ 004159b0
// Size (bytes): 634


undefined4 __fastcall FUN_004159b0(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_20;
  int local_1c;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_4;
  
  iVar2 = DAT_008ac390;
  puVar11 = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_4 = 0;
  if (0 < DAT_008ac390) {
    local_20 = 0;
    local_1c = DAT_008ac390;
    puVar7 = puVar11;
    do {
      pcVar1 = (char *)(local_20 + 0x7c + DAT_008ac394);
      puVar11 = puVar7;
      if (*pcVar1 != '\0') {
        if (puVar7 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar7;
          puVar6 = puVar7;
          while (puVar5 != (undefined4 *)0x0) {
            puVar3 = (undefined1 *)*puVar5;
            if (puVar3 == (undefined1 *)0x0) {
              puVar3 = &DAT_005ea438;
            }
            iVar4 = FUN_00588410(pcVar1,puVar3);
            if (iVar4 == 0) goto LAB_00415a81;
            puVar6 = (undefined4 *)puVar6[1];
            if (puVar6 == (undefined4 *)0x0) break;
            puVar5 = (undefined4 *)*puVar6;
          }
        }
        puVar5 = operator_new(8);
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = 0;
          puVar5[1] = 0xffffffff;
          FUN_00566650(pcVar1);
          puVar6 = operator_new(0xc);
          if (puVar6 == (undefined4 *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            *puVar6 = puVar5;
            puVar6[1] = 0;
            *(undefined1 *)(puVar6 + 2) = 1;
          }
          puVar11 = puVar6;
          puVar5 = puVar6;
          if (puVar7 != (undefined4 *)0x0) {
            local_c[1] = puVar6;
            puVar11 = puVar7;
            puVar5 = local_10;
          }
          local_10 = puVar5;
          local_4 = local_4 + 1;
          local_c = puVar6;
        }
      }
LAB_00415a81:
      local_20 = local_20 + 0x424;
      local_1c = local_1c + -1;
      puVar7 = puVar11;
    } while (local_1c != 0);
  }
  iVar4 = *(int *)(param_1 + 0x10);
  while (iVar4 != 0) {
    iVar4 = *(int *)(iVar4 + 4);
    FUN_00418c10(1);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if ((0 < local_4) && (local_20 = 0, 0 < local_4)) {
    do {
      puVar7 = operator_new(0xac);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = 0;
        puVar7[1] = 0xffffffff;
        FUN_00401000(puVar7 + 3,0x14,2,FUN_00415520);
        FUN_00401000(puVar7 + 0xd,0x14,2,FUN_00415520);
        FUN_00401000(puVar7 + 0x17,0x14,2,FUN_00415520);
        FUN_00401000(puVar7 + 0x21,0x14,2,FUN_00415520);
        FUN_00414d70();
      }
      if ((local_20 < 0) || (iVar4 = local_20, local_4 <= local_20)) {
LAB_00415b80:
        puVar11 = (undefined4 *)0x0;
      }
      else {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          if (puVar11 == (undefined4 *)0x0) goto LAB_00415b80;
          puVar11 = (undefined4 *)puVar11[1];
        }
        if (puVar11 == (undefined4 *)0x0) goto LAB_00415b80;
        puVar11 = (undefined4 *)*puVar11;
      }
      puVar3 = (undefined1 *)*puVar11;
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_00566650(puVar3);
      iVar4 = 0;
      if (0 < iVar2) {
        iVar10 = 0;
        do {
          iVar9 = DAT_008ac394 + iVar10;
          uVar8 = FUN_00415c30();
          iVar9 = FUN_00588410(iVar9 + 0x7c,uVar8);
          if (iVar9 == 0) {
            puVar7[2] = iVar4;
            break;
          }
          iVar4 = iVar4 + 1;
          iVar10 = iVar10 + 0x424;
        } while (iVar4 < iVar2);
      }
      FUN_00414a90();
      FUN_00434030(puVar7,1);
      local_20 = local_20 + 1;
      puVar11 = local_10;
    } while (local_20 < local_4);
  }
  while (puVar11 != (undefined4 *)0x0) {
    puVar11 = (undefined4 *)puVar11[1];
    FUN_00418d60(1);
  }
  return 0;
}


