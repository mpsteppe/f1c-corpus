// f1c  0x00441ad0  size=213
void __thiscall sub_441AD0(int this)
{
  int v1; // eax
  char v2; // dl
  int v3; // eax
  int v4; // edx
  long double v5; // st4
  double v6; // st6
  long double v7; // [esp+8h] [ebp-10h]
  long double v8; // [esp+10h] [ebp-8h]

  v1 = *(_DWORD *)(this + 7936);
  v2 = *(_BYTE *)(v1 + 13388);
  v3 = v1 + 13004;
  if ( v2 )
  {
    if ( *(_DWORD *)(v3 + 388) != 3 )
    {
      if ( byte_7CE838 )
      {
        v4 = *(_DWORD *)(this + 5616);
        v5 = (8.0
            - sqrt(
                *(double *)(v4 + 100) * *(double *)(v4 + 100)
              + *(double *)(v4 + 108) * *(double *)(v4 + 108)
              + *(double *)(v4 + 116) * *(double *)(v4 + 116)))
           * 93.75;
        if ( v5 > 0.0 )
        {
          v6 = *(double *)(this + 72);
          if ( *(_DWORD *)(this + 7920) != -1 )
            v6 = -v6;
          v7 = v5 * v6 * *(double *)(v4 + 68);
          v8 = v5 * v6 * *(double *)(v4 + 92);
          *(long double *)(v4 + 308) = v5 * v6 * *(double *)(v4 + 44) + *(double *)(v4 + 308);
          *(long double *)(v4 + 316) = v7 + *(double *)(v4 + 316);
          *(long double *)(v4 + 324) = v8 + *(double *)(v4 + 324);
        }
      }
    }
  }
}
