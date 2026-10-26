int __fastcall sub_5BB620(int a1, int a2, int a3)
{
  int v3; // edi
  int result; // eax
  const char *v7; // ebx
  int v8; // edi
  int i; // edi
  int v10; // [esp+Ch] [ebp-190h]
  int v11; // [esp+10h] [ebp-18Ch]
  int v12; // [esp+14h] [ebp-188h]
  _BYTE v13[256]; // [esp+18h] [ebp-184h] BYREF
  int v14; // [esp+118h] [ebp-84h]
  char Buffer[128]; // [esp+11Ch] [ebp-80h] BYREF

  v3 = a3;
  v14 = 0;
  if ( a3 == 1 || a3 == 2 )
    v11 = (*(int (__fastcall **)(int, _DWORD))(a1 + 152))(a3, *(_DWORD *)(a1 + 260));
  else
    v11 = 1;
  (*(void (__fastcall **)(int, _BYTE *, _DWORD))(a1 + 148))(a3, v13, *(_DWORD *)(a1 + 260));
  result = 0;
  v10 = 0;
  if ( v14 > 0 )
  {
    while ( 1 )
    {
      v7 = (const char *)*((_DWORD *)&off_624B98 + (unsigned __int8)v13[result]);
      if ( !v7 )
        v7 = aUnknown_0;
      if ( v3 )
      {
        for ( i = 0; i < v11; *(_BYTE *)(*(_DWORD *)(a2 + 2048) + a2 - 1) = 92 )
        {
          sprintf(Buffer, "%s%d", v7, i);
          sub_5BABA0(a2, Buffer);
          *(_BYTE *)(*(_DWORD *)(a2 + 2048) + a2 - 1) = 92;
          v12 = *(_DWORD *)(a2 + 2048);
          if ( a3 == 1 )
          {
            (*(void (__fastcall **)(_DWORD, int, int, _DWORD))(a1 + 140))(
              (unsigned __int8)v13[v10],
              i,
              a2,
              *(_DWORD *)(a1 + 260));
          }
          else if ( a3 == 2 )
          {
            (*(void (__fastcall **)(_DWORD, int, int, _DWORD))(a1 + 144))(
              (unsigned __int8)v13[v10],
              i,
              a2,
              *(_DWORD *)(a1 + 260));
          }
          if ( v12 == *(_DWORD *)(a2 + 2048) )
            sub_5BABA0(a2, &byte_629120);
          ++i;
        }
      }
      else
      {
        sub_5BABA0(a2, v7);
        *(_BYTE *)(*(_DWORD *)(a2 + 2048) + a2 - 1) = 92;
        v8 = *(_DWORD *)(a2 + 2048);
        (*(void (__fastcall **)(_DWORD, int, _DWORD))(a1 + 136))((unsigned __int8)v13[v10], a2, *(_DWORD *)(a1 + 260));
        if ( v8 == *(_DWORD *)(a2 + 2048) )
          sub_5BABA0(a2, &byte_629120);
        *(_BYTE *)(*(_DWORD *)(a2 + 2048) + a2 - 1) = 92;
      }
      result = ++v10;
      if ( v10 >= v14 )
        break;
      v3 = a3;
    }
  }
  return result;
}
