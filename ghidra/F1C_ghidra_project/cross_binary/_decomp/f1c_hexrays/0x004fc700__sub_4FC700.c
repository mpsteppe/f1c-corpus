// f1c  0x004fc700  size=336
char __thiscall sub_4FC700(int this, int a2)
{
  char v3; // bl
  int v4; // eax
  const char *v5; // ebp
  unsigned int v6; // kr04_4
  char v7; // cl
  int v8; // ebx
  char v10; // [esp+13h] [ebp-9h]
  int v12; // [esp+18h] [ebp-4h]
  const char *v13; // [esp+20h] [ebp+4h]

  v3 = dword_7C56A0 & 1;
  if ( dword_8AB6E4 != 2 || (v10 = 1, sub_4B9A00(&dword_8AB6EC)) )
    v10 = 0;
  if ( !v3 || (LOBYTE(v4) = v10) != 0 )
  {
    v5 = (const char *)(a2 + 8);
    v6 = strlen((const char *)(a2 + 8)) + 1;
    v7 = *(_BYTE *)(a2 + 3);
    v8 = this + 80;
    v13 = (const char *)(v6 - 1 + a2 + 9);
    v12 = v7 & 7;
    if ( strcmp((const char *)(this + 80), v5) || (v4 = strcmp((const char *)(this + 132), v13)) != 0 )
    {
      sub_587DD0(v8, v5, 31);
      *(_BYTE *)(v8 + 31) = 0;
      sub_587DD0(this + 132, v13, 31);
      *(_BYTE *)(this + 163) = 0;
      if ( v10 || (LOBYTE(v4) = v12, v12 == dword_7C56A4) )
        LOBYTE(v4) = (unsigned __int8)sub_4FC550(this, 0);
      else
        *(_DWORD *)(this + 68) = v12;
    }
    else if ( *(_DWORD *)(this + 68) != -1 )
    {
      LOBYTE(v4) = v7 & 7;
      *(_DWORD *)(this + 68) = v12;
    }
  }
  return v4;
}
