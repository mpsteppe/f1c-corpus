char __thiscall sub_491A40(int *this)
{
  int v2; // ecx
  void **v3; // edx
  char result; // al
  void *v5; // edi
  int v6; // eax
  int v7; // esi
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // edx

  v2 = *this;
  v3 = *(void ***)(v2 + 16);
  result = 0;
  *(_DWORD *)(v2 + 20) = v3;
  if ( v3 )
  {
    v5 = *v3;
    if ( *v3 )
    {
      sub_490AA0(*v3);
      v6 = *this;
      v7 = *(_DWORD *)(*this + 12);
      v8 = (_DWORD *)(v6 + 12);
      v9 = 0;
      if ( v7 )
      {
        while ( *(void **)v7 != v5 )
        {
          v9 = v7;
          v7 = *(_DWORD *)(v7 + 4);
          if ( !v7 )
            return 1;
        }
        if ( v7 == v8[2] )
          v8[2] = *(_DWORD *)(v7 + 4);
        v10 = *(_DWORD *)(v7 + 4);
        if ( v9 )
          *(_DWORD *)(v9 + 4) = v10;
        else
          *v8 = v10;
        if ( v8[1] == v7 )
          v8[1] = v9;
        --v8[3];
        if ( *(_BYTE *)(v7 + 8) )
        {
          if ( *(_DWORD *)v7 )
            sub_587BCF(*(LPVOID *)v7);
        }
        sub_587BCF((LPVOID)v7);
      }
      return 1;
    }
  }
  return result;
}
