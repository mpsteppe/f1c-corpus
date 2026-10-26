// Function: FUN_0046e7f0 @ 0046e7f0
// Size (bytes): 82


void __fastcall FUN_0046e7f0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_004328f0();
  while (cVar1 == '\0') {
    FUN_00432a10();
    cVar1 = FUN_004328f0();
  }
  if (*(int *)(param_1 + 0x168) != 0) {
    uVar2 = FUN_00489920();
    FUN_00432980(uVar2);
    return;
  }
  FUN_00432180();
  return;
}


