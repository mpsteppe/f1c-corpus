int __thiscall sub_4D4060(_DWORD *this, int a2, char a3)
{
  int v4; // eax
  int v5; // ecx
  _DWORD *v6; // eax
  int v7; // ecx
  const CHAR *v9; // ecx
  const CHAR *v10; // edi
  const CHAR *v11; // edx
  const CHAR *v12; // eax

  if ( a2 > this[37] || a2 <= 0 )
  {
    this[146] = -1;
    return -1;
  }
  v4 = a2 - 1;
  this[146] = a2 - 1;
  if ( a3 )
  {
    v5 = this[139];
    if ( v4 < v5 || v4 >= v5 + this[145] )
    {
      this[139] = v4;
      sub_4D0B20(this);
      sub_4CE500();
    }
  }
  v6 = (_DWORD *)this[36];
  v7 = 0;
  if ( !v6 )
    return -1;
  while ( v7 != this[146] )
  {
    v6 = (_DWORD *)v6[35];
    ++v7;
    if ( !v6 )
      return -1;
  }
  v9 = (const CHAR *)v6[73];
  if ( !v9 )
    v9 = WindowName;
  v10 = (const CHAR *)v6[69];
  if ( !v10 )
    v10 = WindowName;
  v11 = (const CHAR *)v6[42];
  if ( !v11 )
    v11 = WindowName;
  v12 = (const CHAR *)v6[40];
  if ( !v12 )
    v12 = WindowName;
  (*(void (__thiscall **)(_DWORD *, const CHAR *, const CHAR *, const CHAR *, const CHAR *))(*this + 172))(
    this,
    v12,
    v11,
    v10,
    v9);
  return 0;
}
