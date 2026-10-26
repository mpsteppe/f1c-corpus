int __thiscall sub_40ADB0(_DWORD *this)
{
  int v2; // esi
  int v3; // ecx
  double v4; // st7
  float *v5; // esi
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int *v9; // edx
  float v10; // ebp
  int result; // eax
  int v12; // [esp+14h] [ebp-54h]
  float v13; // [esp+18h] [ebp-50h]
  float v14; // [esp+18h] [ebp-50h]
  float v15; // [esp+1Ch] [ebp-4Ch]
  float v16; // [esp+1Ch] [ebp-4Ch]
  float v17; // [esp+30h] [ebp-38h]
  float v18; // [esp+30h] [ebp-38h]
  float v19; // [esp+34h] [ebp-34h] BYREF
  float v20; // [esp+38h] [ebp-30h] BYREF
  int v21; // [esp+3Ch] [ebp-2Ch] BYREF
  int v22; // [esp+40h] [ebp-28h] BYREF
  int v23; // [esp+44h] [ebp-24h] BYREF
  int v24; // [esp+48h] [ebp-20h]
  int v25; // [esp+4Ch] [ebp-1Ch]
  int v26; // [esp+50h] [ebp-18h] BYREF
  int v27; // [esp+54h] [ebp-14h]
  float v28; // [esp+58h] [ebp-10h]
  float v29; // [esp+5Ch] [ebp-Ch] BYREF
  float v30; // [esp+60h] [ebp-8h]
  float v31; // [esp+64h] [ebp-4h]

  v2 = this[5];
  v3 = this[3];
  v2 *= 160;
  v4 = *(float *)(v2 + v3 + 12);
  v5 = (float *)(v3 + v2);
  v6 = this[1];
  v29 = v4 * -1.0;
  v30 = v5[4] * -1.0;
  v31 = v5[5] * -1.0;
  if ( v6 )
  {
    if ( ((_BYTE)v5[29] & 4) != 0 )
    {
      v7 = 0;
      if ( dword_5C329C <= 0 )
      {
LABEL_7:
        sub_457B00(0);
      }
      else
      {
        while ( 1 )
        {
          v8 = dword_7C54F0[v7];
          v26 = *(int *)(v8 + 1860);
          v27 = *(int *)(v8 + 1864);
          v28 = *(float *)(v8 + 1868);
          v17 = (v28 - v31) * (v28 - v31)
              + (*(float *)&v27 - v30) * (*(float *)&v27 - v30)
              + (*(float *)&v26 - v29) * (*(float *)&v26 - v29);
          if ( v17 < 250.0 )
          {
            v9 = (int *)(v8 + 88);
            v23 = *v9;
            v24 = v9[1];
            v25 = v9[2];
            if ( sqrt(*(float *)&v24 * *(float *)&v24 + *(float *)&v25 * *(float *)&v25 + *(float *)&v23
                                                                                        * *(float *)&v23) > 35.0 )
              break;
          }
          if ( ++v7 >= dword_5C329C )
            goto LABEL_7;
        }
        v18 = 1.0 - v17 * 0.0040000002;
        v16 = sub_40C780(this);
        sub_457A00(v18, v16);
      }
    }
    v26 = *(int *)(dword_7C54E0 + 1860);
    v27 = *(int *)(dword_7C54E0 + 1864);
    v28 = *(float *)(dword_7C54E0 + 1868);
    v23 = *(int *)(dword_7C54E0 + 1796);
    v24 = *(int *)(dword_7C54E0 + 1800);
    v25 = *(int *)(dword_7C54E0 + 1804);
    v29 = *(float *)(dword_7C54E0 + 88);
    v30 = *(float *)(dword_7C54E0 + 92);
    v31 = *(float *)(dword_7C54E0 + 96);
    v10 = *v5;
    v15 = sub_40C780(this);
    v13 = sub_4084A0();
    (*(void (__thiscall **)(float *, int *, int *, float *, _DWORD, _DWORD))(LODWORD(v10) + 24))(
      v5,
      &v26,
      &v23,
      &v29,
      LODWORD(v13),
      LODWORD(v15));
    v26 = *((int *)v5 + 3);
    v27 = *((int *)v5 + 4);
    v28 = v5[5];
    v23 = *((int *)v5 + 6);
    v24 = *((int *)v5 + 7);
    v25 = *((int *)v5 + 8);
    sub_541CD0(v26, v27, v28, v23, v24, v25);
    sub_456060(&v20, &v19);
    sub_456080(&v22, &v21);
    v14 = v19 * 0.01745433;
    *(float *)&v12 = v20 * 0.01745433;
    sub_542050(v12, v14, 0);
    sub_5423C0(v22, v21);
    return sub_542680(v5[18]);
  }
  return result;
}
