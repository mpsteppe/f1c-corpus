char __thiscall sub_56D540(_DWORD *this, unsigned int a2, int a3)
{
  int v4; // ebx
  Iostream_init *v5; // ecx
  Iostream_init *v6; // eax

  v4 = sub_5757E0(this);
  if ( (unsigned int)sub_577280(a3) != v4 )
  {
    v5 = *(Iostream_init **)(a3 + 28);
    if ( v5 )
    {
      v6 = Iostream_init::Iostream_init(v5);
      sub_56D370(this, a2, v6);
    }
  }
  return 0;
}
