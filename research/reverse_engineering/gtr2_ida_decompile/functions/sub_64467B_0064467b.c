int __stdcall sub_64467B(int a1, int a2, int a3, _DWORD *a4)
{
  unsigned int v4; // ebx
  _DWORD *v5; // edi
  _DWORD *v6; // esi
  unsigned int v7; // eax
  _DWORD v9[76]; // [esp+Ch] [ebp-154h] BYREF
  _BYTE v10[12]; // [esp+13Ch] [ebp-24h] BYREF
  int v11; // [esp+148h] [ebp-18h]
  _BYTE v12[16]; // [esp+14Ch] [ebp-14h] BYREF
  int v13; // [esp+15Ch] [ebp-4h] BYREF

  v13 = 0;
  sub_5AF533(1);
  if ( a1 )
  {
    (*(void (__stdcall **)(int, int *))(*(_DWORD *)a1 + 24))(a1, &v13);
    (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)a1 + 28))(a1, v9);
    (*(void (__stdcall **)(int, _DWORD, _BYTE *))(*(_DWORD *)a1 + 32))(a1, 0, v10);
    if ( (a2 & 0x100000) != 0 )
    {
      (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)a1 + 36))(a1, v12);
      if ( (v12[12] & 0x20) != 0 )
        a2 |= 0x10u;
    }
  }
  v4 = -1;
  v5 = &unk_735FE8;
  v6 = &unk_736010;
  if ( off_913B0C > &unk_736010 )
  {
    do
    {
      if ( *v6
        && (!v13
         || (*(int (__stdcall **)(int, _DWORD, _DWORD, int, int, int, _DWORD))(*(_DWORD *)v13 + 40))(
              v13,
              v9[1],
              v9[0],
              v11,
              a2,
              a3,
              *v6) >= 0) )
      {
        if ( *a4 == *v6 )
        {
          v5 = v6;
          break;
        }
        if ( v6[8] )
        {
          v7 = sub_644593((int)a4, (int)v6);
          if ( v7 != -1 && v7 <= v4 && (v7 != v4 || v6[2] < v5[2]) )
          {
            v4 = v7;
            v5 = v6;
          }
        }
      }
      v6 += 9;
    }
    while ( v6 < (_DWORD *)off_913B0C );
  }
  if ( v13 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v13 + 8))(v13);
    v13 = 0;
  }
  sub_5AF533(0);
  return *v5;
}
