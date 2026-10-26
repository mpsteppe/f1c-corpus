// Function: FUN_00408740 @ 00408740
// Size (bytes): 154


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00408740(float param_1,float param_2)

{
  float fVar1;
  int iVar2;
  float local_4;
  
  fVar1 = param_2;
  switch(param_2) {
  case 0.0:
    iVar2 = *(int *)((int)param_1 + 0x10);
    break;
  case 1.4013e-45:
    iVar2 = *(int *)((int)param_1 + 0x14);
    break;
  case 2.8026e-45:
    iVar2 = *(int *)((int)param_1 + 0x18);
    break;
  case 4.2039e-45:
    iVar2 = *(int *)((int)param_1 + 0x1c);
    break;
  case 5.60519e-45:
    iVar2 = *(int *)((int)param_1 + 0x3c) * 200 + *(int *)((int)param_1 + 0x20);
    break;
  case 7.00649e-45:
    iVar2 = *(int *)((int)param_1 + 0x24);
    break;
  case 8.40779e-45:
    iVar2 = *(int *)((int)param_1 + 0x28);
    break;
  case 9.80909e-45:
    iVar2 = *(int *)((int)param_1 + 0x2c);
    break;
  case 1.12104e-44:
    iVar2 = *(int *)((int)param_1 + 0x30);
    break;
  default:
    goto switchD_00408752_default;
  }
  if ((iVar2 != 0) && (*(int *)((int)param_1 + 4) != 0)) {
    local_4 = param_1;
    FUN_00456060(&local_4,&param_2);
    FUN_00542050(local_4 * _DAT_0059e65c,param_2 * _DAT_0059e65c,0);
    *(float *)((int)param_1 + 0x34) = fVar1;
  }
switchD_00408752_default:
  return;
}


