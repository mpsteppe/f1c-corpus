// Function: FUN_0057e570 @ 0057e570
// Size (bytes): 354


void __fastcall FUN_0057e570(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(param_1 + 0xaac);
  if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
     ((DVar5 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
      DVar5 != 0 && (DVar5 != 0x80)))) {
    puVar6 = (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)*puVar6;
  puVar6[2] = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
joined_r0x0057e5bf:
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
      for (puVar4 = puVar1; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)puVar4[1]) {
        if ((undefined4 *)*puVar4 == puVar2) {
          if (puVar4 == (undefined4 *)puVar6[2]) {
            puVar6[2] = puVar4[1];
          }
          if (puVar3 == (undefined4 *)0x0) {
            *puVar6 = puVar4[1];
          }
          else {
            puVar3[1] = puVar4[1];
          }
          if ((undefined4 *)puVar6[1] == puVar4) {
            puVar6[1] = puVar3;
          }
          puVar6[3] = puVar6[3] + -1;
          FUN_00491e40();
          FUN_00587bcf(puVar4);
          if (*(HANDLE *)(param_1 + 0xbec) != (HANDLE)0x0) {
            WaitForSingleObject(*(HANDLE *)(param_1 + 0xbec),*(DWORD *)(param_1 + 0xbf0));
          }
          FUN_0057b530();
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          puVar2[8] = 0xffffffff;
          puVar2[9] = 0;
          *(undefined1 *)(puVar2 + 10) = 0;
          puVar2[0xb] = 0;
          puVar2[0xc] = 0;
          *(undefined2 *)(puVar2 + 0xd) = 0;
          FUN_00583210(puVar2,0);
          if (*(HANDLE *)(param_1 + 0xbec) != (HANDLE)0x0) {
            ReleaseMutex(*(HANDLE *)(param_1 + 0xbec));
          }
          puVar1 = (undefined4 *)*puVar6;
          puVar6[2] = puVar1;
          if (puVar1 == (undefined4 *)0x0) goto LAB_0057e6bc;
          puVar2 = (undefined4 *)*puVar1;
          break;
        }
        puVar3 = puVar4;
      }
      goto joined_r0x0057e5bf;
    }
  }
LAB_0057e6bc:
  if (*(HANDLE *)(param_1 + 0xabc) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
  }
  return;
}


