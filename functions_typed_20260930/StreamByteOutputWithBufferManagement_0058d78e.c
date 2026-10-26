_DWORD *__cdecl sub_58D78E(unsigned __int8 a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // eax
  bool v5; // zf
  _DWORD *result; // eax

  if ( --a2[1] < 0 )
  {
    v4 = sub_58CF35(a1, a2);
  }
  else
  {
    *(_BYTE *)(*a2)++ = a1;
    v4 = a1;
  }
  v5 = v4 == -1;
  result = a3;
  if ( v5 )
    *a3 = -1;
  else
    ++*a3;
  return result;
}

