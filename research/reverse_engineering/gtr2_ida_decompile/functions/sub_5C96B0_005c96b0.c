char __thiscall sub_5C96B0(_BYTE *this, int a2, int a3, int a4, int a5)
{
  char v5; // bl
  int v8; // esi
  _DWORD *v9; // edi
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // esi
  _DWORD v15[6]; // [esp+10h] [ebp-70h] BYREF
  _DWORD *v16; // [esp+28h] [ebp-58h]
  int v17; // [esp+2Ch] [ebp-54h]
  int v18; // [esp+38h] [ebp-48h]
  _BYTE v19[4]; // [esp+3Ch] [ebp-44h] BYREF
  char v20[40]; // [esp+40h] [ebp-40h] BYREF
  char v21; // [esp+68h] [ebp-18h]
  unsigned __int16 v22; // [esp+6Ah] [ebp-16h]
  float v23; // [esp+6Ch] [ebp-14h]
  int v24; // [esp+70h] [ebp-10h]
  int v25; // [esp+78h] [ebp-8h]
  int v26; // [esp+7Ch] [ebp-4h]

  v24 = dword_912B08;
  v5 = 0;
  v17 = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 4))(a2, v20, 48);
    switch ( v21 )
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
      case 10:
        v8 = 8;
        break;
      case 11:
        v8 = 9;
        break;
      default:
        v8 = 0;
        break;
    }
    v9 = operator new(0x30u);
    v16 = v9;
    v26 = 0;
    if ( v9 )
    {
      sub_4050C0((int)v20);
      v5 = 1;
      LOBYTE(a3) = 1;
      v18 = 1;
      v10 = sub_5D3A60(v9, v8, v19, v25);
    }
    else
    {
      v10 = 0;
    }
    v26 = -1;
    if ( (v5 & 1) != 0 )
      sub_5A8840();
    v11 = *(_DWORD *)(*(_DWORD *)(a3 + 416) + 8);
    v12 = *(_DWORD *)(v11 + 8 * v22 + 4);
    v13 = v11 + 8 * v22;
    if ( v12 )
      v14 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v13 + 4) + 12))(*(_DWORD *)(v13 + 4));
    else
      v14 = 0;
    v16 = v15;
    v15[0] = &off_72A3D0;
    v15[1] = 0;
    sub_5C7030(v15, v10);
    sub_5C72F0();
    if ( this[12] )
    {
      sub_643E40("    - Material Layer");
      if ( this[12] )
      {
        sub_643E40("       + Texture  = '%s'", v20);
        if ( this[12] )
        {
          sub_643E40("       + Material = '%s' (%d)", *(const char **)(v14 + 8), v22);
          if ( this[12] )
          {
            sub_643E40("       + Amount   = %f", v23);
            if ( this[12] )
              sub_643E40("       + MapType  = %d", v21);
          }
        }
      }
    }
    return 1;
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
