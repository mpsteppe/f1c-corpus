// Function: FUN_005503a0 @ 005503a0
// Size (bytes): 283


undefined4 __fastcall FUN_005503a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_4;
  
  for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    if ((*(uint *)(iVar1 + 0x14) & 0x80000) != 0) {
      local_4 = *(int *)(iVar1 + 0x118);
      if (local_4 != 0) {
        piVar7 = (int *)(*(int *)(iVar1 + 0x11c) + 0x34);
        do {
          iVar5 = 0;
          if (0 < *(int *)(piVar7[-0xc] + 0xa4)) {
            piVar6 = (int *)(*(int *)(piVar7[-0xc] + 0xa8) + 0x50);
            do {
              if (1 < piVar6[-2]) {
                iVar3 = *piVar7;
                iVar2 = *piVar6;
                if ((iVar3 < iVar2) && ((*(byte *)(piVar6 + -4) & 4) != 0)) {
                  iVar4 = iVar3;
                  switch(piVar6[1] & 0xffff000f) {
                  case 1:
                    iVar4 = iVar3 + 1;
                    if (iVar2 <= iVar4) {
                      iVar4 = iVar2 - iVar4;
                    }
                    break;
                  case 2:
                    if (iVar3 < iVar2 + -1) {
                      iVar3 = iVar3 + 1;
                    }
                    iVar4 = iVar3;
                    if (iVar2 <= iVar3) {
                      iVar4 = iVar2 + -1;
                    }
                    break;
                  case 3:
                    if (iVar3 == iVar2 + -1) {
                      iVar3 = -iVar3;
                    }
                    iVar4 = iVar3 + 1;
                    break;
                  case 4:
                    iVar4 = iVar3 + 1;
                    if (iVar2 <= iVar3 + 1) {
                      FUN_0054c030(0,0,1,0);
                      iVar4 = -1;
                    }
                  }
                  *piVar7 = iVar4;
                }
              }
              piVar6 = piVar6 + 0x25;
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(int *)(piVar7[-0xc] + 0xa4));
          }
          piVar7 = piVar7 + 0x10;
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
    }
  }
  return 0;
}


