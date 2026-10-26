void __thiscall sub_524050(double *this, double a2, double *a3, double *a4)
{
  int v4; // esi
  int v5; // edx
  double *v6; // edi
  int v7; // eax
  int v8; // esi
  double v9; // st6
  double *v10; // edx
  double v11; // st7
  double *v12; // eax
  double v13; // st7
  double v14; // st7

  v4 = *((_DWORD *)this + 455);
  if ( v4 > 0 )
  {
    if ( v4 == 1 )
    {
      *(_DWORD *)a3 = *((_DWORD *)this + 458);
      *((_DWORD *)a3 + 1) = *((_DWORD *)this + 459);
      *(_DWORD *)a4 = *((_DWORD *)this + 460);
      *((_DWORD *)a4 + 1) = *((_DWORD *)this + 461);
    }
    else
    {
      v5 = 0;
      v6 = this + 228;
      do
      {
        if ( a2 < *v6 )
          break;
        ++v5;
        v6 += 3;
      }
      while ( v5 < v4 );
      if ( v5 )
      {
        if ( v5 >= v4 )
        {
          v7 = v5 - 2;
          --v5;
        }
        else
        {
          v7 = v5 - 1;
        }
      }
      else
      {
        v7 = 0;
        v5 = 1;
      }
      v8 = 3 * v7 + 228;
      v9 = this[3 * v5 + 228] - this[v8];
      v10 = &this[3 * v5];
      v11 = (a2 - this[v8]) / v9;
      v12 = &this[3 * v7];
      *a3 = (v10[229] - v12[229]) * v11 + v12[229];
      v13 = v11 * (v10[230] - v12[230]) + v12[230];
      *a4 = v13;
      if ( v13 < *a3 )
      {
        v14 = (v13 + *a3) * 0.5;
        *a3 = v14;
        *a4 = v14;
      }
    }
  }
  else
  {
    *(_DWORD *)a3 = 0;
    *((_DWORD *)a3 + 1) = 0;
    *(_DWORD *)a4 = 0;
    *((_DWORD *)a4 + 1) = 0;
  }
}
