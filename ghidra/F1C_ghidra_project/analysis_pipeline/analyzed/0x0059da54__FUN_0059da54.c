// Function: FUN_0059da54 @ 0059da54
// Size (bytes): 99


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059da54(void)

{
  double dVar1;
  double *pdVar2;
  int unaff_EBX;
  int unaff_ESI;
  double in_stack_00000010;
  
  pdVar2 = (double *)(unaff_EBX + 0x1ec0);
  do {
    if (unaff_ESI == 8) {
      pdVar2 = (double *)(DAT_005c7530 + 0x40);
      dVar1 = *pdVar2 / _DAT_007c9310;
    }
    else {
      dVar1 = *pdVar2 / pdVar2[-1];
    }
    dVar1 = dVar1 * *(double *)(unaff_EBX + 0x1c94) * _DAT_0059ec18;
    if (dVar1 < in_stack_00000010) {
      dVar1 = in_stack_00000010;
    }
    if (unaff_ESI < 8) {
      *(double *)((int)pdVar2 + -0x214) = dVar1;
    }
    else {
      pdVar2[-8] = dVar1;
    }
    unaff_ESI = unaff_ESI + 1;
    pdVar2 = pdVar2 + 1;
  } while (unaff_ESI <= *(int *)(unaff_EBX + 0x1eac));
  FUN_0043d8de();
  return;
}


