// Function: FUN_004b1375 @ 004b1375
// Size (bytes): 145


void FUN_004b1375(void)

{
  int in_EAX;
  undefined4 uVar1;
  int unaff_ESI;
  
  if (in_EAX != 0) {
    uVar1 = FUN_00567970();
    uVar1 = FUN_00587ece(uVar1);
    *(undefined4 *)(unaff_ESI + 0x2204) = uVar1;
    if (*(int *)(unaff_ESI + 0x2204) < *(int *)(unaff_ESI + 0x220c)) {
      *(int *)(unaff_ESI + 0x2204) = *(int *)(unaff_ESI + 0x220c);
    }
    else if (*(int *)(unaff_ESI + 0x2210) < *(int *)(unaff_ESI + 0x2204)) {
      *(int *)(unaff_ESI + 0x2204) = *(int *)(unaff_ESI + 0x2210);
    }
    uVar1 = __ftol();
    *(undefined4 *)(unaff_ESI + 0x2204) = uVar1;
    if (*(int *)(unaff_ESI + 0x2204) < *(int *)(unaff_ESI + 0x220c)) {
      *(int *)(unaff_ESI + 0x2204) = *(int *)(unaff_ESI + 0x220c);
      return;
    }
    if (*(int *)(unaff_ESI + 0x2210) < *(int *)(unaff_ESI + 0x2204)) {
      *(int *)(unaff_ESI + 0x2204) = *(int *)(unaff_ESI + 0x2210);
    }
  }
  return;
}


