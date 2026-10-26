void __thiscall sub_5B8D40(int this, int a2)
{
  _DWORD *v3; // edi
  int v4; // ebp
  float *v5; // ebx
  char v7; // c0
  float *v8; // edi
  int *v9; // eax
  int i; // ecx
  int v11; // eax
  _DWORD *v12; // [esp+10h] [ebp-14h]
  int v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+18h] [ebp-Ch]
  int v15; // [esp+20h] [ebp-4h]

  v13 = *(_DWORD *)(this + 28) + 232;
  v3 = *(_DWORD **)(a2 + 516);
  v12 = v3;
  if ( v3 )
  {
    while ( 1 )
    {
      if ( (v3[5] & 0x4000) != 0 )
      {
        if ( sub_59ED70(a2, *(float **)(this + 16), (int)v3) )
        {
          v4 = v3[73];
          v14 = 0;
          if ( (int)v3[72] > 0 )
          {
            v5 = (float *)(v4 + 20);
            do
            {
              if ( !v7 )
              {
                v8 = (float *)(v12[75] + 16 * *((_DWORD *)v5 - 2));
                v15 = *((_DWORD *)v5 - 3);
                if ( ((double (__thiscall *)(int, int, float *))*(_DWORD *)(*(_DWORD *)dword_7E8E58 + 32))(
                       dword_7E8E58,
                       v13,
                       v8) > v5[3]
                  && (v5[1] - *(float *)(*(_DWORD *)(this + 16) + 44)) * v8[2]
                   + (*v5 - *(float *)(*(_DWORD *)(this + 16) + 40)) * v8[1]
                   + (*(v5 - 1) - *(float *)(*(_DWORD *)(this + 16) + 36)) * *v8 > 0.0 )
                {
                  if ( *(int *)(this + 4) >= 1149 )
                    return;
                  v9 = *(int **)(this + 36);
                  if ( *v9 >= 383 )
                    return;
                  *(_DWORD *)(v9[1] + 4 * *v9) = v4;
                  ++**(_DWORD **)(this + 36);
                  for ( i = 0; i < 3; ++i )
                  {
                    v11 = *(_DWORD *)(v15 + 12) + 48 * *(unsigned __int16 *)(v4 + 2 * i);
                    **(float **)(this + 8) = *(float *)(v11 + 12) * 0.050000001 + *(float *)v11;
                    *(float *)(*(_DWORD *)(this + 8) + 4) = *(float *)(v11 + 16) * 0.050000001 + *(float *)(v11 + 4);
                    *(float *)(*(_DWORD *)(this + 8) + 8) = *(float *)(v11 + 20) * 0.050000001 + *(float *)(v11 + 8);
                    *(_DWORD *)(*(_DWORD *)(this + 8) + 12) = *(_DWORD *)(v11 + 24);
                    *(_DWORD *)(this + 8) += 16;
                  }
                  *(_DWORD *)(this + 4) += 3;
                }
                v3 = v12;
              }
              v4 += 36;
              v5 += 9;
              ++v14;
            }
            while ( v14 < v3[72] );
          }
        }
      }
      v12 = (_DWORD *)v3[4];
      if ( !v12 )
        break;
      v3 = (_DWORD *)v3[4];
    }
  }
}
