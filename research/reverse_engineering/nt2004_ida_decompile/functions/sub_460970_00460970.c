int __thiscall sub_460970(int this, int a2)
{
  int v3; // eax
  _BYTE *v4; // esi
  float v6; // [esp+0h] [ebp-E0h]
  _WORD v7[4]; // [esp+10h] [ebp-D0h] BYREF
  char v8; // [esp+18h] [ebp-C8h]
  char v9; // [esp+19h] [ebp-C7h]
  _BYTE v10[198]; // [esp+1Ah] [ebp-C6h] BYREF

  v8 = dword_75CBB0;
  if ( dword_75CBB0 == 7 )
  {
    v9 = *(_BYTE *)(this + 6741);
    qmemcpy(v10, (const void *)(this + 6742), 4 * ((unsigned int)(4 * v9) >> 2));
    v3 = 4 * v9 + 2;
  }
  else
  {
    v9 = 0;
    v3 = 1;
  }
  v6 = dbl_7DA9D0;
  sub_4D0D00(4, 2, v3, 63, LODWORD(v6), 3);
  v4 = (_BYTE *)sub_56A3B0(*(_DWORD *)(this + 6708));
  if ( a2 == -1 )
    v4[4] = 1;
  else
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v4 + 12))(v4, a2);
  sub_56A3D0(v7, (v7[0] >> 6) + 8, v4, 1, 1, -1, 0);
  return sub_56A3C0(*(_DWORD *)(this + 6708), v4);
}
