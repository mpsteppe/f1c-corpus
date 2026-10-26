int __thiscall sub_45CF30(CHAR ***this)
{
  int v1; // esi
  int result; // eax
  CHAR *v4; // ecx
  int v5; // eax
  _DWORD *v6; // ecx

  v4 = **this;
  if ( !v4 )
    v4 = &byte_629120;
  sub_506CA0(v4);
  v5 = sub_506D30(*this + 3);
  sub_592910(v5, 14, 800, 0xFFFFFF, 0, 1072, 0);
  sub_45CC30((char *)*this + 8);
  v6 = *this + 2;
  v1 = 0;
  v6[297] = 0;
  do
    result = sub_45C6C0(v6, v1++);
  while ( v1 < 8 );
  return result;
}
