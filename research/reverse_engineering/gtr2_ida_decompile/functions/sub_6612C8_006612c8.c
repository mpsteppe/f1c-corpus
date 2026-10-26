void __thiscall sub_6612C8(char *Format, int a2, unsigned int a3)
{
  unsigned int v3; // kr00_4
  int v4; // esi
  char *v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  unsigned int v13; // ecx
  int *v14; // edx
  int *v15; // eax
  int v16; // ebx
  unsigned int v17; // ecx
  int *v18; // edx
  int *v19; // eax
  int v20; // ebx
  int *v21; // eax
  int v22; // eax
  int v23; // eax
  _DWORD *v24; // eax
  double v25; // st7
  double v26; // st7
  int v27; // eax
  int v28; // [esp-4h] [ebp-54h]
  char *v29; // [esp+0h] [ebp-50h] BYREF
  int v30; // [esp+10h] [ebp-40h] BYREF
  _DWORD *v31; // [esp+14h] [ebp-3Ch]

  v5 = Format;
  v6 = 0;
  if ( !*((_DWORD *)Format + 20) )
  {
    v7 = a3;
    if ( a3 )
    {
      while ( 1 )
      {
        v8 = *((_DWORD *)v5 + 13);
        --v7;
        if ( !v8 )
          break;
        *(&v30 + v7) = *(_DWORD *)(v8 + 8);
        *((_DWORD *)v5 + 13) = *(_DWORD *)(v8 + 12);
        *(_DWORD *)(v8 + 8) = 0;
        *(_DWORD *)(v8 + 12) = 0;
        if ( !v7 )
          goto LABEL_5;
      }
      sub_65DD1F(*(_DWORD **)v5, (int)(v5 + 16), 0, "internal error: stack underflow");
      *((_DWORD *)v5 + 19) = 1;
    }
    else
    {
LABEL_5:
      switch ( a2 )
      {
        case 0:
        case 6:
          v6 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 5:
        case 10:
        case 23:
        case 25:
        case 29:
        case 35:
        case 41:
        case 42:
        case 47:
        case 48:
          v6 = (_DWORD *)v30;
          break;
        case 3:
          v6 = (_DWORD *)sub_67ECDC(v31, v30);
          break;
        case 7:
          v6 = 0;
          if ( !*((_DWORD *)v5 + 29) )
            *((_DWORD *)v5 + 29) = *(_DWORD *)(v30 + 24);
          break;
        case 8:
          v6 = (_DWORD *)v30;
          goto LABEL_16;
        case 9:
          v9 = *((_DWORD *)v5 + 14);
          v6 = (_DWORD *)v30;
          if ( v9 < 6 || v9 > 9 )
          {
            v29 = "instruction coissue is not supported in this shader version";
            v28 = 2027;
            goto LABEL_24;
          }
          *(_DWORD *)(v30 + 84) = 1;
LABEL_16:
          sub_65F931(v5, v6);
          break;
        case 11:
          v10 = *((_DWORD *)v5 + 14);
          v6 = v31;
          if ( v10 >= 2 && v10 <= 5 || v10 >= 11 && v10 <= 14 )
          {
            v31[16] = v30;
            break;
          }
          v29 = "instruction predication is not supported in this shader version";
          v28 = 2028;
LABEL_24:
          v11 = (int)(v6 + 4);
          goto LABEL_61;
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
          v6 = (_DWORD *)v30;
          v30 = 0;
          if ( a3 > 1 )
          {
            v12 = v31;
            v31 = 0;
            v6[15] = v12;
          }
          v13 = 2;
          if ( a3 > 2 )
          {
            v14 = v6 + 17;
            do
            {
              v15 = &v30 + v13;
              v16 = *v15;
              *v15 = 0;
              *v14 = v16;
              ++v13;
              ++v14;
            }
            while ( v13 < a3 );
          }
          break;
        case 21:
        case 22:
          v6 = (_DWORD *)v30;
          v30 = 0;
          v17 = 1;
          if ( a3 > 1 )
          {
            v18 = v6 + 17;
            do
            {
              v19 = &v30 + v17;
              v20 = *v19;
              *v19 = 0;
              *v18 = v20;
              ++v17;
              ++v18;
            }
            while ( v17 < a3 );
          }
          break;
        case 24:
          v6 = (_DWORD *)v30;
          if ( *(_DWORD *)(v30 + 28) )
          {
            sub_65DD1F(*(_DWORD **)v5, (int)(v5 + 16), 2022, "scalar registers cannot be masked");
            *((_DWORD *)v5 + 19) = 1;
            v6[8] = 983040;
          }
          else
          {
            v6[8] = sub_65F6B1(v5, (int)(v31 + 4));
          }
          break;
        case 26:
          v6 = (_DWORD *)v30;
          if ( *(_DWORD *)(v30 + 20) )
          {
            v29 = "not cannot be used with other modifiers";
            v28 = 2018;
            goto LABEL_60;
          }
          *(_DWORD *)(v30 + 20) = 218103808;
          break;
        case 27:
          v6 = (_DWORD *)v30;
          v21 = *(int **)(v30 + 20);
          if ( v21 )
          {
            if ( v21 == &dword_2000000 )
            {
              *(_DWORD *)(v30 + 20) = 50331648;
            }
            else if ( v21 == (int *)0x4000000 )
            {
              *(_DWORD *)(v30 + 20) = 83886080;
            }
            else if ( v21 == (int *)117440512 )
            {
              *(_DWORD *)(v30 + 20) = 0x8000000;
            }
            else
            {
              if ( v21 == (int *)150994944 || v21 == (int *)167772160 )
              {
                v29 = "negate and divide modifiers cannot be combined";
                v28 = 2011;
                goto LABEL_60;
              }
              if ( v21 == (int *)184549376 )
                *(_DWORD *)(v30 + 20) = 201326592;
            }
          }
          else
          {
            *(_DWORD *)(v30 + 20) = &dword_1000000;
          }
          break;
        case 28:
          v6 = v31;
          if ( *(_DWORD *)(v30 + 24) != 1 )
          {
            v29 = "invalid complement expression";
            v28 = 2010;
            goto LABEL_60;
          }
          v22 = *((_DWORD *)v5 + 14);
          if ( v22 < 6 || v22 > 9 )
          {
            v29 = "complement is not supported in this shader version";
            v28 = 2029;
            goto LABEL_60;
          }
          if ( v31[5] )
          {
            v29 = "complement cannot be used with other modifiers";
            v28 = 2012;
            goto LABEL_60;
          }
          v31[5] = 100663296;
          break;
        case 30:
          v6 = (_DWORD *)v30;
          if ( *(_DWORD *)(v30 + 28) )
          {
            sub_65DD1F(*(_DWORD **)v5, (int)(v5 + 16), 2022, "scalar registers cannot be swizzled");
            *((_DWORD *)v5 + 19) = 1;
            v6[9] = &unk_E40000;
          }
          else
          {
            v6[9] = sub_65F766(v5, (int)(v31 + 4));
          }
          break;
        case 33:
          v29 = 0;
          goto LABEL_68;
        case 34:
          v29 = (char *)v31;
LABEL_68:
          v23 = sub_660D48((_DWORD **)v5, v30 + 16, (int)v29);
          goto LABEL_94;
        case 36:
          v24 = v31;
          v6 = (_DWORD *)v30;
          *(_DWORD *)(v30 + 24) += v31[6];
          if ( v6[10] )
          {
            if ( v24[10] )
            {
              v29 = "only one address register reference allowed in a relative address expression";
              v28 = 2009;
LABEL_60:
              v11 = (int)(v5 + 16);
LABEL_61:
              sub_65DD1F(*(_DWORD **)v5, v11, v28, v29);
              *((_DWORD *)v5 + 19) = 1;
            }
          }
          else
          {
            v6[10] = v24[10];
            v24[10] = 0;
          }
          break;
        case 37:
          v6 = 0;
          if ( !sub_65B229(44) )
            goto LABEL_98;
          v23 = sub_680B7C(0, 0, 0, 0, v30);
          goto LABEL_94;
        case 38:
          v6 = 0;
          if ( !sub_65B229(44) )
            goto LABEL_98;
          v23 = sub_680B7C(0, 0, *(_DWORD *)(v30 + 24), 0, 0);
          goto LABEL_94;
        case 39:
          if ( sub_65B229(48) )
            v6 = (_DWORD *)sub_67EF22(v5 + 16);
          else
            v6 = 0;
          sub_65ED96(v5, (int)v6);
          v6[4] = 2;
          v6[6] = 1;
          break;
        case 40:
          if ( sub_65B229(48) )
            v6 = (_DWORD *)sub_67EF22(v5 + 16);
          else
            v6 = 0;
          sub_65ED96(v5, (int)v6);
          v6[6] = 0;
          v6[4] = 2;
          break;
        case 43:
          v6 = (_DWORD *)v30;
          *(_DWORD *)(v30 + 24) = -*(_DWORD *)(v30 + 24);
          break;
        case 44:
        case 45:
          v6 = (_DWORD *)v30;
          v25 = (double)*(unsigned int *)(v30 + 24);
          *(_DWORD *)(v30 + 16) = 5;
          goto LABEL_88;
        case 46:
          v6 = (_DWORD *)v30;
          v26 = (double)*(unsigned int *)(v30 + 24);
          *(_DWORD *)(v30 + 16) = 5;
          goto LABEL_91;
        case 49:
          v6 = (_DWORD *)v30;
          v26 = *(double *)(v30 + 24);
LABEL_91:
          v25 = -v26;
LABEL_88:
          *((double *)v6 + 3) = v25;
          break;
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
          if ( !sub_65B229(96) )
            goto LABEL_97;
          v23 = sub_680AF5(v5 + 16, *((_DWORD *)v5 + 16), *((_DWORD *)v5 + 17), *((_DWORD *)v5 + 18));
          goto LABEL_94;
        case 61:
        case 62:
        case 63:
          if ( sub_65B229(48) )
          {
            v23 = sub_67EF22(v5 + 16);
LABEL_94:
            v6 = (_DWORD *)v23;
          }
          else
          {
LABEL_97:
            v6 = 0;
          }
LABEL_98:
          sub_65ED96(v5, (int)v6);
          break;
        default:
          break;
      }
      if ( !*((_DWORD *)v5 + 20) )
      {
        if ( sub_65B229(20) )
        {
          v29 = v5;
          v3 = __readeflags();
          v4 = dword_1262594 ^ ~dword_16C6EDC;
          __writeeflags(v3);
          v5 = (char *)_InterlockedExchange((volatile __int32 *)&v29, v4);
          v27 = sub_67ED1B(v6, *((_DWORD *)v5 + 13), v29);
        }
        else
        {
          v27 = 0;
        }
        if ( v27 )
        {
          *((_DWORD *)v5 + 13) = v27;
        }
        else
        {
          sub_65DD1F(*(_DWORD **)v5, (int)(v5 + 16), 0, "internal error: out of memory");
          *((_DWORD *)v5 + 20) = 1;
          *((_DWORD *)v5 + 19) = 1;
        }
      }
    }
  }
}
