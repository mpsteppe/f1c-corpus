// Function: FUN_0042ebc0 @ 0042ebc0
// Size (bytes): 60


void __fastcall FUN_0042ebc0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(param_1 + 200);
  iVar3 = 4;
  do {
    iVar2 = 0xb;
    do {
      *puVar1 = puVar1[-1];
      puVar1 = puVar1 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar1 = (undefined4 *)(param_1 + 0xbc8);
  iVar3 = 0x37;
  do {
    *puVar1 = puVar1[-1];
    puVar1 = puVar1 + 0x10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


