int __thiscall sub_49FCC0(_DWORD *this, int a2, char a3)
{
  int v4; // eax
  int v5; // ecx
  _DWORD *v6; // eax
  int v7; // ecx
  CHAR *v9; // ecx
  CHAR *v10; // edi
  CHAR *v11; // edx
  CHAR *v12; // eax

  if ( a2 > this[37] || a2 <= 0 )
  {
    this[101] = -1;
    return -1;
  }
  v4 = a2 - 1;
  this[101] = a2 - 1;
  if ( a3 )
  {
    v5 = this[94];
    if ( v4 < v5 || v4 >= v5 + this[100] )
    {
      this[94] = v4;
      sub_49FF10(this);
      sub_4A0090(this);
    }
  }
  v6 = (_DWORD *)this[36];
  v7 = 0;
  if ( !v6 )
    return -1;
  while ( v7 != this[101] )
  {
    v6 = (_DWORD *)v6[35];
    ++v7;
    if ( !v6 )
      return -1;
  }
  v9 = (CHAR *)v6[70];
  if ( !v9 )
    v9 = &byte_629120;
  v10 = (CHAR *)v6[68];
  if ( !v10 )
    v10 = &byte_629120;
  v11 = (CHAR *)v6[42];
  if ( !v11 )
    v11 = &byte_629120;
  v12 = (CHAR *)v6[40];
  if ( !v12 )
    v12 = &byte_629120;
  (*(void (__thiscall **)(_DWORD *, CHAR *, CHAR *, CHAR *, CHAR *))(*this + 168))(this, v12, v11, v10, v9);
  return 0;
}
