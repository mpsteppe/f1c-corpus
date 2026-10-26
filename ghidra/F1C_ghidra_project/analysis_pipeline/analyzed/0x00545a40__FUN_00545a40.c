// Function: FUN_00545a40 @ 00545a40
// Size (bytes): 330


undefined4 __fastcall FUN_00545a40(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  if (0 < *(int *)(param_1 + 0x13c)) {
    iVar6 = *(int *)(param_1 + 0x140);
    if (iVar6 != 0) {
      iVar7 = *(int *)(iVar6 + -4);
      if (-1 < iVar7 + -1) {
        do {
          FUN_004b0170();
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      FUN_00587bcf(iVar6 + -4);
    }
    iVar6 = *(int *)(param_1 + 0x13c);
    piVar2 = operator_new(iVar6 * 0x18 + 4);
    if (piVar2 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = piVar2 + 1;
      *piVar2 = iVar6;
      if (-1 < iVar6 + -1) {
        do {
          FUN_00548e00();
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
    iVar7 = 0;
    iVar6 = *(int *)(param_1 + 0x100);
    *(int **)(param_1 + 0x140) = piVar5;
    for (; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x104)) {
      if (((*(byte *)(iVar6 + 4) & 0x40) == 0) && (iVar3 = *(int *)(iVar6 + 0xec), iVar3 != 0)) {
        iVar4 = iVar7 * 0x18;
        do {
          for (iVar1 = *(int *)(iVar3 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
            if ((*(uint *)(iVar1 + 0x14) & 0x4000) != 0) {
              *(int *)(iVar4 + 0x10 + *(int *)(param_1 + 0x140)) = iVar3;
              iVar7 = iVar7 + 1;
              iVar4 = iVar4 + 0x18;
              break;
            }
          }
          iVar3 = *(int *)(iVar3 + 0x4c);
        } while (iVar3 != 0);
      }
    }
    iVar6 = *(int *)(param_1 + 0x108);
    if (iVar6 != 0) {
      iVar7 = iVar7 * 0x18;
      do {
        for (iVar3 = *(int *)(iVar6 + 0x204); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {
          if ((*(uint *)(iVar3 + 0x14) & 0x4000) != 0) {
            *(int *)(iVar7 + 0x10 + *(int *)(param_1 + 0x140)) = iVar6;
            iVar7 = iVar7 + 0x18;
            break;
          }
        }
        iVar6 = *(int *)(iVar6 + 0x4c);
      } while (iVar6 != 0);
    }
  }
  return 0;
}


