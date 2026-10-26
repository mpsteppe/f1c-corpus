int __thiscall sub_4EEAE0(int this, int a2)
{
  int v2; // esi
  const char *v4; // esi
  int result; // eax

  v2 = dword_7D6A5C + 1232 * a2;
  sub_4EDDD0((char *)this, (char *)(v2 + 246));
  strncpy((char *)(this + 24836), (const char *)(v2 + 438), 0x3Fu);
  *(_BYTE *)(this + 24899) = 0;
  strncpy((char *)(this + 24900), (const char *)(v2 + 136), 7u);
  *(_BYTE *)(this + 24907) = 0;
  strncpy((char *)(this + 24908), (const char *)(v2 + 182), 0x3Fu);
  *(_BYTE *)(this + 24971) = 0;
  *(_DWORD *)(this + 24988) = atol((const char *)(v2 + 168));
  *(_DWORD *)(this + 25256) = atol((const char *)(v2 + 175));
  v4 = *(const char **)v2;
  if ( !v4 )
    v4 = &byte_629120;
  strcpy((char *)(this + 24992), v4);
  result = a2;
  *(_DWORD *)(this + 25252) = a2;
  return result;
}
