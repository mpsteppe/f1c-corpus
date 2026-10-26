// Function: FUN_004627c0 @ 004627c0
// Size (bytes): 136


bool FUN_004627c0(int param_1,undefined2 *param_2)

{
  char cVar1;
  undefined2 uVar2;
  int *piVar3;
  bool bVar4;
  int local_4;
  
  piVar3 = (int *)FUN_0057a880();
  FUN_0057a8e0(piVar3);
  local_4 = 0x80;
  FUN_0057a230(param_1,&local_4);
  bVar4 = local_4 == 0x80;
  cVar1 = FUN_00462370();
  *(char *)(param_1 + 0x65) = cVar1 + -1;
  *(undefined1 *)(param_1 + 0x66) = *(undefined1 *)((int)piVar3 + 0x2b);
  if (param_2 != (undefined2 *)0x0) {
    uVar2 = (**(code **)(*piVar3 + 0x18))();
    *param_2 = uVar2;
  }
  FUN_0057a8b0(piVar3);
  return bVar4;
}


