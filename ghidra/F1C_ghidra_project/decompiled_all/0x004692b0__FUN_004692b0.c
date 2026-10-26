// Function: FUN_004692b0 @ 004692b0
// Strings:  [ProfileIcon.bmp, ProfileIcon.bmp, %s%s\]


uint FUN_004692b0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  char local_200;
  undefined4 local_1ff;
  char local_100 [256];
  
  uVar2 = FUN_0048d360();
  uVar2 = FUN_004693e0(uVar2);
  local_200 = DAT_005ea438;
  puVar8 = &local_1ff;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  puVar3 = DAT_005ec440;
  if (DAT_005ec440 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_0058815f(local_100,s__s_s__005c6968,puVar3,uVar2);
  iVar5 = 0;
  do {
    pcVar4 = local_100 + iVar5;
    (&local_200)[iVar5] = *pcVar4;
    iVar5 = iVar5 + 1;
  } while (*pcVar4 != '\0');
  uVar6 = 0xffffffff;
  pcVar4 = &local_200;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if ((0 < (int)(~uVar6 - 1)) && (pcVar4 = &stack0xfffffdff + ~uVar6, &local_200 <= pcVar4)) {
    do {
      if (*pcVar4 == '\\') break;
      *pcVar4 = '\0';
      if (&local_200 < pcVar4) {
        pcVar4 = pcVar4 + -1;
      }
    } while (&local_200 <= pcVar4);
  }
  iVar5 = FUN_00423a00(s_ProfileIcon_bmp_005c6950,&DAT_005ec4cc);
  if (iVar5 != 0) {
    iVar5 = 0;
    do {
      pcVar4 = s_ProfileIcon_bmp_005c6950 + iVar5;
      (&DAT_005ec4cc)[iVar5] = *pcVar4;
      iVar5 = iVar5 + 1;
    } while (*pcVar4 != '\0');
  }
  uVar6 = 0xffffffff;
  pcVar4 = &DAT_005ec4cc;
  do {
    pcVar10 = pcVar4;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar5 = -1;
  pcVar4 = &local_200;
  do {
    pcVar9 = pcVar4;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar9 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar9;
  } while (cVar1 != '\0');
  pcVar4 = pcVar10 + -uVar6;
  pcVar10 = pcVar9 + -1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar10 = pcVar10 + 1;
  }
  FUN_00497c40(&local_200);
  uVar6 = FUN_00468ee0(0);
  return uVar6 & 0xffffff00;
}


