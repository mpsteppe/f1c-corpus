// f1c  0x005654a0  size=120
int __thiscall sub_5654A0(char *this, int a2, char *a3)
{
  char *v4; // eax
  char v5; // cl
  int v6; // eax
  const char *v7; // eax

  v4 = this + 408;
  do
  {
    v5 = *v4;
    *(v4 - 408) = *v4;
    ++v4;
  }
  while ( v5 );
  v6 = sub_5897CA(this, asc_5C30AC);
  *((_DWORD *)this + 96) = v6;
  if ( !v6 )
    return 0;
  if ( sub_588410(v6, a2) )
    return 0;
  v7 = (const char *)sub_5897CA(0, asc_5C64D4);
  *((_DWORD *)this + 96) = v7;
  if ( !v7 )
    return 0;
  strcpy(a3, v7);
  return 1;
}
