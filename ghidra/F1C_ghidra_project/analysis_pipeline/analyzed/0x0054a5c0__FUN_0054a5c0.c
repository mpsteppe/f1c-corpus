// Function: FUN_0054a5c0 @ 0054a5c0
// Size (bytes): 51


void __fastcall FUN_0054a5c0(undefined4 *param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(DAT_008b8f3c + param_2);
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)param_1 = *(undefined1 *)puVar2;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  DAT_008b8f3c = DAT_008b8f3c + param_3;
  return;
}


