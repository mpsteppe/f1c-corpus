char __thiscall sub_501990(int this)
{
  int v2; // ecx
  void *v3; // ecx
  int v4; // eax
  bool v5; // bl
  CHAR ***v6; // eax
  CHAR ***v7; // esi
  CHAR *v8; // eax
  CHAR *v9; // eax
  CHAR *v10; // eax
  int v11; // esi
  __int16 *v12; // ebx
  int v13; // eax
  bool v14; // bl
  CHAR ***v15; // eax
  CHAR *v16; // eax
  char result; // al
  void *v18; // ecx
  char Destination[127]; // [esp+Ch] [ebp-80h] BYREF
  char v20; // [esp+8Bh] [ebp-1h]

  if ( NumOfElements != *(_DWORD *)(this + 84) )
    sub_501DD0(this);
  v2 = *(_DWORD *)(this + 16);
  if ( v2 != -1 )
  {
    if ( *(float *)(this + 96) <= 0.0 )
    {
      v3 = *(void **)(this + 4 * v2 + 36);
      if ( v3 )
      {
        if ( sub_5015E0(v3) == 1 )
        {
          *(_DWORD *)(this + 16) = -1;
          *(_DWORD *)(this + 96) = 1056964608;
        }
      }
      else
      {
        *(_DWORD *)(this + 16) = -1;
      }
    }
    else
    {
      *(float *)(this + 96) = *(float *)(this + 96) - dbl_7DA9C8;
    }
  }
  v4 = *(_DWORD *)(this + 20);
  if ( v4 != -1 && sub_5015E0(*(void **)(this + 4 * v4 + 56)) == 1 )
    *(_DWORD *)(this + 20) = -1;
  v5 = 0;
  v6 = (CHAR ***)sub_40C460(&dword_6291CC);
  v7 = v6;
  if ( flt_7D79F4 <= 0.0 )
  {
    if ( v6 )
    {
      v8 = sub_459BA0(v6);
      v5 = _strcmpi(v8, aDrivable) == 0;
      v9 = sub_459B80(v7);
      _strcmpi(v9, aCockpit);
      v10 = sub_459B80(v7);
      if ( !_strcmpi(v10, aSwingman) || v5 )
        v5 = 1;
    }
  }
  if ( dword_767BA4 && v5 )
    sub_5015E0(*(void **)(this + 28));
  if ( ((dword_761FF8 & 1) == 0 || (byte_762119 & 2) == 0) && ((dword_761FF8 & 1) == 0 || (byte_762199 & 2) == 0) )
  {
    v11 = 0;
    v12 = word_762A08;
    while ( v11 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
    {
      if ( *v12 == 60 )
      {
        v13 = dword_767BA4 == 0;
        dword_767BA4 = v13;
        if ( v13 >= dword_767BAC )
        {
          if ( v13 > dword_767BB0 )
            dword_767BA4 = dword_767BB0;
        }
        else
        {
          dword_767BA4 = dword_767BAC;
        }
        if ( sub_41F230(dword_62A170, aHud, ::Destination) )
        {
          strncpy(::Destination, aHud, 0x1FFu);
          byte_62A37B = 0;
        }
        strncpy(Destination, ::Destination, 0x7Fu);
        v20 = 0;
        sub_45D270(&byte_764D68, Destination, 1);
        if ( dword_767BA4 )
        {
          sub_502060(1);
          if ( sub_41F230(dword_62A170, aHudOn, ::Destination) )
          {
            strncpy(::Destination, aHudOn, 0x1FFu);
            byte_62A37B = 0;
          }
        }
        else
        {
          sub_502090(-1);
          if ( sub_41F230(dword_62A170, aHudOff, ::Destination) )
          {
            strncpy(::Destination, aHudOff, 0x1FFu);
            byte_62A37B = 0;
          }
        }
        strncpy(Destination, ::Destination, 0x7Fu);
        v20 = 0;
        sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
      }
      ++v11;
      ++v12;
    }
  }
  v14 = 0;
  if ( sub_40C460(&dword_6291CC) )
  {
    v15 = (CHAR ***)sub_40C460(&dword_6291CC);
    v16 = sub_459B80(v15);
    v14 = _strcmpi(v16, aCockpit) == 0;
  }
  result = *(_BYTE *)(this + 101);
  if ( result )
  {
    v18 = *(void **)(this + 68);
    if ( v18 )
    {
      if ( !v14 )
        return sub_5015E0(v18);
    }
  }
  return result;
}
