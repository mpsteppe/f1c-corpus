// Function: FUN_004a3910 @ 004a3910
// Strings:  [Normal, PITANIMS.MAS, F0PEWAAA, F0PEHAAA, PITS\, PITGUYC.MTS]


/* WARNING: Removing unreachable block (ram,0x004a3b0e) */
/* WARNING: Removing unreachable block (ram,0x004a3b1f) */

void __thiscall FUN_004a3910(undefined2 *param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  char *pcVar4;
  char local_10 [16];
  
  *param_1 = 0;
  FUN_004a21d0(param_2,s_PITGUYC_MTS_005cd4c0,0,0 < DAT_007cf884);
  FUN_004a3b50();
  puVar2 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  puVar2 = DAT_005ec420;
  if (DAT_005ec420 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005665b0(puVar2);
  FUN_005665b0(s_PITS__005cd4b8);
  if (DAT_005ea3ec == '\0') {
    pcVar4 = s_Normal_005c6e74;
  }
  else {
    pcVar4 = &DAT_005cd4b0;
  }
  FUN_005665b0(pcVar4);
  FUN_0053c800(&DAT_005ea438);
  param_2 = 0;
  FUN_0053cbc0(&param_2,s_PITANIMS_MAS_005cd480);
  iVar3 = 0;
  do {
    cVar1 = (&DAT_005cd4a4)[iVar3];
    local_10[iVar3] = cVar1;
    iVar3 = iVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00566650(local_10);
  FUN_005665b0(&DAT_005cd49c);
  FUN_004a22d0(local_10,&DAT_005ea438,0,0);
  if (0 < *(int *)(param_1 + 0x38)) {
    FUN_004a1fd0(0,*(undefined4 *)(*(int *)(param_1 + 0x3a) + 0x10));
    *(undefined4 *)(param_1 + 0x3e) = *(undefined4 *)(extraout_ECX + 4);
  }
  iVar3 = 0;
  do {
    cVar1 = (&DAT_005cd490)[iVar3];
    local_10[iVar3] = cVar1;
    iVar3 = iVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00566650(local_10);
  FUN_005665b0(&DAT_005cd49c);
  FUN_004a22d0(local_10,&DAT_005ea438,0,0);
  if (1 < *(int *)(param_1 + 0x38)) {
    FUN_004a1fd0(*(undefined4 *)(param_1 + 0x3e),
                 *(float *)(*(int *)(param_1 + 0x3a) + 0x2c) + *(float *)(param_1 + 0x3e));
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(extraout_ECX_00 + 4);
  }
  if (param_2 != 0) {
    FUN_0053ce40(param_2);
  }
  FUN_0053c900(&DAT_005ea438);
  FUN_004a3fe0();
  return;
}


