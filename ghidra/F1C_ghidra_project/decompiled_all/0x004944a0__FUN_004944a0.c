// Function: FUN_004944a0 @ 004944a0
// Strings:  [eaIntro.bik, Legal.bmp, eas.bik]


undefined4 __thiscall FUN_004944a0(int param_1,int *param_2,undefined1 param_3,undefined1 param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 auStack_100 [256];
  
  if (param_2 == (int *)0x0) {
    return 0xffffffff;
  }
  pcVar2 = (char *)(**(code **)(*param_2 + 0xc))();
  pcVar6 = (char *)(param_1 + 0xc);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  *(undefined1 *)(param_1 + 0x198) = param_3;
  *(int **)(param_1 + 0x1a4) = param_2;
  *(undefined1 *)(param_1 + 0x199) = param_4;
  *(undefined1 *)(param_1 + 0x19a) = 0;
  iVar3 = FUN_00491ee0();
  if (iVar3 == -1) {
    return 0xffffffff;
  }
  FUN_004920b0();
  if (DAT_005cc2cc != '\0') {
    puVar4 = DAT_005ec418;
    if (DAT_005ec418 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0058815f(auStack_100,&DAT_005be860,puVar4,s_eas_bik_005cc9c0);
    FUN_004f9b70(auStack_100,0);
    FUN_004f9d60(s_Legal_bmp_005cc9b4,0x40400000,0);
    puVar4 = DAT_005ec418;
    if (DAT_005ec418 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0058815f(auStack_100,&DAT_005be860,puVar4,s_eaIntro_bik_005cc9a8);
    FUN_004f9b70(auStack_100,1);
  }
  FUN_00496380();
  uVar5 = FUN_00492160();
  FUN_00491f60();
  if (DAT_005cc2cc != '\0') {
    DAT_005cc2cc = '\0';
    FUN_0041b970();
  }
  return uVar5;
}


