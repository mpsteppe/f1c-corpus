// Function: FUN_004db7f0 @ 004db7f0
// Size (bytes): 430


void FUN_004db7f0(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = (-(uint)((param_1 & 1) != 0) & 0xffbcbabc) + 0x444444;
  iVar6 = (-(uint)((param_1 & 2) != 0) & 0xbbbabc) + 0x444444;
  iVar5 = (-(uint)((param_1 & 4) != 0) & 0xbb87bc) + 0x444444;
  iVar3 = (-(uint)((param_1 & 8) != 0) & 0xbabbbc) + 0x444444;
  FUN_0058815f(&param_1,&DAT_005ccef0,(int)DAT_005d4ae9);
  uVar2 = param_3;
  iVar1 = param_2;
  FUN_004d7e40(&param_1,param_2 + -0xa3,param_3,iVar4,0,3,0x3f800000,0x3f800000);
  FUN_004d7e40(&param_1,iVar1 + 0xa3,uVar2,iVar4,1,3,0x3f800000,0x3f800000);
  FUN_004d7e40(&param_1,iVar1 + -0x88,uVar2,iVar6,0,3,0x3f800000,0x3f800000);
  FUN_004d7e40(&param_1,iVar1 + 0x88,uVar2,iVar6,1,3,0x3f800000,0x3f800000);
  FUN_004d7e40(&param_1,iVar1 + -0x6d,uVar2,iVar5,0,3,0x3f800000,0x3f800000);
  FUN_004d7e40(&param_1,iVar1 + 0x6d,uVar2,iVar5,1,3,0x3f800000,0x3f800000);
  FUN_004d7e40(&param_1,iVar1 + -0x52,uVar2,iVar3,0,3,0x3f800000,0x3f800000);
  FUN_004d7e40(&param_1,iVar1 + 0x52,uVar2,iVar3,1,3,0x3f800000,0x3f800000);
  return;
}


