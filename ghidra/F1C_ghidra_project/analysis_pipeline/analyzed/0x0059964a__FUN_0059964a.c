// Function: FUN_0059964a @ 0059964a
// Size (bytes): 63


void FUN_0059964a(void)

{
  void *pvVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  uint uVar2;
  
  FUN_0058a5d8();
  uVar2 = *(uint *)(unaff_EBP + 8) | 0x1f;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  if (0xfffffffd < uVar2) {
    uVar2 = *(uint *)(unaff_EBP + 8);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = uVar2 + 2;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  pvVar1 = operator_new(uVar2);
  *(void **)(unaff_EBP + 8) = pvVar1;
  FUN_005996ae();
  return;
}


