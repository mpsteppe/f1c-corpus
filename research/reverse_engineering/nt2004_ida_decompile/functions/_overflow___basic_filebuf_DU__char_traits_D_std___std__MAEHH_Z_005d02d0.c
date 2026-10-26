int __thiscall std::filebuf::overflow(int this, int a2)
{
  unsigned int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  size_t v10; // edi
  int v11; // ebx
  int v12; // [esp+Ch] [ebp-10h] BYREF
  char *v13; // [esp+10h] [ebp-Ch] BYREF
  int v14; // [esp+14h] [ebp-8h]
  char v15; // [esp+1Bh] [ebp-1h] BYREF
  char vars0; // [esp+1Ch] [ebp+0h] BYREF

  if ( a2 == -1 )
    return 0;
  v4 = **(_DWORD **)(this + 32);
  if ( v4 && v4 < v4 + **(_DWORD **)(this + 48) )
  {
    *(_BYTE *)unknown_libname_187(this) = a2;
    return a2;
  }
  if ( !*(_DWORD *)(this + 80) )
    return -1;
  if ( !*(_DWORD *)(this + 56) )
  {
    if ( fputc((char)a2, *(FILE **)(this + 80)) != -1 )
      return a2;
    return -1;
  }
  v15 = a2;
  std::string::erase(0, -1);
  std::string::append(8u, 0);
  v5 = *(_DWORD *)(this + 68);
  std::string::_Freeze(v5);
  v6 = *(_DWORD *)(this + 68);
  v14 = *(_DWORD *)(v5 + 4);
  std::string::_Freeze(v6);
  v7 = (*(int (__thiscall **)(_DWORD, int, char *, char *, char **, _DWORD, int, int *))(**(_DWORD **)(this + 56) + 20))(
         *(_DWORD *)(this + 56),
         this + 64,
         &v15,
         &vars0,
         &v13,
         *(_DWORD *)(v6 + 4),
         v14 != 0 ? v14 + *(_DWORD *)(v5 + 8) : 0,
         &v12);
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 2 && fputc(v15, *(FILE **)(this + 80)) != -1 )
        return a2;
      return -1;
    }
    if ( v13 == &v15 )
      return -1;
  }
  v9 = *(_DWORD *)(this + 68);
  std::string::_Freeze(v9);
  v10 = v12 - *(_DWORD *)(v9 + 4);
  v11 = *(_DWORD *)(this + 68);
  std::string::_Freeze(v11);
  if ( sub_5BF5A6(*(void **)(v11 + 4), 1u, v10, *(FILE **)(this + 80)) == v10 )
    return a2;
  return -1;
}
