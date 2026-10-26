int __thiscall sub_4FBC40(_DWORD *Buffer)
{
  int v3; // esi
  int v4; // esi
  int v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  sub_59EF10(&v6, 2048);
  if ( v6 >= 48 )
  {
    if ( v6 == 48 )
    {
      v3 = *((_DWORD *)off_5FD348 + 4146);
      sub_59EF10(&v5, 2048);
      if ( v3 == 1 && sub_4BBFC0(&unk_766220, v5) )
      {
        v4 = dword_7D3C44;
        if ( dword_79FC40 < 1023 )
        {
          ++dword_79FC40;
          dword_7D3C44 += 208;
        }
        sub_4D0D00((_DWORD *)v4, 4, 8, 8, v6, 0, 0);
        *(_DWORD *)(v4 + 8) = 0;
        *(_WORD *)(v4 + 12) = v5;
        *(_WORD *)(v4 + 14) = -1;
      }
    }
    sub_5A1290(Buffer[5]);
    return 0;
  }
  else
  {
    sub_4DD1C0((int)&unk_6310CC + 25304 * v6, (int)Buffer);
    sub_59EF10(&v5, 2048);
    sub_421590((int)&unk_62BF68 + 25304 * v6, v5 + 1, 0);
    sub_5A1290(Buffer[5]);
    return 0;
  }
}
