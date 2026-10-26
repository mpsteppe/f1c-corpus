int __thiscall sub_618610(int this, int a2, int a3)
{
  int v4; // ebp
  _BYTE *i; // edi
  bool v6; // zf
  int v7; // eax

  v4 = 0;
  for ( i = *(_BYTE **)(this + 16);
        v4 < a3;
        *(_BYTE *)(this + 12) = (*(_BYTE *)(this + 8) | *(_BYTE *)(this + 12))
                              - (*(_BYTE *)(this + 8) & *(_BYTE *)(this + 12)) )
  {
    ++*(_BYTE *)(this + 8);
    *i = *(_BYTE *)(a2 + v4) + *((_BYTE *)Block + *(unsigned __int8 *)(this + 12));
    Seed = *(_BYTE *)(a2 + v4) & 0xF;
    SetEvent(dword_FB4154);
    WaitForSingleObject(hEvent, 0xFFFFFFFF);
    dword_FB4164 &= 0xFFFFFFF0;
    *i++ += dword_FB4164;
    v6 = *(_DWORD *)(this + 12) >= 0;
    v7 = 2 * *(_DWORD *)(this + 12);
    *(_DWORD *)(this + 12) = v7;
    if ( !v6 )
      *(_DWORD *)(this + 12) = v7 + 1;
    ++v4;
  }
  return *(_DWORD *)(this + 16);
}
