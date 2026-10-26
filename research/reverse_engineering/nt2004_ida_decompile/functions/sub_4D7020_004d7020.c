_DWORD **__thiscall sub_4D7020(int this, char a2)
{
  int i; // edi
  int v4; // eax
  char *v5; // ecx
  char *v6; // eax
  signed int v7; // eax
  char *v8; // eax
  char *v9; // eax
  CHAR *v10; // eax
  int *v11; // eax
  int v12; // eax
  signed int v13; // eax
  int v15[7]; // [esp+14h] [ebp-41Ch] BYREF
  _BYTE Buffer[1024]; // [esp+30h] [ebp-400h] BYREF

  sub_4D4B20((_DWORD *)(this + 2088));
  if ( *(_DWORD *)(this + 884) )
  {
    if ( *(_DWORD *)(this + 912) == 1 )
    {
      for ( i = 0; i < 49; ++i )
        sub_4D5A50((_DWORD *)this, i);
      sub_4D7520(this);
      if ( dword_75CBA8 != 4 && *(float *)(this + 2064) - *(float *)(this + 2060) > 0.0 && a2 )
      {
        if ( sub_41F230(dword_62A170, aSavingReplay, Destination) )
        {
          strncpy(Destination, aSavingReplay, 0x1FFu);
          byte_62A37B = 0;
        }
        sub_4BA730(Destination, 1065353216, 1);
        sub_57A080(v15);
        switch ( *(_DWORD *)(this + 1308) )
        {
          case 0:
            v4 = 0;
            break;
          case 1:
            v4 = 1;
            break;
          case 2:
            v4 = 2;
            break;
          case 3:
            v4 = 3;
            break;
          default:
            v4 = 4;
            break;
        }
        v5 = *(char **)(this + 924);
        if ( !v5 )
          v5 = &byte_629120;
        sub_57A110(v5, v4, 0, 1);
        sub_4D63D0(this, (int)v15, *(float *)(this + 2060), *(float *)(this + 2064), 1);
        sub_57A360(this + 884);
        v6 = *(char **)(this + 916);
        if ( !v6 )
          v6 = &byte_629120;
        sub_57A2F0(v6, 0);
        while ( 1 )
        {
          v7 = sub_57A3D0(Buffer, 0x400u);
          if ( v7 <= 0 )
            break;
          sub_57A3A0(Buffer, v7);
        }
        sub_57A360(v15);
        sub_57A0A0(v15);
      }
      sub_57A360(this + 884);
      sub_4D7B10(this);
    }
    else if ( *(_BYTE *)(this + 864) )
    {
      *(_BYTE *)(this + 864) = 0;
      if ( sub_41F230(dword_62A170, aSavingReplay, Destination) )
      {
        strncpy(Destination, aSavingReplay, 0x1FFu);
        byte_62A37B = 0;
      }
      sub_4BA730(Destination, 1065353216, 1);
      v8 = *(char **)(this + 2172);
      if ( !v8 )
        v8 = &byte_629120;
      sub_57AF60(v8);
      sub_57A080(v15);
      v9 = *(char **)(this + 2172);
      if ( !v9 )
        v9 = &byte_629120;
      if ( (unsigned __int8)sub_57A110(v9, 4, 0, 1) )
      {
        v10 = *(CHAR **)(this + 888);
        if ( !v10 )
          v10 = &byte_629120;
        sub_578600(v10);
        sub_4D63D0(this, (int)v15, *(float *)(this + 2060), *(float *)(this + 2064), 1);
        v11 = *(int **)(this + 932);
        *(_DWORD *)(this + 940) = v11;
        if ( v11 )
        {
          v12 = *v11;
          if ( v12 )
          {
            sub_57A5B0(*(_DWORD *)(v12 + 4));
            while ( 1 )
            {
              v13 = sub_57A3D0(Buffer, 0x400u);
              if ( v13 <= 0 )
                break;
              sub_57A3A0(Buffer, v13);
            }
            sub_57A360(v15);
            sub_57A360(this + 884);
            sub_57AF60(&byte_629120);
          }
        }
      }
      sub_57A0A0(v15);
    }
    else
    {
      sub_57A360(this + 884);
    }
  }
  *(_DWORD *)(this + 912) = 0;
  return sub_4D5820((_DWORD *)this);
}
