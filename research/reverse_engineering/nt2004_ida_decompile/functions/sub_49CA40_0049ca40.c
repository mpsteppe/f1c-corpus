int __thiscall sub_49CA40(_DWORD *this, _DWORD *a2, char a3)
{
  _DWORD *v3; // edx
  int v4; // eax
  _DWORD *v5; // ecx
  _DWORD *i; // eax
  int result; // eax

  v3 = this;
  a2[12] = this[12];
  a2[38] = this[38];
  a2[39] = this[39];
  if ( a3 )
  {
    v4 = this[36];
    this[36] = a2;
    a2[35] = v4;
  }
  else
  {
    v5 = (_DWORD *)this[36];
    if ( v5 )
    {
      for ( i = (_DWORD *)v5[35]; i; i = (_DWORD *)i[35] )
        v5 = i;
      sub_49CA30(v5, (int)a2);
    }
    else
    {
      v3[36] = a2;
    }
  }
  result = v3[37] + 1;
  v3[37] = result;
  return result;
}
