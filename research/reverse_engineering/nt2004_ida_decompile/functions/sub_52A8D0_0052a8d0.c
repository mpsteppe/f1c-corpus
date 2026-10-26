int __thiscall sub_52A8D0(const char *this)
{
  const char *v2; // ebx
  unsigned int v3; // kr04_4
  const char *v4; // ebp
  int result; // eax
  int v6; // [esp+0h] [ebp-1Ch]
  int v7; // [esp+18h] [ebp-4h]

  v7 = dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  v2 = this + 80;
  v3 = strlen(this + 80) + 1;
  v4 = this + 132;
  *(float *)&v6 = dbl_7DA9D0;
  sub_4D0D00((_DWORD *)v7, 2, 5, strlen(v4) + 1 + v3, 63, v6, 3);
  strcpy((char *)(v7 + 8), v2);
  strcpy((char *)(v3 + v7 + 8), v4);
  return result;
}
