// Function: FUN_0046b0c0 @ 0046b0c0
// Strings:  [Press key or controller (ESC to skip) -, POPUP_CONTROL_SET, Reserved Key, Reserved Key]


void __thiscall FUN_0046b0c0(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcVar11;
  int local_58;
  undefined4 local_54;
  undefined1 local_50;
  undefined4 local_4f;
  
  iVar2 = FUN_00489940();
  if (param_2 != '\0') {
    *(undefined4 *)(param_1 + 0x1fc) = 1;
  }
  if (((-1 < iVar2) && (iVar2 < DAT_007d1424)) &&
     (pcVar3 = (char *)FUN_00455560(iVar2), pcVar3 != (char *)0x0)) {
    local_50 = DAT_005ea438;
    puVar9 = &local_4f;
    for (iVar5 = 0x13; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    *(undefined2 *)puVar9 = 0;
    *(undefined1 *)((int)puVar9 + 2) = 0;
    iVar5 = *(int *)(param_1 + 0x1fc);
    if (iVar5 == 1) {
      *(int *)(param_1 + 500) = iVar2;
      uVar4 = FUN_00497980();
      *(undefined4 *)(param_1 + 0x1f8) = uVar4;
      FUN_00497940(s_POPUP_CONTROL_SET_005c69e0,0xffffffff);
      pcVar8 = (char *)(param_1 + 0x174);
      *(undefined1 *)(*(int *)(param_1 + 0x40) + 0x1589) = 0;
      FUN_00423a00(s_Press_key_or_controller__ESC_to_s_005c69b8,pcVar8);
      iVar2 = -1;
      pcVar11 = pcVar8;
      do {
        pcVar10 = pcVar11;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar10 = pcVar11 + 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar10;
      } while (cVar1 != '\0');
      *(undefined2 *)(pcVar10 + -1) = DAT_005c32d8;
      iVar2 = FUN_00423a00(pcVar3,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
        do {
          cVar1 = *pcVar3;
          pcVar3[iVar2] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
      }
      uVar6 = 0xffffffff;
      pcVar3 = &DAT_005ec4cc;
      do {
        pcVar11 = pcVar3;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar2 = -1;
      do {
        pcVar3 = pcVar8;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar3 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar3;
      } while (cVar1 != '\0');
      pcVar8 = pcVar11 + -uVar6;
      pcVar3 = pcVar3 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar3 = pcVar3 + 1;
      }
      *(undefined4 *)(param_1 + 0x208) = 1;
      *(undefined4 *)(param_1 + 0x1fc) = 2;
    }
    else if (iVar5 == 2) {
      local_58 = 0;
      local_54 = 0x59;
      cVar1 = FUN_00454d30(&local_50,&local_58,*(undefined4 *)(param_1 + 0x208));
      *(undefined4 *)(param_1 + 0x208) = 0;
      if (cVar1 != '\0') {
        *(undefined4 *)(param_1 + 0x1fc) = 3;
        if (local_58 == 0) {
          iVar2 = FUN_00454c20(local_54);
          if (iVar2 == 0x59) {
            local_54 = 0x59;
          }
          else if (iVar2 < 0) {
            iVar2 = FUN_00423a00(s_Reserved_Key_005c69f4,&DAT_005ec4cc);
            if (iVar2 != 0) {
              iVar2 = 0;
              do {
                pcVar3 = s_Reserved_Key_005c69f4 + iVar2;
                (&DAT_005ec4cc)[iVar2] = *pcVar3;
                iVar2 = iVar2 + 1;
              } while (*pcVar3 != '\0');
            }
            FUN_00498950(&DAT_005ec4cc);
            local_54 = 0x59;
            *(undefined4 *)(param_1 + 0x1fc) = 2;
          }
        }
        *(int *)(param_1 + 0x200) = local_58;
        *(undefined4 *)(param_1 + 0x204) = local_54;
        return;
      }
    }
    else if (iVar5 == 3) {
      FUN_0046a9c0();
      *(undefined1 *)(*(int *)(param_1 + 0x40) + 0x1589) = 1;
      FUN_004988c0(1);
      FUN_00497940(*(undefined4 *)(param_1 + 0x1f8),0xffffffff);
      *(undefined4 *)(param_1 + 0x1fc) = 0;
      return;
    }
  }
  return;
}


