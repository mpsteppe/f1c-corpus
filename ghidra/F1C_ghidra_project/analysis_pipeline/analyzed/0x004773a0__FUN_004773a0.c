// Function: FUN_004773a0 @ 004773a0
// Size (bytes): 101


undefined4 __thiscall FUN_004773a0(int param_1,int param_2)

{
  char cVar1;
  int local_8;
  uint local_4;
  
  FUN_00498880(&local_8,&local_4);
  if ((((param_2 != 0) && (*(int *)(param_1 + 0x120) < local_8)) &&
      (local_8 < *(int *)(param_1 + 0x124))) &&
     ((*(int *)(param_1 + 0x140) < (int)local_4 && ((int)local_4 < *(int *)(param_1 + 0x144))))) {
    cVar1 = FUN_0048ea60(local_8,local_4);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


