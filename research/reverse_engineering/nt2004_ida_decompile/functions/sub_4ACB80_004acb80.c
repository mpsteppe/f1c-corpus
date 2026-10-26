int __thiscall sub_4ACB80(int this)
{
  int v2; // ebx
  int v3; // ebp
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  char *v7; // eax
  int v8; // eax
  char *v9; // eax
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  Concurrency::details::VirtualProcessor *v13; // edi
  CHAR *v14; // eax
  CHAR *v15; // eax
  char *v16; // eax
  int v17; // eax
  Concurrency::details::VirtualProcessor *v18; // edi
  CHAR *v19; // eax
  CHAR *v20; // eax
  int v21; // ecx
  int v22; // ecx
  char *v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  int v32; // ecx
  int v34; // [esp+10h] [ebp-4h]

  sub_4AE700();
  if ( *(_DWORD *)(this + 40) != 2 )
    *(_DWORD *)(this + 40) = 2;
  sub_4AE730(this);
  v2 = *(_DWORD *)(this + 88);
  v3 = *(_DWORD *)(this + 392);
  v4 = *(_DWORD *)(this + 24);
  v34 = *(_DWORD *)(this + 92);
  v5 = sub_4AE7A0(this);
  *(_DWORD *)(this + 112) = v5;
  switch ( v5 )
  {
    case 1:
    case 2:
    case 4:
    case 6:
    case 9:
      *(_DWORD *)(this + 392) = 0;
      break;
    default:
      break;
  }
  if ( !*(_DWORD *)(this + 392) )
    *(_DWORD *)(this + 392) = sub_4AC170((_DWORD *)this, 0, 0);
  if ( v3 != *(_DWORD *)(this + 392) && v3 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 56))(v3);
  if ( v4 != *(_DWORD *)(this + 24) && v4 )
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v4 + 32))(v4, v2, v34);
  if ( v3 && v3 == *(_DWORD *)(this + 392) )
  {
    if ( *(float *)(this + 288) + *(float *)(this + 284) > *(float *)(this + 280) )
      *(float *)(this + 280) = *(float *)(this + 268) + *(float *)(this + 280);
  }
  else
  {
    *(_DWORD *)(this + 280) = 0;
  }
  v6 = *(_DWORD *)(this + 392);
  if ( v6 )
  {
    switch ( *(_DWORD *)(this + 112) )
    {
      case 1:
      case 2:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 132))(v6) )
        {
          v9 = sub_49C940(*(_DWORD **)(this + 392));
          v10 = sub_4ADDB0(v9);
          if ( v10 )
            sub_4ADF10(v10);
        }
        if ( *(_DWORD *)(this + 112) == 2 )
          goto LABEL_24;
        break;
      case 3:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 136))(v6) )
        {
          v16 = sub_49C960(*(_DWORD **)(this + 392));
          v17 = sub_4ADDB0(v16);
          if ( v17 )
            sub_4ADF10(v17);
        }
        v18 = sub_4AC170((_DWORD *)this, 0, 0);
        if ( v18 && *(_DWORD *)(this + 380) )
        {
          v19 = *(CHAR **)(this + 372);
          if ( !v19 )
            v19 = &byte_629120;
          if ( (*(unsigned __int8 (__thiscall **)(Concurrency::details::VirtualProcessor *, CHAR *))(*(_DWORD *)v18 + 108))(
                 v18,
                 v19) )
          {
            v20 = *(CHAR **)(this + 372);
            if ( !v20 )
              v20 = &byte_629120;
            (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *, CHAR *, _DWORD, _DWORD))(*(_DWORD *)v18 + 112))(
              v18,
              v20,
              *(_DWORD *)(this + 380),
              *(_DWORD *)(this + 384));
          }
        }
        goto LABEL_41;
      case 4:
        v21 = *(_DWORD *)(this + 24);
        if ( v4 != v21 )
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v21 + 28))(v21, v2, v34);
        v22 = *(_DWORD *)(this + 392);
        if ( v3 == v22 || (*(int (__thiscall **)(int))(*(_DWORD *)v22 + 52))(v22) )
          break;
        v23 = sub_49C980(*(_DWORD **)(this + 392));
