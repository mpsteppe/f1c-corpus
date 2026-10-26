void __stdcall sub_56FE00(int a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  int v5; // ebp
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // ebx
  int i; // edi
  float *v11; // eax
  int v12; // [esp+4h] [ebp-30h]
  int v13; // [esp+8h] [ebp-2Ch]
  int v14; // [esp+Ch] [ebp-28h]
  float v15; // [esp+10h] [ebp-24h] BYREF
  float v16; // [esp+14h] [ebp-20h] BYREF
  float v17; // [esp+18h] [ebp-1Ch] BYREF
  float v18; // [esp+1Ch] [ebp-18h]
  float v19; // [esp+20h] [ebp-14h]
  float v20; // [esp+24h] [ebp-10h]
  float v21; // [esp+28h] [ebp-Ch] BYREF
  float v22; // [esp+2Ch] [ebp-8h]
  float v23; // [esp+30h] [ebp-4h]

  v2 = a1;
  if ( a1 )
  {
    sub_56C0A0(a1, &v15, &v21);
    v3 = 0;
    v13 = 0;
    v18 = v21 + v15;
    v15 = v18;
    v19 = v16 + v22;
    v16 = v19;
    v20 = v23 + v17;
    v17 = v20;
    v21 = v18 * 0.5;
    v18 = v21;
    v22 = v19 * 0.5;
    v19 = v22;
    v23 = v20 * 0.5;
    v20 = v23;
    while ( 1 )
    {
      if ( v3 )
      {
        v12 = a2;
        v4 = a2;
      }
      else
      {
        v4 = v2;
        v12 = v2;
      }
      if ( v4 )
      {
        sub_5DA7A0(&v15, &v16, &v17);
        v15 = v18 + v15;
        v16 = v19 + v16;
        v17 = v20 + v17;
        sub_5DB150(LODWORD(v15), LODWORD(v16), LODWORD(v17));
        v5 = 0;
        v14 = *(_DWORD *)(v4 + 544);
        if ( v14 > 0 )
          break;
      }
LABEL_22:
      v13 = ++v3;
      if ( v3 >= 2 )
        return;
    }
    while ( 1 )
    {
      v6 = v5;
      if ( v5 < 0 || v5 >= *(_DWORD *)(v4 + 544) )
        goto LABEL_16;
      v7 = *(_DWORD *)(v4 + 532);
      if ( v5 > 0 )
        break;
LABEL_15:
      if ( !v7 )
        goto LABEL_16;
      v8 = *(_DWORD **)v7;
LABEL_18:
      v9 = sub_5EA5B0(v8);
      for ( i = 0; i < v9; v11[2] = v11[2] - v21 )
      {
        v11 = (float *)sub_5EB140(i++, 1);
        *v11 = *v11 - v19;
        v11[1] = v11[1] - v20;
      }
      *v8 &= ~0x800u;
      sub_5EA6C0(1);
      sub_5EAF10(v8);
      if ( ++v5 >= v14 )
      {
        v2 = a1;
        v3 = v13;
        goto LABEL_22;
      }
      v4 = v12;
    }
    while ( v7 )
    {
      v7 = *(_DWORD *)(v7 + 4);
      if ( --v6 <= 0 )
        goto LABEL_15;
    }
LABEL_16:
    v8 = 0;
    goto LABEL_18;
  }
}
