// Function: FUN_005992ef @ 005992ef
// Size (bytes): 89


int __thiscall FUN_005992ef(int param_1,uint param_2,char param_3)

{
  char cVar1;
  int iVar2;
  
  if ((uint)(DAT_005b9c38 - *(int *)(param_1 + 8)) <= param_2) {
    FUN_0059ad49();
  }
  if (param_2 != 0) {
    iVar2 = param_2 + *(int *)(param_1 + 8);
    cVar1 = FUN_00599560(iVar2,0);
    if (cVar1 != '\0') {
      _memset((void *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)),(int)param_3,param_2);
      *(int *)(param_1 + 8) = iVar2;
      *(undefined1 *)(*(int *)(param_1 + 4) + iVar2) = 0;
    }
  }
  return param_1;
}


