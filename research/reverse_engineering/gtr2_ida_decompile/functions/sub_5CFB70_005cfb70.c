char __thiscall sub_5CFB70(int this, int a2, int a3, int a4, int a5)
{
  char v6; // al
  int v7; // esi
  double v8; // st7
  double v9; // st6
  double v10; // st7
  double v11; // st6
  float v12; // ecx
  double v13; // st7
  double v14; // st6
  int v15; // ebx
  int v17; // [esp+Ch] [ebp-B4h]
  int v18; // [esp+10h] [ebp-B0h]
  _BYTE *v19; // [esp+18h] [ebp-A8h]
  int v20; // [esp+1Ch] [ebp-A4h]
  int v21; // [esp+28h] [ebp-98h]
  void *v22; // [esp+2Ch] [ebp-94h]
  void *v23[2]; // [esp+30h] [ebp-90h] BYREF
  _BYTE v24[4]; // [esp+40h] [ebp-80h] BYREF
  const char *v25; // [esp+44h] [ebp-7Ch]
  float v26; // [esp+50h] [ebp-70h]
  int v27; // [esp+54h] [ebp-6Ch]
  float v28; // [esp+58h] [ebp-68h]
  float v29; // [esp+5Ch] [ebp-64h]
  float v30; // [esp+60h] [ebp-60h]
  float v31; // [esp+64h] [ebp-5Ch]
  float v32; // [esp+68h] [ebp-58h] BYREF
  float v33; // [esp+6Ch] [ebp-54h]
  float v34; // [esp+70h] [ebp-50h]
  float v35; // [esp+74h] [ebp-4Ch]
  float v36; // [esp+78h] [ebp-48h]
  float v37; // [esp+7Ch] [ebp-44h]
  float v38; // [esp+80h] [ebp-40h]
  float v39; // [esp+84h] [ebp-3Ch]
  float v40; // [esp+88h] [ebp-38h]
  float v41; // [esp+8Ch] [ebp-34h]
  float v42; // [esp+90h] [ebp-30h]
  float v43; // [esp+94h] [ebp-2Ch]
  float v44; // [esp+98h] [ebp-28h]
  float v45; // [esp+9Ch] [ebp-24h]
  float v46; // [esp+A0h] [ebp-20h]
  char v47; // [esp+ACh] [ebp-14h]
  int v48; // [esp+B4h] [ebp-Ch]

  if ( a3 )
  {
    (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &v32, 68);
    sub_5BE610((int)v24, a2);
    v48 = 0;
    sub_5BE610((int)v23, a2);
    v6 = *(_BYTE *)(this + 12);
    LOBYTE(v48) = 1;
    if ( v6 )
    {
      sub_643E40("- Node name = '%s'", v25);
      if ( *(_BYTE *)(this + 12) )
      {
        sub_643E40("    + Parent = '%s'", (const char *)v23[1]);
        if ( *(_BYTE *)(this + 12) )
        {
          sub_643E40("    + Position:      x=%f, y=%f, z=%f", v30, v31, v32);
          if ( *(_BYTE *)(this + 12) )
          {
            sub_643E40("    + Rotation:      x=%f, y=%f, z=%f, w=%f", v33, v34, v35, v36);
            if ( *(_BYTE *)(this + 12) )
            {
              sub_643E40("    + Scale:         x=%f, y=%f, z=%f", v41, v42, v43);
              if ( *(_BYTE *)(this + 12) )
              {
                sub_643E40("    + Scale Orient:  x=%f, y=%f, z=%f, w=%f", v37, v38, v39, v40);
                if ( *(_BYTE *)(this + 12) )
                  sub_643E40("    + Shear:\t\t\txy=%f, xz=%f, yz=%f", v44, v45, v46);
              }
            }
          }
        }
      }
    }
    v22 = operator new(0x198u);
    LOBYTE(v48) = 2;
    if ( v22 )
    {
      v20 = a3;
      v19 = v24;
      v7 = sub_5C0780();
    }
    else
    {
      v7 = 0;
    }
    v47 = 1;
    sub_5C7280();
    v8 = v28;
    v9 = v29;
    *(_DWORD *)(v7 + 264) = v27;
    *(float *)(v7 + 268) = v8;
    *(float *)(v7 + 272) = v9;
    v10 = v39;
    v11 = v40;
    *(float *)(v7 + 276) = v38;
    *(float *)(v7 + 280) = v10;
    *(float *)(v7 + 284) = v11;
    v12 = v33;
    v13 = v31;
    v14 = v32;
    *(float *)(v7 + 196) = v30;
    *(float *)(v7 + 200) = v13;
    *(float *)(v7 + 208) = v12;
    v26 = v12;
    *(float *)(v7 + 204) = v14;
    *(_DWORD *)(v7 + 228) = *(_DWORD *)(v7 + 264);
    *(_DWORD *)(v7 + 232) = *(_DWORD *)(v7 + 268);
    *(_DWORD *)(v7 + 236) = *(_DWORD *)(v7 + 272);
    *(_DWORD *)(v7 + 212) = *(_DWORD *)(v7 + 196);
    *(_DWORD *)(v7 + 216) = *(_DWORD *)(v7 + 200);
    *(_DWORD *)(v7 + 220) = *(_DWORD *)(v7 + 204);
    *(_DWORD *)(v7 + 224) = *(_DWORD *)(v7 + 208);
    *(_DWORD *)(v7 + 240) = *(_DWORD *)(v7 + 276);
    *(_DWORD *)(v7 + 244) = *(_DWORD *)(v7 + 280);
    *(_DWORD *)(v7 + 248) = *(_DWORD *)(v7 + 284);
    sub_5C00F0(v7, v7, v19, v20);
    if ( v22 )
    {
      v18 = v21;
      v17 = v7;
      sub_5CC900();
    }
    v15 = sub_5BE270(*(_DWORD **)(this + 16), 1);
    if ( v15 )
    {
      sub_5BD430();
      *(_DWORD *)(v15 + 28) = v7;
      LOBYTE(v45) = 0;
      sub_5A8840();
      v45 = NAN;
      sub_5A8840();
      return 1;
    }
    if ( v7 )
      (**(void (__thiscall ***)(int, int, int, int))v7)(v7, 1, v17, v18);
    if ( *(_BYTE *)(this + 12) )
      sub_643E40("Can't find shared data.");
    LOBYTE(v45) = 0;
    sub_5A8840();
    v45 = NAN;
    sub_5A8840();
  }
  else if ( *(_BYTE *)(this + 12) )
  {
    sub_643E40("Passed actor seems to be not valid!");
  }
  return 0;
}
