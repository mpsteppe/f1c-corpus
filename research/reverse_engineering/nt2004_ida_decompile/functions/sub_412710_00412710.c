char __thiscall sub_412710(_DWORD *this, int a2)
{
  int *v2; // eax
  int v3; // eax
  int v4; // eax
  int *v5; // eax
  _DWORD *v7; // esi
  _DWORD *v8; // edx
  int v9; // eax
  LPVOID *v10; // edi

  v2 = (int *)this[3];
  this[5] = v2;
  if ( !v2 )
    return 0;
  v3 = *v2;
  if ( !v3 )
    return 0;
  while ( v3 != a2 )
  {
    v4 = this[5];
    if ( v4 )
      this[5] = *(_DWORD *)(v4 + 4);
    v5 = (int *)this[5];
    if ( v5 )
    {
      v3 = *v5;
      if ( v3 )
        continue;
    }
    return 0;
  }
  v7 = (_DWORD *)this[3];
  v8 = 0;
  if ( v7 )
  {
    while ( *v7 != v3 )
    {
      v8 = v7;
      v7 = (_DWORD *)v7[1];
      if ( !v7 )
        return 1;
    }
    if ( v7 == (_DWORD *)this[5] )
      this[5] = v7[1];
    v9 = v7[1];
    if ( v8 )
      v8[1] = v9;
    else
      this[3] = v9;
    if ( (_DWORD *)this[4] == v7 )
      this[4] = v8;
    --this[6];
    if ( *((_BYTE *)v7 + 8) )
    {
      v10 = (LPVOID *)*v7;
      if ( *v7 )
      {
        if ( *v10 )
          sub_5BE8AE(*v10);
        sub_5BE8AE(v10);
      }
    }
    sub_5BE8AE(v7);
  }
  return 1;
}
