char __thiscall sub_611B20(_DWORD *this, char a2)
{
  int *v3; // eax
  int i; // eax
  int v5; // eax
  int *v6; // eax
  int *v7; // eax
  int j; // eax
  int v9; // eax
  int *v10; // eax
  _DWORD *m; // eax
  int *v12; // eax
  int k; // eax
  int v14; // eax
  int *v15; // eax

  v3 = (int *)this[168];
  this[170] = v3;
  if ( v3 )
  {
    for ( i = *v3; i; i = *v6 )
    {
      (*(void (__thiscall **)(_DWORD *, int, int))(*this + 416))(this, i, 4096);
      v5 = this[170];
      if ( !v5 )
        break;
      v6 = *(int **)(v5 + 4);
      this[170] = v6;
      if ( !v6 )
        break;
    }
  }
  v7 = (int *)this[178];
  this[180] = v7;
  if ( v7 )
  {
    for ( j = *v7; j; j = *v10 )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 456))(this, j);
      v9 = this[180];
      if ( !v9 )
        break;
      v10 = *(int **)(v9 + 4);
      this[180] = v10;
      if ( !v10 )
        break;
    }
  }
  LOBYTE(m) = a2;
  if ( !a2 )
  {
    v12 = (int *)this[173];
    this[175] = v12;
    if ( v12 )
    {
      for ( k = *v12; k; k = *v15 )
      {
        (*(void (__thiscall **)(_DWORD *, int, int))(*this + 416))(this, k, 4096);
        v14 = this[175];
        if ( !v14 )
          break;
        v15 = *(int **)(v14 + 4);
        this[175] = v15;
        if ( !v15 )
          break;
      }
    }
    m = (_DWORD *)this[183];
    this[185] = m;
    if ( m )
    {
      for ( m = (_DWORD *)*m; m; m = (_DWORD *)*m )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD *))(*this + 456))(this, m);
        m = (_DWORD *)this[185];
        if ( !m )
          break;
        m = (_DWORD *)m[1];
        this[185] = m;
        if ( !m )
          break;
      }
    }
  }
  return (char)m;
}
