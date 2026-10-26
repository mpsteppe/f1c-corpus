int __thiscall sub_438690(int this, double a2, int a3)
{
  double v4; // st7
  double v5; // st7
  double v6; // st6
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  double v14; // st7
  double v15; // st6
  const void *v16; // esi
  int result; // eax
  double v18; // [esp+10h] [ebp-40h]
  double v19; // [esp+10h] [ebp-40h]
  double v20; // [esp+18h] [ebp-38h]
  double v21; // [esp+18h] [ebp-38h]
  _BYTE v22[16]; // [esp+20h] [ebp-30h] BYREF
  double v23; // [esp+30h] [ebp-20h]
  double v24[3]; // [esp+38h] [ebp-18h] BYREF

  v20 = fabs(*(double *)(this + 188)) * *(double *)(this + 980);
  v18 = v20 * *(double *)(this + 1044);
  Mat3x3MulVec(a3 + 100, v22);
  if ( v23 >= 0.0 )
    v4 = 0.0;
  else
    v4 = -v23;
  v5 = ((flt_8AFEF0 + 273.16 + flt_8AFEF4 + 273.16) * 0.5 - *(double *)(this + 1028))
     * (v4 * *(double *)(this + 1060) + *(double *)(this + 1052))
     + v18;
  if ( *(double *)(this + 1068) <= *(double *)(this + 1092) )
  {
    v14 = v5 / *(double *)(this + 1092);
  }
  else
  {
    v6 = *(double *)(this + 1068)
       - *(double *)(this + 1028)
       * *(double *)(this + 1028)
       * *(double *)(this + 1028)
       * *(double *)(this + 1084)
       * v20
       * a2;
    *(double *)(this + 1068) = v6;
    if ( v8 | v9 )
    {
      v10 = 0;
      if ( dword_5C329C > 0 )
      {
        while ( *(_DWORD *)(dword_7C54F0[v10] + 13000) )
        {
          if ( ++v10 >= dword_5C329C )
            goto LABEL_12;
        }
        v11 = dword_7C54F0[v10];
        v12 = *(_DWORD *)(v11 + 16488);
        v13 = v11 + 16436;
        if ( !v12 )
          *(_DWORD *)(v13 + 52) = 5;
      }
LABEL_12:
      v14 = 0.0;
      *(_DWORD *)(this + 1068) = 0;
      *(_DWORD *)(this + 1072) = 0;
      *(_DWORD *)(this + 996) = 0;
      *(_DWORD *)(this + 1000) = 0;
    }
    else
    {
      v19 = v5 / v6;
      v14 = v19;
      v15 = fabs(*(double *)(this + 1028) - *(double *)(this + 1036));
      if ( v15 <= *(double *)(this + 1012) )
      {
        *(long double *)(this + 996) = (cos(v15 * *(double *)(this + 1020)) * 0.25 + 0.75) * *(double *)(this + 1004);
      }
      else
      {
        if ( *(double *)(this + 1004) * 0.5 < *(double *)(this + 996) )
        {
          DisplayMessage0x4a();
          v14 = v19;
        }
        *(double *)(this + 996) = *(double *)(this + 1004) * 0.5;
      }
    }
  }
  v16 = (const void *)(*(_DWORD *)(this + 348) + 188);
  *(double *)(this + 1028) = v14 * a2 + *(double *)(this + 1028);
  qmemcpy(v24, v16, sizeof(v24));
  v24[0] = *(double *)(this + 1076) * *(double *)(this + 1068) + *(double *)(this + 204);
  v21 = v24[0];
  result = StructCopyWithReciprocalDivision(v24);
  *(double *)(this + 212) = 1.0 / v21;
  return result;
}
