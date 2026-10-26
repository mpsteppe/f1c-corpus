// Function: FUN_00487160 @ 00487160
// Size (bytes): 122


undefined4 __thiscall FUN_00487160(int param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 local_4;
  
  local_4 = param_1;
  iVar2 = FUN_0049adb0();
  if (((param_2 < iVar2) || (*(int *)(param_1 + 200) != 0)) &&
     (cVar1 = FUN_0049aec0(param_2,&local_4,(int)&local_4 + 2), cVar1 != '\0')) {
    *param_3 = (int)(short)local_4 + *(int *)(param_1 + 0xc);
    *param_4 = (int)local_4._2_2_ + *(int *)(param_1 + 4);
    return 1;
  }
  return 0;
}


