// Function: FUN_004f2320 @ 004f2320
// Size (bytes): 98


void __fastcall FUN_004f2320(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x34ec) = 0;
  *(undefined4 *)(param_1 + 0x34f0) = 0;
  *(undefined4 *)(param_1 + 0x34f4) = 0;
  *(undefined4 *)(param_1 + 0x34f8) = 0;
  *(undefined4 *)(param_1 + 0x34fc) = 0;
  *(undefined4 *)(param_1 + 0x3500) = 0;
  *(undefined4 *)(param_1 + 0x3504) = 0;
  *(undefined4 *)(param_1 + 0x3508) = 0;
  *(undefined4 *)(param_1 + 0x350c) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x35b0);
  iVar2 = 4;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x3e;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(int *)(param_1 + 0x32bc) == 0) {
    FUN_0043e360();
    return;
  }
  return;
}


