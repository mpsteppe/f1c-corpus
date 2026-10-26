int __thiscall sub_5BE1D0(int *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  void *v5; // eax
  const void *v7; // [esp-8h] [ebp-14h]
  size_t v8; // [esp-4h] [ebp-10h]

  if ( *this == this[1] )
    sub_5BE230(this);
  v3 = *this + 1;
  *this = v3;
  if ( a2 < v3 - 1 )
  {
    v8 = this[2] * (v3 - a2 - 1);
    v7 = (const void *)sub_5BE1B0((int)this, a2);
    v5 = (void *)sub_5BE1B0(v4, a2 + 1);
    memcpy(v5, v7, v8);
  }
  return sub_5BE260(a2);
}
