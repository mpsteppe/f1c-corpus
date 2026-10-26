int __thiscall sub_534F50(_DWORD *this)
{
  int *v1; // edx
  int result; // eax
  int v3; // edx

  v1 = (int *)this[1];
  result = 0;
  this[2] = v1;
  if ( v1 )
  {
    v3 = *v1;
    if ( v3 )
      return *(_DWORD *)(v3 + 95732);
  }
  return result;
}
