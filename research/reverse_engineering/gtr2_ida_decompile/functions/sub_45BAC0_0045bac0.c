void __thiscall sub_45BAC0(__int16 *this, double *a2)
{
  __int16 *v2; // esi
  float *v4; // ecx
  int v5; // esi
  bool v6; // c0
  float v7; // [esp+Ch] [ebp+4h]

  v2 = this;
  if ( this[4] < 0 )
  {
LABEL_8:
    sub_45B1F0(*((double **)v2 + 3), (int)a2);
    if ( v2[4] == -2 )
      sub_45B1F0((double *)(*((_DWORD *)v2 + 3) + 96), (int)a2);
  }
  else
  {
    while ( 1 )
    {
      v4 = (float *)*((_DWORD *)v2 + 3);
      v7 = a2[2] * flt_B685D0[*((char *)v2 + 11)] + *a2 * flt_B685D0[*((char *)v2 + 10)];
      if ( v7 <= (double)v4[1] && v7 >= (double)*v4 )
        sub_45BAC0(a2);
      v5 = *((_DWORD *)v2 + 3);
      v6 = v7 < (double)*(float *)(v5 + 16);
      v2 = (__int16 *)(v5 + 16);
      if ( v6 || v7 > (double)*((float *)v2 + 1) )
        break;
      if ( v2[4] < 0 )
        goto LABEL_8;
    }
  }
}
