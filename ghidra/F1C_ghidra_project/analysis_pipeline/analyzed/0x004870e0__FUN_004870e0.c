// Function: FUN_004870e0 @ 004870e0
// Size (bytes): 120


int __thiscall FUN_004870e0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 4);
  local_4 = param_1;
  iVar3 = FUN_0049adb0();
  if (param_2 < iVar3) {
    cVar2 = FUN_0049aec0(param_2,(int)&local_4 + 2,&local_4);
    if (cVar2 != '\0') {
      return (short)local_4 + iVar1;
    }
  }
  else if (*(int *)(param_1 + 200) != 0) {
    cVar2 = FUN_0049aec0(param_2,(int)&local_4 + 2,&local_4);
    if (cVar2 != '\0') {
      return (short)local_4 + iVar1;
    }
  }
  return -1;
}


