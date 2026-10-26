// Function: FUN_005397a0 @ 005397a0
// Size (bytes): 139


void __fastcall FUN_005397a0(undefined4 param_1,undefined1 *param_2,int param_3,int param_4)

{
  byte bVar1;
  int extraout_ECX;
  int iVar2;
  
  FUN_00539720();
  *(undefined4 *)(extraout_ECX + 0x16a7) = 8;
  if (param_4 != 0) {
    *(byte *)(*(int *)(extraout_ECX + 0x14) + *(int *)(extraout_ECX + 8)) = (byte)param_3;
    iVar2 = *(int *)(extraout_ECX + 0x14) + 1;
    bVar1 = (byte)((uint)param_3 >> 8);
    *(int *)(extraout_ECX + 0x14) = iVar2;
    *(byte *)(iVar2 + *(int *)(extraout_ECX + 8)) = bVar1;
    iVar2 = *(int *)(extraout_ECX + 0x14) + 1;
    *(int *)(extraout_ECX + 0x14) = iVar2;
    *(byte *)(iVar2 + *(int *)(extraout_ECX + 8)) = ~(byte)param_3;
    iVar2 = *(int *)(extraout_ECX + 0x14) + 1;
    *(int *)(extraout_ECX + 0x14) = iVar2;
    *(byte *)(iVar2 + *(int *)(extraout_ECX + 8)) = ~bVar1;
    *(int *)(extraout_ECX + 0x14) = *(int *)(extraout_ECX + 0x14) + 1;
  }
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *(undefined1 *)(*(int *)(extraout_ECX + 0x14) + *(int *)(extraout_ECX + 8)) = *param_2;
    param_2 = param_2 + 1;
    *(int *)(extraout_ECX + 0x14) = *(int *)(extraout_ECX + 0x14) + 1;
  }
  return;
}


