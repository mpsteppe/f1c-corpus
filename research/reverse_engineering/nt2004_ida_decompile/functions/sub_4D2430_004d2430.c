int __thiscall sub_4D2430(_BYTE *this)
{
  int v2; // edi
  __int16 *v3; // ebx
  bool v4; // zf

  v2 = 0;
  v3 = word_762A08;
  while ( v2 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
  {
    if ( *v3 != 8226 )
      goto LABEL_7;
    v4 = byte_7D4488 != 0;
    byte_7D4488 = byte_7D4488 == 0;
    if ( v4 )
    {
      sub_4D20D0(10, 2, 0x40000000, 0);
      ++v2;
      ++v3;
    }
    else
    {
      sub_4D20D0(2, 4, 1065353216, 1);
      sub_4D20D0(4, 2, 1045220557, 0);
LABEL_7:
      ++v2;
      ++v3;
    }
  }
  sub_52A110(&unk_7DABA0);
  sub_4D2140(this);
  return sub_5AE8C0(dword_7DA9B8);
}
