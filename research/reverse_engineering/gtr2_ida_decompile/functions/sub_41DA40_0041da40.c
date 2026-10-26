int __thiscall sub_41DA40(_DWORD *this, char *String1)
{
  const char *v2; // eax
  double v3; // st7
  int result; // eax

  v2 = sub_41D920(this, String1);
  if ( !v2 )
    return -1;
  v3 = (double)*((int *)v2 + 17);
  result = *((_DWORD *)v2 + 17);
  if ( -1.0 == v3 )
    return -1;
  return result;
}
