int __thiscall sub_42F310(void *this)
{
  int v1; // eax

  v1 = *(_DWORD *)this + 1;
  *(_DWORD *)this = v1;
  if ( v1 >= (int)NumOfElements && v1 < 48 )
  {
    *(_DWORD *)this = 48;
    return *(_DWORD *)this;
  }
  if ( v1 < 49 )
  {
    if ( v1 >= 48 )
      return *(_DWORD *)this;
    return *(_DWORD *)(dword_75AAD0[v1] + 25248);
  }
  else
  {
    *(_DWORD *)this = 49;
    return 49;
  }
}
