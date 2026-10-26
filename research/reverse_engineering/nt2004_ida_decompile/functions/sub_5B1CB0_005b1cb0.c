BOOL __thiscall sub_5B1CB0(char *this, char *String2)
{
  char *v3; // edi
  char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char *v7; // eax

  v3 = this + 1036;
  v4 = this + 12;
  do
  {
    v5 = *v4;
    v4[1024] = *v4;
    ++v4;
  }
  while ( v5 );
  v6 = strtok(v3, Delimiter);
  *((_DWORD *)this + 515) = v6;
  if ( !v6 || _strcmpi(v6, String2) )
    return 0;
  v7 = strtok(0, &byte_629120);
  *((_DWORD *)this + 515) = v7;
  return v7 != 0;
}
