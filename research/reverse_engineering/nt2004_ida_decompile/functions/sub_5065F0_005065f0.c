int __thiscall sub_5065F0(_DWORD *this, int *a2, float *a3)
{
  int result; // eax

  if ( *this && a2 )
  {
    result = (int)a3;
    if ( a3 )
      return sub_59E170(*a2, a2[1], a2[2], *a3, a3[1], a3[2]);
  }
  return result;
}
