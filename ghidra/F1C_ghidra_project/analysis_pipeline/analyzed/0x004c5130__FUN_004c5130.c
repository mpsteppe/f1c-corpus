// Function: FUN_004c5130 @ 004c5130
// Size (bytes): 66


undefined4 __fastcall FUN_004c5130(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if ((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0x14))) {
    piVar1 = *(int **)(param_1 + 8);
    for (; 0 < iVar2; iVar2 = iVar2 + -1) {
      if (piVar1 == (int *)0x0) goto LAB_004c515c;
      piVar1 = (int *)piVar1[1];
    }
    if ((piVar1 != (int *)0x0) && ((undefined4 *)*piVar1 != (undefined4 *)0x0)) {
      return *(undefined4 *)*piVar1;
    }
  }
LAB_004c515c:
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(param_1 + 0x10) = piVar1;
  if ((piVar1 != (int *)0x0) && ((undefined4 *)*piVar1 != (undefined4 *)0x0)) {
    return *(undefined4 *)*piVar1;
  }
  return 0;
}


