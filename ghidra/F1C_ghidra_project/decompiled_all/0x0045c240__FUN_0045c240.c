// Function: FUN_0045c240 @ 0045c240
// Strings:  [terrain.ini, *.hdv, *.gdb]


void __fastcall FUN_0045c240(char *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar4 = _rand();
  *param_1 = (char)(iVar4 % 0xf7) + '\b';
  iVar4 = _rand();
  param_1[1] = (char)iVar4;
  piVar3 = *(int **)(param_1 + 4);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  param_1[0xc] = '\0';
  param_1[0xd] = '\0';
  param_1[0xe] = '\0';
  param_1[0xf] = '\0';
  param_1[0x10] = '\0';
  param_1[0x11] = '\0';
  param_1[0x12] = '\0';
  param_1[0x13] = '\0';
  puVar5 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  FUN_0045c0c0(s___gdb_005c5b9c,puVar5,2);
  puVar5 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  FUN_0045c0c0(s___hdv_005c5b94,puVar5,1);
  puVar5 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  FUN_0045c0c0(s_terrain_ini_005c5b88,puVar5,0);
  return;
}


