// Function: FUN_0040ea30 @ 0040ea30
// Size (bytes): 249


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040ea30(int param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  double dVar2;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  double local_38;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  *(undefined4 *)(param_1 + 0x20) = param_3;
  *(undefined2 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = 2;
  FUN_004dd550(&local_50);
  local_28 = (double)(local_48 - local_3c);
  local_38 = (double)((local_50 - local_44) * (local_50 - local_44));
  dVar2 = ((double)local_4c - (double)local_40) * ((double)local_4c - (double)local_40);
  local_20 = (local_28 * local_28 + dVar2) * _DAT_0059e6f0;
  local_18 = (local_28 * local_28 + local_38) * _DAT_0059e6f0;
  local_10 = (dVar2 + local_38) * _DAT_0059e6f0;
  FUN_00459950(0,0x40140000,&local_20);
  FUN_00459990(0,0x40900000,0x66666666,0x40466666,0x60000000,0x3fe66666);
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(iVar1 + 0x40) = 0x47ae147b;
  *(undefined4 *)(iVar1 + 0x44) = 0x3f747ae1;
  *(undefined4 *)(iVar1 + 0x48) = 0x47ae147b;
  *(undefined4 *)(iVar1 + 0x4c) = 0x3f747ae1;
  if (param_4 != 0) {
    FUN_0040e770(param_4,0);
  }
  return;
}


