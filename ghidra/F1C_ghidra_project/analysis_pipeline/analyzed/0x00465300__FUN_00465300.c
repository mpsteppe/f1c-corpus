// Function: FUN_00465300 @ 00465300
// Size (bytes): 298


void __thiscall FUN_00465300(int *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  
  uVar1 = *param_2;
  if ((uVar1 >> 0x1d == 1) && ((uVar3 = uVar1 >> 0x12 & 0x3f, uVar3 == 0 || (uVar3 == 7)))) {
    if ((uVar1 & 0xff) < 0x68) {
      FUN_00464b40(param_2);
      return;
    }
  }
  else {
    pvVar4 = operator_new(0x1b0);
    if (pvVar4 != (void *)0x0) {
      FUN_004b3a90(param_2);
      if (((*param_2 & 0x8000000) == 0) && ((*param_2 & 0xe0000000) == 0x20000000)) {
        iVar2 = *param_1;
        puVar5 = operator_new(0xc);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = pvVar4;
          puVar5[1] = 0;
          *(undefined1 *)(puVar5 + 2) = 1;
        }
        if (*(int *)(iVar2 + 0x7c) != 0) {
          *(undefined4 **)(*(int *)(iVar2 + 0x80) + 4) = puVar5;
          *(undefined4 **)(iVar2 + 0x80) = puVar5;
          *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + 1;
          return;
        }
        *(int *)(iVar2 + 0x7c) = (int)puVar5;
        *(undefined4 **)(iVar2 + 0x84) = puVar5;
        *(undefined4 **)(iVar2 + 0x80) = puVar5;
        *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + 1;
        return;
      }
      iVar2 = *param_1;
      puVar5 = operator_new(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = pvVar4;
        puVar5[1] = 0;
        *(undefined1 *)(puVar5 + 2) = 1;
      }
      if (*(int *)(iVar2 + 0x6c) == 0) {
        *(int *)(iVar2 + 0x6c) = (int)puVar5;
        *(undefined4 **)(iVar2 + 0x74) = puVar5;
        *(undefined4 **)(iVar2 + 0x70) = puVar5;
        *(int *)(iVar2 + 0x78) = *(int *)(iVar2 + 0x78) + 1;
        return;
      }
      *(undefined4 **)(*(int *)(iVar2 + 0x70) + 4) = puVar5;
      *(undefined4 **)(iVar2 + 0x70) = puVar5;
      *(int *)(iVar2 + 0x78) = *(int *)(iVar2 + 0x78) + 1;
    }
  }
  return;
}


