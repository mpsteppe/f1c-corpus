// Function: FUN_00462d30 @ 00462d30
// Size (bytes): 97


undefined4 FUN_00462d30(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0057a900();
  if (iVar1 == 0) {
    iVar1 = FUN_0057a590(param_1);
    if (iVar1 != 0) {
      if (iVar1 == 2) {
        return 1;
      }
      if (iVar1 != 3) {
        if (iVar1 != 5) {
          return 3;
        }
        return 4;
      }
      return 2;
    }
  }
  return 0;
}


