int __thiscall sub_50AB51(int this, unsigned int a2, unsigned int a3, int a4)
{
  int result; // eax
  unsigned int v6; // eax
  float *v7; // edx
  _WORD *v8; // ebx
  unsigned __int16 v9; // ax
  double v10; // st4
  _WORD *v11; // ebx
  unsigned __int16 v12; // ax
  double v13; // st4
  double v14; // st3
  double v15; // st3
  double v16; // st2
  double v17; // st2
  double v18; // st1
  double v19; // st1
  double v20; // st2
  double v21; // st2
  double v22; // st2
  double v23; // st4
  double v24; // st4
  double v25; // st4
  float v26; // [esp+4h] [ebp-Ch]
  float v27; // [esp+8h] [ebp-8h]
  float v28; // [esp+8h] [ebp-8h]
  float v29; // [esp+Ch] [ebp-4h]
  float v30; // [esp+Ch] [ebp-4h]
  _WORD *v31; // [esp+18h] [ebp+8h]
  float v32; // [esp+18h] [ebp+8h]
  float v33; // [esp+18h] [ebp+8h]
  float v34; // [esp+18h] [ebp+8h]
  float v35; // [esp+18h] [ebp+8h]
  int v36; // [esp+1Ch] [ebp+Ch]
  float v37; // [esp+1Ch] [ebp+Ch]
  float v38; // [esp+1Ch] [ebp+Ch]
  float v39; // [esp+1Ch] [ebp+Ch]
  unsigned int i; // [esp+20h] [ebp+10h]

  if ( !*(_DWORD *)(this + 4240) )
    return -2147024882;
  if ( a2 < *(_DWORD *)(this + 4212)
    || a2 >= *(_DWORD *)(this + 4220)
    || a3 < *(_DWORD *)(this + 4224)
    || a3 >= *(_DWORD *)(this + 4228) )
  {
    result = sub_50A92D((_DWORD *)this);
    if ( result < 0 )
      return result;
    *(_DWORD *)(this + 4220) = a2 + 1;
    *(_DWORD *)(this + 4212) = a2;
    *(_DWORD *)(this + 4224) = a3;
    *(_DWORD *)(this + 4228) = a3 + 1;
    if ( a4 )
    {
      v6 = *(_DWORD *)(this + 4208);
      v7 = *(float **)(this + 4204);
      v8 = (_WORD *)(*(_DWORD *)(this + 24) + a3 * *(_DWORD *)(this + 4180) + a2 * *(_DWORD *)(this + 4176) + 2 * v6);
      v31 = v8;
      for ( i = v6; i < *(_DWORD *)(this + 4216); v31 = v8 )
      {
        v9 = *v8;
        v10 = (double)(unsigned __int8)(*v8 >> *(_WORD *)(this + 4244));
        v11 = v31;
        v36 = (unsigned __int8)(v9 >> *(_WORD *)(this + 4248));
        v12 = v31[1];
        v27 = v10 - 16.0;
        v29 = (double)v36 - 128.0;
        v13 = (double)(unsigned __int8)(v12 >> *(_WORD *)(this + 4244)) - 16.0;
        v14 = (double)(unsigned __int8)(v12 >> *(_WORD *)(this + 4248)) - 128.0;
        v37 = v14;
        v15 = v14 * 0.0062589301;
        v16 = v27 * 0.0045662099;
        v32 = v16;
        v17 = v16 + v15;
        *v7 = v17;
        v28 = v29 * 0.00153632;
        v18 = v37 * 0.00318811;
        v26 = v18;
        v38 = v32 - v28 - v18;
        v7[1] = v38;
        v19 = v29 * 0.0079107098;
        v33 = v19 + v32;
        v7[2] = v33;
        v7[3] = 1.0;
        if ( v17 >= 0.0 )
        {
          if ( v17 > 1.0 )
            v17 = 1.0;
        }
        else
        {
          v17 = 0.0;
        }
        *v7 = v17;
        if ( v38 >= 0.0 )
        {
          if ( v38 <= 1.0 )
            v20 = v38;
          else
            v20 = 1.0;
        }
        else
        {
          v20 = 0.0;
        }
        v7[1] = v20;
        if ( v33 >= 0.0 )
        {
          if ( v33 <= 1.0 )
            v21 = v33;
          else
            v21 = 1.0;
        }
        else
        {
          v21 = 0.0;
        }
        v7[2] = v21;
        v34 = v13 * 0.0045662099;
        v22 = v13 * 0.0045662099 + v15;
        v23 = v22;
        v7[4] = v22;
        v39 = v34 - v28 - v26;
        v7[5] = v39;
        v30 = v19;
        v35 = v34 + v30;
        v7[6] = v35;
        v7[7] = 1.0;
        if ( v22 >= 0.0 )
        {
          if ( v22 > 1.0 )
            v23 = 1.0;
        }
        else
        {
          v23 = 0.0;
        }
        v7[4] = v23;
        if ( v39 >= 0.0 )
        {
          if ( v39 <= 1.0 )
            v24 = v39;
          else
            v24 = 1.0;
        }
        else
        {
          v24 = 0.0;
        }
        v7[5] = v24;
        if ( v35 >= 0.0 )
        {
          if ( v35 <= 1.0 )
            v25 = v35;
          else
            v25 = 1.0;
        }
        else
        {
          v25 = 0.0;
        }
        i += 2;
        v7[6] = v25;
        v8 = v11 + 2;
        v7 += 8;
      }
    }
  }
  return 0;
}
