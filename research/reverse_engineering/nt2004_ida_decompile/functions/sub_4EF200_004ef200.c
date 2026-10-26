int __thiscall sub_4EF200(int this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  int result; // eax
  int i; // esi
  _DWORD *v8; // ebp
  char v9; // al
  LPVOID *v10; // edi

  v2 = *(_DWORD *)(this + 4);
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          sub_5BE8AE(*v5);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  sub_4EF370(this);
  result = *(_DWORD *)(this + 32);
  if ( result )
    result = sub_5BE8AE(*(LPVOID *)(this + 32));
  for ( i = *(_DWORD *)(this + 4); i; result = sub_5BE8AE(v8) )
  {
    v8 = (_DWORD *)i;
    v9 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v9 )
    {
      v10 = (LPVOID *)*v8;
      if ( *v8 )
      {
        if ( *v10 )
          sub_5BE8AE(*v10);
        sub_5BE8AE(v10);
      }
    }
  }
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  return result;
}
