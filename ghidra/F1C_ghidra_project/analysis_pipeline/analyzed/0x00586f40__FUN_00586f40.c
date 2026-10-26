// Function: FUN_00586f40 @ 00586f40
// Size (bytes): 47


void __thiscall FUN_00586f40(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (uint)*(ushort *)(*(int *)(param_1 + 8) + 2 + param_2 * 4);
  uVar3 = 0;
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      uVar3 = uVar3 | 1 << ((byte)uVar2 & 0x1f);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  *param_3 = *param_3 & uVar3;
  return;
}


