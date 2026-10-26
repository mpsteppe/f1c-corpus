// Function: FUN_004a57a0 @ 004a57a0
// Size (bytes): 69


void __thiscall FUN_004a57a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 2) {
    FUN_004a57f0();
  }
  iVar1 = param_2 * 0x40 + param_1;
  iVar2 = *(int *)(param_2 * 0x40 + 0x2c + param_1) + -1;
  *(int *)(iVar1 + 0x2c) = iVar2;
  if (iVar2 < 0) {
    if (*(char *)(iVar1 + 0x35) == '\0') {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x28) + -1;
    }
    *(int *)(iVar1 + 0x2c) = iVar2;
  }
  if (param_2 == 0) {
    FUN_004a55e0();
  }
  return;
}


