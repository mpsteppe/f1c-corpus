int __thiscall sub_457EE0(float *this)
{
  int i; // edx
  float *v2; // eax
  double v3; // st6
  double v4; // st5
  int result; // eax

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    if ( i )
    {
      v2 = (float *)(*(_DWORD *)this + 28 * i);
      v3 = v2[1] - *(v2 - 6);
      v4 = v2[2] - *(v2 - 5);
      v2[6] = sqrt(v4 * v4 + v3 * v3 + (*v2 - *(v2 - 7)) * (*v2 - *(v2 - 7))) + *(v2 - 1);
    }
    else
    {
      *(_DWORD *)(*(_DWORD *)this + 24) = 0;
    }
  }
  result = *(_DWORD *)this;
  this[2] = *(float *)(28 * i + *(_DWORD *)this - 60);
  return result;
}

