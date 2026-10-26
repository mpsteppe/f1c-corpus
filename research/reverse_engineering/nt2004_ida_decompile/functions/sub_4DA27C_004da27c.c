int __thiscall sub_4DA27C(int *this)
{
  void *v1; // esi
  int result; // eax
  int *v3; // ecx

  v3 = this + 2;
  v1 = (void *)*v3;
  if ( *v3 )
  {
    sub_4D52D0(*v3);
    return sub_5BE8AE(v1);
  }
  return result;
}
