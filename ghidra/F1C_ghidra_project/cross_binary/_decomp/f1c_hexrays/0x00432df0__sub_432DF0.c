// f1c  0x00432df0  size=94
int __thiscall sub_432DF0(const char **this, int a2)
{
  int v3; // eax
  const char *v4; // edx
  unsigned int v5; // kr04_4
  const char *i; // eax

  v3 = sub_4B0B10(a2);
  sub_566650(v3);
  v4 = *this;
  if ( !*this )
    v4 = &byte_5EA438;
  v5 = strlen(v4) + 1;
  if ( (int)(v5 - 1) > 0 )
  {
    for ( i = &v4[v5 - 2]; i >= v4; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  return sub_5665B0(off_5C3F9C[0]);
}
