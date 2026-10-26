char __thiscall sub_5CD240(_BYTE *this, int a2, int a3, int a4, int a5)
{
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  _DWORD v11[6]; // [esp+8h] [ebp-F0h] BYREF
  char v12; // [esp+20h] [ebp-D8h]
  _DWORD *v13; // [esp+24h] [ebp-D4h]
  int v14; // [esp+28h] [ebp-D0h]
  char v15[4]; // [esp+30h] [ebp-C8h] BYREF
  _BYTE v16[8]; // [esp+38h] [ebp-C0h] BYREF
  _BYTE v17[114]; // [esp+40h] [ebp-B8h] BYREF
  unsigned __int16 v18; // [esp+B2h] [ebp-46h]
  float v19; // [esp+B4h] [ebp-44h]
  float v20; // [esp+B8h] [ebp-40h]
  float v21; // [esp+BCh] [ebp-3Ch]
  float v22; // [esp+C0h] [ebp-38h]
  float v23; // [esp+C4h] [ebp-34h]
  float v24; // [esp+C8h] [ebp-30h]
  int v25; // [esp+E4h] [ebp-14h]
  int v26; // [esp+ECh] [ebp-Ch]

  v25 = dword_912B08;
  v14 = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v17, 156);
    v13 = operator new(0x30u);
    v26 = 0;
    if ( v13 )
    {
      sub_4050C0((int)v16);
      return off_16C93EC(a2, a3, a4, a5);
    }
    else
    {
      v26 = -1;
      if ( (v12 & 1) != 0 )
        sub_5A8840();
      v7 = *(_DWORD *)(*(_DWORD *)(a3 + 416) + 8);
      v8 = *(_DWORD *)(v7 + 8 * HIWORD(v20) + 4);
      v9 = v7 + 8 * HIWORD(v20);
      if ( v8 )
        v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v9 + 4) + 12))(*(_DWORD *)(v9 + 4));
      else
        v10 = 0;
      v13 = v11;
      v11[0] = &off_72A3D0;
      v11[1] = 0;
      sub_5C7030(v11, 0);
      sub_5C72F0();
      MEMORY[0x2C] = LODWORD(v24);
      MEMORY[0x1C] = LODWORD(v20);
      MEMORY[0x20] = LODWORD(v21);
      MEMORY[0x24] = LODWORD(v22);
      MEMORY[0x28] = LODWORD(v23);
      if ( this[12] )
      {
        sub_643E40("    - Material Layer");
        if ( this[12] )
        {
          sub_643E40("       + Texture  = %s", v15);
          if ( this[12] )
          {
            sub_643E40("       + Material = %s (number %d)", *(const char **)(v10 + 8), v18);
            if ( this[12] )
            {
              sub_643E40("       + Amount   = %f", v19);
              if ( this[12] )
              {
                sub_643E40("       + MapType  = %d", v17[112]);
                if ( this[12] )
                {
                  sub_643E40("       + UOffset  = %f", v20);
                  if ( this[12] )
                  {
                    sub_643E40("       + VOffset  = %f", v21);
                    if ( this[12] )
                    {
                      sub_643E40("       + UTiling  = %f", v22);
                      if ( this[12] )
                      {
                        sub_643E40("       + VTiling  = %f", v23);
                        if ( this[12] )
                          sub_643E40("       + Rotation = %f (radians)", v24);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      return 1;
    }
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
