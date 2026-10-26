// Function: FUN_0058f939 @ 0058f939
// Size (bytes): 581


undefined4 FUN_0058f939(void)

{
  BYTE *pBVar1;
  byte bVar2;
  int iVar3;
  undefined2 *puVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined4 uVar9;
  _cpinfo local_28;
  undefined2 *local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  void *local_8;
  
  uVar9 = 0;
  local_8 = (void *)0x0;
  local_c = (undefined2 *)0x0;
  if (DAT_008d3f38 == 0) {
    PTR_DAT_005e69c8 = &DAT_005e69d2;
    PTR_DAT_005e69cc = &DAT_005e69d2;
    FUN_0058aa6f(DAT_008d3f6c);
    FUN_0058aa6f(DAT_008d3f70);
    DAT_008d3f6c = (undefined2 *)0x0;
    DAT_008d3f70 = (undefined2 *)0x0;
    return 0;
  }
  if ((DAT_008d3f48 != 0) || (iVar3 = FUN_005968f6(0,DAT_008d3f80,0x1004,&DAT_008d3f48), iVar3 == 0)
     ) {
    puVar4 = _malloc(0x202);
    local_14 = puVar4;
    local_10 = _malloc(0x202);
    local_8 = _malloc(0x101);
    local_c = _malloc(0x202);
    if ((puVar4 != (undefined2 *)0x0) &&
       (((local_10 != (undefined2 *)0x0 && (local_8 != (void *)0x0)) &&
        (local_c != (undefined2 *)0x0)))) {
      iVar3 = 0;
      do {
        *(char *)(iVar3 + (int)local_8) = (char)iVar3;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x100);
      BVar5 = GetCPInfo(DAT_008d3f48,&local_28);
      if ((BVar5 != 0) && (local_28.MaxCharSize < 3)) {
        DAT_005e6bd4 = local_28.MaxCharSize & 0xffff;
        if ((1 < DAT_005e6bd4) && (local_28.LeadByte[0] != '\0')) {
          pBVar6 = local_28.LeadByte + 1;
          do {
            bVar2 = *pBVar6;
            if (bVar2 == 0) break;
            for (uVar7 = (uint)pBVar6[-1]; (int)uVar7 <= (int)(uint)bVar2; uVar7 = uVar7 + 1) {
              *(undefined1 *)(uVar7 + (int)local_8) = 0;
              bVar2 = *pBVar6;
            }
            pBVar1 = pBVar6 + 1;
            pBVar6 = pBVar6 + 2;
          } while (*pBVar1 != 0);
        }
        iVar3 = FUN_00595dc8(1,local_8,0x100,puVar4 + 1,0,0,0);
        if (iVar3 != 0) {
          *puVar4 = 0;
          iVar3 = 0;
          puVar4 = local_c;
          do {
            *puVar4 = (short)iVar3;
            puVar4 = puVar4 + 1;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 0x100);
          puVar4 = local_10 + 1;
          iVar3 = FUN_00596a2e(1,local_c,0x100,puVar4,0,0);
          if (iVar3 != 0) {
            *local_10 = 0;
            if ((1 < (int)DAT_005e6bd4) && (local_28.LeadByte[0] != '\0')) {
              pBVar6 = local_28.LeadByte + 1;
              do {
                if (*pBVar6 == 0) break;
                uVar7 = (uint)pBVar6[-1];
                if (uVar7 <= *pBVar6) {
                  puVar8 = local_14 + uVar7 + 1;
                  do {
                    *puVar8 = 0x8000;
                    uVar7 = uVar7 + 1;
                    puVar8 = puVar8 + 1;
                  } while ((int)uVar7 <= (int)(uint)*pBVar6);
                }
                pBVar1 = pBVar6 + 1;
                pBVar6 = pBVar6 + 2;
              } while (*pBVar1 != 0);
            }
            PTR_DAT_005e69c8 = (undefined *)(local_14 + 1);
            PTR_DAT_005e69cc = (undefined *)puVar4;
            if (DAT_008d3f6c != (undefined2 *)0x0) {
              FUN_0058aa6f(DAT_008d3f6c);
            }
            DAT_008d3f6c = local_14;
            if (DAT_008d3f70 != (undefined2 *)0x0) {
              FUN_0058aa6f(DAT_008d3f70);
            }
            DAT_008d3f70 = local_10;
            goto LAB_0058fb17;
          }
        }
      }
    }
  }
  FUN_0058aa6f(local_14);
  FUN_0058aa6f(local_10);
  uVar9 = 1;
LAB_0058fb17:
  FUN_0058aa6f(local_8);
  FUN_0058aa6f(local_c);
  return uVar9;
}


