// Function: FUN_004630d0 @ 004630d0
// Size (bytes): 101


undefined1 FUN_004630d0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  int local_4;
  
  uVar3 = 0;
  uVar1 = FUN_0057a880();
  iVar2 = FUN_0057a8e0(uVar1);
  if (iVar2 == 0) {
    local_4 = 0x80;
    FUN_0057a230(param_1,&local_4);
    if (local_4 == 0x80) {
      uVar3 = 1;
    }
  }
  FUN_0057a8b0(uVar1);
  return uVar3;
}


