// Function: FUN_00554b20 @ 00554b20
// Size (bytes): 189


void __thiscall FUN_00554b20(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005424e0(&local_10,&local_c,&local_8,&local_4);
  if (param_3 == 0) {
    if (*(int *)(param_2 + 0x1a0) == 0) {
      if ((*(byte *)(param_2 + 0x80) & 2) == 0) {
        uVar1 = 0;
        uVar2 = 2;
      }
      else {
        uVar1 = *(undefined4 *)(param_2 + 0x7c);
        uVar2 = 3;
      }
      uVar1 = (**(code **)(*(int *)param_1[0x440] + 0x90))
                        ((int *)param_1[0x440],0,0,uVar2,uVar1,0x3f800000,0);
      *param_1 = uVar1;
      return;
    }
    FUN_00543250(local_10,local_c,param_1[0x54a],local_10,local_c,local_8,local_4,0,0);
  }
  uVar1 = (**(code **)(*(int *)param_1[0x440] + 0x90))((int *)param_1[0x440],0,0,2,0,0x3f800000,0);
  *param_1 = uVar1;
  return;
}


