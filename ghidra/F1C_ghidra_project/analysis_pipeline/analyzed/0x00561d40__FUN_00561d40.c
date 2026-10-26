// Function: FUN_00561d40 @ 00561d40
// Size (bytes): 191


void __fastcall
FUN_00561d40(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            char *param_5,char *param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    puVar3 = &DAT_005e4cf8;
  }
  else {
    puVar3 = _malloc(0x104);
    *param_1 = puVar3;
  }
  iVar2 = 8 - (int)param_5;
  do {
    cVar1 = *param_5;
    param_5[(int)puVar3 + iVar2] = cVar1;
    param_5 = param_5 + 1;
  } while (cVar1 != '\0');
  iVar2 = 0x48 - (int)param_6;
  do {
    cVar1 = *param_6;
    param_6[(int)puVar3 + iVar2] = cVar1;
    param_6 = param_6 + 1;
  } while (cVar1 != '\0');
  puVar3[1] = param_3;
  puVar3[0x37] = 1;
  *(undefined1 *)(puVar3 + 0x3a) = 1;
  *puVar3 = param_4;
  puVar3[0x40] = param_11;
  puVar3[0x32] = param_7;
  puVar3[0x33] = param_8;
  puVar3[0x39] = param_2;
  puVar3[0x36] = 0;
  puVar3[0x38] = 0;
  puVar3[0x35] = param_10;
  puVar3[0x34] = param_9;
  puVar3[0x3f] = 0;
  return;
}


