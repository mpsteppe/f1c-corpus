// Function: FUN_004d1450 @ 004d1450
// Strings:  [Game Name, %s.bmp, Logo%s.bmp, Logo%s%s.bmp, PBOX%02d, %s%s%s%s, COMMON\, LOGOMAP.MAS]


void FUN_004d1450(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 local_214;
  undefined1 local_210 [8];
  undefined1 local_208 [8];
  undefined1 local_200 [64];
  undefined1 local_1c0 [64];
  undefined1 local_180 [64];
  undefined1 local_140 [64];
  undefined1 local_100 [256];
  
  local_214 = 0;
  puVar6 = DAT_005ec420;
  if (DAT_005ec420 == (undefined1 *)0x0) {
    puVar6 = &DAT_005ea438;
  }
  puVar2 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_0058969d(local_100,0x100,s__s_s_s_s_005d3c28,puVar2,puVar6,s_COMMON__005d3c34,
               s_LOGOMAP_MAS_005d3c3c);
  iVar3 = FUN_0053cbc0(&local_214,local_100);
  if (iVar3 == 0) {
    iVar3 = 0;
    do {
      iVar4 = FUN_004d1410(iVar3);
      if (iVar4 == 0) break;
      FUN_0058815f(local_208,&DAT_005d3c20,iVar4);
      iVar4 = FUN_00568210(s_Game_Name_005c713c);
      local_210[0] = 0;
      if (iVar4 != 0) {
        pcVar5 = (char *)FUN_00567970();
        uVar7 = 0xffffffff;
        pcVar8 = pcVar5;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        if (2 < ~uVar7 - 1) {
          FUN_0058815f(local_210,&DAT_005d3c20,pcVar5 + 3);
        }
      }
      FUN_0058815f(local_200,s_PBOX_02d_005d3c14,iVar3);
      FUN_0058815f(local_180,s_Logo_s_s_bmp_005d3c04,local_208,local_210);
      FUN_0058815f(local_1c0,s_Logo_s_bmp_005d3bf8,local_208);
      FUN_0058815f(local_140,s__s_bmp_005d3bf0,local_200);
      FUN_004dc770(local_180,local_1c0,local_140,1,0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x34);
    FUN_0053ce40(local_214);
  }
  return;
}


