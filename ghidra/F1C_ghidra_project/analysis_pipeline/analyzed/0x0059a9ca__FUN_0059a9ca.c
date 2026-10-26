// Function: FUN_0059a9ca @ 0059a9ca
// Size (bytes): 206


int __thiscall FUN_0059a9ca(int param_1,int param_2,uint param_3,uint param_4)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  
  if (*(uint *)(param_2 + 8) < param_3) {
    FUN_0059af68();
  }
  uVar3 = *(uint *)(param_2 + 8) - param_3;
  if (param_4 < uVar3) {
    uVar3 = param_4;
  }
  if (param_1 == param_2) {
    FUN_00599348(uVar3 + param_3,DAT_005b9c38);
    FUN_00599348(0,param_3);
  }
  else {
    if ((uVar3 != 0) && (uVar3 == *(uint *)(param_2 + 8))) {
      puVar2 = *(undefined **)(param_2 + 4);
      if (puVar2 == (undefined *)0x0) {
        puVar2 = &DAT_005b9d34;
      }
      if ((byte)puVar2[-1] < 0xfe) {
        FUN_005993af(1);
        puVar2 = *(undefined **)(param_2 + 4);
        if (puVar2 == (undefined *)0x0) {
          puVar2 = &DAT_005b9d34;
        }
        *(undefined **)(param_1 + 4) = puVar2;
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        puVar2[-1] = puVar2[-1] + '\x01';
        return param_1;
      }
    }
    cVar1 = FUN_00599560(uVar3,1);
    if (cVar1 != '\0') {
      puVar2 = *(undefined **)(param_2 + 4);
      if (puVar2 == (undefined *)0x0) {
        puVar2 = &DAT_005b9d34;
      }
      FUN_0058cc00(*(undefined4 *)(param_1 + 4),puVar2 + param_3,uVar3);
      *(uint *)(param_1 + 8) = uVar3;
      *(undefined1 *)(*(int *)(param_1 + 4) + uVar3) = 0;
    }
  }
  return param_1;
}


