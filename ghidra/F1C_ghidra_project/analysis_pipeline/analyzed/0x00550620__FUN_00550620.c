// Function: FUN_00550620 @ 00550620
// Size (bytes): 118


void __thiscall FUN_00550620(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if (((param_2 != 0) && (param_3 <= *(int *)(param_2 + 0xa4))) &&
     (iVar1 = *(int *)(param_2 + 0xa8) + param_3 * 0x94, 1 < *(int *)(iVar1 + 0x48))) {
    for (iVar2 = *(int *)(param_1 + 0x204); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
      iVar6 = *(int *)(iVar2 + 0x118);
      if (iVar6 != 0) {
        piVar4 = (int *)(*(int *)(iVar2 + 0x11c) + 0x34);
        do {
          if (piVar4[-0xc] == param_2) {
            iVar5 = *piVar4;
            iVar3 = *(int *)(iVar1 + 0x50);
            if (iVar5 < iVar3) {
              iVar5 = iVar5 + iVar3;
            }
            *piVar4 = iVar5;
          }
          piVar4 = piVar4 + 0x10;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
  }
  return;
}


