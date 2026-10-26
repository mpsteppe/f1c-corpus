// Function: FUN_00467e40 @ 00467e40
// Strings:  [credits.txt]


void __fastcall FUN_00467e40(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 local_120;
  undefined4 local_11f [7];
  undefined1 local_100 [256];
  
  local_120 = DAT_005ea438;
  puVar3 = local_11f;
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)puVar3 = 0;
  FUN_005668b0();
  local_100[0] = 0;
  puVar2 = DAT_005ec408;
  if (DAT_005ec408 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_0058815f(&local_120,&DAT_005be860,puVar2,s_credits_txt_005c6734);
  cVar1 = FUN_00566b20(&local_120,1);
  if (cVar1 != '\0') {
    iVar5 = FUN_00566cc0(local_100,0x100);
    while (iVar5 != 0) {
      puVar2 = (undefined1 *)FUN_00587c20(local_100,&DAT_005c30b0);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 0;
      }
      puVar3 = operator_new(8);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = 0;
        puVar3[1] = 0xffffffff;
        FUN_00566650(local_100);
        puVar4 = operator_new(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = puVar3;
          puVar4[1] = 0;
          *(undefined1 *)(puVar4 + 2) = 1;
        }
        if (*(int *)(param_1 + 0xf8) == 0) {
          *(undefined4 **)(param_1 + 0xf8) = puVar4;
          *(undefined4 **)(param_1 + 0x100) = puVar4;
        }
        else {
          *(undefined4 **)(*(int *)(param_1 + 0xfc) + 4) = puVar4;
        }
        *(undefined4 **)(param_1 + 0xfc) = puVar4;
        *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
      }
      iVar5 = FUN_00566cc0(local_100,0x100);
    }
  }
  FUN_005668d0();
  return;
}


