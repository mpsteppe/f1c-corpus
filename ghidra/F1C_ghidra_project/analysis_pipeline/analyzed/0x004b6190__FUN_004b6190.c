// Function: FUN_004b6190 @ 004b6190
// Size (bytes): 461


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b6190(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char local_79;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int aiStack_60 [12];
  int aiStack_30 [12];
  
  if ((&DAT_005ef9a0)[param_2 * 0x1230] != -1) {
    local_74 = 0;
    local_70 = param_1;
    do {
      iVar7 = 0;
      local_78 = 0;
      local_68 = FUN_004b68c0();
      iVar5 = 0;
      iVar8 = local_78;
      if (0 < local_68) {
        do {
          iVar6 = *(int *)(param_1 + 0x9b8) - iVar5;
          if (iVar6 < 0) {
            iVar6 = iVar6 + *(int *)(param_1 + 0x9b4);
          }
          iVar4 = FUN_004b4840(local_74,param_2,&local_79);
          if (iVar4 != 0) {
            iVar8 = iVar7;
            if (local_79 != '\0') break;
            aiStack_60[iVar7] = iVar4;
            aiStack_30[iVar7] = iVar6;
            iVar7 = iVar7 + 1;
          }
          iVar8 = iVar7;
          if ((0xb < iVar7) || (iVar5 = iVar5 + 1, local_68 <= iVar5)) break;
        } while( true );
      }
      local_78 = iVar8;
      if (_DAT_005acd38 <= (float)local_78) {
        iVar8 = iVar7 + -1;
        iVar6 = 0;
        local_6c = iVar8;
        iVar5 = iVar8;
        if (0 < iVar7 + -2) {
          do {
            FUN_004b4800(local_74,param_2);
            iVar6 = iVar6 + 1;
            iVar5 = local_6c;
          } while (iVar6 < iVar7 + -2);
        }
        while (local_6c = iVar5, 1 < iVar8) {
          local_78 = iVar8 + -1;
          bVar2 = false;
          iVar5 = local_78;
          iVar7 = local_78;
          local_68 = local_78;
          for (iVar6 = iVar8 + -2; iVar4 = iVar5, iVar8 = local_78, 0 < iVar6; iVar6 = iVar6 + -1) {
            while (iVar4 = iVar5, iVar8 = local_78, iVar6 < local_78) {
              if (iVar6 < iVar5) {
                local_64 = aiStack_60[local_6c];
                iVar1 = aiStack_60[iVar6];
                local_78 = iVar7;
                do {
                  cVar3 = FUN_004b6360(local_64,aiStack_60[iVar5],iVar1);
                  iVar4 = local_68;
                  iVar7 = local_78;
                  param_1 = local_70;
                  iVar8 = local_78;
                  if (cVar3 == '\0') goto joined_r0x004b6311;
                  iVar5 = iVar5 + -1;
                  bVar2 = true;
                } while (iVar6 < iVar5);
              }
              else if (!bVar2) goto joined_r0x004b6311;
              local_78 = local_78 + -1;
              iVar5 = iVar4;
              iVar7 = local_78;
            }
            if (!bVar2) break;
          }
joined_r0x004b6311:
          for (; local_78 = iVar7, iVar5 = iVar8, iVar8 < iVar4; iVar4 = iVar4 + -1) {
            FUN_004b4a30(aiStack_60[iVar4]);
            iVar7 = local_78;
          }
        }
      }
      local_74 = local_74 + 1;
    } while (local_74 < 4);
  }
  return;
}


