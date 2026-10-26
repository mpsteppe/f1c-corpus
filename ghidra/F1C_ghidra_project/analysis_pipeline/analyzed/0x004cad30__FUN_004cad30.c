// Function: FUN_004cad30 @ 004cad30
// Size (bytes): 100


int __fastcall FUN_004cad30(char *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  
  uVar5 = 0xffffffff;
  iVar8 = 0;
  pcVar9 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  iVar6 = ~uVar5 - 1;
  iVar7 = 0;
  if (0 < iVar6) {
    bVar4 = 0;
    param_1 = param_1 + (~uVar5 - 2);
    do {
      cVar1 = *param_1;
      if ((cVar1 < 'a') || ('f' < cVar1)) {
        if ((cVar1 < 'A') || ('F' < cVar1)) {
          if (cVar1 < '0') {
            return iVar8;
          }
          if ('9' < cVar1) {
            return iVar8;
          }
          iVar3 = cVar1 + -0x30;
        }
        else {
          iVar3 = cVar1 + -0x37;
        }
      }
      else {
        iVar3 = cVar1 + -0x57;
      }
      bVar2 = bVar4 & 0x1f;
      bVar4 = bVar4 + 4;
      iVar8 = iVar8 + (iVar3 << bVar2);
      iVar7 = iVar7 + 1;
      param_1 = param_1 + -1;
    } while (iVar7 < iVar6);
  }
  return iVar8;
}


