// Function: FUN_0044f070 @ 0044f070
// Size (bytes): 36


void __thiscall FUN_0044f070(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x27c);
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    puVar2 = puVar2 + 1;
  }
  return;
}


