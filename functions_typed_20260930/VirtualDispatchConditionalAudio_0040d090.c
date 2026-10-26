int __thiscall sub_40D090(_DWORD *this)
{
  int v1; // ecx
  int result; // eax
  int v3; // ecx

  v1 = this[2];
  if ( v1 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 16))(v1);
  v3 = dword_8AFE88;
  if ( dword_8AFE88 )
  {
    result = 0;
    *(_DWORD *)(dword_8AFE88 + 424) = 0;
    *(_DWORD *)(v3 + 420) = 0;
  }
  return result;
}

