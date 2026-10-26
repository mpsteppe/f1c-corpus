// Function: FUN_00534b10 @ 00534b10
// Strings:  [%c%c%c%c%c%c%c%c%c%c, 1.1.3, 1.1.3]


undefined4 * __fastcall FUN_00534b10(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  uint uVar8;
  char *pcVar9;
  char *local_60;
  undefined4 local_5c;
  char local_50 [80];
  
  local_60 = local_50;
  local_5c = 0;
  if (param_1 == (char *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_2 == (char *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = _malloc(0x61);
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0x11] = 0;
  *puVar2 = 0;
  puVar2[0x12] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[1] = 0;
  puVar2[0x10] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  uVar3 = FUN_00536e90(0);
  puVar2[0x13] = uVar3;
  uVar8 = 0xffffffff;
  puVar2[0x14] = 0;
  puVar2[0x16] = 0;
  pcVar9 = param_1;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  pcVar4 = _malloc(~uVar8);
  puVar2[0x15] = pcVar4;
  pcVar9 = param_1;
  if (pcVar4 != (char *)0x0) {
    do {
      cVar1 = *pcVar9;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    *(undefined1 *)(puVar2 + 0x17) = 0;
    do {
      if (*param_2 == 'r') {
        *(undefined1 *)(puVar2 + 0x17) = 0x72;
      }
      if ((*param_2 == 'w') || (*param_2 == 'a')) {
        *(undefined1 *)(puVar2 + 0x17) = 0x77;
      }
      cVar1 = *param_2;
      if ((cVar1 < '0') || ('9' < cVar1)) {
        if (cVar1 == 'f') {
          local_5c = 1;
        }
        else if (cVar1 == 'h') {
          local_5c = 2;
        }
        else {
          *local_60 = cVar1;
          local_60 = local_60 + 1;
        }
      }
      param_2 = param_2 + 1;
    } while ((cVar1 != '\0') && (local_60 != &stack0x00000000));
    if (*(char *)(puVar2 + 0x17) != '\0') {
      if (*(char *)(puVar2 + 0x17) == 'w') {
        iVar5 = FUN_00535c10(8,0xfffffff1,8,local_5c,s_1_1_3_005da7a0,0x38);
        pvVar6 = _malloc(0x4000);
        puVar2[0x12] = pvVar6;
        puVar2[3] = pvVar6;
        if (iVar5 != 0) goto LAB_00534c6c;
      }
      else {
        pvVar6 = _malloc(0x4000);
        puVar2[0x11] = pvVar6;
        *puVar2 = pvVar6;
        iVar5 = FUN_005356a0(s_1_1_3_005da7a0,0x38);
        if (iVar5 != 0) goto LAB_00534c6c;
        pvVar6 = (void *)puVar2[0x11];
      }
      if (pvVar6 != (void *)0x0) {
        puVar2[4] = 0x4000;
        puVar7 = (undefined4 *)FUN_0058afcf();
        *puVar7 = 0;
        if (param_3 < 0) {
          iVar5 = FUN_00587db0(param_1);
        }
        else {
          iVar5 = FUN_0058ae69(param_3,local_50);
        }
        puVar2[0x10] = iVar5;
        if (iVar5 != 0) {
          if (*(char *)(puVar2 + 0x17) != 'w') {
            FUN_00534d50();
            iVar5 = FUN_0058ace6(puVar2[0x10]);
            *(int *)((int)puVar2 + 0x5d) = iVar5 - puVar2[1];
            return puVar2;
          }
          FUN_005887b1(iVar5,s__c_c_c_c_c_c_c_c_c_c_005da788,DAT_005da780,DAT_005da784,8,0,0,0,0,0,0
                       ,0xb);
          *(undefined4 *)((int)puVar2 + 0x5d) = 10;
          return puVar2;
        }
      }
    }
  }
LAB_00534c6c:
  FUN_00534ee0();
  return (undefined4 *)0x0;
}


