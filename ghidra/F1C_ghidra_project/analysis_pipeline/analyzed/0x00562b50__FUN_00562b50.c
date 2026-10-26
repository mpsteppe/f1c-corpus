// Function: FUN_00562b50 @ 00562b50
// Size (bytes): 248


undefined4 * __fastcall
FUN_00562b50(char *param_1,char *param_2,char *param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = _malloc(0x5b8);
  *puVar2 = 0;
  uVar3 = FUN_00564810(&LAB_005640f0);
  puVar2[1] = uVar3;
  uVar3 = FUN_005646d0(4,&LAB_005645a0,&LAB_00564600,&LAB_00564630);
  puVar2[0x25] = uVar3;
  puVar2[0x1b] = param_4;
  puVar4 = _malloc(param_4 * 0x1c);
  puVar2[2] = puVar4;
  for (uVar5 = (uint)(param_4 * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  iVar6 = 0xc - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)puVar2 + iVar6] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  iVar6 = 0x2c - (int)param_3;
  do {
    cVar1 = *param_3;
    param_3[(int)puVar2 + iVar6] = cVar1;
    param_3 = param_3 + 1;
  } while (cVar1 != '\0');
  iVar6 = 0x4c - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)puVar2 + iVar6] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  puVar2[0x1e] = param_5;
  puVar2[0x1f] = param_7;
  puVar2[0x20] = &DAT_005ea438;
  puVar2[0x26] = 0;
  FUN_00564660();
  return puVar2;
}


