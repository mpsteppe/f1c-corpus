// Function: FUN_0048e8d0 @ 0048e8d0
// Strings:  [CUBE error loading scene file %s: %s, D:\dev\F1_1999_2002\Source\O_BaseGz.cpp]


undefined4 __fastcall FUN_0048e8d0(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_100 [256];
  
  puVar2 = *(undefined1 **)(param_1 + 0xe0);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar3 = FUN_00588410(puVar2,&DAT_005ea438);
  if (iVar3 != 0) {
    FUN_00496e40();
    puVar2 = *(undefined1 **)(param_1 + 0xe0);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    iVar3 = FUN_00546010((int *)(param_1 + 0xe8),puVar2,0);
    if (iVar3 != 0) {
      FUN_0053c5b0(0,local_100);
      cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_O_Bas_005cc248,0x2259);
      if (cVar1 != '\0') {
        puVar2 = *(undefined1 **)(param_1 + 0xe0);
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = &DAT_005ea438;
        }
        FUN_004d7aa0(&DAT_008ad25c,s_CUBE_error_loading_scene_file__s_005cc220,puVar2,local_100);
      }
      return 1;
    }
    if (*(int *)(param_1 + 0xe8) != 0) {
      uVar4 = FUN_00545020();
      *(undefined4 *)(param_1 + 0xec) = uVar4;
    }
    if (*(int *)(param_1 + 0xec) != 0) {
      FUN_00541cd0(0,0,0,0,0,0);
      FUN_00541ca0(0);
    }
  }
  return 0;
}


