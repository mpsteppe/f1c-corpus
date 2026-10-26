// Function: FUN_00494e60 @ 00494e60
// Size (bytes): 157


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494e60(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (DAT_007cddf0 != (int *)0x0) {
    iVar1 = *DAT_007cddf0;
    DAT_007cddf8 = DAT_007cddf0;
    while (((piVar3 = DAT_007cddf0, piVar2 = DAT_007cddf8, iVar1 != 0 &&
            (FUN_0053d130(iVar1), piVar3 = DAT_007cddf0, piVar2 = (int *)0x0,
            DAT_007cddf8 != (int *)0x0)) &&
           (DAT_007cddf8 = (int *)DAT_007cddf8[1], piVar2 = DAT_007cddf8, DAT_007cddf8 != (int *)0x0
           ))) {
      iVar1 = *DAT_007cddf8;
    }
    while (DAT_007cddf8 = piVar2, piVar3 != (int *)0x0) {
      piVar2 = (int *)piVar3[1];
      if (((char)piVar3[2] != '\0') && (iVar1 = *piVar3, iVar1 != 0)) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar2;
      piVar2 = DAT_007cddf8;
    }
  }
  DAT_007cddf0 = (int *)0x0;
  DAT_007cddf4 = 0;
  DAT_007cddf8 = (int *)0x0;
  _DAT_007cddfc = 0;
  return;
}


