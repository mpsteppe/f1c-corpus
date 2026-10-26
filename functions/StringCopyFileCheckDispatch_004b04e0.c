int __thiscall sub_4B04E0(char *this, const char *a2, int a3)
{
  char *v3; // esi
  const char *v4; // eax
  int v5; // edx
  char v6; // cl
  char *v7; // edx

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
  v7 = (char *)dword_5EC440;
  if ( !dword_5EC440 )
    v7 = byte_5EA438;
  if ( !sub_566810(v3, v7) )
    sub_4B01B0(a2, v3);
  return PlayerFileInit(a3);
}
