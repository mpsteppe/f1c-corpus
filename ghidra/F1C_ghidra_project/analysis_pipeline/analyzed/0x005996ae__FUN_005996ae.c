// Function: FUN_005996ae @ 005996ae
// Size (bytes): 89


void FUN_005996ae(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int unaff_EBP;
  int unaff_ESI;
  uint unaff_EDI;
  
  uVar2 = *(uint *)(unaff_ESI + 8);
  if (uVar2 != 0) {
    if (unaff_EDI < uVar2) {
      uVar2 = unaff_EDI;
    }
    FUN_0058cc00(*(int *)(unaff_EBP + 8) + 1,*(undefined4 *)(unaff_ESI + 4),uVar2);
  }
  uVar2 = *(uint *)(unaff_ESI + 8);
  FUN_005993af(1);
  puVar1 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_ESI + 4) = puVar1 + 1;
  *puVar1 = 0;
  *(uint *)(unaff_ESI + 0xc) = unaff_EDI;
  if (uVar2 <= unaff_EDI) {
    unaff_EDI = uVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(uint *)(unaff_ESI + 8) = unaff_EDI;
  *(undefined1 *)(*(int *)(unaff_ESI + 4) + unaff_EDI) = 0;
  return;
}


