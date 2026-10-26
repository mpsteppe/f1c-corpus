void __thiscall sub_5BD050(_DWORD *this)
{
  int v2; // eax
  void *v3; // edi

  *this = off_729718;
  if ( sub_4FB7D0(this) )
  {
    v2 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
    v3 = (void *)v2;
    if ( v2 )
    {
      sub_5C2630(v2);
      j__free(v3);
    }
    *this = off_7296AC;
  }
  else
  {
    *this = off_7296AC;
  }
}
