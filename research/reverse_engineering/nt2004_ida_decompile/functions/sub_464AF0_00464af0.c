char __thiscall sub_464AF0(int *this)
{
  int v1; // eax
  const char *v2; // edx
  const char *v3; // ecx
  float v5; // [esp+0h] [ebp-DCh]
  _BYTE v6[8]; // [esp+Ch] [ebp-D0h] BYREF
  char Destination[200]; // [esp+14h] [ebp-C8h] BYREF

  v1 = *this;
  if ( *(_DWORD *)(*this + 640) != 1 )
  {
    *(_DWORD *)(v1 + 640) = 1;
    v2 = dword_7665D8;
    if ( !dword_7665D8 )
      v2 = &byte_629120;
    v3 = &v2[strlen(v2)];
    if ( v3 > v2 )
    {
      while ( *v3 != 92 )
      {
        if ( --v3 <= v2 )
          goto LABEL_9;
      }
      ++v3;
    }
LABEL_9:
    strncpy(Destination, v3, 0x7Fu);
    Destination[127] = 0;
    v5 = dbl_7DA9D0;
    sub_4D0D00(4, 48, strlen(Destination), 63, LODWORD(v5), 3);
    LOBYTE(v1) = sub_463A40(dword_764D70, (int)v6, 2, -1, -1);
  }
  return v1;
}
