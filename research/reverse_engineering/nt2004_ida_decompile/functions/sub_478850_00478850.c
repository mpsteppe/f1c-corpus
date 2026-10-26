void __thiscall sub_478850(int this, int a2)
{
  signed int v3; // eax
  int v4; // ebx
  int i; // esi
  const char *v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // ebx
  int v13; // eax
  signed int v14; // [esp+10h] [ebp-58h]
  char *String2; // [esp+14h] [ebp-54h]
  char Buffer; // [esp+18h] [ebp-50h] BYREF
  int v17; // [esp+19h] [ebp-4Fh]
  int v18; // [esp+1Dh] [ebp-4Bh]
  int v19; // [esp+21h] [ebp-47h]
  __int16 v20; // [esp+25h] [ebp-43h]
  char v21; // [esp+27h] [ebp-41h]
  char String1[61]; // [esp+28h] [ebp-40h] BYREF
  __int16 v23; // [esp+65h] [ebp-3h]
  char v24; // [esp+67h] [ebp-1h]
  int *v25; // [esp+6Ch] [ebp+4h]

  String1[0] = byte_629120;
  memset(&String1[1], 0, 0x3Cu);
  v23 = 0;
  v24 = 0;
  if ( a2 )
  {
LABEL_19:
    sub_49FEC0(this);
    v8 = NumOfElements;
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = 0;
      if ( v8 <= 0 )
        break;
      v12 = v10 + 1;
      while ( *(_DWORD *)(dword_75AAD0[v11] + 20884) != v12 )
      {
        if ( ++v11 >= v8 )
          goto LABEL_28;
      }
      if ( *(_DWORD *)(dword_75AAD0[v11] + 16584) != -1 )
      {
        sub_478330((_DWORD *)this, v11, byte_765340, String1);
        v13 = dword_75AAD0[v11];
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v20 = 0;
        v21 = 0;
        Buffer = byte_629120;
        sprintf(&Buffer, "%d", *(_DWORD *)(v13 + 25248));
        sub_49F730(byte_765340, 0, 0, &Buffer, 0);
        sub_49FE20(v9, String1);
        v8 = NumOfElements;
        ++v9;
      }
      v10 = v12;
    }
    while ( v12 < 48 );
LABEL_28:
    sub_476770((int *)this);
  }
  else
  {
    v3 = NumOfElements;
    v14 = NumOfElements;
    v4 = 0;
    v25 = (int *)(this + 432);
    while ( 1 )
    {
      for ( i = 0; i < v3; ++i )
      {
        if ( *(_DWORD *)(dword_75AAD0[i] + 20884) - 1 == v4 )
          break;
      }
      if ( (unsigned __int8)sub_4EED40(dword_75AAD0[i]) && *(_BYTE *)(this + 641) )
      {
        *(_DWORD *)(this + 376) = v4;
        *(_BYTE *)(this + 641) = 0;
      }
      if ( i >= v14 || *(_DWORD *)(dword_75AAD0[i] + 16584) == -1 )
      {
        v7 = sub_49FC20(v4);
      }
      else
      {
        *v25 = i;
        sub_478330((_DWORD *)this, i, byte_765340, String1);
        v6 = (const char *)sub_49FC20(v4);
        String2 = (char *)sub_49FE70(v4);
        if ( !v6 || strcmp(v6, byte_765340) )
          goto LABEL_19;
        v7 = _strcmpi(String1, String2);
      }
      if ( v7 )
        goto LABEL_19;
      ++v4;
      ++v25;
      if ( v4 >= 48 )
        break;
      v3 = NumOfElements;
    }
    sub_476770((int *)this);
  }
}
