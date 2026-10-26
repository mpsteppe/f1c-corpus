void __thiscall sub_5613E0(void *this)
{
  int v2; // ebp
  bool v3; // zf
  int v4; // eax
  int v5; // edx
  int v6; // eax
  double *v7; // ecx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int *v12; // eax
  int v13; // ebx
  int i; // edi
  int v15; // eax
  double v16; // st7
  int v17; // [esp+8h] [ebp-28h]
  float v18; // [esp+Ch] [ebp-24h]
  float v19; // [esp+10h] [ebp-20h]
  float v20; // [esp+14h] [ebp-1Ch]
  float v21; // [esp+18h] [ebp-18h]
  float v22; // [esp+1Ch] [ebp-14h]
  float v23; // [esp+20h] [ebp-10h]
  float v24[3]; // [esp+24h] [ebp-Ch] BYREF

  v2 = **((_DWORD **)this + 3);
  v3 = (*((_BYTE *)this + 36) & 4) == 0;
  *((_DWORD *)this + 1) = 0;
  if ( v3 )
  {
    v4 = *((_DWORD *)this + 6);
    v5 = *(_DWORD *)(v4 + 312);
    if ( (*(_BYTE *)(v5 + 60) & 2) == 0 )
    {
      if ( (*(_DWORD *)(v4 + 20) & 0x20000000) == 0 )
      {
        (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_8B8F24 + 4))(
          dword_8B8F24,
          v4 + 220,
          v4 + 232,
          v5 + 276);
        *(_DWORD *)(*((_DWORD *)this + 6) + 20) |= 0x20000000u;
      }
      sub_5414C0(dword_8B78A0);
      v6 = sub_541470(dword_8B78A0);
      v7 = (double *)*((_DWORD *)this + 7);
      *((_DWORD *)this + 2) = v6;
      if ( *(float *)this > sub_5565B0(v7) )
      {
        v10 = *((_DWORD *)this + 3);
        v19 = *(float *)(v10 + 20);
        v18 = *(float *)(v10 + 12);
        v11 = 0;
        v17 = 0;
        v20 = 1.0 / (double)*(int *)(v10 + 84);
        v23 = 1.0 / (double)*(int *)(v10 + 88);
        v21 = -*(float *)(v10 + 16);
        v22 = *(float *)(v10 + 24);
        v12 = (int *)*((_DWORD *)this + 8);
        if ( *v12 > 0 )
        {
          do
          {
            v13 = *(_DWORD *)(v12[1] + 4 * v11);
            for ( i = 0; i < 3; ++i )
            {
              v15 = *(_DWORD *)(*(_DWORD *)(v13 + 8) + 12) + 48 * *(unsigned __int16 *)(v13 + 2 * i);
              **((float **)this + 2) = *(float *)(v15 + 12) * 0.050000001 + *(float *)v15;
              *(float *)(*((_DWORD *)this + 2) + 4) = *(float *)(v15 + 16) * 0.050000001 + *(float *)(v15 + 4);
              *(float *)(*((_DWORD *)this + 2) + 8) = *(float *)(v15 + 20) * 0.050000001 + *(float *)(v15 + 8);
              *(_DWORD *)(*((_DWORD *)this + 2) + 12) = *(_DWORD *)(v15 + 24);
              (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
                dword_8B8F24,
                v15,
                v24,
                *((_DWORD *)this + 3) + 348);
              v16 = 1.0 / v24[2];
              *(float *)(*((_DWORD *)this + 2) + 16) = (v24[0] * v16 * v18 + v19) * v20;
              *(float *)(*((_DWORD *)this + 2) + 20) = (v24[1] * v16 * v21 + v22) * v23;
              *((_DWORD *)this + 2) += 24;
            }
            v12 = (int *)*((_DWORD *)this + 8);
            *((_DWORD *)this + 1) += 3;
            v11 = ++v17;
          }
          while ( v17 < *v12 );
        }
      }
      else
      {
        sub_556440(*((int **)this + 7));
        **((_DWORD **)this + 8) = 0;
        v8 = 0;
        if ( *(int *)(v2 + 316) > 0 )
        {
          v9 = 0;
          do
          {
            sub_561620(*(_DWORD *)(v9 + *(_DWORD *)(v2 + 320) + 16));
            ++v8;
            v9 += 24;
          }
          while ( v8 < *(_DWORD *)(v2 + 316) );
          sub_5414A0(dword_8B78A0);
          return;
        }
      }
      sub_5414A0(dword_8B78A0);
    }
  }
}
