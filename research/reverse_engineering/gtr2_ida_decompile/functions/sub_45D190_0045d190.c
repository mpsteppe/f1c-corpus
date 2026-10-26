int __thiscall sub_45D190(double *this, int a2)
{
  int v3; // ecx
  double v4; // st7
  __int16 v5; // si
  __int16 *v6; // esi

  v3 = *(_DWORD *)(a2 + 48);
  if ( v3 && !*(_BYTE *)(v3 + 88) && sub_45B1F0((double *)v3, a2) )
    return *(_DWORD *)(a2 + 48);
  v4 = *(double *)a2;
  *(_DWORD *)(a2 + 48) = 0;
  v5 = sub_431910((v4 - this[1]) * this[2]);
  v6 = (__int16 *)*((_DWORD *)this
                  + (((unsigned __int16)sub_431910((*(double *)(a2 + 16) - this[3]) * this[4]) + 32 * v5) & 0x3FF)
                  + 10);
  if ( v6 )
    sub_45BAC0(v6, (double *)a2);
  return *(_DWORD *)(a2 + 48);
}
