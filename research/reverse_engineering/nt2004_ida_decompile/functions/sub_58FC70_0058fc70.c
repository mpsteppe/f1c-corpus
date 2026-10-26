int (__cdecl *__cdecl sub_58FC70(int a1, int a2, int a3, int a4))(_DWORD, _DWORD, _DWORD, _DWORD)
{
  int (__cdecl *result)(_DWORD, _DWORD, _DWORD, _DWORD); // eax
  int v6; // ecx
  unsigned int v7; // edx
  _BYTE *v8; // esi
  int v9; // edi
  int v10; // ebx
  int v11; // [esp+Ch] [ebp-4h] BYREF
  int v12; // [esp+14h] [ebp+4h]
  int (__cdecl *v13)(_DWORD, _DWORD, _DWORD, _DWORD); // [esp+18h] [ebp+8h]

  result = dword_7FFA08;
  if ( dword_7FFA08 )
  {
    sub_58D640(a1, &v11);
    v6 = *(_BYTE *)(a2 + 7) & 0xF;
    v7 = ((2 * *(unsigned __int8 *)(a2 + 6) + 3) & 0xFFFFFFFC) + a2 + 12;
    result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))(a2 + 4 * *(unsigned __int16 *)(a2 + 2 * a3 + 12));
    v13 = result;
    if ( v6 )
    {
      v8 = (_BYTE *)(v7 + 2);
      v12 = v6;
      do
      {
        v9 = (unsigned __int8)*(v8 - 1);
        v10 = (unsigned __int8)*(v8 - 2);
        if ( !*v8 || *v8 == 3 )
        {
          if ( sub_58FD30(v13, (unsigned __int8)*(v8 - 1)) )
            dword_7FFA08(a1, v10, *(_DWORD *)(a4 + 4 * v9), v11);
        }
        v8 += 3;
        result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))--v12;
      }
      while ( v12 );
    }
  }
  return result;
}
