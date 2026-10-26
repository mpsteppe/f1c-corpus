int __thiscall sub_40CC40(_DWORD *this)
{
  int v2; // esi
  int result; // eax
  _DWORD *v4; // edi
  char v5; // cl
  void *v6; // ebx
  int v7; // esi
  _DWORD *v8; // edi
  char v9; // al
  void *v10; // ebx

  *this = &off_5D5828;
  sub_57A7A0(this + 11);
  v2 = this[5];
  for ( result = 0; v2; result = 0 )
  {
    v4 = (_DWORD *)v2;
    v5 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v5 )
    {
      v6 = (void *)*v4;
      if ( *v4 )
      {
        sub_40D5C0(*v4);
        sub_5BE8AE(v6);
      }
    }
    sub_5BE8AE(v4);
  }
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  v7 = this[1];
  if ( v7 )
  {
    do
    {
      v8 = (_DWORD *)v7;
      v9 = *(_BYTE *)(v7 + 8);
      v7 = *(_DWORD *)(v7 + 4);
      if ( v9 )
      {
        v10 = (void *)*v8;
        if ( *v8 )
        {
          sub_40EB10(*v8);
          sub_5BE8AE(v10);
        }
      }
      sub_5BE8AE(v8);
    }
    while ( v7 );
    result = 0;
  }
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  *this = off_5D58A0;
  return result;
}
