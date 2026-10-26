unsigned int *__thiscall sub_5E61C0(_DWORD *this, float *a2)
{
  bool v2; // bl
  unsigned int **v3; // eax
  unsigned int *i; // eax
  unsigned int v5; // edx
  unsigned int v6; // edx
  int v7; // eax
  unsigned int **v8; // eax
  unsigned int *result; // eax
  unsigned int v10; // edx
  unsigned int v11; // edx

  this[68] = *(_DWORD *)a2;
  this[69] = *((_DWORD *)a2 + 1);
  this[70] = *((_DWORD *)a2 + 2);
  v2 = 0;
  if ( *a2 == 0.0 && a2[1] == 0.0 )
    v2 = a2[2] == 0.0;
  v3 = (unsigned int **)this[149];
  this[151] = v3;
  if ( v3 )
  {
    for ( i = *v3; i; i = *v8 )
    {
      i[4] = this[68];
      i[5] = this[69];
      i[6] = this[70];
      v5 = *i;
      if ( v2 )
        v6 = v5 & 0xFFFF7FFF;
      else
        v6 = v5 | 0x8000;
      *i = v6;
      v7 = this[151];
      if ( !v7 )
        break;
      v8 = *(unsigned int ***)(v7 + 4);
      this[151] = v8;
      if ( !v8 )
        break;
    }
  }
  result = (unsigned int *)this[153];
  this[155] = result;
  if ( result )
  {
    for ( result = (unsigned int *)*result; result; result = (unsigned int *)*result )
    {
      result[4] = this[68];
      result[5] = this[69];
      result[6] = this[70];
      v10 = *result;
      if ( v2 )
        v11 = v10 & 0xFFFF7FFF;
      else
        v11 = v10 | 0x8000;
      *result = v11;
      result = (unsigned int *)this[155];
      if ( !result )
        break;
      result = (unsigned int *)result[1];
      this[155] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
