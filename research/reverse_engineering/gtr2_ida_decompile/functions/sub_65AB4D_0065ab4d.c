int __thiscall sub_65AB4D(int this)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // eax
  int v5; // eax
  double v6; // st7
  double *v7; // eax
  bool v8; // zf
  int v9; // esi
  char *v10; // eax
  _DWORD *v11; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // [esp-Ch] [ebp-48h]
  _QWORD v15[4]; // [esp+8h] [ebp-34h] BYREF
  int v16; // [esp+2Ch] [ebp-10h]
  int v17; // [esp+30h] [ebp-Ch]
  int v18; // [esp+34h] [ebp-8h]
  unsigned int v19; // [esp+38h] [ebp-4h]

  v2 = (_DWORD *)(this + 632);
  result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
  if ( result >= 0 )
  {
    if ( *v2 == 1 && !strcmp((const char *)(this + 640), "(") )
    {
      result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
      if ( result < 0 )
        goto LABEL_52;
      if ( *(_DWORD *)(this + 632) == 9 )
      {
        v14 = *(_DWORD *)(this + 664);
        v17 = *(_DWORD *)(this + 640);
        result = sub_65E7A1(v14, this + 632);
        if ( result < 0 )
          goto LABEL_52;
        if ( *(_DWORD *)(this + 632) == 1 && !strcmp((const char *)(this + 640), ",") )
        {
          result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
          if ( result < 0 )
            goto LABEL_52;
          if ( *(_DWORD *)(this + 632) == 9 )
          {
            v4 = *(_DWORD *)(this + 640);
            v19 = 0;
            v16 = v4;
            while ( 1 )
            {
              v18 = 0;
              result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
              if ( result < 0 )
                goto LABEL_52;
              if ( *(_DWORD *)(this + 632) != 1 || strcmp((const char *)(this + 640), ",") )
                goto LABEL_48;
              result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
              if ( result < 0 )
                goto LABEL_52;
              if ( *(_DWORD *)(this + 632) == 1 && !strcmp((const char *)(this + 640), "-") )
              {
                v18 = 1;
                result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
                if ( result < 0 )
                  goto LABEL_52;
              }
              v5 = *(_DWORD *)(this + 632);
              if ( v5 == 2 )
                goto LABEL_26;
              if ( v5 != 3 )
                break;
              v6 = (double)*(int *)(this + 640);
              v7 = (double *)&v15[v19];
LABEL_27:
              v8 = v18 == 0;
              *v7 = v6;
              if ( !v8 )
                *v7 = -*v7;
              if ( ++v19 >= 4 )
              {
                result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
                if ( result < 0 )
                  goto LABEL_52;
                if ( *(_DWORD *)(this + 632) != 1 || strcmp((const char *)(this + 640), (const char *)&word_6FBE80) )
                  goto LABEL_48;
                result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
                if ( result < 0 )
                  goto LABEL_52;
                v9 = *(_DWORD *)(this + 632);
                if ( v9 != 12 && v9 != 13 )
                  goto LABEL_48;
                v10 = (char *)operator new(0x30u);
                if ( v10 )
                {
                  *((_DWORD *)v10 + 10) = 0;
                  v19 = (unsigned int)v10;
                }
                else
                {
                  v19 = 0;
                  v10 = 0;
                }
                if ( !v10 )
                {
                  result = -2147024882;
                  goto LABEL_52;
                }
                *(_DWORD *)v10 = v17;
                *((_DWORD *)v10 + 1) = v16;
                qmemcpy(v10 + 8, v15, 0x20u);
                v11 = (_DWORD *)(this + 60);
                v12 = *(_DWORD *)(this + 60);
                if ( v12 )
                {
                  while ( _stricmp(*(const char **)(v12 + 4), *((const char **)v10 + 1)) < 0 )
                  {
                    v11 = (_DWORD *)(*v11 + 40);
                    v12 = *v11;
                    if ( !*v11 )
                      break;
                    v10 = (char *)v19;
                  }
                  v10 = (char *)v19;
                }
                *((_DWORD *)v10 + 10) = *v11;
                *v11 = v10;
                goto LABEL_51;
              }
            }
            if ( v5 != 4 )
            {
              if ( v5 <= 4 || v5 > 8 )
                goto LABEL_48;
              v6 = *(double *)(this + 640);
              v7 = (double *)&v15[v19];
              goto LABEL_27;
            }
LABEL_26:
            v6 = (double)*(unsigned int *)(this + 640);
            v7 = (double *)&v15[v19];
            goto LABEL_27;
          }
        }
      }
    }
LABEL_48:
    v13 = *(_DWORD *)(this + 632);
    if ( v13 != 12 && v13 != 13 )
      sub_65D86A(*(_DWORD *)(this + 620));
LABEL_51:
    result = 0;
  }
LABEL_52:
  *(_DWORD *)(this + 64) = 1;
  return result;
}
