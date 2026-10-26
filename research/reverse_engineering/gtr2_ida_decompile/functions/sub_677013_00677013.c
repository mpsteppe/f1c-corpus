int __stdcall sub_677013(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int result; // eax

  if ( a3 < 0 )
  {
    v4 = -a3;
    goto LABEL_6;
  }
  result = sub_6768C8(a1, a3, &a3);
  if ( result >= 0 )
  {
    v4 = a3;
LABEL_6:
    while ( 1 )
    {
      result = sub_675635(v4, a2, a4, 1u, 0);
      if ( result < 0 )
        break;
      v4 = *(_DWORD *)(v4 + 36);
      if ( !v4 )
        return 0;
    }
  }
  return result;
}
