int __thiscall sub_4DAC10(int this)
{
  int v2; // ebx
  int v3; // edi

  v2 = 1;
  v3 = this + 92;
  if ( (*(unsigned __int8 (__thiscall **)(int, int, int))(*(_DWORD *)(this + 92) + 16))(this + 92, this + 368, 1) )
  {
    v2 = 0;
    if ( *(_BYTE *)(this + 766)
      && !(*(unsigned __int8 (__thiscall **)(int, int, _DWORD, int, int, int))(*(_DWORD *)(this + 184) + 8))(
            this + 184,
            this + 496,
            0,
            1,
            1,
            1) )
    {
      *(_BYTE *)(this + 766) = 0;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 44))(v3);
    if ( *(_BYTE *)(this + 766) )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)(this + 184) + 52))(this + 184, 0);
  }
  return v2;
}
