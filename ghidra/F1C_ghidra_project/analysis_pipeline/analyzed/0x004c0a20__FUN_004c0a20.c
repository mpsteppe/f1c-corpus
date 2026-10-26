// Function: FUN_004c0a20 @ 004c0a20
// Size (bytes): 85


void __thiscall FUN_004c0a20(int param_1,char *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_2 != (char *)0x0) {
    *param_2 = '\0';
    puVar1 = *(undefined1 **)(param_1 + 8);
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    FUN_004c3f80(puVar1);
    iVar2 = FUN_004c4080();
    if ((iVar2 != 0) && (1 < param_3)) {
      _strncpy(param_2,(char *)(iVar2 + 0x7c),param_3 - 1);
      param_2[param_3 - 1] = '\0';
    }
  }
  return;
}


