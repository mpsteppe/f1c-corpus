// Function: FUN_004c8de0 @ 004c8de0
// Size (bytes): 251


void FUN_004c8de0(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_104 [260];
  
  if (DAT_008ac4c4 != (int *)0x0) {
    if (DAT_008ac4d0 != (int *)0x0) goto LAB_004c8e12;
    DAT_008ac4d0 = (int *)(**(code **)(*DAT_008ac4c4 + 0x60))();
  }
  if (DAT_008ac4d0 == (int *)0x0) {
    return;
  }
LAB_004c8e12:
  if ((-1 < param_1) && (param_1 < 8)) {
    FUN_00566650(&DAT_005ea438);
    puVar1 = DAT_005ec3e0;
    if (DAT_005ec3e0 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    FUN_0058815f(auStack_104,&DAT_005be860,puVar1,(&PTR_s_options_welcome_wav_005d3234)[param_1]);
    FUN_00566650(auStack_104);
    (**(code **)(*DAT_008ac4d0 + 0x1c))(param_2);
    iVar2 = 0;
    (**(code **)(*DAT_008ac4d0 + 4))(&stack0xfffffee4,1);
    if (iVar2 != 0) {
      FUN_00587bcf(iVar2);
    }
  }
  return;
}


