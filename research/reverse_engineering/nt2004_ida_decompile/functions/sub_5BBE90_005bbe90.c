char __fastcall sub_5BBE90(int a1, int a2, char *a3, int a4)
{
  int v4; // edi
  char result; // al
  _BYTE *v7; // esi
  int v8; // ebp
  int v9; // edi
  char v10; // al
  int v12; // [esp+18h] [ebp+8h]

  v4 = a1;
  result = *a3;
  if ( !*a3 )
  {
    v7 = a3 + 5;
    v12 = a4 - 5;
    if ( (*(_BYTE *)(a2 + 20) & 4) != 0 )
    {
      v8 = 0;
      if ( *(int *)(a1 + 60) > 0 )
      {
        do
        {
          v9 = sub_5BC130(v7, v12);
          if ( v9 < 0 )
            break;
          sub_5BA0E0((_DWORD *)a2, (int)v7);
          v7 += v9;
          ++v8;
          v12 -= v9;
        }
        while ( v8 < *(_DWORD *)(a1 + 60) );
        v4 = a1;
      }
      v10 = *(_BYTE *)(a2 + 20) | 1;
    }
    else
    {
      sub_5BA350((_DWORD *)a2, v7, v12);
      v10 = *(_BYTE *)(a2 + 20) | 3;
    }
    *(_BYTE *)(a2 + 20) = v10;
    *(_BYTE *)(a2 + 20) = v10 & 0xF3;
    *(_DWORD *)(a2 + 28) = GetTickCount() - *(_DWORD *)(a2 + 28);
    sub_5BBF60(v4 + 8, a2);
    return (*(int (__fastcall **)(int, _DWORD, int, _DWORD))(v4 + 64))(v4, 0, a2, *(_DWORD *)(v4 + 68));
  }
  return result;
}
