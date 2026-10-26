// Function: FUN_005383d0 @ 005383d0
// Size (bytes): 527


void __fastcall FUN_005383d0(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  iVar5 = *(int *)param_2[2];
  iVar2 = *param_2;
  local_8 = ((int *)param_2[2])[3];
  iVar6 = -1;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x1446) = 0;
  *(undefined4 *)(param_1 + 0x144a) = 0x23d;
  if (0 < local_8) {
    do {
      if (*(short *)(iVar2 + iVar3 * 4) == 0) {
        *(undefined2 *)(iVar2 + 2 + iVar3 * 4) = 0;
      }
      else {
        iVar6 = *(int *)(param_1 + 0x1446) + 1;
        *(int *)(param_1 + 0x1446) = iVar6;
        *(int *)(param_1 + 0xb52 + iVar6 * 4) = iVar3;
        *(undefined1 *)(iVar3 + 0x144e + param_1) = 0;
        iVar6 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < local_8);
  }
  iVar3 = *(int *)(param_1 + 0x1446);
  while (iVar3 < 2) {
    if (iVar6 < 2) {
      iVar7 = iVar6 + 1;
      iVar6 = iVar7;
    }
    else {
      iVar7 = 0;
    }
    *(int *)(param_1 + 0x1446) = iVar3 + 1;
    *(int *)(param_1 + 0xb52 + (iVar3 + 1) * 4) = iVar7;
    *(undefined2 *)(iVar2 + iVar7 * 4) = 1;
    *(undefined1 *)(param_1 + 0x144e + iVar7) = 0;
    *(int *)(param_1 + 0x169b) = *(int *)(param_1 + 0x169b) + -1;
    if (iVar5 != 0) {
      *(uint *)(param_1 + 0x169f) =
           *(int *)(param_1 + 0x169f) - (uint)*(ushort *)(iVar5 + 2 + iVar7 * 4);
    }
    iVar3 = *(int *)(param_1 + 0x1446);
  }
  param_2[1] = iVar6;
  for (iVar5 = *(int *)(param_1 + 0x1446) / 2; 0 < iVar5; iVar5 = iVar5 + -1) {
    FUN_005385e0(iVar5);
  }
  do {
    iVar5 = *(int *)(param_1 + 0xb56);
    *(undefined4 *)(param_1 + 0xb56) =
         *(undefined4 *)(param_1 + 0xb52 + *(int *)(param_1 + 0x1446) * 4);
    *(int *)(param_1 + 0x1446) = *(int *)(param_1 + 0x1446) + -1;
    FUN_005385e0(1);
    iVar6 = *(int *)(param_1 + 0xb56);
    iVar3 = *(int *)(param_1 + 0x144a) + -1;
    *(int *)(param_1 + 0x144a) = iVar3;
    *(int *)(param_1 + 0xb52 + iVar3 * 4) = iVar5;
    iVar3 = *(int *)(param_1 + 0x144a) + -1;
    *(int *)(param_1 + 0x144a) = iVar3;
    *(int *)(param_1 + 0xb52 + iVar3 * 4) = iVar6;
    *(short *)(iVar2 + local_8 * 4) = *(short *)(iVar2 + iVar6 * 4) + *(short *)(iVar2 + iVar5 * 4);
    bVar1 = *(byte *)(param_1 + 0x144e + iVar5);
    bVar4 = *(byte *)(param_1 + 0x144e + iVar6);
    if (bVar4 <= bVar1) {
      bVar4 = bVar1;
    }
    *(byte *)(param_1 + 0x144e + local_8) = bVar4 + 1;
    *(short *)(iVar2 + 2 + iVar6 * 4) = (short)local_8;
    *(short *)(iVar2 + 2 + iVar5 * 4) = (short)local_8;
    *(int *)(param_1 + 0xb56) = local_8;
    local_8 = local_8 + 1;
    FUN_005385e0(1);
  } while (1 < *(int *)(param_1 + 0x1446));
  iVar5 = *(int *)(param_1 + 0x144a) + -1;
  *(int *)(param_1 + 0x144a) = iVar5;
  *(undefined4 *)(param_1 + 0xb52 + iVar5 * 4) = *(undefined4 *)(param_1 + 0xb56);
  FUN_005386c0();
  FUN_005388d0(param_1 + 0xb32);
  return;
}


