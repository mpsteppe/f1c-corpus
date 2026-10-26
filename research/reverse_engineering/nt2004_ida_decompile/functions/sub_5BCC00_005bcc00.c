int __thiscall sub_5BCC00(void *this)
{
  unsigned __int8 *v2; // edi
  int v3; // ebp
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  __int16 v8; // ax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  int v17; // ebx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  void *v22; // eax
  _DWORD v23[2]; // [esp+10h] [ebp-8h] BYREF

  v2 = (unsigned __int8 *)*((_DWORD *)this + 29);
  v3 = *((_DWORD *)this + 30);
  switch ( *((_DWORD *)this + 366) )
  {
    case 0:
      if ( v3 < 1 )
        goto LABEL_40;
      v4 = (*v2 ^ 0xEC) + 2;
      if ( v3 < v4 )
        goto LABEL_40;
      v5 = v2[v4 - 1] ^ 0xEA;
      v6 = v5 + v4;
      if ( v3 < v6 )
        goto LABEL_40;
      sub_5BCF30(v5);
      v2 += v6;
      v3 -= v6;
      *((_DWORD *)this + 366) = 1;
      sub_5BE770(v3);
      goto LABEL_6;
    case 1:
LABEL_6:
      if ( v3 < 6 )
        goto LABEL_40;
      v7 = *((_DWORD *)this + 289);
      *((_DWORD *)this + 292) = *(_DWORD *)v2;
      (*((void (__fastcall **)(void *, int, int, int))this + 288))(this, 6, dword_7FEEC0, v7);
      v8 = *((_WORD *)v2 + 2);
      *((_WORD *)this + 588) = v8;
      if ( v8 == -1 )
      {
        if ( sub_5BC130((int)(v2 + 6), v3 - 6) == -1 )
          goto LABEL_40;
        v10 = *((_DWORD *)this + 289);
        *((_DWORD *)this + 295) = v9;
        (*((void (__fastcall **)(void *, int, int, int))this + 288))(this, 5, dword_7FEEC0, v10);
        if ( !*((_DWORD *)this + 29) )
          goto LABEL_40;
      }
      v2 += 6;
      v3 -= 6;
      if ( (*((_BYTE *)this + 1460) & 2) != 0 || *((_WORD *)this + 588) == 0xFFFF )
      {
        *((_DWORD *)this + 366) = 5;
        *(_DWORD *)this = 2;
        goto LABEL_40;
      }
      *((_DWORD *)this + 366) = 2;
      *((_DWORD *)this + 287) = -1;
LABEL_13:
      if ( *((_DWORD *)this + 287) == -1 )
      {
        if ( v3 < 1 )
          goto LABEL_40;
        *((_DWORD *)this + 287) = *v2;
        v11 = sub_5BE100(0);
        *((_DWORD *)this + 2) = v11;
        if ( !v11 )
          return 5;
        ++v2;
        --v3;
      }
      for ( ; *((_DWORD *)this + 287) > sub_577650(*((void **)this + 2)); v3 += -1 - v13 )
      {
        if ( v3 < 2 )
          break;
        v13 = sub_5BC130((int)(v2 + 1), v3 - 1);
        if ( v13 == -1 )
          break;
        v23[1] = *v2;
        v14 = sub_5BDAD0(this);
        v15 = *((_DWORD *)this + 2);
        v23[0] = v14;
        sub_5BE1C0(v15, v23);
        v2 += v13 + 1;
      }
      if ( *((_DWORD *)this + 287) > sub_577650(*((void **)this + 2)) )
        goto LABEL_40;
      *((_DWORD *)this + 366) = 3;
      *((_DWORD *)this + 287) = -1;
LABEL_25:
      if ( *((_DWORD *)this + 287) != -1 )
        goto LABEL_28;
      if ( v3 >= 1 )
      {
        v16 = *v2++;
        *((_DWORD *)this + 287) = v16;
        *((_DWORD *)this + 286) = 0;
        --v3;
LABEL_28:
        if ( *((_DWORD *)this + 287) > *((_DWORD *)this + 286) )
        {
          do
          {
            v17 = sub_5BC130((int)v2, v3);
            if ( v17 == -1 )
              break;
            v2 += v17;
            v3 -= v17;
            *((_DWORD *)this + *((_DWORD *)this + 286) + 31) = sub_5BDAD0(this);
            v18 = *((_DWORD *)this + 287);
            v19 = *((_DWORD *)this + 286) + 1;
            *((_DWORD *)this + 286) = v19;
          }
          while ( v18 > v19 );
        }
        if ( *((_DWORD *)this + 287) <= *((_DWORD *)this + 286) )
        {
          *((_DWORD *)this + 366) = 4;
LABEL_33:
          if ( v3 >= 5 )
          {
            while ( 1 )
            {
              v20 = sub_5BCFC0(v3);
              if ( v20 == -2 )
                return 5;
              if ( v20 == -1 )
                break;
              v2 += v20;
              v3 -= v20;
              if ( !*((_DWORD *)this + 29) || !v20 )
                goto LABEL_40;
            }
            v21 = *((_DWORD *)this + 289);
            *((_DWORD *)this + 366) = 5;
            *(_DWORD *)this = 2;
            v3 -= 5;
            v2 += 5;
            (*((void (__fastcall **)(void *, int, int, int))this + 288))(this, 3, dword_7FEEC0, v21);
          }
        }
      }
LABEL_40:
      v22 = (void *)*((_DWORD *)this + 29);
      if ( v22 )
      {
        if ( v3 )
          memcpy(v22, v2, v3);
        *((_DWORD *)this + 30) = v3;
      }
      return 0;
    case 2:
      goto LABEL_13;
    case 3:
      goto LABEL_25;
    case 4:
      goto LABEL_33;
    default:
      goto LABEL_40;
  }
}
