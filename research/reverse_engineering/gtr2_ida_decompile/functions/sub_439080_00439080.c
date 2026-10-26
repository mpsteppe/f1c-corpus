int __thiscall sub_439080(float *this)
{
  int v2; // ebp
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // eax

  v2 = 0;
  if ( !*(_BYTE *)this )
  {
    v2 = sub_439020();
    goto LABEL_27;
  }
  v3 = *((_DWORD *)this + 1);
  switch ( v3 )
  {
    case 0:
      sub_412EB0(&dword_91BF20, 5, 1);
      sub_562430(&dword_FAE988, 2, 1);
      *((_DWORD *)this + 1) = 1;
      this[10] = 0.0;
      this[9] = 1.0;
      goto LABEL_27;
    case 1:
      if ( this[9] <= 0.0 )
      {
        *((_DWORD *)this + 1) = 2;
        this[9] = 2.0;
      }
      else
      {
        this[9] = this[9] - dbl_FB1D10;
      }
      break;
    case 2:
      *((_DWORD *)this + 11) = 1;
      *((_DWORD *)this + 1) = 4;
      sub_562430(&dword_FAE988, 0, 1);
      goto LABEL_27;
    case 5:
      if ( this[9] <= 0.0 )
        v2 = 1;
      else
        this[9] = this[9] - dbl_FB1D10;
      goto LABEL_27;
    default:
      if ( this[13] > 0.0 )
      {
        this[13] = this[13] - dbl_FB1D10;
      }
      else
      {
        v4 = *((_DWORD *)this + 6) + 1;
        v5 = *((_DWORD *)this + 6) + 3;
        this[13] = 2.0;
        *((_DWORD *)this + 6) = v4;
        *((_DWORD *)this + 11) = v5;
        if ( v4 < dword_757C10 )
        {
          v6 = 0;
          if ( dword_757C10 > 0 )
          {
            v7 = v4 + 1;
            while ( 1 )
            {
              this[7] = 0.0;
              if ( *(_DWORD *)(*(&dword_91E088 + v6) + 19324) == v7 )
                break;
              if ( ++v6 >= dword_757C10 )
                goto LABEL_22;
            }
            *((_DWORD *)this + 7) = v6;
          }
LABEL_22:
          sub_561B40(&dword_FAE988);
        }
        else
        {
          *((_DWORD *)this + 1) = 5;
          *((_DWORD *)this + 6) = v4 - 1;
          this[9] = 3.0;
        }
      }
      break;
  }
  this[10] = dbl_FB1D10 + this[10];
LABEL_27:
  if ( *((_DWORD *)this + 3) )
    return off_16C93F0();
  else
    return v2;
}
