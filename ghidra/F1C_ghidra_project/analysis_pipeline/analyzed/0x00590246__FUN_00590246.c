// Function: FUN_00590246 @ 00590246
// Size (bytes): 189


uint FUN_00590246(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_7c [120];
  
  uVar1 = FUN_005905dd(param_1);
  iVar2 = (*DAT_008d3fb8)(uVar1,(-(uint)(DAT_008d3fa4 != 0) & 0xfffff002) + 0x1001,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_008d3fb0 = 0;
    return 1;
  }
  iVar2 = FUN_00588410(DAT_008d3fa8,local_7c);
  if (iVar2 == 0) {
    if (DAT_008d3fa4 == 0) {
      uVar3 = 1;
      goto LAB_005902d2;
    }
  }
  else {
    if (((DAT_008d3fa4 != 0) || (DAT_008d3fa0 == 0)) ||
       (iVar2 = FUN_00596c80(DAT_008d3fa8,local_7c,DAT_008d3fa0), iVar2 != 0)) goto LAB_005902f1;
    uVar3 = 0;
LAB_005902d2:
    iVar2 = FUN_0059045f(uVar1,uVar3);
    if (iVar2 == 0) goto LAB_005902f1;
  }
  DAT_008d3fb0 = DAT_008d3fb0 | 4;
  DAT_008d3f98 = uVar1;
  DAT_008d3fb4 = uVar1;
LAB_005902f1:
  return ~DAT_008d3fb0 >> 2 & 1;
}


