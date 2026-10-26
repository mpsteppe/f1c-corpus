// Function: FUN_004972b0 @ 004972b0
// Size (bytes): 279


void FUN_004972b0(uint param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = param_5;
  param_5 = param_5 - param_4;
  iVar4 = param_7 - param_6;
  iVar6 = param_6;
  iVar7 = param_4;
  uVar2 = param_1;
  uVar1 = FUN_00495150(param_6,param_4,iVar4,param_5,param_1);
  FUN_00494bf0(uVar1,iVar6,iVar7,iVar4,param_5,uVar2);
  param_5 = 0;
  if (0 < param_3) {
    uVar3 = param_2 & 0xffffff | param_1 & 0xff000000;
    uVar2 = ~param_2 & 0xffffff | param_1 & 0xff000000;
    do {
      if (0 < param_5) {
        param_4 = param_4 + 1;
        iVar5 = iVar5 + -1;
        param_6 = param_6 + 1;
        param_7 = param_7 + -1;
      }
      uVar1 = FUN_00495150();
      FUN_00494c20(param_6,param_4,param_7,param_4,uVar3,uVar1);
      uVar1 = FUN_00495150();
      FUN_00494c20(param_7,param_4,param_7,iVar5,uVar3,uVar1);
      uVar1 = FUN_00495150();
      FUN_00494c20(param_6,iVar5,param_7,iVar5,uVar2,uVar1);
      uVar1 = FUN_00495150();
      FUN_00494c20(param_6,param_4,param_6,iVar5,uVar2,uVar1);
      param_5 = param_5 + 1;
    } while (param_5 < param_3);
  }
  return;
}


