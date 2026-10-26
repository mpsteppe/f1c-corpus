int __thiscall sub_46BC20(_DWORD *this)
{
  _DWORD *v1; // ebp
  char *v2; // ebx
  int result; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char v8; // cl
  int v9; // eax
  const char *v10; // edi
  double v11; // st7
  int v12; // eax
  int v13; // eax
  char v14; // cl
  int v15; // edx
  int v16; // eax
  char v17; // cl
  const char *v18; // ebp
  unsigned int v19; // ebx
  char *v20; // edi
  char *v21; // edi
  const char *v22; // esi
  char v23; // cl
  float v24; // [esp+18h] [ebp-238h]
  float v25; // [esp+18h] [ebp-238h]
  int v26; // [esp+18h] [ebp-238h]
  int v27; // [esp+1Ch] [ebp-234h]
  int v29; // [esp+28h] [ebp-228h]
  char *v30; // [esp+2Ch] [ebp-224h]
  _BYTE v31[48]; // [esp+30h] [ebp-220h] BYREF
  _BYTE v32[48]; // [esp+60h] [ebp-1F0h] BYREF
  _BYTE v33[48]; // [esp+90h] [ebp-1C0h] BYREF
  char v34[48]; // [esp+C0h] [ebp-190h] BYREF
  _BYTE v35[48]; // [esp+F0h] [ebp-160h] BYREF
  _BYTE v36[48]; // [esp+120h] [ebp-130h] BYREF
  char v37[256]; // [esp+150h] [ebp-100h] BYREF

  v1 = this;
  v2 = (char *)&unk_5EC6D8 + 18624 * this[94];
  result = -1;
  v30 = v2;
  if ( *((_DWORD *)v2 + 3250) == -1 || *((int *)v2 + 4111) < 1 )
  {
    this[94] = -1;
  }
  else
  {
    sub_489CB0(this);
    sub_587DD0(v32, v2 + 17952, 47);
    v32[47] = 0;
    sub_587DD0(v33, v2 + 18104, 47);
    v4 = *((_DWORD *)v2 + 4111);
    v5 = *((_DWORD *)v2 + 4143);
    v33[47] = 0;
    v27 = v4;
    if ( v4 >= v5 )
      v27 = v5;
    result = v27;
    v6 = 0;
    if ( v27 > 0 )
    {
      while ( 1 )
      {
        sub_58815F(v31, "%d", *(char *)(v6 + *((_DWORD *)v2 + 4146)));
        v29 = v6 + 1;
        sub_58815F(v34, "%d", v6 + 1);
        v24 = *(float *)(*((_DWORD *)v2 + 4145) + 4 * v6);
        if ( v24 > 0.0 )
        {
          sub_58957A(v24);
          v9 = sub_587BDC(v24 * 0.016666668);
          sub_58815F(v35, "%d:%06.3f", v9, v24);
        }
        else
        {
          v7 = 0;
          do
          {
            v8 = asc_5C6A94[v7];
            v35[v7++] = v8;
          }
          while ( v8 );
        }
        if ( v24 <= 0.0 || *((float *)v2 + 4135) <= 0.0 )
        {
          v13 = 0;
          do
          {
            v14 = asc_5C6A94[v13];
            v36[v13++] = v14;
          }
          while ( v14 );
        }
        else
        {
          v10 = asc_5C6ABC;
          v11 = v24 - *((float *)v2 + 4135);
          v25 = v11;
          if ( v11 < 0.0 )
            v10 = byte_5EA438;
          sub_58957A(v25);
          v12 = sub_587BDC(v25 * 0.016666668);
          sub_58815F(v36, "%s%d:%06.3f", v10, v12, v25);
          if ( v25 == 0.0 )
            v1[90] = v6;
        }
        v15 = 1;
        v16 = 0;
        do
        {
          v17 = v31[v16];
          v37[v16++] = v17;
        }
        while ( v17 );
        v26 = v1[95];
        v18 = v32;
        do
        {
          if ( v26 != 1 || v15 == 1 || v15 == 4 )
          {
            *(_WORD *)&v37[strlen(v37)] = word_5C692C;
            v19 = strlen(v18) + 1;
            v20 = &v37[strlen(v37)];
            qmemcpy(v20, v18, 4 * (v19 >> 2));
            v22 = &v18[4 * (v19 >> 2)];
            v21 = &v20[4 * (v19 >> 2)];
            v23 = v19;
            v2 = v30;
            qmemcpy(v21, v22, v23 & 3);
          }
          ++v15;
          v18 += 48;
        }
        while ( v15 < 6 );
        result = sub_489600(v37, 0, 0, 0, 0);
        v6 = v29;
        if ( v29 >= v27 )
          break;
        v1 = this;
      }
    }
  }
  return result;
}
