char __thiscall sub_4E3B00(void *this)
{
  int v2; // eax
  char *v3; // eax
  int v4; // esi
  const char *v5; // ecx
  const char *v6; // ecx
  const char *v7; // ecx

  LOBYTE(v2) = *((_BYTE *)this + 640);
  if ( (_BYTE)v2 )
  {
    v3 = (char *)*((_DWORD *)this + 2);
    v4 = dword_76BB88 + 25304 * *((_DWORD *)this + 157);
    if ( !v3 )
      v3 = &byte_629120;
    sub_4E7690(v3);
    sub_4EEAE0(dword_7D6A54);
    v5 = *(const char **)this;
    if ( !*(_DWORD *)this )
      v5 = &byte_629120;
    strcpy((char *)(v4 + 24772), v5);
    v6 = (const char *)*((_DWORD *)this + 2);
    if ( !v6 )
      v6 = &byte_629120;
    strcpy((char *)(v4 + 24992), v6);
    v7 = (const char *)*((_DWORD *)this + 4);
    if ( !v7 )
      v7 = &byte_629120;
    strcpy((char *)(v4 + 25120), v7);
    sub_4DEB20((int *)(v4 + 20836), *((_DWORD *)this + 158) + 1);
    sub_51BC20(*((_DWORD *)this + 159), 0);
    v2 = *((_DWORD *)this + 158) + 1;
    *(_DWORD *)(v4 + 20876) = v2;
  }
  return v2;
}
