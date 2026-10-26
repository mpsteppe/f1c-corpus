char __thiscall sub_521B90(float *this, int a2, int a3, int a4)
{
  int v6; // eax
  int v7; // edi
  int v8; // ebp
  int v9; // eax
  int v10; // ecx
  float v11; // ebp
  int v12; // ecx
  int v13; // edx
  int v14; // edx
  int v15; // eax
  int i; // edi
  char v17; // bl
  int j; // edx
  int v19; // edx
  float v20; // [esp+28h] [ebp-3B8h]
  float v21; // [esp+2Ch] [ebp-3B4h]
  float v22; // [esp+38h] [ebp-3A8h]
  float v23; // [esp+44h] [ebp-39Ch]
  _DWORD v24[3]; // [esp+60h] [ebp-380h]
  _DWORD v25[3]; // [esp+6Ch] [ebp-374h]
  _DWORD v26[3]; // [esp+78h] [ebp-368h]
  _DWORD v27[3]; // [esp+84h] [ebp-35Ch]
  int v28[212]; // [esp+90h] [ebp-350h] BYREF

  if ( *(_DWORD *)a2 >> 29 != 1
    || (*(_DWORD *)a2 & 0xFC0000) != 0
    || byte_B71ED0
    && !dword_923E84[5654 * (unsigned __int8)*(_DWORD *)a2]
    && fabs(*(float *)(a2 + 4) - *(float *)(a4 + 4)) > 0.02 )
  {
    return 0;
  }
  v6 = *((_DWORD *)this + 722646);
  if ( v6 < 3 || v6 > 4 )
  {
LABEL_12:
    sub_51BFA0((_DWORD *)this + 722865, (_DWORD *)a2);
    sub_51BFA0((_DWORD *)this + 722653, (_DWORD *)a4);
    v9 = *((_DWORD *)this + 722875);
    v10 = *((_DWORD *)this + 722876);
    *(float *)v24 = this[722874];
    v24[1] = v9;
    v24[2] = v10;
    v11 = this[722879];
    v12 = *((_DWORD *)this + 722663);
    v13 = *((_DWORD *)this + 722664);
    *(float *)v27 = this[722662];
    v27[1] = v12;
    v27[2] = v13;
    v22 = this[722667];
    sub_59AA00(*(float *)(a3 + 4), (int)v28, 0.0);
    v14 = *(_DWORD *)(a3 + 40);
    v15 = *(_DWORD *)(a3 + 44);
    v26[0] = *(_DWORD *)(a3 + 36);
    v26[1] = v14;
    v26[2] = v15;
    v23 = *(float *)(a3 + 56);
    v25[0] = v28[9];
    v25[1] = v28[10];
    v25[2] = v28[11];
    for ( i = 0; i < 2; ++i )
    {
      v17 = 1;
      if ( i )
      {
        if ( !(unsigned __int8)sub_520DD0() )
          return 0;
        if ( !(unsigned __int8)sub_520DD0() )
          return 0;
        sub_5207E0(v22, v11);
        sub_5207E0(v23, *(float *)&v28[14]);
        if ( !(unsigned __int8)sub_520DD0() )
          return 0;
      }
      else
      {
        for ( j = 0; j < 3; j = v19 + 1 )
        {
          v20 = *(float *)&v25[j] - *(float *)&v26[j];
          if ( j == 1 )
            v20 = v20 + v20;
          v21 = *(float *)&v27[j] - *(float *)&v24[j];
          if ( !sub_520CE0(this, v20, v21) )
            break;
          if ( v19 == 2 )
            v17 = 0;
        }
        if ( v17 )
          return 0;
      }
    }
    return 1;
  }
  else
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = sub_51A200((_DWORD *)(a4 + 8), v7);
      if ( sub_51A200((_DWORD *)(a2 + 8), v7) != v8 )
        return 0;
      if ( ++v7 >= 14 )
        goto LABEL_12;
    }
  }
}
