// Function: FUN_0045f950 @ 0045f950
// Strings:  [%s (%d ms), Synchronizing game, Synchronizing game]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045f950(int param_1,float param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  bool bVar7;
  float10 fVar8;
  float10 fVar9;
  float local_208;
  float local_204;
  double local_200;
  char *local_1f8;
  undefined1 local_1f4 [4];
  undefined1 local_1f0 [64];
  undefined1 local_1b0 [8];
  undefined2 local_1a8;
  
  if ((*(int *)(param_1 + 0x3fc4) == 2) || (*(int *)(param_1 + 0x3fc4) == 1)) {
    param_2 = param_2 + *(float *)(param_1 + 0x38c);
    *(float *)(param_1 + 0x38c) = param_2;
    if (_DAT_0059e7ec < param_2) {
      *(undefined4 *)(param_1 + 0x38c) = 0;
      local_200 = (double)((ulonglong)local_200 & 0xffffffff00000000);
      if (0 < *(int *)(param_1 + 0x3e14)) {
        puVar5 = (undefined4 *)(param_1 + 0x3c74);
        iVar6 = param_1 + 0x394;
        do {
          cVar2 = FUN_00461530(1);
          if (((cVar2 == '\0') && (cVar2 = FUN_00461530(2), cVar2 != '\0')) &&
             (cVar2 = FUN_0045ca20((int)*(char *)(iVar6 + 0x7c),&local_208,1), cVar2 != '\0')) {
            FUN_004b33b0(4,0x2a,2,0xff,(float)_DAT_008afea0,0);
            local_1a8 = __ftol();
            FUN_00462250(local_1b0,2,*puVar5,0xffffffff);
          }
          iVar3 = local_200._0_4_ + 1;
          puVar5 = puVar5 + 1;
          iVar6 = iVar6 + 0x8c;
          local_200 = (double)CONCAT44(local_200._4_4_,iVar3);
        } while (iVar3 < *(int *)(param_1 + 0x3e14));
        return;
      }
    }
  }
  else {
    param_2 = *(float *)(param_1 + 0x10) - param_2;
    *(float *)(param_1 + 0x10) = param_2;
    if (param_2 < DAT_0059e440) {
      bVar7 = *(char *)(param_1 + 0x14) != '\0';
      if (bVar7) {
        *(undefined1 *)(param_1 + 0x14) = 0;
      }
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
      if (bVar7) {
        FUN_0045e570();
      }
    }
    cVar2 = FUN_0057a610(&local_204,&local_1f8,local_1f4);
    if (cVar2 != '\0') {
      if ((DAT_007c56a4 != *local_1f8) && (*local_1f8 < 8)) {
        *(undefined1 *)(param_1 + 0x374) = 1;
        if (DAT_007ce254 == '\0') {
          FUN_004a0250();
        }
        FUN_0042cf10();
        FUN_004a0da0();
        *(undefined4 *)(param_1 + 0x10) = 0x40000000;
      }
      local_200 = (double)local_204;
      fVar8 = (float10)FUN_004f9f60();
      fVar9 = (float10)local_200;
      local_200 = (double)CONCAT44(local_200._4_4_,(float)(fVar9 - fVar8));
      fVar9 = ABS(fVar9 - fVar8);
      local_208 = (float)fVar9;
      if ((float10)_DAT_0059ea08 < fVar9) {
        if (_DAT_0059e84c < local_208) {
          local_1f0[0] = 0;
          iVar6 = FUN_00423a00(s_Synchronizing_game_005c5e80,&DAT_005ec4cc);
          if (iVar6 != 0) {
            iVar6 = 0;
            do {
              pcVar1 = s_Synchronizing_game_005c5e80 + iVar6;
              (&DAT_005ec4cc)[iVar6] = *pcVar1;
              iVar6 = iVar6 + 1;
            } while (*pcVar1 != '\0');
          }
          uVar4 = __ftol();
          FUN_0058815f(local_1f0,s__s___d_ms__005c5e74,&DAT_005ec4cc,uVar4);
          FUN_0045bd10(local_1f0,3,0x1020304);
        }
        if (_DAT_0059e450 < local_208) {
          FUN_0042bda0((double)local_204);
        }
        FUN_004f9fc0();
      }
    }
  }
  return;
}


