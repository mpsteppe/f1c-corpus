char __thiscall sub_5CE960(_BYTE *this, int a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v8; // eax
  char v9; // al
  int v10; // eax
  char v11; // al
  int v12; // ebx
  char v13; // al
  int v14; // ebx
  char v15; // al
  int v16; // ebx
  char v17; // al
  _BYTE *v18; // [esp+18h] [ebp-C8h]
  float *v19; // [esp+1Ch] [ebp-C4h]
  float **v20; // [esp+28h] [ebp-B8h]
  int v21; // [esp+2Ch] [ebp-B4h]
  int v22; // [esp+3Ch] [ebp-A4h]
  float *v23; // [esp+44h] [ebp-9Ch] BYREF
  int v24; // [esp+4Ch] [ebp-94h]
  float v25; // [esp+50h] [ebp-90h]
  void *v26; // [esp+54h] [ebp-8Ch] BYREF
  float v27; // [esp+58h] [ebp-88h] BYREF
  float v28; // [esp+5Ch] [ebp-84h]
  float v29; // [esp+60h] [ebp-80h] BYREF
  void *Block; // [esp+64h] [ebp-7Ch]
  float v31; // [esp+68h] [ebp-78h] BYREF
  const char *v32; // [esp+6Ch] [ebp-74h]
  _DWORD v33[2]; // [esp+70h] [ebp-70h] BYREF
  _BYTE v34[4]; // [esp+78h] [ebp-68h] BYREF
  const char *v35; // [esp+7Ch] [ebp-64h]
  _BYTE v36[4]; // [esp+80h] [ebp-60h] BYREF
  const char *v37; // [esp+84h] [ebp-5Ch]
  int v38; // [esp+94h] [ebp-4Ch]
  unsigned int v39; // [esp+98h] [ebp-48h] BYREF
  int v40; // [esp+9Ch] [ebp-44h]
  char v41; // [esp+A4h] [ebp-3Ch]
  char v42; // [esp+ACh] [ebp-34h]
  char v43; // [esp+B4h] [ebp-2Ch]
  _BYTE v44[4]; // [esp+B8h] [ebp-28h] BYREF
  const char *v45; // [esp+BCh] [ebp-24h]
  char v46; // [esp+C4h] [ebp-1Ch]
  int v47; // [esp+D4h] [ebp-Ch]

  v5 = 0;
  if ( a3 )
  {
    v8 = *(_DWORD *)a2;
    v24 = 16;
    (*(void (__thiscall **)(int, _DWORD *))(v8 + 4))(a2, v33);
    sub_5BE610((int)v44, a2);
    v47 = 0;
    sub_5BE610((int)&v39, a2);
    v9 = this[12];
    LOBYTE(v47) = 1;
    if ( v9 )
    {
      sub_643E40("- Material name = '%s'", v45);
      if ( this[12] )
      {
        sub_643E40("  + Effect file       = '%s'", (const char *)v40);
        if ( this[12] )
        {
          sub_643E40("  + Num int params    = %d", v31);
          if ( this[12] )
          {
            sub_643E40("  + Num float params  = %d", v32);
            if ( this[12] )
            {
              sub_643E40("  + Num color params  = %d", v33[0]);
              if ( this[12] )
                sub_643E40("  + Num bitmap params = %d", v33[1]);
            }
          }
        }
      }
    }
    v28 = COERCE_FLOAT(operator new(0x54u));
    LOBYTE(v47) = 2;
    if ( v28 == 0.0 )
      v10 = 0;
    else
      v10 = sub_5D6120(v44);
    LOBYTE(v47) = 1;
    v29 = COERCE_FLOAT(&off_7296CC);
    Block = 0;
    sub_5BD2D0(&v29, v10);
    LOBYTE(v47) = 3;
    if ( Block )
      v27 = COERCE_FLOAT((*(int (__thiscall **)(void *))(*(_DWORD *)Block + 12))(Block));
    else
      v27 = 0.0;
    v23 = &v29;
    sub_5BD510();
    sub_5A8920((void **)(LODWORD(v25) + 68), a2, v38, v39);
    if ( this[12] )
      sub_643E40("  + Parameters:");
    if ( SLODWORD(v29) > 0 )
    {
      do
      {
        v22 = 4;
        (*(void (__thiscall **)(int, void **))(*(_DWORD *)a2 + 4))(a2, &v26);
        sub_5BE610((int)v34, a2);
        v11 = this[12];
        v46 = 4;
        if ( v11 )
          sub_643E40("    + int %s = %d", v35, v24);
        sub_5C7380();
        LOBYTE(v45) = 3;
        sub_5A8840();
        ++v5;
      }
      while ( v5 < SLODWORD(v25) );
    }
    v12 = 0;
    if ( (int)v26 > 0 )
    {
      do
      {
        v21 = 4;
        v20 = &v23;
        (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 4))(a2);
        sub_5BE610((int)&v31, a2);
        v13 = this[12];
        v43 = 5;
        if ( v13 )
          sub_643E40("    + float %s = %f", v32, *(float *)&v22);
        sub_5C7430((int)&v31, v22);
        v43 = 3;
        sub_5A8840();
        ++v12;
      }
      while ( v12 < v24 );
    }
    v14 = 0;
    if ( SLODWORD(v25) > 0 )
    {
      do
      {
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &v27, 16);
        sub_5BE610((int)v36, a2);
        v15 = this[12];
        v42 = 6;
        if ( v15 )
          sub_643E40("    + color %s = (%f, %f, %f, %f)", v37, v25, *(float *)&v26, v27, v28);
        Block = v26;
        v31 = v27;
        v19 = &v29;
        v29 = v25;
        v18 = v36;
        v32 = (const char *)LODWORD(v28);
        sub_5C74E0();
        v41 = 3;
        sub_5A8840();
        ++v14;
      }
      while ( v14 < 0 );
    }
    v16 = 0;
    if ( (int)v23 > 0 )
    {
      do
      {
        sub_5BE610((int)&v27, a2);
        v41 = 7;
        sub_5BE610((int)v34, a2);
        v17 = this[12];
        v41 = 8;
        if ( v17 )
          sub_643E40("    + string %s = %s", (const char *)LODWORD(v28), v35);
        ((void (__thiscall *)(float **, float *, _BYTE *, _BYTE *, float *))dword_5C75A0)(v20, &v27, v34, v18, v19);
        LOBYTE(v40) = 7;
        sub_5A8840();
        LOBYTE(v40) = 3;
        sub_5A8840();
        ++v16;
      }
      while ( v16 < v22 );
    }
    LOBYTE(v40) = 1;
    if ( v21 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v21 + 4))(v21);
    LOBYTE(v40) = 0;
    sub_5A8840();
    v40 = -1;
    sub_5A8840();
    return 1;
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
