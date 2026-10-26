int __cdecl sub_58F6F0(int a1, int a2, int a3, int a4, char a5, const void *a6)
{
  int result; // eax
  int v7; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edi
  _WORD *v12; // ecx
  int v13; // eax
  __int16 v14; // dx

  result = a2;
  if ( dword_7E4848 < 0 || dword_7E4848 == a2 )
  {
    v7 = dword_7E484C;
    if ( dword_7E484C++ < 8 )
    {
      dword_7E4848 = a2;
      v9 = 23 * v7;
      dword_7E49D4[v9] = a3;
      dword_7E49D8[v9] = a4;
      byte_7E49DC[v9 * 4] = a5;
      qmemcpy(&dword_7E49E0[23 * v7], a6, 0x50u);
      byte_7E49DD[v9 * 4] = 1;
      v10 = *(unsigned __int8 *)(a4 + 4) >> 2;
      if ( v10 )
      {
        v11 = *(unsigned __int8 *)(a4 + 4) >> 2;
        v12 = (_WORD *)(8 * dword_7E4850 + 8276054);
        v13 = a1 + 6;
        do
        {
          v14 = *(_WORD *)(v13 - 6);
          v13 += 8;
          *(v12 - 1) = v14;
          *v12 = *(_WORD *)(v13 - 12);
          v12 += 4;
          --v11;
          *(v12 - 3) = *(unsigned __int8 *)(*(unsigned __int8 *)(v13 - 8) + a1 + 98);
        }
        while ( v11 );
      }
      result = v10 + dword_7E4850;
      dword_7E4850 += v10;
    }
  }
  return result;
}
