int __thiscall sub_4DFB90(_DWORD *this)
{
  int v1; // esi
  _DWORD *v3; // ebx
  int result; // eax
  int v5; // eax
  double v6; // st7
  int v7; // ebx
  int v8; // ebp
  int v9; // esi
  int v10; // eax
  int v11; // [esp+58h] [ebp-30h]
  int v12; // [esp+5Ch] [ebp-2Ch]
  int v13; // [esp+5Ch] [ebp-2Ch]
  float v14; // [esp+60h] [ebp-28h]
  int v15; // [esp+64h] [ebp-24h]
  int v16; // [esp+64h] [ebp-24h]
  int v17; // [esp+68h] [ebp-20h]
  int v18; // [esp+6Ch] [ebp-1Ch]
  int v19; // [esp+70h] [ebp-18h]
  int v20; // [esp+74h] [ebp-14h]
  int v21; // [esp+78h] [ebp-10h]
  int v22; // [esp+80h] [ebp-8h]

  v1 = 0;
  v12 = 2;
  v11 = 0;
  v20 = sub_4DDFE0();
  v3 = this + 127;
  v15 = 4;
  do
  {
    if ( (unsigned __int8)sub_4E2610(v3) )
    {
      sub_539FE0(v3);
      sub_4DF1D0();
      ++v1;
      ++v11;
    }
    v3 += 3;
    --v15;
  }
  while ( v15 );
  result = v11;
  if ( v11 > 0 )
  {
    if ( v1 + 8 <= 600 )
    {
      v5 = 2;
    }
    else
    {
      v5 = 594 - v1;
      v12 = 594 - v1;
    }
    v16 = v5 + 3;
    v6 = (double)*(int *)dword_903EB8 * 0.00125;
    v14 = (double)dword_903EBC * 0.0016666667;
    v17 = (unsigned __int64)((double)2 * v6 + 0.5);
    v7 = (unsigned __int64)((double)v12 * v14 + 0.5);
    v21 = v7;
    v18 = (unsigned __int64)((double)0 * v6 + 0.5);
    v19 = (unsigned __int64)((double)v1 * v14 + 0.5);
    v8 = (unsigned __int64)(v6 * 6.0 + 0.5);
    v9 = 0;
    v13 = v17 + v8 / 2;
    while ( 1 )
    {
      if ( !v9 )
      {
        sub_4DD980(&unk_B6E2A0, v20, v17, v7, v18 + v8, v19 + v8, -1426111420);
        sub_4DD980(&unk_B6E2A0, v20, v13, v7 + v8 / 2, v18, v19, 2236962);
      }
      v10 = sub_539FE0(&this[3 * v9 + 127]);
      sub_4DF290(this, 0, v10, v13, (unsigned __int64)((double)v16 * v14 + 0.5), 0, 1);
      sub_539FE0(&this[3 * v9 + 127]);
      sub_4DF1D0();
      result = v11;
      ++v9;
      v16 += v22;
      if ( v9 >= v11 )
        break;
      v7 = v21;
    }
  }
  return result;
}
