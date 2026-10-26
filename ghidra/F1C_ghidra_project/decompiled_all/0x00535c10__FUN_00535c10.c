// Function: FUN_00535c10 @ 00535c10
// Strings:  [1.1.3, insufficient memory]


undefined4 __fastcall
FUN_00535c10(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char *param_7,
            int param_8)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  if (((param_7 == (char *)0x0) || (*param_7 != *PTR_s_1_1_3_005da818)) || (param_8 != 0x38)) {
    return 0xfffffffa;
  }
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(int *)(param_1 + 0x20) == 0) {
      *(code **)(param_1 + 0x20) = FUN_00536fd0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined1 **)(param_1 + 0x24) = &LAB_00536ff0;
    }
    local_4 = param_2;
    if (param_2 == -1) {
      local_4 = 6;
    }
    iVar4 = param_4;
    if (param_4 < 0) {
      iVar4 = -param_4;
    }
    if (((((0 < param_5) && (param_5 < 10)) && ((param_3 == 8 && ((7 < iVar4 && (iVar4 < 0x10))))))
        && (-1 < local_4)) && (((local_4 < 10 && (-1 < param_6)) && (param_6 < 3)))) {
      piVar2 = (int *)(**(code **)(param_1 + 0x20))();
      if (piVar2 == (int *)0x0) {
        return 0xfffffffc;
      }
      *(int **)(param_1 + 0x1c) = piVar2;
      piVar2[6] = (uint)(param_4 < 0);
      iVar5 = 1 << ((byte)iVar4 & 0x1f);
      *(int *)((int)piVar2 + 0x26) = iVar4;
      *piVar2 = param_1;
      *(int *)((int)piVar2 + 0x22) = iVar5;
      *(int *)((int)piVar2 + 0x2a) = iVar5 + -1;
      iVar4 = 1 << ((byte)(param_4 + 7) & 0x1f);
      *(int *)((int)piVar2 + 0x46) = param_4 + 7;
      *(int *)((int)piVar2 + 0x42) = iVar4;
      *(int *)((int)piVar2 + 0x4a) = iVar4 + -1;
      *(uint *)((int)piVar2 + 0x4e) = (param_4 + 9U) / 3;
      uVar3 = (**(code **)(param_1 + 0x20))(2);
      *(undefined4 *)((int)piVar2 + 0x2e) = uVar3;
      uVar3 = (**(code **)(param_1 + 0x20))(2);
      *(undefined4 *)((int)piVar2 + 0x36) = uVar3;
      uVar3 = (**(code **)(param_1 + 0x20))(2);
      *(undefined4 *)((int)piVar2 + 0x3a) = uVar3;
      *(int *)((int)piVar2 + 0x168f) = 1 << ((char)param_4 + 6U & 0x1f);
      iVar4 = (**(code **)(param_1 + 0x20))(4);
      uVar1 = *(uint *)((int)piVar2 + 0x168f);
      piVar2[2] = iVar4;
      piVar2[3] = uVar1 * 4;
      if (((*(int *)((int)piVar2 + 0x2e) != 0) && (*(int *)((int)piVar2 + 0x36) != 0)) &&
         ((*(int *)((int)piVar2 + 0x3a) != 0 && (iVar4 != 0)))) {
        *(undefined1 *)((int)piVar2 + 0x1d) = 8;
        *(uint *)((int)piVar2 + 0x1697) = iVar4 + (uVar1 & 0xfffffffe);
        *(uint *)((int)piVar2 + 0x168b) = iVar4 + uVar1 * 3;
        *(int *)((int)piVar2 + 0x7e) = local_4;
        *(undefined4 *)((int)piVar2 + 0x7a) = 0x16b1;
        uVar3 = FUN_00535e10();
        return uVar3;
      }
      *(undefined **)(param_1 + 0x18) = PTR_s_insufficient_memory_005da834;
      FUN_005361d0();
      return 0xfffffffc;
    }
  }
  return 0xfffffffe;
}


