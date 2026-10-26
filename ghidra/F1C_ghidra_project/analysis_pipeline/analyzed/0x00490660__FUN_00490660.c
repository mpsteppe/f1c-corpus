// Function: FUN_00490660 @ 00490660
// Size (bytes): 118


void __fastcall FUN_00490660(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4;
  
  local_4 = 0;
  iVar2 = FUN_00486720();
  if ((2 < iVar2) && (iVar2 < 6)) {
    local_4 = 1;
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xec)) {
    do {
      if ((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0xec))) {
        piVar1 = *(int **)(param_1 + 0xe0);
        for (iVar3 = iVar2; 0 < iVar3; iVar3 = iVar3 + -1) {
          if (piVar1 == (int *)0x0) goto LAB_004906c6;
          piVar1 = (int *)piVar1[1];
        }
        if ((piVar1 != (int *)0x0) && ((int *)*piVar1 != (int *)0x0)) {
          (**(code **)(*(int *)*piVar1 + 0x10))(local_4);
        }
      }
LAB_004906c6:
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0xec));
  }
  return;
}


