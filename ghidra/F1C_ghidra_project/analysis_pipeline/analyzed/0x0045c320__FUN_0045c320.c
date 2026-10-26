// Function: FUN_0045c320 @ 0045c320
// Size (bytes): 151


uint __thiscall FUN_0045c320(int param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  *(undefined4 **)(param_1 + 0xc) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar2;
    while (puVar2 != (undefined4 *)0x0) {
      uVar5 = 0xffffffff;
      pcVar6 = param_2;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      for (pcVar6 = param_2 + (~uVar5 - 1); param_2 < pcVar6; pcVar6 = pcVar6 + -1) {
        if (*pcVar6 == '\\') {
          pcVar6 = pcVar6 + 1;
          break;
        }
      }
      puVar3 = (undefined1 *)*puVar2;
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      iVar4 = FUN_00588410(pcVar6,puVar3);
      if (iVar4 == 0) {
        *param_3 = puVar2[2];
        return 1;
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
      }
      if (*(undefined4 **)(param_1 + 0xc) == (undefined4 *)0x0) break;
      puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
    }
  }
  *param_3 = 0;
  return (uint)param_3 & 0xffffff00;
}


