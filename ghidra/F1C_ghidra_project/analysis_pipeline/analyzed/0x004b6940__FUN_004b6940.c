// Function: FUN_004b6940 @ 004b6940
// Size (bytes): 91


void __thiscall FUN_004b6940(int param_1,undefined4 param_2)

{
  char cVar1;
  
  FUN_004b7860(0);
  cVar1 = FUN_004b69f0();
  if (cVar1 == '\0') {
    FUN_004b69a0();
  }
  else {
    *(undefined4 *)(param_1 + 0x9bc) = 0;
    *(undefined4 *)(param_1 + 0x9b8) = 0;
    FUN_004b4e10();
  }
  *(undefined4 *)(*(int *)(param_1 + 0x9b8) * 0xb0 + 0x6c + *(int *)(param_1 + 0x9b0)) = param_2;
  return;
}


