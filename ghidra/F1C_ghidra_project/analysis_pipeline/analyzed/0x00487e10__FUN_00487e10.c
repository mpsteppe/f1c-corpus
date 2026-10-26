// Function: FUN_00487e10 @ 00487e10
// Size (bytes): 83


undefined4 __fastcall FUN_00487e10(int *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = FUN_004874e0();
  if (iVar1 != 0) {
    FUN_00487260(1);
    FUN_00487460();
    puVar2 = (uint *)(**(code **)(*param_1 + 0xac))();
    if (puVar2 != (uint *)0x0) {
      *puVar2 = (uint)(*puVar2 == 0);
    }
    iVar1 = (**(code **)(*param_1 + 0x98))();
    if (iVar1 == 0) {
      FUN_00486600();
      return 0;
    }
  }
  return 0xffffffff;
}


