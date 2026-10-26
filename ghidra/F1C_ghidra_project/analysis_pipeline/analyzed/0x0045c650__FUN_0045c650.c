// Function: FUN_0045c650 @ 0045c650
// Size (bytes): 252


bool __thiscall FUN_0045c650(int param_1,char *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  undefined4 local_204;
  char local_200 [511];
  undefined1 local_1;
  
  *param_3 = 0;
  cVar3 = FUN_00568a60(*(undefined1 *)(param_1 + 1),&local_204);
  bVar9 = cVar3 != '\0';
  if (bVar9) {
    *param_3 = *param_3 + local_204;
  }
  _strncpy(local_200,param_2,0x1ff);
  iVar2 = DAT_008ac488;
  uVar6 = 0xffffffff;
  local_1 = 0;
  pcVar4 = local_200;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar3 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar3 != '\0');
  pcVar4 = local_200 + (~uVar6 - 1);
  if (local_200 < pcVar4) {
    do {
      if (*pcVar4 == '.') {
        *pcVar4 = '\0';
        break;
      }
      pcVar4 = pcVar4 + -1;
    } while (local_200 < pcVar4);
  }
  iVar7 = 0;
  if (0 < DAT_008ac488) {
    iVar8 = 0;
    while( true ) {
      iVar1 = iVar8 + DAT_008ac490;
      iVar5 = FUN_00588410(local_200,iVar1 + 4);
      if (iVar5 == 0) break;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x18c;
      if (iVar2 <= iVar7) {
        return bVar9;
      }
    }
    *param_3 = *param_3 + *(int *)(iVar1 + 0x188);
  }
  return bVar9;
}


