void __thiscall sub_45F160(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  float *v5; // ecx
  int v6; // edi
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int i; // eax
  float v19; // [esp+20h] [ebp-54h]
  _DWORD v20[20]; // [esp+24h] [ebp-50h] BYREF

  v2 = *(_DWORD *)(this + 128);
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 100))(v2);
    v3 = (*(int (__stdcall **)(_DWORD, int, _DWORD *))(**(_DWORD **)(this + 128) + 36))(
           *(_DWORD *)(this + 128),
           80,
           v20);
    if ( v3 != -2147024884 && v3 != -2147024866 )
      goto LABEL_7;
    if ( fabs(dbl_FB1D20 - flt_B6C4F0) >= 3.0 )
    {
      v4 = *(_DWORD *)(this + 128);
      flt_B6C4F0 = dbl_FB1D20;
      if ( !(*(int (__stdcall **)(int))(*(_DWORD *)v4 + 28))(v4) )
      {
        v3 = (*(int (__stdcall **)(_DWORD, int, _DWORD *))(**(_DWORD **)(this + 128) + 36))(
               *(_DWORD *)(this + 128),
               80,
               v20);
LABEL_7:
        if ( v3 )
          return;
        v5 = (float *)(this + 952);
        v6 = 8;
        *(float *)(this + 920) = (float)v20[0];
        *(float *)(this + 924) = (float)v20[1];
        *(float *)(this + 928) = (float)v20[2];
        *(float *)(this + 932) = (float)v20[3];
        *(float *)(this + 936) = (float)v20[4];
        *(float *)(this + 940) = (float)v20[5];
        *(float *)(this + 944) = (float)v20[6];
        *(float *)(this + 948) = (float)v20[7];
        while ( 1 )
        {
          if ( *(v5 - 8) == 0.0 )
          {
            *v5 = -1.0;
          }
          else
          {
            v19 = *(v5 - 8);
            *v5 = v19;
            if ( v8 | v9 )
            {
              if ( *(v5 - 40) == 0.0 || (v10 = v19 + *(v5 - 40), *v5 = v10, v10 <= *(v5 - 32)) )
              {
                v11 = (*(v5 - 32) - *v5) * *(v5 - 24);
                *v5 = v11;
                if ( v11 > 1.0 )
                  *v5 = 1.0;
                if ( *((_DWORD *)v5 - 48) != 1065353216 )
                  *v5 = ((1.0 - *(v5 - 48)) * *v5 + *(v5 - 48)) * *v5;
                v12 = -*v5;
LABEL_27:
                *v5 = v12;
                goto LABEL_28;
              }
              *v5 = 0.0;
            }
            else
            {
              if ( *(v5 - 40) == 0.0 || (v13 = v19 - *(v5 - 40), *v5 = v13, v13 >= *(v5 - 32)) )
              {
                v14 = (*v5 - *(v5 - 32)) * *(v5 - 16);
                *v5 = v14;
                if ( v14 > 1.0 )
                  *v5 = 1.0;
                if ( *((_DWORD *)v5 - 48) == 1065353216 )
                  goto LABEL_28;
                v12 = ((1.0 - *(v5 - 48)) * *v5 + *(v5 - 48)) * *v5;
                goto LABEL_27;
              }
              *v5 = 0.0;
            }
          }
LABEL_28:
          ++v5;
          if ( !--v6 )
          {
            v15 = v20[10];
            v16 = v20[9];
            *(_DWORD *)(this + 1008) = v20[8];
            v17 = v20[11];
            *(_DWORD *)(this + 1016) = v15;
            *(_DWORD *)(this + 1012) = v16;
            *(_DWORD *)(this + 1020) = v17;
            for ( i = 0; i < 24; ++i )
              *(_BYTE *)(this + i + 984) = *((_BYTE *)&v20[12] + i) >> 7;
            return;
          }
        }
      }
    }
  }
}
