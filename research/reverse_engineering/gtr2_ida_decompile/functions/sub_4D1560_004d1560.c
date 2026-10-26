int __userpurge sub_4D1560@<eax>(int *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5, int a6)
{
  int v8; // edi
  int v9; // ebp
  _BYTE *v10; // eax
  int v11; // edx
  const CHAR ***v12; // eax
  const CHAR **v13; // eax
  const CHAR *v14; // eax
  int v15; // edi
  char v16; // bl
  _BYTE *v17; // ecx
  int v18; // eax
  int v19; // ecx
  const CHAR *v20; // eax
  int v21; // eax
  int v22; // [esp-8h] [ebp-3Ch]
  int v23; // [esp+0h] [ebp-34h]
  int v24; // [esp+4h] [ebp-30h]
  int v25; // [esp+8h] [ebp-2Ch]
  _BYTE v26[4]; // [esp+Ch] [ebp-28h] BYREF
  int v27; // [esp+10h] [ebp-24h] BYREF
  int v28; // [esp+14h] [ebp-20h]
  int v29; // [esp+18h] [ebp-1Ch]
  int v30; // [esp+1Ch] [ebp-18h] BYREF
  int v31; // [esp+20h] [ebp-14h]
  _BYTE v32[16]; // [esp+24h] [ebp-10h] BYREF

  if ( !*((_BYTE *)a1 + 792) )
    return 0;
  v30 = a3;
  v29 = a4;
  v8 = 0;
  v9 = 0;
  if ( a6 > 0 )
  {
    v28 = a2;
    while ( 2 )
    {
      switch ( *(_WORD *)(a5 + 2 * v9) )
      {
        case 1:
          v10 = (_BYTE *)a1[199];
          if ( v10 )
            *v10 = 0;
          goto LABEL_8;
        case 0xE:
          goto LABEL_25;
        case 0x1C:
LABEL_8:
          if ( !*((_BYTE *)a1 + 273) )
          {
            v11 = *a1;
            *((_BYTE *)a1 + 268) = 0;
            (*(void (__thiscall **)(int *, int, int, int))(v11 + 168))(a1, v28, v29, v30);
            sub_4DF030(0);
            if ( a1[20] > 0 )
            {
              v12 = (const CHAR ***)a1[17];
              if ( v12 )
              {
                v13 = *v12;
                if ( v13 )
                {
                  v14 = *v13;
                  if ( !v14 )
                    v14 = WindowName;
                  v15 = sub_4DEF00(a1[12], v14);
                  if ( v15 )
                  {
                    (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 132))(v15);
                    (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 136))(v15);
                  }
                }
              }
            }
          }
          (*(void (__thiscall **)(int *))(*a1 + 168))(a1);
          goto LABEL_28;
        case 0x37:
        case 0x4A:
        case 0x4E:
          goto LABEL_29;
        default:
          v27 = *(unsigned __int16 *)(a5 + 2 * v9);
          v16 = sub_45E670();
          LOBYTE(v31) = v16;
          if ( !(unsigned __int8)((int (__thiscall *)(int *, int))byte_4CE6B0)(a1, v31) )
            goto LABEL_29;
          if ( a1[200] - a1[199] < a1[201] - 1 )
          {
            *(_BYTE *)a1[200] = v16;
            v17 = (_BYTE *)(a1[200] + 1);
            a1[200] = (int)v17;
            *v17 = 0;
            if ( a1[202] )
            {
              v18 = a1[61];
              if ( v18 )
              {
                v19 = a1[12];
                if ( v19 )
                {
                  v20 = *(const CHAR **)(v18 + 64);
                  if ( !v20 )
                    v20 = WindowName;
                  sub_4DF1B0(v19, v20);
                  sub_4E08C0(a1[12], a1[202], v32, &v30, 1, v25);
                  sub_4E08C0(a1[12], a1[199], &v27, v26, 1, v22);
                  if ( v23 > v24 )
                  {
LABEL_25:
                    v21 = a1[200];
                    if ( v21 != a1[199] )
                      a1[200] = v21 - 1;
                    *(_BYTE *)a1[200] = 0;
                  }
                }
              }
            }
          }
LABEL_28:
          v8 = 1;
LABEL_29:
          if ( ++v9 >= a5 )
            return v8;
          continue;
      }
    }
  }
  return v8;
}