LABEL_62:
        v24 = sub_4ADDB0(v23);
        if ( v24 )
          sub_4ADF10(v24);
        break;
      case 5:
      case 8:
        if ( *(float *)(this + 272) == 0.0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 60))(v6);
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 392) + 140))(*(_DWORD *)(this + 392));
        v23 = sub_49C9A0(*(_DWORD **)(this + 392));
        goto LABEL_62;
      case 6:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 76))(v6) )
        {
          v7 = sub_49C940(*(_DWORD **)(this + 392));
          v8 = sub_4ADDB0(v7);
          if ( v8 )
            sub_4ADF10(v8);
        }
        if ( *(_DWORD *)(this + 112) == 2 )
LABEL_24:
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 392) + 72))(*(_DWORD *)(this + 392));
        break;
      case 7:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 80))(v6) )
        {
          v11 = sub_49C960(*(_DWORD **)(this + 392));
          v12 = sub_4ADDB0(v11);
          if ( v12 )
            sub_4ADF10(v12);
        }
        v13 = sub_4AC170((_DWORD *)this, 0, 0);
        if ( v13 && *(_DWORD *)(this + 380) )
        {
          v14 = *(CHAR **)(this + 372);
          if ( !v14 )
            v14 = &byte_629120;
          if ( (*(unsigned __int8 (__thiscall **)(Concurrency::details::VirtualProcessor *, CHAR *))(*(_DWORD *)v13 + 108))(
                 v13,
                 v14) )
          {
            v15 = *(CHAR **)(this + 372);
            if ( !v15 )
              v15 = &byte_629120;
            (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *, CHAR *, _DWORD, _DWORD))(*(_DWORD *)v13 + 112))(
              v13,
              v15,
              *(_DWORD *)(this + 380),
              *(_DWORD *)(this + 384));
          }
        }
LABEL_41:
        sub_4AE680(this);
        break;
      case 0xC:
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 100))(v6);
        break;
      case 0xD:
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 104))(v6);
        break;
      default:
        break;
    }
  }
  for ( *(_DWORD *)(this + 408) = 0; ; ++*(_DWORD *)(this + 408) )
  {
    v25 = *(_DWORD *)(this + 408);
    if ( v25 >= ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
      break;
    *(_WORD *)(this + 2 * v25 + 412) = word_762A08[v25];
  }
  v26 = *(_DWORD *)(this + 32);
  LOBYTE(v34) = 0;
  if ( v26 && *(int *)(this + 408) > 0 )
    LOBYTE(v34) = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v26 + 68))(
                    v26,
                    this + 412,
                    *(_DWORD *)(this + 408));
  sub_4AC050((_DWORD *)this, *(_DWORD *)(this + 408), this + 412, v34);
  if ( dword_608F60 == 5 )
    sub_4ACB20((_DWORD *)this);
  if ( *(_DWORD *)(this + 112) == 5 )
    *(float *)(this + 272) = *(float *)(this + 268) + *(float *)(this + 272);
  else
    *(_DWORD *)(this + 272) = 0;
  sub_4AB930(this);
  v27 = *(_DWORD *)(this + 88);
  v28 = *(_DWORD *)(this + 92);
  *(_DWORD *)(this + 116) = *(_DWORD *)(this + 84);
  v29 = *(_DWORD *)(this + 96);
  *(_DWORD *)(this + 124) = v28;
  v30 = *(_DWORD *)(this + 104);
  *(_DWORD *)(this + 120) = v27;
  v31 = *(_DWORD *)(this + 100);
  *(_DWORD *)(this + 128) = v29;
  v32 = *(_DWORD *)(this + 112);
  *(_DWORD *)(this + 136) = v30;
  *(_DWORD *)(this + 132) = v31;
  *(_DWORD *)(this + 144) = v32;
  return 0;
}
