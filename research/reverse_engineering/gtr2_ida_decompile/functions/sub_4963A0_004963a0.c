int __userpurge sub_4963A0@<eax>(
        _DWORD *a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5,
        int a6,
        int a7,
        int a8)
{
  const char *v9; // eax
  int v10; // eax
  int v11; // ecx
  bool v12; // zf
  int v13; // eax
  const CHAR *v14; // eax
  int v15; // eax
  const CHAR *v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // eax
  int v20; // edi
  int v21; // edi
  int v22; // eax
  _DWORD *v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // eax
  int v27; // ebp
  __int64 v28; // rax
  const CHAR *v29; // eax
  const CHAR *v30; // eax
  int v31; // ecx
  __int64 v32; // rax
  int v33; // ebx
  int v35; // [esp+0h] [ebp-64h]
  _DWORD *v36; // [esp+14h] [ebp-50h]
  const CHAR *v37; // [esp+18h] [ebp-4Ch]
  _DWORD *v38; // [esp+18h] [ebp-4Ch]
  _DWORD *v39; // [esp+20h] [ebp-44h]
  int v40; // [esp+30h] [ebp-34h] BYREF
  int v41; // [esp+34h] [ebp-30h] BYREF
  int v42; // [esp+38h] [ebp-2Ch]
  int v43; // [esp+40h] [ebp-24h]
  int v44; // [esp+44h] [ebp-20h]
  int v45; // [esp+4Ch] [ebp-18h]
  _BYTE v46[4]; // [esp+50h] [ebp-14h] BYREF
  _BYTE v47[12]; // [esp+54h] [ebp-10h] BYREF

  v9 = (const char *)a1[40];
  if ( !v9 )
    v9 = WindowName;
  if ( !strlen(v9) )
    return -1;
  v10 = sub_4CD660(a1);
  v11 = a1[61];
  if ( v11 )
  {
    switch ( v10 )
    {
      case 0:
      case 2:
        v12 = (unsigned __int8)sub_4CD650(a1) == 0;
        v13 = a1[61];
        if ( v12 )
        {
          v14 = *(const CHAR **)(v13 + 64);
          if ( v14 )
            goto LABEL_20;
        }
        else
        {
          v14 = *(const CHAR **)(v13 + 80);
          if ( v14 )
            goto LABEL_20;
        }
        goto LABEL_18;
      case 1:
      case 3:
        sub_4CD650(a1);
        v15 = a1[61];
        goto LABEL_12;
      case 4:
        v12 = (unsigned __int8)sub_4CD650(a1) == 0;
        v15 = a1[61];
        if ( v12 )
        {
LABEL_12:
          v14 = *(const CHAR **)(v15 + 80);
          if ( v14 )
            goto LABEL_20;
        }
        else
        {
          v14 = *(const CHAR **)(v15 + 72);
          if ( v14 )
            goto LABEL_20;
        }
LABEL_18:
        v14 = WindowName;
LABEL_19:
        if ( !v14 )
          return 0;
LABEL_20:
        sub_4DF1B0(a1[12], v14);
        v16 = (const CHAR *)a1[40];
        if ( !v16 )
          v16 = WindowName;
        sub_4E08C0(a1[12], v16, v47, v46, 1, v45);
        if ( v44 > 0 )
        {
          v17 = v43;
          if ( v43 > 0 )
          {
            v18 = a1[39];
            if ( !v18 || !a1[38] )
              return -1;
            v19 = a1[69];
            v42 = a2;
            v41 = a3;
            v40 = a4;
            if ( v19 )
            {
              if ( v19 != 2 )
              {
LABEL_37:
                v27 = a1[1];
                v28 = a1[2] - v27 - v17;
                v23 = (_DWORD *)(v27 + (((int)v28 - HIDWORD(v28)) >> 1));
                goto LABEL_38;
              }
              v24 = *(_DWORD *)(v18 + 12);
              if ( (*(int (__thiscall **)(_DWORD *, int, int, int))(*a1 + 12))(a1, v40, v41, v42) - v24 >= 0 )
                (*(int (__thiscall **)(_DWORD *))(*a1 + 12))(a1);
              v25 = *(_DWORD *)(a1[39] + 4);
              if ( (*(int (__thiscall **)(_DWORD *))(*a1 + 16))(a1) - v25 >= 0 )
              {
                v26 = (*(int (__thiscall **)(_DWORD *))(*a1 + 16))(a1);
                v17 = v43;
                v23 = (_DWORD *)(v26 - v43);
                goto LABEL_38;
              }
            }
            else
            {
              v20 = *(_DWORD *)(v18 + 12);
              if ( (*(int (__thiscall **)(_DWORD *, int, int, int))(*a1 + 4))(a1, v40, v41, v42) - v20 >= 0 )
                (*(void (__thiscall **)(_DWORD *))(*a1 + 4))(a1);
              v21 = *(_DWORD *)(a1[39] + 4);
              if ( (*(int (__thiscall **)(_DWORD *))(*a1 + 8))(a1) - v21 >= 0 )
              {
                v22 = (*(int (__thiscall **)(_DWORD *))(*a1 + 8))(a1);
                v17 = v43;
                v23 = (_DWORD *)v22;
LABEL_38:
                v29 = (const CHAR *)a1[40];
                if ( !v29 )
                  v29 = WindowName;
                v39 = (_DWORD *)((char *)v23 + v17);
                v37 = v29;
                sub_4E0730(a1[12]);
                v30 = (const CHAR *)a1[44];
                if ( !v30 )
                  v30 = WindowName;
                sub_4E08C0(a1[12], v30, &v40, &v41, 1, v37);
                v31 = a1[3];
                v32 = a1[4] - v31 - (int)v39;
                v33 = v31 + (((int)v32 - HIDWORD(v32)) >> 1);
                if ( a1[69] == 2 )
                {
                  v35 = (*(int (__thiscall **)(_DWORD *))(*a1 + 12))(a1);
                  (*(int (__thiscall **)(_DWORD *))(*a1 + 12))(a1);
                }
                else
                {
                  v35 = (int)v39 + v33;
                }
                sub_4E0730(a1[12]);
                *v36 = v23;
                *v38 = (char *)v23 + v35;
                *v23 = v33;
                *v39 = v33 + 1;
                return 0;
              }
            }
            v17 = v43;
            goto LABEL_37;
          }
        }
        break;
      default:
        v14 = *(const CHAR **)(v11 + 80);
        if ( !v14 )
          goto LABEL_18;
        goto LABEL_19;
    }
  }
  return 0;
}
