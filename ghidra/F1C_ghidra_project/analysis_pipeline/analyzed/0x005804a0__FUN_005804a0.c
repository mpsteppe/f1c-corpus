// Function: FUN_005804a0 @ 005804a0
// Size (bytes): 284


undefined4 __thiscall FUN_005804a0(int *param_1,char *param_2,undefined1 param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_110;
  undefined1 uStack_10c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0059ca8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x48))();
  FUN_00585680();
  bVar1 = true;
  uStack_10c = 0;
  uStack_4 = 0;
  iVar2 = FUN_0057c7b0(param_1[0x24f],(short)param_1[0x244]);
  if (-1 < iVar2) {
    iVar2 = FUN_0057c7b0(param_1[0x24e],*(ushort *)(param_1 + 0x244) + 0x32);
    if (-1 < iVar2) goto LAB_0058051a;
  }
  bVar1 = false;
LAB_0058051a:
  _strncpy((char *)(param_1 + 0x252),param_2,0x1f);
  *(undefined1 *)((int)param_1 + 0x967) = 0;
  *(undefined1 *)(param_1 + 0x25a) = 1;
  *(undefined1 *)((int)param_1 + 0x96b) = param_3;
  *(undefined1 *)((int)param_1 + 0x96a) = 1;
  if (bVar1) {
    listen(param_1[0x24e],0x7fffffff);
    FUN_00585cd0(4);
    uStack_110 = 0;
    (**(code **)(*param_1 + 0x90))(&uStack_110,2,1);
    FUN_005857c0(uStack_110);
    uVar3 = 0;
  }
  else {
    uVar3 = 6;
  }
  ExceptionList = pvStack_c;
  return uVar3;
}


