// Function: FUN_0051aec2 @ 0051aec2
// Size (bytes): 58


void FUN_0051aec2(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x58);
  *(undefined4 **)(param_1 + 0x194) = puVar1;
  iVar2 = 4;
  *puVar1 = FUN_0051ad93;
  puVar1[1] = FUN_0051a9c6;
  puVar1 = puVar1 + 0xd;
  do {
    puVar1[4] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


