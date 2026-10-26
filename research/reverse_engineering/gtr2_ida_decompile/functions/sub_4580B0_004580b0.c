int __thiscall sub_4580B0(_DWORD *this, int a2)
{
  int *v3; // esi
  const char *v4; // eax
  int v5; // eax
  int v6; // eax
  double v7; // st7
  float *v8; // ecx
  double v10; // st6
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  int v13; // ecx
  int *v14; // eax
  int v15; // eax
  int v16; // eax
  int *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ebp
  int i; // esi
  int v22; // ecx
  int v23; // eax
  int result; // eax
  float v25; // [esp+Ch] [ebp-124h]
  void *Block[4]; // [esp+10h] [ebp-120h] BYREF
  char v27; // [esp+20h] [ebp-110h]
  _BYTE v28[256]; // [esp+24h] [ebp-10Ch] BYREF
  int v29; // [esp+12Ch] [ebp-4h]

  *this = a2;
  v3 = (int *)dword_BE1D0C;
  if ( dword_BE1D0C )
  {
    sub_40B430();
    v4 = (const char *)dword_91CA88;
    v29 = 0;
    if ( !dword_91CA88 )
      v4 = WindowName;
    sub_632041(v28, 256, "%sAmbient\\helicopter.wav", v4);
    sub_615860(v28);
    v5 = *v3;
    Block[2] = (void *)-1;
    Block[3] = (void *)-1;
    v27 = 0;
    v6 = (*(int (__thiscall **)(int *, void **, int, _DWORD))(v5 + 92))(v3, Block, 1, 0);
    this[1] = v6;
    if ( v6 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
      v7 = flt_B70C3C;
      v8 = (float *)this[1];
      v10 = 1.0;
      v25 = *(float *)&dword_B70C60;
      if ( !(v11 | v12) )
        v10 = 1.0 / flt_B70C18;
      v8[7] = v10;
      v8[8] = 1.0 - v10 * v25;
      v8[9] = v7;
    }
    v29 = -1;
    if ( Block[0] )
      j_j__free(Block[0]);
  }
  v13 = *this;
  if ( *(int *)(*this + 544) > 0 )
  {
    v14 = *(int **)(v13 + 532);
    if ( v14 )
    {
      v15 = *v14;
      if ( v15 )
      {
        v16 = *(_DWORD *)(v15 + 396);
        if ( v16 && *(int *)(v16 + 12) > 0 && (v17 = *(int **)v16) != 0 )
          v18 = *v17;
        else
          v18 = 0;
        this[3] = v18;
        if ( v18 )
        {
          v19 = *(_DWORD *)(v18 + 28);
          if ( v19 )
            this[2] = *(_DWORD *)(v19 + 24);
        }
        v20 = *(_DWORD *)(v13 + 544);
        for ( i = 0; i < v20; ++i )
        {
          v22 = i;
          if ( i >= 0 && i < *(_DWORD *)(*this + 544) )
          {
            v23 = *(_DWORD *)(*this + 532);
            if ( i > 0 )
            {
              do
              {
                if ( !v23 )
                  break;
                v23 = *(_DWORD *)(v23 + 4);
                --v22;
              }
              while ( v22 > 0 );
            }
          }
          sub_5F1500(this[3]);
        }
      }
    }
  }
  result = sub_5E9690("HELI", 0, 0);
  this[4] = result;
  if ( result )
    return sub_5E4790(result, 0);
  return result;
}
