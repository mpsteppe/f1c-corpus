int __fastcall sub_4DD7C0(void *a1, float *a2, float *a3)
{
  int result; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int j; // esi
  float *v12; // ecx
  double v13; // st7
  double v14; // st7
  double v15; // st6
  int i; // [esp+10h] [ebp-30h]
  int v17; // [esp+18h] [ebp-28h]
  int v18; // [esp+1Ch] [ebp-24h]
  double v19; // [esp+20h] [ebp-20h]
  double v20; // [esp+28h] [ebp-18h]
  double v21; // [esp+30h] [ebp-10h]
  double v22; // [esp+38h] [ebp-8h]

  v17 = sub_4DD4E0(a1);
  *a3 = 0.0;
  a3[1] = 0.0;
  a3[2] = 0.0;
  v20 = *a2;
  v19 = 0.0;
  v22 = a2[1];
  v21 = a2[2];
  result = sub_54C210(a1);
  v6 = 0;
  v18 = result;
  for ( i = 0; i < v18; ++i )
  {
    v7 = sub_54C230(v6);
    if ( *(float *)(v7 + 244) == 0.0 )
    {
      v8 = *(_DWORD *)(v7 + 20);
      if ( (v8 & 0x2000000) != 0 )
        v9 = 2 - ((v8 & 0x40) != 0);
      else
        v9 = 4 - ((v8 & 0x40) != 0);
    }
    else
    {
      v9 = 0;
    }
    if ( v9 >= v17 )
    {
      v10 = sub_54E100(v7);
      for ( j = 0; j < v10; ++j )
      {
        v12 = (float *)sub_54E120(j);
        v13 = *v12 * v20 + v12[2] * v21 + v12[1] * v22;
        if ( v13 > v19 )
        {
          v19 = v13;
          v14 = v12[2];
          v15 = v12[1];
          *a3 = *v12;
          a3[1] = v15;
          a3[2] = v14;
        }
      }
    }
    result = v18;
    v6 = i + 1;
  }
  return result;
}
