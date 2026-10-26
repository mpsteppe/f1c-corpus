// Function: FUN_00587d02 @ 00587d02
// Size (bytes): 49


undefined4 FUN_00587d02(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((*(byte *)(param_1 + 0xc) & 0x40) == 0) {
    FUN_0058c1b1(param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_0058c203(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return uVar1;
}


