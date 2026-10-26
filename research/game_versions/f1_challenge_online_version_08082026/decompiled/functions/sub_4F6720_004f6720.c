void __thiscall sub_4F6720(double *this, double a2, double *a3, double *a4)
{
  int v4; // esi
  int v5; // edx
  double *v6; // edi
  int v7; // eax
  double *v8; // esi
  double v9; // st7
  double v10; // st7
  double v11; // st7

  v4 = *((_DWORD *)this + 433);
  if ( v4 > 0 )
  {
    if ( v4 == 1 )
    {
      *(_DWORD *)a3 = *((_DWORD *)this + 436);
      *((_DWORD *)a3 + 1) = *((_DWORD *)this + 437);
      *(_DWORD *)a4 = *((_DWORD *)this + 438);
      *((_DWORD *)a4 + 1) = *((_DWORD *)this + 439);
    }
    else
    {
      v5 = 0;
      v6 = this + 217;
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
      v8 = &this[3 * v7];
      v9 = (a2 - v8[217]) / (this[3 * v5 + 217] - v8[217]);
      *a3 = (this[3 * v5 + 218] - v8[218]) * v9 + v8[218];
      v10 = v9 * (this[3 * v5 + 219] - this[3 * v7 + 219]) + this[3 * v7 + 219];
      *a4 = v10;
      if ( v10 < *a3 )
      {
        v11 = (v10 + *a3) * 0.5;
        *a3 = v11;
        *a4 = v11;
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
