// Function: FUN_004be4e0 @ 004be4e0
// Size (bytes): 412


void __thiscall FUN_004be4e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  bVar1 = false;
  iVar2 = __ftol();
  if (iVar2 < 0) {
    iVar2 = 0;
LAB_004be51c:
    bVar1 = true;
  }
  else if (7 < iVar2) {
    iVar2 = 7;
    goto LAB_004be51c;
  }
  iVar3 = __ftol();
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_004be54d:
    bVar1 = true;
  }
  else if (7 < iVar3) {
    iVar3 = 7;
    goto LAB_004be54d;
  }
  local_8 = __ftol();
  if (local_8 < 0) {
    local_8 = 0;
LAB_004be589:
    bVar1 = true;
  }
  else if (7 < local_8) {
    local_8 = 7;
    goto LAB_004be589;
  }
  local_c = __ftol();
  if (local_c < 0) {
    local_c = 0;
  }
  else {
    if (local_c < 8) goto LAB_004be5d0;
    local_c = 7;
  }
  bVar1 = true;
LAB_004be5d0:
  if (iVar2 <= iVar3) {
    local_4 = (iVar3 - iVar2) + 1;
    do {
      if (local_8 <= local_c) {
        iVar2 = (local_c - local_8) + 1;
        do {
          FUN_004bdb10(*(undefined4 *)(param_1 + 0x934),param_2,param_3,param_4);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  iVar2 = *(int *)(param_1 + 0x934);
  if (bVar1) {
    FUN_004bdb10(iVar2,param_2,param_3,param_4);
    iVar2 = *(int *)(param_1 + 0x934);
  }
  *(int *)(param_1 + 0x934) = iVar2 + 1;
  return;
}


