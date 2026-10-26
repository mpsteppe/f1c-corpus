int __thiscall sub_4CDA20(int this, int a2)
{
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  CHAR *v9; // eax
  int v10; // edi
  int v11; // eax
  char v12[28]; // [esp+Ch] [ebp-31Ch] BYREF
  char Source[509]; // [esp+28h] [ebp-300h] BYREF
  __int16 v14; // [esp+225h] [ebp-103h]
  char v15; // [esp+227h] [ebp-101h]
  char Destination[256]; // [esp+228h] [ebp-100h] BYREF

  if ( !sub_4634F0(dword_764D70) || dword_75CBA8 == 1 )
  {
    Source[0] = byte_629120;
    memset(&Source[1], 0, 0x1FCu);
    v14 = 0;
    v15 = 0;
    sub_57A080(v12);
    if ( (GetFileAttributesA((LPCSTR)(this + 20)) & 1) != 0 )
      *(_DWORD *)(this + 276) = 1;
    sub_57B040((char *)(this + 20), 512);
    if ( (unsigned __int8)sub_57A2F0(Source, 1) )
    {
      sub_57B340(512);
      strcpy((char *)(this + 20), Source);
      if ( (byte_762F00 & 1) != 0 )
        sub_4CB410(this, COERCE_FLOAT(2));
      else
        sub_4CB410(this, COERCE_FLOAT(1));
      sub_4BC410((_DWORD *)this, (int)v12);
      if ( *(_DWORD *)(this + 9576) )
      {
        v4 = *(_DWORD *)(this + 9584);
        v5 = *(_DWORD *)(this + 9588);
        *(_DWORD *)(this + 9576) = 1;
        if ( v4 <= 1 )
        {
          if ( v5 < 1 )
            *(_DWORD *)(this + 9576) = v5;
        }
        else
        {
          *(_DWORD *)(this + 9576) = v4;
        }
      }
      if ( *(_BYTE *)(this + 14868) && *(int *)(this + 15000) < 41 )
      {
        v6 = *(_DWORD *)(this + 15012);
        *(_DWORD *)(this + 15000) = 41;
        v7 = *(_DWORD *)(this + 15008);
        v8 = *(_DWORD *)(this + 15000);
        if ( v8 >= v7 )
        {
          if ( v8 > v6 )
            *(_DWORD *)(this + 15000) = v6;
        }
        else
        {
          *(_DWORD *)(this + 15000) = v7;
        }
      }
      v9 = *(CHAR **)(this + 408);
      if ( !v9 )
        v9 = &byte_629120;
      sub_4E8D60(v9);
      v10 = *(_DWORD *)(this + 36 * *(_DWORD *)(this + 9708) + 11460);
      v11 = v10 + sub_42DBA0();
      if ( v11 >= 1 )
      {
        if ( v11 > 48 )
          v11 = 48;
      }
      else
      {
        v11 = 1;
      }
      if ( *(_DWORD *)(this + 9708) == 5 )
        v11 = 0;
      NumOfElements = v11;
      sub_42DC40();
      sub_4CD760((char *)this, Destination, 256);
      sub_4E58F0(Destination);
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 22340) + 16))(*(_DWORD *)(this + 22340));
      sub_4CE0F0(*(_DWORD *)(this + 9708));
      sub_435C20((int)&dword_75E8F0);
      sub_4EFDE0(LODWORD(flt_767898));
      sub_419110(byte_6292D0);
      sub_57A0A0(v12);
      return 0;
    }
    else
    {
      sub_57A0A0(v12);
      return -1;
    }
  }
  else
  {
    sub_4CE0F0(*(_DWORD *)(this + 9708));
    return 0;
  }
}
