unsigned __int64 __thiscall sub_6078F0(int this, int a2, int a3)
{
  int v4; // ebx
  unsigned int v5; // edi
  float *v6; // ecx
  float *v7; // ecx
  int v8; // edx
  double v9; // st7
  unsigned __int64 v10; // rax
  double v11; // st6
  unsigned __int64 v12; // rax
  double v13; // st6
  unsigned __int64 v14; // rax
  double v15; // st6
  unsigned __int64 v16; // rax
  int v17; // ecx
  int v18; // edi
  double v19; // st7
  unsigned __int64 v20; // rax
  double v21; // st7
  unsigned __int64 result; // rax
  float v23; // [esp+14h] [ebp+4h]
  float v24; // [esp+18h] [ebp+8h]

  *(_DWORD *)(this + 44) = 1399379109;
  *(_DWORD *)(this + 40) = 1399379109;
  *(_DWORD *)(this + 36) = 1399379109;
  v4 = 0;
  *(_DWORD *)(this + 56) = -748104539;
  *(_DWORD *)(this + 52) = -748104539;
  *(_DWORD *)(this + 48) = -748104539;
  if ( a3 >= 4 )
  {
    v5 = ((unsigned int)(a3 - 4) >> 2) + 1;
    v6 = (float *)(a2 + 8);
    v4 = 4 * v5;
    do
    {
      if ( *(v6 - 2) < (double)*(float *)(this + 36) )
        *(float *)(this + 36) = *(v6 - 2);
      if ( *(v6 - 1) < (double)*(float *)(this + 40) )
        *(float *)(this + 40) = *(v6 - 1);
      if ( *v6 < (double)*(float *)(this + 44) )
        *(float *)(this + 44) = *v6;
      if ( *(v6 - 2) > (double)*(float *)(this + 48) )
        *(float *)(this + 48) = *(v6 - 2);
      if ( *(v6 - 1) > (double)*(float *)(this + 52) )
        *(float *)(this + 52) = *(v6 - 1);
      if ( *v6 > (double)*(float *)(this + 56) )
        *(float *)(this + 56) = *v6;
      if ( v6[1] < (double)*(float *)(this + 36) )
        *(float *)(this + 36) = v6[1];
      if ( v6[2] < (double)*(float *)(this + 40) )
        *(float *)(this + 40) = v6[2];
      if ( v6[3] < (double)*(float *)(this + 44) )
        *(float *)(this + 44) = v6[3];
      if ( v6[1] > (double)*(float *)(this + 48) )
        *(float *)(this + 48) = v6[1];
      if ( v6[2] > (double)*(float *)(this + 52) )
        *(float *)(this + 52) = v6[2];
      if ( v6[3] > (double)*(float *)(this + 56) )
        *(float *)(this + 56) = v6[3];
      if ( v6[4] < (double)*(float *)(this + 36) )
        *(float *)(this + 36) = v6[4];
      if ( v6[5] < (double)*(float *)(this + 40) )
        *(float *)(this + 40) = v6[5];
      if ( v6[6] < (double)*(float *)(this + 44) )
        *(float *)(this + 44) = v6[6];
      if ( v6[4] > (double)*(float *)(this + 48) )
        *(float *)(this + 48) = v6[4];
      if ( v6[5] > (double)*(float *)(this + 52) )
        *(float *)(this + 52) = v6[5];
      if ( v6[6] > (double)*(float *)(this + 56) )
        *(float *)(this + 56) = v6[6];
      if ( v6[7] < (double)*(float *)(this + 36) )
        *(float *)(this + 36) = v6[7];
      if ( v6[8] < (double)*(float *)(this + 40) )
        *(float *)(this + 40) = v6[8];
      if ( v6[9] < (double)*(float *)(this + 44) )
        *(float *)(this + 44) = v6[9];
      if ( v6[7] > (double)*(float *)(this + 48) )
        *(float *)(this + 48) = v6[7];
      if ( v6[8] > (double)*(float *)(this + 52) )
        *(float *)(this + 52) = v6[8];
      if ( v6[9] > (double)*(float *)(this + 56) )
        *(float *)(this + 56) = v6[9];
      v6 += 12;
      --v5;
    }
    while ( v5 );
  }
  if ( v4 < a3 )
  {
    v7 = (float *)(a2 + 12 * v4 + 8);
    v8 = a3 - v4;
    do
    {
      if ( *(v7 - 2) < (double)*(float *)(this + 36) )
        *(float *)(this + 36) = *(v7 - 2);
      if ( *(v7 - 1) < (double)*(float *)(this + 40) )
        *(float *)(this + 40) = *(v7 - 1);
      if ( *v7 < (double)*(float *)(this + 44) )
        *(float *)(this + 44) = *v7;
      if ( *(v7 - 2) > (double)*(float *)(this + 48) )
        *(float *)(this + 48) = *(v7 - 2);
      if ( *(v7 - 1) > (double)*(float *)(this + 52) )
        *(float *)(this + 52) = *(v7 - 1);
      if ( *v7 > (double)*(float *)(this + 56) )
        *(float *)(this + 56) = *v7;
      v7 += 3;
      --v8;
    }
    while ( v8 );
  }
  v9 = 1.0 / *(float *)(this + 12);
  v10 = (unsigned __int64)((*(float *)(this + 36) - *(float *)(this + 24)) * v9);
  v11 = 1.0 / *(float *)(this + 16);
  *(_DWORD *)(this + 72) = (v10 & 0x80000000) != 0LL ? 0 : v10;
  v24 = v11;
  v12 = (unsigned __int64)((*(float *)(this + 40) - *(float *)(this + 28)) * v24);
  v13 = 1.0 / *(float *)(this + 20);
  *(_DWORD *)(this + 76) = (v12 & 0x80000000) != 0LL ? 0 : v12;
  v23 = v13;
  v14 = (unsigned __int64)((*(float *)(this + 44) - *(float *)(this + 32)) * v23);
  v15 = (*(float *)(this + 48) - *(float *)(this + 24)) * v9;
  *(_DWORD *)(this + 80) = (v14 & 0x80000000) != 0LL ? 0 : v14;
  v16 = (unsigned __int64)v15;
  v17 = *(_DWORD *)(this + 8);
  v18 = v17 - 1;
  if ( v17 - 1 < (int)(unsigned __int64)v15 )
    LODWORD(v16) = v17 - 1;
  v19 = *(float *)(this + 52);
  *(_DWORD *)(this + 84) = v16;
  v20 = (unsigned __int64)((v19 - *(float *)(this + 28)) * v24);
  if ( v18 < (int)v20 )
    LODWORD(v20) = v17 - 1;
  v21 = *(float *)(this + 56);
  *(_DWORD *)(this + 88) = v20;
  result = (unsigned __int64)((v21 - *(float *)(this + 32)) * v23);
  if ( v18 >= (int)result )
    *(_DWORD *)(this + 92) = result;
  else
    *(_DWORD *)(this + 92) = v18;
  return result;
}
