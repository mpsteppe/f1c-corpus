// Function: FUN_004541d0 @ 004541d0
// Strings:  [PAUSE, PAUSE, -EMPTY-, -EMPTY-]


uint __thiscall FUN_004541d0(int param_1,char *param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined3 uVar5;
  int iVar6;
  
  uVar2 = *(uint *)(param_1 + 0xc88);
  if (0 < (int)uVar2) {
    uVar2 = (uint)*(byte *)(param_1 + 0xc8c);
    *param_3 = uVar2;
    if (uVar2 < 0x81) {
      if (uVar2 < 0x5a) {
        pcVar4 = s_PAUSE_005c4890 + uVar2 * 0x10;
        pcVar3 = pcVar4;
        do {
          cVar1 = *pcVar3;
          uVar5 = (undefined3)((uint)pcVar4 >> 8);
          pcVar4 = (char *)CONCAT31(uVar5,cVar1);
          pcVar3 = pcVar3 + 1;
          *param_2 = cVar1;
          param_2 = param_2 + 1;
        } while (cVar1 != '\0');
        return CONCAT31(uVar5,1);
      }
    }
    else {
      uVar2 = uVar2 - 0x80;
      if (uVar2 < 0x58) {
        pcVar3 = s__EMPTY__005c4e30 + uVar2 * 0x10;
        iVar6 = (int)param_2 - (int)pcVar3;
        do {
          cVar1 = *pcVar3;
          pcVar3[iVar6] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        return CONCAT31((int3)((uint)pcVar3 >> 8),1);
      }
    }
  }
  return uVar2 & 0xffffff00;
}


