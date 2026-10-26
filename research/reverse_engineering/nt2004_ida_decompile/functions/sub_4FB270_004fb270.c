int __thiscall sub_4FB270(int this)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  signed int i; // edi
  signed int j; // ebp
  int v7; // edi
  int v8; // ebx
  int v9; // ebp
  float *v10; // edi
  int result; // eax
  float v12; // [esp+0h] [ebp-5Ch]
  float v13; // [esp+0h] [ebp-5Ch]
  float v14; // [esp+14h] [ebp-48h]
  float v15; // [esp+14h] [ebp-48h]
  char Buffer[64]; // [esp+1Ch] [ebp-40h] BYREF

  if ( dword_75CBB0 > 0 )
  {
    if ( dword_75CBB0 <= 6 )
    {
      pfnAPC(*(_DWORD *)(this + 152));
      if ( dword_75CBB4 )
      {
        if ( dword_75CBB4 == 5 )
        {
          if ( dbl_7DA9D0 >= *(float *)(this + 152) )
          {
            sub_42F950(&dword_75CBA8, 8);
            sub_4F8D30((_DWORD *)(this + 224), 2);
            nullsub_6(flt_629328);
          }
        }
        else if ( dword_75CBB4 == 7 )
        {
          v2 = dbl_7DA9C8 + *(float *)(this + 152);
LABEL_73:
          *(float *)(this + 152) = v2;
        }
      }
      else if ( dbl_7DA9D0 >= *(float *)(this + 148) )
      {
        sub_42F950(&dword_75CBA8, 5);
LABEL_7:
        sub_4F8D30((_DWORD *)(this + 224), 1);
      }
    }
    else if ( dword_75CBB0 == 7 )
    {
      switch ( dword_75CBB4 )
      {
        case 0:
          if ( dbl_7DA9D0 >= *(float *)(this + 148) )
          {
            sub_42F950(&dword_75CBA8, 1);
            goto LABEL_7;
          }
          break;
        case 1:
          if ( dbl_7DA9D0 < *(float *)(this + 152) )
          {
            if ( dbl_7DA9D0 >= *(float *)(this + 148) + 900.0 )
              sub_4F8D30((_DWORD *)(this + 224), 2);
          }
          else
          {
            if ( dword_766F44 )
            {
              sub_42F950(&dword_75CBA8, 2);
              v2 = *(float *)(this + 152) + 300.0;
              goto LABEL_73;
            }
            if ( dword_767088 )
            {
              sub_42F950(&dword_75CBA8, 3);
            }
            else
            {
              *(_DWORD *)(this + 196) = 2139095039;
              *(_DWORD *)(this + 148) = 2139095039;
              *(_BYTE *)(this + 162) = 0;
              sub_42F950(&dword_75CBA8, 4);
            }
          }
          break;
        case 2:
          if ( !*(_BYTE *)(this + 162) )
            *(_BYTE *)(this + 162) = 1;
          if ( *(_DWORD *)this == 2 )
          {
            sub_50B4E0(0, 1);
            sub_414EF0((void **)this);
          }
          sub_414FC0((int *)this);
          if ( dbl_7DA9D0 < *(float *)(this + 152) )
            goto LABEL_24;
          *(_BYTE *)(this + 162) = 0;
          if ( dword_767088 )
          {
            sub_42F950(&dword_75CBA8, 3);
            sub_4FA0D0();
          }
          else
          {
            *(_DWORD *)(this + 196) = 2139095039;
            *(_DWORD *)(this + 148) = 2139095039;
            *(_BYTE *)(this + 162) = 0;
            sub_42F950(&dword_75CBA8, 4);
LABEL_24:
            sub_4FA0D0();
          }
          break;
        case 3:
          sub_415230(this);
          if ( !sub_4634F0(dword_764D70) )
          {
            sub_51F3D0(1, 4);
            v12 = dbl_7DA9C8;
            sub_4DE8F0((void *)(dword_75AACC + 20836), v12);
          }
          break;
        case 4:
          if ( !*(_BYTE *)(this + 162) )
          {
            sub_415230(this);
            if ( !byte_76617C )
              sub_40C3F0((_DWORD **)&dword_6291CC);
            *(_BYTE *)(this + 162) = 1;
          }
          if ( dbl_7DA9D0 < *(float *)(this + 148) )
          {
            if ( sub_463490(dword_764D70) )
              sub_45D270(&byte_764D68, a0001, 0);
            v14 = dbl_7DA9D0;
            if ( *(float *)(this + 196) + 4.0 > v14 )
            {
              if ( *(float *)(this + 196) + 3.0 > v14 )
              {
                if ( *(float *)(this + 196) + 2.0 > v14 )
                {
                  if ( *(float *)(this + 196) + 1.0 > v14 )
                  {
                    if ( *(float *)(this + 196) > (double)v14 )
                    {
                      if ( sub_463490(dword_764D70) )
                      {
                        v3 = 32.5 - dbl_7DA9D0;
                        if ( 32.5 - dbl_7DA9D0 > 0.0 )
                        {
                          v4 = v3 + 1.0;
                          v15 = v4;
                          sprintf(
                            Buffer,
                            "%02d:%02d",
                            (unsigned int)(__int64)(0.016666668 * (v4 + 1.0)),
                            (unsigned int)(__int64)(v4 + 1.0 - (double)(int)(__int64)(0.016666668 * (v4 + 1.0)) * 60.0));
                          sub_45D270(&byte_764D68, Buffer, 0);
                          sprintf(
                            Buffer,
                            "%02d:%02d",
                            (unsigned int)(__int64)(v15 * 0.016666668),
                            (unsigned int)(__int64)(v15 - (double)(int)(__int64)(v15 * 0.016666668) * 60.0));
                          sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
                          v3 = v15;
                        }
                        if ( v3 <= 6.0
                          && byte_76617C
                          && sub_463C00(dword_764D70)
                          && sub_42DBA0()
                          && !*(_DWORD *)(dword_75AACC + 20892) )
                        {
                          sub_4B9210();
                        }
                      }
                    }
                    else
                    {
                      sub_4FA8E0((_DWORD *)this, 1);
                    }
                  }
                  else
                  {
                    sub_4FA8E0((_DWORD *)this, 2);
                  }
                }
                else
                {
                  sub_4FA8E0((_DWORD *)this, 3);
                }
              }
              else
              {
                sub_4FA8E0((_DWORD *)this, 4);
              }
            }
            else
            {
              sub_4FA8E0((_DWORD *)this, 5);
            }
          }
          else
          {
            sub_4FAEF0();
            sub_4FA8E0((_DWORD *)this, 0);
            *(_DWORD *)(this + 148) = 0;
            sub_42F950(&dword_75CBA8, 3);
            sub_4BBE60((float *)&unk_766220, 0);
            if ( dword_7D7928 != 2 || dword_6290F4 != 2 )
              sub_4BBF10();
          }
          break;
        case 5:
          if ( *(_DWORD *)(this + 224) == 2 )
          {
            for ( i = 0; i < (int)NumOfElements; ++i )
            {
              if ( *(_DWORD *)(dword_75AAD0[i] + 20852) == 1 )
                sub_4F8D30((_DWORD *)(this + 224), 1);
            }
          }
          if ( sub_42DBA0() && !*(_DWORD *)(dword_75AACC + 20848) && *(_DWORD *)(dword_75AACC + 20844) == 9 )
          {
            v13 = dbl_7DA9C8;
            sub_4DE8F0((void *)(dword_75AACC + 20836), v13);
          }
          break;
        default:
          break;
      }
    }
  }
  if ( (dword_75CBAC & 1) == 0 )
  {
    for ( j = 0; j < (int)NumOfElements; ++j )
    {
      v7 = dword_75AAD0[j];
      if ( *(_DWORD *)(v7 + 16584) != -1 )
        *(float *)(v7 + 20856) = sub_51C7A0(v7 + 84);
    }
  }
  v8 = 0;
  if ( dword_5FD344 > 0 )
  {
    v9 = 0;
    do
    {
      if ( *(_DWORD *)((char *)off_5FD348 + v9 + 16584) != -1 )
      {
        v10 = (float *)((char *)off_5FD348 + v9);
        v10[5214] = sub_51C7A0(v10 + 21);
      }
      ++v8;
      v9 += 25304;
    }
    while ( v8 < dword_5FD344 );
  }
  result = *(_DWORD *)(this + 224);
  if ( result != 2 )
  {
    if ( *(_BYTE *)(this + 256) && fmod(dbl_7DA9D0, 1.0) > 0.5 )
      return sub_4F8D30((_DWORD *)(this + 224), 4);
    else
      return sub_4F8D30((_DWORD *)(this + 224), 1);
  }
  return result;
}
