char __stdcall sub_5276C0(const char *a1, float a2, char a3)
{
  char v3; // bl
  const char *v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-18h] [ebp-170h]
  int v9; // [esp-18h] [ebp-170h]
  int v10; // [esp-14h] [ebp-16Ch]
  int v11; // [esp-14h] [ebp-16Ch]
  int v12; // [esp+8h] [ebp-150h] BYREF
  char v13[76]; // [esp+Ch] [ebp-14Ch] BYREF
  char Buffer[253]; // [esp+58h] [ebp-100h] BYREF
  __int16 v15; // [esp+155h] [ebp-3h]
  char v16; // [esp+157h] [ebp-1h]

  v3 = 0;
  v12 = 0;
  sub_57B5D0(v13);
  if ( !sub_4AB320((int)&v12, (int)a1, 0, 1) )
    goto LABEL_6;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v15 = 0;
  v16 = 0;
  v4 = (const char *)dword_62A098;
  if ( !dword_62A098 )
    v4 = &byte_629120;
  sprintf(Buffer, "%s%s", v4, a1);
  v12 = 0;
  if ( sub_4AB320((int)&v12, (int)Buffer, 0, 1) )
  {
    nullsub_6(v13);
    return 0;
  }
  else
  {
LABEL_6:
    if ( v12 )
    {
      sub_4D20A0(0);
      v10 = *(_DWORD *)(sub_4AB570() + 32);
      v8 = *(_DWORD *)(sub_4AB570() + 28);
      v6 = sub_4AB570();
      sub_4AAF50(*(float *)&v12, 0, 0, *(_DWORD *)(v12 + 28), *(_DWORD *)(v12 + 32), v6, 0, 0, v8, v10, -1, -1, -1, -1);
      sub_4AB400(0);
      v11 = *(_DWORD *)(sub_4AB570() + 32);
      v9 = *(_DWORD *)(sub_4AB570() + 28);
      v7 = sub_4AB570();
      sub_4AAF50(*(float *)&v12, 0, 0, *(_DWORD *)(v12 + 28), *(_DWORD *)(v12 + 32), v7, 0, 0, v9, v11, -1, -1, -1, -1);
      sub_4AB400(0);
      sub_4D20D0(0, 2, 1048576000, 1);
      sub_57B610(1);
      while ( sub_57B7C0(v13) < a2 )
      {
        if ( a3 )
        {
          sub_455D30((int)&ppvOut, 0.050000001);
          if ( (dword_761FF8 & 1) != 0 && dword_762A04 > 0 )
            break;
        }
      }
      sub_4AB330(v12);
      nullsub_6(&unk_765B00);
      v12 = 0;
      v3 = 1;
    }
    nullsub_6(v13);
    return v3;
  }
}
