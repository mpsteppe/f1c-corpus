// Function: FUN_004bdfe0 @ 004bdfe0
// Size (bytes): 48


void __fastcall FUN_004bdfe0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  iVar3 = 8;
  do {
    iVar2 = 8;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 9;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(param_1 + 0x904) = 0;
  return;
}


