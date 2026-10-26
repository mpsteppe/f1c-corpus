// f1c  0x0054fda0  size=77
int __thiscall sub_54FDA0(int this, int a2, int a3)
{
  int result; // eax

  if ( *(_DWORD *)(this + 76) )
    sub_587BCF(*(LPVOID *)(this + 76));
  *(_DWORD *)(this + 76) = sub_587C03(4 * a3);
  for ( result = 0; result < a3; ++result )
    *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * result) = *(_DWORD *)(a2 + 4 * result);
  *(_DWORD *)(this + 80) = a3;
  return result;
}
