// Function: FUN_00568fb0 @ 00568fb0
// Size (bytes): 532


void __thiscall FUN_00568fb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int local_4c;
  int local_48;
  int local_38;
  int local_34;
  int local_24;
  int local_18;
  
  iVar1 = *(int *)(param_1 + 0x22c);
  iVar12 = *(int *)(param_1 + 0x23c) + iVar1 + *(int *)(param_1 + 0x234);
  iVar4 = *(int *)(param_1 + 0x234) + iVar1;
  local_18 = 0;
  if (0 < iVar12) {
    iVar14 = iVar1 * -0x84;
    iVar5 = iVar4 * -0x58;
    local_48 = 0;
    do {
      if (local_18 < iVar1) {
        iVar10 = *(int *)(*(int *)(param_1 + 0x230) + 0x30 + local_48);
        local_4c = 3;
      }
      else if (local_18 < iVar4) {
        iVar10 = *(int *)(*(int *)(param_1 + 0x238) + 0x7c + iVar14);
        local_4c = 2;
      }
      else {
        iVar10 = *(int *)(*(int *)(param_1 + 0x240) + 0x30 + iVar5);
        local_4c = 1;
      }
      if (local_18 < iVar12) {
        local_34 = local_48;
        iVar7 = iVar5;
        iVar9 = local_18;
        local_38 = iVar14;
        do {
          if (iVar9 < iVar1) {
            iVar6 = *(int *)(*(int *)(param_1 + 0x230) + 0x30 + local_34);
            iVar15 = 3;
          }
          else if (iVar9 < iVar4) {
            iVar6 = *(int *)(*(int *)(param_1 + 0x238) + 0x7c + local_38);
            iVar15 = 2;
          }
          else {
            iVar6 = *(int *)(*(int *)(param_1 + 0x240) + 0x30 + iVar7);
            iVar15 = 1;
          }
          if (local_4c != 0) {
            iVar13 = iVar10 * 8;
            piVar11 = (int *)(param_2 + iVar10 * 4);
            local_24 = local_4c;
            do {
              if (iVar15 != 0) {
                iVar3 = iVar6 * 8;
                piVar8 = (int *)(param_2 + iVar6 * 4);
                iVar16 = iVar15;
                do {
                  iVar2 = *piVar11;
                  *(undefined4 *)(iVar3 + iVar2) = 0;
                  *(undefined4 *)(iVar3 + 4 + iVar2) = 0x3ff00000;
                  iVar2 = *piVar8;
                  *(undefined4 *)(iVar13 + iVar2) = 0;
                  iVar3 = iVar3 + 8;
                  piVar8 = piVar8 + 1;
                  iVar16 = iVar16 + -1;
                  *(undefined4 *)(iVar13 + 4 + iVar2) = 0x3ff00000;
                } while (iVar16 != 0);
              }
              piVar11 = piVar11 + 1;
              iVar13 = iVar13 + 8;
              local_24 = local_24 + -1;
            } while (local_24 != 0);
          }
          local_38 = local_38 + 0x84;
          iVar9 = iVar9 + 1;
          iVar7 = iVar7 + 0x58;
          local_34 = local_34 + 0x38;
        } while (iVar9 < iVar12);
      }
      local_18 = local_18 + 1;
      iVar5 = iVar5 + 0x58;
      iVar14 = iVar14 + 0x84;
      local_48 = local_48 + 0x38;
    } while (local_18 < iVar12);
  }
  return;
}


