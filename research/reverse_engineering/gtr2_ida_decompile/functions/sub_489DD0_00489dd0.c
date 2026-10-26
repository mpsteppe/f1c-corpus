int **__thiscall sub_489DD0(_DWORD *this, int **a2, _DWORD *a3)
{
  int *v3; // edx
  int *v4; // eax
  int **result; // eax

  v3 = (int *)this[1];
  v4 = (int *)v3[1];
  while ( !*((_BYTE *)v4 + 21) )
  {
    if ( v4[3] >= *a3 )
    {
      v3 = v4;
      v4 = (int *)*v4;
    }
    else
    {
      v4 = (int *)v4[2];
    }
  }
  if ( v3 == (int *)this[1] || *a3 < v3[3] )
  {
    result = a2;
    *a2 = (int *)this[1];
  }
  else
  {
    result = a2;
    *a2 = v3;
  }
  return result;
}
