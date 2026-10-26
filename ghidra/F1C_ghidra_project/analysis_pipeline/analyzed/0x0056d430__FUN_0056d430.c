// Function: FUN_0056d430 @ 0056d430
// Size (bytes): 1092


void __fastcall FUN_0056d430(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_a2c;
  int local_a28;
  int local_a24;
  int local_a20;
  void *local_a1c;
  int *local_a18;
  int local_a10;
  int local_a0c;
  int local_a00 [127];
  int aiStack_804 [129];
  int aiStack_600 [128];
  int aiStack_400 [128];
  int local_200 [128];
  
  iVar6 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10);
  local_a2c = 0;
  do {
    if (local_a2c == 1) {
      local_a18 = operator_new(local_a20 * 4);
      local_a1c = operator_new(local_a20 * 4);
    }
    local_a20 = 0;
    if (0 < iVar6) {
      local_a0c = 0;
      iVar2 = 0;
      do {
        iVar5 = *(int *)(param_1 + 8);
        if (iVar2 < iVar5) {
          iVar5 = *(int *)(param_1 + 0xc) + local_a0c;
LAB_0056d4e6:
          local_a10 = *(int *)(iVar5 + 4);
          local_a24 = *(int *)(iVar5 + 0xc);
        }
        else {
          if (iVar5 + *(int *)(param_1 + 0x10) <= iVar2) {
            iVar5 = *(int *)(param_1 + 0x1c) + ((iVar2 - iVar5) - *(int *)(param_1 + 0x10)) * 0x48;
            goto LAB_0056d4e6;
          }
          iVar5 = (iVar2 - iVar5) * 0x30 + *(int *)(param_1 + 0x14);
          local_a10 = *(int *)(iVar5 + 4);
          local_a24 = *(int *)(iVar5 + 0xc);
        }
        iVar5 = iVar2 + 1;
        if (iVar5 < iVar6) {
          piVar4 = (int *)((int)local_a1c + local_a20 * 4);
          iVar3 = iVar5;
          local_a28 = local_a0c;
          do {
            local_a28 = local_a28 + 0x30;
            iVar1 = *(int *)(param_1 + 8);
            if (iVar3 < iVar1) {
              iVar1 = local_a28 + *(int *)(param_1 + 0xc);
            }
            else if (iVar3 < iVar1 + *(int *)(param_1 + 0x10)) {
              iVar1 = *(int *)(param_1 + 0x14) + (iVar3 - iVar1) * 0x30;
            }
            else {
              iVar1 = *(int *)(param_1 + 0x1c) + ((iVar3 - iVar1) - *(int *)(param_1 + 0x10)) * 0x48
              ;
            }
            if ((((local_a10 == *(int *)(iVar1 + 4)) || (local_a10 == *(int *)(iVar1 + 0xc))) ||
                (local_a24 == *(int *)(iVar1 + 4))) || (local_a24 == *(int *)(iVar1 + 0xc))) {
              if (local_a2c == 1) {
                *(int *)(((int)local_a18 - (int)local_a1c) + (int)piVar4) = iVar2;
                *piVar4 = iVar3;
              }
              local_a20 = local_a20 + 1;
              piVar4 = piVar4 + 1;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar6);
        }
        local_a0c = local_a0c + 0x30;
        iVar2 = iVar5;
      } while (iVar5 < iVar6);
    }
    local_a2c = local_a2c + 1;
  } while (local_a2c < 2);
  iVar2 = 0;
  if (0 < iVar6) {
    iVar5 = *(int *)(param_1 + 8);
    do {
      local_a00[iVar2] = iVar2;
      local_200[iVar2] = iVar2;
      aiStack_804[iVar2 + 1] = iVar2;
      if (iVar2 < iVar5) {
        iVar3 = 3;
      }
      else {
        iVar3 = (iVar2 < *(int *)(param_1 + 0x10) + iVar5) + 1;
      }
      aiStack_400[iVar2] = iVar3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar6);
  }
  iVar2 = 0;
  iVar5 = 0;
  if (0 < iVar6) {
    do {
      iVar3 = aiStack_804[iVar5 + 1];
      aiStack_600[iVar3] = iVar2;
      iVar2 = iVar2 + aiStack_400[iVar3];
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  iVar2 = 0;
  local_a28 = 0;
  if (0 < local_a20) {
    piVar4 = local_a18;
    iVar5 = local_a20;
    do {
      iVar3 = *piVar4;
      piVar7 = (int *)(((int)local_a1c - (int)local_a18) + (int)piVar4);
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + (aiStack_600[iVar3] - aiStack_600[*piVar7]) *
                      (aiStack_600[iVar3] - aiStack_600[*piVar7]);
      iVar5 = iVar5 + -1;
      local_a28 = iVar2;
    } while (iVar5 != 0);
  }
  do {
    iVar2 = 0;
    local_a24 = 0;
    if (iVar6 < 1) break;
    do {
      local_a2c = 0;
LAB_0056d6a0:
      do {
        if (local_a2c == 0) {
          iVar5 = local_a00[iVar2];
          if (0 < iVar5) {
            iVar3 = aiStack_804[iVar5];
            aiStack_804[iVar5 + 1] = iVar3;
            iVar1 = local_a00[iVar3];
            aiStack_804[iVar5] = iVar2;
            local_a00[iVar3] = iVar1 + 1;
            iVar5 = local_a00[iVar2] + -1;
LAB_0056d715:
            local_a00[iVar2] = iVar5;
            iVar3 = 0;
            iVar5 = 0;
            do {
              iVar1 = aiStack_804[iVar3 + 1];
              aiStack_600[iVar1] = iVar5;
              iVar5 = iVar5 + aiStack_400[iVar1];
              iVar3 = iVar3 + 1;
            } while (iVar3 < iVar6);
            iVar5 = 0;
            if (0 < local_a20) {
              piVar4 = local_a18;
              iVar3 = local_a20;
              do {
                iVar1 = *piVar4;
                piVar7 = (int *)((int)piVar4 + ((int)local_a1c - (int)local_a18));
                piVar4 = piVar4 + 1;
                iVar5 = iVar5 + (aiStack_600[iVar1] - aiStack_600[*piVar7]) *
                                (aiStack_600[iVar1] - aiStack_600[*piVar7]);
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            if (iVar5 < local_a28) {
              piVar4 = local_a00;
              piVar7 = local_200;
              for (iVar3 = iVar6; iVar3 != 0; iVar3 = iVar3 + -1) {
                *piVar7 = *piVar4;
                piVar4 = piVar4 + 1;
                piVar7 = piVar7 + 1;
              }
              local_a24 = local_a24 + 1;
              local_a28 = iVar5;
              goto LAB_0056d6a0;
            }
            iVar5 = 0;
            do {
              local_a00[iVar5] = local_200[iVar5];
              aiStack_804[local_200[iVar5] + 1] = iVar5;
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar6);
          }
        }
        else if ((local_a2c == 1) && (iVar5 = local_a00[iVar2], iVar5 < iVar6 + -1)) {
          iVar3 = aiStack_804[iVar5 + 2];
          aiStack_804[iVar5 + 1] = iVar3;
          aiStack_804[iVar5 + 2] = iVar2;
          local_a00[iVar3] = local_a00[iVar3] + -1;
          iVar5 = local_a00[iVar2] + 1;
          goto LAB_0056d715;
        }
        local_a2c = local_a2c + 1;
      } while (local_a2c < 2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar6);
  } while (0 < local_a24);
  FUN_00587bcf(local_a18);
  FUN_00587bcf(local_a1c);
  iVar2 = 0;
  iVar5 = 0;
  if (0 < iVar6) {
    do {
      iVar3 = aiStack_804[iVar5 + 1];
      iVar1 = *(int *)(param_1 + 8);
      if (iVar3 < iVar1) {
        *(int *)(iVar3 * 0x30 + 0x2c + *(int *)(param_1 + 0xc)) = iVar2;
      }
      else if (iVar3 < iVar1 + *(int *)(param_1 + 0x10)) {
        *(int *)((iVar3 - iVar1) * 0x30 + 0x2c + *(int *)(param_1 + 0x14)) = iVar2;
      }
      else {
        *(int *)(*(int *)(param_1 + 0x1c) + 0x44 +
                ((iVar3 - iVar1) - *(int *)(param_1 + 0x10)) * 0x48) = iVar2;
      }
      iVar2 = iVar2 + aiStack_400[iVar3];
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  return;
}


