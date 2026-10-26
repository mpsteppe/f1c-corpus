int __thiscall sub_6186F0(int this, int a2, int a3, char a4)
{
  int v5; // ebp
  _BYTE *i; // edi
  char v7; // al
  char v8; // dl
  bool v9; // zf
  int v10; // eax

  v5 = 0;
  for ( i = *(_BYTE **)(this + 16);
        v5 < a3;
        *(_BYTE *)(this + 12) = (*(_BYTE *)(this + 8) | *(_BYTE *)(this + 12))
                              - (*(_BYTE *)(this + 8) & *(_BYTE *)(this + 12)) )
  {
    ++*(_BYTE *)(this + 8);
    v7 = *(_BYTE *)(a2 + v5) - *((_BYTE *)Block + *(unsigned __int8 *)(this + 12));
    *i = v7;
    Seed = v7 & 0xF;
    SetEvent(dword_FB4154);
    WaitForSingleObject(hEvent, 0xFFFFFFFF);
    dword_FB4164 &= 0xFFFFFFF0;
    v8 = *i - dword_FB4164;
    *i = v8;
    if ( a4 && v8 == 10 )
      *i = 0;
    ++i;
    v9 = *(_DWORD *)(this + 12) >= 0;
    v10 = 2 * *(_DWORD *)(this + 12);
    *(_DWORD *)(this + 12) = v10;
    if ( !v9 )
      *(_DWORD *)(this + 12) = v10 + 1;
    ++v5;
  }
  return *(_DWORD *)(this + 16);
}
