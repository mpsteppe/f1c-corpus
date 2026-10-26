// Function: FUN_004e1970 @ 004e1970
// Size (bytes): 39


void __fastcall FUN_004e1970(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = (undefined4 *)(param_1 + 0xb70);
  do {
    uVar1 = FUN_004e18c0(iVar2);
    *puVar3 = uVar1;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 0xe);
  return;
}


