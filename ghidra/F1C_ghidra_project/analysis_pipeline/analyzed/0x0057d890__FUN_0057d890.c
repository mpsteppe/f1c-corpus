// Function: FUN_0057d890 @ 0057d890
// Size (bytes): 60


uint FUN_0057d890(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_00585770();
  uVar2 = FUN_005871f0();
  if ((uVar2 != uVar1) && (*(int *)(param_2 + 0x1c) != 0)) {
    uVar3 = FUN_004b3db0();
    uVar2 = FUN_0057d6c0(param_1,uVar3);
  }
  return uVar2 & 0xffffff00;
}


