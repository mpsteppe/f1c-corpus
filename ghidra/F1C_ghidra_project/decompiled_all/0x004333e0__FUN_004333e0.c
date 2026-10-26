// Function: FUN_004333e0 @ 004333e0
// Strings:  [ai.svm, .race, .qual]


/* WARNING: Removing unreachable block (ram,0x00433668) */
/* WARNING: Removing unreachable block (ram,0x00433644) */
/* WARNING: Removing unreachable block (ram,0x00433679) */
/* WARNING: Removing unreachable block (ram,0x00433655) */

void FUN_004333e0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int local_8c;
  char local_80 [128];
  
  FUN_00433890(local_80,0x80);
  iVar3 = DAT_005c329c;
  local_8c = 0;
  if (0 < DAT_005c329c) {
    do {
      iVar2 = (&DAT_007c54f0)[local_8c];
      if (*(int *)(iVar2 + 13000) != 0) {
        if (DAT_007d03e0 == '\0') {
LAB_00433682:
          _strncpy((char *)(iVar2 + 0x4794),local_80,0xff);
          *(undefined1 *)(iVar2 + 0x4893) = 0;
        }
        else {
          FUN_00566650(iVar2 + 0x4714);
          uVar8 = 0xffffffff;
          pcVar4 = &DAT_005ea438;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          if ((0 < (int)(~uVar8 - 1)) && (pcVar4 = &DAT_005ea436 + ~uVar8, &DAT_005ea437 < pcVar4))
          {
            do {
              if (*pcVar4 == '\\') break;
              *pcVar4 = '\0';
              pcVar4 = pcVar4 + -1;
            } while (&DAT_005ea437 < pcVar4);
          }
          pcVar4 = (char *)FUN_00415c30();
          uVar8 = 0xffffffff;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          if ((0 < (int)(~uVar8 - 1)) &&
             (iVar5 = FUN_00415c30(), *(char *)(iVar5 + -1 + (~uVar8 - 1)) != '\\')) {
            FUN_005665b0(&DAT_005c2aac);
          }
          uVar6 = FUN_004326a0();
          uVar7 = FUN_00415c30();
          FUN_00566650(uVar7);
          FUN_005665b0(uVar6);
          iVar5 = FUN_00432e50(DAT_007c56a4);
          if (iVar5 == 5) {
            pcVar4 = s__qual_005c4080;
          }
          else {
            pcVar4 = s__race_005c4078;
          }
          FUN_005665b0(pcVar4);
          FUN_005665b0(&DAT_005c403c);
          iVar5 = FUN_00587db0(&DAT_005ea438,&DAT_005c36f0);
          if (iVar5 == 0) {
            FUN_00566650(&DAT_005ea438);
            FUN_005665b0(uVar6);
            FUN_005665b0(&DAT_005c403c);
            iVar5 = FUN_00587db0(&DAT_005ea438,&DAT_005c36f0);
            if (iVar5 == 0) {
              FUN_00566650(&DAT_005ea438);
              FUN_005665b0(s_ai_svm_005c4070);
              iVar5 = FUN_00587db0(&DAT_005ea438,&DAT_005c36f0);
              if (iVar5 == 0) goto LAB_00433682;
            }
            FUN_00587d02(iVar5);
            _strncpy((char *)(iVar2 + 0x4794),&DAT_005ea438,0xff);
            *(undefined1 *)(iVar2 + 0x4893) = 0;
          }
          else {
            FUN_00587d02(iVar5);
            FUN_004336d0(0xff);
          }
        }
      }
      local_8c = local_8c + 1;
    } while (local_8c < iVar3);
  }
  return;
}


