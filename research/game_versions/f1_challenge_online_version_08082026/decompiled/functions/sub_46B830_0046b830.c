void __stdcall sub_46B830(int a1, char *a2, int a3)
{
  int v3; // esi
  char *v4; // edi
  double v5; // st7
  double v6; // st7
  int v7; // eax
  int v8; // eax
  double v9; // st7
  int v10; // eax
  float v11; // [esp+18h] [ebp+4h]
  float v12; // [esp+18h] [ebp+4h]
  float v13; // [esp+1Ch] [ebp+8h]

  v3 = dword_7C54F0[a1];
  v4 = strcpy(a2, asc_5C6A94);
  if ( v3 && dword_7C56A4 >= 0 )
  {
    if ( dword_7C56A4 <= 6 )
    {
      if ( *(_DWORD *)(v3 + 16484) != 3 )
      {
        v7 = 0;
        if ( dword_5C329C > 0 )
        {
          while ( *(_DWORD *)(dword_7C54F0[v7] + 16480) != 1 )
          {
            if ( ++v7 >= dword_5C329C )
              return;
          }
          v8 = dword_7C54F0[v7];
          if ( v8 )
          {
            v13 = *(float *)(v8 + 16540);
            v11 = *(float *)(v3 + 16540);
            if ( v13 > 0.0 && v11 > 0.0 )
            {
              v9 = v11 - v13;
              v12 = v9;
              sub_58957A(v9);
              v10 = sub_587BDC(v12 * 0.016666668);
              sub_58815F(v4, "%02.2d:%06.3f", v10, v9);
            }
          }
        }
      }
    }
    else if ( dword_7C56A4 == 7 && *(_DWORD *)(v3 + 16484) == 1 && *(float *)(v3 + 16568) > 0.0 )
    {
      v5 = (double)*(int *)(v3 + 16444) * flt_5EA3FC / *(float *)(v3 + 16568);
      if ( byte_7D0474 )
        v6 = v5 * 0.001;
      else
        v6 = v5 * 0.0006213711922373339;
      sub_58815F(v4, "%6.2f", v6 * 3600.0);
    }
  }
}
