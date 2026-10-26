// Function: FUN_0057e280 @ 0057e280
// Size (bytes): 279


void __thiscall FUN_0057e280(int *param_1,float param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 auStack_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0059c9f8;
  local_c = ExceptionList;
  fVar1 = (float)param_1[0x2aa];
  ExceptionList = &local_c;
  param_1[0x2aa] = (int)(fVar1 - param_2);
  if (fVar1 - param_2 <= DAT_0059e440) {
    param_1[0x2aa] = 0x3e000000;
    FUN_00585d20();
    if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
      WaitForSingleObject((HANDLE)param_1[0x2b6],param_1[0x2b7]);
    }
    iVar3 = (**(code **)(*param_1 + 0xa4))();
    iVar6 = 0;
    if (0 < iVar3) {
      do {
        FUN_0057b780(0,0,0);
        uStack_4 = 0;
        cVar2 = (**(code **)(*param_1 + 0xac))(iVar6,auStack_2c);
        if (cVar2 != '\0') {
          if ((char)uStack_4 != '\0') {
            iVar4 = FUN_00587220();
            if (iVar4 != 2) goto LAB_0057e355;
          }
          uVar7 = 0;
          uVar5 = FUN_005871f0(0);
          FUN_00585870(uVar5,uVar7);
        }
LAB_0057e355:
        local_c = (void *)0xffffffff;
        FUN_0057b7f0();
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar3);
    }
    FUN_0057e3a0();
    if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[0x2b6]);
    }
  }
  ExceptionList = local_c;
  return;
}


