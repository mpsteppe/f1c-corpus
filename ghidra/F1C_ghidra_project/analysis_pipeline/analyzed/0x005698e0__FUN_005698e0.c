// Function: FUN_005698e0 @ 005698e0
// Size (bytes): 166


int __thiscall
FUN_005698e0(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5
            )

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) * 0x84 + *(int *)(param_1 + 0x238);
  *(int *)(param_1 + 0x234) = *(int *)(param_1 + 0x234) + 1;
  *(undefined4 *)(iVar1 + 0x78) = param_5;
  *(undefined4 *)(iVar1 + 0x7c) = param_3;
  *(undefined1 *)(iVar1 + 0x80) = param_4;
  FUN_0056c3a0(iVar1 + 0x18,iVar1 + 0x30);
  return iVar1;
}


