// Function: FUN_00406e50 @ 00406e50
// Size (bytes): 320


void __fastcall FUN_00406e50(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1[0x22] != 0) {
    puVar1 = (undefined4 *)param_1[2];
    param_1[4] = (int)puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      piVar2 = (int *)*puVar1;
      while (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x18))();
        puVar1 = (undefined4 *)param_1[2];
        param_1[4] = (int)puVar1;
        if (puVar1 == (undefined4 *)0x0) break;
        piVar2 = (int *)*puVar1;
      }
    }
    piVar2 = (int *)param_1[6];
    while (piVar2 != (int *)0x0) {
      piVar3 = (int *)piVar2[1];
      if (((char)piVar2[2] != '\0') && ((undefined4 *)*piVar2 != (undefined4 *)0x0)) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      FUN_00587bcf(piVar2);
      piVar2 = piVar3;
    }
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    piVar2 = (int *)param_1[10];
    while (piVar2 != (int *)0x0) {
      piVar3 = (int *)piVar2[1];
      if (((char)piVar2[2] != '\0') && (piVar4 = (int *)*piVar2, piVar4 != (int *)0x0)) {
        if (*piVar4 != 0) {
          FUN_00587bcf(*piVar4);
        }
        FUN_00587bcf(piVar4);
      }
      FUN_00587bcf(piVar2);
      piVar2 = piVar3;
    }
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    piVar2 = (int *)param_1[0xe];
    while (piVar2 != (int *)0x0) {
      piVar3 = (int *)piVar2[1];
      if (((char)piVar2[2] != '\0') && (iVar5 = *piVar2, iVar5 != 0)) {
        FUN_00405410();
        FUN_00587bcf(iVar5);
      }
      FUN_00587bcf(piVar2);
      piVar2 = piVar3;
    }
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    (**(code **)(*param_1 + 0x34))(0);
    if (param_1[0x24] != 0) {
      _AIL_waveOutClose_4(param_1[0x24]);
      param_1[0x24] = 0;
    }
    _AIL_shutdown_0();
    param_1[0x22] = 0;
  }
  return;
}


