// Function: FUN_004901a0 @ 004901a0
// Size (bytes): 163


void __fastcall FUN_004901a0(int param_1)

{
  char *_Source;
  int iVar1;
  undefined4 *puVar2;
  char local_40;
  undefined4 local_3f;
  undefined1 local_1;
  
  local_40 = DAT_005ea438;
  puVar2 = &local_3f;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  _Source = *(char **)(param_1 + 0xb8);
  if (_Source == (char *)0x0) {
    _Source = &DAT_005ea438;
  }
  _strncpy(&local_40,_Source,0x3f);
  local_1 = 0;
  iVar1 = FUN_00588410(&local_40,&DAT_005cc21c);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  iVar1 = FUN_00588410(&local_40,&DAT_005cc210);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xe4) = 1;
  }
  iVar1 = FUN_00588410(&local_40,&DAT_005c36f0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xe4) = 2;
  }
  return;
}


