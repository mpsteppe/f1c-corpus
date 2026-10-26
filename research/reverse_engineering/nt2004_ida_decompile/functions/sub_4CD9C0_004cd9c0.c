int __thiscall sub_4CD9C0(char *this, const char *a2, int a3)
{
  char *v3; // esi
  const char *v4; // eax
  int v5; // edx
  char v6; // cl
  CHAR *v7; // edx

  v3 = this + 20;
  v4 = a2;
  v5 = this + 20 - a2;
  do
  {
    v6 = *v4;
    v4[v5] = *v4;
    ++v4;
  }
  while ( v6 );
  v7 = *(CHAR **)dword_62A0D0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v7 = &byte_629120;
  if ( !sub_579060(v3, v7) )
    sub_4CD540(a2, v3);
  return sub_4CDA20(a3);
}
