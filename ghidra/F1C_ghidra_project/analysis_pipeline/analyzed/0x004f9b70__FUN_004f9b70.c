// Function: FUN_004f9b70 @ 004f9b70
// Size (bytes): 486


undefined4 FUN_004f9b70(char *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_208;
  char local_201;
  char local_200 [512];
  
  local_208 = 0;
  iVar2 = FUN_00404fe0();
  FUN_00551f10(&local_208,param_1,1,*(undefined4 *)(iVar2 + 0x90));
  if (local_208 == 0) {
    iVar2 = -(int)param_1;
    do {
      cVar1 = *param_1;
      param_1[(int)(local_200 + iVar2)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    FUN_00422fd0(local_200,0x200);
    iVar2 = FUN_00404fe0();
    FUN_00551f10(&local_208,local_200,1,*(undefined4 *)(iVar2 + 0x90));
    if (local_208 == 0) {
      return 1;
    }
  }
  local_201 = FUN_004c8580();
  if (local_201 != '\0') {
    FUN_004c85a0();
  }
  uVar7 = 0;
  uVar6 = 0x3f800000;
  uVar5 = 0x3f800000;
  uVar4 = 0;
  uVar3 = 0;
  FUN_00495140(0,0,0x3f800000,0x3f800000,0);
  FUN_005434a0(uVar3,uVar4,uVar5,uVar6,uVar7);
  FUN_00495020();
  uVar7 = 0;
  uVar6 = 0x3f800000;
  uVar5 = 0x3f800000;
  uVar4 = 0;
  uVar3 = 0;
  FUN_00495140(0,0,0x3f800000,0x3f800000,0);
  FUN_005434a0(uVar3,uVar4,uVar5,uVar6,uVar7);
  FUN_00551eb0(DAT_007cf2cc);
  uVar6 = 0;
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = FUN_00495140(0,0,0);
  iVar2 = FUN_00551cf0(uVar3,uVar4,uVar5,uVar6);
  do {
    if (iVar2 != 0) {
LAB_004f9d0f:
      FUN_00551f80(local_208);
      FUN_00495060();
      if (local_201 != '\0') {
        FUN_004c85c0();
      }
      return 0;
    }
    FUN_00495020();
    FUN_004537b0(0x3d4ccccd);
    if ((param_2 != '\0') && (0 < DAT_007cb218)) {
      FUN_004537b0(0x3d4ccccd);
      goto LAB_004f9d0f;
    }
    FUN_004a1830();
    uVar6 = 0;
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = FUN_00495140(0,0,0);
    iVar2 = FUN_00551cf0(uVar3,uVar4,uVar5,uVar6);
  } while( true );
}


