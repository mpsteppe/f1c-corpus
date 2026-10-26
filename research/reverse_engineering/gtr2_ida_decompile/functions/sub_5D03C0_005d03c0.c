char __userpurge sub_5D03C0@<al>(int a1@<ecx>, _DWORD *a2@<esi>, int a3, int a4, _DWORD *a5, int a6)
{
  _DWORD *v6; // edi
  int v9; // esi
  int *v10; // edi
  char v11; // dl
  int v12; // ecx
  int v13; // eax
  int v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // esi
  _DWORD *v17; // eax
  _DWORD *v18; // edi
  void (__thiscall ***v19)(_DWORD, int); // ecx
  int v20; // ebp
  int v21; // esi
  int *v22; // edi
  int i; // esi
  int *v24; // ecx
  int v26; // [esp+2Ch] [ebp-60h] BYREF
  int v27; // [esp+30h] [ebp-5Ch] BYREF
  int v28; // [esp+34h] [ebp-58h]
  int *v29; // [esp+38h] [ebp-54h]
  _DWORD v30[3]; // [esp+3Ch] [ebp-50h] BYREF
  float v31; // [esp+48h] [ebp-44h] BYREF
  char v32; // [esp+4Ch] [ebp-40h]
  unsigned __int8 v33; // [esp+4Dh] [ebp-3Fh]
  int v34; // [esp+50h] [ebp-3Ch] BYREF
  int v35; // [esp+54h] [ebp-38h] BYREF
  char v36[36]; // [esp+58h] [ebp-34h] BYREF
  int v37; // [esp+7Ch] [ebp-10h]
  int v38; // [esp+84h] [ebp-8h]
  int retaddr; // [esp+8Ch] [ebp+0h]

  v6 = a5;
  v37 = dword_912B08;
  if ( a5 )
  {
    v9 = a3;
    (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a3 + 4))(a3, &v27, 8);
    if ( *(_BYTE *)(a1 + 12) )
    {
      sub_643E40("    - Phoneme Motion Data");
      if ( *(_BYTE *)(a1 + 12) )
      {
        sub_643E40("       + Interpolation Type = Hermite");
        if ( *(_BYTE *)(a1 + 12) )
        {
          sub_643E40("       + NrKeys             = %d", v28);
          if ( *(_BYTE *)(a1 + 12) )
            sub_643E40("       + NumPhonemes        = %d", v27);
        }
      }
    }
    if ( v27 > 0 )
    {
      v26 = v27;
      do
      {
        (*(void (__thiscall **)(int, int *, int, _DWORD *))(*(_DWORD *)v9 + 4))(v9, &v35, 40, a2);
        if ( *(_BYTE *)(a1 + 12) )
          sub_643E40("          - Phoneme             = %s", v36);
        v30[0] = &off_6F197C;
        v30[1] = 0;
        v30[2] = 0;
        v31 = 0.0;
        sub_5A8860(v30, strlen(v36), 0);
        v10 = v29;
        if ( v29 )
        {
          v11 = v30[0];
          v12 = v30[0] >> 2;
          qmemcpy(v29, &v34, 4 * (v30[0] >> 2));
          qmemcpy(&v10[v12], &v34 + v12, v11 & 3);
        }
        v38 = 0;
        v13 = sub_5C0060();
        v14 = sub_5D1170(v13);
        retaddr = -1;
        sub_5A8840();
        v15 = operator new(0x24u);
        if ( v15 )
        {
          v15[8] = v14;
          *v15 = 0;
          v15[1] = 0;
          v15[2] = 0;
          *((_BYTE *)v15 + 30) = 0;
          v15[5] = 0;
          v15[4] = 1;
          v15[6] = 1065353216;
          *((_BYTE *)v15 + 29) = 0;
          *((_BYTE *)v15 + 28) = 1;
          v15[3] = 0;
          v16 = v15;
        }
        else
        {
          v16 = 0;
        }
        v17 = operator new(0xCu);
        if ( v17 )
        {
          v17[1] = 0;
          *v17 = &off_72A3FC;
          v17[2] = 0;
          v18 = v17;
        }
        else
        {
          v18 = 0;
        }
        v19 = (void (__thiscall ***)(_DWORD, int))v16[3];
        if ( v19 )
          (**v19)(v19, 1);
        v16[3] = v18;
        v18[1] = v16;
        a2 = v16;
        v16[4] = 0;
        sub_5D10A0(a6);
        v9 = a3;
        --v26;
      }
      while ( *(float *)&v26 != 0.0 );
      v6 = a5;
    }
    v20 = 0;
    if ( v28 > 0 )
    {
      while ( 1 )
      {
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v9 + 4))(v9, &v31, 8);
        v21 = 0;
        if ( (int)v6[9] > 0 )
        {
          do
          {
            v22 = *(int **)(v6[11] + 4 * v21);
            if ( !v20 && v31 > 0.0 )
            {
              v34 = 0;
              sub_5CEE80(v22, 0.0, (int)&v34);
            }
            if ( v21 == v32 )
              *(float *)&v26 = (double)v33 * 0.0039215689;
            else
              *(float *)&v26 = 0.0;
            sub_5CEE80(v22, v31, (int)&v26);
            ++v21;
            v6 = a5;
          }
          while ( v21 < a5[9] );
        }
        if ( ++v20 >= v28 )
          break;
        v9 = a3;
      }
    }
    for ( i = 0; i < v6[9]; ++i )
    {
      v24 = *(int **)(v6[11] + 4 * i);
      if ( v24 )
        sub_5C6450(v24);
    }
    sub_5CF6F0(v6);
    return 1;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 12) )
      sub_643E40("Passed motion seems to be not valid!");
    return 0;
  }
}
