// Function: FUN_00432cf0 @ 00432cf0
// Size (bytes): 250


undefined4 FUN_00432cf0(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char local_100 [255];
  undefined1 local_1;
  
  if (param_1 != 0) {
    pcVar2 = (char *)FUN_004b0b10();
    _strncpy(local_100,pcVar2,0xff);
    uVar3 = 0xffffffff;
    local_1 = 0;
    pcVar2 = local_100;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = local_100 + (~uVar3 - 1);
    if (local_100 < pcVar2) {
      do {
        if (*pcVar2 == '.') {
          *pcVar2 = '\0';
          break;
        }
        pcVar2 = pcVar2 + -1;
      } while (local_100 < pcVar2);
    }
    uVar3 = 0xffffffff;
    pcVar2 = PTR_DAT_005c3f84;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar2 = local_100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 + (~uVar4 - 2) < 0x100) {
      uVar3 = 0xffffffff;
      pcVar2 = PTR_DAT_005c3f84;
      do {
        pcVar7 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar7 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar7;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar5 = -1;
      pcVar2 = local_100;
      do {
        pcVar6 = pcVar2;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      pcVar2 = pcVar7 + -uVar3;
      pcVar7 = pcVar6 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar7 = pcVar7 + 1;
      }
      _strncpy(param_2,local_100,param_3 - 1U);
      param_2[param_3 - 1U] = '\0';
      return 0;
    }
  }
  return 1;
}


