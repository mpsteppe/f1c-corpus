int __cdecl sub_58FF0D(int a1, int a2, _BYTE **a3)
{
  int v3; // ebx
  int result; // eax
  int v5; // esi

  v3 = 0;
  result = 1;
  while ( v3 <= a2 )
  {
    if ( !result )
      break;
    v5 = (v3 + a2) / 2;
    result = sub_588410(*a3, *(_BYTE **)(a1 + 8 * v5));
    if ( result )
    {
      if ( result >= 0 )
        v3 = v5 + 1;
      else
        a2 = v5 - 1;
    }
    else
    {
      *a3 = (_BYTE *)(a1 + 8 * v5 + 4);
    }
  }
  return result;
}
