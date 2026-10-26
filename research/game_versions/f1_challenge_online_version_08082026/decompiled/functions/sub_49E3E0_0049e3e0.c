void __thiscall sub_49E3E0(_DWORD *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // eax

  v1 = this[2];
  if ( v1 )
  {
    v2 = this[5];
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 84);
      if ( v3 )
        sub_49F1C0(1, 1, 0, v1, v3);
    }
  }
}
