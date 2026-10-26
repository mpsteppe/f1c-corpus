void __stdcall sub_5A2B00(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v3; // eax
  int v4; // eax

  v1 = (_DWORD *)dword_7E5EC0;
  if ( dword_7E5EC0 )
  {
    while ( v1 != a1 || (*v1)-- != 1 )
    {
      v1 = (_DWORD *)v1[3];
      if ( !v1 )
        return;
    }
    v3 = v1[2];
    if ( v3 )
      *(_DWORD *)(v3 + 12) = v1[3];
    v4 = v1[3];
    if ( v4 )
      *(_DWORD *)(v4 + 8) = v1[2];
    if ( !v1[2] )
      dword_7E5EC0 = v1[3];
    sub_5A2660((int)v1);
    j_nullsub_6(v1);
    sub_5BE8AE();
    --dword_7E8D44;
  }
}
