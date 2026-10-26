int __thiscall sub_6A6480(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  void *v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  char *v8; // ecx
  int v9; // edi
  void *v10; // eax
  void *v11; // eax
  double *v12; // ecx

  v2 = 0;
  v3 = 0;
  this[173] = operator new(4 * this[3]);
  v4 = operator new(4 * this[2]);
  v5 = this[173] == 0;
  this[174] = v4;
  if ( v5 || !v4 )
    return -2147024882;
  if ( this[3] )
  {
    do
    {
      v6 = (_DWORD *)sub_681186(116);
      v7 = v6 ? sub_680CEC(v6) : 0;
      *(_DWORD *)(this[173] + 4 * v2) = v7;
      v8 = *(char **)(this[173] + 4 * v2);
      if ( !v8 )
        return -2147024882;
      v3 = sub_681430(v8, *(_DWORD **)(this[6] + 4 * v2));
      if ( v3 < 0 )
        return v3;
    }
    while ( (unsigned int)++v2 < this[3] );
  }
  v9 = 0;
  if ( this[2] )
  {
    do
    {
      v10 = (void *)sub_6816E7(128);
      v11 = v10 ? sub_681563(v10) : 0;
      *(_DWORD *)(this[174] + 4 * v9) = v11;
      v12 = *(double **)(this[174] + 4 * v9);
      if ( !v12 )
        return -2147024882;
      v3 = sub_6815D6(v12, *(_DWORD *)(this[5] + 4 * v9));
      if ( v3 < 0 )
        return v3;
    }
    while ( (unsigned int)++v9 < this[2] );
  }
  this[176] = this[3];
  this[175] = this[2];
  return v3;
}
