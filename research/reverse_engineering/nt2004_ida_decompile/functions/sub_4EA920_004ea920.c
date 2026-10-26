int __thiscall sub_4EA920(int *this)
{
  int result; // eax
  void *v3; // edi
  _DWORD **v4; // ecx
  void *v5; // edi
  int i; // edi
  void **v7; // ebp
  bool v8; // zf
  int j; // edi
  void **v10; // ebp
  int k; // edi
  LPVOID **v12; // ebp
  _DWORD *m; // edi
  _BYTE *v14; // ebp
  void *v15; // [esp+10h] [ebp-4h]
  void *v16; // [esp+10h] [ebp-4h]

  result = sub_4EC230(this);
  v3 = (void *)this[24];
  if ( v3 )
  {
    sub_4EAAC0(this[24]);
    result = sub_5BE8AE(v3);
    this[24] = 0;
  }
  v4 = (_DWORD **)this[25];
  if ( v4 )
  {
    result = sub_41C880(v4);
    v5 = (void *)this[25];
    if ( v5 )
    {
      sub_41C880((_DWORD **)this[25]);
      result = sub_5BE8AE(v5);
    }
    this[25] = 0;
  }
  for ( i = *this; i; result = sub_5BE8AE(v7) )
  {
    v7 = (void **)i;
    v8 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v8 )
    {
      v15 = *v7;
      if ( *v7 )
      {
        sub_4EDCB0();
        sub_5BE8AE(v15);
      }
    }
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  for ( j = this[4]; j; result = sub_5BE8AE(v10) )
  {
    v10 = (void **)j;
    v8 = *(_BYTE *)(j + 8) == 0;
    j = *(_DWORD *)(j + 4);
    if ( !v8 )
    {
      v16 = *v10;
      if ( *v10 )
      {
        sub_4EAA70();
        sub_5BE8AE(v16);
      }
    }
  }
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  for ( k = this[12]; k; result = sub_5BE8AE(v12) )
  {
    v12 = (LPVOID **)k;
    v8 = *(_BYTE *)(k + 8) == 0;
    k = *(_DWORD *)(k + 4);
    if ( !v8 && *v12 )
      sub_4115A0(*v12, 1);
  }
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  for ( m = (_DWORD *)this[16]; m; result = sub_5BE8AE(v14) )
  {
    v14 = m;
    m = (_DWORD *)m[1];
    sub_4145A0(v14);
  }
  this[16] = 0;
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  return result;
}
