// Function: FUN_004189f0 @ 004189f0
// Size (bytes): 39


undefined1 __thiscall FUN_004189f0(int param_1,int param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int *extraout_ECX;
  int iVar3;
  int extraout_EDX;
  
  uVar1 = 0;
  piVar2 = (int *)(param_1 + 0x864);
  iVar3 = 0x14;
  do {
    if (*piVar2 == param_2) {
      FUN_004144d0();
      uVar1 = 1;
      piVar2 = extraout_ECX;
      iVar3 = extraout_EDX;
    }
    piVar2 = piVar2 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return uVar1;
}


