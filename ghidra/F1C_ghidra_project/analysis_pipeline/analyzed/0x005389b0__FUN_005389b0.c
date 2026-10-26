// Function: FUN_005389b0 @ 005389b0
// Size (bytes): 224


void __fastcall FUN_005389b0(int param_1,int param_2,int param_3)

{
  short *psVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_4;
  
  uVar2 = *(ushort *)(param_2 + 2);
  iVar5 = 0;
  local_4 = 0xffffffff;
  iVar8 = 7;
  iVar4 = 4;
  if (uVar2 == 0) {
    iVar8 = 0x8a;
    iVar4 = 3;
  }
  *(undefined2 *)(param_2 + 6 + param_3 * 4) = 0xffff;
  if (-1 < param_3) {
    puVar3 = (ushort *)(param_2 + 6);
    param_3 = param_3 + 1;
    uVar6 = (uint)uVar2;
    do {
      uVar7 = (uint)*puVar3;
      iVar5 = iVar5 + 1;
      if ((iVar8 <= iVar5) || (uVar6 != uVar7)) {
        if (iVar5 < iVar4) {
          psVar1 = (short *)(param_1 + 0xa72 + uVar6 * 4);
          *psVar1 = *psVar1 + (short)iVar5;
        }
        else if (uVar6 == 0) {
          if (iVar5 < 0xb) {
            *(short *)(param_1 + 0xab6) = *(short *)(param_1 + 0xab6) + 1;
          }
          else {
            *(short *)(param_1 + 0xaba) = *(short *)(param_1 + 0xaba) + 1;
          }
        }
        else {
          if (uVar6 != local_4) {
            psVar1 = (short *)(param_1 + 0xa72 + uVar6 * 4);
            *psVar1 = *psVar1 + 1;
          }
          *(short *)(param_1 + 0xab2) = *(short *)(param_1 + 0xab2) + 1;
        }
        iVar5 = 0;
        local_4 = uVar6;
        if (uVar7 == 0) {
          iVar8 = 0x8a;
          iVar4 = 3;
        }
        else if (uVar6 == uVar7) {
          iVar8 = 6;
          iVar4 = 3;
        }
        else {
          iVar8 = 7;
          iVar4 = 4;
        }
      }
      puVar3 = puVar3 + 2;
      param_3 = param_3 + -1;
      uVar6 = uVar7;
    } while (param_3 != 0);
  }
  return;
}


