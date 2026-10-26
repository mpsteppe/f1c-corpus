int __thiscall sub_500DC0(int *this, char *String1)
{
  int v3; // ebx
  int v4; // edi
  const char *v5; // eax

  v3 = 0;
  if ( *this <= 0 )
  {
LABEL_7:
    if ( dword_75CBA8 != 5 )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1190) )
        sub_500FE0((int)&unk_7D7920, aNonExistentTir_0, (char)String1);
    }
    return 0;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(const char **)(v4 + this[1]);
      if ( !v5 )
        v5 = &byte_629120;
      if ( !_strcmpi(String1, v5) )
        return this[1] + 36 * v3;
      ++v3;
      v4 += 36;
      if ( v3 >= *this )
        goto LABEL_7;
    }
  }
}
