// Function: FUN_0057a230 @ 0057a230
// Size (bytes): 45


void __thiscall FUN_0057a230(int param_1,undefined4 *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  bVar1 = *(byte *)(param_1 + 0x2c);
  uVar3 = (uint)bVar1;
  *param_3 = uVar3;
  if (uVar3 != 0) {
    puVar4 = (undefined4 *)(param_1 + 0x2d);
    for (uVar2 = (uint)(bVar1 >> 2); uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_2 = *puVar4;
      puVar4 = puVar4 + 1;
      param_2 = param_2 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
  }
  return;
}


