int __usercall sub_490B5A@<eax>(int a1@<eax>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
  int v5; // edi
  int v6; // ebx
  int result; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  int v14; // eax
  const char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // [esp-10h] [ebp-114h]
  const char *v20; // [esp-10h] [ebp-114h]
  const char *v21; // [esp-10h] [ebp-114h]
  const char *v22; // [esp-10h] [ebp-114h]
  const char *v23; // [esp-10h] [ebp-114h]
  int v24; // [esp-10h] [ebp-114h]
  CHAR v25; // [esp+0h] [ebp-104h] BYREF
  __int16 v26; // [esp+1h] [ebp-103h]
  char v27; // [esp+3h] [ebp-101h]
  char Buffer[256]; // [esp+4h] [ebp-100h] BYREF

  LOBYTE(a1) = BYTE1(a2) + a1;
  *(_DWORD *)(a3 + 8 * a4 - 1) -= a1;
  v26 = 0;
  v27 = 0;
  v25 = byte_629120;
  v5 = sub_57AE50(aSeasonraces);
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 176))(a2);
  result = sub_49FEC0(a2);
  if ( v6 )
  {
    result = sub_49F640(&v25);
    if ( v5 )
    {
      result = sub_57A720((char *)(v6 + 260));
      if ( result )
      {
        v8 = sub_57A720(aTrackType);
        if ( v8 )
        {
          v19 = (const char *)sub_57A6D0(v8);
          v9 = (const char *)sub_49D690(0);
          sprintf(Buffer, "%s%s%s", v9, &v25, v19);
          sub_49F730(Buffer, 0, 0, 0, 0);
        }
        v10 = sub_57A720(aLength);
        if ( v10 )
        {
          v20 = (const char *)sub_57A6D0(v10);
          v11 = (const char *)sub_49D690(1);
          sprintf(Buffer, "%s%s%s", v11, &v25, v20);
          sub_49F730(Buffer, 0, 0, 0, 0);
        }
        v12 = sub_57A720(aBanking_0);
        if ( v12 )
        {
          v21 = (const char *)sub_57A6D0(v12);
          v13 = (const char *)sub_49D690(2);
          sprintf(Buffer, "%s%s%s", v13, &v25, v21);
          sub_49F730(Buffer, 0, 0, 0, 0);
        }
        v14 = sub_57A720(aCapacity_0);
        if ( v14 )
        {
          v22 = (const char *)sub_57A6D0(v14);
          v15 = (const char *)sub_49D690(3);
          sprintf(Buffer, "%s%s%s", v15, &v25, v22);
          sub_49F730(Buffer, 0, 0, 0, 0);
        }
        v16 = sub_57A720(aTrackRecord_0);
        if ( v16 )
        {
          v23 = (const char *)sub_57A6D0(v16);
          v17 = (const char *)sub_49D690(4);
          sprintf(Buffer, "%s%s%s", v17, &v25, v23);
          sub_49F730(Buffer, 0, 0, 0, 0);
        }
        sub_4CE0F0(*(_DWORD *)dword_7689CC);
        v24 = *(_DWORD *)dword_768B70;
        v18 = (const char *)sub_49D690(5);
        sprintf(Buffer, "%s%s%d", v18, &v25, v24);
        return sub_49F730(Buffer, 0, 0, 0, 0);
      }
    }
  }
  return result;
}
