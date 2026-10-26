// Function: FUN_0044bc10 @ 0044bc10
// Size (bytes): 64


uint FUN_0044bc10(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 3) {
    return (uint)(0 < param_1);
  }
  iVar1 = FUN_0044bc10(param_1 - param_1 / 2);
  iVar2 = FUN_0044bc10(param_1 / 2);
  return iVar1 + 1 + iVar2;
}


