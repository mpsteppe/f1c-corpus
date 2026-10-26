char __thiscall sub_5CA420(_BYTE *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  _DWORD v12[6]; // [esp+8h] [ebp-98h] BYREF
  char v13; // [esp+20h] [ebp-80h]
  _DWORD *v14; // [esp+24h] [ebp-7Ch]
  int v15; // [esp+28h] [ebp-78h]
  char v16[8]; // [esp+30h] [ebp-70h] BYREF
  _BYTE v17[8]; // [esp+38h] [ebp-68h] BYREF
  _BYTE v18[26]; // [esp+40h] [ebp-60h] BYREF
  unsigned __int16 v19; // [esp+5Ah] [ebp-46h]
  float v20; // [esp+5Ch] [ebp-44h]
  float v21; // [esp+60h] [ebp-40h]
  float v22; // [esp+64h] [ebp-3Ch]
  float v23; // [esp+68h] [ebp-38h]
  float v24; // [esp+6Ch] [ebp-34h]
  float v25; // [esp+70h] [ebp-30h]
  int v26; // [esp+8Ch] [ebp-14h]
  int v27; // [esp+94h] [ebp-Ch]

  v26 = dword_912B08;
  v15 = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v18, 68);
    v7 = operator new(0x30u);
    v14 = v7;
    v27 = 0;
    if ( v7 )
    {
      sub_4050C0((int)v17);
      return off_16C922C(v7, a2, a3, a4, a5);
    }
    else
    {
      v27 = -1;
      if ( (v13 & 1) != 0 )
        sub_5A8840();
      v8 = *(_DWORD *)(*(_DWORD *)(a3 + 416) + 8);
      v9 = *(_DWORD *)(v8 + 8 * HIWORD(v21) + 4);
      v10 = v8 + 8 * HIWORD(v21);
      if ( v9 )
        v11 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v10 + 4) + 12))(*(_DWORD *)(v10 + 4));
      else
        v11 = 0;
      v14 = v12;
      v12[0] = &off_72A3D0;
      v12[1] = 0;
      sub_5C7030(v12, 0);
      sub_5C72F0();
      MEMORY[0x2C] = LODWORD(v25);
      MEMORY[0x1C] = LODWORD(v21);
      MEMORY[0x20] = LODWORD(v22);
      MEMORY[0x24] = LODWORD(v23);
      MEMORY[0x28] = LODWORD(v24);
      if ( this[12] )
      {
        sub_643E40("    - Material Layer");
        if ( this[12] )
        {
          sub_643E40("       + Texture  = %s", v16);
          if ( this[12] )
          {
            sub_643E40("       + Material = %s (number %d)", *(const char **)(v11 + 8), v19);
            if ( this[12] )
            {
              sub_643E40("       + Amount   = %f", v20);
              if ( this[12] )
              {
                sub_643E40("       + MapType  = %d", v18[24]);
                if ( this[12] )
                {
                  sub_643E40("       + UOffset  = %f", v21);
                  if ( this[12] )
                  {
                    sub_643E40("       + VOffset  = %f", v22);
                    if ( this[12] )
                    {
                      sub_643E40("       + UTiling  = %f", v23);
                      if ( this[12] )
                      {
                        sub_643E40("       + VTiling  = %f", v24);
                        if ( this[12] )
                          sub_643E40("       + Rotation = %f (radians)", v25);
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
