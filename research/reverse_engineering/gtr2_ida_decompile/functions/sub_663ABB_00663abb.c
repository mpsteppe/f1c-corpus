int __thiscall sub_663ABB(_DWORD *this)
{
  int v2; // edi
  char *v3; // eax
  int v4; // esi
  int v5; // eax
  double *v6; // esi
  int v8; // [esp+14h] [ebp-14h] BYREF
  int v9; // [esp+18h] [ebp-10h]
  char *String1; // [esp+20h] [ebp-8h]
  int v11; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD *)(*this + 60);
  do
  {
LABEL_18:
    if ( !v2 )
      return 0;
    v3 = *(char **)(v2 + 4);
    v4 = 0;
    v11 = 0;
    String1 = v3;
    do
    {
      if ( _stricmp(String1, *(const char **)(v2 + 4)) )
        break;
      if ( sub_6460B4(*(const char **)v2, 0, &v8) >= 0 )
      {
        v5 = this[4];
        if ( v5 == v9 )
        {
          if ( !v4 )
            v4 = v2;
        }
        else if ( (v5 & 0xFFFF0000) == v9 && !v11 )
        {
          v11 = v2;
        }
      }
      v2 = *(_DWORD *)(v2 + 40);
    }
    while ( v2 );
    if ( v4 )
      break;
    v4 = v11;
  }
  while ( !v11 );
  String1 = (char *)sub_681A51(*(_DWORD *)(v4 + 4), 2897, 1, 4);
  if ( String1 != (char *)-1 )
  {
    v11 = 0;
    v6 = (double *)(v4 + 8);
    while ( sub_681AAA((int)String1, 0, v11, *v6) != -1 )
    {
      ++v11;
      ++v6;
      if ( (unsigned int)v11 >= 4 )
        goto LABEL_18;
    }
  }
  return -2147024882;
}
