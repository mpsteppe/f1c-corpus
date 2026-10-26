// Function: FUN_0055c3c0 @ 0055c3c0
// Size (bytes): 126


undefined4 __thiscall FUN_0055c3c0(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 local_20 [28];
  undefined4 uStack_4;
  
  if ((param_2[6] & 1U) == 0) {
    if ((param_2[6] & 2U) != 0) {
      param_2 = (int *)param_2[3];
    }
  }
  else {
    param_2 = (int *)param_2[2];
  }
  iVar1 = (**(code **)(*param_2 + 0x20))(param_2);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 0xff;
  }
  if (&stack0x00000000 != (undefined1 *)0x36) {
    FUN_0055c450(local_20,0,&uStack_4);
    return uStack_4;
  }
  FUN_0055c450(0x15,0,0x32);
  return uStack_4;
}


