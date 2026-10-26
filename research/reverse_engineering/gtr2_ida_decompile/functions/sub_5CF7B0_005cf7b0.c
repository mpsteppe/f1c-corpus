char __thiscall sub_5CF7B0(int this, int a2, int a3, int a4, int a5)
{
  int v6; // esi
  int v7; // edx
  double v8; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st7
  int v12; // eax
  double v13; // st6
  int v14; // ebx
  int v16; // [esp+8h] [ebp-58h]
  int v17; // [esp+Ch] [ebp-54h]
  _DWORD *v18; // [esp+14h] [ebp-4Ch]
  int v19; // [esp+18h] [ebp-48h]
  _DWORD v20[7]; // [esp+34h] [ebp-2Ch] BYREF
  char v21; // [esp+50h] [ebp-10h]
  int v22; // [esp+54h] [ebp-Ch]

  v20[1] = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)a2 + 4))(a2, this + 20);
    if ( *(_BYTE *)(this + 12) )
    {
      sub_643E40("- Node name = '%s'", (const char *)(this + 20));
      if ( *(_BYTE *)(this + 12) )
      {
        sub_643E40("    + Parent = '%s'", (const char *)(this + 148));
        if ( *(_BYTE *)(this + 12) )
        {
          sub_643E40(
            "    + Position:      x=%f, y=%f, z=%f",
            *(float *)(this + 276),
            *(float *)(this + 280),
            *(float *)(this + 284));
          if ( *(_BYTE *)(this + 12) )
          {
            sub_643E40(
              "    + Rotation:      x=%f, y=%f, z=%f, w=%f",
              *(float *)(this + 288),
              *(float *)(this + 292),
              *(float *)(this + 296),
              *(float *)(this + 300));
            if ( *(_BYTE *)(this + 12) )
            {
              sub_643E40(
                "    + Scale:         x=%f, y=%f, z=%f",
                *(float *)(this + 320),
                *(float *)(this + 324),
                *(float *)(this + 328));
              if ( *(_BYTE *)(this + 12) )
              {
                sub_643E40(
                  "    + Scale Orient:  x=%f, y=%f, z=%f, w=%f",
                  *(float *)(this + 304),
                  *(float *)(this + 308),
                  *(float *)(this + 312),
                  *(float *)(this + 316));
                if ( *(_BYTE *)(this + 12) )
                  sub_643E40(
                    "    + Shear:\t\t\txy=%f, xz=%f, yz=%f",
                    *(float *)(this + 332),
                    *(float *)(this + 336),
                    *(float *)(this + 340));
              }
            }
          }
        }
      }
    }
    v20[0] = operator new(0x198u);
    v22 = 0;
    if ( v20[0] )
    {
      sub_4050C0(this + 20);
      v19 = a3;
      v18 = v20;
      v21 = 1;
      v6 = sub_5C0780();
    }
    else
    {
      v6 = 0;
    }
    v20[5] = -1;
    sub_5C7280();
    v7 = *(_DWORD *)(this + 284);
    v8 = *(float *)(this + 280);
    *(float *)(v6 + 264) = *(float *)(this + 276);
    *(_DWORD *)(v6 + 272) = v7;
    *(float *)(v6 + 268) = v8;
    v9 = *(float *)(this + 320);
    v10 = *(float *)(this + 324);
    *(_DWORD *)(v6 + 284) = *(_DWORD *)(this + 328);
    *(float *)(v6 + 276) = v9;
    *(float *)(v6 + 280) = v10;
    v11 = *(float *)(this + 288);
    v12 = *(_DWORD *)(this + 300);
    v13 = *(float *)(this + 292);
    *(_DWORD *)(v6 + 204) = *(_DWORD *)(this + 296);
    *(float *)(v6 + 196) = v11;
    *(float *)(v6 + 200) = v13;
    *(_DWORD *)(v6 + 208) = v12;
    v20[0] = v12;
    *(_DWORD *)(v6 + 228) = *(_DWORD *)(v6 + 264);
    *(_DWORD *)(v6 + 232) = *(_DWORD *)(v6 + 268);
    *(_DWORD *)(v6 + 236) = *(_DWORD *)(v6 + 272);
    *(_DWORD *)(v6 + 212) = *(_DWORD *)(v6 + 196);
    *(_DWORD *)(v6 + 216) = *(_DWORD *)(v6 + 200);
    *(_DWORD *)(v6 + 220) = *(_DWORD *)(v6 + 204);
    *(_DWORD *)(v6 + 224) = *(_DWORD *)(v6 + 208);
    *(_DWORD *)(v6 + 240) = *(_DWORD *)(v6 + 276);
    *(_DWORD *)(v6 + 244) = *(_DWORD *)(v6 + 280);
    *(_DWORD *)(v6 + 248) = *(_DWORD *)(v6 + 284);
    sub_5C00F0(v6, v6, v18, v19);
    if ( *(_BYTE *)(this + 148) )
    {
      v17 = this + 148;
      v16 = v6;
      sub_5CC900();
    }
    v14 = sub_5BE270(*(_DWORD **)(this + 16), 1);
    if ( v14 )
    {
      sub_5BD430();
      *(_DWORD *)(v14 + 28) = v6;
      return 1;
    }
    if ( v6 )
      (**(void (__thiscall ***)(int, int, int, int))v6)(v6, 1, v16, v17);
    if ( *(_BYTE *)(this + 12) )
      sub_643E40((const char *)0x144);
  }
  else if ( *(_BYTE *)(this + 12) )
  {
    sub_643E40("Passed actor seems to be not valid!");
  }
  return 0;
}
