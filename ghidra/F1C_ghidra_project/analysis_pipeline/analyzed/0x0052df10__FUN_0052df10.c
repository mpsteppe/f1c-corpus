// Function: FUN_0052df10 @ 0052df10
// Size (bytes): 77


undefined4 __thiscall FUN_0052df10(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = (**(code **)(*param_1 + 8))();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if ((char)param_1[0x924] == '\x01') {
    uVar2 = FUN_0052e6f0(param_2);
  }
  else if ((char)param_1[0x924] == '\x02') {
    uVar2 = FUN_00531250(param_2);
    return uVar2;
  }
  return uVar2;
}


