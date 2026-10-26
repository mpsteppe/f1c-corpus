// Function: FUN_0049b370 @ 0049b370
// Size (bytes): 703


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0049b370(int param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,char param_6
            )

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_2c;
  int local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_14;
  float local_10;
  
  local_28 = 0;
  local_2c = 0;
  FUN_005531f0(param_2,&local_28,&local_2c,0);
  iVar1 = __ftol();
  local_28 = iVar1;
  local_2c = __ftol();
  if ((0 < iVar1) && (0 < local_2c)) {
    local_20 = (float)*(int *)(param_1 + 8);
    iVar5 = *(int *)(param_1 + 8) - iVar1 / 2;
    iVar1 = *param_3;
    local_1c = (float)(iVar1 + 4 + local_2c);
    local_10 = (float)(*(int *)(param_1 + 0xc) - iVar1) * _DAT_0059ee8c + (float)(iVar1 + 4);
    local_24 = iVar5;
    local_14 = local_20;
    FUN_00553a20(&local_20,0x88aaaaaa);
    local_20 = (float)(*(int *)(param_1 + 8) + -1);
    FUN_00553a20(&local_20,0x88aaaaaa);
    local_20 = (float)(*(int *)(param_1 + 8) + -2);
    FUN_00553a20(&local_20,0x88aaaaaa);
    local_20 = (float)(*(int *)(param_1 + 8) + -3);
    FUN_00553a20(&local_20,0x88aaaaaa);
    local_20 = (float)(*(int *)(param_1 + 8) + -4);
    FUN_00553a20(&local_20,0x88aaaaaa);
    local_20 = (float)(*(int *)(param_1 + 8) + -5);
    FUN_00553a20(&local_20,0x88cccccc);
    if (DAT_007ce23c != 0) {
      FUN_004dcdd0(iVar5 + -4,*param_3 + -4,1,0);
      FUN_004dcd80(local_28 + 8,local_2c + 8);
      FUN_004dcf20(0x66ffffff);
      FUN_004dcd60(0);
    }
    uVar2 = __ftol();
    uVar3 = __ftol();
    uVar4 = *(undefined4 *)(param_4 + 0x48);
    FUN_00552fc0(0xffffffff);
    FUN_00553070(param_2,uVar2,uVar3,DAT_008b8dc8);
    FUN_00552fc0(uVar4);
    if ((param_6 != '\0') && (DAT_007ce240 != 0)) {
      iVar1 = local_2c + 8;
      uVar4 = FUN_0049b200(0xffffff,0xffffffff,0);
      FUN_004dcdd0(iVar5 + 5 + local_28,*param_3 + -4,1,0);
      FUN_004dcd80(iVar1,iVar1);
      FUN_004dcf20(uVar4);
      FUN_004dcd60(0);
    }
    *param_3 = *param_3 + local_2c + 8;
  }
  return;
}


