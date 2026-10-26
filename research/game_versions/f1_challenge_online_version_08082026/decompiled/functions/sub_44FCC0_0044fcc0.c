int __thiscall sub_44FCC0(int this)
{
  int result; // eax
  float *v3; // ecx
  int v4; // edi
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  float v16; // [esp+20h] [ebp-54h]
  _DWORD v17[20]; // [esp+24h] [ebp-50h] BYREF

  result = *(_DWORD *)(this + 128);
  if ( result )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)result + 100))(result);
    result = (*(int (__stdcall **)(_DWORD, int, _DWORD *))(**(_DWORD **)(this + 128) + 36))(
               *(_DWORD *)(this + 128),
               80,
               v17);
    if ( result == -2147024884 || result == -2147024866 )
    {
      result = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 128) + 28))(*(_DWORD *)(this + 128));
      if ( result )
        return result;
      result = (*(int (__stdcall **)(_DWORD, int, _DWORD *))(**(_DWORD **)(this + 128) + 36))(
                 *(_DWORD *)(this + 128),
                 80,
                 v17);
    }
    if ( !result )
    {
      v3 = (float *)(this + 952);
      v4 = 8;
      *(float *)(this + 920) = (float)v17[0];
      *(float *)(this + 924) = (float)v17[1];
      *(float *)(this + 928) = (float)v17[2];
      *(float *)(this + 932) = (float)v17[3];
      *(float *)(this + 936) = (float)v17[4];
      *(float *)(this + 940) = (float)v17[5];
      *(float *)(this + 944) = (float)v17[6];
      *(float *)(this + 948) = (float)v17[7];
      while ( 1 )
      {
        if ( *(v3 - 8) == 0.0 )
        {
          *v3 = -1.0;
        }
        else
        {
          v16 = *(v3 - 8);
          *v3 = v16;
          if ( v6 | v7 )
          {
            if ( *(v3 - 40) == 0.0 || (v8 = v16 + *(v3 - 40), *v3 = v8, v8 <= *(v3 - 32)) )
            {
              v9 = (*(v3 - 32) - *v3) * *(v3 - 24);
              *v3 = v9;
              if ( v9 > 1.0 )
                *v3 = 1.0;
              if ( *((_DWORD *)v3 - 48) != 1065353216 )
                *v3 = ((1.0 - *(v3 - 48)) * *v3 + *(v3 - 48)) * *v3;
              v10 = -*v3;
LABEL_26:
              *v3 = v10;
              goto LABEL_27;
            }
            *v3 = 0.0;
          }
          else
          {
            if ( *(v3 - 40) == 0.0 || (v11 = v16 - *(v3 - 40), *v3 = v11, v11 >= *(v3 - 32)) )
            {
              v12 = (*v3 - *(v3 - 32)) * *(v3 - 16);
              *v3 = v12;
              if ( v12 > 1.0 )
                *v3 = 1.0;
              if ( *((_DWORD *)v3 - 48) == 1065353216 )
                goto LABEL_27;
              v10 = ((1.0 - *(v3 - 48)) * *v3 + *(v3 - 48)) * *v3;
              goto LABEL_26;
            }
            *v3 = 0.0;
          }
        }
LABEL_27:
        ++v3;
        if ( !--v4 )
        {
          v13 = v17[9];
          v14 = v17[10];
          *(_DWORD *)(this + 1000) = v17[8];
          v15 = v17[11];
          *(_DWORD *)(this + 1004) = v13;
          *(_DWORD *)(this + 1008) = v14;
          *(_DWORD *)(this + 1012) = v15;
          for ( result = 0; result < 16; ++result )
            *(_BYTE *)(this + result + 984) = *((_BYTE *)&v17[12] + result) >> 7;
          return result;
        }
      }
    }
  }
  return result;
}
