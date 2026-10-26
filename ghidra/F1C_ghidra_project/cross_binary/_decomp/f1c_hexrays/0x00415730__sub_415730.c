// f1c  0x00415730  size=73
int __thiscall sub_415730(int **this, int a2)
{
  int result; // eax
  int v4; // eax

  sub_415700(this);
  sub_4C3F80(a2);
  result = sub_4C4080(&unk_8AC388);
  if ( result )
  {
    v4 = sub_415230((char ****)this, (const char *)(result + 188), a2);
    result = sub_415650(this, v4);
    if ( result )
      *(_BYTE *)(result + 12) = 1;
  }
  return result;
}
