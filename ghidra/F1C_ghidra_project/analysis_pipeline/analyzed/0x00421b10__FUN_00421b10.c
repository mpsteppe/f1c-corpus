// Function: FUN_00421b10 @ 00421b10
// Size (bytes): 441


void __fastcall FUN_00421b10(char *param_1,char *param_2)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  undefined1 local_a00 [512];
  undefined1 local_800;
  undefined4 local_7ff;
  undefined1 local_400;
  undefined4 local_3ff;
  
  local_800 = DAT_005ea438;
  puVar7 = &local_7ff;
  for (iVar5 = 0xff; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  local_400 = DAT_005ea438;
  puVar7 = &local_3ff;
  for (iVar5 = 0xff; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  FUN_00565dc0();
  FUN_00565f80(&DAT_005c2ab8,0,param_1,1);
  FUN_00565f50();
  pbVar2 = (byte *)FUN_00565ed0();
  do {
    if (pbVar2 == (byte *)0x0) {
      FUN_00565e20();
      return;
    }
    if ((*pbVar2 & 0x10) == 0) {
      pbVar2 = pbVar2 + 0x2c;
      iVar5 = 2;
      bVar10 = true;
      pbVar6 = pbVar2;
      pbVar8 = &DAT_005beb48;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar10 = *pbVar6 == *pbVar8;
        pbVar6 = pbVar6 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (!bVar10) {
        iVar5 = 3;
        bVar10 = true;
        pbVar6 = pbVar2;
        pbVar8 = &DAT_005c2ab4;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar10 = *pbVar6 == *pbVar8;
          pbVar6 = pbVar6 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (!bVar10) {
          iVar5 = -1;
          pcVar9 = param_1;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          if (iVar5 != -2) {
            iVar5 = -1;
            pcVar9 = param_2;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              cVar1 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar1 != '\0');
            if (iVar5 != -2) {
              FUN_0058815f(&local_800,&DAT_005be860,param_1,pbVar2);
              FUN_0058815f(&local_400,&DAT_005be860,param_2,pbVar2);
              iVar5 = FUN_00587db0(&local_800,&DAT_005be828);
              if ((iVar5 != 0) && (iVar3 = FUN_00587db0(&local_400,&DAT_005c2ab0), iVar3 != 0)) {
                iVar4 = FUN_0058803f(local_a00,1,0x200,iVar5);
                while (0 < iVar4) {
                  FUN_00588678(local_a00,1,iVar4,iVar3);
                  iVar4 = FUN_0058803f(local_a00,1,0x200,iVar5);
                }
                FUN_00587d02(iVar5);
                FUN_00587d02(iVar3);
              }
            }
          }
        }
      }
    }
    FUN_00565f20();
    pbVar2 = (byte *)FUN_00565ed0();
  } while( true );
}


