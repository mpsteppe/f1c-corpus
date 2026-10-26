// Function: FUN_00554610 @ 00554610
// Size (bytes): 70


void __thiscall FUN_00554610(undefined4 *param_1,int param_2)

{
  if (param_2 != param_1[0xc]) {
    if (param_2 == 0) {
      (**(code **)(*DAT_008b89a0 + 0xf4))(DAT_008b89a0,*param_1,0);
      param_1[0xc] = 0;
      return;
    }
    (**(code **)(*DAT_008b89a0 + 0xf4))
              (DAT_008b89a0,*param_1,*(undefined4 *)(*(int *)(param_2 + 0x54) + 0x14));
    param_1[0xc] = param_2;
  }
  return;
}


