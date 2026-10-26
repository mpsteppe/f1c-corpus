// Function: FUN_0048aed0 @ 0048aed0
// Size (bytes): 339


void __thiscall FUN_0048aed0(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 local_228 [36];
  undefined1 local_204 [4];
  undefined1 local_200;
  undefined4 local_1ff;
  
  local_200 = DAT_005ea438;
  puVar5 = &local_1ff;
  for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  FUN_005668b0();
  puVar3 = *(undefined1 **)(param_1 + 0xb0);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  puVar7 = DAT_005ec408;
  if (DAT_005ec408 == (undefined1 *)0x0) {
    puVar7 = &DAT_005ea438;
  }
  FUN_0058815f(&local_200,&DAT_005be860,puVar7,puVar3);
  cVar2 = FUN_00566b20(&local_200,1);
  if (cVar2 != '\0') {
    FUN_00566db0(2);
    iVar6 = FUN_00566e20();
    FUN_00566db0(0);
    iVar4 = FUN_00566e20();
    puVar5 = operator_new(8);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar3 = operator_new(iVar6 - iVar4);
      *puVar5 = puVar3;
      *puVar3 = 0;
      puVar5[1] = iVar6 - iVar4;
    }
    FUN_00566cc0(local_204,1);
    iVar6 = FUN_00566cc0(local_228,2);
    while (iVar6 != 0) {
      FUN_005665b0(local_228);
      iVar6 = FUN_00566cc0(local_228,2);
    }
    piVar1 = (int *)*param_2;
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        FUN_00587bcf(*piVar1);
      }
      FUN_00587bcf(piVar1);
      *param_2 = 0;
    }
    *param_2 = (int)puVar5;
  }
  FUN_005668d0();
  return;
}


