BOOL __cdecl sub_58EAB0(int a1, int a2, __int16 *a3)
{
  __int16 v3; // cx
  int v4; // edi
  int v5; // edx
  __int16 v6; // bx
  __int16 v7; // cx
  bool v8; // sf

  v3 = *(_WORD *)a1;
  v4 = *(unsigned __int8 *)(a1 + 2);
  a3[1] = -1;
  v5 = *(unsigned __int8 *)(a1 + 3);
  *a3 = -1;
  if ( !v5 )
  {
    *a3 = sub_58CE20(v3);
    return *a3 >= 0;
  }
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
    {
      v6 = sub_58CE20(v3);
      if ( sub_58CEB0(v6, *(_DWORD *)(a2 + 4 * v4)) )
      {
        v7 = *(_WORD *)(a2 + 4 * v4);
        *a3 = v6;
        v8 = *a3 < 0;
        a3[1] = v7;
        return !v8;
      }
      else
      {
        *a3 = -1;
        return *a3 >= 0;
      }
    }
    return *a3 >= 0;
  }
  if ( v4 >= 20 )
    *a3 = -1;
  else
    *a3 = sub_58CE60(v3, *(_WORD *)(a2 + 4 * v4));
  return *a3 >= 0;
}
