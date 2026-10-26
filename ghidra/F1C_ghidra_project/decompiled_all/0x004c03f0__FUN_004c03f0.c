// Function: FUN_004c03f0 @ 004c03f0
// Strings:  [ACTIVE, CONTROLTYPE, CURRENTGRIDPOSITION, ORIGINALGRIDPOSITION, POLESTAKEN, POINTSPOSITION, SEASONPOINTS, FINISHPOINTS]


undefined1 __thiscall FUN_004c03f0(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  char *pcVar6;
  int local_84;
  undefined1 local_80 [128];
  
  uVar4 = 0;
  uVar5 = 0;
  if (*param_2 != 0) {
    while (uVar4 = uVar5, iVar2 = FUN_00566cc0(&DAT_008ac1e8,0x100), iVar2 != 0) {
      uVar5 = 1;
      iVar2 = FUN_005651b0();
      if (iVar2 == 0) {
        iVar2 = FUN_005654a0(&DAT_005cc650,local_80);
        if (iVar2 == 0) {
          iVar2 = FUN_005654a0(s_VEHFILE_005d2718,local_80);
          if (iVar2 == 0) {
            iVar2 = FUN_005654a0(s_RCDFILE_005d2710,local_80);
            if (iVar2 == 0) {
              uVar3 = 0xffffffff;
              pcVar6 = s_FINISHPOSITION_005d2700;
              do {
                if (uVar3 == 0) break;
                uVar3 = uVar3 - 1;
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              iVar2 = FUN_00587c20(&DAT_008ac1e8,s_FINISHPOSITION_005d2700);
              if (((iVar2 != 0) && (iVar2 = FUN_00587ece(iVar2 + (~uVar3 - 1)), -1 < iVar2)) &&
                 (iVar2 < 0x30)) {
                FUN_0058815f(local_80,s__s_2_2d_005d26f8,s_FINISHPOSITION_005d2700,iVar2);
                FUN_00565760(local_80,param_1 + 0x18 + iVar2 * 4,0,0,0);
              }
              uVar3 = 0xffffffff;
              pcVar6 = s_FINISHPOINTS_005d26e8;
              do {
                if (uVar3 == 0) break;
                uVar3 = uVar3 - 1;
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              iVar2 = FUN_00587c20(&DAT_008ac1e8,s_FINISHPOINTS_005d26e8);
              if (((iVar2 != 0) && (iVar2 = FUN_00587ece((~uVar3 - 1) + iVar2), -1 < iVar2)) &&
                 (iVar2 < 0x30)) {
                FUN_0058815f(local_80,s__s_2_2d_005d26f8,s_FINISHPOINTS_005d26e8,iVar2);
                FUN_00565760(local_80,param_1 + 0xd8 + iVar2 * 4,0,0,0);
              }
              FUN_00565760(s_SEASONPOINTS_005d26d8,param_1 + 0x198,0,0,0);
              FUN_00565760(s_POINTSPOSITION_005d26c8,param_1 + 0x19c,0,0,0);
              FUN_00565760(s_POLESTAKEN_005d26bc,param_1 + 0x1a0,0,0,0);
              FUN_00565760(s_ORIGINALGRIDPOSITION_005d26a4,param_1 + 0x1a4,0,0,0);
              FUN_00565760(s_CURRENTGRIDPOSITION_005d2690,param_1 + 0x1a8,0,0,0);
              FUN_00565760(s_CONTROLTYPE_005d2684,param_1 + 0x1ac,0,0,0);
              iVar2 = FUN_00565760(s_ACTIVE_005d267c,&local_84,0,0,0);
              if (iVar2 != 0) {
                *(bool *)(param_1 + 0x1b0) = local_84 != 0;
              }
            }
            else {
              FUN_00566650(local_80);
            }
          }
          else {
            FUN_00566650(local_80);
          }
        }
        else {
          FUN_00566650(local_80);
        }
      }
      else {
        if (iVar2 == 1) {
          return 1;
        }
        if (iVar2 == 4) {
          return 1;
        }
      }
    }
  }
  return uVar4;
}


