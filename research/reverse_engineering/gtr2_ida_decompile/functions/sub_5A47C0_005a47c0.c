int __thiscall sub_5A47C0(void *this, int a2)
{
  int v2; // edi

  v2 = dword_16C9988;
  if ( a2 )
  {
    sub_5A46A0(this, a2);
    v2 = 0;
  }
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 56))(this);
  return v2;
}
