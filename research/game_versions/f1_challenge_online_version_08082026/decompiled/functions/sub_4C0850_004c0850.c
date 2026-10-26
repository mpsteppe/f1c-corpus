char __thiscall sub_4C0850(void *this)
{
  int v2; // eax
  char *v3; // eax
  int v4; // esi
  const char *v5; // ecx
  const char *v6; // ecx

  LOBYTE(v2) = *((_BYTE *)this + 432);
  if ( (_BYTE)v2 )
  {
    v3 = (char *)*((_DWORD *)this + 2);
    v4 = dword_7D2E48 + 18624 * *((_DWORD *)this + 105);
    if ( !v3 )
      v3 = byte_5EA438;
    sub_4C3F80(v3);
    sub_4C78F0(dword_8AC38C);
    v5 = *(const char **)this;
    if ( !*(_DWORD *)this )
      v5 = byte_5EA438;
    strcpy((char *)(v4 + 17952), v5);
    v6 = (const char *)*((_DWORD *)this + 2);
    if ( !v6 )
      v6 = byte_5EA438;
    strcpy((char *)(v4 + 18196), v6);
    sub_4BC2F0(v4 + 16436, *((_DWORD *)this + 106) + 1);
    sub_4EF5A0(*((_DWORD *)this + 107), 0);
    v2 = *((_DWORD *)this + 106) + 1;
    *(_DWORD *)(v4 + 16472) = v2;
  }
  return v2;
}
