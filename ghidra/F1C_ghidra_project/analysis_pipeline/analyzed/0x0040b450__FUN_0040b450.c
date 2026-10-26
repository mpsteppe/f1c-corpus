// Function: FUN_0040b450 @ 0040b450
// Size (bytes): 59


uint __thiscall FUN_0040b450(int *param_1,int param_2,char param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined3 extraout_var;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = FUN_0040ad60(param_2);
    if (-1 < (int)uVar1) {
      uVar2 = FUN_0040ad90(uVar1);
      uVar3 = (undefined3)((uint)uVar2 >> 8);
      if (param_3 != '\0') {
        (**(code **)(*param_1 + 0x10))();
        uVar3 = extraout_var;
      }
      return CONCAT31(uVar3,1);
    }
  }
  return uVar1 & 0xffffff00;
}


