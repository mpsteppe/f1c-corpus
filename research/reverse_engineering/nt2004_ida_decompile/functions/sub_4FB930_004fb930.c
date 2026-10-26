void __thiscall sub_4FB930(int this)
{
  int v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]

  if ( dword_75CBB0 >= 0 )
  {
    if ( dword_75CBB0 <= 6 )
    {
      if ( (*(float *)(this + 152) + *(float *)(this + 148)) * 0.5 <= dbl_7DA9D0 )
        *(_BYTE *)(this + 160) = 1;
LABEL_39:
      sub_4FA900(this);
      sub_4F9040(this);
    }
    else if ( dword_75CBB0 == 7 )
    {
      if ( (dword_761FF8 & 1) != 0 && (byte_762135 & 2) != 0 && !byte_766191 )
        *(_BYTE *)(this + 161) = 1;
      switch ( dword_75CBB4 )
      {
        case 0:
        case 1:
          if ( *(_BYTE *)(this + 161) )
          {
            if ( dword_766F44 )
            {
              *(float *)&v3 = dbl_7DA9D0 + 300.0;
              sub_4FAF30(2, v3);
            }
            else
            {
              if ( !dword_767088 )
                goto LABEL_34;
              sub_4FAF30(3, *(_DWORD *)(this + 152));
            }
          }
          break;
        case 2:
          if ( *(_BYTE *)(this + 161) && *(float *)(this + 132) > 1.5 || !sub_414D40((_DWORD *)this) && !dword_766E00 )
          {
            sub_415230(this);
            if ( dword_767088 )
              sub_4FAF30(3, *(_DWORD *)(this + 152));
            else
              sub_4FB0B0();
            sub_41BDD0();
          }
          sub_51F3D0(1, 4);
          sub_4FA0D0();
          break;
        case 3:
          if ( sub_4FAE90((float *)this) )
            sub_4FB0B0();
          sub_4FAE10((float *)this);
          sub_4FA900(this);
          if ( !*(_BYTE *)(this + 188) )
          {
            sub_41BBF0(flt_629328);
            if ( sub_4FA1A0((_BYTE *)this) )
            {
              *(_BYTE *)(this + 188) = 1;
              sub_42F950(&dword_75CBA8, 5);
              *(float *)&v2 = dbl_7DA9D0;
              sub_4FAFF0((int *)this, v2, -1);
            }
          }
          if ( !sub_463490(dword_764D70) )
          {
            if ( *(_BYTE *)(this + 161) )
            {
              sub_45D270(&byte_764D68, aPressSpaceToSk, 0);
              sub_45D270(&byte_764D68, aBeginningPaceL, 0);
              sub_4FA450((float *)this);
            }
            else
            {
              sub_45D100(&byte_764D68, (int)aPressSpaceToSk, 3, 16909060, 0);
            }
          }
          break;
        case 4:
          if ( *(_DWORD *)(this + 196) == 2139095039 )
LABEL_34:
            sub_4FB0B0();
          break;
        case 5:
        case 6:
        case 7:
        case 8:
          sub_4BBBD0(&unk_766220);
          if ( (*(float *)(this + 152) + *(float *)(this + 148)) * 0.5 > dbl_7DA9D0 )
            goto LABEL_39;
          *(_BYTE *)(this + 160) = 1;
          sub_4FA900(this);
          sub_4F9040(this);
          break;
        default:
          return;
      }
    }
  }
}
