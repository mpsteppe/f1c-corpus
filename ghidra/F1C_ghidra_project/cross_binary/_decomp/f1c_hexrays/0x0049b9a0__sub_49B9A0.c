// f1c  0x0049b9a0  size=138
bool sub_49B9A0()
{
  int v0; // ecx
  bool v1; // bl
  char *v2; // esi

  v0 = *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580);
  v1 = v0 == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) && dbl_7C9174 > dbl_7C9204 && dword_7CEA5C;
  v2 = (char *)&unk_5EC6D8 + 18624 * v0;
  if ( !byte_5EC354[*((_DWORD *)v2 + 4645)] && v1 )
    sub_41B190((int)v2);
  byte_5EC354[*((_DWORD *)v2 + 4645)] = v1;
  return v1;
}
