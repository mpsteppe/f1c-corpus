// f1c  0x00491fb0  size=117
int __thiscall sub_491FB0(_DWORD *this)
{
  int v2; // eax

  if ( !sub_5351D0(256) )
    return 0;
  while ( 1 )
  {
    ++this[99];
    v2 = sub_5651B0(&unk_7CD9D8);
    if ( v2 != 1 && (v2 <= 2 || v2 > 4) )
      break;
    ++this[100];
    if ( !sub_5351D0(256) )
      return 0;
  }
  return 1;
}
