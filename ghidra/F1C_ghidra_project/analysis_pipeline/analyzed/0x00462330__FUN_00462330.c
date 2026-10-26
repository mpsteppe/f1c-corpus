// Function: FUN_00462330 @ 00462330
// Size (bytes): 50


int __fastcall FUN_00462330(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = FUN_0057a810();
  iVar2 = 0;
  piVar3 = (int *)(*param_1 + 0x3e18);
  do {
    if (*piVar3 == iVar1) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 0x68);
  return -1;
}


