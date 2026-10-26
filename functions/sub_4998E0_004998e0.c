int __thiscall sub_4998E0(_BYTE *this, int a2)
{
  _DWORD *v2; // ecx
  int result; // eax

  SmallStructInit(this);
  result = a2;
  v2[3] = a2;
  if ( a2 )
  {
    *v2 = 0;
    result = *(_DWORD *)(a2 + 28);
    v2[2] = result;
    v2[4] = 0;
    v2[5] = 0;
    if ( !result )
      return sub_499910(v2);
  }
  return result;
}
