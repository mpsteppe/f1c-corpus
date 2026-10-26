// Function: FUN_004b1410 @ 004b1410
// Size (bytes): 270


undefined4 __thiscall FUN_004b1410(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 local_100;
  undefined4 local_ff;
  
  puVar2 = *(undefined1 **)(param_1 + 0x1f9c);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar3 = FUN_00588410(param_2,puVar2);
  if (iVar3 != 0) {
    local_100 = DAT_005ea438;
    puVar5 = &local_ff;
    for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    *(undefined2 *)puVar5 = 0;
    *(undefined1 *)((int)puVar5 + 2) = 0;
    puVar2 = *(undefined1 **)(param_1 + 0x1f9c);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    puVar4 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    iVar3 = FUN_0058969d(&local_100,0xff,&DAT_005be860,puVar4,puVar2);
    if (-1 < iVar3) {
      FUN_005684a0(&local_100);
      puVar2 = DAT_005ec3d8;
      if (DAT_005ec3d8 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_0058969d(&local_100,0xff,&DAT_005be860,puVar2,param_2);
      if (-1 < iVar3) {
        cVar1 = FUN_00567f40(&local_100,0);
        if (cVar1 == '\x01') {
          FUN_004b0930();
          FUN_00566650(param_2);
          FUN_004b0720();
          return 1;
        }
      }
    }
  }
  return 0;
}


