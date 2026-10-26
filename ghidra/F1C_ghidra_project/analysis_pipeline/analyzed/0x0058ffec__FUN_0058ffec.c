// Function: FUN_0058ffec @ 0058ffec
// Size (bytes): 516


uint FUN_0058ffec(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined1 local_7c [120];
  
  iVar1 = FUN_005905dd(param_1);
  iVar2 = (*DAT_008d3fb8)(iVar1,(-(uint)(DAT_008d3f9c != 0) & 0xfffff005) + 0x1002,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_008d3fb0 = 0;
    return 1;
  }
  iVar2 = FUN_00588410(DAT_008d3fac,local_7c);
  if (iVar2 == 0) {
    iVar2 = (*DAT_008d3fb8)(iVar1,(-(uint)(DAT_008d3fa4 != 0) & 0xfffff002) + 0x1001,local_7c,0x78);
    if (iVar2 == 0) {
      DAT_008d3fb0 = 0;
      return 1;
    }
    iVar2 = FUN_00588410(DAT_008d3fa8,local_7c);
    if (iVar2 == 0) {
      DAT_008d3fb0 = DAT_008d3fb0 | 0x304;
      DAT_008d3fb4 = iVar1;
LAB_00590092:
      DAT_008d3f98 = iVar1;
    }
    else if ((DAT_008d3fb0 & 2) == 0) {
      if ((DAT_008d3fa0 == 0) ||
         (iVar2 = FUN_00596c80(DAT_008d3fa8,local_7c,DAT_008d3fa0), iVar2 != 0)) {
        if (((DAT_008d3fb0 & 1) == 0) && (iVar2 = FUN_00590440(iVar1), iVar2 != 0)) {
          DAT_008d3fb0 = DAT_008d3fb0 | 1;
          DAT_008d3fb4 = iVar1;
        }
      }
      else {
        DAT_008d3fb0 = DAT_008d3fb0 | 2;
        DAT_008d3fb4 = iVar1;
        sVar3 = _strlen(DAT_008d3fa8);
        if (sVar3 == DAT_008d3fa0) goto LAB_00590092;
      }
    }
  }
  if ((DAT_008d3fb0 & 0x300) == 0x300) goto LAB_005901dc;
  iVar2 = (*DAT_008d3fb8)(iVar1,(-(uint)(DAT_008d3fa4 != 0) & 0xfffff002) + 0x1001,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_008d3fb0 = 0;
    return 1;
  }
  iVar2 = FUN_00588410(DAT_008d3fa8,local_7c);
  if (iVar2 == 0) {
    DAT_008d3fb0 = DAT_008d3fb0 | 0x200;
    if (((DAT_008d3fa4 == 0) && (DAT_008d3fa0 != 0)) &&
       (sVar3 = _strlen(DAT_008d3fa8), sVar3 == DAT_008d3fa0)) {
      uVar4 = 1;
      goto LAB_005901bb;
    }
  }
  else {
    if (((DAT_008d3fa4 != 0) || (DAT_008d3fa0 == 0)) ||
       (iVar2 = FUN_00596c80(DAT_008d3fa8,local_7c,DAT_008d3fa0), iVar2 != 0)) goto LAB_005901dc;
    uVar4 = 0;
LAB_005901bb:
    iVar2 = FUN_0059045f(iVar1,uVar4);
    if (iVar2 == 0) goto LAB_005901dc;
  }
  DAT_008d3fb0 = DAT_008d3fb0 | 0x100;
  if (DAT_008d3f98 == 0) {
    DAT_008d3f98 = iVar1;
  }
LAB_005901dc:
  return ~DAT_008d3fb0 >> 2 & 1;
}


