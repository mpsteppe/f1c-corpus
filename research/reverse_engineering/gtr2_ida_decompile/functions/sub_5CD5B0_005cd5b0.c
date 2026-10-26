char __thiscall sub_5CD5B0(_BYTE *this, int a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v8; // esi
  void *v9; // eax
  float *v10; // esi
  int v11; // ecx
  _DWORD v12[5]; // [esp+8h] [ebp-6Ch] BYREF
  const char *v13; // [esp+20h] [ebp-54h]
  void *v14; // [esp+2Ch] [ebp-48h]
  float v15; // [esp+30h] [ebp-44h] BYREF
  float v16; // [esp+34h] [ebp-40h]
  float v17; // [esp+38h] [ebp-3Ch]
  float v18; // [esp+3Ch] [ebp-38h]
  float v19; // [esp+40h] [ebp-34h]
  float v20; // [esp+44h] [ebp-30h]
  _DWORD v21[5]; // [esp+48h] [ebp-2Ch] BYREF
  char v22; // [esp+5Ch] [ebp-18h]
  int v23; // [esp+68h] [ebp-Ch]

  v5 = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)a2 + 4))(a2, v21, 28);
    sub_5BE610((int)&v15, a2);
    v23 = 0;
    switch ( LOBYTE(v19) )
    {
      case 0:
        v8 = 1;
        break;
      case 1:
        v8 = 2;
        break;
      case 2:
        v8 = 3;
        break;
      case 3:
        v8 = 5;
        break;
      case 4:
        v8 = 10;
        break;
      case 5:
        v8 = 11;
        break;
      case 6:
        v8 = 4;
        break;
      case 7:
        v8 = 6;
        break;
      case 8:
        v8 = 12;
        break;
      case 9:
        v8 = 7;
        break;
      case 0xA:
        v8 = 8;
        break;
      case 0xB:
        v8 = 9;
        break;
      default:
        v8 = 0;
        break;
    }
    v9 = operator new(0x30u);
    v14 = v9;
    LOBYTE(v23) = 1;
    if ( v9 )
      v10 = (float *)sub_5D3A60(v9, v8, &v15, LODWORD(v20));
    else
      v10 = 0;
    v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 416) + 8) + 8 * HIWORD(v16) + 4);
    v22 = 0;
    if ( v11 )
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
    v13 = (const char *)v12;
    v12[0] = &off_72A3D0;
    v12[1] = 0;
    sub_5C7030(v12, (int)v10);
    sub_5C72F0();
    v10[11] = v20;
    v10[7] = v16;
    v10[8] = v17;
    v10[9] = v18;
    v10[10] = v19;
    if ( this[12] )
    {
      sub_643E40("    - Material Layer");
      if ( this[12] )
      {
        sub_643E40("       + Texture  = %s", v13);
        if ( this[12] )
        {
          sub_643E40("       + Material = %s (number %d)", *(const char **)(v5 + 8), HIWORD(v14));
          if ( this[12] )
          {
            sub_643E40("       + Amount   = %f", v15);
            if ( this[12] )
            {
              sub_643E40("       + MapType  = %d", (char)v14);
              if ( this[12] )
              {
                sub_643E40("       + UOffset  = %f", v16);
                if ( this[12] )
                {
                  sub_643E40("       + VOffset  = %f", v17);
                  if ( this[12] )
                  {
                    sub_643E40("       + UTiling  = %f", v18);
                    if ( this[12] )
                    {
                      sub_643E40("       + VTiling  = %f", v19);
                      if ( this[12] )
                        sub_643E40("       + Rotation = %f (radians)", v20);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    v21[3] = -1;
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
