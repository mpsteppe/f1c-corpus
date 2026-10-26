int __thiscall sub_4F3C10(_DWORD *this)
{
  _DWORD *v1; // esi
  int result; // eax
  int v3; // ebp
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // ebx
  int i; // edi
  float *v9; // eax
  int v11; // [esp+Ch] [ebp-4Ch]
  float v12; // [esp+10h] [ebp-48h] BYREF
  float v13; // [esp+14h] [ebp-44h] BYREF
  float v14; // [esp+18h] [ebp-40h] BYREF
  float v15; // [esp+1Ch] [ebp-3Ch]
  float v16; // [esp+20h] [ebp-38h]
  float v17; // [esp+24h] [ebp-34h]
  float v18; // [esp+28h] [ebp-30h]
  float v19; // [esp+2Ch] [ebp-2Ch]
  float v20; // [esp+30h] [ebp-28h]
  float v21; // [esp+34h] [ebp-24h]
  float v22; // [esp+38h] [ebp-20h]
  float v23; // [esp+3Ch] [ebp-1Ch]
  float v24[6]; // [esp+40h] [ebp-18h] BYREF

  v1 = this;
  sub_56C0A0(v24);
  v15 = v24[0] + v24[3];
  v18 = v15;
  v16 = v24[4] + v24[1];
  v19 = v16;
  v17 = v24[2] + v24[5];
  v20 = v17;
  v21 = v15 * 0.5;
  v15 = v21;
  v22 = v16 * 0.5;
  v16 = v22;
  v23 = v17 * 0.5;
  v17 = v23;
  sub_5DA7A0(&v12, &v13, &v14);
  v12 = v15 + v12;
  v13 = v16 + v13;
  v14 = v17 + v14;
  sub_5DB150(LODWORD(v12), LODWORD(v13), LODWORD(v14));
  result = *(_DWORD *)(v1[34] + 544);
  v3 = 0;
  v11 = result;
  if ( result > 0 )
  {
    while ( 1 )
    {
      v4 = v3;
      if ( v3 < 0 || v3 >= *(_DWORD *)(v1[34] + 544) )
        goto LABEL_10;
      v5 = *(_DWORD *)(v1[34] + 532);
      if ( v3 > 0 )
        break;
LABEL_9:
      if ( !v5 )
        goto LABEL_10;
      v6 = *(_DWORD **)v5;
LABEL_12:
      v7 = sub_5EA5B0(v6);
      for ( i = 0; i < v7; v9[2] = v9[2] - v18 )
      {
        v9 = (float *)sub_5EB140(i++, 1);
        *v9 = *v9 - v16;
        v9[1] = v9[1] - v17;
      }
      *v6 &= ~0x800u;
      sub_5EA6C0(1);
      sub_5EAF10(v6);
      result = v11;
      if ( ++v3 >= v11 )
        return result;
      v1 = this;
    }
    while ( v5 )
    {
      v5 = *(_DWORD *)(v5 + 4);
      if ( --v4 <= 0 )
        goto LABEL_9;
    }
LABEL_10:
    v6 = 0;
    goto LABEL_12;
  }
  return result;
}
