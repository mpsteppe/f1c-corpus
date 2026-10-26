// Function: FUN_0055c7f0 @ 0055c7f0
// Size (bytes): 98


undefined4 __thiscall FUN_0055c7f0(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_8;
  undefined1 local_4 [4];
  
  FUN_0055c650(&local_8,*(undefined4 *)(param_1 + 0x1544),0);
  FUN_0055c450(local_8,&local_8,local_4);
  if (param_2 == 0x200000) {
    if (local_8 == 0x20) {
      uVar1 = FUN_0055c7d0();
      return uVar1;
    }
    if (local_8 == 0x10) {
      uVar1 = FUN_0055c7b0();
      return uVar1;
    }
  }
  return 0xffffffff;
}


