// Function: FUN_0049d700 @ 0049d700
// Size (bytes): 417


void __fastcall FUN_0049d700(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_40 [63];
  undefined1 local_1;
  
  uVar2 = DAT_007ce238;
  uVar1 = DAT_005ccbc0;
  iVar3 = DAT_005ccbb8;
  FUN_0049e410(DAT_005ccbc0,DAT_007ce238,DAT_005ccbb8);
  iVar3 = iVar3 + DAT_005ccbbc;
  FUN_0049c310(local_40,0x40);
  local_1 = 0;
  FUN_0049f6a0(local_40,uVar1,iVar3,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
  FUN_0049c370(local_40,0x40);
  FUN_0049f6a0(local_40,uVar2,iVar3,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
  iVar3 = iVar3 + DAT_005ccbbc;
  FUN_0049c490(local_40,0x40);
  local_1 = 0;
  FUN_0049f6a0(local_40,uVar1,iVar3,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
  FUN_0049c4e0(local_40,0x40);
  FUN_0049f6a0(local_40,uVar2,iVar3,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
  iVar3 = iVar3 + DAT_005ccbbc;
  FUN_0049bcd0(local_40,0x40);
  FUN_0049f6a0(local_40,uVar1,iVar3,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
  FUN_0049bd40(local_40,0x40);
  FUN_0049f6a0(local_40,uVar2,iVar3,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
  iVar3 = iVar3 + DAT_005ccbbc;
  FUN_0049c0b0(local_40,0x40);
  FUN_0049f6a0(local_40,0xf0,iVar3,*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
  return;
}


