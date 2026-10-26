char __thiscall sub_60CC30(int this, char a2)
{
  int v2; // eax
  int v4; // eax

  LOBYTE(v2) = a2;
  if ( a2 != *(_BYTE *)(this + 4804) )
  {
    *(_BYTE *)(this + 4804) = a2;
    v4 = *(_DWORD *)(this + 9548);
    if ( a2 )
      v2 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v4 + 228))(v4, 14, 1);
    else
      v2 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v4 + 228))(v4, 14, 0);
    *(_DWORD *)(this + 8) = v2;
  }
  return v2;
}
