__int16 __cdecl sub_597621(char *a1, int a2, int a3)
{
  unsigned int v4; // ecx
  int v5; // esi
  int v6; // eax
  __int16 result; // ax
  unsigned int v8; // [esp+8h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]
  int v12; // [esp+28h] [ebp+10h]

  v11 = 16462;
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = 0;
  if ( a2 )
  {
    v12 = a2;
    do
    {
      v8 = *(_DWORD *)a3;
      v9 = *(_DWORD *)(a3 + 4);
      v10 = *(_DWORD *)(a3 + 8);
      F_96BitLeftShiftBy1((_DWORD *)a3);
      F_96BitLeftShiftBy1((_DWORD *)a3);
      CRTAdd12((unsigned int *)a3, &v8);
      F_96BitLeftShiftBy1((_DWORD *)a3);
      v9 = 0;
      v10 = 0;
      v8 = *a1;
      CRTAdd12((unsigned int *)a3, &v8);
      ++a1;
      --v12;
    }
    while ( v12 );
  }
  while ( !*(_DWORD *)(a3 + 8) )
  {
    v4 = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(a3 + 8) = HIWORD(v4);
    v5 = (v4 << 16) | HIWORD(*(_DWORD *)a3);
    v6 = *(_DWORD *)a3 << 16;
    v11 += 65520;
    *(_DWORD *)(a3 + 4) = v5;
    *(_DWORD *)a3 = v6;
  }
  while ( (*(_DWORD *)(a3 + 8) & 0x8000) == 0 )
  {
    F_96BitLeftShiftBy1((_DWORD *)a3);
    v11 += 0xFFFF;
  }
  result = v11;
  *(_WORD *)(a3 + 10) = v11;
  return result;
}
