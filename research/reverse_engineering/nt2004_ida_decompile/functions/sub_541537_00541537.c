int __thiscall sub_541537(_DWORD *this)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  void *v7; // eax
  void *v8; // eax
  unsigned int v9; // ebx
  unsigned int i; // edi
  _DWORD *v11; // ecx
  unsigned int j; // edi
  _DWORD *v13; // ecx
  unsigned int v14; // eax
  unsigned int k; // edi
  unsigned int v16; // [esp+4h] [ebp-20h]
  unsigned int v17; // [esp+8h] [ebp-1Ch]
  unsigned int v18; // [esp+Ch] [ebp-18h]
  int v19; // [esp+Ch] [ebp-18h]
  void *v20; // [esp+Ch] [ebp-18h]
  void *v21; // [esp+10h] [ebp-14h]
  void *v22; // [esp+10h] [ebp-14h]
  unsigned int v23; // [esp+10h] [ebp-14h]
  void *v24; // [esp+14h] [ebp-10h]

  if ( *((_BYTE *)this + 8) != 1 )
    return -2147467259;
  v3 = (_DWORD *)this[1];
  v4 = (_DWORD *)*this;
  v18 = v3[1046];
  if ( v18 <= v4[1046] )
    v18 = v4[1046];
  v16 = v3[1047];
  if ( v16 >= v4[1047] )
    v16 = v4[1047];
  v5 = v4[1048];
  v17 = v3[1048];
  if ( v17 >= v5 )
    v17 = v5;
  v6 = 16 * v18;
  v7 = operator new(16 * v18);
  v21 = v7;
  if ( v7 )
  {
    sub_53D688((int)v7, 16, v18, (int (__thiscall *)(int))sub_53D5B2);
    v24 = v21;
  }
  else
  {
    v24 = 0;
  }
  if ( !v24 )
    return -2147467259;
  v19 = *(_DWORD *)(this[1] + 4184);
  v8 = operator new(16 * v19);
  v22 = v8;
  if ( v8 )
  {
    sub_53D688((int)v8, 16, v19, (int (__thiscall *)(int))sub_53D5B2);
    v20 = v22;
  }
  else
  {
    v20 = 0;
  }
  if ( v20 )
  {
    v9 = v17;
    v23 = 0;
    memset(v24, 0, v6);
    memset(v20, 0, 16 * *(_DWORD *)(this[1] + 4184));
    if ( v17 )
    {
      do
      {
        for ( i = 0; i < v16; ++i )
        {
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)*this + 4))(
            *this,
            i,
            v23,
            v24);
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)this[1] + 8))(
            this[1],
            i,
            v23,
            v24);
        }
        v11 = (_DWORD *)this[1];
        for ( j = v16; j < v11[1047]; ++j )
        {
          (*(void (__thiscall **)(_DWORD *, unsigned int, unsigned int, void *))(*v11 + 8))(v11, j, v23, v20);
          v11 = (_DWORD *)this[1];
        }
        v9 = v17;
        ++v23;
      }
      while ( v23 < v17 );
    }
    v13 = (_DWORD *)this[1];
    if ( v9 < v13[1048] )
    {
      v14 = v13[1047];
      do
      {
        for ( k = 0; k < v14; ++k )
        {
          (*(void (__thiscall **)(_DWORD *, unsigned int, unsigned int, void *))(*v13 + 8))(v13, k, v9, v20);
          v13 = (_DWORD *)this[1];
          v14 = v13[1047];
        }
        v13 = (_DWORD *)this[1];
        ++v9;
      }
      while ( v9 < v13[1048] );
    }
    sub_5BE8AE();
    sub_5BE8AE();
    return 0;
  }
  else
  {
    sub_5BE8AE();
    return -2147467259;
  }
}
