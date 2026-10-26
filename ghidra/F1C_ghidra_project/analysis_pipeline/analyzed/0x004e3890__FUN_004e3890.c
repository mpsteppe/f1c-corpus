// Function: FUN_004e3890 @ 004e3890
// Size (bytes): 62


void __fastcall FUN_004e3890(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xba8)) {
    iVar1 = param_1 + 0xbac;
    do {
      FUN_004df110(0,0xffffffff);
      *(undefined4 *)(iVar1 + 0x18) = 0;
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x2ec;
    } while (iVar2 < *(int *)(param_1 + 0xba8));
  }
  return;
}


