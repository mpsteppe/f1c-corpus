// Function: FUN_0049e410 @ 0049e410
// Size (bytes): 121


void __thiscall FUN_0049e410(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_10 [16];
  
  FUN_0049bb40(local_10,0xf);
  FUN_0049f6a0(local_10,param_2,param_4,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
  FUN_0049bbb0(local_10,0xf);
  FUN_0049f6a0(local_10,param_3,param_4,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
  return;
}


