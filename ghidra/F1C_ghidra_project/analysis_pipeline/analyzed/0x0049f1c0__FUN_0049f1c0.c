// Function: FUN_0049f1c0 @ 0049f1c0
// Size (bytes): 867


undefined4 __thiscall
FUN_0049f1c0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_70;
  char *local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  float local_48;
  int local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  char local_20 [31];
  undefined1 local_1;
  
  uVar5 = 1;
  if ((param_5 != 0) && (param_6 != 0)) {
    local_70 = param_3;
    local_44 = param_1;
    FUN_005531f0(&DAT_005ccfc4,&local_64,&local_58,0);
    iVar7 = DAT_007c54e8;
    local_64 = (int)(local_64 + (local_64 >> 0x1f & 3U)) >> 2;
    local_50 = local_64 / 2 + local_64 * 0xb + param_2;
    local_54 = (local_64 * 0xb - local_64 / 2) + param_2;
    iVar10 = DAT_007c54e8 + 0x32f4;
    local_60 = local_58 + 1;
    FUN_004a58b0();
    if (*(int *)(*(int *)(param_1 + 4) * 0x40 + iVar10) < 2) {
      FUN_0049f170(1);
    }
    local_68 = (char *)(iVar7 + 0x3302);
    local_5c = 0;
    do {
      iVar10 = local_5c;
      pcVar6 = (char *)FUN_004a47e0();
      iVar7 = FUN_00423a00(pcVar6,&DAT_005ec4cc);
      if (iVar7 != 0) {
        if (pcVar6 == (char *)0x0) {
          DAT_005ec4cc = 0;
        }
        else {
          iVar7 = (int)&DAT_005ec4cc - (int)pcVar6;
          do {
            cVar1 = *pcVar6;
            pcVar6[iVar7] = cVar1;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
        }
      }
      _strncpy(local_20,&DAT_005ec4cc,0x1f);
      local_1 = 0;
      FUN_0049f6a0(local_20,local_54,local_70,param_5,param_6,1);
      _strncpy(local_20,local_68,0x1f);
      local_1 = 0;
      FUN_0049f6a0(local_20,local_50,local_70,param_5,param_6,0);
      if (iVar10 == *(int *)(param_1 + 4)) {
        iVar7 = __ftol();
        iVar8 = __ftol();
        iVar9 = __ftol();
        if (*(int *)(param_6 + 0x1c) < 300) {
          iVar11 = iVar7 + 0xfa;
        }
        else {
          iVar11 = iVar7 + 1000;
        }
        fVar2 = (float)iVar7;
        iVar7 = iVar9 * iVar10 + iVar8;
        local_48 = (float)iVar7;
        fVar3 = (float)iVar11;
        iVar8 = (iVar10 + 1) * iVar9 + iVar8;
        local_38 = 0;
        local_2c = 0;
        local_4c = iVar7;
        local_40 = fVar2;
        local_3c = local_48;
        local_34 = fVar3;
        local_30 = local_48;
        FUN_00553a20(&local_40,param_4);
        local_4c = iVar7 + -1;
        local_3c = (float)local_4c;
        local_38 = 0;
        local_2c = 0;
        local_40 = fVar2;
        local_34 = fVar3;
        local_30 = local_3c;
        FUN_00553a20(&local_40,param_4);
        fVar4 = (float)iVar8;
        local_34 = fVar2;
        local_30 = fVar4;
        FUN_00553a20(&local_40,param_4);
        local_30 = local_48;
        local_40 = fVar3;
        local_3c = fVar4;
        local_34 = fVar3;
        FUN_00553a20(&local_40,param_4);
        local_40 = fVar3;
        local_3c = fVar4;
        local_34 = fVar2;
        local_30 = fVar4;
        FUN_00553a20(&local_40,param_4);
        local_48 = (float)(iVar8 + 1);
        local_3c = (float)(int)local_48;
        local_40 = fVar3;
        local_34 = fVar2;
        local_30 = local_3c;
        FUN_00553a20(&local_40,param_4);
        iVar10 = local_5c;
        param_1 = local_44;
      }
      local_70 = local_70 + local_60;
      local_5c = iVar10 + 1;
      local_68 = local_68 + 0x40;
    } while (local_5c < 5);
    uVar5 = 0;
  }
  return uVar5;
}


