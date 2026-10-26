_DWORD *__thiscall sub_5F1370(_DWORD *this, _DWORD *a2, float a3)
{
  int v4; // esi
  unsigned __int64 v5; // rax
  int v6; // ebx
  int v7; // eax
  float *v8; // ebx
  int v9; // eax
  float *v10; // edi
  float *v11; // esi
  double v12; // st7
  bool v13; // cc
  _DWORD *result; // eax
  float v15; // [esp+0h] [ebp-20h]
  int v16; // [esp+4h] [ebp-1Ch]
  int v17; // [esp+8h] [ebp-18h]
  int v18; // [esp+Ch] [ebp-14h]
  float v19[4]; // [esp+10h] [ebp-10h] BYREF

  v4 = this[7];
  if ( a3 > (double)*(float *)(v4 + 24) )
    a3 = *(float *)(v4 + 24);
  v5 = (unsigned __int64)(a3 / *(float *)(v4 + 24) * (double)*(int *)(v4 + 36));
  this[2] = v5;
  if ( (int)v5 >= *(_DWORD *)(v4 + 36) - 1 )
  {
    if ( (_DWORD)v5 == *(_DWORD *)(v4 + 36) )
    {
      LODWORD(v5) = v5 - 1;
      this[2] = v5;
    }
  }
  else
  {
    LODWORD(v5) = v5 + 1;
  }
  v16 = v5;
  v18 = 0;
  if ( (int)this[5] > 0 )
  {
    v17 = 0;
    do
    {
      v6 = this[6];
      v7 = *(_DWORD *)(v6 + v17 + 4);
      v8 = (float *)(v17 + v6);
      if ( (unsigned __int8)v7 != 255 )
      {
        v9 = *(_DWORD *)(44 * (unsigned __int8)v7 + *(_DWORD *)(this[7] + 32) + 40);
        v10 = (float *)(v9 + 32 * v16);
        v11 = (float *)(v9 + 32 * this[2]);
        v12 = *v10 - *v11;
        if ( 0.0 == v12 )
          v15 = 0.0;
        else
          v15 = (a3 - *v11) / v12;
        v19[1] = 0.0;
        v19[0] = 0.0;
        v19[2] = 1.0;
        sub_5D8490(v19, v11 + 4, v10 + 4, v15);
        sub_5D7630(v19, (int)(v8 + 19));
        v8[31] = (v10[1] - v11[1]) * v15 + v11[1];
        v8[32] = (v10[2] - v11[2]) * v15 + v11[2];
        v8[33] = (v10[3] - v11[3]) * v15 + v11[3];
      }
      v13 = ++v18 < this[5];
      v17 += 180;
    }
    while ( v13 );
  }
  result = a2;
  *this |= 0x1000u;
  if ( a2 )
  {
    result = (_DWORD *)a2[98];
    *result |= 0x40u;
  }
  return result;
}
