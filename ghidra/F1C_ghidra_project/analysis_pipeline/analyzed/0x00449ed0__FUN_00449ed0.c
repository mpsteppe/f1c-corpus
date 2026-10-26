// Function: FUN_00449ed0 @ 00449ed0
// Size (bytes): 143


void FUN_00449ed0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_38 [10];
  int local_10;
  undefined2 local_c;
  
  iVar2 = 0;
  piVar3 = (int *)(param_1 + 4);
  do {
    iVar1 = *piVar3;
    local_38[iVar2 * 2 + 3] = *(int *)(iVar1 + 0x10);
    local_38[iVar2 * 2 + 4] = *(int *)(iVar1 + 0x14);
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 2;
  } while (iVar2 < 3);
  iVar2 = 0;
  do {
    local_38[iVar2] = *(int *)(*(int *)(param_1 + iVar2 * 8) + 0x48);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  local_38[9] = local_38[1] * 0x200000 + local_38[0];
  local_10 = (local_38[1] >> 0xb) + local_38[2] * 0x400;
  local_c = *(undefined2 *)(param_1 + 0x1a);
  FUN_00566bd0(local_38 + 3,0x22);
  FUN_00449a80(param_1,1);
  return;
}


