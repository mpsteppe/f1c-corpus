char __thiscall sub_52A980(int this, int a2)
{
  char v3; // bl
  int v4; // eax
  const char *v5; // ebp
  char *v6; // edx
  int v7; // edi
  char v9; // [esp+13h] [ebp-9h]
  char *Source; // [esp+18h] [ebp-4h]
  char *v12; // [esp+20h] [ebp+4h]

  v3 = dword_75CBAC & 1;
  if ( dword_7D5DA4 != 2 || (v9 = 1, sub_4D9AE0(&dword_7D5DAC)) )
    v9 = 0;
  if ( !v3 || (LOBYTE(v4) = v9) != 0 )
  {
    v5 = (const char *)(a2 + 8);
    v6 = (char *)(this + 80);
    Source = (char *)(strlen((const char *)(a2 + 8)) + a2 + 9);
    v7 = (*(_DWORD *)a2 >> 22) & 0xF;
    v12 = (char *)(this + 80);
    if ( !strcmp((const char *)(this + 80), v5) )
    {
      v4 = strcmp((const char *)(this + 132), Source);
      if ( !v4 )
      {
        if ( *(_DWORD *)(this + 68) != -1 )
          *(_DWORD *)(this + 68) = v7;
        return v4;
      }
      v6 = v12;
    }
    strncpy(v6, v5, 0x1Fu);
    v12[31] = 0;
    strncpy((char *)(this + 132), Source, 0x1Fu);
    LOBYTE(v4) = v9;
    *(_BYTE *)(this + 163) = 0;
    if ( v9 || v7 == dword_75CBB0 )
      LOBYTE(v4) = sub_52A7D0(this, 0);
    else
      *(_DWORD *)(this + 68) = v7;
  }
  return v4;
}
