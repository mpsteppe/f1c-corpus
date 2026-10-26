int __thiscall sub_4ED570(int *this)
{
  int result; // eax
  int *v2; // eax

  result = *this;
  if ( *this )
  {
    if ( *(_DWORD *)(result + 100) )
    {
      v2 = (int *)sub_4ED8C0(this);
      return sub_4EA920(v2);
    }
  }
  return result;
}
