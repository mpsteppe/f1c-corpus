// Function: FUN_004a2010 @ 004a2010
// Strings:  [CUBE error loading pitcrew mesh %s: %s, D:\dev\F1_1999_2002\Source\pitcrew.cpp]


undefined4 __thiscall
FUN_004a2010(short *param_1,char *param_2,int param_3,int param_4,char param_5)

{
  short *psVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined1 local_100 [256];
  
  if (param_3 == 0) {
    return 0xffffffff;
  }
  if (*param_1 <= DAT_007cf884) {
    psVar1 = param_1 + 0x32;
    iVar4 = FUN_005450e0(psVar1,param_2,param_3,0x10);
    if (iVar4 != 0) {
      FUN_0053c5b0(0,local_100);
      cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_pitcr_005cd174,0xb4);
      if (cVar3 != '\0') {
        FUN_004d7aa0(&DAT_008ad25c,s_CUBE_error_loading_pitcrew_mesh___005cd14c,param_3,local_100);
      }
      return 0xffffffff;
    }
    bVar2 = false;
    for (iVar4 = *(int *)(param_3 + 0x44); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x44)) {
      FUN_0054a870(iVar4);
      if (*(char *)(iVar4 + 0x40) == '\0') {
        bVar2 = true;
      }
    }
    if (param_4 == 0) {
      FUN_00545250(*(undefined4 *)psVar1);
    }
    else {
      FUN_0054ba00(*(undefined4 *)psVar1,0);
    }
    iVar4 = FUN_0054c210();
    *(int *)(param_1 + 0x34) = iVar4;
    pvVar5 = operator_new(iVar4 * 4);
    *(void **)(param_1 + 0x36) = pvVar5;
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x34)) {
      do {
        uVar6 = FUN_0054c230(iVar4);
        *(undefined4 *)(*(int *)(param_1 + 0x36) + iVar4 * 4) = uVar6;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x34));
    }
    if ((param_5 != '\0') || (1 < DAT_007cf884)) {
      iVar4 = FUN_0054c230(0);
      for (; (iVar4 != 0 && (param_3 != 0)); param_3 = *(int *)(param_3 + 0x44)) {
        if ((*(char *)(param_3 + 0x40) != '\0') && (FUN_00545930(iVar4,param_4), bVar2)) {
          *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x2000000;
        }
        iVar4 = *(int *)(iVar4 + 0x10);
      }
    }
    iVar4 = 4 - (int)param_2;
    do {
      cVar3 = *param_2;
      param_2[(int)param_1 + iVar4] = cVar3;
      param_2 = param_2 + 1;
    } while (cVar3 != '\0');
  }
  return 0;
}


