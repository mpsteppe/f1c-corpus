// Function: FUN_00415730 @ 00415730
// Size (bytes): 73


void FUN_00415730(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00415700();
  FUN_004c3f80(param_1);
  iVar1 = FUN_004c4080();
  if (iVar1 != 0) {
    uVar2 = FUN_00415230(iVar1 + 0xbc,param_1);
    iVar1 = FUN_00415650(uVar2);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0xc) = 1;
    }
  }
  return;
}


