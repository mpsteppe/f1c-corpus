int __thiscall sub_491BD0(int *this)
{
  int v2; // eax
  void **v3; // ecx
  int result; // eax
  void *v5; // ecx
  int v6; // ecx
  int v7; // eax
  int v8; // ebp
  int v9; // esi
  _DWORD *i; // ebp
  LPVOID *v11; // edi
  char v12; // al

  v2 = *this;
  v3 = *(void ***)(*this + 12);
  result = v2 + 12;
  *(_DWORD *)(result + 8) = v3;
  if ( v3 )
  {
    v5 = *v3;
    if ( v5 )
    {
      do
      {
        LinkedListNodePrepend(v5);
        v6 = *(_DWORD *)(*this + 20);
        v7 = *this + 12;
        if ( v6 )
          *(_DWORD *)(*this + 20) = *(_DWORD *)(v6 + 4);
        result = *(_DWORD *)(v7 + 8);
        if ( !result )
          break;
        v5 = *(void **)result;
      }
      while ( *(_DWORD *)result );
    }
  }
  v8 = *this;
  v9 = *(_DWORD *)(*this + 12);
  for ( i = (_DWORD *)(v8 + 12); v9; result = FreeWrapper_7bcf(v11) )
  {
    v11 = (LPVOID *)v9;
    v12 = *(_BYTE *)(v9 + 8);
    v9 = *(_DWORD *)(v9 + 4);
    if ( v12 && *v11 )
      FreeWrapper_7bcf(*v11);
  }
  *i = 0;
  i[1] = 0;
  i[2] = 0;
  i[3] = 0;
  return result;
}
