char sub_4BAC70()
{
  int v0; // eax

  dword_766178 = 0;
  dword_766180 = 0;
  byte_766185 = 0;
  byte_766188 = 0;
  byte_766191 = 0;
  dword_766194 = 0;
  LOBYTE(v0) = sub_405BE0(&dword_629124);
  if ( (_BYTE)v0 )
  {
    v0 = sub_4059F0(&dword_629124);
    if ( v0 == 2 )
    {
      if ( dword_7655CC )
        LOBYTE(v0) = (unsigned __int8)sub_4AC980((_DWORD *)dword_7655CC);
    }
  }
  return v0;
}
