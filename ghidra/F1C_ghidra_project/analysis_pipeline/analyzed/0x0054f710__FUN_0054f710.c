// Function: FUN_0054f710 @ 0054f710
// Size (bytes): 130


int __fastcall FUN_0054f710(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_4;
  
  iVar1 = 0;
  piVar2 = *(int **)(*(int *)(param_1 + 0x1e0) + 8);
  local_4 = 0;
  if (*(int *)(*(int *)(param_1 + 0x1e0) + 4) < 1) {
    return 0;
  }
  do {
    if (*piVar2 == 2) {
      local_4 = local_4 + 1;
    }
    else {
      (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,piVar2 + 1,piVar2 + 4,param_1 + 0x114);
      (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,piVar2 + 7,piVar2 + 10,param_1 + 0x114);
    }
    piVar2 = piVar2 + 0x1d;
    iVar1 = iVar1 + 1;
  } while (iVar1 < *(int *)(*(int *)(param_1 + 0x1e0) + 4));
  return local_4;
}


