int __thiscall sub_5A3350(int this, unsigned __int8 a2, int a3, int a4, int a5, __int16 a6)
{
  int v7; // edx
  int v8; // edi
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // st4
  int v17; // eax
  double v18; // st3
  double v19; // st3
  float *v20; // ebx
  float *v21; // ebp
  float *v22; // ebx
  float *v23; // ebp
  float *v24; // ebx
  int v25; // eax
  int v26; // eax
  __int64 v27; // rax
  bool v28; // zf
  int v30; // [esp+8h] [ebp-10h]
  float v31; // [esp+1Ch] [ebp+4h]
  int v32; // [esp+1Ch] [ebp+4h]
  float v33; // [esp+20h] [ebp+8h]
  float v34; // [esp+24h] [ebp+Ch]
  float v35; // [esp+28h] [ebp+10h]

  if ( a2 < 0x20u || a2 >= *(int *)(this + 140) )
  {
    LODWORD(v27) = 0;
  }
  else
  {
    v7 = *(_DWORD *)(this + 100);
    v8 = 16 * a2;
    v9 = *(__int16 *)(v8 + this - 328);
    v10 = v8 + this - 328;
    if ( (v7 & 0x100000) != 0 )
    {
      v11 = *(unsigned __int8 *)(v10 + 4);
      v12 = *(unsigned __int8 *)(v10 + 5);
    }
    else
    {
      v11 = *(_DWORD *)(this + 116) - 1;
      v12 = *(_DWORD *)(this + 120) - 1;
    }
    v30 = v11;
    if ( (v7 & 0x10000) != 0 )
    {
      sub_59FDC0(
        *(void **)(this + 180),
        v9,
        *(__int16 *)(v10 + 2) + 1,
        a5,
        a3,
        a4,
        v11,
        v12 - 1,
        *(_DWORD *)(this + 108),
        0);
    }
    else
    {
      v13 = (double)a3;
      if ( (a6 & 0x2000) != 0 )
      {
        v14 = (double)a4;
      }
      else
      {
        v13 = v13 * *(float *)(this + 172) + 0.5;
        v14 = (double)a4 * *(float *)(this + 176) + 0.5;
      }
      if ( (a6 & 0x4000) != 0 )
      {
        v15 = (double)(a3 + v11);
        v16 = (double)(a4 + v12);
      }
      else
      {
        v15 = (double)v11 * *(float *)(this + 172) + v13 + 0.5;
        v16 = (double)v12 * *(float *)(this + 176) + v14 + 0.5;
      }
      v17 = *(_DWORD *)(this + 180);
      v18 = (double)*(int *)(v17 + 28);
      v31 = (double)v9 / v18;
      v35 = (float)*(int *)(v17 + 32);
      v33 = (double)*(__int16 *)(v10 + 2) / v35;
      v34 = (double)v30 / v18 + v31;
      v19 = (double)v12 / v35 + v33;
      **(float **)(this + 20) = v13;
      *(float *)(*(_DWORD *)(this + 20) + 4) = v14;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 16) = *(_DWORD *)(this + 152);
      *(float *)(*(_DWORD *)(this + 20) + 20) = v31;
      *(float *)(*(_DWORD *)(this + 20) + 24) = v33;
      v20 = (float *)(*(_DWORD *)(this + 20) + 28);
      *(_DWORD *)(this + 20) = v20;
      *v20 = v13;
      *(float *)(*(_DWORD *)(this + 20) + 4) = v16;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 16) = *(_DWORD *)(this + 152);
      *(float *)(*(_DWORD *)(this + 20) + 20) = v31;
      *(float *)(*(_DWORD *)(this + 20) + 24) = v19;
      v21 = (float *)(*(_DWORD *)(this + 20) + 28);
      *(_DWORD *)(this + 20) = v21;
      *v21 = v15;
      *(float *)(*(_DWORD *)(this + 20) + 4) = v16;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 16) = *(_DWORD *)(this + 152);
      *(float *)(*(_DWORD *)(this + 20) + 20) = v34;
      *(float *)(*(_DWORD *)(this + 20) + 24) = v19;
      v22 = (float *)(*(_DWORD *)(this + 20) + 28);
      *(_DWORD *)(this + 20) = v22;
      *v22 = v15;
      *(float *)(*(_DWORD *)(this + 20) + 4) = v16;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 16) = *(_DWORD *)(this + 152);
      *(float *)(*(_DWORD *)(this + 20) + 20) = v34;
      *(float *)(*(_DWORD *)(this + 20) + 24) = v19;
      v23 = (float *)(*(_DWORD *)(this + 20) + 28);
      *(_DWORD *)(this + 20) = v23;
      *v23 = v15;
      *(float *)(*(_DWORD *)(this + 20) + 4) = v14;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 16) = *(_DWORD *)(this + 152);
      *(float *)(*(_DWORD *)(this + 20) + 20) = v34;
      *(float *)(*(_DWORD *)(this + 20) + 24) = v33;
      v24 = (float *)(*(_DWORD *)(this + 20) + 28);
      *(_DWORD *)(this + 20) = v24;
      *v24 = v13;
      *(float *)(*(_DWORD *)(this + 20) + 4) = v14;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 20) + 16) = *(_DWORD *)(this + 152);
      *(float *)(*(_DWORD *)(this + 20) + 20) = v31;
      *(float *)(*(_DWORD *)(this + 20) + 24) = v33;
      v25 = *(_DWORD *)(this + 12);
      *(_DWORD *)(this + 20) += 28;
      *(_DWORD *)(this + 12) = v25 + 6;
      *(_DWORD *)(this + 148) = *(char *)(v10 + 7);
    }
    v26 = *(_DWORD *)(this + 100);
    if ( (a6 & 0x2000) != 0 )
    {
      if ( (v26 & 0x100000) != 0 )
        v32 = *(char *)(v10 + 7) + *(unsigned __int8 *)(v10 + 4) + 1;
      else
        v32 = *(unsigned __int8 *)(v10 + 4);
      return (__int64)((double)v32 * *(float *)(this + 172) + 0.5);
    }
    else
    {
      v28 = (v26 & 0x100000) == 0;
      LODWORD(v27) = *(unsigned __int8 *)(v10 + 4);
      if ( !v28 )
        LODWORD(v27) = *(char *)(v10 + 7) + (_DWORD)v27 + 1;
    }
  }
  return v27;
}
