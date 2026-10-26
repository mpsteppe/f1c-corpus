// Function: FUN_004c6c40 @ 004c6c40
// Strings:  [vehgen.scn]


void __thiscall FUN_004c6c40(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  char *_Source;
  undefined1 local_40 [64];
  
  puVar1 = operator_new(0x80);
  *puVar1 = 0;
  puVar2 = DAT_005ec438;
  if (DAT_005ec438 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  FUN_005665b0(s_vehgen_scn_005d3224);
  FUN_004ddf90(*(undefined4 *)(param_1 + 0x4894),0);
  puVar2 = puVar1;
  if (puVar1 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_004a4900(puVar2);
  puVar2 = puVar1;
  if (puVar1 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_004dfce0(puVar2,param_2);
  FUN_00568540();
  FUN_004f8370();
  FUN_004bb800();
  *(undefined4 *)(param_1 + 0x48a4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x48a8) = 0xffffffff;
  if (*(int *)(param_1 + 13000) == 0) {
    FUN_004b0b20(local_40,0x3f);
    FUN_004c6980(local_40);
    _Source = DAT_007ce684;
    if (DAT_007ce684 == (char *)0x0) {
      _Source = &DAT_005ea438;
    }
    _strncpy((char *)(param_1 + 0x4660),_Source,0x17);
    *(undefined1 *)(param_1 + 0x4677) = 0;
  }
  FUN_004c7b50();
  FUN_00410b20(param_1 + 0xc);
  if (puVar1 != (undefined1 *)0x0) {
    FUN_00587bcf(puVar1);
  }
  return;
}


