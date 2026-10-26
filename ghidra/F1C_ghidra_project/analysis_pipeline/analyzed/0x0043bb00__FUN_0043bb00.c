// Function: FUN_0043bb00 @ 0043bb00
// Size (bytes): 41


void __thiscall FUN_0043bb00(int param_1,double param_2)

{
  double dVar1;
  
  dVar1 = *(double *)(param_1 + 0x1428);
  *(double *)(param_1 + 0x1428) = param_2;
  *(double *)(param_1 + 0xd4c) =
       (param_2 - dVar1) * *(double *)(param_1 + 0x1430) + *(double *)(param_1 + 0xd4c);
  return;
}


