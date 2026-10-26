// Function: FUN_00535e80 @ 00535e80
// Strings:  [buffer error, buffer error, buffer error, stream error]


uint __fastcall FUN_00535e80(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if ((((param_1 == (int *)0x0) || (puVar1 = (undefined4 *)param_1[7], puVar1 == (undefined4 *)0x0))
      || (4 < param_2)) || (param_2 < 0)) {
    return 0xfffffffe;
  }
  if (((param_1[3] == 0) || ((*param_1 == 0 && (param_1[1] != 0)))) ||
     ((puVar1[1] == 0x29a && (param_2 != 4)))) {
    param_1[6] = (int)PTR_s_stream_error_005da82c;
    return 0xfffffffe;
  }
  if (param_1[4] == 0) {
    param_1[6] = (int)PTR_s_buffer_error_005da838;
    return 0xfffffffb;
  }
  iVar2 = *(int *)((int)puVar1 + 0x1e);
  *puVar1 = param_1;
  *(int *)((int)puVar1 + 0x1e) = param_2;
  if (puVar1[1] == 0x2a) {
    puVar1[1] = 0x71;
    FUN_00536130();
    if (*(int *)((int)puVar1 + 0x62) != 0) {
      FUN_00536130();
      FUN_00536130();
    }
    param_1[0xc] = 1;
  }
  if (puVar1[5] == 0) {
    if (((param_1[1] == 0) && (param_2 <= iVar2)) && (param_2 != 4)) {
      param_1[6] = (int)PTR_s_buffer_error_005da838;
      return 0xfffffffb;
    }
  }
  else {
    FUN_00536160();
    if (param_1[4] == 0) {
      *(undefined4 *)((int)puVar1 + 0x1e) = 0xffffffff;
      return 0;
    }
  }
  if (puVar1[1] == 0x29a) {
    if (param_1[1] != 0) {
      param_1[6] = (int)PTR_s_buffer_error_005da838;
      return 0xfffffffb;
    }
LAB_00535ff0:
    if ((*(int *)((int)puVar1 + 0x6a) == 0) && ((param_2 == 0 || (puVar1[1] == 0x29a))))
    goto LAB_005360a2;
  }
  else if (param_1[1] == 0) goto LAB_00535ff0;
  iVar2 = (**(code **)(&DAT_005b77f0 + *(int *)((int)puVar1 + 0x7a) * 0xc))();
  if ((iVar2 == 2) || (iVar2 == 3)) {
    puVar1[1] = 0x29a;
  }
  if ((iVar2 == 0) || (iVar2 == 2)) {
    if (param_1[4] == 0) {
      *(undefined4 *)((int)puVar1 + 0x1e) = 0xffffffff;
    }
    return 0;
  }
  if (iVar2 == 1) {
    if (param_2 == 1) {
      FUN_00537fe0();
    }
    else {
      FUN_00537f30(0,0);
      if (param_2 == 3) {
        *(undefined2 *)(*(int *)((int)puVar1 + 0x3a) + -2 + *(int *)((int)puVar1 + 0x42) * 2) = 0;
        uVar4 = *(int *)((int)puVar1 + 0x42) * 2 - 2;
        puVar5 = *(undefined4 **)((int)puVar1 + 0x3a);
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar5 = 0;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      }
    }
    FUN_00536160();
    if (param_1[4] == 0) {
      *(undefined4 *)((int)puVar1 + 0x1e) = 0xffffffff;
      return 0;
    }
  }
LAB_005360a2:
  if (param_2 != 4) {
    return 0;
  }
  if (puVar1[6] == 0) {
    FUN_00536130();
    FUN_00536130();
    FUN_00536160();
    puVar1[6] = 0xffffffff;
    return (uint)(puVar1[5] == 0);
  }
  return 1;
}


