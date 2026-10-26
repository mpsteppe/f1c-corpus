int __stdcall sub_5AB683(int a1, float *a2, float a3, float *a4, float *a5, float a6, float *a7)
{
  unsigned __int8 v8; // c2
  unsigned __int8 v9; // c3
  int v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // eax
  int v15; // [esp+14h] [ebp-C8h] BYREF
  _BYTE v16[64]; // [esp+54h] [ebp-88h] BYREF
  _DWORD v17[18]; // [esp+94h] [ebp-48h] BYREF

  if ( a4 )
  {
    if ( v9 | v8 )
    {
      v11 = a1;
      if ( a2 )
      {
        *(float *)(a1 + 44) = 0.0;
        *(float *)(a1 + 36) = 0.0;
        *(float *)(a1 + 32) = 0.0;
        *(float *)(a1 + 28) = 0.0;
        *(float *)(a1 + 24) = 0.0;
        *(float *)(a1 + 16) = 0.0;
        *(float *)(a1 + 12) = 0.0;
        *(float *)(a1 + 8) = 0.0;
        *(float *)(a1 + 4) = 0.0;
        *(float *)a1 = *a4;
        v12 = *((_DWORD *)a4 + 1);
        *(float *)(a1 + 40) = 1.0;
        *(_DWORD *)(a1 + 20) = v12;
        *(float *)(a1 + 48) = (1.0 - *a4) * *a2;
        *(float *)(a1 + 52) = (1.0 - a4[1]) * a2[1];
        *(float *)(a1 + 56) = 0.0;
      }
      else
      {
        *(float *)(a1 + 56) = 0.0;
        *(float *)(a1 + 52) = 0.0;
        *(float *)(a1 + 48) = 0.0;
        *(float *)(a1 + 44) = 0.0;
        *(float *)(a1 + 36) = 0.0;
        *(float *)(a1 + 32) = 0.0;
        *(float *)(a1 + 28) = 0.0;
        *(float *)(a1 + 24) = 0.0;
        *(float *)(a1 + 16) = 0.0;
        *(float *)(a1 + 12) = 0.0;
        *(float *)(a1 + 8) = 0.0;
        *(float *)(a1 + 4) = 0.0;
        *(float *)a1 = *a4;
        v13 = *((_DWORD *)a4 + 1);
        *(float *)(a1 + 40) = 1.0;
        *(_DWORD *)(a1 + 20) = v13;
      }
      *(float *)(a1 + 60) = 1.0;
    }
    else
    {
      *(float *)&v17[14] = 0.0;
      *(float *)v17 = *a4;
      *(float *)&v17[13] = 0.0;
      v10 = *((_DWORD *)a4 + 1);
      *(float *)&v17[12] = 0.0;
      v17[5] = v10;
      *(float *)&v17[11] = 0.0;
      *(float *)&v17[9] = 0.0;
      *(float *)&v17[8] = 0.0;
      *(float *)&v17[7] = 0.0;
      *(float *)&v17[6] = 0.0;
      *(float *)&v17[4] = 0.0;
      *(float *)&v17[3] = 0.0;
      *(float *)&v17[2] = 0.0;
      *(float *)&v17[1] = 0.0;
      *(float *)&v17[10] = 1.0;
      *(float *)&v17[15] = 1.0;
      sub_5AB05C((int)v16, a3);
      if ( a2 )
      {
        sub_5AA765();
        v11 = a1;
        *(float *)(a1 + 56) = 0.0;
        *(float *)(a1 + 52) = 0.0;
        *(float *)(a1 + 48) = 0.0;
        *(float *)(a1 + 44) = 0.0;
        *(float *)(a1 + 36) = 0.0;
        *(float *)(a1 + 32) = 0.0;
        *(float *)(a1 + 28) = 0.0;
        *(float *)(a1 + 24) = 0.0;
        *(float *)(a1 + 16) = 0.0;
        *(float *)(a1 + 12) = 0.0;
        *(float *)(a1 + 8) = 0.0;
        *(float *)(a1 + 4) = 0.0;
        *(float *)(a1 + 60) = 1.0;
        *(float *)(a1 + 40) = 1.0;
        *(float *)(a1 + 20) = 1.0;
        *(float *)a1 = 1.0;
        *(float *)(a1 + 48) = -*a2;
        *(float *)(a1 + 52) = -a2[1];
        sub_5AA514(a1, a1, (int)&v15);
        sub_5AA514(v11, v11, (int)v17);
        sub_5AA514(v11, v11, (int)v16);
        *(float *)(a1 + 48) = *a2 + *(float *)(a1 + 48);
        *(float *)(a1 + 52) = a2[1] + *(float *)(a1 + 52);
      }
      else
      {
        v11 = a1;
        sub_5AA765();
        sub_5AA514(v11, v11, (int)v17);
        sub_5AA514(v11, v11, (int)v16);
      }
    }
  }
  else
  {
    v11 = a1;
    *(float *)(a1 + 56) = 0.0;
    *(float *)(a1 + 52) = 0.0;
    *(float *)(a1 + 48) = 0.0;
    *(float *)(a1 + 44) = 0.0;
    *(float *)(a1 + 36) = 0.0;
    *(float *)(a1 + 32) = 0.0;
    *(float *)(a1 + 28) = 0.0;
    *(float *)(a1 + 24) = 0.0;
    *(float *)(a1 + 16) = 0.0;
    *(float *)(a1 + 12) = 0.0;
    *(float *)(a1 + 8) = 0.0;
    *(float *)(a1 + 4) = 0.0;
    *(float *)(a1 + 60) = 1.0;
    *(float *)(a1 + 40) = 1.0;
    *(float *)(a1 + 20) = 1.0;
    *(float *)a1 = 1.0;
  }
  if ( 0.0 != a6 )
  {
    sub_5AB05C((int)v16, a6);
    if ( a5 )
    {
      *(float *)(v11 + 48) = *(float *)(v11 + 48) - *a5;
      *(float *)(v11 + 52) = *(float *)(v11 + 52) - a5[1];
      sub_5AA514(v11, v11, (int)v16);
      *(float *)(v11 + 48) = *a5 + *(float *)(v11 + 48);
      *(float *)(v11 + 52) = a5[1] + *(float *)(v11 + 52);
    }
    else
    {
      sub_5AA514(v11, v11, (int)v16);
    }
  }
  if ( a7 )
  {
    *(float *)(v11 + 48) = *a7 + *(float *)(v11 + 48);
    *(float *)(v11 + 52) = a7[1] + *(float *)(v11 + 52);
  }
  return v11;
}
