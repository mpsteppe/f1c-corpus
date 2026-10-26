// Function: FUN_00460c30 @ 00460c30
// Size (bytes): 37


int __thiscall FUN_00460c30(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x3e18);
  do {
    if (param_2 == *piVar2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x68);
  return 0x3f;
}


