int __thiscall sub_500A20(_DWORD *this, char *String1)
{
  int v3; // ebx
  int v4; // edi
  const char *v5; // eax

  v3 = 0;
  if ( (int)this[4] <= 0 )
  {
LABEL_7:
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1080) )
      sub_500FE0((int)&unk_7D7920, aTireBrandDoesn_1, (char)String1);
    return 0;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(const char **)(v4 + this[5]);
      if ( !v5 )
        v5 = &byte_629120;
      if ( !_strcmpi(String1, v5) )
        return this[5] + 2072 * v3;
      ++v3;
      v4 += 2072;
      if ( v3 >= this[4] )
        goto LABEL_7;
    }
  }
}
