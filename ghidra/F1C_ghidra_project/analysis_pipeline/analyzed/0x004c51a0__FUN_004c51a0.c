// Function: FUN_004c51a0 @ 004c51a0
// Size (bytes): 285


void FUN_004c51a0(undefined4 param_1,undefined4 param_2,char *param_3,int param_4)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  char local_100 [256];
  
  uVar5 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  for (pcVar6 = param_3 + (~uVar5 - 1); param_3 < pcVar6; pcVar6 = pcVar6 + -1) {
    if (*pcVar6 == '.') {
      *pcVar6 = '\0';
      break;
    }
  }
  uVar5 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  for (pcVar6 = param_3 + (~uVar5 - 1); param_3 < pcVar6; pcVar6 = pcVar6 + -1) {
    if (*pcVar6 == '\\') {
      pcVar6 = pcVar6 + 1;
      break;
    }
  }
  FUN_0058815f(local_100,&DAT_005c2c18,pcVar6);
  iVar7 = 0;
  if (0 < DAT_008ac488) {
    iVar8 = param_4 + 0x104;
    do {
      iVar3 = FUN_00588410(local_100,iVar8);
      if (iVar3 == 0) break;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x18c;
    } while (iVar7 < DAT_008ac488);
  }
  if (iVar7 == DAT_008ac488) {
    puVar1 = (undefined1 *)(iVar7 * 0x18c + 0x104 + param_4);
    *puVar1 = 0;
    pcVar6 = local_100;
    do {
      cVar2 = *pcVar6;
      pcVar6[(int)puVar1 - (int)local_100] = cVar2;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    DAT_008ac488 = DAT_008ac488 + 1;
  }
  param_4 = iVar7 * 0x18c + param_4;
  pcVar6 = param_3;
  do {
    cVar2 = *pcVar6;
    pcVar6[(param_4 + 4) - (int)param_3] = cVar2;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_004c5ae0(param_3);
  uVar4 = FUN_004c5bb0(param_3,0x73,0xd3);
  *(undefined4 *)(param_4 + 0x188) = uVar4;
  return;
}


