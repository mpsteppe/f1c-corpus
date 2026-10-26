void __thiscall sub_4F9200(float *this, unsigned __int8 *a2)
{
  signed int v2; // esi
  int *v3; // eax
  double v4; // st7
  double v5; // st6
  _DWORD *v6; // edi
  signed int i; // ecx
  double v8; // st7
  int v9; // [esp+0h] [ebp-28h]
  float v10; // [esp+10h] [ebp-18h]
  float v11; // [esp+14h] [ebp-14h]
  float v12; // [esp+18h] [ebp-10h]
  float v13; // [esp+1Ch] [ebp-Ch]
  float v14; // [esp+20h] [ebp-8h]
  float v15; // [esp+2Ch] [ebp+4h]
  float v16; // [esp+2Ch] [ebp+4h]
  float v17; // [esp+2Ch] [ebp+4h]

  if ( fabs(dbl_7DA9D0 - this[73]) >= 1.0 )
  {
    this[73] = dbl_7DA9D0;
    v2 = NumOfElements;
    if ( (int)NumOfElements >= 2 )
    {
      v10 = flt_6290D0;
      v11 = (double)*((int *)&unk_62BF68 + 6326 * *a2 + 5212) * flt_6290D0 + *((float *)&unk_62BF68 + 6326 * *a2 + 5214);
      v4 = flt_769080;
      if ( flt_769080 <= 2.0 )
      {
        v4 = v4 * flt_6290D0;
        if ( v4 < 1.0 )
          v4 = 1.0;
      }
      v13 = 1.0;
      v12 = 1.0 / v4;
      v3 = (int *)((char *)&unk_62BF68 + 25304 * a2[NumOfElements - 1]);
      v15 = (double)v3[5212] * flt_6290D0 + *((float *)v3 + 5214);
      v5 = v11 - v15;
      if ( v5 < v4 )
      {
        v16 = v5;
        v13 = v16 * v12;
      }
      v14 = (double)dword_768F3C * 25.5;
      v6 = (_DWORD *)dword_7D3C44;
      if ( dword_79FC40 < 1023 )
      {
        ++dword_79FC40;
        dword_7D3C44 += 208;
      }
      *(float *)&v9 = dbl_7DA9D0;
      sub_4D0D00(v6, 4, 9, NumOfElements, 63, v9, 0);
      for ( i = 0; i < v2; ++i )
      {
        v8 = (v13 - (v11 - ((double)*(int *)(dword_75AAD0[i] + 20848) * v10 + *(float *)(dword_75AAD0[i] + 20856)))
                  * v12)
           * v14;
        v17 = v8;
        if ( v8 >= 0.0 )
        {
          if ( v17 > 255.0 )
            v17 = 255.0;
        }
        else
        {
          v17 = 0.0;
        }
        *((_BYTE *)v6 + i + 8) = (int)v17;
      }
    }
  }
}
