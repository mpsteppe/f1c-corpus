void __thiscall sub_5BD210(_DWORD *this, int a2)
{
  int v3; // ecx
  _DWORD *v4; // eax
  _DWORD *v5; // edi

  if ( a2 )
  {
    v4 = operator new(0xCu);
    if ( v4 )
    {
      v4[2] = a2;
      v4[1] = 0;
      *v4 = off_7296D0;
      v5 = v4;
      (*(void (__thiscall **)(_DWORD *))*v4)(v4);
    }
    else
    {
      v5 = 0;
    }
    v3 = this[1];
    this[1] = v5;
  }
  else
  {
    v3 = this[1];
    this[1] = 0;
  }
  if ( v3 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(v3);
}
