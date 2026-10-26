void __thiscall sub_530780(int this, int a2, char *String1, float a4)
{
  int v5; // ebx
  int v6; // edi
  int v7; // esi
  int v8; // eax
  double v9; // st7
  int v10; // edi
  int v11; // esi
  int v12; // eax
  double v13; // st7
  double v14; // st6
  double v15; // st7
  _DWORD *v16; // eax
  char *v17; // eax
  float v18; // [esp+10h] [ebp-18h]
  float v19; // [esp+14h] [ebp-14h]
  float v20; // [esp+18h] [ebp-10h]
  float v21; // [esp+18h] [ebp-10h]
  float v22; // [esp+1Ch] [ebp-Ch]
  float v23; // [esp+20h] [ebp-8h]
  float v24; // [esp+34h] [ebp+Ch]

  *(_DWORD *)(this + 844) = 1142292480;
  v5 = dword_757C10;
  v6 = 0;
  v18 = 99999.898;
  v22 = 0.0;
  v19 = 0.0;
  v23 = 10.0;
  if ( dword_757C10 <= 0 )
    goto LABEL_37;
  do
  {
    v7 = *(&dword_91E088 + v6);
    v8 = sub_539670((char *)(v7 + 22084));
    if ( v8 )
      v9 = *(float *)(v8 + 2700);
    else
      v9 = 1.0;
    v20 = *(float *)(v7 + 19436) / v9;
    if ( v20 > 1.0 && v20 < (double)v18 && *(_DWORD *)(v7 + 14820) == 1 )
    {
      v18 = *(float *)(v7 + 19436) / v9;
      if ( *(_DWORD *)(this + 864) == 6 )
        v22 = *(float *)(v7 + 20656);
      else
        v22 = *(float *)(v7 + 20652);
    }
    ++v6;
  }
  while ( v6 < v5 );
  if ( v18 >= 9000.0 )
    goto LABEL_37;
  v10 = 0;
  do
  {
    v11 = *(&dword_91E088 + v10);
    v12 = sub_539670((char *)(v11 + 22084));
    if ( v12 )
      v13 = *(float *)(v12 + 2700);
    else
      v13 = 1.0;
    v21 = *(float *)(v11 + 19436) / v13;
    if ( v21 > 0.0 && v21 > (double)v19 && v18 * 1.15 > v21 && *(_DWORD *)(v11 + 14820) == 1 )
    {
      v19 = *(float *)(v11 + 19436) / v13;
      if ( *(_DWORD *)(this + 864) == 6 )
        v23 = *(float *)(v11 + 20656);
      else
        v23 = *(float *)(v11 + 20652);
    }
    ++v10;
  }
  while ( v10 < v5 );
  if ( v19 <= 1.0 || v18 == v19 )
  {
LABEL_37:
    if ( String1 && sub_53A250(String1) )
    {
      v16 = (_DWORD *)(a2 < 2 || a2 > 4 ? sub_616630(off_9034EC) : sub_616630(off_9034E8[0]));
      if ( v16 )
      {
        v17 = sub_48D380(v16);
        *(float *)(this + 844) = atof(v17);
      }
    }
    *(float *)(this + 840) = a4;
    *(_BYTE *)(this + 834) = 1;
    *(float *)(this + 844) = (1.0 - a4) * (*(float *)(this + 844) * 0.30000001) + *(float *)(this + 844);
  }
  else
  {
    v14 = v22 - v23;
    if ( v14 < 0.0099999998 )
      v14 = 0.0099999998;
    *(_BYTE *)(this + 834) = 1;
    v15 = v18 - (v19 - v18) / v14 * (1.0 - v22);
    *(float *)(this + 844) = v15;
    v24 = v18 * 0.97000003;
    if ( v15 < v24 )
      *(float *)(this + 844) = v24;
  }
}
