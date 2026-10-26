// Function: FUN_0049da60 @ 0049da60
// Size (bytes): 157


void __fastcall FUN_0049da60(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_40 [64];
  
  uVar2 = DAT_007ce238;
  uVar1 = DAT_005ccbc0;
  iVar3 = DAT_005ccbb8;
  FUN_0049e410(DAT_005ccbc0,DAT_007ce238,DAT_005ccbb8);
  if (*(int *)(param_1 + 8) != 0) {
    iVar3 = iVar3 + DAT_005ccbbc;
    FUN_0049c8f0(local_40,0x40);
    FUN_0049f6a0(local_40,uVar1,iVar3,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    FUN_0049c960(local_40,0x40);
    FUN_0049f6a0(local_40,uVar2,iVar3,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
  }
  return;
}


