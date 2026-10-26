char __thiscall sub_5DD0A0(_DWORD *this, char a2, char a3)
{
  int *v4; // eax
  int i; // eax
  int v6; // eax
  int *v7; // eax
  unsigned __int8 *v8; // ecx
  int *v9; // eax
  int j; // eax
  int v11; // eax
  int *v12; // eax
  _BYTE *v13; // eax
  _DWORD *v14; // ecx

  if ( a2 )
  {
    v4 = (int *)this[113];
    this[115] = v4;
    if ( v4 )
    {
      for ( i = *v4; i; i = *v7 )
      {
        sub_5DCFF0(i, 1);
        v6 = this[115];
        if ( !v6 )
          break;
        v7 = *(int **)(v6 + 4);
        this[115] = v7;
        if ( !v7 )
          break;
      }
    }
    v8 = (unsigned __int8 *)dword_FB27A4;
    if ( !*(_BYTE *)(dword_FB27A4 + 4815) )
    {
      v9 = (int *)this[109];
      this[111] = v9;
      if ( v9 )
      {
        for ( j = *v9; j; j = *v12 )
        {
          sub_5DCFF0(j, 1);
          v11 = this[111];
          if ( !v11 )
            break;
          v12 = *(int **)(v11 + 4);
          this[111] = v12;
          if ( !v12 )
            break;
        }
      }
      v8 = (unsigned __int8 *)dword_FB27A4;
    }
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 360))(v8[4815]);
  }
  LOBYTE(v13) = a3;
  if ( a3 )
  {
    v14 = dword_FB2D78;
    dword_FB2D80 = (int)dword_FB2D78;
    if ( dword_FB2D78 )
    {
      v13 = *(_BYTE **)dword_FB2D78;
      if ( *(_DWORD *)dword_FB2D78 )
      {
        do
        {
          if ( (*v13 & 4) != 0 )
          {
            LOBYTE(v13) = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)dword_FB27A4 + 328))(dword_FB27A4, v13);
            v14 = (_DWORD *)dword_FB2D80;
          }
          if ( !v14 )
            break;
          v14 = (_DWORD *)v14[1];
          dword_FB2D80 = (int)v14;
          if ( !v14 )
            break;
          v13 = (_BYTE *)*v14;
        }
        while ( *v14 );
      }
    }
  }
  return (char)v13;
}
