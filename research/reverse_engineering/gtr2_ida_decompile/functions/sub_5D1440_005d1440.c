double *__thiscall sub_5D1440(int *this, int a2, int a3)
{
  double *v4; // eax
  double *v5; // esi

  v4 = (double *)operator new(0x58u);
  if ( v4 )
    v5 = sub_5C23D0(v4, a2, this[1]);
  else
    v5 = 0;
  v5[2] = *(float *)(a3 + 4);
  *((_BYTE *)v5 + 83) = *(_BYTE *)(a3 + 32);
  *((_DWORD *)v5 + 12) = *(_DWORD *)(a3 + 16);
  *((_DWORD *)v5 + 18) = *(_DWORD *)(a3 + 24);
  *((float *)v5 + 6) = *(float *)(a3 + 8);
  sub_5C2530((int)v5, *(float *)(a3 + 12), *(float *)a3);
  *((_DWORD *)v5 + 14) = *(_DWORD *)(a3 + 20);
  *((_DWORD *)v5 + 19) = *(_DWORD *)(a3 + 28);
  *((_BYTE *)v5 + 84) = *(_BYTE *)(a3 + 34);
  return v5;
}
