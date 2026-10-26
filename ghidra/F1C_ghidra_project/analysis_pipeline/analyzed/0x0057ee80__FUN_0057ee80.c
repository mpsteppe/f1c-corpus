// Function: FUN_0057ee80 @ 0057ee80
// Size (bytes): 158


undefined1 __thiscall FUN_0057ee80(int param_1,undefined4 param_2,undefined4 *param_3,DWORD param_4)

{
  int *piVar1;
  char cVar2;
  DWORD DVar3;
  undefined4 uVar4;
  undefined1 local_1;
  
  local_1 = 0;
  DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),param_4);
  if ((DVar3 != 0x102) && (DVar3 != 0xffffffff)) {
    piVar1 = *(int **)(param_1 + 0xac8);
    *(int **)(param_1 + 0xad0) = piVar1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
      while( true ) {
        cVar2 = FUN_0057b840(param_2);
        if (cVar2 != '\0') {
          uVar4 = FUN_005871f0();
          local_1 = 1;
          *param_3 = uVar4;
          goto LAB_0057eef2;
        }
        if (*(int *)(param_1 + 0xad0) == 0) break;
        piVar1 = *(int **)(*(int *)(param_1 + 0xad0) + 4);
        *(int **)(param_1 + 0xad0) = piVar1;
        if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) break;
      }
      local_1 = 0;
    }
LAB_0057eef2:
    if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
    }
  }
  return local_1;
}


