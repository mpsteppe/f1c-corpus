// Function: FUN_0042aeb0 @ 0042aeb0
// Size (bytes): 47


undefined4 __thiscall FUN_0042aeb0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x4144);
  do {
    if (*piVar2 == param_2) {
      return *(undefined4 *)(param_1 + 0x4148 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 5);
  return 0xffffffff;
}


