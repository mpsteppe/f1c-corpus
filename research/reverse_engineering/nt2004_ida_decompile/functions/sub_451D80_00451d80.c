void __thiscall sub_451D80(
        _DWORD *this,
        int a2,
        float *a3,
        float *a4,
        float *a5,
        float *a6,
        float *a7,
        float *a8,
        float a9,
        float a10)
{
  int v10; // eax
  double v11; // st7
  double v12; // st6
  double v13; // st4
  double v14; // st6
  _DWORD v15[6]; // [esp+0h] [ebp-18h] BYREF
  int v16; // [esp+1Ch] [ebp+4h]

  v10 = this[32];
  if ( v10 )
  {
    v15[2] = a2;
    v15[0] = 24;
    v15[1] = 16;
    v15[3] = 1;
    if ( !(*(int (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v10 + 20))(v10, 4, v15) )
    {
      v11 = (double)v15[4];
      v12 = (double)v15[5];
      *a7 = v11;
      *a6 = 0.0;
      if ( v11 != v12 )
        *a6 = 1.0 / (v12 - v11);
      *a3 = a10 * (v12 - v11) + v11;
      v13 = (v12 - v11) * a9 * 0.5;
      *a8 = v13;
      *(float *)&v16 = v13 + v11;
      v14 = v12 - *a8;
      *a4 = 0.0;
      if ( *a3 != *(float *)&v16 )
        *a4 = 1.0 / (*a3 - *(float *)&v16);
      *a5 = 0.0;
      if ( v14 != *a3 )
        *a5 = 1.0 / (v14 - *a3);
    }
  }
}
