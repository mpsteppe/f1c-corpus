char __thiscall sub_528C70(int this, float a2, int a3, float a4, char a5)
{
  int v6; // edi
  int i; // ecx
  double v8; // st7
  int j; // edi
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  double v14; // st7
  double v15; // st6
  int v16; // edi
  double v17; // st5
  int v18; // ebp
  int v19; // ebx
  double v20; // st7
  double v21; // st6
  long double v22; // st7
  int v23; // eax
  float *v24; // ecx
  int v25; // eax
  int v26; // eax
  float v28; // [esp+8h] [ebp-374h]
  float v29; // [esp+8h] [ebp-374h]
  float v30; // [esp+8h] [ebp-374h]
  float v31; // [esp+Ch] [ebp-370h]
  float v32; // [esp+14h] [ebp-368h]
  float v33; // [esp+18h] [ebp-364h]
  float v34; // [esp+18h] [ebp-364h]
  float v35; // [esp+1Ch] [ebp-360h]
  int v36[3]; // [esp+20h] [ebp-35Ch] BYREF
  int v37[212]; // [esp+2Ch] [ebp-350h] BYREF

  if ( !*(_BYTE *)(this + 2892940) )
  {
    if ( a3 )
      sub_526700();
    v28 = sub_617F80(this + 2892312);
    if ( a5 || v28 > 0.025 && fabs(a4 - *(float *)(this + 2892392)) > 0.001 )
    {
      sub_617E70(this + 2892312);
      v6 = *(_DWORD *)(this + 2892916) != 0 ? 1 : 105;
      for ( i = sub_42DA10(&unk_920488); i < v6; i = sub_42DA60(&unk_920488) )
      {
        v8 = v28 + *(float *)(this + 4 * i + 2892396);
        *(float *)(this + 4 * i + 2892396) = v8;
        if ( a5 || v8 > *(float *)(this + 2892944) )
        {
          *(_DWORD *)(this + 4 * i + 2892396) = 0;
          sub_53EC40((int)v37, a4);
          sub_528960((int *)this, (int)v37, SLODWORD(a4));
        }
      }
      for ( j = *(_DWORD *)(this + 2892308); j < 105; j += 12 )
        sub_5253A0((_DWORD *)this, a5, SLODWORD(a4), j);
      *(_DWORD *)(this + 2892308) = (*(_DWORD *)(this + 2892308) + 1) % 12;
    }
    v10 = *(_DWORD *)(this + 2892916);
    *(float *)(this + 2892392) = a4;
    if ( !v10 && a2 != 0.0 && (int)*(_DWORD *)LODWORD(a2) > 0 )
    {
      sub_51A340((_DWORD *)LODWORD(a2));
      while ( sub_51BFE0((_DWORD *)LODWORD(a2), v37) )
      {
        switch ( (unsigned int)v37[0] >> 29 )
        {
          case 1u:
            v11 = ((unsigned int)v37[0] >> 18) & 0x3F;
            if ( v11 && v11 != 7 )
              goto LABEL_22;
            break;
          case 2u:
          case 3u:
          case 4u:
          case 6u:
LABEL_22:
            sub_528960((int *)this, (int)v37, SLODWORD(a4));
            break;
          default:
            break;
        }
      }
    }
    v12 = *(_DWORD *)(this + 2890596);
    if ( v12 != -1 )
    {
      v13 = *(_DWORD *)(this + 2890588) + 184 * v12;
      if ( v13 )
      {
        if ( *(float *)(this + 2892944) + *(float *)(v13 + 116) <= a4 )
          sub_527E30((int *)this, a4);
      }
    }
    if ( *(_DWORD *)(this + 2892916) == 1 )
    {
      v14 = *(float *)(dword_91E084 + 16020);
      v15 = *(float *)(dword_91E084 + 16016);
      v16 = *(_DWORD *)(dword_91E084 + 15988);
      v17 = *(float *)(dword_91E084 + 16012);
      v18 = *(_DWORD *)(dword_91E084 + 15992);
      v19 = *(_DWORD *)(dword_91E084 + 15996);
      v36[0] = v16;
      v36[1] = v18;
      v36[2] = v19;
      if ( 0.0 == sqrt(v17 * v17 + v15 * v15 + v14 * v14) )
      {
        v29 = *(float *)(dword_91E084 + 16004);
      }
      else
      {
        v20 = 0.0;
        v31 = *(float *)(dword_91E084 + 16012);
        v32 = *(float *)(dword_91E084 + 16020);
        v21 = v31 * v31 + v32 * v32;
        if ( v21 > 0.0 )
        {
          v33 = v21;
          v22 = 1.0 / sqrt(v33);
          v30 = v22;
          v31 = v22 * v31;
          v20 = v30 * 0.0;
          v32 = v30 * v32;
        }
        if ( fabs(v31 * v31 + v32 * v32 + v20 * v20) > 0.00000011920929 )
          v29 = atan2(-v31, -v32);
        else
          v29 = *(float *)(dword_91E084 + 16004);
      }
      v34 = *(float *)(dword_91E084 + 16148);
      v35 = *(float *)(dword_91E084 + 16156);
      if ( a5
        || (v23 = *(_DWORD *)(this + 2892928)) == 0
        || (v23 < 2 ? (v24 = 0) : (v24 = (float *)(*(_DWORD *)(this + 2892936) + 8 * (3 * v23 - 6))),
            sub_5217F0((float *)(*(_DWORD *)(this + 2892936) + 24 * v23 - 24), (float *)v36, v29, v35, v34, v24)) )
      {
        v25 = *(_DWORD *)(this + 2892928);
        if ( v25 < *(_DWORD *)(this + 2892932) )
        {
          v26 = *(_DWORD *)(this + 2892936) + 24 * v25;
          *(_DWORD *)v26 = v16;
          *(_DWORD *)(v26 + 4) = v18;
          *(float *)(v26 + 12) = v29;
          *(_DWORD *)(v26 + 8) = v19;
          *(float *)(v26 + 16) = v35;
          *(float *)(v26 + 20) = v34;
          ++*(_DWORD *)(this + 2892928);
        }
      }
      sub_521770((_DWORD *)(this + 2892996));
    }
  }
  return 0;
}
