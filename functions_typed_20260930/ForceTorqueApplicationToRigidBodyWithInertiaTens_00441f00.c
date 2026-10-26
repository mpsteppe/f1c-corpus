void __thiscall sub_441F00(int this, float a2, float a3, float a4, float a5)
{
  int v6; // edx
  double *v7; // ecx
  int v8; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st7
  double v12; // st7
  double v13; // st6
  double v14[3]; // [esp+4h] [ebp-30h] BYREF
  double v15; // [esp+2Ch] [ebp-8h]

  if ( a2 == 0.0 && a3 == 0.0 && a4 == 0.0 && a5 == 0.0 )
  {
    *(_BYTE *)(this + 5924) = 0;
  }
  else
  {
    *(_BYTE *)(this + 5924) = 1;
    v6 = 0;
    do
    {
      v7 = (double *)(this + 24 * v6);
      v8 = *(_DWORD *)(this + 5616);
      v9 = *(double *)(v8 + 44) * v7[718] + *(double *)(v8 + 36) * v7[717] + *(double *)(v8 + 28) * v7[716];
      v10 = *(double *)(v8 + 68) * v7[718] + *(double *)(v8 + 60) * v7[717] + *(double *)(v8 + 52) * v7[716];
      v15 = *(double *)(v8 + 92) * v7[718] + *(double *)(v8 + 84) * v7[717] + *(double *)(v8 + 76) * v7[716];
      v14[0] = v9 + *(double *)(v8 + 4);
      v11 = v10 + *(double *)(v8 + 12);
      v14[2] = v15 + *(double *)(v8 + 20);
      v12 = v11 - *(double *)(this + 8 * v6 + 5872);
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          v13 = a3;
        }
        else if ( v6 == 2 )
        {
          v13 = a4;
        }
        else
        {
          v13 = a5;
        }
      }
      else
      {
        v13 = a2;
      }
      ++v6;
      v14[1] = v13 + v12 + *(double *)(this + 8 * v6 + 5920) + *(double *)(this + 5620) * 0.000015328125;
      qmemcpy(v7 + 745, v14, 0x18u);
    }
    while ( v6 < 4 );
  }
}

