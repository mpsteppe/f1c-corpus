void __thiscall sub_418AC0(_DWORD *this)
{
  double v1; // st7
  _DWORD *v2; // edi
  int v3; // esi
  int v4; // ebx
  int v5; // edx
  float *v6; // ecx
  int i; // ebx
  int v8; // eax
  _DWORD *j; // ecx
  _DWORD *v10; // esi

  v1 = dbl_8AFEA8;
  v2 = this + 537;
  v3 = -1;
  v4 = -1;
  v5 = 0;
  v6 = (float *)(this + 537);
  do
  {
    if ( *((_DWORD *)v6 + 3) != -1082130432 && v1 > v6[3] )
      sub_4144D0(v6);
    if ( *(_DWORD *)v6 == -1 )
    {
      if ( v3 == -1 )
        v3 = v5;
    }
    else
    {
      v4 = v5;
    }
    ++v5;
    v6 += 8;
  }
  while ( v5 < 20 );
  if ( v4 != -1 && v3 < v4 )
  {
    for ( i = 1; i < 20; ++i )
    {
      if ( *v2 == -1 )
      {
        v8 = i;
        for ( j = v2 + 8; *j == -1; j += 8 )
        {
          if ( ++v8 >= 20 )
            return;
        }
        v10 = &this[8 * v8 + 537];
        sub_4145C0(v2, v10);
        sub_4144D0(v10);
      }
      v2 += 8;
    }
  }
}
