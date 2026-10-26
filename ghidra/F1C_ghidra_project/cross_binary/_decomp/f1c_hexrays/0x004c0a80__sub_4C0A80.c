// f1c  0x004c0a80  size=44
int __thiscall sub_4C0A80(_DWORD *this)
{
  char *v1; // eax
  int v2; // eax

  v1 = (char *)this[2];
  if ( !v1 )
    v1 = byte_5EA438;
  sub_4C3F80(v1);
  v2 = sub_4C4080(&unk_8AC388);
  if ( v2 )
    return v2 + 124;
  else
    return 0;
}
