int __stdcall sub_6770AA(_DWORD *a1, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // esi
  int result; // eax

  if ( a3 < 0 )
  {
    v5 = -a3;
    goto LABEL_6;
  }
  result = sub_6768C8(a1, a3, &a3);
  if ( result >= 0 )
  {
    v5 = a3;
LABEL_6:
    while ( 1 )
    {
      result = sub_675B3D(v5, a2, a4, a5, 0);
      if ( result < 0 )
        break;
      v5 = *(_DWORD *)(v5 + 36);
      if ( !v5 )
        return 0;
    }
  }
  return result;
}
