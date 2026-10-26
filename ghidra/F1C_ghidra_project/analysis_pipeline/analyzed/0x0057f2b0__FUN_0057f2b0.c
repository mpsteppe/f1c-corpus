// Function: FUN_0057f2b0 @ 0057f2b0
// Size (bytes): 196


void __fastcall FUN_0057f2b0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_310;
  undefined1 auStack_30c [748];
  void *pvStack_20;
  int iStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0059ca3b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(param_1[0x250] + 0xc))();
  auStack_30c[0] = 0;
  puVar3 = &uStack_310;
  uStack_4 = 0;
  uStack_310 = 0;
  (**(code **)(param_1[0x250] + 0x10))(auStack_30c,uVar1,puVar3);
  iVar2 = (**(code **)(*param_1 + 0x58))();
  FUN_00586800(0,10,1,2,0xffffffff);
  FUN_00586a00(&stack0xfffffce8,puVar3);
  if (iStack_10 == -1) {
    *(undefined1 *)(*(int *)(iVar2 + 0x48) + 4) = 1;
  }
  else {
    (**(code **)(**(int **)(iVar2 + 0x48) + 0xc))(iStack_10);
  }
  FUN_00585380(iVar2);
  ExceptionList = pvStack_20;
  return;
}


