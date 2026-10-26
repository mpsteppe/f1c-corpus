void __fastcall sub_5BB390(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int v7; // eax
  const char *v8; // edx
  int v9; // ebp
  int v10; // eax
  int v11; // edx
  _BYTE *v12; // ebp
  int v13; // edx
  int j; // ebx
  int k; // [esp+10h] [ebp-110h]
  int i; // [esp+10h] [ebp-110h]
  int v17; // [esp+14h] [ebp-10Ch]
  int v18; // [esp+18h] [ebp-108h]
  _BYTE v19[256]; // [esp+1Ch] [ebp-104h] BYREF
  int v20; // [esp+11Ch] [ebp-4h]

  v20 = 0;
  if ( !a4 )
    return;
  if ( a3 == 1 || a3 == 2 )
  {
    if ( (unsigned int)(2048 - *(_DWORD *)(a2 + 2048)) < 2 )
      return;
    v17 = (*(int (__fastcall **)(int, _DWORD))(a1 + 152))(a3, *(_DWORD *)(a1 + 260));
    *(_WORD *)(a2 + *(_DWORD *)(a2 + 2048)) = htons(v17);
    *(_DWORD *)(a2 + 2048) += 2;
  }
  else
  {
    v17 = 1;
  }
  if ( a4 != 255 )
  {
    v12 = a5;
LABEL_19:
    v13 = 0;
    for ( i = 0; v13 < v17; i = v13 )
    {
      for ( j = 0; j < a4; ++j )
      {
        v18 = *(_DWORD *)(a2 + 2048);
        if ( a3 )
        {
          if ( a3 == 1 )
          {
            (*(void (__thiscall **)(_DWORD, int, _DWORD))(a1 + 140))((unsigned __int8)v12[j], a2, *(_DWORD *)(a1 + 260));
          }
          else if ( a3 == 2 )
          {
            (*(void (__thiscall **)(_DWORD, int, _DWORD))(a1 + 144))((unsigned __int8)v12[j], a2, *(_DWORD *)(a1 + 260));
          }
        }
        else
        {
          (*(void (__fastcall **)(_DWORD, int, _DWORD))(a1 + 136))((unsigned __int8)v12[j], a2, *(_DWORD *)(a1 + 260));
        }
        if ( v18 == *(_DWORD *)(a2 + 2048) )
          sub_5BABA0(a2, &byte_629120);
        v13 = i;
      }
      ++v13;
    }
    return;
  }
  (*(void (__fastcall **)(int, _BYTE *, _DWORD))(a1 + 148))(a3, v19, *(_DWORD *)(a1 + 260));
  v7 = 0;
  for ( k = 0; k < v20; ++k )
  {
    v8 = (const char *)*((_DWORD *)&off_624B98 + (unsigned __int8)v19[v7]);
    if ( !v8 )
      v8 = aUnknown_0;
    sub_5BABA0(a2, v8);
    if ( !a3 )
    {
      v9 = *(_DWORD *)(a2 + 2048);
      (*(void (__fastcall **)(_DWORD, int, _DWORD))(a1 + 136))((unsigned __int8)v19[k], a2, *(_DWORD *)(a1 + 260));
      if ( v9 == *(_DWORD *)(a2 + 2048) )
        sub_5BABA0(a2, &byte_629120);
    }
    v7 = k + 1;
  }
  v10 = *(_DWORD *)(a2 + 2048);
  if ( 2048 - v10 >= 1 )
  {
    *(_BYTE *)(v10 + a2) = 0;
    v11 = v20;
    ++*(_DWORD *)(a2 + 2048);
    a4 = v11;
    v12 = v19;
    if ( a3 )
      goto LABEL_19;
  }
}
