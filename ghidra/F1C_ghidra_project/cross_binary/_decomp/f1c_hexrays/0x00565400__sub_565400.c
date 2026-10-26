// f1c  0x00565400  size=150
BOOL __thiscall sub_565400(char *this, int a2)
{
  char *v3; // eax
  char v4; // cl
  int v5; // eax
  int v6; // eax
  int v8; // eax

  v3 = this + 408;
  do
  {
    v4 = *v3;
    *(v3 - 408) = *v3;
    ++v3;
  }
  while ( v4 );
  v5 = sub_5897CA(this, asc_5C30AC);
  *((_DWORD *)this + 96) = v5;
  if ( !v5 )
    return 0;
  while ( sub_588410(*((_DWORD *)this + 96), a2) )
  {
    *((_DWORD *)this + 96) = sub_5897CA(0, &word_5C32D8);
    v6 = sub_5897CA(0, asc_5C30AC);
    *((_DWORD *)this + 96) = v6;
    if ( !v6 )
      return 0;
  }
  v8 = sub_5897CA(0, &word_5C32D8);
  *((_DWORD *)this + 96) = v8;
  return v8 != 0;
}
