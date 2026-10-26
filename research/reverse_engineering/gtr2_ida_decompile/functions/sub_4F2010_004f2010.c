int __thiscall sub_4F2010(void *this, char a2)
{
  int v2; // ecx
  int result; // eax
  float *v4; // ecx

  v2 = dword_BE1BD8 + 2824 * *(_DWORD *)(*(_DWORD *)this + 22472);
  result = *(_DWORD *)(v2 + 268);
  if ( !result )
  {
    if ( a2 )
      v4 = (float *)(v2 + 236);
    else
      v4 = (float *)(v2 + 252);
    if ( fabs(*v4) >= 0.40000001 )
    {
      result = 2;
      if ( v4[1] > 0.58999997 )
        return 1;
    }
    else if ( v4[2] <= 0.0 )
    {
      return 4;
    }
    else
    {
      return 3;
    }
  }
  return result;
}
