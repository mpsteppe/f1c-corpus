int __cdecl sub_58DE40(int a1, int a2)
{
  int v2; // edi
  BOOL v3; // ebx
  char *v4; // esi
  int v5; // ebp
  unsigned int v6; // edi
  int v7; // eax
  unsigned int v9; // [esp+10h] [ebp-28h]
  unsigned int v10; // [esp+14h] [ebp-24h]
  unsigned __int16 v11; // [esp+18h] [ebp-20h]
  int v12; // [esp+1Ch] [ebp-1Ch]
  int v13; // [esp+20h] [ebp-18h]
  int v14; // [esp+24h] [ebp-14h]
  int v15; // [esp+28h] [ebp-10h]
  int v16; // [esp+2Ch] [ebp-Ch]
  int v17; // [esp+30h] [ebp-8h] BYREF
  int v18; // [esp+34h] [ebp-4h] BYREF

  v2 = dword_7FF9FC + sub_58FC30();
  v3 = 0;
  v16 = v2;
  v15 = 0;
  v12 = -1;
  v10 = -1;
  v11 = 0;
  v9 = 0;
  v4 = byte_7FFAAB;
  while ( 1 )
  {
    if ( *(v4 - 1) && (unsigned __int8)*v4 == a2 && !*(_WORD *)(v4 + 1) )
    {
      v5 = *(_DWORD *)(v4 + 5);
      v13 = 0;
      v14 = 1;
      if ( a1 )
        v14 = sub_58DFD0(*(_WORD *)v5, a1);
      v6 = v2 - *(_DWORD *)(v4 - 7);
      if ( *(_WORD *)(v5 + 2) && v6 > *(unsigned __int16 *)(v5 + 2) )
        v13 = 1;
      if ( dword_7FFA20[a2] == 1 && (*(_BYTE *)(v5 + 10) & 1) != 0 )
      {
        v17 = *(_DWORD *)(v4 + 9);
        v3 = 0;
        if ( sub_58D5A0((int)&v17, &v18) )
          v3 = *(_WORD *)(v5 + 4) < *(_WORD *)(*(_DWORD *)v18 + 22);
      }
      if ( v13 )
      {
        sub_58DB10(v9);
      }
      else if ( v14 && !v3 )
      {
        v7 = *(unsigned __int16 *)(v5 + 4);
        if ( (unsigned __int16)v7 <= v15 )
        {
          if ( (unsigned __int16)v7 == v15 && (v6 < v10 || v6 == v10 && *(_WORD *)(v4 - 3) > v11) )
          {
            v12 = v9;
            v10 = v6;
            v11 = *(_WORD *)(v4 - 3);
          }
        }
        else
        {
          v12 = v9;
          v10 = v6;
          v11 = *(_WORD *)(v4 - 3);
          v15 = *(unsigned __int16 *)(v5 + 4);
        }
      }
    }
    v4 += 96;
    ++v9;
    if ( (int)v4 >= (int)&unk_8000AB )
      break;
    v2 = v16;
    v3 = 0;
  }
  return v12;
}
