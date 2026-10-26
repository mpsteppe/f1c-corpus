int __cdecl sub_5118E6(_BYTE *a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+4h] [ebp-4h]

  v4 = sub_517E43(1);
  v8 = v4;
  if ( !v4 )
    return 0;
  if ( sub_58A7EC(v4, 0, v7) )
  {
    sub_517EC8(v8, *(LPVOID *)(v8 + 156));
    sub_517E85(v8);
    return 0;
  }
  sub_51184F((_DWORD *)v8, a2, a3, a4);
  if ( !a1 || *a1 != 49 )
    sub_511869(v8, (int)"Incompatible libpng version in application and library");
  *(_DWORD *)(v8 + 160) = 0x2000;
  *(_DWORD *)(v8 + 156) = sub_517E92(v8, 0x2000);
  *(_DWORD *)(v8 + 132) = sub_513C80;
  *(_DWORD *)(v8 + 136) = sub_513CD3;
  *(_DWORD *)(v8 + 140) = v8;
  v6 = sub_517AC5(v8 + 100, "1.1.3", 56);
  if ( v6 == -6 )
  {
    sub_511869(v8, (int)"zlib version error");
  }
  else if ( v6 == -4 || v6 == -2 )
  {
    sub_511869(v8, (int)"zlib memory error");
  }
  else if ( v6 )
  {
    sub_511869(v8, (int)"Unknown zlib error");
  }
  *(_DWORD *)(v8 + 112) = *(_DWORD *)(v8 + 156);
  *(_DWORD *)(v8 + 116) = *(_DWORD *)(v8 + 160);
  sub_513BF9(v8, 0, 0);
  return v8;
}
