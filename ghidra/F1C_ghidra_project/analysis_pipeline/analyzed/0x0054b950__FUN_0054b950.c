// Function: FUN_0054b950 @ 0054b950
// Size (bytes): 143


void __thiscall
FUN_0054b950(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x204);
  if ((*(uint *)(iVar1 + 0x14) & 0x20000000) == 0) {
    (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,iVar1 + 0xdc,iVar1 + 0xe8,param_1 + 0x1a0);
    *(uint *)(*(int *)(param_1 + 0x204) + 0x14) =
         *(uint *)(*(int *)(param_1 + 0x204) + 0x14) | 0x20000000;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x204) + 0xe8);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x204) + 0xec);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x204) + 0xf0);
  }
  return;
}


