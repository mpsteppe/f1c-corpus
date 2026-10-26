// Function: FUN_004069f0 @ 004069f0
// Strings:  [%s%d,%d.mp3]


bool __thiscall FUN_004069f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_20 [32];
  
  if (*(int *)(param_1 + 0x5c) != -1) {
    FUN_00406a70();
  }
  iVar1 = FUN_00595ae2(param_2,0x8000,0x100);
  *(int *)(param_1 + 0x5c) = iVar1;
  if (iVar1 != -1) {
    FUN_0058c724(iVar1,param_3,0);
    FUN_0058815f(local_20,s__s_d__d_mp3_005be854,&DAT_005be820,*(undefined4 *)(param_1 + 0x5c),
                 *(undefined4 *)(param_1 + 0x1c));
    FUN_00566650(local_20);
  }
  return *(int *)(param_1 + 0x5c) != -1;
}


