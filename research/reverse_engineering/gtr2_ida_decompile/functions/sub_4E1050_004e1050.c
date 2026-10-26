// bad sp value at call has been detected, the output may be wrong!
int __usercall sub_4E1050@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  double v4; // st7
  int v6; // ecx
  int v7; // ebx
  int v8; // ebp
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  const CHAR *v12; // eax
  int v13; // edi
  const CHAR *v14; // eax
  int v15; // edi
  const CHAR *v16; // eax
  int v17; // eax
  int v18; // edi
  const CHAR *v19; // eax
  const CHAR *v20; // eax
  const CHAR *v21; // eax
  int v22; // eax
  int v23; // edi
  const CHAR *v24; // eax
  const CHAR *v25; // eax
  int v26; // ecx
  int v27; // ecx
  const CHAR *v28; // eax
  int v29; // eax
  int v34; // [esp+28h] [ebp-4h]

  v4 = dbl_FB1D08;
  v6 = *(_DWORD *)(a1 + 40);
  *(float *)(a1 + 268) = dbl_FB1D08;
  *(float *)(a1 + 264) = v4 + *(float *)(a1 + 264);
  if ( v6 != 2 )
    *(_DWORD *)(a1 + 40) = 2;
  sub_4DF380((_DWORD *)a1);
  v7 = *(_DWORD *)(a1 + 88);
  v8 = *(_DWORD *)(a1 + 392);
  v9 = *(_DWORD *)(a1 + 24);
  v34 = *(_DWORD *)(a1 + 92);
  v10 = sub_4DE470(a1);
  *(_DWORD *)(a1 + 112) = v10;
  switch ( v10 )
  {
    case 1:
    case 2:
    case 4:
    case 6:
    case 9:
      *(_DWORD *)(a1 + 392) = 0;
      break;
    default:
      break;
  }
  if ( !*(_DWORD *)(a1 + 392) )
    *(_DWORD *)(a1 + 392) = sub_4DFAA0((_DWORD *)a1, v9, a1, 0, 0);
  if ( v8 != *(_DWORD *)(a1 + 392) && v8 )
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v8 + 56))(v8, a4, a3);
  if ( v9 != *(_DWORD *)(a1 + 24) && v9 )
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 32))(v9, v7, v34);
  if ( v8 && v8 == *(_DWORD *)(a1 + 392) )
  {
    if ( *(float *)(a1 + 288) + *(float *)(a1 + 284) > *(float *)(a1 + 280) )
      *(float *)(a1 + 280) = *(float *)(a1 + 280) + *(float *)(a1 + 268);
  }
  else
  {
    *(_DWORD *)(a1 + 280) = 0;
  }
  v11 = *(_DWORD *)(a1 + 392);
  if ( v11 )
  {
    switch ( *(_DWORD *)(a1 + 112) )
    {
      case 1:
      case 2:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 132))(v11) )
        {
          v14 = sub_4CF840(*(_DWORD **)(a1 + 392));
          v15 = sub_4DE300((void *)a1, (int)v14);
          if ( v15 )
          {
            sub_4DE350((_DWORD *)a1);
            if ( byte_B708D0 == 1 )
              sub_4E05F0(v15);
          }
        }
        if ( *(_DWORD *)(a1 + 112) == 2 )
          goto LABEL_25;
        return off_16C98E0();
      case 3:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 136))(v11) )
        {
          v21 = sub_4CF860(*(_DWORD **)(a1 + 392));
          v22 = sub_4DE300((void *)a1, (int)v21);
          if ( v22 )
          {
            if ( byte_B708D0 == 1 )
              sub_4E05F0(v22);
          }
        }
        v23 = sub_4DFAA0((_DWORD *)a1, v9, a1, 0, 0);
        if ( v23 && *(_DWORD *)(a1 + 380) )
        {
          v24 = *(const CHAR **)(a1 + 372);
          if ( !v24 )
            v24 = WindowName;
          if ( (*(unsigned __int8 (__thiscall **)(int, const CHAR *))(*(_DWORD *)v23 + 108))(v23, v24) )
          {
            v25 = *(const CHAR **)(a1 + 372);
            if ( !v25 )
              v25 = WindowName;
            (*(void (__thiscall **)(int, const CHAR *, _DWORD, _DWORD))(*(_DWORD *)v23 + 112))(
              v23,
              v25,
              *(_DWORD *)(a1 + 380),
              *(_DWORD *)(a1 + 384));
          }
        }
        goto LABEL_44;
      case 4:
        v26 = *(_DWORD *)(a1 + 24);
        if ( v9 != v26 )
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v26 + 28))(v26, v7, a2);
        v27 = *(_DWORD *)(a1 + 392);
        if ( v8 == v27 || (*(int (__thiscall **)(int))(*(_DWORD *)v27 + 52))(v27) )
          return off_16C98E0();
        v28 = sub_4CF880(*(_DWORD **)(a1 + 392));
LABEL_66:
        v29 = sub_4DE300((void *)a1, (int)v28);
        if ( v29 && byte_B708D0 == 1 )
          sub_4E05F0(v29);
        break;
      case 5:
      case 8:
        if ( *(float *)(a1 + 272) == 0.0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 60))(v11);
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 392) + 140))(*(_DWORD *)(a1 + 392));
        v28 = sub_4CF8A0(*(_DWORD **)(a1 + 392));
        goto LABEL_66;
      case 6:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 76))(v11) )
        {
          v12 = sub_4CF840(*(_DWORD **)(a1 + 392));
          v13 = sub_4DE300((void *)a1, (int)v12);
          if ( v13 )
          {
            sub_4DE350((_DWORD *)a1);
            if ( byte_B708D0 == 1 )
              sub_4E05F0(v13);
          }
        }
        if ( *(_DWORD *)(a1 + 112) == 2 )
LABEL_25:
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 392) + 72))(*(_DWORD *)(a1 + 392));
        return off_16C98E0();
      case 7:
        if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 80))(v11) )
        {
          v16 = sub_4CF860(*(_DWORD **)(a1 + 392));
          v17 = sub_4DE300((void *)a1, (int)v16);
          if ( v17 )
          {
            if ( byte_B708D0 == 1 )
              sub_4E05F0(v17);
          }
        }
        v18 = sub_4DFAA0((_DWORD *)a1, v9, a1, 0, 0);
        if ( v18 && *(_DWORD *)(a1 + 380) )
        {
          v19 = *(const CHAR **)(a1 + 372);
          if ( !v19 )
            v19 = WindowName;
          if ( (*(unsigned __int8 (__thiscall **)(int, const CHAR *))(*(_DWORD *)v18 + 108))(v18, v19) )
          {
            v20 = *(const CHAR **)(a1 + 372);
            if ( !v20 )
              v20 = WindowName;
            (*(void (__thiscall **)(int, const CHAR *, _DWORD, _DWORD))(*(_DWORD *)v18 + 112))(
              v18,
              v20,
              *(_DWORD *)(a1 + 380),
              *(_DWORD *)(a1 + 384));
          }
        }
LABEL_44:
        sub_4DE3E0();
        return off_16C98E0();
      case 0xC:
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 100))(v11);
        return off_16C98E0();
      case 0xD:
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 104))(v11);
        return off_16C98E0();
      default:
        return off_16C98E0();
    }
  }
  return off_16C98E0();
}
