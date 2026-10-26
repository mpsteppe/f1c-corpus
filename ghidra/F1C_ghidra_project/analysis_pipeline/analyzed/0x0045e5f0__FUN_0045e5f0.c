// Function: FUN_0045e5f0 @ 0045e5f0
// Size (bytes): 39


uint __thiscall FUN_0045e5f0(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = (int *)(param_1 + 0x3e18);
  do {
    if (*piVar2 == param_2) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 1;
  } while ((int)uVar1 < 0x68);
  return uVar1 & 0xffffff00;
}


