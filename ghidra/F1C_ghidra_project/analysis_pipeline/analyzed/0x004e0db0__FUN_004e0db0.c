// Function: FUN_004e0db0 @ 004e0db0
// Size (bytes): 105


void __fastcall FUN_004e0db0(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_004e0d00(param_1 + 0x5e4);
  FUN_004e0d00(param_1 + 0x628);
  iVar2 = param_1 + 0x188;
  iVar1 = 4;
  do {
    FUN_004e0d00(iVar2 + -0x44);
    FUN_004e0d00(iVar2);
    iVar2 = iVar2 + 0x128;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  param_1 = param_1 + 0x66c;
  iVar2 = 8;
  do {
    FUN_004e0d00(param_1);
    param_1 = param_1 + 0x44;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


