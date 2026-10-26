// Function: FUN_0058ae69 @ 0058ae69
// Size (bytes): 243


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0058ae69(uint param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  
  if (((DAT_008d4a20 <= param_1) ||
      (bVar3 = true,
      (*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) == 0)) ||
     (iVar7 = FUN_0058c5ac(), iVar7 == 0)) {
    return 0;
  }
  cVar1 = *param_2;
  if (cVar1 != 'a') {
    if (cVar1 == 'r') {
      *(undefined4 *)(iVar7 + 0xc) = 1;
      goto LAB_0058aecf;
    }
    if (cVar1 != 'w') {
      iVar7 = 0;
      goto LAB_0058af4b;
    }
  }
  *(undefined4 *)(iVar7 + 0xc) = 2;
LAB_0058aecf:
  *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | DAT_008d41bc;
  bVar2 = bVar3;
  bVar4 = false;
  bVar6 = false;
LAB_0058aedf:
  bVar5 = bVar6;
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) goto LAB_0058af3e;
  bVar6 = bVar5;
  if (cVar1 == '+') {
    if ((*(uint *)(iVar7 + 0xc) & 0x80) == 0) {
      *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffffffc | 0x80;
      goto LAB_0058aedf;
    }
  }
  else {
    if (cVar1 == 'b') {
LAB_0058af1f:
      bVar6 = bVar3;
      if (bVar5) goto LAB_0058af31;
      goto LAB_0058aedf;
    }
    if (cVar1 == 'c') {
      if (bVar4) goto LAB_0058af31;
      *(byte *)(iVar7 + 0xd) = *(byte *)(iVar7 + 0xd) | 0x40;
      bVar4 = bVar3;
      goto LAB_0058aedf;
    }
    if (cVar1 == 'n') {
      if (bVar4) goto LAB_0058af31;
      *(byte *)(iVar7 + 0xd) = *(byte *)(iVar7 + 0xd) & 0xbf;
      bVar4 = bVar3;
      goto LAB_0058aedf;
    }
    if (cVar1 == 't') goto LAB_0058af1f;
  }
LAB_0058af31:
  bVar2 = false;
  bVar6 = bVar5;
  goto LAB_0058aedf;
LAB_0058af3e:
  _DAT_008d3ec8 = _DAT_008d3ec8 + 1;
  *(uint *)(iVar7 + 0x10) = param_1;
LAB_0058af4b:
  FUN_0058c203(iVar7);
  return iVar7;
}


