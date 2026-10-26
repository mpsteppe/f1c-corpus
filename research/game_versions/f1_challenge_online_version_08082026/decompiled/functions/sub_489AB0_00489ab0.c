int __thiscall sub_489AB0(_DWORD *this, int a2, char a3)
{
  int v4; // eax
  int v5; // ecx
  _DWORD *v6; // eax
  int v7; // ecx
  char *v9; // ecx
  char *v10; // edi
  char *v11; // edx
  char *v12; // eax

  if ( a2 > this[37] || a2 <= 0 )
  {
    this[90] = -1;
    return -1;
  }
  v4 = a2 - 1;
  this[90] = a2 - 1;
  if ( a3 )
  {
    v5 = this[83];
    if ( v4 < v5 || v4 >= v5 + this[89] )
    {
      this[83] = v4;
      sub_489D00(this);
      sub_489E90(this);
    }
  }
  v6 = (_DWORD *)this[36];
  v7 = 0;
  if ( !v6 )
    return -1;
  while ( v7 != this[90] )
  {
    v6 = (_DWORD *)v6[35];
    ++v7;
    if ( !v6 )
      return -1;
  }
  v9 = (char *)v6[42];
  if ( !v9 )
    v9 = byte_5EA438;
  v10 = (char *)v6[40];
  if ( !v10 )
    v10 = byte_5EA438;
  v11 = (char *)v6[46];
  if ( !v11 )
    v11 = byte_5EA438;
  v12 = (char *)v6[44];
  if ( !v12 )
    v12 = byte_5EA438;
  (*(void (__thiscall **)(_DWORD *, char *, char *, char *, char *))(*this + 168))(this, v12, v11, v10, v9);
  return 0;
}
