// Function: FUN_0040e770 @ 0040e770
// Size (bytes): 202


void __thiscall FUN_0040e770(int param_1,undefined4 param_2,char param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_0054fb40(0);
  if ((-1 < *(int *)(param_1 + 0x1c)) && (*(int *)(param_1 + 0x1c) < 3)) {
    FUN_0040e2b0();
  }
  FUN_0054b530(&local_18,&local_14,&local_10,&local_c,&local_8,&local_4);
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
    puVar1 = *(undefined4 **)(param_1 + 0x20);
    puVar1[0x34] = param_2;
    (**(code **)*puVar1)();
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    puVar1 = *(undefined4 **)(param_1 + 0x20);
    puVar1[0x34] = param_2;
    (**(code **)*puVar1)();
    break;
  default:
    goto switchD_0040e7c4_default;
  }
  iVar2 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 4) = local_18;
  *(undefined4 *)(iVar2 + 8) = local_14;
  *(undefined4 *)(iVar2 + 0xc) = local_10;
  *(undefined4 *)(iVar2 + 0x10) = local_c;
  *(undefined4 *)(iVar2 + 0x14) = local_8;
  *(undefined4 *)(iVar2 + 0x18) = local_4;
switchD_0040e7c4_default:
  FUN_0040ed10();
  if (param_3 == '\0') {
    FUN_004be010(param_1);
  }
  return;
}


