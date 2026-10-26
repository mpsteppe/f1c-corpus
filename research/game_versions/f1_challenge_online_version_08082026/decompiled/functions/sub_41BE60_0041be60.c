void sub_41BE60()
{
  int v0; // esi
  int v1; // eax
  float v2[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    sub_4144D0(v2);
    v0 = sub_4FF130(&unk_8AFEC0);
    v1 = sub_4FF1D0(&unk_8AFEC0);
    switch ( v0 )
    {
      case 2:
        if ( v1 != 2 )
          goto LABEL_17;
        sub_4144F0(v2, 506, -1, -1, -1, -1, -2.0, -2.0);
        sub_418560(flt_5EA618, v2);
        if ( flt_8AFEF0 > 30.0 )
        {
          sub_4144F0(v2, 507, -1, -1, -1, -1, -2.0, -2.0);
          sub_418560(flt_5EA618, v2);
        }
        return;
      case 3:
        if ( v1 == 3 || v1 == 2 )
          sub_4144F0(v2, 509, -1, -1, -1, -1, -2.0, -2.0);
        else
          sub_4144F0(v2, 512, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_21;
      case 4:
        if ( v1 != 4 && v1 != 5 )
          goto LABEL_17;
        sub_4144F0(v2, 510, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_19;
      case 5:
        if ( v1 == 4 || v1 == 5 )
        {
          sub_4144F0(v2, 511, -1, -1, -1, -1, -2.0, -2.0);
LABEL_19:
          sub_418560(flt_5EA618, v2);
          if ( (flt_8AFEE8 + flt_8AFEEC) * 0.5 > 0.7 )
          {
            sub_4144F0(v2, 513, -1, -1, -1, -1, -2.0, -2.0);
LABEL_21:
            sub_418560(flt_5EA618, v2);
          }
        }
        else
        {
LABEL_17:
          sub_4144F0(v2, 512, -1, -1, -1, -1, -2.0, -2.0);
          sub_418560(flt_5EA618, v2);
        }
        break;
      default:
        return;
    }
  }
}
