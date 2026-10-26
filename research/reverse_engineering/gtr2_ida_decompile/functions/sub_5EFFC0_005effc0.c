int __thiscall sub_5EFFC0(int this, unsigned __int8 a2, int a3, int a4, _DWORD *a5, char a6)
{
  int v7; // ebx
  int v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // ebp
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st4
  float *v16; // ebx
  float *v17; // ebp
  float *v18; // ebx
  float *v19; // ebp
  float *v20; // ebx
  int v21; // eax
  __int64 v22; // rax

  if ( a2 < 0x20u || a2 >= *(int *)(this + 124) )
  {
    LODWORD(v22) = 0;
  }
  else
  {
    v7 = *(__int16 *)(this + 24 * a2 - 584);
    v8 = this + 24 * a2 - 584;
    v9 = *(_DWORD *)(this + 16);
    if ( (v9 & 2) != 0 )
    {
      v10 = *(unsigned __int8 *)(v8 + 4);
      v11 = *(unsigned __int8 *)(v8 + 5);
    }
    else
    {
      v10 = *(_DWORD *)(this + 100);
      v11 = *(_DWORD *)(this + 104);
    }
    if ( (v9 & 1) != 0 )
    {
      v12 = (double)a3 + 0.5;
      if ( (a6 & 0x40) != 0 )
      {
        v13 = (double)a4 + 0.5;
      }
      else
      {
        v12 = v12 * *(float *)(this + 152);
        v13 = ((double)a4 + 0.5) * *(float *)(this + 156);
      }
      if ( a6 >= 0 )
      {
        v14 = (double)v10 * *(float *)(this + 152) + v12;
        v15 = (double)v11 * *(float *)(this + 156) + v13;
      }
      else
      {
        v14 = (double)(a3 + v10) + 0.5;
        v15 = (double)(a4 + v11) + 0.5;
      }
      **(float **)(this + 168) = v12;
      *(float *)(*(_DWORD *)(this + 168) + 4) = v13;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 16) = *(_DWORD *)(this + 84);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 20) = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 24) = *(_DWORD *)(v8 + 12);
      v16 = (float *)(*(_DWORD *)(this + 168) + 28);
      *(_DWORD *)(this + 168) = v16;
      *v16 = v12;
      *(float *)(*(_DWORD *)(this + 168) + 4) = v15;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 16) = *(_DWORD *)(this + 84);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 20) = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 24) = *(_DWORD *)(v8 + 20);
      v17 = (float *)(*(_DWORD *)(this + 168) + 28);
      *(_DWORD *)(this + 168) = v17;
      *v17 = v14;
      *(float *)(*(_DWORD *)(this + 168) + 4) = v15;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 16) = *(_DWORD *)(this + 84);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 20) = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 24) = *(_DWORD *)(v8 + 20);
      v18 = (float *)(*(_DWORD *)(this + 168) + 28);
      *(_DWORD *)(this + 168) = v18;
      *v18 = v14;
      *(float *)(*(_DWORD *)(this + 168) + 4) = v15;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 16) = *(_DWORD *)(this + 84);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 20) = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 24) = *(_DWORD *)(v8 + 20);
      v19 = (float *)(*(_DWORD *)(this + 168) + 28);
      *(_DWORD *)(this + 168) = v19;
      *v19 = v14;
      *(float *)(*(_DWORD *)(this + 168) + 4) = v13;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 16) = *(_DWORD *)(this + 84);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 20) = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 24) = *(_DWORD *)(v8 + 12);
      v20 = (float *)(*(_DWORD *)(this + 168) + 28);
      *(_DWORD *)(this + 168) = v20;
      *v20 = v12;
      *(float *)(*(_DWORD *)(this + 168) + 4) = v13;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 8) = 0;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 12) = 1065353216;
      *(_DWORD *)(*(_DWORD *)(this + 168) + 16) = *(_DWORD *)(this + 84);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 20) = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(*(_DWORD *)(this + 168) + 24) = *(_DWORD *)(v8 + 12);
      v21 = *(_DWORD *)(this + 160);
      *(_DWORD *)(this + 168) += 28;
      *(_DWORD *)(this + 160) = v21 + 6;
      *(_DWORD *)(this + 132) = *(char *)(v8 + 7);
    }
    else
    {
      sub_5E7540(
        *(_DWORD **)(this + 172),
        v7,
        *(__int16 *)(v8 + 2) + 1,
        a5,
        a3,
        a4,
        v10,
        v11 - 1,
        *(_DWORD *)(this + 92),
        0,
        0);
    }
    if ( (a6 & 0x40) != 0 )
    {
      if ( (*(_BYTE *)(this + 16) & 2) != 0 )
        return (unsigned __int64)((double)(*(char *)(v8 + 7) + *(unsigned __int8 *)(v8 + 4) + 1)
                                * *(float *)(this + 152)
                                + 0.5);
      else
        return (unsigned __int64)((double)*(unsigned __int8 *)(v8 + 4) * *(float *)(this + 152) + 0.5);
    }
    else
    {
      LODWORD(v22) = *(unsigned __int8 *)(v8 + 4);
    }
  }
  return v22;
}
