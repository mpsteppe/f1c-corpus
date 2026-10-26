// Function: FUN_004c38d0 @ 004c38d0
// Size (bytes): 293


undefined4 __fastcall FUN_004c38d0(undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  int *local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  char local_200 [512];
  
  pcVar6 = (char *)*param_1;
  local_210 = (int *)0x0;
  local_20c = 0;
  local_208 = 0;
  local_204 = 0;
  if (pcVar6 == (char *)0x0) {
    pcVar6 = &DAT_005ea438;
  }
  pcVar8 = local_200;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar8 = cVar1;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar7 = 0xffffffff;
  pcVar6 = local_200;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  pcVar6 = local_200 + (~uVar7 - 1);
  if (local_200 < pcVar6) {
    do {
      if (*pcVar6 == '\\') {
        pcVar6 = pcVar6 + 1;
        break;
      }
      pcVar6 = pcVar6 + -1;
    } while (local_200 < pcVar6);
  }
  pcVar8 = (char *)(param_1 + 0xf8);
  iVar9 = (int)pcVar8 - (int)pcVar6;
  do {
    cVar1 = *pcVar6;
    pcVar6[iVar9] = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar7 = 0xffffffff;
  pcVar6 = pcVar8;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  for (pcVar6 = pcVar8 + (~uVar7 - 1); pcVar8 < pcVar6; pcVar6 = pcVar6 + -1) {
    if (*pcVar6 == '.') {
      *pcVar6 = '\0';
      break;
    }
  }
  iVar9 = -1;
  do {
    pcVar6 = pcVar8;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar6 + -1) = DAT_005d306c;
  pcVar6[3] = DAT_005d3070;
  FUN_004c3a00(&local_210);
  uVar5 = local_204;
  param_1[0x108] = local_204;
  piVar4 = local_210;
  while (piVar4 != (int *)0x0) {
    piVar2 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (piVar3 = (int *)*piVar4, piVar3 != (int *)0x0)) {
      if (*piVar3 != 0) {
        FUN_00587bcf(*piVar3);
      }
      FUN_00587bcf(piVar3);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar2;
  }
  return uVar5;
}


