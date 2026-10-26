// Function: FUN_004db550 @ 004db550
// Size (bytes): 118


void FUN_004db550(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (DAT_007d0474 == '\0') {
    iVar1 = FUN_0049b950();
  }
  else {
    iVar1 = FUN_0049b900();
  }
  uVar4 = 0x14;
  uVar3 = param_1;
  uVar2 = FUN_0049b8f0(param_1,0x14);
  FUN_004db6f0(uVar2,uVar3,uVar4);
  FUN_004db9a0((float)iVar1,param_1,0x44);
  uVar2 = 10;
  uVar3 = FUN_0049b7a0(param_1,10);
  FUN_004db7f0(uVar3,param_1,uVar2);
  return;
}


