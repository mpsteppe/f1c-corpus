// Function: FUN_0044f5f0 @ 0044f5f0
// Size (bytes): 68


void __fastcall FUN_0044f5f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  SetCursor((HCURSOR)0x0);
  puVar1 = (undefined4 *)(param_1 + 0x30);
  iVar2 = 6;
  do {
    if ((HCURSOR)*puVar1 != (HCURSOR)0x0) {
      DestroyCursor((HCURSOR)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0xa8) = 0;
  return;
}


