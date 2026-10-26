// Function: FUN_004dbe60 @ 004dbe60
// Size (bytes): 292


void FUN_004dbe60(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_40 [64];
  
  bVar1 = DAT_008acf8c != 0x7fffffff;
  if (bVar1) {
    FUN_0049c670(local_40,0x40);
    uVar6 = 0x3f400000;
    uVar5 = 2;
    uVar4 = 0xffff00;
    uVar3 = 0x2e;
    iVar2 = param_1 + 0xd7;
  }
  else {
    FUN_0049c8f0(local_40,0x40);
    iVar2 = param_1 + 0x32;
    FUN_004d7e40(local_40,iVar2,10,0xffffff,1,2,0x3f800000,0x3f800000);
    FUN_0049c960(local_40,0x40);
    uVar6 = 0x3f800000;
    uVar5 = 0;
    uVar4 = 0xffffff;
    uVar3 = 10;
  }
  FUN_004d7e40(local_40,iVar2,uVar3,uVar4,uVar5,!bVar1,uVar6,0x3f800000);
  FUN_0049c700(local_40,0x40);
  FUN_004d7e40(local_40,param_1 + 0x32,0x32,0xffffff,1,2,0x3f800000,0x3f800000);
  FUN_0049c770(local_40,0x40);
  FUN_004d7e40(local_40,param_1 + 0x32,0x32,0xffffff,0,1,0x3f800000,0x3f800000);
  return;
}


