char __thiscall sub_4AFDB0(_DWORD *this)
{
  const char *v2; // eax
  char *v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // eax

  if ( !*this )
    return 0;
  v2 = (const char *)this[1];
  if ( !v2 )
    v2 = &byte_629120;
  if ( !strlen(v2) )
    return 0;
  v3 = (char *)this[1];
  if ( !v3 )
    v3 = &byte_629120;
  v4 = sub_4ADBB0((_DWORD *)dword_7655CC, v3);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = sub_4B07C0(v4);
  if ( !v6 )
    return 0;
  sub_5A16B0(v6);
  sub_4B0090(*(_DWORD *)(v5 + 20), *(float *)(v5 + 24));
  sub_4B01D0(*(float *)(v5 + 12), *(float *)(v5 + 16));
  return 1;
}
