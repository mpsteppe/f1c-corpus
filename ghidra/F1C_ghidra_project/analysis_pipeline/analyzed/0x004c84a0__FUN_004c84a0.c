// Function: FUN_004c84a0 @ 004c84a0
// Size (bytes): 191


void __thiscall FUN_004c84a0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_00565dc0();
  FUN_00565f80(param_2,0,param_3,0);
  iVar2 = FUN_005662d0();
  while (iVar2 != 0) {
    puVar3 = operator_new(8);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      puVar3[1] = 0xffffffff;
      FUN_00566650(iVar2);
      puVar4 = operator_new(0xc);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = puVar3;
        puVar4[1] = 0;
        *(undefined1 *)(puVar4 + 2) = 1;
      }
      if (*param_1 == 0) {
        *param_1 = (int)puVar4;
        param_1[2] = (int)puVar4;
      }
      else {
        *(undefined4 **)(param_1[1] + 4) = puVar4;
      }
      param_1[1] = (int)puVar4;
      param_1[3] = param_1[3] + 1;
    }
    cVar1 = FUN_00565f20();
    if (cVar1 == '\0') break;
    iVar2 = FUN_005662d0();
  }
  FUN_00565e20();
  return;
}


