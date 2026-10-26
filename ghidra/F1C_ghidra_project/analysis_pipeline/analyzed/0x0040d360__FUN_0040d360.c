// Function: FUN_0040d360 @ 0040d360
// Size (bytes): 85


int __thiscall FUN_0040d360(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x2e) = 1;
  if (param_2 < 1) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else {
    *(int *)(param_1 + 0x30) = param_2;
  }
  if ((param_3 < 1) || (param_3 <= param_2)) {
    *(int *)(param_1 + 0x34) = param_2 + 5;
  }
  else {
    *(int *)(param_1 + 0x34) = param_3;
  }
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = _rand();
  iVar3 = *(int *)(param_1 + 0x34) - iVar1;
  *(float *)(param_1 + 0x3c) = (float)(iVar2 % iVar3 + iVar1);
  return iVar2 / iVar3;
}


