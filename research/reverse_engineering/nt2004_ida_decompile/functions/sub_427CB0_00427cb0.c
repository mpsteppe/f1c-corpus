char __thiscall sub_427CB0(int this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  int v4; // ebp
  int v5; // eax
  char *v6; // edi
  int v7; // edx
  float v8; // eax
  double v9; // st6
  double v10; // st4
  double v11; // st5
  int v12; // ecx
  float *v13; // edx
  int v14; // eax
  char *v15; // edi
  int v16; // edx
  float v17; // eax
  double v18; // st6
  double v19; // st4
  double v20; // st5
  int v21; // ecx
  float *v22; // edx
  int v23; // ebx
  _DWORD *v24; // eax
  int v25; // edx
  int v26; // ebx
  _DWORD *v27; // eax
  int v28; // edx
  char result; // al
  int v30; // [esp+4h] [ebp-18h]
  int v31; // [esp+8h] [ebp-14h]
  int v32; // [esp+Ch] [ebp-10h] BYREF
  float v33; // [esp+10h] [ebp-Ch]
  int v34; // [esp+14h] [ebp-8h]
  float v35; // [esp+18h] [ebp-4h]

  v30 = 0;
  v2 = (_DWORD *)(this + 21256);
  v3 = 5;
  do
  {
    v2[22] = 1232348144;
    *v2 = 0;
    v2 += 32;
    --v3;
  }
  while ( v3 );
  v4 = -1;
  v31 = -1;
  sub_41F340(flt_62BC28, *(_DWORD *)(*(_DWORD *)(this + 80) + 25248));
  while ( !*(_DWORD *)(this + 21768) )
  {
    if ( v30 < 2 )
    {
      v5 = sub_41F360(flt_62BC28, &v32);
      v31 = v5;
      if ( v5 == v4 || v5 == -1 )
        break;
      if ( *(_DWORD *)(*(_DWORD *)(this + 80) + 25248) == v5 )
      {
        v4 = sub_41F3A0(flt_62BC28, &v32);
        continue;
      }
      v6 = (char *)&unk_62BF68 + 25304 * v5;
      v7 = *((_DWORD *)v6 + 4402);
      v8 = *((float *)v6 + 4403);
      v33 = *((float *)v6 + 4401);
      v35 = v8;
      v34 = v7;
      v9 = v8 - *(float *)(this + 17612);
      v10 = v33 - *(float *)(this + 17604);
      v11 = v9 * v9 + v10 * v10;
      if ( v11 < *(float *)(this + 21856) )
      {
        ++v30;
        v12 = 0;
        v13 = (float *)(this + 21344);
        while ( v11 >= *v13 )
        {
          ++v12;
          v13 += 32;
          if ( v12 >= 5 )
            goto LABEL_13;
        }
        v23 = (v12 << 7) + this;
        if ( *(float *)(v23 + 21344) < 999999.0 && v12 <= 3 )
        {
          v24 = (_DWORD *)(this + 21768);
          v25 = 4 - v12;
          do
          {
            *v24 = *(v24 - 32);
            v24[22] = *(v24 - 10);
            v24 -= 32;
            --v25;
          }
          while ( v25 );
        }
        *(float *)(v23 + 21344) = v11;
        *(_DWORD *)(v23 + 21256) = v6;
      }
    }
LABEL_13:
    v14 = sub_41F3A0(flt_62BC28, &v32);
    v4 = v14;
    if ( v31 == v14 || v14 == -1 )
      break;
    v15 = (char *)&unk_62BF68 + 25304 * v14;
    v16 = *((_DWORD *)v15 + 4402);
    v17 = *((float *)v15 + 4403);
    v33 = *((float *)v15 + 4401);
    v35 = v17;
    v34 = v16;
    v18 = v17 - *(float *)(this + 17612);
    v19 = v33 - *(float *)(this + 17604);
    v20 = v18 * v18 + v19 * v19;
    if ( v20 < *(float *)(this + 21856) )
    {
      v21 = 0;
      v22 = (float *)(this + 21344);
      while ( v20 >= *v22 )
      {
        ++v21;
        v22 += 32;
        if ( v21 >= 5 )
          goto LABEL_30;
      }
      v26 = (v21 << 7) + this;
      if ( *(float *)(v26 + 21344) < 999999.0 && v21 <= 3 )
      {
        v27 = (_DWORD *)(this + 21768);
        v28 = 4 - v21;
        do
        {
          *v27 = *(v27 - 32);
          v27[22] = *(v27 - 10);
          v27 -= 32;
          --v28;
        }
        while ( v28 );
      }
      *(float *)(v26 + 21344) = v20;
      *(_DWORD *)(v26 + 21256) = v15;
    }
LABEL_30:
    ;
  }
  result = *(_BYTE *)(this + 24280);
  if ( result )
    *(_BYTE *)(this + 24280) = 0;
  return result;
}
