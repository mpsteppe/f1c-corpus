// Function: FUN_00415700 @ 00415700
// Size (bytes): 44


void __fastcall FUN_00415700(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  param_1[2] = (int)piVar1;
  if ((piVar1 != (int *)0x0) && (iVar2 = *piVar1, iVar2 != 0)) {
    while( true ) {
      *(undefined1 *)(iVar2 + 0xc) = 0;
      if (param_1[2] == 0) break;
      piVar1 = *(int **)(param_1[2] + 4);
      param_1[2] = (int)piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
      iVar2 = *piVar1;
      if (iVar2 == 0) {
        return;
      }
    }
  }
  return;
}


