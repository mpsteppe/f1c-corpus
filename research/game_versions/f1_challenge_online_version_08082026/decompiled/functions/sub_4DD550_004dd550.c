int __fastcall sub_4DD550(void *a1, float *a2, float *a3)
{
  int result; // eax
  int v7; // ecx
  int v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  float *v12; // ecx
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]
  int i; // [esp+20h] [ebp+4h]

  v13 = sub_4DD4E0(a1);
  *a2 = 3.4028235e38;
  a2[1] = 3.4028235e38;
  a2[2] = 3.4028235e38;
  *a3 = -3.4028235e38;
  a3[1] = -3.4028235e38;
  a3[2] = -3.4028235e38;
  result = sub_54C210(a1);
  v7 = 0;
  v15 = result;
  for ( i = 0; i < v15; ++i )
  {
    v8 = sub_54C230(v7);
    if ( *(float *)(v8 + 244) == 0.0 )
    {
      v9 = *(_DWORD *)(v8 + 20);
      if ( (v9 & 0x2000000) != 0 )
        v10 = 2 - ((v9 & 0x40) != 0);
      else
        v10 = 4 - ((v9 & 0x40) != 0);
    }
    else
    {
      v10 = 0;
    }
    if ( v10 >= v13 )
    {
      v11 = 0;
      v14 = sub_54E100(v8);
      if ( v14 > 0 )
      {
        do
        {
          v12 = (float *)sub_54E120(v11);
          if ( *v12 < (double)*a2 )
            *a2 = *v12;
          if ( v12[1] < (double)a2[1] )
            a2[1] = v12[1];
          if ( v12[2] < (double)a2[2] )
            a2[2] = v12[2];
          if ( *v12 > (double)*a3 )
            *a3 = *v12;
          if ( v12[1] > (double)a3[1] )
            a3[1] = v12[1];
          if ( v12[2] > (double)a3[2] )
            a3[2] = v12[2];
          ++v11;
        }
        while ( v11 < v14 );
      }
    }
    result = v15;
    v7 = i + 1;
  }
  return result;
}
