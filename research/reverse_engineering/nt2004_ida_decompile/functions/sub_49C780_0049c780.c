void __thiscall sub_49C780(_DWORD *this)
{
  _DWORD *v2; // esi
  void *v3; // edi
  _DWORD *v4; // esi
  void *v5; // edi
  _DWORD *v6; // esi
  void *v7; // edi
  _DWORD *v8; // esi
  void *v9; // edi
  Concurrency::details::VirtualProcessor *i; // esi
  int v11; // esi
  LPVOID **v12; // ebp
  char v13; // al
  LPVOID *v14; // edi

  v2 = (_DWORD *)this[62];
  while ( v2 )
  {
    v3 = v2;
    v2 = (_DWORD *)v2[6];
    sub_4B1280(v3);
    sub_5BE8AE(v3);
  }
  v4 = (_DWORD *)this[63];
  while ( v4 )
  {
    v5 = v4;
    v4 = (_DWORD *)v4[6];
    sub_4B1280(v5);
    sub_5BE8AE(v5);
  }
  v6 = (_DWORD *)this[64];
  while ( v6 )
  {
    v7 = v6;
    v6 = (_DWORD *)v6[6];
    sub_4B1280(v7);
    sub_5BE8AE(v7);
  }
  v8 = (_DWORD *)this[65];
  while ( v8 )
  {
    v9 = v8;
    v8 = (_DWORD *)v8[6];
    sub_4B1280(v9);
    sub_5BE8AE(v9);
  }
  for ( i = (Concurrency::details::VirtualProcessor *)this[36]; i; i = (Concurrency::details::VirtualProcessor *)this[36] )
  {
    this[36] = Concurrency::details::VirtualProcessor::GetExecutionResourceId(i);
    (**(void (__thiscall ***)(Concurrency::details::VirtualProcessor *, int))i)(i, 1);
  }
  this[36] = 0;
  v11 = this[17];
  while ( v11 )
  {
    v12 = (LPVOID **)v11;
    v13 = *(_BYTE *)(v11 + 8);
    v11 = *(_DWORD *)(v11 + 4);
    if ( v13 )
    {
      v14 = *v12;
      if ( *v12 )
      {
        if ( *v14 )
          sub_5BE8AE(*v14);
        sub_5BE8AE(v14);
      }
    }
    sub_5BE8AE(v12);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
}
