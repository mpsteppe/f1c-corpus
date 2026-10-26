// Function: FUN_0044f540 @ 0044f540
// Size (bytes): 162


uint __thiscall FUN_0044f540(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  HANDLE pvVar2;
  int iVar3;
  undefined4 *puVar4;
  CHAR local_100;
  undefined4 local_ff;
  
  local_100 = DAT_005ea438;
  puVar4 = &local_ff;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  puVar1 = DAT_005ec408;
  if (DAT_005ec408 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(&local_100,&DAT_005be860,puVar1,param_2);
  pvVar2 = LoadImageA((HINSTANCE)0x0,&local_100,2,0,0,0x10);
  if (pvVar2 != (HANDLE)0x0) {
    puVar4 = (undefined4 *)(param_1 + 0x30 + *(int *)(param_1 + 0xa8) * 0x14);
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    *(HANDLE *)(param_1 + 0x30 + *(int *)(param_1 + 0xa8) * 0x14) = pvVar2;
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + 1;
  }
  return (uint)pvVar2 & 0xffffff00;
}


