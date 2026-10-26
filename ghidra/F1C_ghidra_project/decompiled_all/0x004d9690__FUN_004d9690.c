// Function: FUN_004d9690 @ 004d9690
// Strings:  [ --:--.---, %.2d:%06.3f]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d9690(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  float local_8c;
  undefined4 local_88;
  float local_84;
  char local_80 [127];
  undefined1 local_1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x4060) + -1;
    if ((-1 < iVar2) && (iVar2 < 0x19)) {
      FUN_0058815f(local_80,&DAT_005ccef0,(int)(char)(DAT_005d4ae8 + (char)iVar2));
      uVar7 = CONCAT44(DAT_005acf60,3);
      uVar6 = 0;
      uVar5 = 0xffffff;
      uVar1 = DAT_005acf60;
      uVar3 = __ftol(0xffffff,0,3,DAT_005acf60,DAT_005acf60);
      uVar4 = __ftol(uVar3);
      FUN_004d7e40(local_80,uVar4,uVar3,uVar5,uVar6,uVar7,uVar1);
    }
    _strncpy(local_80,(char *)(param_1 + 0x46f8),0x7f);
    local_1 = 0;
    FUN_00589901(local_80);
    uVar1 = __ftol();
    uVar7 = 0x3f8000003f800000;
    uVar6 = 0;
    uVar5 = 0;
    uVar4 = 0xffffff;
    uVar3 = __ftol(0xffffff,0,0,0x3f800000);
    FUN_004d7e40(local_80,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7);
    _strncpy(local_80,(char *)(param_1 + 0x46b8),0x7f);
    local_1 = 0;
    FUN_00589901(local_80);
    uVar7 = 0x3f8000003f800000;
    uVar6 = 0;
    uVar5 = 0;
    uVar4 = 0x48aab3;
    uVar3 = __ftol(0x48aab3,0,0,0x3f800000);
    FUN_004d7e40(local_80,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7);
    local_84 = *(float *)(param_1 + 0x405c);
    if (DAT_0059e440 <= local_84) {
      local_88 = 0;
      local_8c = 0.0;
      FUN_0049b630(local_84,&local_88,&local_8c);
      FUN_0058815f(local_80,s___2d__06_3f_005d4b14,local_88,(double)local_8c);
    }
    else {
      _strncpy(local_80,&DAT_005cce18,0x7f);
      local_1 = 0;
    }
    uVar7 = 0x3f8000003f800000;
    uVar6 = 0;
    uVar5 = 0;
    uVar4 = 0xffff00;
    uVar3 = __ftol(0xffff00,0,0,0x3f800000,0x3f800000);
    FUN_004d7e40(local_80,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7);
    uVar1 = 0;
  }
  return uVar1;
}


