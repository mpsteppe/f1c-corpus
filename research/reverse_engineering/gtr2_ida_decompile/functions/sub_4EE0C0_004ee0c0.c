int __thiscall sub_4EE0C0(_DWORD *this)
{
  int i; // esi
  int v3; // ecx
  int result; // eax
  int (__thiscall ***v5)(_DWORD, int); // ecx

  for ( i = 0; i < 93; ++i )
  {
    v3 = this[i];
    if ( v3 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(v3);
      result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[i] + 24))(this[i]);
      v5 = (int (__thiscall ***)(_DWORD, int))this[i];
      if ( v5 )
        result = (**v5)(v5, 1);
      this[i] = 0;
    }
  }
  return result;
}
