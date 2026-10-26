// Function: FUN_004b0930 @ 004b0930
// Size (bytes): 102


undefined4 FUN_004b0930(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_100;
  undefined4 local_ff;
  
  FUN_004b0e30();
  local_100 = DAT_005ea438;
  puVar2 = &local_ff;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  FUN_004b02b0(&local_100,0x100);
  FUN_0058ba36(&local_100,0x180);
  FUN_004c2700(&local_100);
  return 0;
}


