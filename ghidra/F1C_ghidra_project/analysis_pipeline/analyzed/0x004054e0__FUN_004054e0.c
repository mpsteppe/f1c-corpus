// Function: FUN_004054e0 @ 004054e0
// Size (bytes): 334


bool __thiscall FUN_004054e0(int param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined1 *puVar6;
  undefined1 local_28 [4];
  int local_24;
  byte local_d;
  int local_8;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    return true;
  }
  if (*(uint *)(param_1 + 0x14) <= param_2) {
    return true;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x18) + param_2 * 4);
  iVar3 = FUN_00587f64(*(int *)(param_1 + 0xc),iVar1,0);
  if ((iVar3 == 0) &&
     (iVar3 = FUN_0058803f(local_28,0x28,1,*(undefined4 *)(param_1 + 0xc)), iVar3 != 0)) {
    puVar6 = local_28;
    FUN_00404fe0(puVar6);
    iVar3 = FUN_00407ef0(puVar6);
    *(int *)(param_1 + 0x2c) = iVar3;
    if (iVar3 != -1) {
      FUN_004056a0(local_28);
      iVar3 = *(int *)(param_1 + 0x2c);
      iVar1 = iVar1 + 0x28;
      *(uint *)(param_1 + 0x1c) = param_2;
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(int *)(param_1 + 0x28) = iVar1;
      if (iVar3 == 0) {
        *(int *)(param_1 + 0x24) = local_24 + 0x2c;
        return false;
      }
      if (iVar3 != 1) {
        if (iVar3 != 2) {
          return false;
        }
        *(int *)(param_1 + 0x24) = local_24;
        FUN_00587f64(*(undefined4 *)(param_1 + 0xc),iVar1,0);
        return false;
      }
      bVar5 = (local_d & 4) == 0;
      if (!bVar5) {
        *(int *)(param_1 + 0x24) = local_8 + 0x2c;
      }
      uVar4 = FUN_0059b650(*(undefined4 *)(param_1 + 0x10));
      uVar4 = FUN_0058ae69(uVar4,&DAT_005be828);
      *(undefined4 *)(param_1 + 0x38) = uVar4;
      (**(code **)(*(int *)(param_1 + 0x34) + 0xc))(*(undefined4 *)(param_1 + 0x28),0);
      cVar2 = FUN_0052d8d0((int *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x28),
                           *(int *)(param_1 + 0x24) + -0x2c);
      if (cVar2 != '\0') {
        return bVar5;
      }
      FUN_00405630();
    }
  }
  return true;
}


