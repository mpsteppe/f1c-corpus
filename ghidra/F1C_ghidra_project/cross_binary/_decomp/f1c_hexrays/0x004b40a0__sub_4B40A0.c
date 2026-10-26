// f1c  0x004b40a0  size=199
int __thiscall sub_4B40A0(_BYTE *this)
{
  int v1; // esi
  __int16 *v3; // edi
  char *v4; // eax
  int v5; // eax
  char v6; // cl

  v1 = 0;
  if ( dword_7CB218 > 0 )
  {
    v3 = word_7CB21C;
    do
    {
      if ( *v3 == 88 )
      {
        v4 = (char *)dword_5EC478;
        if ( !dword_5EC478 )
          v4 = byte_5EA438;
        if ( !sub_551FD0(0, 0, dword_8B8DD4, dword_8B8DD8, v4) )
        {
          if ( sub_423A00(byte_5EC4C0, aScreenSaved, byte_5EC4CC) )
          {
            v5 = 0;
            do
            {
              v6 = aScreenSaved[v5];
              byte_5EC4CC[v5++] = v6;
            }
            while ( v6 );
          }
          sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
        }
      }
      ++v1;
      ++v3;
    }
    while ( v1 < dword_7CB218 );
  }
  sub_4FBD70(&unk_8AFFC8);
  sub_4B3DC0(this);
  return sub_557120(dword_8AFE88);
}
