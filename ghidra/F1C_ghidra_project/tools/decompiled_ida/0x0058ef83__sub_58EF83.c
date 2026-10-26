// Address: 0x0058ef83
// Size: 145 bytes
// Name: sub_58EF83
// Type: int()
// Source: IDA Hex-Rays decompilation

int sub_58EF83()
{
  void *v0; // eax
  void *v1; // esi

  if ( dword_8D3F44 )
  {
    v0 = (void *)sub_58AB58(1, 172);
    v1 = v0;
    if ( !v0 )
      return 1;
    if ( sub_58F014(v0) )
    {
      sub_58F362(v1);
      sub_58AA6F(v1);
      return 1;
    }
    off_5E99D0 = (_UNKNOWN ***)v1;
    sub_58F362(dword_8D3F58);
    sub_58AA6F(dword_8D3F58);
    dword_8D3F58 = v1;
  }
  else
  {
    off_5E99D0 = (_UNKNOWN ***)off_5E99D8;
    sub_58F362(dword_8D3F58);
    sub_58AA6F(dword_8D3F58);
    dword_8D3F58 = 0;
  }
  return 0;
}
