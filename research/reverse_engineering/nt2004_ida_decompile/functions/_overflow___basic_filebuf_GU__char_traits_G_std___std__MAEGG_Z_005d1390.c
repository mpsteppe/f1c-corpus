__int16 __thiscall std::basic_filebuf<unsigned short>::overflow(int this, int Character)
{
  __int16 result; // ax
  unsigned int v4; // eax
  bool v5; // zf
  _DWORD *v6; // ecx
  _DWORD *v7; // edi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // ebx
  size_t v12; // edi
  int v13; // ebx
  int v14; // [esp+Ch] [ebp-10h] BYREF
  wchar_t *v15; // [esp+10h] [ebp-Ch] BYREF
  int v16; // [esp+14h] [ebp-8h]
  wchar_t v17[2]; // [esp+18h] [ebp-4h] BYREF

  if ( (_WORD)Character == 0xFFFF )
    return 0;
  v4 = **(_DWORD **)(this + 32);
  if ( v4 && v4 < v4 + 2 * **(_DWORD **)(this + 48) )
  {
    *(_WORD *)unknown_libname_195(this) = Character;
    return Character;
  }
  if ( !*(_DWORD *)(this + 80) )
    return -1;
  if ( !*(_DWORD *)(this + 56) )
  {
    v5 = fputwc(Character, *(FILE **)(this + 80)) == 0xFFFF;
    result = Character;
    goto LABEL_14;
  }
  v6 = *(_DWORD **)(this + 68);
  *(_DWORD *)v17 = Character;
  std::string::erase(v6, 0, 0xFFFFFFFF);
  std::string::append(*(_DWORD **)(this + 68), 8u, 0);
  v7 = *(_DWORD **)(this + 68);
  std::string::_Freeze(v7);
  v8 = *(_DWORD **)(this + 68);
  v16 = v7[1];
  std::string::_Freeze(v8);
  v9 = (*(int (__thiscall **)(_DWORD, int, wchar_t *, wchar_t *, wchar_t **, _DWORD, int, int *))(**(_DWORD **)(this + 56)
                                                                                                + 20))(
         *(_DWORD *)(this + 56),
         this + 64,
         v17,
         &v17[1],
         &v15,
         v8[1],
         v16 != 0 ? v16 + v7[2] : 0,
         &v14);
  if ( !v9 )
    goto LABEL_17;
  v10 = v9 - 1;
  if ( !v10 )
  {
    if ( v15 == v17 )
      return -1;
LABEL_17:
    v11 = *(_DWORD **)(this + 68);
    std::string::_Freeze(v11);
    v12 = v14 - v11[1];
    v13 = *(_DWORD *)(this + 68);
    std::string::_Freeze((_DWORD *)v13);
    v5 = sub_5BF5A6(*(void **)(v13 + 4), 1u, v12, *(FILE **)(this + 80)) == v12;
    result = Character;
    if ( v5 )
      return result;
    return -1;
  }
  if ( v10 != 2 )
    return -1;
  v5 = fputwc(v17[0], *(FILE **)(this + 80)) == 0xFFFF;
  result = Character;
LABEL_14:
  if ( !v5 )
    return result;
  return -1;
}
