void __thiscall sub_452270(int this)
{
  int v2; // eax
  int v3; // eax
  float *v4; // ecx
  int v5; // edi
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int i; // eax
  float v18; // [esp+20h] [ebp-54h]
  _DWORD v19[20]; // [esp+24h] [ebp-50h] BYREF

  v2 = *(_DWORD *)(this + 128);
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 100))(v2);
    v3 = (*(int (__stdcall **)(_DWORD, int, _DWORD *))(**(_DWORD **)(this + 128) + 36))(
           *(_DWORD *)(this + 128),
           80,
           v19);
    if ( v3 != -2147024884 && v3 != -2147024866 )
      goto LABEL_7;
    if ( dbl_7DA9D8 >= flt_764D50 + 3.0 )
    {
      flt_764D50 = dbl_7DA9D8;
      if ( !(*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 128) + 28))(*(_DWORD *)(this + 128)) )
      {
        v3 = (*(int (__stdcall **)(_DWORD, int, _DWORD *))(**(_DWORD **)(this + 128) + 36))(
               *(_DWORD *)(this + 128),
               80,
               v19);
LABEL_7:
        if ( v3 )
          return;
        v4 = (float *)(this + 952);
        v5 = 8;
        *(float *)(this + 920) = (float)v19[0];
        *(float *)(this + 924) = (float)v19[1];
        *(float *)(this + 928) = (float)v19[2];
        *(float *)(this + 932) = (float)v19[3];
        *(float *)(this + 936) = (float)v19[4];
        *(float *)(this + 940) = (float)v19[5];
        *(float *)(this + 944) = (float)v19[6];
        *(float *)(this + 948) = (float)v19[7];
        while ( 1 )
        {
          if ( *(v4 - 8) == 0.0 )
          {
            *v4 = -1.0;
          }
          else
          {
            v18 = *(v4 - 8);
            *v4 = v18;
            if ( v7 | v8 )
            {
              if ( *(v4 - 40) == 0.0 || (v9 = v18 + *(v4 - 40), *v4 = v9, v9 <= *(v4 - 32)) )
              {
                v10 = (*(v4 - 32) - *v4) * *(v4 - 24);
                *v4 = v10;
                if ( v10 > 1.0 )
                  *v4 = 1.0;
                if ( *((_DWORD *)v4 - 48) != 1065353216 )
                  *v4 = ((1.0 - *(v4 - 48)) * *v4 + *(v4 - 48)) * *v4;
                v11 = -*v4;
LABEL_27:
                *v4 = v11;
                goto LABEL_28;
              }
              *v4 = 0.0;
            }
            else
            {
              if ( *(v4 - 40) == 0.0 || (v12 = v18 - *(v4 - 40), *v4 = v12, v12 >= *(v4 - 32)) )
              {
                v13 = (*v4 - *(v4 - 32)) * *(v4 - 16);
                *v4 = v13;
                if ( v13 > 1.0 )
                  *v4 = 1.0;
                if ( *((_DWORD *)v4 - 48) == 1065353216 )
                  goto LABEL_28;
                v11 = ((1.0 - *(v4 - 48)) * *v4 + *(v4 - 48)) * *v4;
                goto LABEL_27;
              }
              *v4 = 0.0;
            }
          }
LABEL_28:
          ++v4;
          if ( !--v5 )
          {
            v14 = v19[9];
            v15 = v19[10];
            *(_DWORD *)(this + 1000) = v19[8];
            v16 = v19[11];
            *(_DWORD *)(this + 1004) = v14;
            *(_DWORD *)(this + 1008) = v15;
            *(_DWORD *)(this + 1012) = v16;
            for ( i = 0; i < 16; ++i )
              *(_BYTE *)(this + i + 984) = *((_BYTE *)&v19[12] + i) >> 7;
            return;
          }
        }
      }
    }
  }
}
