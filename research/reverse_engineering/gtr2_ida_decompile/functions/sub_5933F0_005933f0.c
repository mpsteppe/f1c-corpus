char __thiscall sub_5933F0(int this, int a2)
{
  char v2; // bl
  int v4; // eax
  const char *v6; // ebx
  char v8; // [esp+Bh] [ebp-9h]
  const char *v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]
  const char *v11; // [esp+18h] [ebp+4h]

  v2 = dword_B640C4 & 1;
  if ( dword_BE1204 != 2 || (v8 = 1, sub_521050(&dword_BE120C)) )
    v8 = 0;
  if ( !v2 || (LOBYTE(v4) = v8) != 0 )
  {
    v11 = (const char *)(a2 + 8);
    v9 = (const char *)(strlen(v11) + a2 + 9);
    v6 = &v9[strlen(v9) + 1];
    v10 = *(_BYTE *)(a2 + 3) & 7;
    if ( strcmp((const char *)(this + 28), v11)
      || strcmp((const char *)(this + 60), v9)
      || (v4 = strcmp((const char *)(this + 92), v6)) != 0 )
    {
      sub_630FE0(this + 28, v11, 31);
      *(_BYTE *)(this + 59) = 0;
      sub_630FE0(this + 60, v9, 31);
      *(_BYTE *)(this + 91) = 0;
      sub_630FE0(this + 92, v6, 31);
      *(_BYTE *)(this + 123) = 0;
      if ( v8 || (v4 = v10, v10 == *(_DWORD *)dword_B640C8) )
      {
        LOBYTE(v4) = sub_5930F0();
        return v4;
      }
      goto LABEL_11;
    }
    if ( *(_DWORD *)(this + 20) != -1 )
    {
      v4 = *(_BYTE *)(a2 + 3) & 7;
LABEL_11:
      *(_DWORD *)(this + 20) = v4;
    }
  }
  return v4;
}
