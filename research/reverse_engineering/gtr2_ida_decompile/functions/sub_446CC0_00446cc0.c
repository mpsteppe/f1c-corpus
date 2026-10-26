void __thiscall sub_446CC0(int this)
{
  int v2; // eax
  char v3; // cl
  int v4; // eax
  double *v5; // ecx
  long double v6; // st4
  double v7; // st6
  double v8[3]; // [esp+0h] [ebp-18h] BYREF

  v2 = *(_DWORD *)(this + 9392);
  v3 = *(_BYTE *)(v2 + 15572);
  v4 = v2 + 14824;
  if ( v3 )
  {
    if ( *(_DWORD *)(v4 + 752) != 3 )
    {
      if ( byte_B6FA9C )
      {
        v5 = *(double **)(this + 6312);
        v6 = (8.0 - sqrt(v5[13] * v5[13] + v5[14] * v5[14] + v5[15] * v5[15])) * 93.75;
        if ( v6 > 0.0 )
        {
          v7 = *(double *)(this + 72);
          if ( *(_DWORD *)(this + 9376) != -1 )
            v7 = -v7;
          v8[0] = v6 * v7 * v5[6];
          v8[1] = v6 * v7 * v5[9];
          v8[2] = v6 * v7 * v5[12];
          sub_43A660(v5, v8);
        }
      }
    }
  }
}
