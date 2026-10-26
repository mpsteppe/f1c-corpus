int __thiscall sub_5A96B0(unsigned int **this, int a2, int a3)
{
  int v4; // edi
  int result; // eax
  unsigned int **i; // esi
  _DWORD *v7; // eax
  unsigned int *v8; // eax
  int v9; // edx

  *this = 0;
  this[1] = 0;
  sub_5A4830(dword_7E6B48, a3);
  v4 = 0;
  result = sub_5A4730(dword_7E6B48);
  if ( result > 0 )
  {
    for ( i = this + 2; ; ++i )
    {
      v7 = operator new(0x124u);
      v8 = v7 ? sub_5A9310(v7, v4) : 0;
      *i = v8;
      result = sub_5A9330(v8);
      if ( result )
        break;
      strcpy((char *)*i + 4, (const char *)(sub_5A4750(dword_7E6B48, v4) + 24));
      (*i)[65] = v4;
      (*i)[66] = 0;
      (*i)[67] = 0;
      sub_5A93B0(*i);
      v9 = (int)*this + 1;
      this[1] = (unsigned int *)((char *)this[1] + 1);
      *this = (unsigned int *)v9;
      ++v4;
      result = sub_5A4730(dword_7E6B48);
      if ( v4 >= result )
        return result;
    }
    if ( this[v4 + 2] )
    {
      j_nullsub_6(this[v4 + 2]);
      result = sub_5BE8AE();
    }
    this[v4 + 2] = 0;
  }
  return result;
}
