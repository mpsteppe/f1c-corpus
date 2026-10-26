// Function: FUN_00434000 @ 00434000
// Size (bytes): 39


void __fastcall FUN_00434000(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  uVar1 = DAT_007c56c0;
  puVar2 = (undefined1 *)*param_1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_0042fd00(puVar2,1);
  DAT_007c56c0 = uVar1;
  return;
}


