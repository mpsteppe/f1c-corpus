// Function: FUN_0056d880 @ 0056d880
// Size (bytes): 104


void __thiscall FUN_0056d880(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_c;
  
  iVar4 = 0;
  if (0 < param_3) {
    local_c = param_3;
    piVar3 = param_2;
    do {
      iVar2 = 0;
      do {
        iVar1 = *piVar3;
        *(undefined4 *)(iVar1 + iVar2 * 8) = 0;
        *(undefined4 *)(iVar1 + 4 + iVar2 * 8) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3);
      piVar3 = piVar3 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  if (0 < *param_1) {
    do {
      FUN_00568fb0(param_2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *param_1);
  }
  return;
}


