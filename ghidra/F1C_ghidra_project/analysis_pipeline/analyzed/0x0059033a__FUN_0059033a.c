// Function: FUN_0059033a @ 0059033a
// Size (bytes): 134


uint FUN_0059033a(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_7c [120];
  
  uVar1 = FUN_005905dd(param_1);
  iVar2 = (*DAT_008d3fb8)(uVar1,(-(uint)(DAT_008d3f9c != 0) & 0xfffff005) + 0x1002,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_008d3fb0 = 0;
    uVar3 = 1;
  }
  else {
    iVar2 = FUN_00588410(DAT_008d3fac,local_7c);
    if (iVar2 == 0) {
      iVar2 = FUN_00590440(uVar1);
      if (iVar2 != 0) {
        DAT_008d3fb0 = DAT_008d3fb0 | 4;
        DAT_008d3f98 = uVar1;
        DAT_008d3fb4 = uVar1;
      }
    }
    uVar3 = ~DAT_008d3fb0 >> 2 & 1;
  }
  return uVar3;
}


