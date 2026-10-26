// Function: FUN_004989e0 @ 004989e0
// Strings:  [FTIM28BLK, FTIM28BLK, savingreplay0000.bmp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004989e0(float param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  float10 fVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_68;
  int local_64;
  float local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  
  if (param_2 != (char *)0x0) {
    iVar6 = -1;
    pcVar7 = param_2;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (iVar6 != -2) {
      local_60 = param_1;
      iVar6 = FUN_00497ad0(s_savingreplay0000_bmp_005ccb00,0);
      if (iVar6 != 0) {
        uVar10 = *(undefined4 *)(*(int *)(iVar6 + 0xc) + 0x1c);
        uVar11 = *(undefined4 *)(*(int *)(iVar6 + 0xc) + 0x20);
        uVar4 = FUN_00495150();
        FUN_00494a30(*(undefined4 *)(iVar6 + 0xc),0,0,uVar4,0,0x112,uVar10,uVar11,0,0);
        iVar6 = FUN_0053d1f0(s_FTIM28BLK_005ccaf4);
        FUN_00498560(s_FTIM28BLK_005ccaf4);
        if (iVar6 != 0) {
          local_64 = 0;
          local_60 = 0.0;
          FUN_005531f0(param_2,&local_64,&local_60,1);
          iVar6 = local_64 / 2;
          uVar4 = FUN_00495150();
          FUN_00553070(param_2,400 - iVar6,0x119,uVar4);
        }
        FUN_00495080();
        uVar9 = 0x112;
        uVar4 = 0;
        FUN_00490920(0,0x112,uVar10,uVar11);
        FUN_004918d0(uVar4,uVar9,uVar10,uVar11);
        return;
      }
      local_50 = FUN_0053d1f0((int)param_1 + 0x1538);
      if (local_50 != 0) {
        local_68 = 0;
        local_64 = 0;
        FUN_005531f0(param_2,&local_68,&local_64,1);
        local_54 = 400 - local_68 / 2;
        local_58 = 300 - local_64 / 2;
        local_5c = FUN_00495150();
        FUN_00568ba0();
        FUN_00568be0(1);
        FUN_00568c60();
        do {
          fVar8 = (float10)FUN_00568d90();
          local_60 = (float)fVar8;
          iVar6 = __ftol();
          iVar5 = __ftol();
          uVar2 = __ftol();
          uVar3 = __ftol();
          uVar10 = local_5c;
          FUN_00494bf0(local_5c,400 - (iVar6 + 8) / 2,300 - (iVar5 + 8) / 2,iVar6 + 8,iVar5 + 8,
                       CONCAT31(CONCAT21(CONCAT11(uVar3,uVar2),uVar2),uVar2));
          FUN_00495080();
        } while (local_60 <= _DAT_0059e8fc);
        FUN_00553070(param_2,local_54,local_58,uVar10);
        FUN_00495080();
        FUN_004b0170();
      }
    }
  }
  return;
}


