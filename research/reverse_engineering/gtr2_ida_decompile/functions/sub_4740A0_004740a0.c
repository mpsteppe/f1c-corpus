int __thiscall sub_4740A0(int this, int a2)
{
  int v3; // eax
  _BYTE *v4; // esi
  float v6; // [esp+4h] [ebp-368h]
  unsigned int v7; // [esp+1Ch] [ebp-350h] BYREF
  char v8; // [esp+24h] [ebp-348h]
  char v9; // [esp+25h] [ebp-347h]
  _BYTE v10[838]; // [esp+26h] [ebp-346h] BYREF

  v8 = dword_B640C8[0];
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    v9 = *(_BYTE *)(this + 113349);
    qmemcpy(v10, (const void *)(this + 113350), 4 * ((unsigned int)(4 * v9) >> 2));
    v3 = 4 * v9 + 2;
  }
  else
  {
    v9 = 0;
    v3 = 1;
  }
  v6 = dbl_FB1D18;
  sub_51B2A0(4, 2, v3, 255, LODWORD(v6), 3);
  v4 = (_BYTE *)sub_59B480(*(_DWORD *)(this + 113316));
  if ( a2 == -1 )
    v4[4] = 1;
  else
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v4 + 12))(v4, a2);
  sub_59B7F0((char)&v7, ((v7 >> 8) & 0x3FF) + 8, (char)v4, 1, 1, -1, 0);
  return sub_59B490(*(_DWORD *)(this + 113316), v4);
}
